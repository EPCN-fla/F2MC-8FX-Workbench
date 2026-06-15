/*
 MB89660/660R Series I/O register declaration file V30L08
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
__IO_STATIC __RESERVE_D(dmy_11,1)		/* addr 11h */
__IO_EXTERN __UNION_D(io_pdr6,IO_PDR6)		/* addr 12h */
__IO_EXTERN __UCHAR_D(IO_DDR6)			/* addr 13h */
__IO_STATIC __RESERVE_D(dmy_14,1)		/* addr 14h */
__IO_EXTERN __UNION_D(io_adc1,IO_ADC1)		/* addr 15h */
__IO_EXTERN __UNION_D(io_adc2,IO_ADC2)		/* addr 16h */
__IO_EXTERN __UCHAR_D(IO_ADCD)			/* addr 17h */
__IO_EXTERN __UNION_D(io_t2cr,IO_T2CR)		/* addr 18h */
__IO_EXTERN __UNION_D(io_t1cr,IO_T1CR)		/* addr 19h */
__IO_EXTERN __UNION_D(io_t12dr,IO_T12DR)	/* addr 1A-1Bh */
__IO_EXTERN __UNION_D(io_cntr,IO_CNTR)		/* addr 1Ch */
__IO_EXTERN __UCHAR_D(IO_COMR)			/* addr 1Dh */
__IO_STATIC __RESERVE_D(dmy_1E_1F,2)		/* addr 1E-1Fh */
__IO_EXTERN __UNION_D(io_smc,IO_SMC)		/* addr 20h */
__IO_EXTERN __UNION_D(io_src,IO_SRC)		/* addr 21h */
__IO_EXTERN __UNION_D(io_ssd,IO_SSD)		/* addr 22h */
__IO_EXTERN __UCHAR_D(IO_SIDR)			/* addr 23h */
__IO_EXTERN __UNION_D(io_smr,IO_SMR)		/* addr 24h */
__IO_EXTERN __UCHAR_D(IO_SDR)			/* addr 25h */
__IO_EXTERN __UNION_D(io_eic1,IO_EIC1)		/* addr 26h */
__IO_EXTERN __UNION_D(io_eic2,IO_EIC2)		/* addr 27h */
__IO_EXTERN __UNION_D(io_tmcr,IO_TMCR)		/* addr 28h */
__IO_EXTERN __USHORT_D(IO_TCR)			/* addr 29-2Ah */
__IO_EXTERN __UNION_D(io_opcr,IO_OPCR)		/* addr 2Bh */
__IO_EXTERN __USHORT_D(IO_CPR0)			/* addr 2C-2Dh */
__IO_EXTERN __USHORT_D(IO_CPR1)			/* addr 2E-2Fh */
__IO_EXTERN __UNION_D(io_iccr,IO_ICCR)		/* addr 30h */
__IO_EXTERN __UNION_D(io_icic,IO_ICIC)		/* addr 31h */
__IO_EXTERN __USHORT_D(IO_ICR0)			/* addr 32-33h */
__IO_EXTERN __USHORT_D(IO_ICR1)			/* addr 34-35h */
__IO_STATIC __RESERVE_D(dmy_36_7B,70)		/* addr 36-7Bh */
__IO_EXTERN __UCHAR_D(IO_ILR1)			/* addr 7Ch */
__IO_EXTERN __UCHAR_D(IO_ILR2)			/* addr 7Dh */
__IO_EXTERN __UCHAR_D(IO_ILR3)			/* addr 7Eh */
__IO_STATIC __RESERVE_D(dmy_7F,1)		/* addr 7Fh */
