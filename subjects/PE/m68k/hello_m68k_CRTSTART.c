// hello_m68k_CRTSTART.c
// Generated by decompiling hello_m68k.exe
// using Reko decompiler version 0.9.1.0.

#include "hello_m68k_CRTSTART.h"

// 000021F0: void fn000021F0(Register (ptr32 Eq_n) a5)
void fn000021F0(struct Eq_n * a5)
{
	struct Eq_n * d0_n = a5->ptrFFFFFAA0->ptr001C;
	struct Eq_n * a1_n = d0_n;
	if (d0_n != null)
	{
		int32 d1_n;
		for (d1_n = 0x00; d1_n < 0x03; ++d1_n)
		{
			word32 d0_n = *a1_n->ptr0004;
			if (d0_n != 0x45434F4E)
			{
				if (d0_n == 0x46535953)
				{
					a5->aFFFFF958[d1_n] |= 0x01;
					struct Eq_n * a0_n = *a1_n->ptr0008;
					a5->aFFFFF998[d1_n] = SEQ(SLICE(a0_n, word16, 16), a0_n->w0002);
				}
			}
			else
			{
				a5->aFFFFF958[d1_n] |= 0x41;
				a5->aFFFFF998[d1_n] = a1_n;
			}
			++a1_n;
		}
	}
}

// 00002264: void fn00002264(Stack (ptr32 byte) dwArg04)
void fn00002264(byte * dwArg04)
{
	if (dwArg04 != null)
	{
		byte v11_n = *dwArg04;
		if (v11_n != 0x00)
		{
			byte * a2_n = dwArg04;
			uint32 d0_n;
			byte * a1_n = dwArg04 + 0x01;
			for (d0_n = (uint32) (uint8) v11_n; d0_n != 0x00; --d0_n)
			{
				*a2_n = *a1_n;
				++a1_n;
				++a2_n;
			}
			*a2_n = 0x00;
		}
	}
}

// 00002294: void fn00002294(Register (ptr32 Eq_n) a5)
void fn00002294(struct Eq_n * a5)
{
	fn00002354(a5, 0x00, 0x00);
}

// 000022C4: void fn000022C4(Register word32 a2, Register ptr32 a5)
void fn000022C4(word32 a2, ptr32 a5)
{
	fn000023B4(a5 + -744, a5 + -0x02E4);
	struct Eq_n * a7_n = (struct Eq_n *) <invalid>;
	a7_n->t0004 = a5 + -0x02EC;
	a7_n->t0000 = a5 + -0x02F0;
	struct Eq_n * a6_n = fn000023B4(a7_n->t0000, a7_n->t0004);
	struct Eq_n * a7_n = (struct Eq_n *) <invalid>;
	a7_n->w0002 = ~0x5760;
	a7_n->b0001 = 0x01;
	word32 * a7_n;
	word32 a6_n;
	ptr32 a5_n;
	(a5 + 0x00C2)();
	word32 v10_n = *a7_n;
	*(a7_n - 0x02) = 0xA1AD;
	0x00 = 0x00;
	word32 * a7_n;
	struct Eq_n * a6_n;
	word32 a2_n;
	struct Eq_n * a5_n;
	word32 a0_n;
	(a5_n + 0x00C2)();
	if (a2_n - *a7_n != 0x00)
	{
		__syscall(0xA1AD);
		a6_n->dwFFFFFFFC = a0_n;
		if (false)
			a5_n->dwFFFFF948 = a6_n->dwFFFFFFFC;
	}
}

