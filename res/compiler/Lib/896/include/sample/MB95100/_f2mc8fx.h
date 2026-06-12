/*
 MB95100 Series I/O register declaration file V01L02
 ALL RIGHTS RESERVED, COPYRIGHT (C) FUJITSU LIMITED 2004
 LICENSED MATERIAL - PROGRAM PROPERTY OF FUJITSU LIMITED
*/

#if defined(__CPU_MB95F108S__) || \
    defined(__CPU_MB95F108W__) || \
    defined(__CPU_MB95107__) || \
    defined(__CPU_MB95F108HS__) || \
    defined(__CPU_MB95F108HW__) || \
    defined(__CPU_MB95108H__) || \
    defined(__CPU_MB95F104AMS__) || \
    defined(__CPU_MB95F104AMW__) || \
    defined(__CPU_MB95F106AMS__) || \
    defined(__CPU_MB95F106AMW__) || \
    defined(__CPU_MB95108AM__) || \
    defined(__CPU_MB95F108AMS__) || \
    defined(__CPU_MB95F108AMW__) || \
    defined(__CPU_MB95107B__) || \
    defined(__CPU_MB95F108BS__) || \
    defined(__CPU_MB95F108BW__)
 #ifdef __FASM__
  #include "mb95100_a.inc"
 #else
  #include "mb95100.h"
 #endif
#else
 #error "The I/O register file of the specified CPU option does not exist"
#endif
