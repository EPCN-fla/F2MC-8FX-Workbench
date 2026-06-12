/*
 MB89830 Series I/O register declaration file V30L08
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
__IO_EXTERN __UNION_D(io_pdr2,IO_PDR2)		/* addr 04h */
__IO_STATIC __RESERVE_D(dmy_05_07,3)		/* addr 05-07h */
__IO_EXTERN __UNION_D(io_stbc,IO_STBC)		/* addr 08h */
__IO_EXTERN __UCHAR_D(IO_WDTC)			/* addr 09h */
__IO_EXTERN __UNION_D(io_tbtc,IO_TBTC)		/* addr 0Ah */
__IO_STATIC __RESERVE_D(dmy_0B,1)		/* addr 0Bh */
__IO_EXTERN __UNION_D(io_pdr3,IO_PDR3)		/* addr 0Ch */
__IO_EXTERN __UCHAR_D(IO_DDR3)			/* addr 0Dh */
__IO_EXTERN __UNION_D(io_pdr4,IO_PDR4)		/* addr 0Eh */
__IO_EXTERN __UCHAR_D(IO_DDR4)			/* addr 0Fh */
__IO_EXTERN __UNION_D(io_pdr5,IO_PDR5)		/* addr 10h */
__IO_EXTERN __UCHAR_D(IO_DDR5)			/* addr 11h */
__IO_EXTERN __UNION_D(io_pdr6,IO_PDR6)		/* addr 12h */
__IO_STATIC __RESERVE_D(dmy_13,1)		/* addr 13h */
__IO_EXTERN __UNION_D(io_cntr,IO_CNTR)		/* addr 14h */
__IO_EXTERN __UCHAR_D(IO_COMR)			/* addr 15h */
__IO_EXTERN __UNION_D(io_tmcr,IO_TMCR)		/* addr 16h */
__IO_EXTERN __USHORT_D(IO_TCR)			/* addr 17-18h */
__IO_EXTERN __UNION_D(io_smr,IO_SMR)		/* addr 19h */
__IO_EXTERN __UCHAR_D(IO_SDR)			/* addr 1Ah */
__IO_EXTERN __UNION_D(io_bzcr,IO_BZCR)		/* addr 1Bh */
__IO_EXTERN __UCHAR_D(IO_BZFR)			/* addr 1Ch */
__IO_EXTERN __UNION_D(io_eic1,IO_EIC)		/* addr 1Dh */
__IO_STATIC __RESERVE_D(dmy_1E_1F,2)		/* addr 1E-1Fh */
__IO_EXTERN __UNION_D(io_mcnt,IO_MCNT)		/* addr 20h */
__IO_EXTERN __UNION_D(io_intstr,IO_INTSTR)	/* addr 21h */
__IO_EXTERN __USHORT_D(IO_CMCLBR)		/* addr 22-23h */
__IO_EXTERN __USHORT_D(IO_OUTCBR)		/* addr 24-25h */
__IO_EXTERN __UNION_D(io_adc1,IO_ADC1)		/* addr 26h */
__IO_EXTERN __UNION_D(io_adc2,IO_ADC2)		/* addr 27h */
__IO_EXTERN __UNION_D(io_adc3,IO_ADC3)		/* addr 28h */
__IO_EXTERN __UNION_D(io_add,IO_ADD0)		/* addr 29-2Ah */
__IO_EXTERN __UNION_D(io_add,IO_ADD1)		/* addr 2B-2Ch */
__IO_EXTERN __UNION_D(io_add,IO_ADD2)		/* addr 2D-2Eh */
__IO_EXTERN __UNION_D(io_add,IO_ADD3)		/* addr 2F-30h */
__IO_EXTERN __UNION_D(io_add,IO_ADD4)		/* addr 31-32h */
__IO_EXTERN __UNION_D(io_add,IO_ADD5)		/* addr 33-34h */
__IO_EXTERN __UNION_D(io_add,IO_ADD6)		/* addr 35-36h */
__IO_EXTERN __UNION_D(io_add,IO_ADD7)		/* addr 37-38h */
__IO_STATIC __RESERVE_D(dmy_39_3C,4)		/* addr 39-3Ch */
__IO_EXTERN __UNION_D(io_scr ,IO_SCR)		/* addr 3Dh */
__IO_EXTERN __UNION_D(io_scmr,IO_SCMR)		/* addr 3Eh */
__IO_EXTERN __UNION_D(io_scbr,IO_SCBR)		/* addr 3Fh */
__IO_EXTERN __UCHAR_AD(IO_SDRAM,32)		/* addr 40-5Fh */
__IO_STATIC __RESERVE_D(dmy_60_7B,28)		/* addr 60-7Bh */
__IO_EXTERN __UCHAR_D(IO_ILR1)			/* addr 7Ch */
__IO_EXTERN __UCHAR_D(IO_ILR2)			/* addr 7Dh */
__IO_EXTERN __UCHAR_D(IO_ILR3)			/* addr 7Eh */
__IO_STATIC __RESERVE_D(dmy_7F,1)		/* addr 7Fh */
