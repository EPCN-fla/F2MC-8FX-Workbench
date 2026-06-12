/*
 MB89470 Series I/O register declaration file V30L08R01
 ALL RIGHTS RESERVED, COPYRIGHT (C) FUJITSU LIMITED 1998
 LICENSED MATERIAL - PROGRAM PROPERTY OF FUJITSU LIMITED
*/
#ifdef __FASM__
#include "_ra89470.h"
#else
#include "_r89470.h"
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

__IO_EXTERN __UNION_D(io_pdr0,	IO_PDR0)	/* addr 00h */
__IO_EXTERN __UCHAR_D(		IO_DDR0)	/* addr 01h */
__IO_EXTERN __UNION_D(io_pdr1,	IO_PDR1)	/* addr 02h */
__IO_EXTERN __UCHAR_D(		IO_DDR1)	/* addr 03h */
__IO_EXTERN __UNION_D(io_pdr2,	IO_PDR2)	/* addr 04h */
__IO_STATIC __RESERVE_D(dmy_05, 1)		/* addr 05h */
__IO_EXTERN __UNION_D(io_pdr2,	IO_DDR2)	/* addr 06h */
__IO_EXTERN __UNION_D(io_sycc,	IO_SYCC)	/* addr 07h */
__IO_EXTERN __UNION_D(io_stbc,	IO_STBC)	/* addr 08h */
__IO_EXTERN __UCHAR_D(		IO_WDTC)	/* addr 09h */
__IO_EXTERN __UNION_D(io_tbtc,	IO_TBTC)	/* addr 0Ah */
__IO_EXTERN __UNION_D(io_wpcr,	IO_WPCR)	/* addr 0Bh */
__IO_EXTERN __UNION_D(io_pdr3,	IO_PDR3)	/* addr 0Ch */
__IO_EXTERN __UNION_D(io_pdr4,	IO_PDR4)	/* addr 0Dh */
__IO_EXTERN __UNION_D(io_rsfr,	IO_RSFR)	/* addr 0Eh */
__IO_EXTERN __UNION_D(io_buzr,	IO_BUZR)	/* addr 0Fh */
__IO_EXTERN __UNION_D(io_pdr5,	IO_PDR5)	/* addr 10h */
__IO_EXTERN __UNION_D(io_pdr5,	IO_DDR5)	/* addr 11h */
__IO_STATIC __RESERVE_D(dmy_12_13, 2)		/* addr 12-13h */
__IO_EXTERN __UNION_D(io_t2cr,	IO_T4CR)	/* addr 14h */
__IO_EXTERN __UNION_D(io_t1cr,	IO_T3CR)	/* addr 15h */
__IO_EXTERN __UNION_D(io_tdr,	IO_T43DR)	/* addr 16-17h */
__IO_EXTERN __UNION_D(io_t2cr,	IO_T2CR)	/* addr 18h */
__IO_EXTERN __UNION_D(io_t1cr,	IO_T1CR)	/* addr 19h */
__IO_EXTERN __UNION_D(io_tdr,	IO_T21DR)	/* addr 1A-1Bh */
__IO_STATIC __RESERVE_D(dmy_1C_1F, 4)		/* addr 1C-1Fh */
__IO_EXTERN __UNION_D(io_adc1,	IO_ADC1)	/* addr 20h */
__IO_EXTERN __UNION_D(io_adc2,	IO_ADC2)	/* addr 21h */
__IO_EXTERN __UNION_D(io_add,	IO_ADD)		/* addr 22-23h */
__IO_EXTERN __UNION_D(io_ader,	IO_ADER)	/* addr 24h */
__IO_STATIC __RESERVE_D(dmy_25, 1)		/* addr 25h */
__IO_EXTERN __UNION_D(io_smc1,	IO_SMC11)	/* addr 26h */
__IO_EXTERN __UNION_D(io_smc2,	IO_SMC12)	/* addr 27h */
__IO_EXTERN __UNION_D(io_ssd,	IO_SSD1)	/* addr 28h */
__IO_EXTERN __UCHAR_D(		IO_SIDR1)	/* addr 29h */
__IO_EXTERN __UCHAR_D(		IO_SRC1)	/* addr 2Ah */
__IO_EXTERN __UNION_D(io_smc1,	IO_SMC21)	/* addr 2Bh */
__IO_EXTERN __UNION_D(io_smc2,	IO_SMC22)	/* addr 2Ch */
__IO_EXTERN __UNION_D(io_ssd,	IO_SSD2)	/* addr 2Dh */
__IO_EXTERN __UCHAR_D(		IO_SIDR2)	/* addr 2Eh */
__IO_EXTERN __UCHAR_D(		IO_SRC2)	/* addr 2Fh */
__IO_EXTERN __UNION_D(io_eic1,	IO_EIC1)	/* addr 30h */
__IO_EXTERN __UNION_D(io_eic2,	IO_EIC2)	/* addr 31h */
__IO_EXTERN __UNION_D(io_eie2,	IO_EIE2)	/* addr 32h */
__IO_EXTERN __UNION_D(io_eif2,	IO_EIF2)	/* addr 33h */
__IO_EXTERN __UNION_D(io_pcr1,	IO_PCR1)	/* addr 34h */
__IO_EXTERN __UNION_D(io_pcr2,	IO_PCR2)	/* addr 35h */
__IO_EXTERN __UCHAR_D(		IO_PLBR)	/* addr 36h */
__IO_STATIC __RESERVE_D(dmy_37, 1)		/* addr 37h */
__IO_EXTERN __UNION_D(io_cntr,	IO_CNTR)	/* addr 38h */
__IO_EXTERN __UCHAR_D(		IO_COMR)	/* addr 39h */
__IO_STATIC __RESERVE_D(dmy_3A_6F, 54)		/* addr 3A-6Fh */
__IO_EXTERN __UNION_D(io_purc0,	IO_PURC0)	/* addr 70h */
__IO_EXTERN __UNION_D(io_purc1,	IO_PURC1)	/* addr 71h */
__IO_EXTERN __UNION_D(io_purc2,	IO_PURC2)	/* addr 72h */
__IO_EXTERN __UNION_D(io_purc3,	IO_PURC3)	/* addr 73h */
__IO_STATIC __RESERVE_D(dmy_74,1)		/* addr 74h */
__IO_EXTERN __UNION_D(io_purc5,	IO_PURC5)	/* addr 75h */
__IO_STATIC __RESERVE_D(dmy_76_7A, 5)		/* addr 76-7Ah */
__IO_EXTERN __UCHAR_D(		IO_ILR1)	/* addr 7Bh */
__IO_EXTERN __UCHAR_D(		IO_ILR2)	/* addr 7Ch */
__IO_EXTERN __UCHAR_D(		IO_ILR3)	/* addr 7Dh */
__IO_EXTERN __UCHAR_D(		IO_ILR4)	/* addr 7Eh */
__IO_STATIC __RESERVE_D(dmy_7F, 1)		/* addr 7Fh */
