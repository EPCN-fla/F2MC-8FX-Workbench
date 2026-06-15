/*
 F2MC-8L family I/O register macro declaration file V30L08
 ALL RIGHTS RESERVED, COPYRIGHT (C) FUJITSU LIMITED 1998
 LICENSED MATERIAL - PROGRAM PROPERTY OF FUJITSU LIMITED
*/

#macro  __GLOBAL_SYMBOL		sname, uname, asym, dummy
	.GLOBAL			\asym\sname
#ifdef  __IO_DEFINE
\asym\sname	.res.b  0
#endif
	uname			sname
#endm

#macro	__GLOBAL_SYMBOL_A		sname, uname, size, asym, join, dummy
	.GLOBAL			\asym\sname
#ifdef  __IO_DEFINE
\asym\sname	.res.b  0
#endif
	#set CNT   0
	#repeat	size
	#define	S_NAME	sname\join\CNT

	.GLOBAL			\asym\S_NAME
#ifdef  __IO_DEFINE
\asym\S_NAME	.res.b  0
#endif

	uname			S_NAME
	#set CNT CNT+1
	#endm
#endm

#macro	__GLOBAL_SYMBOL_MEM_A	sname, uname, size, asym, join, dummy
	.GLOBAL			\asym\sname
#ifdef  __IO_DEFINE
\asym\sname	.res.b  0
#endif
	#set CNT_MEM   0
	#repeat	size
	#define	S_NAME_MEM	sname\join\CNT_MEM

	.GLOBAL			\asym\S_NAME_MEM
#ifdef  __IO_DEFINE
\asym\S_NAME_MEM	.res.b  0
#endif

	uname			S_NAME_MEM
	#set CNT_MEM CNT_MEM+1
	#endm

#endm

#macro __ORG_SYMBOL		name,asym
#ifdef  __IO_DEFINE
	.ORG			\asym\name
#endif
#endm

#macro	__GLOBAL_RES_B		uname, sname, size, asym, join, dummy
	.GLOBAL			\asym\uname\join\sname
#ifdef __IO_DEFINE
\asym\uname\join\sname		.RES.b	size
#endif
#endm

#macro	__GLOBAL_RES_B_A		uname, sname, size, cnt, asym, join, dummy
	.GLOBAL			\asym\uname\join\sname
#ifdef __IO_DEFINE
\asym\uname\join\sname		.RES.b	(size * cnt)
#endif
#endm

#macro	__GLOBAL_RES_I		uname, sname, size, asym, join, dummy
	.GLOBAL			\asym\uname\join\sname
#ifdef __IO_DEFINE
\asym\uname\join\sname		.RES.i	size
#endif
#endm

#macro	__GLOBAL_RES_I_UNION	uname, sname, size, asym, join, dummy
	.GLOBAL			\asym\uname\join\sname
#ifdef __IO_DEFINE
	.ORG			\asym\uname
\asym\uname\join\sname		.RES.i	size
#endif
#endm

#macro	__AREA_RES_B		size
#ifdef __IO_DEFINE
				.RES.b	size
#endif
#endm

#macro __AREA_RES_I		size
#ifdef  __IO_DEFINE
				.RES.i	size
#endif
#endm

