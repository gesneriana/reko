// test.c
// Generated by decompiling test
// using Reko decompiler version 0.7.2.0.

#include "test.h"

// 00000588: void _init(Register (ptr Eq_2) ra)
void _init(Eq_2 * ra)
{
	if (__gmon_start__ == 0x00)
	{
		word32 sp_25;
		word32 r28_26;
		word32 r25_27;
		struct Eq_17 * ra_28;
		word32 r2_29;
		bcuiposr0 None_30;
		(ra->ptr104F4 + 2004)();
		word32 sp_36;
		word32 r28_37;
		word32 r25_38;
		word32 ra_39;
		word32 r2_40;
		bcuiposr0 None_41;
		(ra_28->ptr104D0 + 0x0970)();
	}
	else
	{
		word32 sp_12;
		word32 r28_13;
		word32 r25_14;
		word32 ra_15;
		word32 r2_16;
		bcuiposr0 None_17;
		__gmon_start__();
	}
}

// 00000610: void __start(Register (ptr Eq_37) ra, Stack word32 dwArg00)
void __start(Eq_37 * ra, word32 dwArg00)
{
	<anonymous> * r25_23 = ra->ptr104C0;
	word32 sp_24;
	word32 ra_25;
	word32 r0_26;
	word32 r28_27;
	word32 r4_28;
	word32 r5_29;
	word32 r6_30;
	word32 r1_31;
	word32 r7_32;
	word32 r8_33;
	word32 r2_34;
	word32 r25_35;
	r25_23();
	while (true)
		;
}

// 00000670: void deregister_tm_clones()
void deregister_tm_clones()
{
	word32 r2_8 = globals->dw10AA4;
	if (r2_8 != globals->ptr10AA8 + 2692)
	{
		if (__gmon_start__ != null)
		{
			word32 sp_19;
			word32 r28_20;
			word32 r25_21;
			word32 r4_22;
			word32 r2_23;
			word32 ra_24;
			__gmon_start__();
		}
	}
}

// 000006A8: void register_tm_clones()
void register_tm_clones()
{
	int32 r5_10 = globals->dw10AA4 - (globals->ptr10AA8 + 2692);
	Eq_81 r2_12 = r5_10 >> 0x02 >> 0x1F;
	if ((word32) r2_12 + (r5_10 >> 0x02) >> 0x01 != 0x00)
	{
		if (__gmon_start__ != null)
		{
			word32 sp_23;
			word32 r28_24;
			word32 r25_25;
			word32 r4_26;
			word32 r5_27;
			word32 r2_28;
			__gmon_start__();
		}
	}
}

// 000006F4: void __do_global_dtors_aux()
void __do_global_dtors_aux()
{
	struct Eq_60 * r19_10 = globals->ptr10AA8;
	if ((word32) r19_10[2800] == 0x00)
	{
		if (__gmon_start__ != 0x00)
		{
			word32 sp_104;
			word32 r28_105;
			word32 r25_106;
			word32 ra_108;
			word32 r18_109;
			word32 r17_110;
			word32 r16_111;
			word32 r2_112;
			word32 r4_113;
			word32 r3_114;
			__gmon_start__();
		}
		struct Eq_60 * r17_52 = globals->ptr10AA8;
		struct Eq_60 * r2_50 = globals->ptr10AA8;
		Eq_119 r2_56 = r17_52[0x0AF4];
		Eq_119 r16_58 = (globals->dw10AB0 - (r2_50 + 2664) >> 0x02) + -0x01;
		int32 r18_54 = r2_50 + 2664;
		if ((word32) (r2_56 < r16_58) != 0x00)
		{
			do
			{
				int32 r2_78 = (word32) r2_56 + 0x01;
				r17_52[0x0AF4] = (struct Eq_60) r2_78;
				<anonymous> ** r2_81 = r18_54 + (r2_78 << 0x02);
				<anonymous> * r25_82 = *r2_81;
				word32 sp_83;
				word32 r28_84;
				word32 r25_85;
				word32 ra_87;
				Eq_119 r16_90;
				word32 r2_91;
				word32 r4_92;
				word32 r3_93;
				r25_82();
				r2_56 = r17_52[0x0AF4];
			} while ((word32) (r2_56 < r16_90) != 0x00);
		}
		if (true)
		{
			deregister_tm_clones();
			return;
		}
		r19_10[2800] = (struct Eq_60) 0x01;
	}
}

// 000007D4: void frame_dummy()
void frame_dummy()
{
	register_tm_clones();
}

// 000007F0: void main(Stack word32 dwArg00, Stack word32 dwArg04)
void main(word32 dwArg00, word32 dwArg04)
{
	memset(r4_20, r5_19, r6_18);
	calloc(r4_35, r5_34);
	r2_45->t0000 = dwLoc14;
	r2_45->b0004 = (byte) (word32) bLoc10;
	r2_45->t0000.u0 = 0x0C;
	r2_45->dw0001 = 0x00;
	struct Eq_210 * r2_50 = r2_45;
	Eq_209 r3_52 = dwLoc14;
	struct Eq_210 * r2_62 = r2_45;
}

// 000008C0: void __libc_csu_init(Register (ptr Eq_2) ra)
void __libc_csu_init(Eq_2 * ra)
{
	if (true)
		_init(ra);
	else
	{
		word32 * r16_45 = globals->ptr10ABC;
		if (globals->ptr10ABC - r16_45 >> 0x02 != 0x00)
		{
			while (true)
			{
				<anonymous> * r25_68 = *r16_45;
				word32 sp_73;
				word32 r28_74;
				word32 r25_75;
				word32 r21_76;
				word32 r6_77;
				word32 r20_78;
				word32 r5_79;
				word32 r19_80;
				word32 r4_81;
				word32 r18_82;
				word32 r16_83;
				word32 ra_84;
				word32 r17_85;
				r25_68();
				if (r18_82 == r17_85)
					break;
				r16_45 = r16_83 + 0x04;
			}
		}
	}
}

// 00000964: void __libc_csu_fini()
void __libc_csu_fini()
{
}

// 00000970: void __do_global_ctors_aux()
void __do_global_ctors_aux()
{
	struct Eq_60 * r3_7 = globals->ptr10AA8;
	<anonymous> * r25_17 = r3_7[2656];
	if (r25_17 != (<anonymous> *) -0x01)
	{
		do
		{
			word32 sp_30;
			word32 r28_31;
			word32 r25_32;
			word32 r3_33;
			word32 r2_34;
			word32 ra_35;
			word32 r17_36;
			int32 * r16_37;
			r25_17();
		} while (*r16_37 != -0x01);
	}
}

// 00000A10: void _fini(Register (ptr Eq_288) ra)
void _fini(Eq_288 * ra)
{
	word32 sp_16;
	word32 r28_17;
	word32 r25_18;
	word32 ra_19;
	bcuiposr0 None_20;
	(ra->ptr10084 + 0x06F4)();
}

