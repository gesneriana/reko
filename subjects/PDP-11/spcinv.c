// spcinv.c
// Generated by decompiling spcinv.sav
// using Reko decompiler version 0.7.2.0.

#include "spcinv.h"

// 0200: void fn0200(Register Eq_2 r4, Register (ptr Eq_3) r5, Register (ptr Eq_4) pc)
void fn0200(Eq_2 r4, Eq_3 * r5, Eq_4 * pc)
{
	do
	{
		PRINT(&globals->b0F9A);
		ptr16 sp_143 = fp;
		word16 r2_29 = 0x02;
		Eq_14 r3_115 = 0x00;
		do
		{
			word16 r0_14;
		} while (TTYIN(out r0_14));
		do
		{
			word16 r0_19;
		} while (TTYIN(out r0_19));
		do
		{
			word16 r0_21;
		} while (TTYIN(out r0_21));
		if (0xF0A8 == 0x00)
		{
			PRINT(&globals->b0FDA);
			do
			{
				word16 r0_393;
			} while (TTYIN(out r0_393));
			break;
		}
		r2_29 = 0x01;
		r3_115.u0 = 0x01;
		if (~0x0F50 == 0x00)
			break;
		r2_29 = 0x00;
		r3_115.u0 = 0x02;
	} while (61611 == 0x00);
	globals->w0F06 = r2_29;
	globals->u0F08 = r3_115;
	globals->w0024 = globals->w0024 | 0x1040;
	globals->w1166 = 0x1100;
	globals->w1168 = 4464;
	FnSubfn(&globals->w1166);
	globals->w0AB4 = globals->w1170;
	globals->w0B5E = 0x00;
	globals->w1166 = 0x0101;
	globals->w1168 = 4446;
	FnSubfn(&globals->w1166);
	if (true)
	{
		globals->w1166 = 0x0801;
		globals->w1168 = 0x00;
		globals->w116A = 0x0B5E;
		globals->w116C = 0x01;
		globals->w116E = 0x00;
		FnSubfn(&globals->w1166);
		__syscall(0x88FC);
	}
	ptr16 r2_237;
	Eq_99 r1_110 = fn0BD6(out r2_237);
l02A2:
	fn0C20(r3_115, r5, pc);
l02A6:
	Eq_153 r0_90;
	if (!TTYIN(out r0_90) && globals->ptr0EFA == 0x00)
	{
		globals->u02CB = r0_90;
		word16 * r1_341 = &globals->w02C6;
		do
		{
			r1_341 = r1_395 + 0x01;
			word16 * r1_395 = r1_341;
		} while (*r1_395 - r0_90 != 0x00);
		struct Eq_169 * r1_351 = r1_341 - 711 << 0x01;
		word16 sp_353;
		word16 r2_354;
		byte NZ_355;
		bool V_356;
		word16 r3_357;
		bool C_358;
		bool N_359;
		bool Z_360;
		word16 r0_361;
		word16 r1_362;
		byte NZVC_363;
		byte NZV_364;
		word16 pc_365;
		word16 r4_366;
		byte ZC_367;
		word16 r5_368;
		r1_351->ptr02CC();
		return;
	}
	globals->w1166 = 0x1100;
	globals->w1168 = 4464;
	FnSubfn(&globals->w1166);
	Eq_135 r0_101 = globals->w1170 - globals->w1172;
	if (r0_101 < 0x00)
	{
		if (0x1178 - r4 == 0x00)
			goto l02A6;
		fn0AF6(r1_110, r3_115, r4, r5, bArg00);
	}
	globals->w1174 = globals->w1170;
	pc->w0E52 = pc->w0E52 + 0x01;
	globals->w0EF6 = ~globals->w0EF4;
	if (v49 == 0x00)
		globals->w0EF8 = ~globals->w0EF6;
	if (globals->ptr0EFA != 0x00)
	{
		globals->w0EFC = globals->ptr0EFA - 0x01;
		if (v55 != 0x00)
			goto l0370;
		if (globals->w0F18 == 0x00)
			goto l03AE;
		Eq_14 r3_313;
		Eq_2 r4_314;
		struct Eq_3 * r5_315;
		Eq_135 r0_316 = fn0486(r0_101, r1_110, r3_115, r4, r5, bArg00, out r3_313, out r4_314, out r5_315);
		globals->w0F16 = 0x02;
		r4 = fn0470(r0_316, r1_110, r2_237, r3_313, r4_314, r5_315, bArg00);
		globals->w0F18 = 0x78;
	}
	if (globals->w0EF8 != 0x00)
	{
l036C:
		word16 r2_278;
		byte NZ_279;
		bool V_280;
		word16 r3_281;
		bool C_282;
		bool N_283;
		bool Z_284;
		word16 r0_285;
		byte NZVC_287;
		byte NZV_288;
		byte ZC_291;
		word16 r5_292;
		globals->ptr0EFA();
		goto l0370;
	}
	else
	{
		if (0x08 - globals->w0F14 < 0x00)
		{
			globals->w0F18 = globals->w0F16 - 0x01;
			if (v91 <= 0x00)
			{
				globals->ptr0EFA = 1110;
				goto l036C;
			}
		}
l0370:
		Eq_2 r4_227;
		struct Eq_3 * r5_228;
		Eq_99 r1_229 = fn04A0(r1_110, r4, pc, out r4_227, out r5_228);
		Eq_99 r1_231;
		Eq_14 r3_232;
		Eq_2 r4_233;
		struct Eq_3 * r5_234;
		Eq_135 r0_235 = fn07A6(fn06D6(r1_229, r4_227, r5_228, pc), pc, out r1_231, out r3_232, out r4_233, out r5_234);
		r0_101 = fn0998(r0_235, r1_231, r3_232, r4_233, r5_234, pc, bArg00, out r1_110, out r2_237, out r3_115, out r4, out r5);
		if (0x1178 - r4 != 0x00)
			break;
		if (globals->w0F12 != 0x00)
			continue;
		if (globals->w0F02 != 0x00)
			continue;
		if (true)
		{
			globals->w0F1A = globals->w0F18 + 0x01;
			goto l02A2;
		}
l03AE:
		cu16 v67_144 = globals->w0B5A - globals->w0B5A;
		if (v67_144 > 0x00)
		{
			globals->w0B5E = globals->w0B5A;
			globals->w1166 = 0x0101;
			globals->w1168 = 4446;
			FnSubfn(&globals->w1166);
			if (v67_144 >= 0x00)
			{
l03E6:
				globals->w1166 = 0x0901;
				globals->w1168 = 0x00;
				globals->w116A = 0x0B5E;
				globals->w116C = 0x01;
				globals->w116E = 0x00;
				FnSubfn(&globals->w1166);
				__syscall(0x88FC);
				r0_101.u0 = 0x0601;
				goto l040A;
			}
			globals->w1166 = 0x0201;
			globals->w1168 = 4446;
			globals->w116A = 0x01;
			FnSubfn(&globals->w1166);
			r0_101.u0 = 4454;
			if (v67_144 >= 0x00)
				goto l03E6;
		}
l040A:
		Eq_14 r3_160;
		Eq_2 r4_161;
		struct Eq_3 * r5_162;
		Eq_135 r0_163 = fn0486(r0_101, r1_110, r3_115, r4, r5, bArg00, out r3_160, out r4_161, out r5_162);
		struct Eq_403 * sp_164 = sp_143 - 0x01;
		sp_164->b0000 = 0x01;
		sp_164->b0001 = 0x18;
		Eq_2 r4_170;
		struct Eq_3 * r5_171;
		fn0AB6(r0_163, r1_110, r3_160, r4_161, r5_162, out r4_170, out r5_171);
		Eq_2 r4_174;
		struct Eq_3 * r5_175;
		Eq_135 r0_176 = fn0AE8(r0_163, r4_170, r5_171, wLoc02, out r4_174, out r5_175);
		*(r1_110 - 0x02) = (union Eq_2 *) r4_174;
		word16 r4_182;
		word16 r5_183;
		fn0AE8(r0_176, r4_174, r5_175, wLoc02, out r4_182, out r5_183);
	}
}

