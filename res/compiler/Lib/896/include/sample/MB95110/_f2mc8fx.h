/*
 MB95110 Series I/O register declaration file V01L03
 ALL RIGHTS RESERVED, COPYRIGHT (C) FUJITSU MICROELECTRONICS LIMITED 2008
 LICENSED MATERIAL - PROGRAM PROPERTY OF FUJITSU MICROELECTRONICS LIMITED
*/

#if defined(__CPU_MB95F118S__) || \
    defined(__CPU_MB95F118W__) || \
    defined(__CPU_MB95116__) || \
    defined(__CPU_MB95116B__) || \
    defined(__CPU_MB95F118BS__) || \
    defined(__CPU_MB95F118BW__) || \
    defined(__CPU_MB95F114MS__) || \
    defined(__CPU_MB95F114MW__) || \
    defined(__CPU_MB95F116MS__) || \
    defined(__CPU_MB95F116MW__) || \
    defined(__CPU_MB95117M__) || \
    defined(__CPU_MB95F118MS__) || \
    defined(__CPU_MB95F118MW__) || \
    defined(__CPU_MB95F116MAS__) || \
    defined(__CPU_MB95F116MAW__) 
#ifdef __FASM__
#include "mb95110_a.inc"
#else
#include "mb95110.h"
#endif
#else
#error "The I/O register file of the specified CPU option does not exist"
#endif
