/*
 MB95430 Series I/O register declaration file V01L03
 ALL RIGHTS RESERVED, COPYRIGHT (C) FUJITSU MICROELECTRONICS LIMITED 2010
 LICENSED MATERIAL - PROGRAM PROPERTY OF FUJITSU MICROELECTRONICS LIMITED
*/

#if defined(__CPU_MB95F434H__) || \
    defined(__CPU_MB95F434K__) 
#ifdef __FASM__
#include "mb95430_a.inc"
#else
#include "mb95430.h"
#endif
#else
#error "The I/O register file of the specified CPU option does not exist"
#endif
