/*
 MB89800 Series I/O register declaration file V30L08
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
__IO_STATIC __RESERVE_D(dmy_01,1)		/* addr 01h */
__IO_EXTERN __UNION_D(io_pdr1,IO_PDR1)		/* addr 02h */
__IO_STATIC __RESERVE_D(dmy_03,1)		/* addr 03h */
__IO_EXTERN __UNION_D(io_pdr2,IO_PDR2)		/* addr 04h */
__IO_STATIC __RESERVE_D(dmy_05_06,2)		/* addr 05-06h */
__IO_EXTERN __UNION_D(io_sycc,IO_SYCC)		/* addr 07h */
__IO_EXTERN __UNION_D(io_stbc,IO_STBC)		/* addr 08h */
__IO_EXTERN __UCHAR_D(IO_WDTC)			/* addr 09h */
__IO_EXTERN __UNION_D(io_tbtc,IO_TBTC)		/* addr 0Ah */
__IO_STATIC __RESERVE_D(dmy_0B,1)		/* addr 0Bh */
__IO_EXTERN __CONST __UNION_D(io_pdr3,IO_PDR3)	/* addr 0Ch */
__IO_STATIC __RESERVE_D(dmy_0D,1)		/* addr 0Dh */
__IO_EXTERN __UNION_D(io_pdr4,IO_PDR4)		/* addr 0Eh */
__IO_EXTERN __UCHAR_D(IO_DDR4)			/* addr 0Fh */
__IO_STATIC __RESERVE_D(dmy_10_11,2)		/* addr 10-11h */
__IO_EXTERN __UNION_D(io_cntr,IO_CNTR)		/* addr 12h */
__IO_EXTERN __UCHAR_D(IO_COMR)			/* addr 13h */
__IO_EXTERN __UNION_D(io_pcr1,IO_PCR1)		/* addr 14h */
__IO_EXTERN __UNION_D(io_pcr2,IO_PCR2)		/* addr 15h */
__IO_EXTERN __UCHAR_D(IO_RLBR)			/* addr 16h */
__IO_EXTERN __UNION_D(io_nccr,IO_NCCR)		/* addr 17h */
__IO_STATIC __RESERVE_D(dmy_18_1B,4)		/* addr 18-1Bh */
__IO_EXTERN __UNION_D(io_smr ,IO_SMR)		/* addr 1Ch */
__IO_EXTERN __UCHAR_D(IO_SDR)			/* addr 1Dh */
__IO_STATIC __RESERVE_D(dmy_1E_1F,2)		/* addr 1E-1Fh */
__IO_EXTERN __UNION_D(io_smc,IO_SMC1)		/* addr 20h */
__IO_EXTERN __UNION_D(io_src,IO_SRC)		/* addr 21h */
__IO_EXTERN __UNION_D(io_ssd,IO_SSD)		/* addr 22h */
__IO_EXTERN __UCHAR_D(IO_SIDR)			/* addr 23h */
__IO_EXTERN __UNION_D(io_smc2,IO_SMC2)		/* addr 24h */
__IO_STATIC __RESERVE_D(dmy_25_2F,11)		/* addr 25-2Fh */
__IO_EXTERN __UNION_D(io_eic1,IO_EIC)		/* addr 30h */
__IO_STATIC __RESERVE_D(dmy_31_4F,31)		/* addr 31-4Fh */
__IO_EXTERN __UNION_D(io_vram,IO_VRAM)		/* addr 60-72h */
__IO_STATIC __RESERVE_D(dmy_73_78,6)		/* addr 73-78h */
__IO_EXTERN __UNION_D(io_lcr ,IO_LCR1)		/* addr 79h */
__IO_EXTERN __UNION_D(io_segr,IO_SEGR)		/* addr 7Ah */
__IO_STATIC __RESERVE_D(dmy_7B,1)		/* addr 7Bh */
__IO_EXTERN __UCHAR_D(IO_ILR1)			/* addr 7Ch */
__IO_EXTERN __UCHAR_D(IO_ILR2)			/* addr 7Dh */
__IO_EXTERN __UCHAR_D(IO_ILR3)			/* addr 7Eh */
__IO_STATIC __RESERVE_D(dmy_7F,1)		/* addr 7Fh */
