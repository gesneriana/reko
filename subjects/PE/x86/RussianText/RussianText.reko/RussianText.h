// RussianText.h
// Generated by decompiling RussianText.exe
// using Reko decompiler version 0.8.2.0.

/*
// Equivalence classes ////////////
Eq_1: (struct "Globals" (40208B uint32 dw40208B) (4020A4 char b4020A4) (4020F8 word32 dw4020F8))
	globals_t (in globals : (ptr32 (struct "Globals")))
Eq_2: (struct "Eq_2" (0 word32 dw0000) (4 ptr32 ptr0004))
	T_2 (in dwArg04 : (ptr32 Eq_2))
	T_5 (in dwArg04 : (ptr32 Eq_2))
	T_63 (in fp - 0x0000000C : word32)
Eq_3: (fn void ((ptr32 Eq_2)))
	T_3 (in fn004011FC : ptr32)
	T_4 (in signature of fn004011FC : void)
	T_60 (in fn004011FC : ptr32)
Eq_17: HANDLE
	T_17 (in eax_22 : Eq_17)
	T_20 (in GetProcessHeap() : HANDLE)
Eq_18: (fn Eq_17 ())
	T_18 (in GetProcessHeap : ptr32)
	T_19 (in signature of GetProcessHeap : void)
Eq_24: (segment "Eq_24" (2C (ptr32 (arr word32)) ptr002C))
	T_24 (in fs : selector)
Eq_35: (fn int32 ((ptr32 char)))
	T_35 (in printf : ptr32)
	T_36 (in signature of printf : void)
Eq_45: (fn (ptr32 void) ((ptr32 void), (ptr32 void), Eq_49))
	T_45 (in memcpy : ptr32)
	T_46 (in signature of memcpy : void)
Eq_49: size_t
	T_49 (in _Size : size_t)
	T_53 (in 0x0000009C : word32)
Eq_50: (fn (ptr32 void) ())
	T_50 (in fn00401158 : ptr32)
	T_51 (in signature of fn00401158 : void)
	T_66 (in fn00401158 : ptr32)
Eq_55: (fn void ())
	T_55 (in _InitTermAndUnexPtrs : ptr32)
	T_56 (in signature of _InitTermAndUnexPtrs : void)
// Type Variables ////////////
globals_t: (in globals : (ptr32 (struct "Globals")))
  Class: Eq_1
  DataType: (ptr32 Eq_1)
  OrigDataType: (ptr32 (struct "Globals"))
T_2: (in dwArg04 : (ptr32 Eq_2))
  Class: Eq_2
  DataType: (ptr32 Eq_2)
  OrigDataType: word32
T_3: (in fn004011FC : ptr32)
  Class: Eq_3
  DataType: (ptr32 Eq_3)
  OrigDataType: (ptr32 (fn T_6 (T_2)))
T_4: (in signature of fn004011FC : void)
  Class: Eq_3
  DataType: (ptr32 Eq_3)
  OrigDataType: 
T_5: (in dwArg04 : (ptr32 Eq_2))
  Class: Eq_2
  DataType: (ptr32 Eq_2)
  OrigDataType: (ptr32 (struct (0 T_75 t0000) (4 T_79 t0004)))
T_6: (in fn004011FC(dwArg04) : void)
  Class: Eq_6
  DataType: void
  OrigDataType: void
T_7: (in 0040208B : ptr32)
  Class: Eq_7
  DataType: (ptr32 uint32)
  OrigDataType: (ptr32 (struct (0 T_8 t0000)))
T_8: (in Mem0[0x0040208B:word32] : word32)
  Class: Eq_8
  DataType: uint32
  OrigDataType: up32
T_9: (in 0x00000000 : word32)
  Class: Eq_8
  DataType: uint32
  OrigDataType: up32
T_10: (in globals->dw40208B < 0x00000000 : bool)
  Class: Eq_10
  DataType: bool
  OrigDataType: bool
T_11: (in eax_11 : word32)
  Class: Eq_11
  DataType: word32
  OrigDataType: word32
T_12: (in Top_12 : int8)
  Class: Eq_12
  DataType: int8
  OrigDataType: int8
T_13: (in __CRTL_TLS_GetValue : ptr32)
  Class: Eq_13
  DataType: (ptr32 code)
  OrigDataType: (ptr32 code)
T_14: (in signature of __CRTL_TLS_GetValue : void)
  Class: Eq_14
  DataType: Eq_14
  OrigDataType: 
T_15: (in 0x00000000 : word32)
  Class: Eq_11
  DataType: word32
  OrigDataType: word32
T_16: (in eax_11 == 0x00000000 : bool)
  Class: Eq_16
  DataType: bool
  OrigDataType: bool
T_17: (in eax_22 : Eq_17)
  Class: Eq_17
  DataType: Eq_17
  OrigDataType: HANDLE
T_18: (in GetProcessHeap : ptr32)
  Class: Eq_18
  DataType: (ptr32 Eq_18)
  OrigDataType: (ptr32 (fn T_20 ()))
T_19: (in signature of GetProcessHeap : void)
  Class: Eq_18
  DataType: (ptr32 Eq_18)
  OrigDataType: 
T_20: (in GetProcessHeap() : HANDLE)
  Class: Eq_17
  DataType: Eq_17
  OrigDataType: HANDLE
T_21: (in __CRTL_TLS_ExitThread : ptr32)
  Class: Eq_21
  DataType: (ptr32 code)
  OrigDataType: (ptr32 code)
T_22: (in signature of __CRTL_TLS_ExitThread : void)
  Class: Eq_22
  DataType: Eq_22
  OrigDataType: 
T_23: (in eax : word32)
  Class: Eq_23
  DataType: word32
  OrigDataType: word32
T_24: (in fs : selector)
  Class: Eq_24
  DataType: (ptr16 Eq_24)
  OrigDataType: (ptr16 (segment (2C T_26 t002C)))
T_25: (in 0x002C : word16)
  Class: Eq_25
  DataType: (memptr (ptr16 Eq_24) (ptr32 (arr word32)))
  OrigDataType: (memptr T_24 (struct (0 T_26 t0000)))
T_26: (in Mem0[fs:0x002C:word32] : word32)
  Class: Eq_26
  DataType: (ptr32 (arr word32))
  OrigDataType: (ptr32 (struct (0 (arr T_80) a0000)))
T_27: (in 0040208B : ptr32)
  Class: Eq_27
  DataType: (ptr32 uint32)
  OrigDataType: (ptr32 (struct (0 T_28 t0000)))
T_28: (in Mem0[0x0040208B:word32] : word32)
  Class: Eq_8
  DataType: uint32
  OrigDataType: ui32
T_29: (in 0x00000004 : word32)
  Class: Eq_29
  DataType: ui32
  OrigDataType: ui32
T_30: (in globals->dw40208B * 0x00000004 : word32)
  Class: Eq_30
  DataType: ui32
  OrigDataType: ui32
T_31: (in Mem0[fs:0x002C:word32][Mem0[0x0040208B:word32] * 0x00000004] : word32)
  Class: Eq_23
  DataType: word32
  OrigDataType: word32
T_32: (in eax : int32)
  Class: Eq_32
  DataType: int32
  OrigDataType: int32
T_33: (in argc : int32)
  Class: Eq_33
  DataType: int32
  OrigDataType: int32
T_34: (in argv : (ptr32 (ptr32 char)))
  Class: Eq_34
  DataType: (ptr32 (ptr32 char))
  OrigDataType: (ptr32 (ptr32 char))
T_35: (in printf : ptr32)
  Class: Eq_35
  DataType: (ptr32 Eq_35)
  OrigDataType: (ptr32 (fn T_39 (T_38)))
T_36: (in signature of printf : void)
  Class: Eq_35
  DataType: (ptr32 Eq_35)
  OrigDataType: 
T_37: (in ptrArg04 : (ptr32 char))
  Class: Eq_37
  DataType: (ptr32 char)
  OrigDataType: 
T_38: (in 0x004020A4 : word32)
  Class: Eq_37
  DataType: (ptr32 char)
  OrigDataType: (ptr32 char)
T_39: (in printf(&globals->b4020A4) : int32)
  Class: Eq_39
  DataType: int32
  OrigDataType: int32
T_40: (in 0x00000000 : word32)
  Class: Eq_32
  DataType: int32
  OrigDataType: word32
T_41: (in dwArg04 : (ptr32 void))
  Class: Eq_41
  DataType: (ptr32 void)
  OrigDataType: word32
T_42: (in ebx_12 : (ptr32 void))
  Class: Eq_41
  DataType: (ptr32 void)
  OrigDataType: (ptr32 void)
T_43: (in 0x00000000 : word32)
  Class: Eq_41
  DataType: (ptr32 void)
  OrigDataType: word32
T_44: (in dwArg04 != null : bool)
  Class: Eq_44
  DataType: bool
  OrigDataType: bool
T_45: (in memcpy : ptr32)
  Class: Eq_45
  DataType: (ptr32 Eq_45)
  OrigDataType: (ptr32 (fn T_54 (T_52, T_42, T_53)))
T_46: (in signature of memcpy : void)
  Class: Eq_45
  DataType: (ptr32 Eq_45)
  OrigDataType: 
T_47: (in _Dst : (ptr32 void))
  Class: Eq_47
  DataType: (ptr32 void)
  OrigDataType: 
T_48: (in _Src : (ptr32 void))
  Class: Eq_41
  DataType: (ptr32 void)
  OrigDataType: 
T_49: (in _Size : size_t)
  Class: Eq_49
  DataType: Eq_49
  OrigDataType: 
T_50: (in fn00401158 : ptr32)
  Class: Eq_50
  DataType: (ptr32 Eq_50)
  OrigDataType: (ptr32 (fn T_52 ()))
T_51: (in signature of fn00401158 : void)
  Class: Eq_50
  DataType: (ptr32 Eq_50)
  OrigDataType: 
T_52: (in fn00401158() : word32)
  Class: Eq_47
  DataType: (ptr32 void)
  OrigDataType: (ptr32 void)
T_53: (in 0x0000009C : word32)
  Class: Eq_49
  DataType: Eq_49
  OrigDataType: size_t
T_54: (in memcpy(fn00401158(), ebx_12, 0x0000009C) : (ptr32 void))
  Class: Eq_54
  DataType: (ptr32 void)
  OrigDataType: (ptr32 void)
T_55: (in _InitTermAndUnexPtrs : ptr32)
  Class: Eq_55
  DataType: (ptr32 Eq_55)
  OrigDataType: (ptr32 (fn T_57 ()))
T_56: (in signature of _InitTermAndUnexPtrs : void)
  Class: Eq_55
  DataType: (ptr32 Eq_55)
  OrigDataType: 
T_57: (in _InitTermAndUnexPtrs() : void)
  Class: Eq_57
  DataType: void
  OrigDataType: void
T_58: (in 0x00000000 : word32)
  Class: Eq_41
  DataType: (ptr32 void)
  OrigDataType: word32
T_59: (in dwArg04 != null : bool)
  Class: Eq_59
  DataType: bool
  OrigDataType: bool
T_60: (in fn004011FC : ptr32)
  Class: Eq_3
  DataType: (ptr32 Eq_3)
  OrigDataType: (ptr32 (fn T_64 (T_63)))
T_61: (in fp : ptr32)
  Class: Eq_61
  DataType: ptr32
  OrigDataType: ptr32
T_62: (in 0x0000000C : word32)
  Class: Eq_62
  DataType: ui32
  OrigDataType: ui32
T_63: (in fp - 0x0000000C : word32)
  Class: Eq_2
  DataType: (ptr32 Eq_2)
  OrigDataType: ptr32
T_64: (in fn004011FC(fp - 0x0000000C) : void)
  Class: Eq_6
  DataType: void
  OrigDataType: void
T_65: (in dwLoc08 : word32)
  Class: Eq_41
  DataType: (ptr32 void)
  OrigDataType: word32
T_66: (in fn00401158 : ptr32)
  Class: Eq_50
  DataType: (ptr32 Eq_50)
  OrigDataType: (ptr32 (fn T_67 ()))
T_67: (in fn00401158() : word32)
  Class: Eq_47
  DataType: (ptr32 void)
  OrigDataType: word32
T_68: (in 0x0000001C : word32)
  Class: Eq_68
  DataType: word32
  OrigDataType: word32
T_69: (in fn00401158() + 0x0000001C : word32)
  Class: Eq_69
  DataType: word32
  OrigDataType: word32
T_70: (in 004020F8 : ptr32)
  Class: Eq_70
  DataType: (ptr32 word32)
  OrigDataType: (ptr32 (struct (0 T_71 t0000)))
T_71: (in Mem17[0x004020F8:word32] : word32)
  Class: Eq_69
  DataType: word32
  OrigDataType: word32
T_72: (in 0x82727349 : word32)
  Class: Eq_72
  DataType: word32
  OrigDataType: word32
T_73: (in 0x00000000 : word32)
  Class: Eq_73
  DataType: word32
  OrigDataType: word32
T_74: (in dwArg04 + 0x00000000 : word32)
  Class: Eq_74
  DataType: word32
  OrigDataType: word32
T_75: (in Mem18[dwArg04 + 0x00000000:word32] : word32)
  Class: Eq_72
  DataType: word32
  OrigDataType: word32
T_76: (in 0x004020E4 : ptr32)
  Class: Eq_76
  DataType: ptr32
  OrigDataType: ptr32
T_77: (in 0x00000004 : word32)
  Class: Eq_77
  DataType: word32
  OrigDataType: word32
T_78: (in dwArg04 + 0x00000004 : word32)
  Class: Eq_78
  DataType: ptr32
  OrigDataType: ptr32
T_79: (in Mem19[dwArg04 + 0x00000004:word32] : word32)
  Class: Eq_76
  DataType: ptr32
  OrigDataType: word32
T_80:
  Class: Eq_80
  DataType: word32
  OrigDataType: (struct 0004 (0 T_31 t0000))
*/
typedef struct Globals {
	uint32 dw40208B;	// 40208B
	char b4020A4;	// 4020A4
	word32 dw4020F8;	// 4020F8
} Eq_1;

typedef struct Eq_2 {
	word32 dw0000;	// 0
	ptr32 ptr0004;	// 4
} Eq_2;

typedef void (Eq_3)(Eq_2 *);

typedef HANDLE Eq_17;

typedef HANDLE (Eq_18)();

typedef struct Eq_24 {
	word32 (* ptr002C)[];	// 2C
} Eq_24;

typedef int32 (Eq_35)(char *);

typedef void (Eq_45)(void, void, size_t);

typedef size_t Eq_49;

typedef void (Eq_50)();

typedef void (Eq_55)();
