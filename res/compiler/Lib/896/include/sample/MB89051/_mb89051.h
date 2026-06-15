/*
 MB89051 Series I/O register declaration file V30L02
 ALL RIGHTS RESERVED, COPYRIGHT (C) FUJITSU LIMITED 2002
 LICENSED MATERIAL - PROGRAM PROPERTY OF FUJITSU LIMITED
*/
#ifdef __FASM__
#include "_ra89051.h"
#else
#include "_r89051.h"
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
__IO_EXTERN __UNION_D(io_pdr0,IO_DDR0)		/* addr 01h */
__IO_EXTERN __UNION_D(io_pdr1,IO_PDR1)		/* addr 02h */
__IO_EXTERN __UNION_D(io_pdr1,IO_DDR1)		/* addr 03h */
__IO_EXTERN __UNION_D(io_pdr2,IO_PDR2)		/* addr 04h */
__IO_STATIC __RESERVE_D(dmy_05,1)		/* addr 05h */
__IO_EXTERN __UNION_D(io_pdr2,IO_DDR2)		/* addr 06h */
__IO_EXTERN __UNION_D(io_sycc,IO_SYCC)		/* addr 07h */
__IO_EXTERN __UNION_D(io_stbc,IO_STBC)		/* addr 08h */
__IO_EXTERN __UCHAR_D(IO_WDTC)			/* addr 09h */
__IO_EXTERN __UNION_D(io_tbtc,IO_TBTC)		/* addr 0Ah */
__IO_STATIC __RESERVE_D(dmy_0B,1)		/* addr 0Bh */
__IO_EXTERN __UNION_D(io_pdr3,IO_PDR3)		/* addr 0Ch */
__IO_EXTERN __UNION_D(io_pdr3,IO_DDR3)		/* addr 0Dh */
__IO_STATIC __RESERVE_D(dmy_0E_0F,2)		/* addr 0E-0Fh */
__IO_EXTERN __UNION_D(io_pdr4,IO_PDR4)		/* addr 10h */
__IO_EXTERN __UNION_D(io_pdr4,IO_DDR4)		/* addr 11h */
__IO_EXTERN __UNION_D(io_pdr5,IO_PDR5)		/* addr 12h */
__IO_STATIC __RESERVE_D(dmy_13_20,14)		/* addr 13-20h */
__IO_EXTERN __UNION_D(io_purr0,IO_PURR0)	/* addr 21h */
__IO_EXTERN __UNION_D(io_purr1,IO_PURR1)	/* addr 22h */
__IO_EXTERN __UNION_D(io_purr2,IO_PURR2)	/* addr 23h */
__IO_EXTERN __UNION_D(io_purr3,IO_PURR3)	/* addr 24h */
__IO_EXTERN __UNION_D(io_purr4,IO_PURR4)	/* addr 25h */
__IO_STATIC __RESERVE_D(dmy_26,1)		/* addr 26h */
__IO_EXTERN __UNION_D(io_cntr1,IO_CNTR1)	/* addr 27h */
__IO_EXTERN __UNION_D(io_cntr2,IO_CNTR2)	/* addr 28h */
__IO_EXTERN __UNION_D(io_cntr3,IO_CNTR3)	/* addr 29h */
__IO_EXTERN __UCHAR_D(IO_COMR1)			/* addr 2Ah */
__IO_EXTERN __UCHAR_D(IO_COMR2)			/* addr 2Bh */
__IO_EXTERN __UNION_D(io_ckr,IO_CKR)		/* addr 2Ch */
__IO_EXTERN __UNION_D(io_scs,IO_SCS)		/* addr 2Dh */
__IO_EXTERN __UNION_D(io_fmcs,IO_FMCS)		/* addr 2Eh */
__IO_EXTERN __UNION_D(io_smc1,IO_SMC1)		/* addr 2Fh */
__IO_EXTERN __UNION_D(io_smc2,IO_SMC2)		/* addr 30h */
__IO_EXTERN __UNION_D(io_ssd,IO_SSD)		/* addr 31h */
__IO_EXTERN __UCHAR_D(IO_SIDR)			/* addr 32h */
__IO_EXTERN __UCHAR_D(IO_SRC)			/* addr 33h */
__IO_EXTERN __UNION_D(io_ibsr,IO_IBSR)		/* addr 34h */
__IO_EXTERN __UNION_D(io_ibcr,IO_IBCR)		/* addr 35h */
__IO_EXTERN __UNION_D(io_iccr,IO_ICCR)		/* addr 36h */
__IO_EXTERN __UNION_D(io_iadr,IO_IADR)		/* addr 37h */
__IO_EXTERN __UCHAR_D(IO_IDAR)			/* addr 38h */
__IO_STATIC __RESERVE_D(dmy_39,1)		/* addr 39h */
__IO_EXTERN __UNION_D(io_smr ,IO_SMR1)		/* addr 3Ah */
__IO_EXTERN __UCHAR_D(IO_SDR1)			/* addr 3Bh */
__IO_EXTERN __UNION_D(io_eie,IO_EIE)		/* addr 3Ch */
__IO_EXTERN __UNION_D(io_eif,IO_EIF)		/* addr 3Dh */
__IO_STATIC __RESERVE_D(dmy_3E_3F,2)		/* addr 3E-3Fh */
__IO_EXTERN __UNION_D(io_hmdr,IO_HMDR)		/* addr 40h */
__IO_EXTERN __UNION_D(io_hdsr1,IO_HDSR1)	/* addr 41h */
__IO_EXTERN __UCHAR_D(IO_HDSR2)			/* addr 42h */
__IO_EXTERN __UCHAR_D(IO_HDSR3)			/* addr 43h */
__IO_EXTERN __UNION_D(io_hstr,IO_HSTR)		/* addr 44h */
__IO_EXTERN __UNION_D(io_occr,IO_OCCR)		/* addr 45h */
__IO_EXTERN __UCHAR_D(IO_DADR)			/* addr 46h */
__IO_STATIC __RESERVE_D(dmy_47_49,3)		/* addr 47-49h */
__IO_EXTERN __UNION_D(io_smr ,IO_SMR2)		/* addr 4Ah */
__IO_EXTERN __UCHAR_D(IO_SDR2)			/* addr 4Bh */
__IO_STATIC __RESERVE_D(dmy_4C_4D,2)		/* addr 4C-4Dh */
__IO_EXTERN __UNION_D(io_hdsr4,IO_HDSR4)	/* addr 4Eh */
__IO_STATIC __RESERVE_D(dmy_4F,1)		/* addr 4Fh */
__IO_EXTERN __UNION_D(io_umdr,IO_UMDR)		/* addr 50h */
__IO_EXTERN __UNION_D(io_dbar,IO_DBAR)		/* addr 51h */
__IO_EXTERN __UCHAR_D(IO_TDCR0)			/* addr 52h */
__IO_EXTERN __UCHAR_D(IO_TDCR1)			/* addr 53h */
__IO_STATIC __RESERVE_D(dmy_54,1)		/* addr 54h */
__IO_EXTERN __UCHAR_D(IO_TDCR2)			/* addr 55h */
__IO_STATIC __RESERVE_D(dmy_56,1)		/* addr 56h */
__IO_EXTERN __UCHAR_D(IO_TDCR3)			/* addr 57h */
__IO_EXTERN __UNION_D(io_uctr,IO_UCTR)		/* addr 58h */
__IO_EXTERN __UNION_D(io_ustr1,IO_USTR1)	/* addr 59h */
__IO_EXTERN __UNION_D(io_ustr2,IO_USTR2)	/* addr 5Ah */
__IO_EXTERN __UNION_D(io_umskr,IO_UMSKR)	/* addr 5Bh */
__IO_EXTERN __USHORT_D(IO_UFRMR)		/* addr 5C-5Dh */
__IO_EXTERN __UNION_D(io_eper,IO_EPER)		/* addr 5Eh */
__IO_EXTERN __UNION_D(io_epbr0,IO_EPBR0)	/* addr 5Fh */
__IO_EXTERN __UNION_D(io_epbrn,IO_EPBR1)	/* addr 60-61h */
__IO_EXTERN __UNION_D(io_epbrn,IO_EPBR2)	/* addr 62-63h */
__IO_EXTERN __UNION_D(io_epbrn,IO_EPBR3)	/* addr 64-65h */
__IO_STATIC __RESERVE_D(dmy_66_7A,21)		/* addr 66-7Ah */
__IO_EXTERN __UCHAR_D(IO_ILR1)			/* addr 7Bh */
__IO_EXTERN __UCHAR_D(IO_ILR2)			/* addr 7Ch */
__IO_EXTERN __UCHAR_D(IO_ILR3)			/* addr 7Dh */
__IO_EXTERN __UCHAR_D(IO_ILR4)			/* addr 7Eh */
__IO_STATIC __RESERVE_D(dmy_7F,1)		/* addr 7Fh */
