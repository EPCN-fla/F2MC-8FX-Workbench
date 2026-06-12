/*
 F2MC-8L family I/O register declaration file V30L08R02
 ALL RIGHTS RESERVED, COPYRIGHT (C) FUJITSU LIMITED 1998
 LICENSED MATERIAL - PROGRAM PROPERTY OF FUJITSU LIMITED
*/

/* Flash Memory Series */
#if   defined(__CPU_MB89F217__)
#define __CPU_MB89F210_SERIES
#endif

#if defined(__CPU_MB89215__)   || defined(__CPU_MB89P215__)  || \
    defined(__CPU_MB89PV210__) || defined(__CPU_MB89F217__)

#include "_mb89210.h"

#else
#error "The I/O register file of the specified CPU option does not exist"

#endif
