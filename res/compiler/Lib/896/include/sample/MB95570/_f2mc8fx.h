/*
 MB95570 Series I/O register declaration file V01L02
 ALL RIGHTS RESERVED, COPYRIGHT (C) FUJITSU SEMICONDUCTOR LIMITED 2010
 LICENSED MATERIAL - PROGRAM PROPERTY OF FUJITSU SEMICONDUCTOR LIMITED
*/

#if defined(__CPU_MB95F572H__) || \
    defined(__CPU_MB95F572K__) || \
    defined(__CPU_MB95F573H__) || \
    defined(__CPU_MB95F573K__) || \
    defined(__CPU_MB95F574H__) || \
    defined(__CPU_MB95F574K__) 
#ifdef __FASM__
#include "mb95570_a.inc"
#else
#include "mb95570.h"
#endif
#else
#error "The I/O register file of the specified CPU option does not exist"
#endif
