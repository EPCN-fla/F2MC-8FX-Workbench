/*
 MB95870 Series I/O register declaration file V01L02
 ALL RIGHTS RESERVED, COPYRIGHT (C) FUJITSU SEMICONDUCTOR LIMITED 2012
 LICENSED MATERIAL - PROGRAM PROPERTY OF FUJITSU SEMICONDUCTOR LIMITED
*/

#if defined(__CPU_MB95F876K__) 
#ifdef __FASM__
#include "mb95870_a.inc"
#else
#include "mb95870.h"
#endif
#else
#error "The I/O register file of the specified CPU option does not exist"
#endif
