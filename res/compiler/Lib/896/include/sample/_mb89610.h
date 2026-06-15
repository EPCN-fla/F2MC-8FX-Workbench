/*
 MB89610/610R Series I/O register declaration file V30L08
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
__IO_STATIC __RESERVE_D(dmy_06_07,2)		/* addr 06-07h */
__IO_EXTERN __UNION_D(io_stbc,IO_STBC)		/* addr 08h */
__IO_EXTERN __UCHAR_D(IO_WDTC)			/* addr 09h */
__IO_EXTERN __UNION_D(io_tbtc,IO_TBTC)		/* addr 0Ah */
__IO_STATIC __RESERVE_D(dmy_0B,1)		/* addr 0Bh */
__IO_EXTERN __UNION_D(io_pdr3,IO_PDR3)		/* addr 0Ch */
__IO_EXTERN __UCHAR_D(IO_DDR3)			/* addr 0Dh */
__IO_EXTERN __UNION_D(io_pdr4,IO_PDR4)		/* addr 0Eh */
__IO_EXTERN __UNION_D(io_bzcr,IO_BZCR)		/* addr 0Fh */
__IO_EXTERN __UNION_D(io_pdr5,IO_PDR5)		/* addr 10h */
__IO_EXTERN __CONST __UNION_D(io_pdr6,IO_PDR6)	/* addr 11h */
__IO_EXTERN __UNION_D(io_cntr,IO_CNTR)		/* addr 12h */
__IO_EXTERN __UCHAR_D(IO_COMR)			/* addr 13h */
__IO_EXTERN __UNION_D(io_pcr1,IO_PCR1)		/* addr 14h */
__IO_EXTERN __UNION_D(io_pcr2,IO_PCR2)		/* addr 15h */
__IO_EXTERN __UCHAR_D(IO_RLBR)			/* addr 16h */
__IO_STATIC __RESERVE_D(dmy_17,1)		/* addr 17h */
__IO_EXTERN __UNION_D(io_tmcr,IO_TMCR)		/* addr 18h */
__IO_EXTERN __USHORT_D(IO_TCR)			/* addr 19-1Ah */
__IO_STATIC __RESERVE_D(dmy_1B,1)		/* addr 1Bh */
__IO_EXTERN __UNION_D(io_smr,IO_SMR1)		/* addr 1Ch */
__IO_EXTERN __UCHAR_D(IO_SDR1)			/* addr 1Dh */
__IO_EXTERN __UNION_D(io_smr,IO_SMR2)		/* addr 1Eh */
__IO_EXTERN __UCHAR_D(IO_SDR2)			/* addr 1Fh */
__IO_STATIC __RESERVE_D(dmy_20_23,4)		/* addr 20-23h */
__IO_EXTERN __UNION_D(io_eic1,IO_EIC1)		/* addr 24h */
__IO_EXTERN __UNION_D(io_eic2,IO_EIC2)		/* addr 25h */
__IO_STATIC __RESERVE_D(dmy_26_7B,86)		/* addr 26-7Bh */
__IO_EXTERN __UCHAR_D(IO_ILR1)			/* addr 7Ch */
__IO_EXTERN __UCHAR_D(IO_ILR2)			/* addr 7Dh */
__IO_EXTERN __UCHAR_D(IO_ILR3)			/* addr 7Eh */
__IO_STATIC __RESERVE_D(dmy_7F,1)		/* addr 7Fh */
