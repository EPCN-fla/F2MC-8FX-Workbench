/*
 MB95220 Series I/O register declaration file V01L01
 ALL RIGHTS RESERVED, COPYRIGHT (C) FUJITSU MICROELECTRONICS LIMITED 2008
 LICENSED MATERIAL - PROGRAM PROPERTY OF FUJITSU MICROELECTRONICS LIMITED
*/

#if defined(__CPU_MB95F222H__) || \
    defined(__CPU_MB95F222K__) || \
    defined(__CPU_MB95F223H__) || \
    defined(__CPU_MB95F223K__) 
#ifdef __FASM__
#include "mb95220_a.inc"
#else
#include "mb95220.h"
#endif
#else
#error "The I/O register file of the specified CPU option does not exist"
#endif
