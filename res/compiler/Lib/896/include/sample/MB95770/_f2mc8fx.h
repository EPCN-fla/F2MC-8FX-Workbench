/*
 MB95770 Series I/O register declaration file V01L01
 ALL RIGHTS RESERVED, COPYRIGHT (C) FUJITSU SEMICONDUCTOR LIMITED 2012
 LICENSED MATERIAL - PROGRAM PROPERTY OF FUJITSU SEMICONDUCTOR LIMITED
*/

#if defined(__CPU_MB95F774L__) || \
    defined(__CPU_MB95F776L__) || \
    defined(__CPU_MB95F778L__) || \
    defined(__CPU_MB95F774E__) || \
    defined(__CPU_MB95F776E__) || \
    defined(__CPU_MB95F778E__) 
#ifdef __FASM__
#include "mb95770_a.inc"
#else
#include "mb95770.h"
#endif
#else
#error "The I/O register file of the specified CPU option does not exist"
#endif
