/*
 MB89490 Series I/O register declaration file V30L08R03
 ALL RIGHTS RESERVED, COPYRIGHT (C) FUJITSU LIMITED 1998
 LICENSED MATERIAL - PROGRAM PROPERTY OF FUJITSU LIMITED
*/
#ifdef __FASM__
#include "_ra89490.h"
#else
#include "_r89490.h"
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
__IO_EXTERN __UNION_D(io_pdr3,IO_DDR3)		/* addr 0Dh */
__IO_EXTERN __UNION_D(io_rsfr,IO_RSFR)		/* addr 0Eh */
__IO_EXTERN __UNION_D(io_pdr4,IO_PDR4)		/* addr 0Fh */
__IO_EXTERN __UNION_D(io_pdr5,IO_PDR5)		/* addr 10h */
__IO_EXTERN __UNION_D(io_pdr5,IO_DDR5)		/* addr 11h */
__IO_EXTERN __UNION_D(io_pdr6,IO_PDR6)		/* addr 12h */
__IO_EXTERN __UNION_D(io_pdr6,IO_DDR6)		/* addr 13h */
__IO_EXTERN __UNION_D(io_pdr7,IO_PDR7)		/* addr 14h */
__IO_EXTERN __UNION_D(io_pdr7,IO_DDR7)		/* addr 15h */
__IO_EXTERN __UNION_D(io_pdr8,IO_PDR8)		/* addr 16h */
__IO_EXTERN __UNION_D(io_pdr8,IO_DDR8)		/* addr 17h */
__IO_EXTERN __UNION_D(io_eic0,IO_EIC0)		/* addr 18h */
__IO_EXTERN __UNION_D(io_eic1,IO_EIC1)		/* addr 19h */
__IO_EXTERN __UNION_D(io_eic2,IO_EIC2)		/* addr 1Ah */
__IO_EXTERN __UNION_D(io_eic3,IO_EIC3)		/* addr 1Bh */
__IO_EXTERN __UNION_D(io_eie1,IO_EIE1)		/* addr 1Ch */
__IO_EXTERN __UNION_D(io_eif1,IO_EIF1)		/* addr 1Dh */
__IO_EXTERN __UNION_D(io_smr,IO_SMR)		/* addr 1Eh */
__IO_EXTERN __UCHAR_D(IO_SDR)			/* addr 1Fh */
__IO_EXTERN __UNION_D(io_t01cr1,IO_T0CR1)	/* addr 20h */
__IO_EXTERN __UNION_D(io_t01cr0,IO_T0CR0)	/* addr 21h */
__IO_EXTERN __UNION_D(io_tdr01,IO_T0DR01)	/* addr 22-23h */
__IO_EXTERN __UNION_D(io_t01cr1,IO_T1CR1)	/* addr 24h */
__IO_EXTERN __UNION_D(io_t01cr0,IO_T1CR0)	/* addr 25h */
__IO_EXTERN __UNION_D(io_tdr01,IO_T1DR01)	/* addr 26-27h */
__IO_EXTERN __UNION_D(io_ader,IO_ADER)		/* addr 28h */
__IO_EXTERN __UNION_D(io_adc0,IO_ADC0)		/* addr 29h */
__IO_EXTERN __UNION_D(io_adc1,IO_ADC1)		/* addr 2Ah */
__IO_EXTERN __UNION_D(io_add,IO_ADD)		/* addr 2B-2Ch */
__IO_EXTERN __UNION_D(io_cntr0,IO_CNTR0)	/* addr 2Dh */
__IO_EXTERN __UCHAR_D(IO_COMR0)			/* addr 2Eh */
__IO_EXTERN __UNION_D(io_smc0,IO_SMC0)		/* addr 2Fh */
__IO_EXTERN __UNION_D(io_smc1,IO_SMC1)		/* addr 30h */
__IO_EXTERN __UNION_D(io_ssd,IO_SSD)		/* addr 31h */
__IO_EXTERN __UCHAR_D(IO_SIDR)			/* addr 32h */
__IO_EXTERN __UCHAR_D(IO_SRC)			/* addr 33h */
__IO_EXTERN __UNION_D(io_cntr1,IO_CNTR1)	/* addr 34h */
__IO_EXTERN __UCHAR_D(IO_COMR1)			/* addr 35h */
__IO_EXTERN __CONST __UNION_D(io_ibsr,IO_IBSR)	/* addr 36h */
__IO_EXTERN __UNION_D(io_ibcr,IO_IBCR)		/* addr 37h */
__IO_EXTERN __UNION_D(io_iccr,IO_ICCR)		/* addr 38h */
__IO_EXTERN __UNION_D(io_iadr,IO_IADR)		/* addr 39h */
__IO_EXTERN __UCHAR_D(IO_IDAR)			/* addr 3Ah */
__IO_EXTERN __UNION_D(io_pllcr,IO_PLLCR)	/* addr 3Bh */
__IO_STATIC __RESERVE_D(dmy_3C_3F,4)		/* addr 3C-3Fh */
__IO_EXTERN __UCHAR_D(IO_RMN)			/* addr 40h */
__IO_EXTERN __UNION_D(io_rmc,IO_RMC)		/* addr 41h */
__IO_EXTERN __UNION_D(io_rms,IO_RMS)		/* addr 42h */
__IO_EXTERN __UNION_D(io_rmd,IO_RMD)		/* addr 43h */
__IO_EXTERN __UCHAR_D(IO_RMCD0)			/* addr 44h */
__IO_EXTERN __UCHAR_D(IO_RMCD1)			/* addr 45h */
__IO_EXTERN __UCHAR_D(IO_RMCD2)			/* addr 46h */
__IO_EXTERN __UCHAR_D(IO_RMCD3)			/* addr 47h */
__IO_EXTERN __UCHAR_D(IO_RMCD4)			/* addr 48h */
__IO_EXTERN __UCHAR_D(IO_RMCD5)			/* addr 49h */
__IO_EXTERN __UNION_D(io_rmci,IO_RMCI)		/* addr 4Ah */
__IO_STATIC __RESERVE_D(dmy_4B_5D,19)		/* addr 4B-5Dh */
__IO_EXTERN __UCHAR_D(IO_LOCR)			/* addr 5Eh */
__IO_EXTERN __UNION_D(io_lcd,IO_LCD)		/* addr 5Fh */
__IO_EXTERN __UNION_D(io_vram,IO_VRAM)		/* addr 60-6Fh */
__IO_EXTERN __UNION_D(io_purc0,IO_PURC0)	/* addr 70h */
__IO_EXTERN __UNION_D(io_purc1,IO_PURC1)	/* addr 71h */
__IO_EXTERN __UNION_D(io_purc2,IO_PURC2)	/* addr 72h */
__IO_EXTERN __UNION_D(io_purc3,IO_PURC3)	/* addr 73h */
__IO_EXTERN __UNION_D(io_purc5,IO_PURC5)	/* addr 74h */
__IO_EXTERN __UNION_D(io_purc6,IO_PURC6)	/* addr 75h */
__IO_EXTERN __UNION_D(io_purc7,IO_PURC7)	/* addr 76h */
__IO_EXTERN __UNION_D(io_purc8,IO_PURC8)	/* addr 77h */
__IO_STATIC __RESERVE_D(dmy_78_79,2)		/* addr 78-79h */
#ifdef __CPU_MB89F490_SERIES
__IO_EXTERN __UNION_D(io_fmcs, IO_FMCS)		/* addr 7Ah */
#else
__IO_STATIC __RESERVE_D(dmy_7A,1)		/* addr 7Ah */
#endif
__IO_EXTERN __UCHAR_D(IO_ILR1)			/* addr 7Bh */
__IO_EXTERN __UCHAR_D(IO_ILR2)			/* addr 7Ch */
__IO_EXTERN __UCHAR_D(IO_ILR3)			/* addr 7Dh */
__IO_EXTERN __UCHAR_D(IO_ILR4)			/* addr 7Eh */
__IO_STATIC __RESERVE_D(dmy_7F,1)		/* addr 7Fh */
