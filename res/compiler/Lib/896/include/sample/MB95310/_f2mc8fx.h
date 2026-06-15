/*
 MB95310 Series I/O register declaration file V01L02
 ALL RIGHTS RESERVED, COPYRIGHT (C) FUJITSU MICROELECTRONICS LIMITED 2009
 LICENSED MATERIAL - PROGRAM PROPERTY OF FUJITSU MICROELECTRONICS LIMITED
*/

#if defined(__CPU_MB95F314E__) || \
    defined(__CPU_MB95F314L__) || \
    defined(__CPU_MB95F316E__) || \
    defined(__CPU_MB95F316L__) || \
    defined(__CPU_MB95F318__) || \
    defined(__CPU_MB95F318E__) || \
    defined(__CPU_MB95F318L__) 
#ifdef __FASM__
#include "mb95310_a.inc"
#else
#include "mb95310.h"
#endif
#else
#error "The I/O register file of the specified CPU option does not exist"
#endif
