/*
 MB95280 Series I/O register declaration file V01L04
 ALL RIGHTS RESERVED, COPYRIGHT (C) FUJITSU MICROELECTRONICS LIMITED 2008
 LICENSED MATERIAL - PROGRAM PROPERTY OF FUJITSU MICROELECTRONICS LIMITED
*/

#if defined(__CPU_MB95F282H__) || \
    defined(__CPU_MB95F282K__) || \
    defined(__CPU_MB95F283H__) || \
    defined(__CPU_MB95F283K__) || \
    defined(__CPU_MB95F284H__) || \
    defined(__CPU_MB95F284K__) || \
    defined(__CPU_MB95F282HA__) || \
    defined(__CPU_MB95F282KA__) || \
    defined(__CPU_MB95F283HA__) || \
    defined(__CPU_MB95F283KA__) || \
    defined(__CPU_MB95F284HA__) || \
    defined(__CPU_MB95F284KA__) 
#ifdef __FASM__
#include "mb95280_a.inc"
#else
#include "mb95280.h"
#endif
#else
#error "The I/O register file of the specified CPU option does not exist"
#endif
