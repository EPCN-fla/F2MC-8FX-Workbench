/*
 MB95R203 Series I/O register declaration file V01L03
 ALL RIGHTS RESERVED, COPYRIGHT (C) FUJITSU MICROELECTRONICS LIMITED 2008
 LICENSED MATERIAL - PROGRAM PROPERTY OF FUJITSU MICROELECTRONICS LIMITED
*/

#if defined(__CPU_MB95R203__) || \
    defined(__CPU_MB95R203A__) 
#ifdef __FASM__
#include "mb95r203_a.inc"
#else
#include "mb95r203.h"
#endif
#else
#error "The I/O register file of the specified CPU option does not exist"
#endif
