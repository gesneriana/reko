// test.c
// Generated by decompiling test
// using Reko decompiler version 0.8.0.0.

#include "test.h"

// 00000000004003E0: void _init()
void _init()
{
	word64 rax_4 = globals->qw600FF8;
	if (rax_4 != 0x00)
	{
		word64 rsp_15;
		byte SCZO_16;
		word64 rax_17;
		byte SZO_18;
		byte C_19;
		byte Z_20;
		__gmon_start__();
	}
}

// 0000000000400440: void _start(Register (ptr Eq_16) rdx, Stack Eq_17 qwArg00)
void _start( * rdx, Eq_17 qwArg00)
{
	__align((char *) fp + 0x08);
	__libc_start_main(&globals->t40053D, qwArg00, (char *) fp + 0x08, &globals->t400550, &globals->t4005C0, rdx, fp);
	__hlt();
}

// 0000000000400470: void deregister_tm_clones(Register word64 r8)
void deregister_tm_clones(word64 r8)
{
	if (true || 0x00 == 0x00)
		return;
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
	null();
}

// 00000000004004A0: void register_tm_clones(Register word64 r8)
void register_tm_clones(word64 r8)
{
	if (false || 0x00 == 0x00)
		return;
	word64 rsp_45;
	word64 rax_46;
	word64 rbp_47;
	word64 r8_48;
	byte SCZO_49;
	word64 rdx_50;
	byte Z_51;
	byte SZO_52;
	byte C_53;
	word64 rsi_54;
	word64 rdi_55;
	null();
}

// 00000000004004E0: void __do_global_dtors_aux(Register word64 r8)
void __do_global_dtors_aux(word64 r8)
{
	if (globals->b601040 == 0x00)
	{
		deregister_tm_clones(r8);
		globals->b601040 = 0x01;
	}
}

// 0000000000400500: void frame_dummy(Register word64 r8)
void frame_dummy(word64 r8)
{
	if (globals->qw600E20 == 0x00 || 0x00 == 0x00)
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
		fn0000000000000000();
		register_tm_clones(r8_54);
	}
}

// 000000000040052D: void f()
void f()
{
	putchar(0x78);
}

// 000000000040053D: void main()
void main()
{
	f();
}

// 0000000000400550: void __libc_csu_init(Register word32 edi)
void __libc_csu_init(word32 edi)
{
	_init();
	if (0x00600E18 - 0x00600E10 >> 0x03 != 0x00)
	{
		do
		{
			word64 rsp_69;
			word64 r15_70;
			word32 r15d_71;
			word32 edi_72;
			word64 r14_73;
			word64 rsi_74;
			word64 r13_75;
			word64 rdx_76;
			word64 r12_77;
			word64 rbp_78;
			word64 rbx_79;
			byte SCZO_80;
			word32 ebx_81;
			byte SZO_82;
			byte C_83;
			byte Z_84;
			word64 rdi_85;
			globals->ptr600E10();
		} while (rbx_79 + 0x01 != rbp_78);
	}
}

// 00000000004005C0: void __libc_csu_fini()
void __libc_csu_fini()
{
}

// 00000000004005C4: void _fini()
void _fini()
{
}

