/*
 MB95690 Series I/O register declaration file V01L02
 ALL RIGHTS RESERVED, COPYRIGHT (C) FUJITSU SEMICONDUCTOR LIMITED 2011
 LICENSED MATERIAL - PROGRAM PROPERTY OF FUJITSU SEMICONDUCTOR LIMITED
*/

#if defined(__CPU_MB95F694K__) || \
    defined(__CPU_MB95F696K__) || \
    defined(__CPU_MB95F698K__) 
#ifdef __FASM__
#include "mb95690_a.inc"
#else
#include "mb95690.h"
#endif
#else
#error "The I/O register file of the specified CPU option does not exist"
#endif
