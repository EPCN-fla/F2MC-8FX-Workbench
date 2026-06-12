/*
 MB95270 Series I/O register declaration file V01L04
 ALL RIGHTS RESERVED, COPYRIGHT (C) FUJITSU MICROELECTRONICS LIMITED 2008
 LICENSED MATERIAL - PROGRAM PROPERTY OF FUJITSU MICROELECTRONICS LIMITED
*/

#if defined(__CPU_MB95F272H__) || \
    defined(__CPU_MB95F272K__) || \
    defined(__CPU_MB95F273H__) || \
    defined(__CPU_MB95F273K__) || \
    defined(__CPU_MB95F274H__) || \
    defined(__CPU_MB95F274K__) || \
    defined(__CPU_MB95F272HA__) || \
    defined(__CPU_MB95F272KA__) || \
    defined(__CPU_MB95F273HA__) || \
    defined(__CPU_MB95F273KA__) || \
    defined(__CPU_MB95F274HA__) || \
    defined(__CPU_MB95F274KA__) 
#ifdef __FASM__
#include "mb95270_a.inc"
#else
#include "mb95270.h"
#endif
#else
#error "The I/O register file of the specified CPU option does not exist"
#endif
