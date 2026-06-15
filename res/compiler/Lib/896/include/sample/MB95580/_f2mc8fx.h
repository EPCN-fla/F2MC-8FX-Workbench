/*
 MB95580 Series I/O register declaration file V01L02
 ALL RIGHTS RESERVED, COPYRIGHT (C) FUJITSU SEMICONDUCTOR LIMITED 2010
 LICENSED MATERIAL - PROGRAM PROPERTY OF FUJITSU SEMICONDUCTOR LIMITED
*/

#if defined(__CPU_MB95F582H__) || \
    defined(__CPU_MB95F582K__) || \
    defined(__CPU_MB95F583H__) || \
    defined(__CPU_MB95F583K__) || \
    defined(__CPU_MB95F584H__) || \
    defined(__CPU_MB95F584K__) 
#ifdef __FASM__
#include "mb95580_a.inc"
#else
#include "mb95580.h"
#endif
#else
#error "The I/O register file of the specified CPU option does not exist"
#endif
