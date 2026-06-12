/*
 MB95140 Series I/O register declaration file V01L02
 ALL RIGHTS RESERVED, COPYRIGHT (C) FUJITSU LIMITED 2004
 LICENSED MATERIAL - PROGRAM PROPERTY OF FUJITSU LIMITED
*/

#if defined(__CPU_MB95F146S__) || defined(__CPU_MB95F146W__)
 #ifdef __FASM__
  #include "mb95140_a.inc"
 #else
  #include "mb95140.h"
 #endif
#else
 #error "The I/O register file of the specified CPU option does not exist"
#endif
