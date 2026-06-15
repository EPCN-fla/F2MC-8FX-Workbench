/*
 F2MC-8L family I/O register declaration file V30L08R03
 ALL RIGHTS RESERVED, COPYRIGHT (C) FUJITSU LIMITED 1998
 LICENSED MATERIAL - PROGRAM PROPERTY OF FUJITSU LIMITED
*/

#if defined(__CPU_MB89485__)   || defined(__CPU_MB89485L__)  || \
    defined(__CPU_MB89P485__)  || defined(__CPU_MB89P485L__) || \
    defined(__CPU_MB89PV480__)

#include "_mb89480.h"

#else
#error "The I/O register file of the specified CPU option does not exist"

#endif