// 0470: Register Eq_2 fn0470(Register Eq_135 r0, Register Eq_99 r1, Register ptr16 r2, Register Eq_14 r3, Register Eq_2 r4, Register (ptr Eq_3) r5, Stack byte bArg00)
Eq_2 fn0470(Eq_135 r0, Eq_99 r1, ptr16 r2, Eq_14 r3, Eq_2 r4, Eq_3 * r5, byte bArg00)
{
	word16 wLoc02_6 = DPB(wLoc02, globals->w0F14, 8);
	Eq_2 r4_16;
	struct Eq_3 * r5_17;
	fn0AB6(r0, r1, r3, r4, r5, out r4_16, out r5_17);
	Eq_2 r4_19;
	word16 r5_20;
	fn0AE8(r0, r4_16, r5_17, wLoc02_6, out r4_19, out r5_20);
	*(r2 - 0x02) = (union Eq_2 *) r4_19;
	return r4_19;
}

// 0486: Register Eq_135 fn0486(Register Eq_135 r0, Register Eq_99 r1, Register Eq_14 r3, Register Eq_2 r4, Register (ptr Eq_3) r5, Stack byte bArg00, Register out ptr16 r3Out, Register out ptr16 r4Out, Register out ptr16 r5Out)
Eq_135 fn0486(Eq_135 r0, Eq_99 r1, Eq_14 r3, Eq_2 r4, Eq_3 * r5, byte bArg00, ptr16 & r3Out, ptr16 & r4Out, ptr16 & r5Out)
{
	Eq_2 r4_14;
	struct Eq_3 * r5_15;
	word16 r3_16;
	*r3Out = fn0AB6(r0, r1, r3, r4, r5, out r4_14, out r5_15);
	word16 r4_17;
	word16 r5_18;
	return fn0A74(r0, r4_14, r5_15, out r4_17, out r5_18);
}

// 04A0: Register Eq_99 fn04A0(Register Eq_99 r1, Register Eq_2 r4, Register (ptr Eq_4) pc, Register out ptr16 r4Out, Register out ptr16 r5Out)
Eq_99 fn04A0(Eq_99 r1, Eq_2 r4, Eq_4 * pc, ptr16 & r4Out, ptr16 & r5Out)
{
	*r4Out = r4;
	*r5Out = r5;
	cui16 v5_4 = pc->w0A52 & globals->w0EF4;
	pc->w0A52 = v5_4;
	struct Eq_638 * sp_1 = fp;
	if (v5_4 != 0x00)
		return r1;
	struct Eq_3 * r5_100 = globals->ptr0F04;
l04AE:
	Eq_14 r3_54 = (int16) r5_100[0x0778];
	if (r3_54 != 0x00)
	{
		globals->u0F0C = r3_54;
		Eq_135 r0_92 = (int16) r5_100->b0EF3;
		sp_1 = sp_1 - 0x01;
		sp_1->b0000 = (byte) r3_54;
		sp_1->b0001 = (byte) r0_92;
		byte * r4_99;
		Eq_14 r3_101 = fn0AB6(r0_92, r1, r3_54, r4, r5_100, out r4_99, out r5_100);
		*r4_99 = 0x20;
		r4 = r4_99 + 0x01;
		*r4Out = r4;
		Eq_135 r0_105 = r0_92 - 0x01;
		if ((false || 0x04 - (r0_92 - 0x01) > 0x00) && 0x02 - (r0_92 - 0x01) != 0x00)
		{
			r5_100->b0EF3 = (byte) (r0_92 - 0x01);
			if (22 - (r0_92 - 0x01) < 0x00 || !fn067C(r0_92 - 0x01, r3_101, r4_99 + 0x01, r5_100, bLoc02, out r0_105, out r1, out r3_101, out r4, out r5_100))
			{
				r1 = (word16) r0_105 + 0x01;
				if (0x03 - r0_105 != 0x00 || (false || !fn05D4(r0_105, r1, r3_101, r4, r5_100, pc, bLoc02, out r0_105, out r1, out r3_101, out r4, out r5_100)))
				{
					Eq_135 r0_155;
					if (!fn064A(r0_105, r1, r3_101, r4, r5_100, out r0_155, out r4, out r5_100))
					{
						struct Eq_768 * r2_159 = null;
l050C:
						if (r2_159[0x06DC] - r0_155 != 0x00)
						{
							cu16 v43_336 = r2_159[0x06DC] - r1;
							if (v43_336 < 0x00)
								break;
							if (v43_336 != 0x00)
							{
								r2_159 = r2_159 + 0x01;
								if (0x0A - r2_159 <= 0x00)
									goto l050C;
								Eq_2 r4_190;
								struct Eq_3 * r5_191;
								Eq_135 r0_192 = fn0AE8(r0_155, r4, r5_100, wLoc02, out r4_190, out r5_191);
								sp_1->b0000 = (byte) r4_190;
								byte * r4_198;
								struct Eq_3 * r5_199;
								Eq_135 r0_200 = fn0AE8(r0_192, r4_190, r5_191, wLoc02, out r4_198, out r5_199);
								byte ** r1_201 = r1 - 0x02;
								*r1_201 = (byte **) r4_198;
								*r4_198 = globals->b1159;
								fn0AE8(r0_200, r4_198 + 0x01, r5_199, wLoc02, out r4, out r5_100);
								*(r1_201 - 0x02) = (union Eq_2 *) r4;
								sp_1 = sp_1 + 0x01;
								r1 = r1_201 - 0x02;
l05CA:
								r5_100 = r5_100 - 0x01;
								*r5Out = r5_100;
								if (r5_100 >= null)
									goto l04AE;
								return r1;
							}
						}
						r0_155 = r2_159[0x06D6];
						r1.u0 = 0x08;
						do
						{
							Eq_14 r3_233 = *r0_155;
							if (r3_233 != 0x00)
							{
								if (true)
								{
									if ((word16) r3_233 + 0x04 - r5_100[0x0778] <= 0x00)
									{
										if (*r0_155 - r5_100[0x0778] < 0x00)
											break;
										Eq_99 r1_266 = *r0_155;
										*r0_155 = *r0_155 | 0x8000;
										Eq_135 r0_269 = r0_155 - r2_159[0x06D6];
										globals->u0F0A = r0_269;
										*((word16) r0_269 + 0x0DC4) = *((word16) r0_269 + 0x0DC4) - 0x01;
										sp_1 = sp_1 - 0x01;
										sp_1->b0000 = (byte) r1_266;
										sp_1->b0001 = (byte) r2_159[0x06DC];
										byte * r4_279;
										struct Eq_3 * r5_280;
										fn0AB6(r0_269, r1_266, (word16) r3_233 + 0x04, r4, r5_100, out r4_279, out r5_280);
										Eq_99 r1_282;
										Eq_2 r4_283;
										struct Eq_3 * r5_284;
										fn0A7C(r0_269, r1_266, r4_279, r5_280, pc, out r1_282, out r4_283, out r5_284);
										pc->w05F2 = (word16) r2_159[1770] + pc->w05F2;
										word16 r3_291;
										fn0B1A(r1_282, r4_283, r5_284, bLoc02, out r1, out r3_291, out r4, out r5_100);
										globals->w0F14 = globals->w0F12 - 0x01;
										if (v79 <= 0x00 && true)
										{
											globals->ptr0EFA = 0x00;
											globals->w0EFC = 0x05;
										}
										goto l0584;
									}
								}
								else
								{
									struct Eq_858 * sp_310 = sp_1 - 0x01;
									sp_310->b0000 = (byte) *r0_155;
									sp_310->t0001 = r2_159[0x06DC];
									Eq_2 r4_316;
									struct Eq_3 * r5_317;
									fn0AB6(r0_155, r1, r3_233, r4, r5_100, out r4_316, out r5_317);
									Eq_2 r4_319;
									struct Eq_3 * r5_320;
									r0_155 = fn0A74(r0_155, r4_316, r5_317, out r4_319, out r5_320);
									*r0_155 = 0x00;
									int16 r3_325 = (int16) r5_320[0x0778];
									*(sp_310 - 0x01) = (union Eq_896 *) (r3_325 + 0x01);
									sp_310->b0000 = r5_320->b0EF3;
									fn0AB6(r0_155, r1, r3_325 + 0x01, r4_319, r5_320, out r4, out r5_100);
									sp_1 = sp_310 - 0x01;
								}
							}
							r0_155 = (word16) r0_155 + 0x02;
							r1 = r1 - 0x01;
						} while (r1 != 0x00);
						break;
					}
				}
			}
		}
l0584:
		r5_100[0x0778] = (struct Eq_3) 0x00;
	}
	goto l05CA;
}

