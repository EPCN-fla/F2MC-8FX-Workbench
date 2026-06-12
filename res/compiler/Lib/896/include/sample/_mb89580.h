/*
 MB89580 Series I/O register declaration file V30L08
 ALL RIGHTS RESERVED, COPYRIGHT (C) FUJITSU LIMITED 1998
 LICENSED MATERIAL - PROGRAM PROPERTY OF FUJITSU LIMITED
*/
#ifdef __FASM__
#include "_mb895xx_a.h"
#else
#include "_mb895xx.h"
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
__IO_STATIC __RESERVE_D(dmy_05_06,2)		/* addr 05-06h */
__IO_EXTERN __UNION_D(io_sycc,IO_SYCC)		/* addr 07h */
__IO_EXTERN __UNION_D(io_stbc,IO_STBC)		/* addr 08h */
__IO_EXTERN __UCHAR_D(IO_WDTC)			/* addr 09h */
__IO_EXTERN __UNION_D(io_tbtc,IO_TBTC)		/* addr 0Ah */
__IO_STATIC __RESERVE_D(dmy_0B,1)		/* addr 0Bh */
__IO_EXTERN __UNION_D(io_pdr3,IO_PDR3)		/* addr 0Ch */
__IO_EXTERN __UNION_D(io_pdr3,IO_DDR3)		/* addr 0Dh */
__IO_STATIC __RESERVE_D(dmy_0E_0F,2)		/* addr 0E-0Fh */
__IO_EXTERN __UNION_D(io_pdr4,IO_PDR4)		/* addr 10h */
__IO_EXTERN __UNION_D(io_ddr4,IO_DDR4)		/* addr 11h */
__IO_EXTERN __UNION_D(io_pdr5,IO_PDR5)		/* addr 12h */
__IO_EXTERN __UNION_D(io_ddr5,IO_DDR5)		/* addr 13h */
__IO_EXTERN __UNION_D(io_pdr6,IO_PDR6)		/* addr 14h */
__IO_EXTERN __UNION_D(io_pdcr,IO_PDCR)		/* addr 15h */
__IO_STATIC __RESERVE_D(dmy_16_20,11)		/* addr 16-20h */
__IO_EXTERN __UNION_D(io_purr0,IO_PURR0)	/* addr 21h */
__IO_EXTERN __UNION_D(io_purr1,IO_PURR1)	/* addr 22h */
__IO_EXTERN __UNION_D(io_purr2,IO_PURR2)	/* addr 23h */
__IO_EXTERN __UNION_D(io_purr3,IO_PURR3)	/* addr 24h */
__IO_EXTERN __UNION_D(io_purr4,IO_PURR4)	/* addr 25h */
__IO_EXTERN __UNION_D(io_purr5,IO_PURR5)	/* addr 26h */
__IO_EXTERN __UNION_D(io_cntr1,IO_CNTR1)	/* addr 27h */
__IO_EXTERN __UNION_D(io_cntr2,IO_CNTR2)	/* addr 28h */
__IO_EXTERN __UNION_D(io_cntr3,IO_CNTR3)	/* addr 29h */
__IO_EXTERN __UCHAR_D(IO_COMR1)			/* addr 2Ah */
__IO_EXTERN __UCHAR_D(IO_COMR2)			/* addr 2Bh */
__IO_EXTERN __UNION_D(io_ckr,IO_CKR)		/* addr 2Ch */
__IO_EXTERN __UNION_D(io_scs,IO_SCS)		/* addr 2Dh */
__IO_STATIC __RESERVE_D(dmy_2E,1)		/* addr 2Eh */
__IO_EXTERN __UNION_D(io_smc21,IO_SMC21)	/* addr 2Fh */
__IO_EXTERN __UNION_D(io_smc22,IO_SMC22)	/* addr 30h */
__IO_EXTERN __UNION_D(io_ssd2,IO_SSD2)		/* addr 31h */
__IO_EXTERN __UCHAR_D(IO_SIDR2)			/* addr 32h */
__IO_EXTERN __UCHAR_D(IO_SRC2)			/* addr 33h */
__IO_STATIC __RESERVE_D(dmy_34_3B,8)		/* addr 34-3Bh */
__IO_EXTERN __UNION_D(io_eie2,IO_EIE2)		/* addr 3Ch */
__IO_EXTERN __UNION_D(io_eif2,IO_EIF2)		/* addr 3Dh */
__IO_STATIC __RESERVE_D(dmy_3E_4F,18)		/* addr 3E-4Fh */
__IO_EXTERN __UNION_D(io_umdr,IO_UMDR)		/* addr 50h */
__IO_EXTERN __UNION_D(io_dbar,IO_DBAR)		/* addr 51h */
__IO_EXTERN __UCHAR_D(IO_TDCR0)			/* addr 52h */
__IO_EXTERN __UCHAR_D(IO_TDCR11)		/* addr 53h */
__IO_EXTERN __UCHAR_D(IO_TDCR12)		/* addr 54h */
__IO_EXTERN __UCHAR_D(IO_TDCR21)		/* addr 55h */
__IO_EXTERN __UCHAR_D(IO_TDCR22)		/* addr 56h */
__IO_EXTERN __UCHAR_D(IO_TDCR3)			/* addr 57h */
__IO_EXTERN __UNION_D(io_uctr,IO_UCTR)		/* addr 58h */
__IO_EXTERN __UNION_D(io_ustr1,IO_USTR1)	/* addr 59h */
__IO_EXTERN __UNION_D(io_ustr2,IO_USTR2)	/* addr 5Ah */
__IO_EXTERN __UNION_D(io_umskr,IO_UMSKR)	/* addr 5Bh */
__IO_EXTERN __UCHAR_D(IO_UFRMR1)		/* addr 5Ch */
__IO_EXTERN __UCHAR_D(IO_UFRMR2)		/* addr 5Dh */
__IO_EXTERN __UNION_D(io_eper,IO_EPER)		/* addr 5Eh */
__IO_EXTERN __UNION_D(io_epbr0,IO_EPBR0)	/* addr 5Fh */
__IO_EXTERN __UNION_D(io_epbrm,IO_EPBR1)	/* addr 60-61h */
__IO_EXTERN __UNION_D(io_epbrm,IO_EPBR2)	/* addr 62-63h */
__IO_EXTERN __UNION_D(io_epbrn,IO_EPBR3)	/* addr 64-65h */
__IO_STATIC __RESERVE_D(dmy_66_7B,22)		/* addr 66-7Bh */
__IO_EXTERN __UCHAR_D(IO_ILR1)			/* addr 7Ch */
__IO_EXTERN __UCHAR_D(IO_ILR2)			/* addr 7Dh */
__IO_EXTERN __UCHAR_D(IO_ILR3)			/* addr 7Eh */
__IO_STATIC __RESERVE_D(dmy_7F,1)		/* addr 7Fh */
