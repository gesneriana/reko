// retpoline_init.c
// Generated by decompiling retpoline.elf
// using Reko decompiler version 0.9.1.0.

#include "retpoline_init.h"

// 0000000000400428: void _init()
void _init()
{
	if (__gmon_start__ != 0x00)
		__gmon_start__();
}