// 05D4: FlagGroup bool fn05D4(Register Eq_135 r0, Register Eq_99 r1, Register Eq_14 r3, Register Eq_2 r4, Register (ptr Eq_3) r5, Register (ptr Eq_4) pc, Stack byte bArg00, Register out Eq_757 r0Out, Register out ptr16 r1Out, Register out ptr16 r3Out, Register out ptr16 r4Out, Register out (ptr Eq_761) r5Out)
bool fn05D4(Eq_135 r0, Eq_99 r1, Eq_14 r3, Eq_2 r4, Eq_3 * r5, Eq_4 * pc, byte bArg00, Eq_757 & r0Out, ptr16 & r1Out, ptr16 & r3Out, ptr16 & r4Out, Eq_761 * & r5Out)
{
	*r3Out = r3;
	*r1Out = r1;
	*r4Out = r4;
	*r5Out = r5;
	*r0Out = r0;
	word16 v9_6 = globals->w0F02 - r3;
	cu16 v12_10 = 0x04 - v9_6;
	bool Z_122 = cond(v12_10);
	if (v12_10 <= 0x00)
	{
		byte * r4_50;
		struct Eq_3 * r5_51;
		fn0AB6(r0, r1, r3, r4, r5, out r4_50, out r5_51);
		Eq_99 r1_54;
		Eq_2 r4_55;
		struct Eq_3 * r5_56;
		fn0A7C(r0, r1, r4_50, r5_51, pc, out r1_54, out r4_55, out r5_56);
		fn0A94();
		word16 r3_61 = __rol(0x00, 0x00);
		ui16 r3_63 = __rol(r3_61, r3_61);
		Eq_135 r0_126 = *((char *) globals->a0F2A + r3_63 * 0x02);
		Eq_1099 v25_66 = pc->t090A >> 0x01;
		pc->t090A = v25_66;
		if (v25_66 >= 0x00)
			r0_126 = (word16) r0_126 + 200;
		pc->w054A = (word16) r0_126 + pc->w054A;
		*(fp - 0x02) = globals->w0F02;
		*(fp - 0x01) = 0x04;
		Eq_2 r4_81;
		struct Eq_3 * r5_82;
		fn0AB6(r0_126, r1_54, r3_63 << 0x01, r4_55, r5_56, out r4_81, out r5_82);
		byte * r4_84;
		struct Eq_3 * r5_85;
		Eq_135 r0_86 = fn0AE8(r0_126, r4_81, r5_82, v9_6, out r4_84, out r5_85);
		*(r1_54 - 0x02) = (byte **) r4_84;
		*r4_84 = 0x28;
		word16 r3_95;
		byte * r4_96;
		Eq_135 r0_97 = fn0B60(r0_86, r1_54 - 0x02, 0x03, r4_84 + 0x01, out r3_95, out r4_96);
		*r4_96 = 0x29;
		Eq_2 r4_103;
		struct Eq_3 * r5_104;
		fn0AE8(r0_97, r4_96 + 0x01, r5_85, v9_6, out r4_103, out r5_104);
		*(r1_54 - 0x04) = (union Eq_2 *) r4_103;
		word16 r1_112;
		word16 r3_113;
		word16 r4_114;
		word16 r5_115;
		word16 r0_116;
		*r0Out = fn0B1A(r1_54 - 0x04, r4_103, r5_104, bLoc02, out r1_112, out r3_113, out r4_114, out r5_115);
		globals->b0F05 = ~0x00;
		Z_122 = true;
	}
	return Z_122;
}

// 064A: FlagGroup bool fn064A(Register Eq_135 r0, Register Eq_99 r1, Register Eq_14 r3, Register Eq_2 r4, Register (ptr Eq_3) r5, Register out ptr16 r0Out, Register out ptr16 r4Out, Register out (ptr Eq_742) r5Out)
bool fn064A(Eq_135 r0, Eq_99 r1, Eq_14 r3, Eq_2 r4, Eq_3 * r5, ptr16 & r0Out, ptr16 & r4Out, Eq_742 * & r5Out)
{
	*r5Out = r5;
	*r0Out = r0;
	*r4Out = r4;
	struct Eq_1218 * r2_10 = globals->w0F06;
l064E:
	bool Z_30;
	if (r2_10[0x0EE6] - r3 == 0x00 && r2_10[0x0EEC] >= 0x00)
	{
		if (r2_10[0x0EE9] - r1 == 0x00)
		{
l0670:
			r2_10[0x0EE6] = (struct Eq_1218) 0x00;
			Z_30 = true;
			return Z_30;
		}
		if (r2_10[0x0EE9] - r0 == 0x00)
		{
			byte * r4_76;
			word16 r5_77;
			word16 r0_78;
			*r0Out = fn0AE8(r0, r4, r5, wLoc02, out r4_76, out r5_77);
			*fp = (byte **) r4_76;
			*r4_76 = 0x20;
			word16 r4_84;
			*r4Out = r4_76 + 0x01;
			goto l0670;
		}
	}
	r2_10 = r2_10 - 0x01;
	Z_30 = cond(r2_10);
	if (r2_10 >= null)
		goto l064E;
	return Z_30;
}

