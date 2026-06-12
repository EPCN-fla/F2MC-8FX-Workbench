/*
 MB95120 Series I/O register declaration file V01L03
 ALL RIGHTS RESERVED, COPYRIGHT (C) FUJITSU LIMITED 2004
 LICENSED MATERIAL - PROGRAM PROPERTY OF FUJITSU LIMITED
*/

#if defined(__CPU_MB95F128HW__) || defined(__CPU_MB95F128__) || \
    defined(__CPU_MB95F128MB__) || \
    defined(__CPU_MB95F124MB__) || \
    defined(__CPU_MB95F126MB__) || \
    defined(__CPU_MB95128MB__)
 #ifdef __FASM__
  #include "mb95120_a.inc"
 #else
  #include "mb95120.h"
 #endif
#else
 #error "The I/O register file of the specified CPU option does not exist"
#endif
