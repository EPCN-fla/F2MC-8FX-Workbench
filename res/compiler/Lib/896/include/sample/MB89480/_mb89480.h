/*
 MB89480 Series I/O register declaration file V30L08R03
 ALL RIGHTS RESERVED, COPYRIGHT (C) FUJITSU LIMITED 1998
 LICENSED MATERIAL - PROGRAM PROPERTY OF FUJITSU LIMITED
*/
#ifdef __FASM__
#include "_ra89480.h"
#else
#include "_r89480.h"
#endif

/* I/O Area Address */
#ifdef __FASM__
#ifdef __IO_DEFINE
  .section IO_REG, IOCOMMON, locate=0x000000
#else
  .section IO, IO
#endif
#else
#ifdef __IO_DEFINE
  #pragma section IO=IO_REG, attr=IOCOMMON, locate=0x000000
#else
  #pragma section IO=IO, attr=IO
#endif
#endif

__IO_EXTERN __UNION_D(io_pdr0,IO_PDR0)		/* addr 00h */
__IO_EXTERN __UCHAR_D(IO_DDR0)			/* addr 01h */
__IO_EXTERN __UNION_D(io_pdr1,IO_PDR1)		/* addr 02h */
__IO_EXTERN __UCHAR_D(IO_DDR1)			/* addr 03h */
__IO_EXTERN __UNION_D(io_pdr2,IO_PDR2)		/* addr 04h */
__IO_STATIC __RESERVE_D(dmy_05,1)		/* addr 05h */
__IO_EXTERN __UNION_D(io_pdr2,IO_DDR2)		/* addr 06h */
__IO_EXTERN __UNION_D(io_sycc,IO_SYCC)		/* addr 07h */
__IO_EXTERN __UNION_D(io_stbc,IO_STBC)		/* addr 08h */
__IO_EXTERN __UCHAR_D(IO_WDTC)			/* addr 09h */
__IO_EXTERN __UNION_D(io_tbtc,IO_TBTC)		/* addr 0Ah */
__IO_EXTERN __UNION_D(io_wpcr,IO_WPCR)		/* addr 0Bh */
__IO_EXTERN __UNION_D(io_pdr3,IO_PDR3)		/* addr 0Ch */
__IO_STATIC __RESERVE_D(dmy_0D,1)		/* addr 0Dh */
__IO_EXTERN __UNION_D(io_rsfr,IO_RSFR)		/* addr 0Eh */
__IO_STATIC __RESERVE_D(dmy_0F,1)		/* addr 0Fh */
__IO_EXTERN __UNION_D(io_pdr4,IO_PDR4)		/* addr 10h */
__IO_STATIC __RESERVE_D(dmy_11,1)		/* addr 11h */
__IO_EXTERN __UNION_D(io_pdr5,IO_PDR5)		/* addr 12h */
__IO_STATIC __RESERVE_D(dmy_13_1F,13)		/* addr 13-1Fh */
__IO_EXTERN __UNION_D(io_smc1,IO_SMC1)		/* addr 20h */
__IO_EXTERN __UNION_D(io_smc2,IO_SMC2)		/* addr 21h */
__IO_EXTERN __UCHAR_D(IO_SRC)			/* addr 22h */
__IO_EXTERN __UNION_D(io_ssd,IO_SSD)		/* addr 23h */
__IO_EXTERN __UCHAR_D(IO_SIDR)			/* addr 24h */
__IO_EXTERN __UNION_D(io_eic1,IO_EIC1)		/* addr 25h */
__IO_EXTERN __UNION_D(io_eic2,IO_EIC2)		/* addr 26h */
__IO_EXTERN __UNION_D(io_eie2,IO_EIE2)		/* addr 27h */
__IO_EXTERN __UNION_D(io_eif2,IO_EIF2)		/* addr 28h */
__IO_STATIC __RESERVE_D(dmy_29_2B,3)		/* addr 29-2Bh */
__IO_EXTERN __UNION_D(io_adc1,IO_ADC1)		/* addr 2Ch */
__IO_EXTERN __UNION_D(io_adc2,IO_ADC2)		/* addr 2Dh */
__IO_EXTERN __UNION_D(io_add,IO_ADD)		/* addr 2E-2Fh */
__IO_EXTERN __UNION_D(io_ader,IO_ADER)		/* addr 30h */
__IO_EXTERN __UNION_D(io_pcr1,IO_PCR1)		/* addr 31h */
__IO_EXTERN __UNION_D(io_pcr2,IO_PCR2)		/* addr 32h */
__IO_EXTERN __UCHAR_D(IO_PLBR)			/* addr 33h */
__IO_EXTERN __UNION_D(io_cntr,IO_CNTR)		/* addr 34h */
__IO_EXTERN __UCHAR_D(IO_COMR)			/* addr 35h */
__IO_EXTERN __UNION_D(io_t12cr2,IO_T2CR2)	/* addr 36h */
__IO_EXTERN __UNION_D(io_t12cr1,IO_T2CR1)	/* addr 37h */
__IO_EXTERN __UNION_D(io_tdr12,IO_T2DR12)	/* addr 38-39h */
__IO_EXTERN __UNION_D(io_t12cr2,IO_T1CR2)	/* addr 3Ah */
__IO_EXTERN __UNION_D(io_t12cr1,IO_T1CR1)	/* addr 3Bh */
__IO_EXTERN __UNION_D(io_tdr12,IO_T1DR12)	/* addr 3C-3Dh */
__IO_EXTERN __UNION_D(io_ppgc1,IO_PPGC1)	/* addr 3Eh */
__IO_EXTERN __UNION_D(io_ppgc2,IO_PPGC2)	/* addr 3Fh */
__IO_EXTERN __UNION_D(io_buzr,IO_BUZR)		/* addr 40h */
__IO_STATIC __RESERVE_D(dmy_41_5D,29)		/* addr 41-5Dh */
__IO_EXTERN __UNION_D(io_lcr1,IO_LCR1)		/* addr 5Eh */
__IO_EXTERN __UCHAR_D(IO_LCR2)			/* addr 5Fh */
__IO_EXTERN __UNION_D(io_vram,IO_VRAM)		/* addr 60-6Fh */
__IO_EXTERN __UNION_D(io_purc0,IO_PURC0)	/* addr 70h */
__IO_STATIC __RESERVE_D(dmy_71,1)		/* addr 71h */
__IO_EXTERN __UNION_D(io_purc2,IO_PURC2)	/* addr 72h */
__IO_STATIC __RESERVE_D(dmy_73_7A,8)		/* addr 73-7Ah */
__IO_EXTERN __UCHAR_D(IO_ILR1)			/* addr 7Bh */
__IO_EXTERN __UCHAR_D(IO_ILR2)			/* addr 7Ch */
__IO_EXTERN __UCHAR_D(IO_ILR3)			/* addr 7Dh */
__IO_EXTERN __UCHAR_D(IO_ILR4)			/* addr 7Eh */
__IO_STATIC __RESERVE_D(dmy_7F,1)		/* addr 7Fh */