// 067C: FlagGroup bool fn067C(Register Eq_135 r0, Register Eq_14 r3, Register Eq_2 r4, Register (ptr Eq_3) r5, Stack byte bArg00, Register out Eq_718 r0Out, Register out ptr16 r1Out, Register out (ptr Eq_720) r3Out, Register out ptr16 r4Out, Register out (ptr Eq_722) r5Out)
bool fn067C(Eq_135 r0, Eq_14 r3, Eq_2 r4, Eq_3 * r5, byte bArg00, Eq_718 & r0Out, ptr16 & r1Out, Eq_720 * & r3Out, ptr16 & r4Out, Eq_722 * & r5Out)
{
	*r3Out = r3;
	*r0Out = r0;
	*r5Out = r5;
	*r4Out = r4;
	struct Eq_1283 * r1_7 = (word16) r0 + (r3 - 0x01 << 0x01);
	*r1Out = r1_7;
	byte v11_9 = r1_7->b0E2A;
	bool Z_12 = cond(v11_9);
	if (v11_9 != 0x00)
	{
		r1_7->b0E2A = r1_7->b0E2A - 0x01;
		Eq_99 r1_39 = (int16) r1_7->b0E2A;
		*r1Out = r1_39;
		byte * r4_46;
		word16 r5_47;
		word16 r3_48;
		*r3Out = fn0AB6(r0, r1_39, r3, r4, r5, out r4_46, out r5_47);
		byte v23_49 = *((word32) r1_39 + 0x0EE0);
		*r4_46 = v23_49;
		word16 r4_51;
		*r4Out = r4_46 + 0x01;
		Z_12 = cond(v23_49);
	}
	return Z_12;
}

// 06A2: void fn06A2()
void fn06A2()
{
	if (globals->u0F0A != 0x00)
	{
		struct Eq_1338 * r5_25 = globals->ptr0F04;
		do
		{
			if (r5_25[0x0EF0] == 0x00)
			{
				cu16 r0_37 = globals->w0F14;
				if (0x08 - r0_37 >= 0x00)
				{
					r5_25[0x0EF0] = (struct Eq_1338) (r0_37 + 0x02);
					r5_25[0x0EF3] = (struct Eq_1338) 0x18;
					globals->u0F0C = 0x00;
				}
				return;
			}
			r5_25 = r5_25 - 0x01;
		} while (r5_25 >= null);
	}
}

// 06D6: Register Eq_2 fn06D6(Register Eq_99 r1, Register Eq_2 r4, Register (ptr Eq_3) r5, Register (ptr Eq_4) pc)
Eq_2 fn06D6(Eq_99 r1, Eq_2 r4, Eq_3 * r5, Eq_4 * pc)
{
	struct Eq_1375 * sp_1 = fp;
	struct Eq_1377 * r2_25 = globals->w0F06;
l06DA:
	Eq_14 r3_28 = (int16) r2_25[0x0EE6];
	if (r3_28 == 0x00)
	{
l07A0:
		r2_25 = r2_25 - 0x01;
		if (r2_25 >= null)
			goto l06DA;
		return r4;
	}
	cui16 v12_49 = pc->w0812 & globals->w0EF4;
	pc->w0812 = v12_49;
	if (v12_49 == 0x00 && (false || globals->w0EF4 - globals->w0EF4 == 0x00))
		goto l07A0;
	Eq_14 r3_135;
	Eq_135 r0_57 = (int16) r2_25[0x0EE9];
	if (r2_25[0x0EEC] >= 0x00)
	{
		sp_1 = sp_1 - 0x01;
		sp_1->b0000 = (byte) r3_28;
		sp_1[0x01] = (struct Eq_1375) r0_57;
		byte * r4_188;
		r3_135 = fn0AB6(r0_57, r1, r3_28, r4, r5, out r4_188, out r5);
		*r4_188 = 0x20;
		r4 = r4_188 + 0x01;
	}
	else
	{
		sp_1 = sp_1 - 0x01;
		sp_1->b0000 = (byte) ((word16) r3_28 + 0x01);
		sp_1[0x01] = (struct Eq_1375) r0_57;
		r3_135 = fn0AB6(r0_57, r1, (word16) r3_28 + 0x01, r4, r5, out r4, out r5) - 0x01;
		r2_25[0x0EEC] = (struct Eq_1377) (r2_25[0x0EEC] & ~0x80);
	}
	r2_25[0x0EE9] = (struct Eq_1377) ((byte) r2_25[0x0EE9] + 0x01);
	Eq_135 r0_133 = (word32) r0_57 + 0x01;
	if (0x19 - ((word32) r0_57 + 0x01) != 0x00)
	{
		if (0x18 - ((word32) r0_57 + 0x01) != 0x00)
		{
			if (22 - ((word32) r0_57 + 0x01) >= 0x00 && !fn067C((word32) r0_57 + 0x01, r3_135, r4, r5, bLoc02, out r0_133, out r1, out r3_135, out r4, out r5))
				goto l0784;
			goto l078A;
		}
		if (globals->ptr0EFA != 0x00 || globals->w0F14 - r3_135 < 0x00)
			goto l078A;
		r3_135 = r3_135 - 0x04;
		if (globals->w0F14 - r3_135 > 0x00)
		{
l078A:
			Eq_2 r4_103;
			struct Eq_3 * r5_104;
			Eq_135 r0_105 = fn0AE8(r0_133, r4, r5, wLoc02, out r4_103, out r5_104);
			**r3_135 = r4_103;
			byte * r4_111;
			struct Eq_3 * r5_112;
			Eq_135 r0_113 = fn0AE8(r0_105, r4_103, r5_104, wLoc02, out r4_111, out r5_112);
			byte ** r1_114 = r1 - 0x02;
			*r1_114 = (byte **) r4_111;
			*r4_111 = globals->b115A;
			fn0AE8(r0_113, r4_111 + 0x01, r5_112, wLoc02, out r4, out r5);
			*(r1_114 - 0x02) = (union Eq_2 *) r4;
			r1 = r1_114 - 0x02;
			goto l07A0;
		}
		sp_1 = sp_1 - 0x01;
		sp_1->b0000 = globals->w0F14;
		sp_1[0x01] = (struct Eq_1375) 0x18;
		byte * r4_158;
		struct Eq_3 * r5_159;
		fn0AB6((word32) r0_57 + 0x01, r1, r3_135, r4, r5, out r4_158, out r5_159);
		ptr16 r1_161;
		Eq_2 r4_162;
		struct Eq_3 * r5_163;
		Eq_135 r0_164 = fn0A7C((word32) r0_57 + 0x01, r1, r4_158, r5_159, pc, out r1_161, out r4_162, out r5_163);
		globals->ptr0EFA = 0x00;
		globals->w0EFC = 0x05;
		globals->w0F1A = globals->w0F18 - 0x01;
		Eq_2 r4_171;
		struct Eq_3 * r5_172;
		fn0AE8(r0_164, r4_162, r5_163, wLoc02, out r4_171, out r5_172);
		*(r1_161 - 0x02) = (union Eq_2 *) r4_171;
		r1 = fn0B3A(r1_161 - 0x02, r4_171, r5_172, bLoc02, out r4, out r5);
	}
l0784:
	r2_25[0x0EE6] = (struct Eq_1377) 0x00;
	goto l07A0;
}

