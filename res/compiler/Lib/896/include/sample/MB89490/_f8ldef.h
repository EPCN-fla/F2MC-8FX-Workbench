/*
 F2MC-8L family I/O register macro declaration file V30L08
 ALL RIGHTS RESERVED, COPYRIGHT (C) FUJITSU LIMITED 1998
 LICENSED MATERIAL - PROGRAM PROPERTY OF FUJITSU LIMITED
*/

/* for FASM */
#ifdef __FASM__

#define	__IO_EXTERN
#define	__IO_STATIC
#define __IO_DATA_EXTERN

#define __CONST
#define __VOLATILE
#define __EXTERN

#define __STRUCT_D(uname,name)	__GLOBAL_SYMBOL   name,uname,_,dummy
#define __UNION_D(uname,name)	__GLOBAL_SYMBOL   name,uname,_,dummy
#define __UCHAR_D(name)		__GLOBAL_RES_B  name,< >,1,_,< >,dummy
#define __USHORT_D(name)	__GLOBAL_RES_B  name,< >,2,_,< >,dummy
#define __ULONG_D(name)		__GLOBAL_RES_B  name,< >,4,_,< >,dummy
#define __RESERVE_D(name,size)	__AREA_RES_B    size

#define	__STRUCT_AD(uname,name,size) \
				__GLOBAL_SYMBOL_A  name,uname,size,_,_,dummy
#define __UNION_AD(uname,name,size) \
				__GLOBAL_SYMBOL_A  name,uname,size,_,_,dummy
#define __UCHAR_AD(name,size)	__GLOBAL_RES_B_A   name,< >,1,size,_,< >,dummy
#define __USHORT_AD(name,size)	__GLOBAL_RES_B_A   name,< >,2,size,_,< >,dummy
#define __ULONG_AD(name,size)	__GLOBAL_RES_B_A   name,< >,4,size,_,< >,dummy

#define __STRUCT		#macro
#define __UNION			#macro

#define __STRUCT_B		symbol
#define __STRUCT_E		#endm

#define __TYPE_UNION		__ORG_SYMBOL    symbol,_

#define __STRUCT_TYPE_B
#define __STRUCT_TYPE_UNION	__ORG_SYMBOL    symbol,_
#define __STRUCT_TYPE_E(name)

#define __UNION_TYPE_B
#define __UNION_TYPE_UNION	__ORG_SYMBOL    symbol,_
#define __UNION_TYPE_E(name)

#define __BYTE_MEM
#define __WORD_MEM
#define __LWORD_MEM

#define __BYTE_MEM_A(size)
#define __WORD_MEM_A(size)
#define __LWORD_MEM_A(size)

#define	__STRUCT_MEM(uname,name)	__GLOBAL_SYMBOL  \
					symbol<_>name,uname,_,dummy
#define __UNION_MEM(uname,name)		__GLOBAL_SYMBOL  \
					symbol<_>name,uname,_,dummy

#define	__STRUCT_MEM_A(uname,name,size) __GLOBAL_SYMBOL_MEM_A  \
					symbol<_>name,uname,size,_,_,dummy
#define __UNION_MEM_A(uname,name,size)  __GLOBAL_SYMBOL_MEM_A  \
					symbol<_>name,uname,size,_,_,dummy

#define __UCHAR(name)		__GLOBAL_RES_B  symbol,name,1,_,_,dummy
#define __USHORT(name)		__GLOBAL_RES_B  symbol,name,2,_,_,dummy
#define __ULONG(name)		__GLOBAL_RES_B  symbol,name,4,_,_,dummy

#define __UCHAR_A(name,size)	__GLOBAL_RES_B_A symbol,name,1,size,_,_,dummy
#define __USHORT_A(name,size)	__GLOBAL_RES_B_A symbol,name,2,size,_,_,dummy
#define __ULONG_A(name,size)	__GLOBAL_RES_B_A symbol,name,4,size,_,_,dummy

#define __UCHARBIT(name,size)	__GLOBAL_RES_I  symbol,name,size,_,_,dummy
#define __USHORTBIT(name,size)	__GLOBAL_RES_I  symbol,name,size,_,_,dummy
#define __ULONGBIT(name,size)	__GLOBAL_RES_I  symbol,name,size,_,_,dummy

#define __UCHARBIT_UNION(name,size)  __GLOBAL_RES_I_UNION \
						symbol,name,size,_,_,dummy
#define __USHORTBIT_UNION(name,size) __GLOBAL_RES_I_UNION \
						symbol,name,size,_,_,dummy
