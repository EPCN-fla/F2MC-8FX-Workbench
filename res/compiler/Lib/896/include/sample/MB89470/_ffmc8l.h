/*
 F2MC-8L family I/O register declaration file V30L08R01
 ALL RIGHTS RESERVED, COPYRIGHT (C) FUJITSU LIMITED 1998
 LICENSED MATERIAL - PROGRAM PROPERTY OF FUJITSU LIMITED
*/

#if defined(__CPU_MB89475__)   || defined(__CPU_MB89P475__)  || \
    defined(__CPU_MB89PV470__)

#include "_mb89470.h"

#else
#error "The I/O register file of the specified CPU option does not exist"

#endif