// 07A6: Register Eq_135 fn07A6(Register Eq_2 r4, Register (ptr Eq_4) pc, Register out ptr16 r1Out, Register out ptr16 r3Out, Register out ptr16 r4Out, Register out ptr16 r5Out)
Eq_135 fn07A6(Eq_2 r4, Eq_4 * pc, ptr16 & r1Out, ptr16 & r3Out, ptr16 & r4Out, ptr16 & r5Out)
{
	*r4Out = r4;
	*r5Out = r5;
	*r1Out = r1;
	*r3Out = r3;
	globals->w0F1E = globals->w0F1C - 0x01;
	struct Eq_1673 * sp_1 = fp;
	if (v5 == 0x00)
	{
		globals->w0F1E = globals->w0F26;
		struct Eq_3 * r5_167;
		*r5Out = 0x00;
		do
		{
			struct Eq_1713 * r2_183 = globals->w0F1A;
			r0 = r2_183->t0DB8;
			if (r0 != 0x00)
			{
				if (globals->w0EFC != 0x00)
				{
					Eq_99 r1_396 = r2_183->t0DAC;
					Eq_14 r3_397 = 0x08;
					do
					{
						if (*r1_396 != 0x00)
						{
							sp_1 = sp_1 - 0x01;
							sp_1->b0000 = (byte) *r1_396;
							sp_1[0x01] = (struct Eq_1673) r0;
							Eq_2 r4_439;
							struct Eq_3 * r5_440;
							r3_397 = fn0AB6(r0, r1_396, r3_397, r4, r5_167, out r4_439, out r5_440);
							r0 = fn0A74(r0, r4_439, r5_440, out r4, out r5_167);
							if (*r1_396 <= 0x00)
								*r1_396 = 0x00;
						}
						r1_396 = (word32) r1_396 + 0x02;
						r3_397 = r3_397 - 0x01;
					} while (r3_397 != 0x00);
					r2_183->t0DB8 = (word32) r2_183->t0DB8 + 0x01;
					r0 = (word32) r0 + 0x01;
				}
				Eq_99 r1_266 = r2_183->t0DAC;
				Eq_14 r3_267 = 0x08;
				do
				{
					if (true)
					{
						*r1_266 = (word32) *r1_266 + globals->w0F20;
						if (0x08 - *r1_266 <= 0x00 || 0x48 - *r1_266 >= 0x00)
							globals->ptr0F00 = sp_1;
						if (0x17 - r0 == 0x00)
							globals->w0F02 = sp_1;
						if (22 - r0 >= 0x00)
							fn093C(r0, r1_266, r3_267);
						sp_1 = sp_1 - 0x01;
						sp_1->b0000 = (byte) *r1_266;
						sp_1[0x01] = (struct Eq_1673) r0;
						Eq_2 r4_340;
						struct Eq_3 * r5_341;
						ptr16 r3_343 = fn096A(fn0AB6(r0, r1_266, r3_267, r4, (char *) &r5_167->ptr0000 + 0x01, out r4_340, out r5_341));
						r0 = fn0AE8(r0, r4_340, r5_341, wLoc02, out r4, out r5_167);
						**(r3_343 - 0x02) = (union Eq_2 **) r4;
						r3_267 = r3_343 - 0x02;
					}
					else if (true && globals->w0EFC == 0x00)
					{
						sp_1 = sp_1 - 0x01;
						sp_1->b0000 = (byte) *r1_266;
						sp_1[0x01] = (struct Eq_1673) r0;
						Eq_2 r4_384;
						struct Eq_3 * r5_385;
						r3_267 = fn0AB6(r0, r1_266, r3_267, r4, r5_167, out r4_384, out r5_385);
						r0 = fn0A74(r0, r4_384, r5_385, out r4, out r5_167);
						*r1_266 = 0x00;
					}
					r1_266 = (word32) r1_266 + 0x02;
					*r1Out = r1_266;
					r3_267 = r3_267 - 0x01;
					*r3Out = r3_267;
				} while (r3_267 != 0x00);
				if (r5_167 == null)
					r2_183->t0DB8.u0 = 0x00;
			}
			ci16 v80_201 = pc->w06AE - 0x02;
			pc->w06AE = v80_201;
			if (v80_201 < 0x00)
			{
				globals->w0F1C = 0x0A;
				globals->w0DAA = ~globals->w0DA8;
				if (globals->w0EFC != 0x00)
					globals->w0EFE = 0x00;
				else if (globals->w0EFE != 0x00)
				{
					globals->w0F22 = -globals->w0F20;
					if (globals->ptr0F00 == 0x00)
						globals->w0EFE = 0x01;
				}
				globals->ptr0F00 = 0x00;
				globals->w0F02 = 0x00;
				goto l08B2;
			}
		} while (r5_167 != null);
		globals->ptr0F28 = r5_167;
	}
l08B2:
	if (globals->w0F12 == 0x00)
		return r0;
	cui16 v38_49 = pc->w063A & globals->w0EF4;
	pc->w063A = v38_49;
	if (v38_49 == 0x00)
		return r0;
	struct Eq_1775 * r2_54 = globals->w0F06;
l08C4:
	if (r2_54[0x0EE6] != 0x00)
	{
		r2_54 = r2_54 - 0x01;
		if (r2_54 >= null)
			goto l08C4;
		return r0;
	}
	do
	{
		Eq_135 r0_101 = fn0A94() & globals->w0F0E;
		if (r0_101 != 0x00)
			return r0_101;
		cui16 r0_89 = fn0A94();
		ci16 r1_140 = globals->u0F08;
		*r1Out = r1_140;
		if (r1_140 >= 0x00 && (true && r0_89 << 0x01 < 0x00))
			break;
		word16 r1_135 = __rol(0x00, 0x00);
		word16 r1_137 = __rol(r1_135, r1_135);
		*r1Out = __rol(r1_137, r1_137) << 0x01;
	} while (false);
	r0_101.u0 = 0x0DB8;
	do
	{
		r0_101 = r0_101 - 0x02;
		byte * r3_104 = (word32) *r0_101.u0 + r1_140;
	} while (false);
	int16 r3_111 = (int16) *r3_104;
	r2_54[0x0EE6] = (struct Eq_1775) (r3_111 + 0x02);
	r2_54[0x0EE9] = (struct Eq_1775) *((byte) r0_101.u0 + 0x0C);
	r2_54[0x0EEC] = (struct Eq_1775) 0x80;
	word16 r3_112;
	*r3Out = r3_111 + 0x02;
	if (3500 - r0_101 != 0x00)
	{
		r0_101 = fn0A94() & globals->u0F0C;
		if (r0_101 != 0x00)
			return r0_101;
	}
	r2_54[0x0EEC] = (struct Eq_1775) ((byte) r2_54[0x0EEC] + 0x01);
	return r0_101;
}

