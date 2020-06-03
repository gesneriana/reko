#region License
/* 
 * Copyright (C) 1999-2020 John Källén.
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
using Reko.Core.Machine;
using Reko.Core.Rtl;
using Reko.Core.Services;
using System.Collections;
using System.Collections.Generic;

namespace Reko.Arch.H8
{
    public class H8Rewriter : IEnumerable<RtlInstructionCluster>
    {
        private readonly H8Architecture arch;
        private readonly EndianImageReader rdr;
        private readonly ProcessorState state;
        private readonly IStorageBinder binder;
        private readonly IRewriterHost host;
        private readonly IEnumerator<H8Instruction> dasm;
        private RtlEmitter m;
        private InstrClass iclass;

        public H8Rewriter(H8Architecture arch, EndianImageReader rdr, ProcessorState state, IStorageBinder binder, IRewriterHost host)
        {
            this.arch = arch;
            this.rdr = rdr;
            this.state = state;
            this.binder = binder;
            this.host = host;
            this.dasm = new H8Disassembler(rdr).GetEnumerator();
            this.m = new RtlEmitter(new List<RtlInstruction>());
        }

        public IEnumerator<RtlInstructionCluster> GetEnumerator()
        {
            while (dasm.MoveNext())
            {
                var instr = dasm.Current;
                switch (instr.Mnemonic)
                {
                default:
                    EmitUnitTest(instr);
                    goto case Mnemonic.Invalid;
                case Mnemonic.Invalid:
                    m.Invalid();
                    iclass = InstrClass.Invalid;
                    break;
                }
                yield return m.MakeCluster(instr.Address, instr.Length, iclass);
                m = new RtlEmitter(new List<RtlInstruction>());
            }
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            return GetEnumerator();
        }

        private void EmitUnitTest(MachineInstruction instr, string message = "")
        {
            var testgenSvc = arch.Services.GetService<ITestGenerationService>();
            testgenSvc?.ReportMissingRewriter("H8Rw", instr, rdr, message);
        }
    }
}