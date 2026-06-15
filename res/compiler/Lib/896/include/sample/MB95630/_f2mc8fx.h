/*
 MB95630 Series I/O register declaration file V01L02
 ALL RIGHTS RESERVED, COPYRIGHT (C) FUJITSU SEMICONDUCTOR LIMITED 2011
 LICENSED MATERIAL - PROGRAM PROPERTY OF FUJITSU SEMICONDUCTOR LIMITED
*/

#if defined(__CPU_MB95F632H__) || \
    defined(__CPU_MB95F632K__) || \
    defined(__CPU_MB95F633H__) || \
    defined(__CPU_MB95F633K__) || \
    defined(__CPU_MB95F634H__) || \
    defined(__CPU_MB95F634K__) || \
    defined(__CPU_MB95F636H__) || \
    defined(__CPU_MB95F636K__) 
#ifdef __FASM__
#include "mb95630_a.inc"
#else
#include "mb95630.h"
#endif
#else
#error "The I/O register file of the specified CPU option does not exist"
#endif