// 093C: void fn093C(Register Eq_135 r0, Register Eq_99 r1, Register Eq_14 r3)
void fn093C(Eq_135 r0, Eq_99 r1, Eq_14 r3)
{
	word16 r3_7 = *r1;
	cui16 r3_17 = r3_7 - 0x01;
	if (globals->w0F20 >= 0x00)
		r3_17 = r3_7 - 0x02;
	struct Eq_2118 * r3_21 = (word32) r0 + (r3_17 << 0x01) - 22 + 0x0E40;
	word16 wLoc04_24 = 0x07;
	do
	{
		r3_21->b0000 = 0x00;
		word16 v21_33 = wLoc04_24 - 0x01;
		r3_21 = r3_21 + 0x01;
		wLoc04_24 = v21_33;
	} while (v21_33 != 0x00);
}

// 096A: Register Eq_14 fn096A(Register Eq_14 r3)
Eq_14 fn096A(Eq_14 r3)
{
	if ((r3 & 0x01) == 0x00)
	{
		if (globals->w0DA8 == 0x00)
		{
l0976:
			globals->b112D = 0x2F;
			globals->b1131 = 0x5C;
			return r3 & 0x01;
		}
	}
	else if (globals->w0DA8 != 0x00)
		goto l0976;
	globals->b112D = 0x5C;
	globals->b1131 = 0x2F;
	return r3 & 0x01;
}

// 0998: Register Eq_135 fn0998(Register Eq_135 r0, Register Eq_99 r1, Register Eq_14 r3, Register Eq_2 r4, Register (ptr Eq_3) r5, Register (ptr Eq_4) pc, Stack byte bArg00, Register out ptr16 r1Out, Register out ptr16 r2Out, Register out ptr16 r3Out, Register out ptr16 r4Out, Register out ptr16 r5Out)
Eq_135 fn0998(Eq_135 r0, Eq_99 r1, Eq_14 r3, Eq_2 r4, Eq_3 * r5, Eq_4 * pc, byte bArg00, ptr16 & r1Out, ptr16 & r2Out, ptr16 & r3Out, ptr16 & r4Out, ptr16 & r5Out)
{
	*r1Out = r1;
	*r3Out = r3;
	*r4Out = r4;
	*r5Out = r5;
	Eq_2183 r2_111 = globals->w0F02;
	*r2Out = r2_111;
	if (true)
	{
		globals->w0F20 = globals->w0F1E - 0x01;
		if (v10 != 0x00)
		{
			if (r2_111 == 0x00 || 0x28 - globals->w0F1E > 0x00)
				return r0;
			goto l0A2A;
		}
		globals->w0F20 = 100;
		globals->w0F12 = 0x01;
		globals->w0A6A = 4404;
		cui16 r0_166 = fn0A94();
		*r2Out = 0x01;
		*r1Out = 0x00;
		r0 = r0_166 << 0x01;
		if (r0_166 << 0x01 < 0x00)
		{
			r0 = r0_166 << 0x02;
			if (r0_166 << 0x02 < 0x00)
			{
				globals->w0F12 = globals->w0F10 + 0x01;
				globals->w0A6A = 0x113D;
				*r1Out = 0x0A;
			}
		}
		if (r0 <= 0x00)
		{
			globals->w0F12 = -globals->w0F10;
			pc->w008A = (word16) ((word32) r1 + pc->w008A);
			*r2Out = 0x4A;
		}
	}
	if (globals->w0EF4 != 0x00 || globals->w0EF6 != 0x00)
	{
l0A18:
		globals->ptr0F04 = r2_111;
		return r0;
	}
	if (globals->w0F10 >= 0x00)
	{
		if (0x49 - r2_111 != 0x00)
		{
l0A04:
			*r2Out = (word16) r2_111.u1 + globals->w0F10;
			Eq_2 r4_144;
			struct Eq_3 * r5_145;
			word16 r3_146;
			*r3Out = fn0AB6(r0, r1, r3, r4, r5, out r4_144, out r5_145);
			fn0A60(r0, r1, r4_144, r5_145);
			goto l0A18;
		}
	}
	else if (0x02 - r2_111 != 0x00)
		goto l0A04;
l0A2A:
	Eq_2 r4_63;
	struct Eq_3 * r5_64;
	Eq_14 r3_65 = fn0AB6(r0, r1, r3, r4, r5, out r4_63, out r5_64);
	Eq_2 r4_66;
	struct Eq_3 * r5_67;
	Eq_135 r0_68 = fn0A74(r0, r4_63, r5_64, out r4_66, out r5_67);
	*(fp - 0x02) = (union Eq_2183 *) r2_111;
	*(fp - 0x01) = 0x04;
	Eq_2 r4_75;
	struct Eq_3 * r5_76;
	word16 r3_77;
	*r3Out = fn0AB6(r0_68, r1, r3_65, r4_66, r5_67, out r4_75, out r5_76);
	word16 r4_78;
	word16 r5_79;
	r0 = fn0A74(r0_68, r4_75, r5_76, out r4_78, out r5_79);
	globals->ptr0F04 = 0x00;
	if (true)
	{
		globals->ptr0EFA = 0x00;
		globals->w0EFC = 0x05;
	}
	return r0;
}

// 0A60: void fn0A60(Register Eq_135 r0, Register Eq_99 r1, Register Eq_2 r4, Register (ptr Eq_3) r5)
void fn0A60(Eq_135 r0, Eq_99 r1, Eq_2 r4, Eq_3 * r5)
{
	Eq_2 r4_6;
	struct Eq_3 * r5_7;
	Eq_135 r0_8 = fn0AE8(r0, r4, r5, wLoc02, out r4_6, out r5_7);
	*(r1 - 0x02) = (union Eq_2 *) r4_6;
	word16 r4_15;
	word16 r5_16;
	fn0AE8(r0_8, r4_6, r5_7, wLoc02, out r4_15, out r5_16);
	__halt();
}

// 0A74: Register Eq_135 fn0A74(Register Eq_135 r0, Register Eq_2 r4, Register (ptr Eq_3) r5, Register out ptr16 r4Out, Register out ptr16 r5Out)
Eq_135 fn0A74(Eq_135 r0, Eq_2 r4, Eq_3 * r5, ptr16 & r4Out, ptr16 & r5Out)
{
	word16 r4_6;
	***************************************************************************************************** r5_7;
	Eq_135 r0_8 = fn0AE8(r0, r4, r5, wLoc02, out r4_6, out r5_7);
	Mem10[r5_7 + 0x00:word16] = r5_7;
	word16 r5_11;
	*r5Out = (char *) r5_7 + 0x02;
	return r0_8;
}

