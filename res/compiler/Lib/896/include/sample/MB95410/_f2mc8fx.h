/*
 MB95410 Series I/O register declaration file V01L01
 ALL RIGHTS RESERVED, COPYRIGHT (C) FUJITSU SEMICONDUCTOR LIMITED 2010
 LICENSED MATERIAL - PROGRAM PROPERTY OF FUJITSU SEMICONDUCTOR LIMITED
*/

#if defined(__CPU_MB95F414H__) || \
    defined(__CPU_MB95F414K__) || \
    defined(__CPU_MB95F416H__) || \
    defined(__CPU_MB95F416K__) || \
    defined(__CPU_MB95F418H__) || \
    defined(__CPU_MB95F418K__) 
#ifdef __FASM__
#include "mb95410_a.inc"
#else
#include "mb95410.h"
#endif
#else
#error "The I/O register file of the specified CPU option does not exist"
#endif
