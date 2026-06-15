/*
 MB89880 Series I/O register declaration file V30L08
 ALL RIGHTS RESERVED, COPYRIGHT (C) FUJITSU LIMITED 1998
 LICENSED MATERIAL - PROGRAM PROPERTY OF FUJITSU LIMITED
*/
#ifdef __FASM__
#include "_mb898xx_a.h"
#else
#include "_mb898xx.h"
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
__IO_EXTERN __UNION_D(io_pdr3,IO_PDR3)		/* addr 04h */
__IO_STATIC __RESERVE_D(dmy_05_07,3)		/* addr 05-07h */
__IO_EXTERN __UNION_D(io_stbc,IO_STBC)		/* addr 08h */
__IO_EXTERN __UCHAR_D(IO_WDTC)			/* addr 09h */
__IO_EXTERN __UNION_D(io_tbtc,IO_TBTC)		/* addr 0Ah */
__IO_EXTERN __UCHAR_D(IO_DDR3)			/* addr 0Bh */
__IO_EXTERN __UNION_D(io_pdr2,IO_PDR2)		/* addr 0Ch */
__IO_EXTERN __UCHAR_D(IO_DDR2)			/* addr 0Dh */
__IO_EXTERN __UNION_D(io_pdr4,IO_PDR4)		/* addr 0Eh */
__IO_EXTERN __UCHAR_D(IO_DDR4)			/* addr 0Fh */
__IO_EXTERN __UNION_D(io_pdr5,IO_PDR5)		/* addr 10h */
__IO_EXTERN __UCHAR_D(IO_DDR5)			/* addr 11h */
__IO_EXTERN __UNION_D(io_pdr6,IO_PDR6)		/* addr 12h */
__IO_STATIC __RESERVE_D(dmy_13_14,2)		/* addr 13-14h */
__IO_EXTERN __UNION_D(io_tmcr,IO_TMCR)		/* addr 15h */
__IO_EXTERN __USHORT_D(IO_TCR)			/* addr 16-17h */
__IO_STATIC __RESERVE_D(dmy_18,1)		/* addr 18h */
__IO_EXTERN __UNION_D(io_cntr0,IO_CNTR0)	/* addr 19h */
__IO_EXTERN __UNION_D(io_cntr1,IO_CNTR1)	/* addr 1Ah */
__IO_EXTERN __UNION_D(io_cntr2,IO_CNTR2)	/* addr 1Bh */
__IO_EXTERN __UNION_D(io_cntr3,IO_CNTR3)	/* addr 1Ch */
__IO_EXTERN __UCHAR_D(IO_COMR0)			/* addr 1Dh */
__IO_EXTERN __UCHAR_D(IO_COMR1)			/* addr 1Eh */
__IO_EXTERN __UCHAR_D(IO_COMR2)			/* addr 1Fh */
__IO_EXTERN __UNION_D(io_smr,IO_SMR)		/* addr 20h */
__IO_EXTERN __UCHAR_D(IO_SDR)			/* addr 21h */
__IO_EXTERN __UNION_D(io_eic1,IO_EIC)		/* addr 22h */
__IO_STATIC __RESERVE_D(dmy_23,1)		/* addr 23h */
__IO_EXTERN __UNION_D(io_adc1,IO_ADC1)		/* addr 24h */
__IO_EXTERN __UNION_D(io_adc2,IO_ADC2)		/* addr 25h */
__IO_EXTERN __UNION_D(io_add,IO_ADD)		/* addr 26-27h */
__IO_STATIC __RESERVE_D(dmy_28_2F,8)		/* addr 28-2Fh */
__IO_EXTERN __UNION_D(io_icsr,IO_ICSR)		/* addr 30h */
__IO_EXTERN __UNION_D(io_icic,IO_ICIC)		/* addr 31h */
__IO_EXTERN __UNION_D(io_icis,IO_ICIS)		/* addr 32h */
__IO_EXTERN __CONST __USHORT_D(IO_ICR0)		/* addr 33-34h */
__IO_EXTERN __CONST __USHORT_D(IO_ICR1)		/* addr 35-36h */
__IO_EXTERN __CONST __USHORT_D(IO_ICR2)		/* addr 37-38h */
__IO_EXTERN __CONST __USHORT_D(IO_FTMR)		/* addr 39-3Ah */
__IO_EXTERN __UCHAR_D(IO_BRDR)			/* addr 3Bh */
__IO_EXTERN __UNION_D(io_usmr,IO_USMR)		/* addr 3Ch */
__IO_EXTERN __UNION_D(io_uscr,IO_USCR)		/* addr 3Dh */
__IO_EXTERN __UNION_D(io_ustr,IO_USTR)		/* addr 3Eh */
__IO_EXTERN __UCHAR_D(IO_URXD)			/* addr 3Fh */
__IO_EXTERN __UCHAR_D(IO_TXDR)			/* addr 40h */
__IO_EXTERN __UCHAR_D(IO_RXDR)			/* addr 41h */
__IO_EXTERN __UCHAR_D(IO_AKR)			/* addr 42h */
__IO_EXTERN __UNION_D(io_ccr,IO_CCR)		/* addr 43h */
__IO_EXTERN __UNION_D(io_str1,IO_STR1)		/* addr 44h */
__IO_EXTERN __UNION_D(io_str2,IO_STR2)		/* addr 45h */
__IO_EXTERN __UNION_D(io_mdr ,IO_MDR)		/* addr 46h */
__IO_EXTERN __CONST __UCHAR_D(IO_MLC)		/* addr 47h */
__IO_STATIC __RESERVE_D(dmy_48_7B,52)		/* addr 48-7Bh */
__IO_EXTERN __UCHAR_D(IO_ILR1)			/* addr 7Ch */
__IO_EXTERN __UCHAR_D(IO_ILR2)			/* addr 7Dh */
__IO_EXTERN __UCHAR_D(IO_ILR3)			/* addr 7Eh */
__IO_STATIC __RESERVE_D(dmy_7F,1)		/* addr 7Fh */