#define __ULONGBIT_UNION(name,size)  __GLOBAL_RES_I_UNION \
						symbol,name,size,_,_,dummy

#define __UCHARBIT_NONAME(size)   __AREA_RES_I    size
#define __USHORTBIT_NONAME(size)  __AREA_RES_I    size
#define __ULONGBIT_NONAME(size)   __AREA_RES_I    size

#define __UCHARBIT_COM01(name,size)   __GLOBAL_RES_I \
					symbol,name,size,_,_COM01_,dummy
#define __UCHARBIT_COM012(name,size)  __GLOBAL_RES_I \
					symbol,name,size,_,_COM012_,dummy
#define __UCHARBIT_COM0123(name,size) __GLOBAL_RES_I \
					symbol,name,size,_,_COM0123_,dummy

#include "_f8ldef.inc"

/* for FCC */
#else

 #ifdef __IO_DEFINE
  #define __IO_EXTERN		__io
  #define __IO_STATIC		__io static
  #define __IO_DATA_EXTERN      volatile
  #define __RESERVE_D(name,size)	unsigned char  name[size];
 #else
  #define __SECTION(addr)
  #define __IO_EXTERN		extern __io
  #define __IO_STATIC
  #define __IO_DATA_EXTERN 	extern volatile
  #define __RESERVE_D(name,size)
 #endif

#define __STRUCT_D(uname,name)	/* volatile */ struct uname   name;
#define __UNION_D(uname,name)	/* volatile */ union  uname   name;
#define __UCHAR_D(name)		/* volatile */ unsigned char  name;
#define __USHORT_D(name)	/* volatile */ unsigned short name;
#define __ULONG_D(name)		/* volatile */ unsigned long  name;

#define	__STRUCT_AD(uname,name,size) \
				/* volatile */ struct uname   name[size];
#define __UNION_AD(uname,name,size) \
				/* volatile */ union  uname   name[size];
#define __UCHAR_AD(name,size)	/* volatile */ unsigned char  name[size];
#define __USHORT_AD(name,size)	/* volatile */ unsigned short name[size];
#define __ULONG_AD(name,size)	/* volatile */ unsigned long  name[size];

#define __STRUCT		struct
#define __UNION			union
#define __CONST			const
#define __VOLATILE		volatile
#define __EXTERN		extern volatile

#define __STRUCT_B		{
#define __STRUCT_E		};

#define __TYPE_UNION

#define __STRUCT_TYPE_B		struct {
#define __STRUCT_TYPE_UNION	struct {
#define __STRUCT_TYPE_E(name)	} name;

#define __UNION_TYPE_B		union {
#define __UNION_TYPE_UNION	union {
#define __UNION_TYPE_E(name)	} name;

#define __BYTE_MEM		unsigned char  byte;
#define __WORD_MEM		unsigned short word;
#define __LWORD_MEM		unsigned long  lword;

#define __BYTE_MEM_A(size)	unsigned char  byte[size];
#define __WORD_MEM_A(size)	unsigned short word[size];
#define __LWORD_MEM_A(size)	unsigned long  lword[size];

#define	__STRUCT_MEM(uname,name)  struct uname   name;
#define __UNION_MEM(uname,name)   union  uname   name;

#define	__STRUCT_MEM_A(uname,name,size) struct uname   name[size];
#define __UNION_MEM_A(uname,name,size)  union  uname   name[size];

#define __UCHAR(name)		unsigned char  name;
#define __USHORT(name)		unsigned short name;
#define __ULONG(name)		unsigned long  name;

#define __UCHAR_A(name,size)	unsigned char  name[size];
#define __USHORT_A(name,size)	unsigned short name[size];
#define __ULONG_A(name,size)	unsigned long  name[size];

#define __UCHARBIT(name,size)	unsigned char  name :size;
#define __USHORTBIT(name,size)	unsigned short name :size;
#define __ULONGBIT(name,size)	unsigned long  name :size;

#define __UCHARBIT_UNION(name,size)  __UCHARBIT(name,size)
#define __USHORTBIT_UNION(name,size) __USHORTBIT(name,size)
#define __ULONGBIT_UNION(name,size)  __ULONGBIT(name,size)

#define __UCHARBIT_NONAME(size)   unsigned char       :size;
#define __USHORTBIT_NONAME(size)  unsigned short      :size;
#define __ULONGBIT_NONAME(size)   unsigned long       :size;

#define __UCHARBIT_COM01(name,size)	__UCHARBIT(name, size)
#define __UCHARBIT_COM012(name,size)	__UCHARBIT(name, size)
#define __UCHARBIT_COM0123(name,size)	__UCHARBIT(name, size)

#endif
