/*
 MB89201 Series I/O register declaration file V01L01
 ALL RIGHTS RESERVED, COPYRIGHT (C) FUJITSU LIMITED 2004
 LICENSED MATERIAL - PROGRAM PROPERTY OF FUJITSU LIMITED
*/

#if defined(__CPU_MB89F202__) 
#ifdef __FASM__
#include "mb89201_a.inc"
#else
#include "mb89201.h"
#endif
#else
#error "The I/O register file of the specified CPU option does not exist"
#endif
