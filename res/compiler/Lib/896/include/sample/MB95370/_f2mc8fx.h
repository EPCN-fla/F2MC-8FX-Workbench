/*
 MB95370 Series I/O register declaration file V01L02
 ALL RIGHTS RESERVED, COPYRIGHT (C) FUJITSU MICROELECTRONICS LIMITED 2009
 LICENSED MATERIAL - PROGRAM PROPERTY OF FUJITSU MICROELECTRONICS LIMITED
*/

#if defined(__CPU_MB95F374E__) || \
    defined(__CPU_MB95F374L__) || \
    defined(__CPU_MB95F376E__) || \
    defined(__CPU_MB95F376L__) || \
    defined(__CPU_MB95F378E__) || \
    defined(__CPU_MB95F378L__) 
#ifdef __FASM__
#include "mb95370_a.inc"
#else
#include "mb95370.h"
#endif
#else
#error "The I/O register file of the specified CPU option does not exist"
#endif
