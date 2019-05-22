#region License
/* 
 * Copyright (C) 1999-2019 John Källén.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; see the file COPYING.  If not, write to
 * the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
 */
#endregion

using Reko.Core;
using Reko.Core.Expressions;
using Reko.Core.Lib;
using Reko.Core.Machine;
using Reko.Core.Types;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Reko.Arch.PaRisc
{
    public class PaRiscDisassembler : DisassemblerBase<PaRiscInstruction>
    {
        private const InstrClass TD = InstrClass.Transfer | InstrClass.Delay;
        private const InstrClass CTD = InstrClass.ConditionalTransfer | InstrClass.Delay;

        private static readonly MaskDecoder rootDecoder;
        private static readonly InstrDecoder invalid;

        private readonly PaRiscArchitecture arch;
        private readonly EndianImageReader rdr;
        private readonly bool is64bit;
        private readonly PrimitiveType dtSignedWord;

        private Address addr;
        private readonly List<MachineOperand> ops;
        private bool annul;
        private bool zero;
        private SignExtension signExtend;
        private ConditionOperand cond;
        private BaseRegMod addrMod;
        private int coprocessor;
        private FpFormat fpFormat;

        public PaRiscDisassembler(PaRiscArchitecture arch, EndianImageReader rdr)
        {
            this.arch = arch;
            this.rdr = rdr;
            this.ops = new List<MachineOperand>();
            is64bit = arch.Is64Bit();
            this.dtSignedWord = is64bit ? PrimitiveType.Int64 : PrimitiveType.Int32;
        }

        public override PaRiscInstruction DisassembleInstruction()
        {
            this.addr = rdr.Address;
            this.ops.Clear();
            this.annul = false;
            this.zero = false;
            this.signExtend = 0;
            this.cond = null;
            this.coprocessor = -1;
            this.addrMod = BaseRegMod.None;
            this.fpFormat = FpFormat.None;

            if (!rdr.TryReadBeUInt32(out uint uInstr))
                return null;
            var instr = rootDecoder.Decode(uInstr, this);
            instr.Address = this.addr;
            instr.Length = (int) (rdr.Address - addr);
            instr.InstructionClass |= uInstr == 0 ? InstrClass.Zero : 0;
            return instr;
        }

        /// <summary>
        /// Create a Reko bitfield using PA Risc bit position + bit length.
        /// </summary>
        /// <remarks>
        /// PA Risc instruction bits are numbered from the MSB to LSB, but 
        /// Reko bitfields are numbered from LSB to MSB.
        /// </summary>
        private static Bitfield BeField(int bitPos, int bitLength)
        {
            return new Bitfield(32 - (bitPos + bitLength), bitLength);
        }

        private static Bitfield[] BeFields(params (int bitPos, int bitLength)[] flds)
        {
            return flds.Select(f => BeField(f.bitPos, f.bitLength)).ToArray();
        }

        /// <summary>
        /// Unsigned immediate field.
        /// </summary>
        private static Mutator<PaRiscDisassembler> u(int bitPos, int bitLength, PrimitiveType dt)
        {
            var field = BeField(bitPos, bitLength);
            return (u, d) =>
            {
                var v = field.Read(u);
                Decoder.DumpMaskedInstruction(u, field.Mask << field.Position, "Unsigned immediate");
                d.ops.Add(new ImmediateOperand(Constant.Create(dt, v)));
                return true;
            };
        }

        /// <summary>
        /// Unsigned immediate fields.
        /// </summary>
        private static Mutator<PaRiscDisassembler> u(Bitfield[] fields, Func<uint, Bitfield[], uint> mutator)
        {
            return (u, d) =>
            {
                var n = mutator(u, fields);
                d.ops.Add(new ImmediateOperand(Constant.Create(PrimitiveType.Word32, n)));
                return true;
            };
        }
        private static Mutator<PaRiscDisassembler> u8(int bitPos, int bitLength) => u(bitPos, bitLength, PrimitiveType.Byte);
        private static Mutator<PaRiscDisassembler> u16(int bitPos, int bitLength) => u(bitPos, bitLength, PrimitiveType.Word16);

        private static Mutator<PaRiscDisassembler> u8From31(int bitPos, int bitLength)
        {
            var field = BeField(bitPos, bitLength);
            return (u, d) =>
            {
                var v = 31 - field.Read(u);
                d.ops.Add(new ImmediateOperand(Constant.Create(PrimitiveType.Byte, v)));
                return true;
            };
        }

        private static Mutator<PaRiscDisassembler> u8From32(int bitPos, int bitLength)
        {
            var field = BeField(bitPos, bitLength);
            return (u, d) =>
            {
                var v = 32 - field.Read(u);
                d.ops.Add(new ImmediateOperand(Constant.Create(PrimitiveType.Byte, v)));
                return true;
            };
        }

        private static Mutator<PaRiscDisassembler> Left(Bitfield[] fields, Func<uint, Bitfield[], uint> mutator, int sh)
        {
            return (u, d) =>
            {
                var n = mutator(u, fields);
                d.ops.Add(new LeftImmediateOperand((int)n << sh));
                return true;
            };
        }

        /// <summary>
        /// Signed immediate constant.
        /// </summary>
        private static Mutator<PaRiscDisassembler> s(int bitPos, int bitLength, PrimitiveType dt)
        {
            var field = BeField(bitPos, bitLength);
            return (u, d) =>
            {
                var v = field.ReadSigned(u);
                d.ops.Add(new ImmediateOperand(Constant.Create(dt, v)));
                return true;
            };
        }
        private static Mutator<PaRiscDisassembler> s32(int bitPos, int bitLength) => s(bitPos, bitLength, PrimitiveType.Int32);


        /// <summary>
        /// Wonky "low sign extend" format. 
        /// </summary>
        /// <remarks>
        /// From the manual:
        /// sign_ext(cat(x{ len - 1},x{ 0..len - 2}),len))
        /// </remarks>
        private static Mutator<PaRiscDisassembler> lse(int bitPos, int bitLength)
        {
            var fields = BeFields((bitPos + bitLength - 1, 1), (bitPos, bitLength - 1));
            return (u, d) =>
            {
                var v = Bitfield.ReadSignedFields(fields, u);
                d.ops.Add(new ImmediateOperand(Constant.Create(d.dtSignedWord, v)));
                return true;
            };
        }

        /// <summary>
        /// Signed immediate constant spread across multiple fields with a postprocessor.
        /// </summary>
        private static Mutator<PaRiscDisassembler> s(PrimitiveType dt, Bitfield[] fields, Func<bool, uint, Bitfield[], uint> mutator)
        {
            return (u, d) =>
            {
                var v = mutator(d.is64bit, u, fields);
                d.ops.Add(new ImmediateOperand(Constant.Create(dt, v)));
                return true;
            };
        }

        private static Mutator<PaRiscDisassembler> r(int bitPos, int bitLength)
        {
            var field = BeField(bitPos, bitLength);
            return (u, d) =>
            {
                var iReg = field.Read(u);
                d.ops.Add(new RegisterOperand(Registers.GpRegs[iReg]));
                return true;
            };
        }
        private static readonly Mutator<PaRiscDisassembler> r6 = r(6, 5);
        private static readonly Mutator<PaRiscDisassembler> r11 = r(11, 5);
        private static readonly Mutator<PaRiscDisassembler> r27 = r(27, 5);

        private static Mutator<PaRiscDisassembler> fr(int bitPos, int bitLength)
        {
            var field = BeField(bitPos, bitLength);
            return (u, d) =>
            {
                var iReg = field.Read(u);
                d.ops.Add(new RegisterOperand(Registers.FpRegs[iReg]));
                return true;
            };
        }
        private static readonly Mutator<PaRiscDisassembler> fr6 = fr(6, 5);
        private static readonly Mutator<PaRiscDisassembler> fr11 = fr(11, 5);
        private static readonly Mutator<PaRiscDisassembler> fr27 = fr(27, 5);

        /// <summary>
        /// Single precision floating point register.
        /// </summary>
        private static Mutator<PaRiscDisassembler> frsng(params (int bitPos, int bitLength)[] flds)
        {
            var fields = BeFields(flds);
            return (u, d) =>
            {
                var iReg = Bitfield.ReadFields(fields, u);
                d.ops.Add(new RegisterOperand(Registers.FpRegs32[iReg]));
                return true;
            };
        }
        private static readonly Mutator<PaRiscDisassembler> fr27_24 = frsng((27, 5), (24,1));
        private static readonly Mutator<PaRiscDisassembler> fr11_19 = frsng((27, 5), (19,1));

        /// <summary>
        /// Specific register.
        /// </summary>
        private static Mutator<PaRiscDisassembler> reg(RegisterStorage r)
        {
            return (u, d) =>
            {
                d.ops.Add(new RegisterOperand(r));
                return true;
            };
        }

        /// <summary>
        /// Address space register.
        /// </summary>
        private static Mutator<PaRiscDisassembler> sr(int bitPos)
        {
            var field = BeField(bitPos, 3);
            return (u, d) =>
            {
                var iReg = field.Read(u);
                d.ops.Add(new RegisterOperand(Registers.SpaceRegs[iReg]));
                return true;
            };
        }

        /// <summary>
        /// Conditional field.
        /// </summary>
        private static Mutator<PaRiscDisassembler> cf(int bitPos, int bitLen, ConditionOperand[] conds)
        {
            Debug.Assert(conds.Length == (1 << bitLen));
            var field = BeField(bitPos, bitLen);
            return (u, d) =>
            {
                Decoder.DumpMaskedInstruction(u, field.Mask << field.Position, "conditional field");
                var iCond = field.Read(u);
                var cond = conds[iCond];
                if (cond == null)
                    return false;
                if (cond.Type != ConditionType.Never)
                {
                    d.cond = cond;
                }
                return true;
            };
        }
        private static Mutator<PaRiscDisassembler> cf16_cmpsub = cf(16, 4, new[]
        {
            ConditionOperand.Never,
            ConditionOperand.Tr,
            ConditionOperand.Eq,
            ConditionOperand.Ne,

            ConditionOperand.Lt,
            ConditionOperand.Ge,
            ConditionOperand.Le,
            ConditionOperand.Gt,

            ConditionOperand.Ult,
            ConditionOperand.Uge,
            ConditionOperand.Ule,
            ConditionOperand.Ugt,

            ConditionOperand.Sv,
            ConditionOperand.Nsv,
            ConditionOperand.Odd,
            ConditionOperand.Even,
        });
        private static Mutator<PaRiscDisassembler> cf16_add = cf(16, 4, new[]
        {
            ConditionOperand.Never,
            ConditionOperand.Tr,
            ConditionOperand.Eq,
            ConditionOperand.Ne,

            ConditionOperand.Lt,
            ConditionOperand.Ge,
            ConditionOperand.Le,
            ConditionOperand.Gt,

            ConditionOperand.Nuv,
            ConditionOperand.Uv,
            ConditionOperand.Znv,
            ConditionOperand.Vnz,

            ConditionOperand.Sv,
            ConditionOperand.Nsv,
            ConditionOperand.Odd,
            ConditionOperand.Even,
        });
        private static Mutator<PaRiscDisassembler> cf16_add64 = cf(16, 4, new[]
        {
            ConditionOperand.Never64,
            ConditionOperand.Tr64,
            ConditionOperand.Eq64,
            ConditionOperand.Ne64,

            ConditionOperand.Lt64,
            ConditionOperand.Ge64,
            ConditionOperand.Le64,
            ConditionOperand.Gt64,

            ConditionOperand.Nuv64,
            ConditionOperand.Uv64,
            ConditionOperand.Znv64,
            ConditionOperand.Vnz64,

            ConditionOperand.Sv64,
            ConditionOperand.Nsv64,
            ConditionOperand.Odd64,
            ConditionOperand.Even64,
        });
        private static Mutator<PaRiscDisassembler> cf16_log = cf(16, 4, new[]
        {
            ConditionOperand.Never,
            ConditionOperand.Tr,
            ConditionOperand.Eq,
            ConditionOperand.Ne,

            ConditionOperand.Lt,
            ConditionOperand.Ge,
            ConditionOperand.Le,
            ConditionOperand.Gt,

            null,
            null,
            null,
            null,

            null,
            null,
            ConditionOperand.Odd,
            ConditionOperand.Even,
        });
        private static Mutator<PaRiscDisassembler> cf16_cmp32_t = cf(16, 3, new[]
        {
            ConditionOperand.Never,
            ConditionOperand.Eq,
            ConditionOperand.Lt,
            ConditionOperand.Le,

            ConditionOperand.Ult,
            ConditionOperand.Ule,
            ConditionOperand.Sv,
            ConditionOperand.Odd,
        });
        private static Mutator<PaRiscDisassembler> cf16_cmp32_f = cf(16, 3, new[]
        {
            ConditionOperand.Tr,
            ConditionOperand.Ne,
            ConditionOperand.Ge,
            ConditionOperand.Gt,

            ConditionOperand.Uge,
            ConditionOperand.Ugt,
            ConditionOperand.Nsv,
            ConditionOperand.Even,
        });
        private static Mutator<PaRiscDisassembler> cf16_shext = cf(16, 3, new[]
        {
            ConditionOperand.Never,
            ConditionOperand.Eq,
            ConditionOperand.Lt,
            ConditionOperand.Odd,

            ConditionOperand.Tr,
            ConditionOperand.Ne,
            ConditionOperand.Ge,
            ConditionOperand.Even,
        });

        private static Mutator<PaRiscDisassembler> cf16_add_3 = cf(16, 3, new[]
        {
            ConditionOperand.Never,
            ConditionOperand.Eq,
            ConditionOperand.Lt,
            ConditionOperand.Le,
            ConditionOperand.Nuv,
            ConditionOperand.Znv,
            ConditionOperand.Sv,
            ConditionOperand.Odd
        });

        private static Mutator<PaRiscDisassembler> cf16_add_3_neg = cf(16, 3, new[]
        {
            ConditionOperand.Tr,
            ConditionOperand.Ne,
            ConditionOperand.Ge,
            ConditionOperand.Gt,
            ConditionOperand.Uv,
            ConditionOperand.Vnz,
            ConditionOperand.Nsv,
            ConditionOperand.Even
        });

        private static Mutator<PaRiscDisassembler> cf16_add_3_64 = cf(16, 3, new[]
        {
            ConditionOperand.Never,
            ConditionOperand.Eq,   
            ConditionOperand.Lt,   
            ConditionOperand.Le,   
            ConditionOperand.Nuv,  
            ConditionOperand.Eq64, 
            ConditionOperand.Lt64, 
            ConditionOperand.Le64, 
        });

        private static Mutator<PaRiscDisassembler> cf16_add_3_neg_64 = cf(16, 3, new[]
        {
            ConditionOperand.Tr,
            ConditionOperand.Ne,
            ConditionOperand.Ge,
            ConditionOperand.Gt,
            ConditionOperand.Uv,
            ConditionOperand.Ne64,
            ConditionOperand.Ge64,
            ConditionOperand.Gt64
        });

        private static bool cfadd_bitsize(uint uInstr, PaRiscDisassembler dasm)
        {
            if (dasm.is64bit)
            {
                return cf16_add_3_64(uInstr, dasm);
            }
            else
            {
                return cf16_add_3(uInstr, dasm);
            }
        }

        private static bool cfadd_bitsize_neg(uint uInstr, PaRiscDisassembler dasm)
        {
            if (dasm.is64bit)
            {
                return cf16_add_3_neg_64(uInstr, dasm);
            }
            else
            {
                return cf16_add_3_neg(uInstr, dasm);
            }
        }


        private static readonly Mutator<PaRiscDisassembler> cf27_fp = cf(27, 5, new[]
        {
            new ConditionOperand(ConditionType.FpFalseQ, "false?"),
            new ConditionOperand(ConditionType.FpFalse, "false"),
            new ConditionOperand(ConditionType.Fp2, "?"),
            new ConditionOperand(ConditionType.Fp3, "!<=>"),

            new ConditionOperand(ConditionType.Fp4, "="),
            new ConditionOperand(ConditionType.Fp5, "=T"),
            new ConditionOperand(ConditionType.Fp6, "?="),
            new ConditionOperand(ConditionType.Fp7, "!<>"),

            new ConditionOperand(ConditionType.Fp8, "!?>="),
            new ConditionOperand(ConditionType.Fp9, "<"),
            new ConditionOperand(ConditionType.Fp10, "?<"),
            new ConditionOperand(ConditionType.Fp11, "!>="),

            new ConditionOperand(ConditionType.Fp12, "!?>"),
            new ConditionOperand(ConditionType.Fp13, "<="),
            new ConditionOperand(ConditionType.Fp14, "?<="),
            new ConditionOperand(ConditionType.Fp15, "!>"),

            new ConditionOperand(ConditionType.Fp16, "!?<="),
            new ConditionOperand(ConditionType.Fp17, ">"),
            new ConditionOperand(ConditionType.Fp18, "?>"),
            new ConditionOperand(ConditionType.Fp19, "!<="),

            new ConditionOperand(ConditionType.Fp20, "!?<"),
            new ConditionOperand(ConditionType.Fp21, ">="),
            new ConditionOperand(ConditionType.Fp22, "?>="),
            new ConditionOperand(ConditionType.Fp23, "!<"),

            new ConditionOperand(ConditionType.Fp24, "!?="),
            new ConditionOperand(ConditionType.Fp25, "<>"),
            new ConditionOperand(ConditionType.Fp26, "!="),
            new ConditionOperand(ConditionType.Fp27, "!=T"),

            new ConditionOperand(ConditionType.Fp28, "!?"),
            new ConditionOperand(ConditionType.Fp29, "<=>"),
            new ConditionOperand(ConditionType.Fp30, "true?"),
            new ConditionOperand(ConditionType.Fp31, "true"),
        });


        /// <summary>
        /// Register indirect with displacement with space register
        /// </summary>
        private static Mutator<PaRiscDisassembler> M(PrimitiveType dt, int baseRegPos, Bitfield [] dispFields, Func<bool, uint,Bitfield[],uint> permutator)
        {
            var baseRegField = BeField(baseRegPos, 5);
            var totalLength = dispFields.Sum(f => f.Length);
            return (u, d) =>
            {
                var disp = (int) Bits.SignExtend(permutator(d.is64bit, u, dispFields), totalLength);
                var iBaseReg = baseRegField.Read(u);
                var am = Bitfield.ReadFields(amFields, u);
                d.ops.Add(MemoryOperand.Indirect(dt, disp, Registers.GpRegs[iBaseReg]));
                return true;
            };
        }

        /// <summary>
        /// Register indirect with displacement with space register and base register update
        /// </summary>
        private static Mutator<PaRiscDisassembler> Mam(PrimitiveType dt, int baseRegPos, Bitfield[] dispFields, Func<bool, uint, Bitfield[], uint> permutator)
        {
            var baseRegField = BeField(baseRegPos, 5);
            var totalLength = dispFields.Sum(f => f.Length);
            return (u, d) =>
            {
                var disp = (int) Bits.SignExtend(permutator(d.is64bit, u, dispFields), totalLength);
                var iBaseReg = baseRegField.Read(u);
                var am = Bitfield.ReadFields(amFields, u);
                d.addrMod = disp > 0
                    ? BaseRegMod.ma
                    : BaseRegMod.mb;
                d.ops.Add(MemoryOperand.Indirect(dt, disp, Registers.GpRegs[iBaseReg]));
                return true;
            };
        }

        private static readonly BaseRegMod[] baseRegMods = new[]
        {
            BaseRegMod.None,
            BaseRegMod.ma,
            BaseRegMod.None,
            BaseRegMod.mb
        };
        private static readonly Bitfield[] amFields = BeFields((18, 1), (26, 1));

        /// <summary>
        /// Register indirect with short displacement with space register
        /// </summary>
        private static Mutator<PaRiscDisassembler> Mshort(PrimitiveType dt)
        {
            var dispField = BeField(11, 5);
            var baseRegField = BeField(6, 5);
            var spaceRegField = BeField(16, 2);
            return (u, d) =>
            {
                var disp = dispField.ReadSigned(u);
                var iBaseReg = baseRegField.Read(u);
                var iSpaceReg = spaceRegField.Read(u);
                var am = Bitfield.ReadFields(amFields, u);
                d.addrMod =  (am == 1 && disp == 0)
                    ? BaseRegMod.o
                    : baseRegMods[am];
                d.ops.Add(MemoryOperand.Indirect(dt, disp, Registers.GpRegs[iBaseReg], Registers.SpaceRegs[iSpaceReg]));
                return true;
            };
        }

        /// <summary>
        /// Register indirect with displacement with space register
        /// </summary>
        private static Mutator<PaRiscDisassembler> M(PrimitiveType dt, int dispPos, int dispLen, int baseRegPos, int spacePos)
        {
            var dispField = BeField(dispPos, dispLen);
            var baseRegField = BeField(baseRegPos, 5);
            var spaceRegField = BeField(spacePos, 2);
            return (u, d) =>
            {
                var disp = dispField.ReadSigned(u);
                var iBaseReg = baseRegField.Read(u);
                var iSpaceReg = spaceRegField.Read(u);
                var am = Bitfield.ReadFields(amFields, u);
                d.addrMod = (am == 1 && disp == 0)
                    ? BaseRegMod.o
                    : baseRegMods[am];
                d.ops.Add(MemoryOperand.Indirect(dt, disp, Registers.GpRegs[iBaseReg], Registers.SpaceRegs[iSpaceReg]));
                return true;
            };
        }

        /// <summary>
        /// Register indirect, with offset in multiple fields, shifted by the element size
        /// </summary>
        private static Mutator<PaRiscDisassembler> Msh(PrimitiveType dt, Bitfield[] fields, int baseRegPos, int spacePos)
        {
            var baseRegField = BeField(baseRegPos, 5);
            var spaceRegField = BeField(spacePos, 2);
            return (u, d) =>
            {
                var disp = Bitfield.ReadSignedFields(fields, u) * dt.Size;
                var iBaseReg = baseRegField.Read(u);
                var iSpaceReg = spaceRegField.Read(u);
                d.ops.Add(MemoryOperand.Indirect(dt, disp, Registers.GpRegs[iBaseReg], Registers.SpaceRegs[iSpaceReg]));
                return true;
            };
        }

        /// <summary>
        /// Register indirect indexed
        /// </summary>
        private static Mutator<PaRiscDisassembler> Mx(PrimitiveType dt, int baseRegPos, int idxRegPos)
        {
            var baseRegField = BeField(baseRegPos, 5);
            var idxRegField = BeField(idxRegPos, 5);
            return (u, d) =>
            {
                var iBaseReg = baseRegField.Read(u);
                var iIdxReg = idxRegField.Read(u);
                d.ops.Add(MemoryOperand.Indexed(dt, Registers.GpRegs[iBaseReg], Registers.GpRegs[iIdxReg]));
                return true;
            };
        }

        /// <summary>
        /// Register indirect indexed with address space
        /// </summary>
        private static Mutator<PaRiscDisassembler> Mx(PrimitiveType dt, int baseRegPos, int idxRegPos, int spaceRegPos)
        {
            var baseRegField = BeField(baseRegPos, 5);
            var idxRegField = BeField(idxRegPos, 5);
            var spaceRegField = BeField(spaceRegPos, 2);
            return (u, d) =>
            {
                var iBaseReg = baseRegField.Read(u);
                var iIdxReg = idxRegField.Read(u);
                var iSpaceRegField = spaceRegField.Read(u);
                var am = Bitfield.ReadFields(amFields, u);
                d.addrMod = (am == 1 && iIdxReg == 0)
                    ? BaseRegMod.o
                    : baseRegMods[am];
                d.ops.Add(MemoryOperand.Indexed(dt, Registers.GpRegs[iBaseReg], Registers.GpRegs[iIdxReg], Registers.SpaceRegs[iSpaceRegField]));
                return true;
            };
        }

        /// <summary>
        /// PC-relative address.
        /// </summary>
        private static Mutator<PaRiscDisassembler> PcRel(Func<uint, Bitfield[],uint> permutator, Bitfield[] fields)
        {
            int totalWidth = fields.Sum(f => f.Length);
            return (u, d) =>
            {
                var offset = (int)Bits.SignExtend(permutator(u, fields), totalWidth) * 4 + 8;
                var addrDst = d.addr + offset;
                d.ops.Add(AddressOperand.Create(addrDst));
                return true;
            };
        }

        /// <summary>
        /// Annul bit.
        /// </summary>
        private static Mutator<PaRiscDisassembler> Annul(int bitPos)
        {
            return (u, d) =>
            {
                d.annul = Bits.IsBitSet(u, 31 - bitPos);
                return true;
            };
        }

        /// <summary>
        /// Co-processor selector.
        /// </summary>
        private static Mutator<PaRiscDisassembler> cop(int bitPos, int bitLength)
        {
            var field = BeField(bitPos, bitLength);
            return (u, d) =>
            {
                d.coprocessor = (int) field.Read(u);
                return true;
            };
        }

        // Set the 'z' completer
        private static Mutator<PaRiscDisassembler> z(int bitPos)
        {
            var field = BeField(bitPos, 1);
            return (u, d) =>
            {
                d.zero = field.Read(u) == 0;
                return true;
            };
        }

        // Set the 'sign-extend' completer
        private static Mutator<PaRiscDisassembler> se(int bitPos)
        {
            var field = BeField(bitPos, 1);
            return (u, d) =>
            {
                d.signExtend = field.Read(u) == 0 
                    ? SignExtension.u
                    : SignExtension.s;
                return true;
            };
        }

        // Set the 'fpFormat' completer
        private static readonly Bitfield fpFmtField = BeField(19, 2);
        private static readonly Dictionary<uint, FpFormat> fpFormats = new Dictionary<uint, FpFormat>
        {
            { 0, FpFormat.sgl },
            { 1, FpFormat.dbl },
            { 3, FpFormat.quad },
        };
        private static bool fpFmt(uint uInstr, PaRiscDisassembler dasm)
        {
            var uFormat = fpFmtField.Read(uInstr);
            return fpFormats.TryGetValue(uFormat, out dasm.fpFormat);
        }

        private static bool Eq0(uint u) => u == 0;
        private static bool IsFpuProcessor(uint u) => (u & ~1) == 0;

        // Assembles a 6-bit extract/deposit length specifier:
        private static uint assemble_6(uint u, Bitfield[] fields)
        {
            var x = fields[0].Read(u);
            var y = fields[1].Read(u);
            return 32 * x + (32 - y);
        }

        private static uint assemble_12(uint u, Bitfield[] fields)
        {
            // return(cat(y,x{10},x{0..9}))
            var x = fields[0].Read(u);
            var y = fields[1].Read(u);
            var p = y;
            p = (p << fields[0].Length) 
                | ((x << 10) & 0b1_00000_00000)
                | ((x >> 1) & 0b0_11111_11111);
            return p;
        }

        private static uint assemble_16(bool is64bit, uint u, Bitfield[] fields)
        {
            var x = fields[0].Read(u);
            var y = fields[1].Read(u);
            uint y_13 = y & 1;
            if (is64bit)
            {
                // return(cat(y{13},xor(y{13},x{0}),xor(y{13},x{1}),y{0..12}))

                uint x_0 = (x >> 1) & 1;
                uint x_1 = x & 1;
                uint p = y_13;
                p = (p << 1) | (y_13 ^ x_0);
                p = (p << 1) | (y_13 ^ x_1);
                p = (p << 13) | (y >> 1);
                return p;
            }
            else
            {
                uint p = ((8 - y_13) & 7) << 13;
                p = p | (y >> 1);
                return Bits.SignExtend(p, 16);
            }
        }

        private static uint assemble_16a(bool is64Bit, uint u, Bitfield[] fields)
        {
            var x = fields[0].Read(u);
            var y = fields[1].Read(u);
            var z = fields[2].Read(u);
            var p = ((8 - z) & 7) << 13;
            if (is64Bit)
            {
                // return(cat(z,xor(z,x{0}),xor(z,x{1}),y,0{0..1}))
                p = p ^ (x << 13);
            }
            p = p | (y << 2);
            return p;
        }

        private static uint assemble_17(uint u, Bitfield[] fields)
        {
            var x = fields[0].Read(u);
            var y = fields[1].Read(u);
            var z = fields[2].Read(u);
            var p = z;
            p = (p << fields[0].Length) | x;
            p = (p << fields[1].Length)
                | ((y << 10) & 0b1_00000_00000)
                | ((y >> 1)  & 0b0_11111_11111);
            return p;
        }

        private static Bitfield[] asm21_fields =
        {
            BeField(11+20, 1),
            BeField(11+9, 11),
            BeField(11+5, 2),
            BeField(11+0, 5),
            BeField(11+7, 2)
        };

        private static uint assemble_21(uint u, Bitfield[] fields)
        {
            var x = fields[0].Read(u);
            var p = Bitfield.ReadFields(asm21_fields, x);
            return p;
        }

        private static uint assemble_22(uint u, Bitfield[] fields)
        {
            var a = fields[0].Read(u);
            var b = fields[1].Read(u);
            var c = fields[2].Read(u);
            var d = fields[3].Read(u);
            var p = d;
            p = (p << fields[0].Length) | a;
            p = (p << fields[1].Length) | b;
            p = (p << fields[2].Length)
                | ((c << 10) & 0b1_00000_00000)
                | ((c >> 1) & 0b0_11111_11111);
            return p;
        }

        private static Func<bool, uint, Bitfield[], uint> low_sign_ext(int width)
        {
            return (is64bit, u, fields) =>
            {
                var x = fields[0].Read(u);
                var x_lsb = x & 1;
                var p = (x >> 1) | (x << (width - 1));
                return Bits.SignExtend(p, width);
            };
        }
        private static readonly Func<bool, uint, Bitfield[], uint> low_sign_ext5 = low_sign_ext(5);
        private static readonly Func<bool, uint, Bitfield[], uint> low_sign_ext11 = low_sign_ext(11);

        /// <summary>
        /// Decoders analyze the 32-bit instruction word and generate a disassembled instruction.
        /// </summary>
        private abstract class Decoder
        {
            public abstract PaRiscInstruction Decode(uint uInstr, PaRiscDisassembler dasm);

            public static void DumpMaskedInstruction(uint wInstr, uint shMask, string tag)
            {
                var hibit = 0x80000000u;
                var sb = new StringBuilder();
                for (int i = 0; i < 32; ++i)
                {
                    if ((shMask & hibit) != 0)
                    {
                        sb.Append((wInstr & hibit) != 0 ? '1' : '0');
                    }
                    else
                    {
                        sb.Append((wInstr & hibit) != 0 ? ':' : '.');
                    }
                    shMask <<= 1;
                    wInstr <<= 1;
                }
                if (!string.IsNullOrEmpty(tag))
                {
                    sb.AppendFormat(" {0}", tag);
                }
                Debug.Print(sb.ToString());
            }
        }

        private class InstrDecoder : Decoder
        {
            private readonly InstrClass iclass;
            private readonly Opcode opcode;
            private readonly Mutator<PaRiscDisassembler>[] mutators;

            public InstrDecoder(InstrClass iclass, Opcode opcode, params Mutator<PaRiscDisassembler> [] mutators)
            {
                this.iclass = iclass;
                this.opcode = opcode;
                this.mutators = mutators;
            }

            public override PaRiscInstruction Decode(uint uInstr, PaRiscDisassembler dasm)
            {
                foreach (var m in mutators)
                {
                    if (!m(uInstr, dasm))
                        return invalid.Decode(uInstr, dasm);
                }
                return new PaRiscInstruction
                {
                    InstructionClass = iclass,
                    Opcode = opcode,
                    Coprocessor = dasm.coprocessor,
                    Condition = dasm.cond,
                    Operands = dasm.ops.ToArray(),
                    Annul = dasm.annul,
                    Zero = dasm.zero,
                    Sign = dasm.signExtend,
                    BaseReg = dasm.addrMod,
                    FpFmt = dasm.fpFormat
                };
            }
        }

        private class MaskDecoder : Decoder
        {
            private readonly Bitfield bitfield;
            private readonly Decoder[] decoders;

            public MaskDecoder(Bitfield bitfield, Decoder [] decoders)
            {
                this.bitfield = bitfield;
                this.decoders = decoders;
            }

            public override PaRiscInstruction Decode(uint uInstr, PaRiscDisassembler dasm)
            {
                DumpMaskedInstruction(uInstr, bitfield.Mask << bitfield.Position, "");
                uint code = bitfield.Read(uInstr);
                return decoders[code].Decode(uInstr, dasm);
            }
        }

        private class ConditionalDecoder : Decoder
        {
            private readonly Bitfield field;
            private readonly Predicate<uint> predicate;
            private readonly Decoder trueDecoder;
            private readonly Decoder falseDecoder;

            public ConditionalDecoder(int bitPos, int bitLength, Predicate<uint> predicate, Decoder trueDecoder, Decoder falseDecoder)
            {
                this.field = BeField(bitPos, bitLength);
                this.predicate = predicate;
                this.trueDecoder = trueDecoder;
                this.falseDecoder = falseDecoder;
            }

            public override PaRiscInstruction Decode(uint uInstr, PaRiscDisassembler dasm)
            {
                DumpMaskedInstruction(uInstr, field.Mask << field.Position, "");
                var u = field.Read(uInstr);
                var cond = predicate(u);
                var decoder = cond ? trueDecoder : falseDecoder;
                return decoder.Decode(uInstr, dasm);
            }
        }

        private class NyiDecoder : Decoder
        {
            private readonly Opcode mnemonic;
            private readonly string message;

            public NyiDecoder(Opcode mnemonic, string message)
            {
                this.mnemonic = mnemonic;
                this.message = !string.IsNullOrEmpty(message) ? message : mnemonic.ToString();
            }

            public override PaRiscInstruction Decode(uint uInstr, PaRiscDisassembler dasm)
            {
                dasm.EmitUnitTest(
                    dasm.arch.Name,
                    uInstr.ToString("X8"),
                    message,
                    "PaRiscDis",
                    dasm.addr,
                    Console =>
                    {
                        Console.WriteLine($"    AssertCode(\"@@@\", 0x{uInstr:X8});");
                        Console.WriteLine();
                    });
                return new PaRiscInstruction
                {
                    InstructionClass = 0,
                    Opcode = mnemonic,
                    Operands = new MachineOperand[0]
                };
            }

            [Conditional("DEBUG")]
            private void EmitUnitTest(uint wInstr)
            {
                Console.WriteLine("    // Reko: a decoder for hppa instruction {0} at address(.*?) has not");
                Console.WriteLine("    // {0}", message);
                Console.WriteLine("    [Test]");
                Console.WriteLine("    public void PaRiscDis_{0:X8}()", wInstr);
                Console.WriteLine("    {");
                Console.WriteLine("        AssertCode(\"@@@\", \"{0:X8}\");", wInstr);
                Console.WriteLine("    }");
                Console.WriteLine("");
            }
        }


        private static InstrDecoder Instr(Opcode opcode, params Mutator<PaRiscDisassembler> [] mutators)
        {
            return new InstrDecoder(InstrClass.Linear, opcode, mutators);
        }

        private static InstrDecoder Instr(Opcode opcode, InstrClass iclass, params Mutator<PaRiscDisassembler>[] mutators)
        {
            return new InstrDecoder(iclass, opcode, mutators);
        }

        // Note: the bit positions are big-endian to follow the PA-RISC manual.
        private static MaskDecoder Mask(
            int bitPos,
            int bitLength,
            params Decoder[] decoders)
        {
            Debug.Assert(1 << bitLength == decoders.Length, $"Expected {1 << bitLength} decoders but saw {decoders.Length}");
            return new MaskDecoder(BeField(bitPos, bitLength), decoders);
        }

        private static MaskDecoder Mask(
            int bitPos,
            int bitLength,
            Decoder defaultDecoder,
            params (int, Decoder)[] sparseDecoders)
        {
            var decoders = Enumerable.Range(0, 1 << bitLength).Select(n => defaultDecoder).ToArray();
            foreach (var (i, d) in sparseDecoders)
            {
                decoders[i] = d;
            }
            return new MaskDecoder(BeField(bitPos, bitLength), decoders);
        }

        private static ConditionalDecoder Cond(
            int bitPos,
            int bitLength,
            Predicate<uint> predicate,
            Decoder trueDecoder,
            Decoder falseDecoder)
        {
            return new ConditionalDecoder(bitPos, bitLength, predicate, trueDecoder, falseDecoder);
        }

        private static NyiDecoder Nyi(string message)
        {
            return new NyiDecoder(Opcode.invalid, message);
        }

        private static NyiDecoder Nyi(Opcode opcode, string message)
        {
            return new NyiDecoder(opcode, message);
        }


        static PaRiscDisassembler()
        {
            invalid = Instr(Opcode.invalid, InstrClass.Invalid);

            var systemOp = Mask(19, 8, invalid,
                (0x00, Instr(Opcode.@break, InstrClass.Call|InstrClass.Transfer, u8(27,5), u16(6,13))),
                (0x20, Nyi(Opcode.sync, "")),
                (0x20, Nyi(Opcode.syncdma, "")),
                (0x60, Nyi(Opcode.rfi, "")),
                (0x65, Nyi(Opcode.rfir, "")),
                (0x6B, Nyi(Opcode.ssm, "")),
                (0x73, Nyi(Opcode.rsm, "")),
                (0xC3, Nyi(Opcode.mtsm, "")),
                (0x85, Cond(16,2, Eq0,
                    Instr(Opcode.ldsid, r6,r27),
                    Instr(Opcode.ldsid, sr(16),r27))),
                (0xC1, Instr(Opcode.mtsp, r(11,5),sr(16))),
                (0x25, Nyi(Opcode.mfsp, "")),
                (0xC2, Nyi(Opcode.mtctl, "")),
                (0x45, Nyi(Opcode.mfctl, "")));

            var memMgmt = Mask(19, 1,
                Nyi("memMgmt-19:0"),
                Mask(18, 8, invalid,
                    (0x60, Nyi(Opcode.idtlbt, "")),
                    (0x48, Nyi(Opcode.pdtlb, "")),
                    (0x49, Nyi(Opcode.pdtlbe, "")),
                    (0x58, Nyi(Opcode.pdtlb, "")),
                    (0x4A, Nyi(Opcode.fdc, "(index)")),
                    (0xCA, Nyi(Opcode.fdc, "(imm)")),
                    (0x4B, Nyi(Opcode.fdce, "")),
                    (0x4E, Nyi(Opcode.pdc, "")),
                    (0x4F, Nyi(Opcode.fic, "")),
                    (0x46, Nyi(Opcode.probe, "")),
                    (0xC6, Nyi(Opcode.probei, "")),
                    (0x47, Nyi(Opcode.probe, "")),
                    (0xC7, Nyi(Opcode.probei, "")),
                    (0x4D, Nyi(Opcode.lpa, "")),
                    (0x4C, Nyi(Opcode.lci, ""))));
            var arithLog = Mask(20, 6, invalid,
                (0x18, Mask(26, 1,
                    Instr(Opcode.add, cf16_add, r11,r6,r27),
                    Instr(Opcode.add, cf16_add64, r11,r6,r27))),
                (0x38, Nyi(Opcode.addo, "")),
                (0x1C, Instr(Opcode.add_c, cf16_add, r11, r6, r27)),
                (0x3C, Nyi(Opcode.addco, "")),
                (0x19, Nyi(Opcode.shladd, "")),
                (0x39, Nyi(Opcode.shladdo, "")),
                (0x1A, Instr(Opcode.shladd, r11,s(24, 2, PrimitiveType.Byte),r6,r27)),
                (0x3A, Nyi(Opcode.shladdo, "")),
                (0x1B, Nyi(Opcode.shladd, "")),
                (0x3B, Nyi(Opcode.shladdo, "")),
                (0x10, Nyi(Opcode.sub, "")),
                (0x30, Nyi(Opcode.subo, "")),
                (0x13, Nyi(Opcode.subt, "")),
                (0x33, Nyi(Opcode.subto, "")),
                (0x14, Instr(Opcode.sub_b, cf16_cmpsub, r11,r6,r27)),
                (0x34, Nyi(Opcode.subbo, "")),
                (0x11, Nyi(Opcode.ds, "")),
                (0x00, Nyi(Opcode.andcm, "")),
                (0x08, Instr(Opcode.and, cf16_log,r11,r6,r27)),
                (0x09, Instr(Opcode.or, cf16_log,r11,r6,r27)),
                (0x0A, Nyi(Opcode.xor, "")),
                (0x0E, Nyi(Opcode.uxor, "")),
                (0x22, Nyi(Opcode.comclr, "")),
                (0x26, Nyi(Opcode.uaddcm, "")),
                (0x27, Nyi(Opcode.uaddcmt, "")),
                (0x28, Instr(Opcode.add_l, cf16_add, r11,r6,r27)),
                (0x29, Nyi(Opcode.sh1addl, "")),
                (0x2A, Instr(Opcode.shladd, r11, u(24, 2, PrimitiveType.Byte), r6, r27)),
                (0x2B, Nyi(Opcode.sh3addl, "")),
                (0x2E, Nyi(Opcode.dcor, "")),
                (0x2F, Nyi(Opcode.idcor, "")));

            var indexMem = Mask(19, 1,  // opc=3
                Mask(22, 4, invalid,
                    (0x0, Instr(Opcode.ldb, Mx(PrimitiveType.Byte, 5, 11, 16), r27)),
                    (0x1, Instr(Opcode.ldh, Mx(PrimitiveType.Word16, 5, 11, 16), r27)),
                    (0x2, Instr(Opcode.ldw, Mx(PrimitiveType.Word32, 5, 11, 16), r27)),
                    (0x3, Nyi(Opcode.ldd, "(index")),
                    (0x4, Nyi(Opcode.ldda, "(index")),
                    (0x5, Nyi(Opcode.ldcd, "(index")),
                    (0x6, Nyi(Opcode.ldwa, "(index")),
                    (0x7, Nyi(Opcode.ldcw, "(index"))),
                Mask(22, 4, invalid,
                    (0x0, Instr(Opcode.ldb, Mshort(PrimitiveType.Byte), r27)),
                    (0x1, Instr(Opcode.ldh, Mshort(PrimitiveType.Word16), r27)),
                    (0x2, Instr(Opcode.ldw, Mshort(PrimitiveType.Word32), r27)),
                    (0x3, Nyi(Opcode.ldd, "(short")),
                    (0x4, Nyi(Opcode.ldda, "(short")),
                    (0x5, Nyi(Opcode.ldcd, "(short")),
                    (0x6, Nyi(Opcode.ldwa, "(short")),
                    (0x7, Nyi(Opcode.ldcw, "(short")),
                    (0x8, Instr(Opcode.stb, r27, Mshort(PrimitiveType.Byte))),
                    (0x9, Instr(Opcode.sth, r27, Mshort(PrimitiveType.Word16))),
                    (0xA, Instr(Opcode.stw, r27, Mshort(PrimitiveType.Word32))),
                    (0xB, Nyi(Opcode.std, "(short")),
                    (0xC, Nyi(Opcode.stby, "(short")),
                    (0xD, Nyi(Opcode.stdby, "(short")),
                    (0xE, Instr(Opcode.stwa, r27, Mshort(PrimitiveType.Word32))),
                    (0xF, Nyi(Opcode.stda, "(short"))));

            var spopN = Nyi("spopN");
            var coprW = Cond(23, 3, IsFpuProcessor,
                Mask(19, 1,
                    Mask(22, 1,
                        Nyi(Opcode.fldw, "(index)"),
                        Nyi(Opcode.fstw, "(index)")),
                    Mask(22, 1,
                        Instr(Opcode.fldw, M(PrimitiveType.Real32, 6, BeFields((11,5)), low_sign_ext5), fr27_24),
                        Instr(Opcode.fstw, fr27, M(PrimitiveType.Real32, 6, BeFields((11,5)), low_sign_ext5)))),
                invalid);
            var copr = Mask(21, 2,
                Nyi("FP 0C zero"),
                Nyi("FP 0C one"),
                Nyi("FP 0C two"),
                Mask(16, 3,
                    Nyi(Opcode.fadd, ""),
                    Nyi(Opcode.fsub, ""),
                    Instr(Opcode.fmpy, fpFmt, fr6, fr11, fr27),
                    Nyi(Opcode.fdiv, ""),

                    invalid,
                    invalid,
                    invalid,
                    invalid));
            var floatDecoder = Mask(21, 2,
                Nyi("FP 0E zero"),
                Nyi("FP 0E one"),
                Instr(Opcode.fcmp, cf27_fp, fr27_24,fr11_19),
                Nyi("FP 0E three"));
            var productSpecific = Nyi("productSpecific");
            var subi = Mask(20, 1,
                Instr(Opcode.subi, cf16_cmpsub, s(PrimitiveType.Int32, BeFields((21, 11)), low_sign_ext11), r6, r11),
                Instr(Opcode.subi_tsv, cf16_cmpsub, s(PrimitiveType.Int32, BeFields((21, 11)), low_sign_ext11), r6, r11));
            var addit = Nyi("addit");
            var addi = Mask(20, 1,
                Instr(Opcode.addi, cf16_add, s(PrimitiveType.Int32, BeFields((21,11)), low_sign_ext11),r6,r11), 
                Nyi("addi-tsv"));
            var extract = Mask(19, 2,
                Nyi("extract-00"),
                Nyi("extract-01"),
                Nyi("extract-10"),
                Instr(Opcode.extrw, cf16_shext, se(21), r6, u(22, 5,PrimitiveType.Byte), u8From32(27, 5), r11));
            var deposit = Mask(19, 2,
                Nyi("depw-var"),
                Nyi("depw-fixed"),
                Nyi("depwi-var"),
                Instr(Opcode.depwi, cf16_shext, z(21), s(11, 5, PrimitiveType.Byte), u8From31(22, 5), u(BeFields((0, 0), (27, 5)), assemble_6), r6));

            var branch = Mask(16, 3,
                Instr(Opcode.b_l, PcRel(assemble_17, BeFields((11,5),(19,11),(31,1))),r6, Annul(30)),
                Nyi(Opcode.gate, ""),
                Instr(Opcode.b_l, r11,r6,Annul(30)),
                Nyi(Opcode.blrpush, ""),

                invalid,
                Instr(Opcode.b_l, PcRel(assemble_22, BeFields((6,5),(11,5),(19,11),(31,1))),reg(Registers.GpRegs[2]), Annul(30)),
                Instr(Opcode.bv, Mx(PrimitiveType.Ptr32, 6, 11), Annul(30)),
                Nyi(Opcode.bve, ""));

            rootDecoder = Mask(0, 6,
                systemOp,
                memMgmt,
                arithLog,
                indexMem,

                spopN,
                Nyi(Opcode.diag, ""),
                Nyi(Opcode.fmpyadd, ""),
                invalid,

                Instr(Opcode.ldil, u(11, 21, PrimitiveType.Word32), r6),
                coprW,
                Instr(Opcode.addil, Left(BeFields((11,21)), assemble_21, 11), r6,reg(Registers.GpRegs[1])),
                Mask(19, 1,
                    Instr(Opcode.cstd, cop(23, 3), r27,Mx(PrimitiveType.Real64,6,11,16)),
                    Instr(Opcode.cstd, cop(23, 3), r27,Msh(PrimitiveType.Real64,BeFields((11,5)), 6, 16))),

                copr,
                Instr(Opcode.ldo, M(PrimitiveType.Word32, 6, BeFields((16,2),(18,14)), assemble_16),r11),
                floatDecoder,
                productSpecific,

                // 10
                Instr(Opcode.ldb, M(PrimitiveType.Byte, 6, BeFields((16, 2), (18, 14)), assemble_16), r11),
                Instr(Opcode.ldh, M(PrimitiveType.Word16, 6, BeFields((16, 2), (18, 14)), assemble_16), r11),
                Instr(Opcode.ldw, M(PrimitiveType.Word32, 6, BeFields((16, 2), (18, 14)), assemble_16), r11),
                Instr(Opcode.ldw, Mam(PrimitiveType.Word32, 6, BeFields((16,2), (18,11), (31,1)), assemble_16a), r11),

                invalid,
                invalid,
                invalid,
                invalid,

                Instr(Opcode.stb, r11,M(PrimitiveType.Byte, 6, BeFields((16,2), (18,14)),assemble_16)),
                Instr(Opcode.sth, r11,M(PrimitiveType.Word16, 6, BeFields((16,2), (18,14)),assemble_16)),
                Instr(Opcode.stw, r11,M(PrimitiveType.Word32, 6, BeFields((16, 2), (18, 14)), assemble_16)),
                Instr(Opcode.stw, r11,Mam(PrimitiveType.Word32, 6, BeFields((16, 2), (18, 11), (31,1)), assemble_16a)),

                invalid,
                invalid,
                invalid,
                invalid,

                // 20
                Instr(Opcode.cmpb,  InstrClass.ConditionalTransfer, cf16_cmp32_t,r11,r6,PcRel(assemble_12, BeFields((19,11),(31,1))), Annul(30)),
                Instr(Opcode.cmpib, InstrClass.ConditionalTransfer, cf16_cmp32_t,s(11,5,PrimitiveType.Word32),r6,PcRel(assemble_12, BeFields((19, 11), (31, 1))), Annul(30)),
                Instr(Opcode.cmpb,  InstrClass.ConditionalTransfer, cf16_cmp32_f,r11,r6,PcRel(assemble_12, BeFields((19, 11), (31, 1))), Annul(30)),
                Instr(Opcode.cmpib, InstrClass.ConditionalTransfer, cf16_cmp32_f,s(11,5,PrimitiveType.Word32),r6,PcRel(assemble_12, BeFields((19, 11), (31, 1))), Annul(30)),

                Nyi(Opcode.comiclr, ""),
                subi,
                Nyi(Opcode.fmpysub, ""),
                invalid,

                Instr(Opcode.addb, CTD, cf16_add_3, r11, r6,PcRel(assemble_12, BeFields((19,11),(31,1))), Annul(30)),
                Instr(Opcode.addib, CTD, cfadd_bitsize, lse(11,5),r6,PcRel(assemble_12, BeFields((19,11),(31,1))),Annul(30)),
                Instr(Opcode.addb, CTD, cf16_add_3_neg, r11, r6, PcRel(assemble_12, BeFields((19, 11), (31, 1))), Annul(30)),
                Instr(Opcode.addib, CTD, cfadd_bitsize_neg, lse(11,5),r6,PcRel(assemble_12, BeFields((19,11),(31,1))),Annul(30)),

                addit,
                addi,
                invalid,
                invalid,

                // 30
                Nyi(Opcode.bvb, ""),
                Nyi(Opcode.bb, ""),
                Instr(Opcode.movb, CTD, cf16_shext, r11,r6,PcRel(assemble_12, BeFields((19, 11), (31, 1))), Annul(30)),
                Instr(Opcode.movib, CTD, cf16_shext, lse(11,5),r6,PcRel(assemble_12, BeFields((19, 11), (31, 1))), Annul(30)),

                extract,
                deposit,
                invalid,
                invalid,

                Instr(Opcode.be,  TD, Msh(PrimitiveType.Ptr32, BeFields((11,5),(19,11),(31,1)),6,16),Annul(30)),
                Instr(Opcode.be_l,TD, Msh(PrimitiveType.Ptr32, BeFields((11,5),(19,11),(31,1)),6,16),Annul(30)),
                branch,
                invalid,

                invalid,
                invalid,
                invalid,
                invalid);
        }
    }
}
