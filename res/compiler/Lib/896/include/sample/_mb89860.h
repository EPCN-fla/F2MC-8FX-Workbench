/*
 MB89860 Series I/O register declaration file V30L08
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
__IO_EXTERN __UCHAR_D(IO_BCTR)			/* addr 05h */
__IO_STATIC __RESERVE_D(dmy_06_07,2)		/* addr 06-07h */
__IO_EXTERN __UNION_D(io_stbc,IO_STBC)		/* addr 08h */
__IO_EXTERN __UCHAR_D(IO_WDTC)			/* addr 09h */
__IO_EXTERN __UNION_D(io_tbtc,IO_TBTC)		/* addr 0Ah */
__IO_STATIC __RESERVE_D(dmy_0B,1)		/* addr 0Bh */
__IO_EXTERN __UNION_D(io_pdr3,IO_PDR3)		/* addr 0Ch */
__IO_EXTERN __UCHAR_D(IO_DDR3)			/* addr 0Dh */
__IO_EXTERN __UNION_D(io_pdr4,IO_PDR4)		/* addr 0Eh */
__IO_EXTERN __UCHAR_D(IO_DDR4)			/* addr 0Fh */
__IO_EXTERN __UNION_D(io_pdr5,IO_PDR5)		/* addr 10h */
__IO_STATIC __RESERVE_D(dmy_11,1)		/* addr 11h */
__IO_EXTERN __CONST __UNION_D(io_pdr6,IO_PDR6)	/* addr 12h */
__IO_STATIC __RESERVE_D(dmy_13,1)		/* addr 13h */
__IO_EXTERN __UNION_D(io_pdr7,IO_PDR7)		/* addr 14h */
__IO_STATIC __RESERVE_D(dmy_15,1)		/* addr 15h */
__IO_EXTERN __UNION_D(io_pdr8,IO_PDR8)		/* addr 16h */
__IO_STATIC __RESERVE_D(dmy_17_1B,5)		/* addr 17-1Bh */
__IO_EXTERN __UNION_D(io_cntr,IO_CNTR1)		/* addr 1Ch */
__IO_EXTERN __UCHAR_D(IO_COMR1)			/* addr 1Dh */
__IO_EXTERN __UNION_D(io_cntr,IO_CNTR2)		/* addr 1Eh */
__IO_EXTERN __UCHAR_D(IO_COMR2)			/* addr 1Fh */
__IO_EXTERN __UNION_D(io_smc,IO_SMC)		/* addr 20h */
__IO_EXTERN __UNION_D(io_src,IO_SRC)		/* addr 21h */
__IO_EXTERN __UNION_D(io_ssd,IO_SSD)		/* addr 22h */
__IO_EXTERN __UCHAR_D(IO_SIDR)			/* addr 23h */
__IO_EXTERN __UNION_D(io_smr,IO_SMR)		/* addr 24h */
__IO_EXTERN __UCHAR_D(IO_SDR)			/* addr 25h */
__IO_EXTERN __UNION_D(io_eic1,IO_EIC1)		/* addr 26h */
__IO_EXTERN __UNION_D(io_eic2,IO_EIC2)		/* addr 27h */
__IO_EXTERN __UNION_D(io_adc1,IO_ADC1)		/* addr 28h */
__IO_EXTERN __UNION_D(io_adc2,IO_ADC2)		/* addr 29h */
__IO_EXTERN __UNION_D(io_add ,IO_ADD)		/* addr 2A-2Bh */
__IO_STATIC __RESERVE_D(dmy_2C,1)		/* addr 2Ch */
__IO_EXTERN __UCHAR_D(IO_ZOCTR)			/* addr 2Dh */
__IO_EXTERN __USHORT_D(IO_CLRBR)		/* addr 2E-2Fh */
__IO_EXTERN __UNION_D(io_tcsr,IO_TCSR)		/* addr 30h */
__IO_EXTERN __UNION_D(io_cicr,IO_CICR)		/* addr 31h */
__IO_EXTERN __UNION_D(io_tmcr,IO_TMCR)		/* addr 32h */
__IO_EXTERN __UNION_D(io_coer,IO_COER)		/* addr 33h */
__IO_EXTERN __UNION_D(io_cmcr,IO_CMCR)		/* addr 34h */
__IO_EXTERN __UNION_D(io_dtcr,IO_DTCR)		/* addr 35h */
__IO_EXTERN __UCHAR_D(IO_DTSR)			/* addr 36h */
__IO_EXTERN __UNION_D(io_octbr,IO_OCTBR)	/* addr 37h */
__IO_EXTERN __USHORT_D(IO_OCPBR0)		/* addr 38-39h */
__IO_EXTERN __USHORT_D(IO_OCPBR1)		/* addr 3A-3Bh */
__IO_EXTERN __USHORT_D(IO_OCPBR2)		/* addr 3C-3Dh */
__IO_EXTERN __USHORT_D(IO_OCPBR3)		/* addr 3E-3Fh */
__IO_STATIC __RESERVE_D(dmy_40_7B,60)		/* addr 40-7Bh */
__IO_EXTERN __UCHAR_D(IO_ILR1)			/* addr 7Ch */
__IO_EXTERN __UCHAR_D(IO_ILR2)			/* addr 7Dh */
__IO_EXTERN __UCHAR_D(IO_ILR3)			/* addr 7Eh */
__IO_STATIC __RESERVE_D(dmy_7F,1)		/* addr 7Fh */
