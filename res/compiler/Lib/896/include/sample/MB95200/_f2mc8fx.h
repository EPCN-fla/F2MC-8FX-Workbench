/*
 MB95200 Series I/O register declaration file V01L03
 ALL RIGHTS RESERVED, COPYRIGHT (C) FUJITSU MICROELECTRONICS LIMITED 2008
 LICENSED MATERIAL - PROGRAM PROPERTY OF FUJITSU MICROELECTRONICS LIMITED
*/

#if defined(__CPU_MB95F202K__) || \
    defined(__CPU_MB95F203K__) || \
    defined(__CPU_MB95F204K__) || \
    defined(__CPU_MB95F202H__) || \
    defined(__CPU_MB95F203H__) || \
    defined(__CPU_MB95F204H__) 
#ifdef __FASM__
#include "mb95200_a.inc"
#else
#include "mb95200.h"
#endif
#else
#error "The I/O register file of the specified CPU option does not exist"
#endif
