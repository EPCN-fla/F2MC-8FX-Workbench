/*
 MB89210 Series I/O register declaration file V30L08R02
 ALL RIGHTS RESERVED, COPYRIGHT (C) FUJITSU LIMITED 1998
 LICENSED MATERIAL - PROGRAM PROPERTY OF FUJITSU LIMITED
*/
#ifdef __FASM__
#include "_ra89210.h"
#else
#include "_r89210.h"
#endif

/* I/O Area Address */
#ifdef __FASM__
#ifdef __IO_DEFINE
  .section IO_REG, IOCOMMON, locate=0x000000
#else
  .section IO, IO
#endif
#else
#ifdef __IO_DEFINE
  #pragma section IO=IO_REG, attr=IOCOMMON, locate=0x000000
#else
  #pragma section IO=IO, attr=IO
#endif
#endif

__IO_EXTERN __UNION_D(io_pdr0,IO_PDR0)		/* addr 00h */
__IO_EXTERN __UNION_D(io_pdr0,IO_DDR0)		/* addr 01h */
__IO_STATIC __RESERVE_D(dmy_02_06,5)		/* addr 02-06h */
__IO_EXTERN __UCHAR_D(IO_SYCC)			/* addr 07h */
__IO_EXTERN __UNION_D(io_stbc,IO_STBC)		/* addr 08h */
__IO_EXTERN __UCHAR_D(IO_WDTC)			/* addr 09h */
__IO_EXTERN __UNION_D(io_tbtc,IO_TBTC)		/* addr 0Ah */
__IO_STATIC __RESERVE_D(dmy_0B,1)		/* addr 0Bh */
__IO_EXTERN __UNION_D(io_pdr1,IO_PDR1)		/* addr 0Ch */
__IO_EXTERN __UNION_D(io_pdr1,IO_DDR1)		/* addr 0Dh */
__IO_EXTERN __UNION_D(io_rsfr,IO_RSFR)		/* addr 0Eh */
__IO_EXTERN __UNION_D(io_pdr2,IO_PDR2)		/* addr 0Fh */
__IO_EXTERN __UNION_D(io_pdr2,IO_DDR2)		/* addr 10h */
__IO_STATIC __RESERVE_D(dmy_11,1)		/* addr 11h */
__IO_EXTERN __UNION_D(io_pdr3,IO_PDR3)		/* addr 12h */
__IO_EXTERN __UNION_D(io_ddr3,IO_DDR3)		/* addr 13h */
__IO_EXTERN __UNION_D(io_rcr21,IO_RCR21)	/* addr 14h */
__IO_EXTERN __UNION_D(io_rcr22,IO_RCR22)	/* addr 15h */
__IO_EXTERN __UNION_D(io_rcr23,IO_RCR23)	/* addr 16h */
__IO_EXTERN __UNION_D(io_rcr24,IO_RCR24)	/* addr 17h */
__IO_STATIC __RESERVE_D(dmy_18,1)		/* addr 18h */
__IO_EXTERN __UNION_D(io_tccr,IO_TCCR0)		/* addr 19h */
__IO_EXTERN __UNION_D(io_t1cr01,IO_T1CR0)	/* addr 1Ah */
__IO_EXTERN __UNION_D(io_t0cr01,IO_T0CR0)	/* addr 1Bh */
__IO_EXTERN __UNION_D(io_t01dr,IO_TDR0)		/* addr 1C-1Dh */
__IO_EXTERN __UNION_D(io_tcp0,IO_TCP0)		/* addr 1E-1Fh */
__IO_EXTERN __UNION_D(io_tcr2,IO_TCR20)		/* addr 20h */
__IO_STATIC __RESERVE_D(dmy_21,1)		/* addr 21h */
__IO_EXTERN __UNION_D(io_cntr,IO_CNTR)		/* addr 22h */
__IO_EXTERN __UCHAR_D(IO_COMR)			/* addr 23h */
__IO_EXTERN __UNION_D(io_eic1,IO_EIC1)		/* addr 24h */
__IO_EXTERN __UNION_D(io_eic2,IO_EIC2)		/* addr 25h */
__IO_STATIC __RESERVE_D(dmy_26_27,2)		/* addr 26-27h */
__IO_EXTERN __UNION_D(io_scr,IO_SCR)		/* addr 28h */
__IO_EXTERN __UNION_D(io_usmr,IO_USMR)		/* addr 29h */
__IO_EXTERN __UNION_D(io_ssr,IO_SSR)		/* addr 2Ah */
__IO_EXTERN __UCHAR_D(IO_RTDR)			/* addr 2Bh */
__IO_EXTERN __UNION_D(io_escr,IO_ESCR)		/* addr 2Ch */
__IO_EXTERN __UNION_D(io_eccr,IO_ECCR)		/* addr 2Dh */
__IO_EXTERN __UNION_D(io_bgr,IO_BGR)		/* addr 2E-2Fh */
__IO_EXTERN __UNION_D(io_adc1,IO_ADC1)		/* addr 30h */
__IO_EXTERN __UNION_D(io_adc2,IO_ADC2)		/* addr 31h */
__IO_EXTERN __UNION_D(io_add,IO_ADD)		/* addr 32-33h */
__IO_EXTERN __UNION_D(io_aden,IO_ADEN)		/* addr 34h */
__IO_STATIC __RESERVE_D(dmy_35_38,4)		/* addr 35-38h */
__IO_EXTERN __UNION_D(io_smr,IO_SMR)		/* addr 39h */
__IO_EXTERN __UCHAR_D(IO_SDR)			/* addr 3Ah */
__IO_STATIC __RESERVE_D(dmy_3B_40,6)		/* addr 3B-40h */
__IO_EXTERN __UNION_D(io_tccr,IO_TCCR1)		/* addr 41h */
__IO_EXTERN __UNION_D(io_t1cr01,IO_T1CR1)	/* addr 42h */
__IO_EXTERN __UNION_D(io_t0cr01,IO_T0CR1)	/* addr 43h */
__IO_EXTERN __UNION_D(io_t01dr,IO_TDR1)		/* addr 44-45h */
__IO_EXTERN __UNION_D(io_tcp1,IO_TCP1)		/* addr 46-47h */
__IO_EXTERN __UNION_D(io_tcr2,IO_TCR21)		/* addr 48h */
__IO_EXTERN __UNION_D(io_tcsl,IO_TCSL)		/* addr 49h */
__IO_STATIC __RESERVE_D(dmy_4A_5F,22)		/* addr 4A-5Fh */
#if defined(__CPU_MB89215__) || defined(__CPU_MB89P215__) || \
    defined(__CPU_MB89F217__)