// 0A7C: Register Eq_135 fn0A7C(Register Eq_135 r0, Register Eq_99 r1, Register (ptr byte) r4, Register (ptr Eq_3) r5, Register (ptr Eq_4) pc, Register out ptr16 r1Out, Register out ptr16 r4Out, Register out ptr16 r5Out)
Eq_135 fn0A7C(Eq_135 r0, Eq_99 r1, byte * r4, Eq_3 * r5, Eq_4 * pc, ptr16 & r1Out, ptr16 & r4Out, ptr16 & r5Out)
{
	*r4 = globals->b0F24;
	Eq_2 r4_12;
	struct Eq_3 * r5_13;
	Eq_135 r0_14 = fn0AE8(r0, r4 + 0x01, r5, wLoc02, out r4_12, out r5_13);
	*(r1 - 0x02) = (union Eq_2 *) r4_12;
	Eq_2 r4_21;
	struct Eq_3 * r5_22;
	Eq_135 r0_23 = fn0AE8(r0_14, r4_12, r5_13, wLoc02, out r4_21, out r5_22);
	pc->ptr0000 = r5_22;
	word16 r4_29;
	word16 r5_30;
	Eq_135 r0_31 = fn0AE8(r0_23, r4_21, r5_22, wLoc02, out r4_29, out r5_30);
	*(r1 - 0x04) = r4_29;
	word16 r1_32;
	*r1Out = r1 - 0x04;
	return r0_31;
}

// 0A94: Register word16 fn0A94()
word16 fn0A94()
{
	word16 r0_10 = ((DPB(__swab(globals->w0AB2), 0x00, 0) << 0x01) + globals->w0AB2 << 0x02) + globals->w0AB2;
	globals->w0AB4 = r0_10 + 0x3619;
	return r0_10 + 0x3619;
}

// 0AB6: Register Eq_14 fn0AB6(Register Eq_135 r0, Register Eq_99 r1, Register Eq_14 r3, Register Eq_2 r4, Register (ptr Eq_3) r5, Register out ptr16 r4Out, Register out (ptr Eq_424) r5Out)
Eq_14 fn0AB6(Eq_135 r0, Eq_99 r1, Eq_14 r3, Eq_2 r4, Eq_3 * r5, ptr16 & r4Out, Eq_424 * & r5Out)
{
	byte * r4_6;
	word16 r5_7;
	Eq_135 r0_8 = fn0AE8(r0, r4, r5, wLoc02, out r4_6, out r5_7);
	*fp->t0000 = r4_6;
	fp->t0000 = r0_8;
	*(fp - 0x02) = (union Eq_14 *) r3;
	word16 r3_22;
	byte * r4_23;
	fn0B60((int16) fp->b0005, r1, ~0x01, r4_6, out r3_22, out r4_23);
	*r4_23 = 0x3B;
	word16 r3_32;
	byte * r4_33;
	fn0B60((int16) fp->t0004, r1, ~0x01, r4_23 + 0x01, out r3_32, out r4_33);
	*r4_33 = 0x48;
	Eq_14 v19_38 = *(fp - 0x02);
	fp->t0004 = fp->t0002;
	word16 r4_37;
	*r4Out = r4_33 + 0x01;
	return v19_38;
}

// 0AE8: Register Eq_135 fn0AE8(Register Eq_135 r0, Register Eq_2 r4, Register (ptr Eq_3) r5, Stack word16 wArg00, Register out ptr16 r4Out, Register out (ptr Eq_438) r5Out)
Eq_135 fn0AE8(Eq_135 r0, Eq_2 r4, Eq_3 * r5, word16 wArg00, ptr16 & r4Out, Eq_438 * & r5Out)
{
	byte * r0_14 = r5->ptr0000;
	do
	{
		byte v9_15 = *r0_14;
		r4->u0 = v9_15;
		r0_14 = r0_14 + 0x01;
		r4 = (word32) r4 + 0x01;
	} while (v9_15 != 0x00);
	word16 sp_33;
	Eq_135 r0_34;
	byte NZ_35;
	bool V_36;
	word16 r5_37;
	word16 r4_38;
	bool Z_39;
	byte NZV_40;
	r5[0x01]();
	return r0_34;
}

// 0AF6: void fn0AF6(Register Eq_99 r1, Register Eq_14 r3, Register Eq_2 r4, Register (ptr Eq_3) r5, Stack byte bArg00)
void fn0AF6(Eq_99 r1, Eq_14 r3, Eq_2 r4, Eq_3 * r5, byte bArg00)
{
	byte * r4_16;
	word16 r5_17;
	fn0AB6(globals->w0F14 + 0x02, r1, r3, r4, r5, out r4_16, out r5_17);
	*r4_16 = 0x80;
	PRINT(&globals->b1178);
}

// 0B1A: Register Eq_135 fn0B1A(Register Eq_99 r1, Register Eq_2 r4, Register (ptr Eq_3) r5, Stack byte bArg00, Register out ptr16 r1Out, Register out ptr16 r3Out, Register out ptr16 r4Out, Register out (ptr Eq_1015) r5Out)
Eq_135 fn0B1A(Eq_99 r1, Eq_2 r4, Eq_3 * r5, byte bArg00, ptr16 & r1Out, ptr16 & r3Out, ptr16 & r4Out, Eq_1015 * & r5Out)
{
	Eq_135 r0_3 = globals->w0B5A;
	word16 wLoc02_8 = DPB(wLoc02, 0x2B, 8);
	Eq_2 r4_16;
	struct Eq_3 * r5_17;
	Eq_14 r3_18 = fn0AB6(r0_3, r1, 0x05, r4, r5, out r4_16, out r5_17);
	byte * r4_19;
	struct Eq_3 * r5_20;
	Eq_135 r0_21 = fn0AE8(r0_3, r4_16, r5_17, wLoc02_8, out r4_19, out r5_20);
	*(r1 - 0x02) = (byte **) r4_19;
	word16 r3_27;
	Eq_2 r4_28;
	fn0B60(r0_21, r1 - 0x02, r3_18, r4_19, out r3_27, out r4_28);
	Eq_135 r0_30 = globals->w0F18;
	*(fp - 0x02) = 0x1F;
	*(fp - 0x01) = 0x02;
	byte * r4_38;
	struct Eq_3 * r5_39;
	Eq_14 r3_40 = fn0AB6(r0_30, r1 - 0x02, 0x03, r4_28, r5_20, out r4_38, out r5_39);
	word16 r3_41;
	Eq_2 r4_42;
	Eq_135 r0_43 = fn0B60(r0_30, r1 - 0x02, r3_40, r4_38, out r3_41, out r4_42);
	word16 r4_44;
	word16 r5_45;
	Eq_135 r0_46 = fn0AE8(r0_43, r4_42, r5_39, wLoc02_8, out r4_44, out r5_45);
	*(r1 - 0x04) = r4_44;
	word16 r1_47;
	*r1Out = r1 - 0x04;
	return r0_46;
}

// 0B3A: Register Eq_99 fn0B3A(Register Eq_99 r1, Register Eq_2 r4, Register (ptr Eq_3) r5, Stack byte bArg00, Register out ptr16 r4Out, Register out ptr16 r5Out)
Eq_99 fn0B3A(Eq_99 r1, Eq_2 r4, Eq_3 * r5, byte bArg00, ptr16 & r4Out, ptr16 & r5Out)
{
	Eq_135 r0_3 = globals->w0F18;
	byte * r4_16;
	struct Eq_3 * r5_17;
	Eq_14 r3_18 = fn0AB6(r0_3, r1, 0x03, r4, r5, out r4_16, out r5_17);
	word16 r3_19;
	Eq_2 r4_20;
	Eq_135 r0_21 = fn0B60(r0_3, r1, r3_18, r4_16, out r3_19, out r4_20);
	word16 r4_22;
	word16 r5_23;
	fn0AE8(r0_21, r4_20, r5_17, DPB(wLoc02, 0x1F, 8), out r4_22, out r5_23);
	*(r1 - 0x02) = r4_22;
	return r1 - 0x02;
}

