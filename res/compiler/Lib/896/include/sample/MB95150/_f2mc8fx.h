/*
 MB95150 Series I/O register declaration file V01L02
 ALL RIGHTS RESERVED, COPYRIGHT (C) FUJITSU LIMITED 2004
 LICENSED MATERIAL - PROGRAM PROPERTY OF FUJITSU LIMITED
*/

#if defined(__CPU_MB95F156H__) || \
    defined(__CPU_MB95156M__) || \
    defined(__CPU_MB95F156M__)
 #ifdef __FASM__
  #include "mb95150_a.inc"
 #else
  #include "mb95150.h"
 #endif
#else
 #error "The I/O register file of the specified CPU option does not exist"
#endif
