/*
 MB95810 Series I/O register declaration file V01L01
 ALL RIGHTS RESERVED, COPYRIGHT (C) FUJITSU SEMICONDUCTOR LIMITED 2011
 LICENSED MATERIAL - PROGRAM PROPERTY OF FUJITSU SEMICONDUCTOR LIMITED
*/

#if defined(__CPU_MB95F814K__) || \
    defined(__CPU_MB95F816K__) || \
    defined(__CPU_MB95F818K__) 
#ifdef __FASM__
#include "mb95810_a.inc"
#else
#include "mb95810.h"
#endif
#else
#error "The I/O register file of the specified CPU option does not exist"
#endif