// 0B60: Register Eq_135 fn0B60(Register Eq_135 r0, Register Eq_99 r1, Register Eq_14 r3, Register (ptr byte) r4, Register out ptr16 r3Out, Register out ptr16 r4Out)
Eq_135 fn0B60(Eq_135 r0, Eq_99 r1, Eq_14 r3, byte * r4, ptr16 & r3Out, ptr16 & r4Out)
{
	*r3Out = r3;
	*r4Out = r4;
	word16 wLoc08_101 = 0x00;
	if (r3 >= 0x00)
		globals->w0BC8 = 0x20;
	else
	{
		globals->w0BC8 = 0x30;
		*r3Out = -r3;
	}
	if (r3 == 0x00)
		return r0;
	word16 * r2_56 = 0x0BD4 - (r3 << 0x01);
l0B88:
	word16 r5_65 = 0x30;
	cu16 v22_68 = *r2_56;
	r2_56 = r2_56 + 0x01;
	if (v22_68 == 0x00)
		return r0;
	while (true)
	{
		r0 = r0 - v22_68;
		if (r0 < 0x00)
			break;
		r5_65 = r5_65 + 0x01;
	}
	Eq_2770 r5_107;
	r0 = (word32) r0 + v22_68;
	if (wLoc08_101 == 0x00)
	{
		if (r5_65 != ~0x2F)
			wLoc08_101 = wLoc08_101 + 0x01;
		else if (0x01 - r3 != 0x00 && *r2_56 != 0x00)
		{
			r5_107 = (int16) globals->b0BC6;
l0BB8:
			*r4 = (byte) r5_107;
			*r4Out = r4 + 0x01;
			r3 = r3 - 0x01;
			*r3Out = r3;
			if (r3 != 0x00)
				goto l0B88;
			return r0;
		}
	}
	r5_107 = r5_65 + 0x00;
	goto l0BB8;
}

// 0BD6: Register ptr16 fn0BD6(Register out ptr16 r2Out)
ptr16 fn0BD6(ptr16 & r2Out)
{
	globals->w0F1A = 0x03;
	globals->w0B5C = 0x00;
	globals->w0F0E = 0xF800;
	globals->w0F10 = 0xE000;
	byte * r1_14 = &globals->b0E56;
	word16 r0_18 = 0x06;
	do
	{
		word16 r2_19 = 0x0A;
		do
		{
			*r1_14 = 0x04;
			r1_14 = r1_14 + 0x01;
			r2_19 = r2_19 - 0x01;
			*r2Out = r2_19;
		} while (r2_19 != 0x00);
		r1_14 = r1_14 + 0x0A;
		r0_18 = r0_18 - 0x01;
	} while (r0_18 != 0x00);
	globals->w1166 = 0x1100;
	globals->w1168 = 4464;
	FnSubfn(&globals->w1166);
	globals->w1174 = globals->w1170;
	return r1_14 + 0x0A;
}

// 0C20: void fn0C20(Register Eq_14 r3, Register (ptr Eq_3) r5, Register (ptr Eq_4) pc)
void fn0C20(Eq_14 r3, Eq_3 * r5, Eq_4 * pc)
{
	word16 * r1_12 = globals->a0DB8;
	word16 r0_15 = 0x06;
	Eq_777 r2_13 = 0x05;
	do
	{
		*r1_12 = (word16) r2_13;
		r1_12 = r1_12 + 0x01;
		r2_13.u1 = (word16) r2_13.u1 + 0x02;
		r0_15 = r0_15 - 0x01;
	} while (r0_15 != 0x00);
	struct Eq_2895 * r1_18 = null;
	word16 r0_20 = 0x08;
	ptr16 r2_21 = 11;
	do
	{
		r1_18[1776] = (struct Eq_2895) r2_21;
		r1_18[0x06F8] = (struct Eq_2895) r2_21;
		r1_18[0x0700] = (struct Eq_2895) r2_21;
		r1_18[1800] = (struct Eq_2895) r2_21;
		r1_18[1808] = (struct Eq_2895) r2_21;
		r1_18[1816] = (struct Eq_2895) r2_21;
		r1_18[0x06E2] = (struct Eq_2895) 0x06;
		r1_18 = r1_18 + 0x01;
		r2_21 = r2_21 + 0x08;
		r0_20 = r0_20 - 0x01;
	} while (r0_20 != 0x00);
	Eq_99 r1_43 = 0x0EE6;
	Eq_135 r0_44 = 0x10;
	do
	{
		r1_43->u0 = 0x00;
		r1_43 = (word32) r1_43 + 0x02;
		r0_44 = r0_44 - 0x01;
	} while (r0_44 != 0x00);
	globals->u0F0A = ~0x00;
	globals->w0F14 = 0x30;
	globals->w0F16 = 0x02;
	globals->w0F18 = 0x78;
	globals->w0F1C = 0x0A;
	globals->w0F1E = 0x04;
	globals->ptr0F28 = 0x04;
	globals->w0F20 = 100;
	globals->w0F22 = 0x01;
	pc->w025E = pc->w025E << 0x01;
	ui16 v35_68 = pc->w025C << 0x01;
	pc->w025C = v35_68;
	if (v35_68 == 0x00)
		pc->w0256 = pc->w0256 >> 0x01;
	Eq_2 r4_78;
	struct Eq_3 * r5_79;
	Eq_135 r0_80 = fn0AE8(r0_44, 0x1178, r5, wLoc02, out r4_78, out r5_79);
	*r1_43 = r4_78;
	Eq_2 r4_86;
	struct Eq_3 * r5_87;
	Eq_135 r0_88 = fn0AE8(r0_80, r4_78, r5_79, wLoc02, out r4_86, out r5_87);
	*r1_43 = r4_86;
	*(fp - 0x01) = 0x02;
	*fp = 0x18;
	Eq_2 r4_98;
	struct Eq_3 * r5_99;
	Eq_14 r3_100 = fn0AB6(r0_88, r1_43, r3, r4_86, r5_87, out r4_98, out r5_99);
	Eq_2 r4_101;
	struct Eq_3 * r5_102;
	Eq_135 r0_103 = fn0AE8(r0_88, r4_98, r5_99, wLoc02, out r4_101, out r5_102);
	*(r2_21 - 0x02) = (union Eq_2 *) r4_101;
	*(fp - 0x02) = 0x02;
	*(fp - 0x01) = 0x02;
	Eq_2 r4_112;
	struct Eq_3 * r5_113;
	fn0AB6(r0_103, r1_43, r3_100, r4_101, r5_102, out r4_112, out r5_113);
	word16 r4_115;
	word16 r5_116;
	fn0AE8(r0_103, r4_112, r5_113, wLoc02, out r4_115, out r5_116);
}

