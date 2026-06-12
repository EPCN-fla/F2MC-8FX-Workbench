/*
 MB89570 Series I/O register declaration file V30L08
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
__IO_STATIC __RESERVE_D(dmy_05,1)		/* addr 05h */
__IO_EXTERN __UCHAR_D(IO_DDR2)			/* addr 06h */
__IO_EXTERN __UNION_D(io_sycc,IO_SYCC)		/* addr 07h */
__IO_EXTERN __UNION_D(io_stbc,IO_STBC)		/* addr 08h */
__IO_EXTERN __UCHAR_D(IO_WDTC)			/* addr 09h */
__IO_EXTERN __UNION_D(io_tbtc,IO_TBTC)		/* addr 0Ah */
__IO_EXTERN __UNION_D(io_wpcr,IO_WPCR)		/* addr 0Bh */
__IO_STATIC __RESERVE_D(dmy_0C_0D,2)		/* addr 0C-0Dh */
__IO_EXTERN __UNION_D(io_rsfr,IO_RSFR)		/* addr 0Eh */
__IO_STATIC __RESERVE_D(dmy_0F,1)		/* addr 0Fh */
__IO_EXTERN __UNION_D(io_smc21,IO_SMC21)	/* addr 10h */
__IO_EXTERN __UNION_D(io_smc22,IO_SMC22)	/* addr 11h */
__IO_EXTERN __UNION_D(io_ssd2,IO_SSD2)		/* addr 12h */
__IO_EXTERN __UCHAR_D(IO_SIDR2)			/* addr 13h */
__IO_EXTERN __UCHAR_D(IO_SRC2)			/* addr 14h */
__IO_EXTERN __UNION_D(io_pdra,IO_PDRA)		/* addr 15h */
__IO_EXTERN __UNION_D(io_lcr3,IO_LCR3)		/* addr 16h */
__IO_EXTERN __UNION_D(io_pdrb,IO_PDRB)		/* addr 17h */
__IO_EXTERN __UNION_D(io_lcr4,IO_LCR4)		/* addr 18h */
__IO_EXTERN __UNION_D(io_brsr3,IO_BRSR3)	/* addr 19h */
__IO_EXTERN __UNION_D(io_t2cr,IO_T2CR)		/* addr 1Ah */
__IO_EXTERN __UNION_D(io_t1cr,IO_T1CR)		/* addr 1Bh */
__IO_EXTERN __UNION_D(io_t12dr,IO_T12DR)	/* addr 1C-1Dh */
__IO_STATIC __RESERVE_D(dmy_1E_1F,2)		/* addr 1E-1Fh */
__IO_EXTERN __UNION_D(io_pdr3,IO_PDR3)		/* addr 20h */
__IO_EXTERN __UNION_D(io_pdr4,IO_PDR4)		/* addr 21h */
__IO_EXTERN __UNION_D(io_pdr5,IO_PDR5)		/* addr 22h */
__IO_EXTERN __UNION_D(io_ddr5,IO_DDR5)		/* addr 23h */
__IO_EXTERN __UNION_D(io_pdr6,IO_PDR6)		/* addr 24h */
__IO_EXTERN __UNION_D(io_pdr7,IO_PDR7)		/* addr 25h */
__IO_EXTERN __UNION_D(io_ddr7,IO_DDR7)		/* addr 26h */
__IO_EXTERN __UNION_D(io_pdr8,IO_PDR8)		/* addr 27h */
__IO_EXTERN __UNION_D(io_ddr8,IO_DDR8)		/* addr 28h */
__IO_EXTERN __UNION_D(io_pdr9,IO_PDR9)		/* addr 29h */
__IO_EXTERN __UNION_D(io_ddr9,IO_DDR9)		/* addr 2Ah */
__IO_STATIC __RESERVE_D(dmy_2B_2C,2)		/* addr 2B-2Ch */
__IO_EXTERN __UNION_D(io_aden1,IO_ADEN1)	/* addr 2Dh */
__IO_EXTERN __UNION_D(io_aden2,IO_ADEN2)	/* addr 2Eh */
__IO_EXTERN __UNION_D(io_adc1,IO_ADC1)		/* addr 2Fh */
__IO_EXTERN __UNION_D(io_adc2,IO_ADC2)		/* addr 30h */
__IO_STATIC __RESERVE_D(dmy_31,1)		/* addr 31h */
__IO_EXTERN __UNION_D(io_add ,IO_ADD)		/* addr 32-33h */
__IO_STATIC __RESERVE_D(dmy_34,1)		/* addr 34h */
__IO_EXTERN __CONST __UNION_D(io_ibsr,IO_IBSR)	/* addr 35h */
__IO_EXTERN __UNION_D(io_ibcr,IO_IBCR)		/* addr 36h */
__IO_EXTERN __UNION_D(io_iccr,IO_ICCR)		/* addr 37h */
__IO_EXTERN __UNION_D(io_iadr,IO_IADR)		/* addr 38h */
__IO_EXTERN __UCHAR_D(IO_IDAR)			/* addr 39h */
__IO_EXTERN __UNION_D(io_itcr,IO_ITCR)		/* addr 3Ah */
__IO_EXTERN __UNION_D(io_itsr,IO_ITSR)		/* addr 3Bh */
__IO_EXTERN __UCHAR_D(IO_ITOD)			/* addr 3Ch */
__IO_EXTERN __UCHAR_D(IO_ITOC)			/* addr 3Dh */
__IO_EXTERN __UCHAR_D(IO_ISTO)			/* addr 3Eh */
__IO_EXTERN __UCHAR_D(IO_IMTO)			/* addr 3Fh */
__IO_EXTERN __CONST __UNION_D(io_mbsr,IO_MBSR)	/* addr 40h */
__IO_EXTERN __UNION_D(io_mbcr,IO_MBCR)		/* addr 41h */
__IO_EXTERN __UNION_D(io_mccr,IO_MCCR)		/* addr 42h */
__IO_EXTERN __UNION_D(io_madr,IO_MADR1)		/* addr 43h */
__IO_EXTERN __UNION_D(io_madr,IO_MADR2)		/* addr 44h */
__IO_EXTERN __UNION_D(io_madr,IO_MADR3)		/* addr 45h */
__IO_EXTERN __UNION_D(io_madr,IO_MADR4)		/* addr 46h */
__IO_EXTERN __UNION_D(io_madr,IO_MADR5)		/* addr 47h */
__IO_EXTERN __UNION_D(io_madr,IO_MADR6)		/* addr 48h */
__IO_EXTERN __UCHAR_D(IO_MDAR)			/* addr 49h */
__IO_EXTERN __UNION_D(io_mtcr,IO_MTCR)		/* addr 4Ah */
__IO_EXTERN __UNION_D(io_mtsr,IO_MTSR)		/* addr 4Bh */
__IO_EXTERN __UCHAR_D(IO_MTOD)			/* addr 4Ch */
__IO_EXTERN __UCHAR_D(IO_MTOC)			/* addr 4Dh */
__IO_EXTERN __UCHAR_D(IO_MSTO)			/* addr 4Eh */
__IO_EXTERN __UCHAR_D(IO_MMTO)			/* addr 4Fh */
__IO_EXTERN __UNION_D(io_malr,IO_MALR)		/* addr 50h */
__IO_EXTERN __UNION_D(io_cocr1,IO_COCR1)	/* addr 51h */
__IO_EXTERN __UNION_D(io_cocr2,IO_COCR2)	/* addr 52h */
__IO_EXTERN __UNION_D(io_cosr1,IO_COSR1)	/* addr 53h */
__IO_EXTERN __UNION_D(io_cicr1,IO_CICR1)	/* addr 54h */
__IO_EXTERN __UNION_D(io_cosr2,IO_COSR2)	/* addr 55h */
__IO_EXTERN __UNION_D(io_cicr2,IO_CICR2)	/* addr 56h */
__IO_EXTERN __UNION_D(io_cosr3,IO_COSR3)	/* addr 57h */
__IO_EXTERN __UNION_D(io_cosr4,IO_COSR4)	/* addr 58h */
__IO_EXTERN __UNION_D(io_cier,IO_CIER)		/* addr 59h */
__IO_EXTERN __UNION_D(io_eic1,IO_EIC1)		/* addr 5Ah */
__IO_EXTERN __UNION_D(io_eic2,IO_EIC2)		/* addr 5Bh */
__IO_EXTERN __UNION_D(io_brsr1,IO_BRSR1)	/* addr 5Ch */
__IO_EXTERN __UNION_D(io_brsr2,IO_BRSR2)	/* addr 5Dh */
__IO_EXTERN __UNION_D(io_lcr1,IO_LCR1)		/* addr 5Eh */
__IO_EXTERN __UNION_D(io_lcr2,IO_LCR2)		/* addr 5Fh */
__IO_EXTERN __UNION_D(io_vram,IO_VRAM)		/* addr 60-67h */
__IO_STATIC __RESERVE_D(dmy_68_6F,8)		/* addr 68-6Fh */
__IO_EXTERN __UNION_D(io_dacr,IO_DACR)		/* addr 70h */
__IO_EXTERN __UCHAR_D(IO_DADR1)			/* addr 71h */
__IO_EXTERN __UCHAR_D(IO_DADR2)			/* addr 72h */
__IO_EXTERN __UNION_D(io_tmcr,IO_TMCR)		/* addr 73h */
__IO_EXTERN __USHORT_D(IO_TCR)			/* addr 74-75h */
__IO_STATIC __RESERVE_D(dmy_76,1)		/* addr 76h */
__IO_EXTERN __UNION_D(io_wren,IO_WREN)		/* addr 77h */
__IO_STATIC __RESERVE_D(dmy_78_7A,3)		/* addr 78-7Ah */
__IO_EXTERN __UCHAR_D(IO_ILR1)			/* addr 7Bh */
__IO_EXTERN __UCHAR_D(IO_ILR2)			/* addr 7Ch */
__IO_EXTERN __UCHAR_D(IO_ILR3)			/* addr 7Dh */
__IO_EXTERN __UCHAR_D(IO_ILR4)			/* addr 7Eh */
__IO_STATIC __RESERVE_D(dmy_7F,1)		/* addr 7Fh */

#ifdef __FASM__
#ifdef __IO_DEFINE
  .section IO_WILDR, COMMON, locate=0x0C80
#else
  .section DATA, DATA, ALIGN=1
#endif
#else
#ifdef __IO_DEFINE
  #pragma section DATA=IO_WILDR,locate=0x0C80
#endif
#endif

__IO_DATA_EXTERN __STRUCT_AD(io_wildreg,IO_WILDR,6)	/* addr C80-C91h */
