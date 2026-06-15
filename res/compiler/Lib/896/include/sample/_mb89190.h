/*
 MB89190/190A Series I/O register declaration file V30L08
 ALL RIGHTS RESERVED, COPYRIGHT (C) FUJITSU LIMITED 1998
 LICENSED MATERIAL - PROGRAM PROPERTY OF FUJITSU LIMITED
*/
#ifdef __FASM__
#include "_mb891xx_a.h"
#else
#include "_mb891xx.h"
#endif

/* I/O Area Address */
#ifdef __FASM__
#ifdef __IO_DEFINE
  .section IO_REG, IOCOMMON, locate=0x000000
#else
  .section IO, IO, ALIGN=1
#endif
#else
#ifdef __IO_DEFINE
  #pragma section IO=IO_REG, attr=IOCOMMON, locate=0x000000
#endif
#endif

__IO_EXTERN __UNION_D(io_pdr0,IO_PDR0)		/* addr 00h */
__IO_EXTERN __UCHAR_D(IO_DDR0)			/* addr 01h */
__IO_EXTERN __UNION_D(io_eni0,IO_ENI0)		/* addr 02h */
__IO_STATIC __RESERVE_D(dmy_03_07,5)		/* addr 03-07h */
__IO_EXTERN __UNION_D(io_stbc,IO_STBC)		/* addr 08h */
__IO_EXTERN __UCHAR_D(IO_WDTC)			/* addr 09h */
__IO_EXTERN __UNION_D(io_tbtc,IO_TBTC)		/* addr 0Ah */
__IO_STATIC __RESERVE_D(dmy_0B,1)		/* addr 0Bh */
__IO_EXTERN __UNION_D(io_pdr3,IO_PDR3)		/* addr 0Ch */
__IO_EXTERN __UCHAR_D(IO_DDR3)			/* addr 0Dh */
__IO_EXTERN __UNION_D(io_pdr4,IO_PDR4)		/* addr 0Eh */
__IO_EXTERN __UNION_D(io_bzcr,IO_BZCR)		/* addr 0Fh */
__IO_STATIC __RESERVE_D(dmy_10_13,4)		/* addr 10-13h */
__IO_EXTERN __UNION_D(io_rcr1,IO_RCR1)		/* addr 14h */
__IO_EXTERN __UNION_D(io_rcr2,IO_RCR2)		/* addr 15h */
__IO_STATIC __RESERVE_D(dmy_16_17,2)		/* addr 16-17h */
__IO_EXTERN __UNION_D(io_t2cr,IO_T2CR)		/* addr 18h */
__IO_EXTERN __UNION_D(io_t1cr,IO_T1CR)		/* addr 19h */
__IO_EXTERN __UNION_D(io_t12dr,IO_T12DR)	/* addr 1A-1Bh */
__IO_EXTERN __UNION_D(io_smr,IO_SMR)		/* addr 1Ch */
__IO_EXTERN __UCHAR_D(IO_SDR)			/* addr 1Dh */
__IO_STATIC __RESERVE_D(dmy_1E_1F,2)		/* addr 1E-1Fh */
#if defined(__CPU_MB89190A__)  || defined(__CPU_MB89191A__) || \
    defined(__CPU_MB89193A__)  || defined(__CPU_MB89195A__) || \
    defined(__CPU_MB89P195A__) || defined(__CPU_MB89PV190A__)
__IO_EXTERN __UNION_D(io_adc1,IO_ADC1)		/* addr 20h */
__IO_EXTERN __UNION_D(io_adc2,IO_ADC2)		/* addr 21h */
__IO_EXTERN __UCHAR_D(IO_ADCD)			/* addr 22h */
#else
__IO_STATIC __RESERVE_D(dmy_20_22,3)		/* addr 20-22h */
#endif
__IO_EXTERN __UNION_D(io_eic1,IO_EIC1)		/* addr 23h */
__IO_EXTERN __UNION_D(io_eic2,IO_EIC2)		/* addr 24h */
__IO_STATIC __RESERVE_D(dmy_25_31,13)		/* addr 25-31h */
__IO_EXTERN __UNION_D(io_eie2,IO_EIE2)		/* addr 32h */
__IO_EXTERN __UNION_D(io_eif2,IO_EIF2)		/* addr 33h */
__IO_STATIC __RESERVE_D(dmy_34_7B,72)		/* addr 34-7Bh */
__IO_EXTERN __UCHAR_D(IO_ILR1)			/* addr 7Ch */
__IO_EXTERN __UCHAR_D(IO_ILR2)			/* addr 7Dh */
__IO_EXTERN __UCHAR_D(IO_ILR3)			/* addr 7Eh */
__IO_STATIC __RESERVE_D(dmy_7F,1)		/* addr 7Fh */
