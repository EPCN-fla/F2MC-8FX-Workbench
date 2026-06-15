/*
 MB89980 Series I/O register declaration file V30L08
 ALL RIGHTS RESERVED, COPYRIGHT (C) FUJITSU LIMITED 1998
 LICENSED MATERIAL - PROGRAM PROPERTY OF FUJITSU LIMITED
*/
#ifdef __FASM__
#include "_mb899xx_a.h"
#else
#include "_mb899xx.h"
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
__IO_EXTERN __UNION_D(io_pdr1,IO_PDR1)		/* addr 02h */
__IO_EXTERN __UCHAR_D(IO_DDR1)			/* addr 03h */
__IO_EXTERN __UNION_D(io_pdr2,IO_PDR2)		/* addr 04h */
__IO_EXTERN __UCHAR_D(IO_DDR2)			/* addr 05h */
__IO_STATIC __RESERVE_D(dmy_06,1)		/* addr 06h */
__IO_EXTERN __UNION_D(io_sycc,IO_SYCC)		/* addr 07h */
__IO_EXTERN __UNION_D(io_stbc,IO_STBC)		/* addr 08h */
__IO_EXTERN __UCHAR_D(IO_WDTC)			/* addr 09h */
__IO_EXTERN __UNION_D(io_tbtc,IO_TBTC)		/* addr 0Ah */
__IO_EXTERN __UNION_D(io_wpcr,IO_WPCR)		/* addr 0Bh */
__IO_EXTERN __UNION_D(io_pdr3,IO_PDR3)		/* addr 0Ch */
__IO_STATIC __RESERVE_D(dmy_0D,1)		/* addr 0Dh */
__IO_EXTERN __UNION_D(io_pdr4,IO_PDR4)		/* addr 0Eh */
__IO_EXTERN __UNION_D(io_pdr5,IO_PDR5)		/* addr 0Fh */
__IO_EXTERN __UNION_D(io_bzcr,IO_BZCR)		/* addr 10h */
__IO_STATIC __RESERVE_D(dmy_11,1)		/* addr 11h */
__IO_EXTERN __UNION_D(io_pdr6,IO_PDR6)		/* addr 12h */
__IO_EXTERN __UNION_D(io_pdr7,IO_PDR7)		/* addr 13h */
__IO_EXTERN __UNION_D(io_rcr1,IO_RCR1)		/* addr 14h */
__IO_EXTERN __UNION_D(io_rcr2,IO_RCR2)		/* addr 15h */
__IO_STATIC __RESERVE_D(dmy_16_17,2)		/* addr 16-17h */
__IO_EXTERN __UNION_D(io_t2cr,IO_T2CR)		/* addr 18h */
__IO_EXTERN __UNION_D(io_t1cr,IO_T1CR)		/* addr 19h */
__IO_EXTERN __UNION_D(io_t12dr,IO_T12DR)	/* addr 1A-1Bh */
__IO_STATIC __RESERVE_D(dmy_1C_1D,2)		/* addr 1C-1Dh */
__IO_EXTERN __UNION_D(io_cntr,IO_CNTR1)		/* addr 1Eh */
__IO_EXTERN __UCHAR_D(IO_COMR1)			/* addr 1Fh */
__IO_EXTERN __UNION_D(io_cntr,IO_CNTR2)		/* addr 20h */
__IO_EXTERN __UCHAR_D(IO_COMR2)			/* addr 21h */
__IO_STATIC __RESERVE_D(dmy_22_2C,11)		/* addr 22-2Ch */
__IO_EXTERN __UNION_D(io_adc1,IO_ADC1)		/* addr 2Dh */
__IO_EXTERN __UNION_D(io_adc2,IO_ADC2)		/* addr 2Eh */
__IO_EXTERN __UCHAR_D(IO_ADCD)			/* addr 2Fh */
__IO_EXTERN __UNION_D(io_eie1,IO_EIE1)		/* addr 30h */
__IO_EXTERN __UNION_D(io_eif1,IO_EIF1)		/* addr 31h */
__IO_EXTERN __UNION_D(io_eie2,IO_EIE2)		/* addr 32h */
__IO_EXTERN __UNION_D(io_eif2,IO_EIF2)		/* addr 33h */
__IO_STATIC __RESERVE_D(dmy_34_3F,12)		/* addr 34-3Fh */
#if defined(__CPU_MB89P985__) || defined(__CPU_MB89PV980__)
__IO_EXTERN __UNION_D(io_purr0,IO_PURR0)	/* addr 40h */
__IO_EXTERN __UNION_D(io_purr1,IO_PURR1)	/* addr 41h */
__IO_EXTERN __UNION_D(io_purr5,IO_PURR5)	/* addr 42h */
#else
__IO_STATIC __RESERVE_D(dmy_40_42,3)		/* addr 40-42h */
#endif
__IO_STATIC __RESERVE_D(dmy_43_5F,29)		/* addr 43-5Fh */
__IO_EXTERN __UNION_D(io_vram,IO_VRAM)		/* addr 60-66h */
__IO_STATIC __RESERVE_D(dmy_67_71,11)		/* addr 67-71h */
__IO_EXTERN __UNION_D(io_lcr,IO_LCR1)		/* addr 72h */
#if defined(__CPU_MB89P985__) || defined(__CPU_MB89PV980__)
__IO_EXTERN __UNION_D(io_lcr2,IO_LCR2)		/* addr 73h */
#else
__IO_STATIC __RESERVE_D(dmy_73,1)		/* addr 73h */
#endif
__IO_STATIC __RESERVE_D(dmy_74_7B,8)		/* addr 74-7Bh */
__IO_EXTERN __UCHAR_D(IO_ILR1)			/* addr 7Ch */
__IO_EXTERN __UCHAR_D(IO_ILR2)			/* addr 7Dh */
__IO_EXTERN __UCHAR_D(IO_ILR3)			/* addr 7Eh */
__IO_STATIC __RESERVE_D(dmy_7F,1)		/* addr 7Fh */
