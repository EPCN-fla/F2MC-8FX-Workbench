/*
 MB95260 Series I/O register declaration file V01L04
 ALL RIGHTS RESERVED, COPYRIGHT (C) FUJITSU MICROELECTRONICS LIMITED 2008
 LICENSED MATERIAL - PROGRAM PROPERTY OF FUJITSU MICROELECTRONICS LIMITED
*/

#if defined(__CPU_MB95F262H__) || \
    defined(__CPU_MB95F262K__) || \
    defined(__CPU_MB95F263H__) || \
    defined(__CPU_MB95F263K__) || \
    defined(__CPU_MB95F264H__) || \
    defined(__CPU_MB95F264K__) || \
    defined(__CPU_MB95F262HA__) || \
    defined(__CPU_MB95F262KA__) || \
    defined(__CPU_MB95F263HA__) || \
    defined(__CPU_MB95F263KA__) || \
    defined(__CPU_MB95F264HA__) || \
    defined(__CPU_MB95F264KA__) 
#ifdef __FASM__
#include "mb95260_a.inc"
#else
#include "mb95260.h"
#endif
#else
#error "The I/O register file of the specified CPU option does not exist"
#endif
