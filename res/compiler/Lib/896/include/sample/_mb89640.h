/*
 MB89640 Series I/O register declaration file V30L08
 ALL RIGHTS RESERVED, COPYRIGHT (C) FUJITSU LIMITED 1998
 LICENSED MATERIAL - PROGRAM PROPERTY OF FUJITSU LIMITED
*/
#ifdef __FASM__
#include "_mb896xx_a.h"
#else
#include "_mb896xx.h"
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
__IO_EXTERN __UCHAR_D(IO_BCTR)			/* addr 05h */
__IO_STATIC __RESERVE_D(dmy_06,1)		/* addr 06h */
__IO_EXTERN __UNION_D(io_sycc,IO_SYCC)		/* addr 07h */
__IO_EXTERN __UNION_D(io_stbc,IO_STBC)		/* addr 08h */
__IO_EXTERN __UCHAR_D(IO_WDTC)			/* addr 09h */
__IO_EXTERN __UNION_D(io_tbtc,IO_TBTC)		/* addr 0Ah */
__IO_EXTERN __UNION_D(io_wpcr,IO_WPCR)		/* addr 0Bh */
__IO_EXTERN __UNION_D(io_pdr3,IO_PDR3)		/* addr 0Ch */
__IO_EXTERN __UCHAR_D(IO_DDR3)			/* addr 0Dh */
__IO_EXTERN __UNION_D(io_pdr4,IO_PDR4)		/* addr 0Eh */
__IO_EXTERN __UNION_D(io_bzcr,IO_BZCR)		/* addr 0Fh */
__IO_EXTERN __UNION_D(io_pdr5,IO_PDR5)		/* addr 10h */
__IO_EXTERN __UNION_D(io_pdr6,IO_PDR6)		/* addr 11h */
__IO_EXTERN __CONST __UNION_D(io_pdr7,IO_PDR7)	/* addr 12h */
__IO_EXTERN __CONST __UNION_D(io_pdr8,IO_PDR8)	/* addr 13h */
__IO_STATIC __RESERVE_D(dmy_14_17,4)		/* addr 14-17h */
__IO_EXTERN __UNION_D(io_tmcr,IO_TMCR)		/* addr 18h */
__IO_EXTERN __USHORT_D(IO_TCR)			/* addr 19-1Ah */
__IO_STATIC __RESERVE_D(dmy_1B,1)		/* addr 1Bh */
__IO_EXTERN __UNION_D(io_smr,IO_SMR1)		/* addr 1Ch */
__IO_EXTERN __UCHAR_D(IO_SDR1)			/* addr 1Dh */
__IO_EXTERN __UNION_D(io_smr,IO_SMR2)		/* addr 1Eh */
__IO_EXTERN __UCHAR_D(IO_SDR2)			/* addr 1Fh */
__IO_EXTERN __UNION_D(io_adc1,IO_ADC1)		/* addr 20h */
__IO_EXTERN __UNION_D(io_adc2,IO_ADC2)		/* addr 21h */
__IO_EXTERN __UCHAR_D(IO_ADCD)			/* addr 22h */
__IO_STATIC __RESERVE_D(dmy_23,1)		/* addr 23h */
__IO_EXTERN __UNION_D(io_dacr,IO_DACR)		/* addr 24h */
__IO_EXTERN __UCHAR_D(IO_DADR1)			/* addr 25h */
__IO_EXTERN __UCHAR_D(IO_DADR2)			/* addr 26h */
__IO_STATIC __RESERVE_D(dmy_27,1)		/* addr 27h */
__IO_EXTERN __UNION_D(io_cntr1,IO_CNTR1)	/* addr 28h */
__IO_EXTERN __UNION_D(io_cntr2,IO_CNTR2)	/* addr 29h */
__IO_EXTERN __UNION_D(io_cntr3,IO_CNTR3)	/* addr 2Ah */
__IO_EXTERN __UCHAR_D(IO_COMR1)			/* addr 2Bh */
__IO_EXTERN __UCHAR_D(IO_COMR2)			/* addr 2Ch */
__IO_EXTERN __UNION_D(io_pcr1,IO_PCR1)		/* addr 2Dh */
__IO_EXTERN __UNION_D(io_pcr2,IO_PCR2)		/* addr 2Eh */
__IO_EXTERN __UCHAR_D(IO_RLBR)			/* addr 2Fh */
__IO_STATIC __RESERVE_D(dmy_30,1)		/* addr 30h */
__IO_EXTERN __UNION_D(io_eic1,IO_EIC1)		/* addr 31h */
__IO_EXTERN __UNION_D(io_eic2,IO_EIC2)		/* addr 32h */
__IO_EXTERN __UNION_D(io_eie2,IO_EIE2)		/* addr 33h */
__IO_EXTERN __UNION_D(io_eif2,IO_EIF2)		/* addr 34h */
__IO_STATIC __RESERVE_D(dmy_35_7B,71)		/* addr 35-7Bh */
__IO_EXTERN __UCHAR_D(IO_ILR1)			/* addr 7Ch */
__IO_EXTERN __UCHAR_D(IO_ILR2)			/* addr 7Dh */
__IO_EXTERN __UCHAR_D(IO_ILR3)			/* addr 7Eh */
__IO_STATIC __RESERVE_D(dmy_7F,1)		/* addr 7Fh */
