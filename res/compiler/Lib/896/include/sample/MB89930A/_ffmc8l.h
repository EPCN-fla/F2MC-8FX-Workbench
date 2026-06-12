/*
 MB89930A Series I/O register declaration file V01L01
 ALL RIGHTS RESERVED, COPYRIGHT (C) FUJITSU LIMITED 2004
 LICENSED MATERIAL - PROGRAM PROPERTY OF FUJITSU LIMITED
*/

#if defined(__CPU_MB89PV930A__) || \
    defined(__CPU_MB89935A__) || \
    defined(__CPU_MB89935B__) || \
    defined(__CPU_MB89P935A__) || \
    defined(__CPU_MB89P935B__) 
#ifdef __FASM__
#include "mb89930a_a.inc"
#else
#include "mb89930a.h"
#endif
#else
#error "The I/O register file of the specified CPU option does not exist"
#endif
