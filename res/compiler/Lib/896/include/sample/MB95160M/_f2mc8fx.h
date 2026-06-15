/*
 MB95160M Series I/O register declaration file V01L02
 ALL RIGHTS RESERVED, COPYRIGHT (C) FUJITSU LIMITED 2004
 LICENSED MATERIAL - PROGRAM PROPERTY OF FUJITSU LIMITED
*/

#if defined(__CPU_MB95F168M__) || \
    defined(__CPU_MB95F166__)
#ifdef __FASM__
#include "mb95160m_a.inc"
#else
#include "mb95160m.h"
#endif
#else
#error "The I/O register file of the specified CPU option does not exist"
#endif
