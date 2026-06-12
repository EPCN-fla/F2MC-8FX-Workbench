/*
 MB95130 Series I/O register declaration file V01L04
 ALL RIGHTS RESERVED, COPYRIGHT (C) FUJITSU LIMITED 2004
 LICENSED MATERIAL - PROGRAM PROPERTY OF FUJITSU LIMITED
*/

#if defined(__CPU_MB95F136HS__) || defined(__CPU_MB95F136HW__) || \
    defined(__CPU_MB95F136MS__) || defined(__CPU_MB95F136MW__) || \
    defined(__CPU_MB95136M__) || \
    defined(__CPU_MB95F133MS__) || \
    defined(__CPU_MB95F133MW__) || \
    defined(__CPU_MB95F134MS__) || \
    defined(__CPU_MB95F134MW__) || \
    defined(__CPU_MB95F136MBS__) || defined(__CPU_MB95F136MBW__) || \
    defined(__CPU_MB95136MB__) || \
    defined(__CPU_MB95F133MBS__) || \
    defined(__CPU_MB95F133MBW__) || \
    defined(__CPU_MB95F134MBS__) || \
    defined(__CPU_MB95F134MBW__)
 #ifdef __FASM__
  #include "mb95130_a.inc"
 #else
  #include "mb95130.h"
 #endif
#else
 #error "The I/O register file of the specified CPU option does not exist"
#endif
