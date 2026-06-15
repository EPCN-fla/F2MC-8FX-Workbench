/*
 MB95390 Series I/O register declaration file V01L04
 ALL RIGHTS RESERVED, COPYRIGHT (C) FUJITSU MICROELECTRONICS LIMITED 2009
 LICENSED MATERIAL - PROGRAM PROPERTY OF FUJITSU MICROELECTRONICS LIMITED
*/

#if defined(__CPU_MB95F394H__) || \
    defined(__CPU_MB95F394K__) || \
    defined(__CPU_MB95F396H__) || \
    defined(__CPU_MB95F396K__) || \
    defined(__CPU_MB95F398H__) || \
    defined(__CPU_MB95F398K__) 
#ifdef __FASM__
#include "mb95390_a.inc"
#else
#include "mb95390.h"
#endif
#else
#error "The I/O register file of the specified CPU option does not exist"
#endif