// 00002354: Register word32 fn00002354(Register (ptr32 Eq_n) a5, Stack int32 dwArg08, Stack byte bArg0F)
word32 fn00002354(struct Eq_n * a5, int32 dwArg08, byte bArg0F)
{
	a5->bFFFFFA9C = bArg0F;
	ptr32 a7_n = fp - 0x04;
	if (dwArg08 == 0x00)
	{
		if (a5->tFFFFFD3C != 0x00)
		{
			fn000023B4(a5->tFFFFFD3C, a5->tFFFFFD38);
			struct Eq_n * a7_n = (struct Eq_n *) <invalid>;
			a7_n = &a7_n->t0008;
		}
		union Eq_n * a7_n = a7_n - 0x04;
		*a7_n = (union Eq_n *) ((char *) &a5->ptrFFFFFAA0 + 0x0288);
		*(a7_n - 0x04) = (char *) &a5->ptrFFFFFAA0 + 0x0280;
		fn000023B4(*(a7_n - 0x04), *a7_n);
		struct Eq_n * a7_n = (struct Eq_n *) <invalid>;
		a7_n = &a7_n->t0008;
	}
	union Eq_n * a7_n = a7_n - 0x04;
	*a7_n = (union Eq_n *) ((char *) &a5->ptrFFFFFAA0 + 656);
	*(a7_n - 0x04) = (char *) &a5->ptrFFFFFAA0 + 0x028C;
	struct Eq_n * a6_n = fn000023B4(*(a7_n - 0x04), *a7_n);
	if (a6_n->dw0010 == 0x00)
	{
		if (a5->ptrFFFFFAA0 != null)
			a5->ptrFFFFFAA0->dw000E = a6_n->dw0008;
		(*((char *) &a5->tFFFFFD3C + 0x0326))();
	}
	return a6_n->dw0000;
}

// 000023B4: Register word32 fn000023B4(Stack Eq_n dwArg04, Stack Eq_n dwArg08)
word32 fn000023B4(Eq_n dwArg04, Eq_n dwArg08)
{
	word32 * a6_n = fp - 0x04;
	int32 d5_n = -0x01;
	Eq_n d4_n = dwArg08;
	Eq_n d3_n = dwArg04;
	if (dwArg08 - dwArg04 > 0x00)
	{
		do
		{
			<anonymous> * d0_n = *d3_n;
			if (d0_n != null && d0_n - d5_n != 0x00)
			{
				word32 a0_n;
				word32 d0_n;
				d0_n();
			}
			d3_n = (word32) d3_n + 0x04;
		} while (d4_n - d3_n > 0x00);
	}
	return *a6_n;
}

// 000023F8: void fn000023F8(Register Eq_n a5)
void fn000023F8(Eq_n a5)
{
	struct Eq_n * a6_n;
	Eq_n a5_n = fn00002418(a5, out a6_n);
	struct Eq_n * a7_n = (struct Eq_n *) <invalid>;
	*(a7_n - 0x04) = a6_n->dw0008;
	word32 a6_n;
	Eq_n a5_n = fn0000243C(a5_n, *(a7_n - 0x04), out a6_n);
	struct Eq_n * a7_n = (struct Eq_n *) <invalid>;
	&a7_n->t0000.u0->dw0000 = 0xFF;
	(*((word32) a5_n - 1288))();
}

// 00002418: Register Eq_n fn00002418(Register Eq_n a5, Register out ptr32 a6Out)
Eq_n fn00002418(Eq_n a5, ptr32 & a6Out)
{
	struct Eq_n * a7_n = (struct Eq_n *) <invalid>;
	word32 a6_n;
	Eq_n a5_n = fn0000243C(a5, 252, out a6_n);
	word32 a7_n = &a7_n->t0004;
	<anonymous> * a0_n = *((word32) a5_n - 1012);
	if (a0_n != null)
		a0_n();
	ptr32 * a7_n = a7_n - 0x04;
	*a7_n = 0xFF;
	ptr32 * a6_n;
	Eq_n a5_n = fn0000243C(a5_n, *a7_n, out a6_n);
	a6Out = *a6_n;
	return a5_n;
}

// 0000243C: Register Eq_n fn0000243C(Register Eq_n a5, Stack ptr32 dwArg04, Register out ptr32 a6Out)
Eq_n fn0000243C(Eq_n a5, ptr32 dwArg04, ptr32 & a6Out)
{
	ptr32 * a6_n = fp - 0x04;
	int32 d1_n = 0x00;
	struct Eq_n * d2_n = (word32) a5 - 0x044C;
	while (dwArg04 - d2_n->dw0000 != 0x00)
	{
		++d2_n;
		++d1_n;
		if (d2_n - (a5 + -1012) >=u 0x00)
			break;
	}
	if (dwArg04 - *((word32) a5 + (d1_n * 0x08 - 0x044C)) == 0x00)
	{
		byte * a0_n = *((word32) a5 + (d1_n * 0x08 - 0x0448));
		byte * a1_n = a0_n;
		do
		{
			a1_n = a1_n + 0x01;
			a1_n = a1_n;
		} while (*a1_n != 0x00);
		word32 a1_n = a1_n - (a0_n + 0x01);
		(a5 + 0x0092)();
	}
	a6Out = *a6_n;
	return a5;
}

