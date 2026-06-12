/*
 MB95330 Series I/O register declaration file V01L03
 ALL RIGHTS RESERVED, COPYRIGHT (C) FUJITSU MICROELECTRONICS LIMITED 2009
 LICENSED MATERIAL - PROGRAM PROPERTY OF FUJITSU MICROELECTRONICS LIMITED
*/

#if defined(__CPU_MB95F332H__) || \
    defined(__CPU_MB95F332K__) || \
    defined(__CPU_MB95F333H__) || \
    defined(__CPU_MB95F333K__) || \
    defined(__CPU_MB95F334H__) || \
    defined(__CPU_MB95F334K__) 
#ifdef __FASM__
#include "mb95330_a.inc"
#else
#include "mb95330.h"
#endif
#else
#error "The I/O register file of the specified CPU option does not exist"
#endif