__IO_EXTERN __UNION_D(io_xcrs,IO_XCRS)		/* addr 60h */
#else
__IO_STATIC __RESERVE_D(dmy_60,1)		/* addr 60h */
#endif
__IO_STATIC __RESERVE_D(dmy_61_6F,15)		/* addr 61-6Fh */
__IO_EXTERN __UNION_D(io_pul0,IO_PUL0)		/* addr 70h */
__IO_EXTERN __UNION_D(io_pul1,IO_PUL1)		/* addr 71h */
__IO_EXTERN __UNION_D(io_pul2,IO_PUL2)		/* addr 72h */
__IO_EXTERN __UNION_D(io_pul3,IO_PUL3)		/* addr 73h */
__IO_STATIC __RESERVE_D(dmy_74_79,6)		/* addr 74-79h */
#ifdef __CPU_MB89F210_SERIES
__IO_EXTERN __UNION_D(io_fmcs, IO_FMCS)		/* addr 7Ah */
#else
__IO_STATIC __RESERVE_D(dmy_7A,1)		/* addr 7Ah */
#endif
__IO_EXTERN __UCHAR_D(IO_ILR1)			/* addr 7Bh */
__IO_EXTERN __UCHAR_D(IO_ILR2)			/* addr 7Ch */
__IO_EXTERN __UCHAR_D(IO_ILR3)			/* addr 7Dh */
__IO_EXTERN __UCHAR_D(IO_ILR4)			/* addr 7Eh */
__IO_STATIC __RESERVE_D(dmy_7F,1)		/* addr 7Fh */
