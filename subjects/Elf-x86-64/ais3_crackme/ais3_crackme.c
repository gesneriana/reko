// ais3_crackme.c
// Generated by decompiling ais3_crackme
// using Reko decompiler version 0.7.2.0.

#include "ais3_crackme.h"

// 00000000004003C8: void _init()
void _init()
{
	call_gmon_start();
}

// 0000000000400410: void _start(Register (ptr Eq_5) rdx, Stack Eq_6 qwArg00)
void _start( * rdx, Eq_6 qwArg00)
{
	__align((char *) fp + 0x08);
	__libc_start_main(&globals->t4005C5, qwArg00, (char *) fp + 0x08, &globals->t400620, &globals->t4006B0, rdx, fp);
	__hlt();
}

// 000000000040043C: void call_gmon_start()
void call_gmon_start()
{
	word64 rax_4 = globals->qw600FE0;
	if (rax_4 != 0x00)
	{
		word64 rsp_17;
		byte SCZO_18;
		word64 rax_19;
		byte SZO_20;
		byte C_21;
		byte Z_22;
		word32 eax_23;
		eax();
	}
}

// 0000000000400460: void deregister_tm_clones(Register word64 r8)
void deregister_tm_clones(word64 r8)
{
	if (false && 0x00 != 0x00)
	{
		word64 rsp_42;
		word32 eax_43;
		word64 rax_44;
		word64 rbp_45;
		word64 r8_46;
		byte SCZO_47;
		byte CZ_48;
		byte SZO_49;
		byte C_50;
		byte Z_51;
		word32 edi_52;
		word64 rdi_53;
		eax();
	}
}

// 0000000000400490: void register_tm_clones(Register word64 r8)
void register_tm_clones(word64 r8)
{
	if (true && 0x00 != 0x00)
	{
		word64 rsp_47;
		word64 rax_48;
		word64 rbp_49;
		word64 r8_50;
		byte SCZO_51;
		word64 rdx_52;
		byte Z_53;
		byte SZO_54;
		byte C_55;
		word64 rsi_56;
		word64 rdi_57;
		word32 edx_58;
		edx();
	}
}

// 00000000004004D0: void __do_global_dtors_aux(Register word64 r8)
void __do_global_dtors_aux(word64 r8)
{
	if (globals->b601038 == 0x00)
	{
		deregister_tm_clones(r8);
		globals->b601038 = 0x01;
	}
}

// 00000000004004F0: void frame_dummy(Register word64 r8)
void frame_dummy(word64 r8)
{
	if (globals->qw600E08 == 0x00 || 0x00 == 0x00)
		register_tm_clones(r8);
	else
	{
		word64 rsp_44;
		byte SCZO_45;
		byte Z_46;
		word32 eax_47;
		word64 rax_48;
		byte SZO_49;
		byte C_50;
		word64 rbp_51;
		word32 edi_52;
		word64 rdi_53;
		word64 r8_54;
		word64 rdx_55;
		word32 edx_56;
		word64 rsi_57;
		eax();
		register_tm_clones(r8_54);
	}
}

// 0000000000400520: Register word32 verify(Register (arr Eq_133) rdi)
word32 verify(Eq_133 rdi[])
{
	word32 dwLoc0C_126 = 0x00;
	while (true)
	{
		word32 eax_122;
		if ((byte) (word32) (&(&(&(&(&(&(&(&(&(&(&(&(&(&(&(&(&(&(&rdi[(int64) (word32) (uint64) dwLoc0C_126].a0000)[0x00].a0000)[0x00].a0000)[0x00].a0000)[0x00].a0000)[0x00].a0000)[0x00].a0000)[0x00].a0000)[0x00].a0000)[0x00].a0000)[0x00].a0000)[0x00].a0000)[0x00].a0000)[0x00].a0000)[0x00].a0000)[0x00].a0000)[0x00].a0000)[0x00].a0000)[0x00].a0000)[0x00] == 0x00)
			break;
		byte al_73 = (byte) (uint64) ((word32) (uint64) dwLoc0C_126 ^ (word32) ((uint64) ((word32) (&((&((&((&((&((&((&((&((&((&((&((&((&((&((&((&((&((&((&(rdi)[(int64) ((word32) ((uint64) dwLoc0C_126))].a0000))[0x00].a0000))[0x00].a0000))[0x00].a0000))[0x00].a0000))[0x00].a0000))[0x00].a0000))[0x00].a0000))[0x00].a0000))[0x00].a0000))[0x00].a0000))[0x00].a0000))[0x00].a0000))[0x00].a0000))[0x00].a0000))[0x00].a0000))[0x00].a0000))[0x00].a0000))[0x00].a0000)[0x00])));
		uint64 rax_113 = (uint64) dwLoc0C_126;
		if ((byte) (word32) (DPB(rax_113, (int16) (byte) rax_113, 0) + 0x00601020) != (byte) ((uint64) ((word32) ((uint64) ((word32) ((uint64) ((word32) al_73 >> (byte) ((uint64) ((word32) ((uint64) (0x08 - (word32) ((uint64) ((word32) ((uint64) ((word32) ((uint64) ((word32) ((uint64) dwLoc0C_126) ^ 0x09)) & 0x03)))))))))))) | (word32) ((uint64) ((word32) ((uint64) ((word32) ((uint64) ((word32) al_73 << (byte) ((uint64) ((word32) ((uint64) ((word32) ((uint64) ((word32) ((uint64) dwLoc0C_126) ^ 0x09)) & 0x03)))))))))))) + 0x08)
		{
			eax_122 = 0x00;
			return eax_122;
		}
		dwLoc0C_126 = dwLoc0C_126 + 0x01;
	}
	eax_122 = (word32) (dwLoc0C_126 == 0x17);
	return eax_122;
}

// 00000000004005C5: void main(Register (ptr Eq_218) rsi, Register word32 edi)
void main(Eq_218 * rsi, word32 edi)
{
	if (edi != 0x02)
		puts("You need to enter the secret key!");
	else if (verify(rsi->ptr0008) != 0x00)
		puts("Correct! that is the secret key!");
	else
		puts("I'm sorry, that's the wrong secret key!");
}

// 0000000000400620: void __libc_csu_init(Register word32 edi)
void __libc_csu_init(word32 edi)
{
	_init();
	if (0x0000000000600E00 - 0x0000000000600DF8 >> 0x03 != 0x00)
	{
		do
		{
			word64 rsp_60;
			word64 rbp_61;
			word64 r12_62;
			word64 r13_63;
			word64 r14_64;
			word64 r15_65;
			word64 rbx_66;
			byte SCZO_67;
			word32 r13d_68;
			word32 edi_69;
			word64 rsi_70;
			word64 rdx_71;
			byte SZO_72;
			byte C_73;
			byte Z_74;
			word32 ebx_75;
			word64 rdi_76;
			globals->u600DF8();
		} while (rbx_66 + 0x01 != rbp_61);
	}
}

// 00000000004006B0: void __libc_csu_fini()
void __libc_csu_fini()
{
}

// 00000000004006B4: void _fini()
void _fini()
{
}

