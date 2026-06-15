/*
 MB95210 Series I/O register declaration file V01L03
 ALL RIGHTS RESERVED, COPYRIGHT (C) FUJITSU MICROELECTRONICS LIMITED 2008
 LICENSED MATERIAL - PROGRAM PROPERTY OF FUJITSU MICROELECTRONICS LIMITED
*/

#if defined(__CPU_MB95F212K__) || \
    defined(__CPU_MB95F213K__) || \
    defined(__CPU_MB95F214K__) || \
    defined(__CPU_MB95F212H__) || \
    defined(__CPU_MB95F213H__) || \
    defined(__CPU_MB95F214H__) 
#ifdef __FASM__
#include "mb95210_a.inc"
#else
#include "mb95210.h"
#endif
#else
#error "The I/O register file of the specified CPU option does not exist"
#endif
