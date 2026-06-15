/*
 MB95470 Series I/O register declaration file V01L01
 ALL RIGHTS RESERVED, COPYRIGHT (C) FUJITSU SEMICONDUCTOR LIMITED 2010
 LICENSED MATERIAL - PROGRAM PROPERTY OF FUJITSU SEMICONDUCTOR LIMITED
*/

#if defined(__CPU_MB95F474H__) || \
    defined(__CPU_MB95F474K__) || \
    defined(__CPU_MB95F476H__) || \
    defined(__CPU_MB95F476K__) || \
    defined(__CPU_MB95F478H__) || \
    defined(__CPU_MB95F478K__) 
#ifdef __FASM__
#include "mb95470_a.inc"
#else
#include "mb95470.h"
#endif
#else
#error "The I/O register file of the specified CPU option does not exist"
#endif
