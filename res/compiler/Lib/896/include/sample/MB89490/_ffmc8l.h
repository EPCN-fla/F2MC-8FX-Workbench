/*
 F2MC-8L family I/O register declaration file V30L08R03
 ALL RIGHTS RESERVED, COPYRIGHT (C) FUJITSU LIMITED 1998
 LICENSED MATERIAL - PROGRAM PROPERTY OF FUJITSU LIMITED
*/

/* Flash Memory Series */
#if   defined(__CPU_MB89F499__)
#define __CPU_MB89F490_SERIES
#endif

#if defined(__CPU_MB89497__)   || defined(__CPU_MB89498__)  || \
    defined(__CPU_MB89F499__)  || defined(__CPU_MB89PV490__)

#include "_mb89490.h"

#else
#error "The I/O register file of the specified CPU option does not exist"

#endif
