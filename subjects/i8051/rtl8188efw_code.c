// rtl8188efw_code.c
// Generated by decompiling rtl8188efw.bin
// using Reko decompiler version 0.9.1.0.

#include "rtl8188efw_code.h"

// 0000: void fn0000(Register byte R1, Register (ptr16 Eq_n) __data)
void fn0000(byte R1, struct Eq_n * __data)
{
	__data->*0x1D = 0x00;
	byte A_n = __data->b80F0;
	byte R1_n;
	struct Eq_n * __data_n;
	fn4EF3();
	__data_n->b0157 = 0x05;
	if ((__data_n->b80EA >> 0x02 & 0x01) == 0x00)
		fn4AC0();
}

