/*
 MB95350L Series I/O register declaration file V01L03
 ALL RIGHTS RESERVED, COPYRIGHT (C) FUJITSU MICROELECTRONICS LIMITED 2009
 LICENSED MATERIAL - PROGRAM PROPERTY OF FUJITSU MICROELECTRONICS LIMITED
*/

#if defined(__CPU_MB95F352E__) || \
    defined(__CPU_MB95F353E__) || \
    defined(__CPU_MB95F354E__) || \
    defined(__CPU_MB95F352L__) || \
    defined(__CPU_MB95F353L__) || \
    defined(__CPU_MB95F354L__) 
#ifdef __FASM__
#include "mb95350l_a.inc"
#else
#include "mb95350l.h"
#endif
#else
#error "The I/O register file of the specified CPU option does not exist"
#endif
