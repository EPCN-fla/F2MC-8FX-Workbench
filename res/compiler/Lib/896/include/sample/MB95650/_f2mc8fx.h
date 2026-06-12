/*
 MB95650 Series I/O register declaration file V01L01
 ALL RIGHTS RESERVED, COPYRIGHT (C) FUJITSU SEMICONDUCTOR LIMITED 2012
 LICENSED MATERIAL - PROGRAM PROPERTY OF FUJITSU SEMICONDUCTOR LIMITED
*/

#if defined(__CPU_MB95F652E__) || \
    defined(__CPU_MB95F652L__) || \
    defined(__CPU_MB95F653E__) || \
    defined(__CPU_MB95F653L__) || \
    defined(__CPU_MB95F654E__) || \
    defined(__CPU_MB95F654L__) || \
    defined(__CPU_MB95F656E__) || \
    defined(__CPU_MB95F656L__) 
#ifdef __FASM__
#include "mb95650_a.inc"
#else
#include "mb95650.h"
#endif
#else
#error "The I/O register file of the specified CPU option does not exist"
#endif
