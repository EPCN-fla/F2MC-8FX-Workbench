/*
 MB89560 Series I/O register declaration file V30L08
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
__IO_STATIC __RESERVE_D(dmy_04_06,3)		/* addr 04-06h */
__IO_EXTERN __UNION_D(io_sycc,IO_SYCC)		/* addr 07h */
__IO_EXTERN __UNION_D(io_stbc,IO_STBC)		/* addr 08h */
__IO_EXTERN __UCHAR_D(IO_WDTC)			/* addr 09h */
__IO_EXTERN __UNION_D(io_tbtc,IO_TBTC)		/* addr 0Ah */
__IO_EXTERN __UNION_D(io_wpcr,IO_WPCR)		/* addr 0Bh */
__IO_EXTERN __UNION_D(io_pdr2,IO_PDR2)		/* addr 0Ch */
__IO_EXTERN __UNION_D(io_pdr2,IO_DDR2)		/* addr 0Dh */
__IO_EXTERN __UNION_D(io_pdr3,IO_PDR3)		/* addr 0Eh */
__IO_EXTERN __UNION_D(io_pdr4,IO_PDR4)		/* addr 0Fh */
__IO_EXTERN __UNION_D(io_ddr4,IO_DDR4)		/* addr 10h */
__IO_EXTERN __UNION_D(io_pdr5,IO_PDR5)		/* addr 11h */
__IO_STATIC __RESERVE_D(dmy_12,1)		/* addr 12h */
__IO_EXTERN __UNION_D(io_pdr6,IO_PDR6)		/* addr 13h */
__IO_STATIC __RESERVE_D(dmy_14_19,6)		/* addr 14-19h */
__IO_EXTERN __UNION_D(io_t2cr,IO_T2CR)		/* addr 1Ah */
__IO_EXTERN __UCHAR_D(IO_T2DR)			/* addr 1Bh */
__IO_EXTERN __UNION_D(io_t1cr,IO_T1CR)		/* addr 1Ch */
__IO_EXTERN __UCHAR_D(IO_T1DR)			/* addr 1Dh */
__IO_STATIC __RESERVE_D(dmy_1E_21,4)		/* addr 1E-21h */
__IO_EXTERN __UNION_D(io_smc11,IO_SMC11)	/* addr 22h */
__IO_EXTERN __UNION_D(io_src1,IO_SRC1)		/* addr 23h */
__IO_EXTERN __UNION_D(io_ssd1,IO_SSD1)		/* addr 24h */
__IO_EXTERN __UCHAR_D(IO_SIDR1)			/* addr 25h */
__IO_EXTERN __UNION_D(io_smc12,IO_SMC12)	/* addr 26h */
__IO_EXTERN __UNION_D(io_cntr1,IO_CNTR1)	/* addr 27h */
__IO_EXTERN __UNION_D(io_cntr2,IO_CNTR2)	/* addr 28h */
__IO_EXTERN __UNION_D(io_cntr3,IO_CNTR3)	/* addr 29h */
__IO_EXTERN __UCHAR_D(IO_COMR1)			/* addr 2Ah */
__IO_EXTERN __UCHAR_D(IO_COMR2)			/* addr 2Bh */
__IO_EXTERN __UNION_D(io_pcr1,IO_PCR1)		/* addr 2Ch */
__IO_EXTERN __UNION_D(io_pcr2,IO_PCR2)		/* addr 2Dh */
__IO_EXTERN __UCHAR_D(IO_RLBR)			/* addr 2Eh */
__IO_EXTERN __UNION_D(io_smc21,IO_SMC21)	/* addr 2Fh */
__IO_EXTERN __UNION_D(io_smc22,IO_SMC22)	/* addr 30h */
__IO_EXTERN __UNION_D(io_ssd2,IO_SSD2)		/* addr 31h */
__IO_EXTERN __UCHAR_D(IO_SIDR2)			/* addr 32h */
__IO_EXTERN __UCHAR_D(IO_SRC2)			/* addr 33h */
__IO_EXTERN __UNION_D(io_adc1,IO_ADC1)		/* addr 34h */
__IO_EXTERN __UNION_D(io_adc2,IO_ADC2)		/* addr 35h */
__IO_EXTERN __STRUCT_D(io_add,IO_ADD)		/* addr 36-37h */
__IO_EXTERN __UNION_D(io_rcr21,IO_RCR21)	/* addr 38h */
__IO_EXTERN __UNION_D(io_rcr23,IO_RCR23)	/* addr 39h */
__IO_EXTERN __UNION_D(io_rcr22,IO_RCR22)	/* addr 3Ah */
__IO_EXTERN __UNION_D(io_rcr24,IO_RCR24)	/* addr 3Bh */
__IO_STATIC __RESERVE_D(dmy_3C_3E,3)		/* addr 3C-3Eh */
__IO_EXTERN __UNION_D(io_eic1,IO_EIC1)		/* addr 3Fh */
__IO_EXTERN __UNION_D(io_eic2,IO_EIC2)		/* addr 40h */
__IO_EXTERN __UNION_D(io_eic3,IO_EIC3)		/* addr 41h */
__IO_EXTERN __UNION_D(io_eic4,IO_EIC4)		/* addr 42h */
__IO_STATIC __RESERVE_D(dmy_43_50,14)		/* addr 43-50h */
__IO_EXTERN __CONST __UNION_D(io_ibsr,IO_IBSR)	/* addr 51h */
__IO_EXTERN __UNION_D(io_ibcr,IO_IBCR)		/* addr 52h */
__IO_EXTERN __UNION_D(io_iccr,IO_ICCR)		/* addr 53h */
__IO_EXTERN __UNION_D(io_iadr,IO_IADR)		/* addr 54h */
__IO_EXTERN __UCHAR_D(IO_IDAR)			/* addr 55h */
__IO_EXTERN __UNION_D(io_eie2,IO_EIE2)		/* addr 56h */
__IO_EXTERN __UNION_D(io_eif2,IO_EIF2)		/* addr 57h */
__IO_EXTERN __UNION_D(io_rcr1,IO_RCR1)		/* addr 58h */
__IO_EXTERN __UNION_D(io_rcr2,IO_RCR2)		/* addr 59h */
__IO_EXTERN __UNION_D(io_ckr ,IO_CKR)		/* addr 5Ah */
__IO_EXTERN __UNION_D(io_lcr1,IO_LCR1)		/* addr 5Bh */
__IO_EXTERN __UNION_D(io_lcr2,IO_LCR2)		/* addr 5Ch */
__IO_EXTERN __UNION_D(io_lcr3,IO_LCR3)		/* addr 5Dh */
__IO_EXTERN __UCHAR_D(IO_LCD1)			/* addr 5Eh */
__IO_STATIC __RESERVE_D(dmy_5F,1)		/* addr 5Fh */
__IO_EXTERN __UNION_D(io_vram,IO_VRAM)		/* addr 60-6Bh */
__IO_STATIC __RESERVE_D(dmy_6C_6F,4)		/* addr 6C-6Fh */
__IO_EXTERN __UNION_D(io_smr ,IO_SMR)		/* addr 70h */
__IO_EXTERN __UCHAR_D(IO_SDR)			/* addr 71h */
__IO_EXTERN __UNION_D(io_purr0,IO_PURR0)	/* addr 72h */
__IO_EXTERN __UNION_D(io_purr1,IO_PURR1)	/* addr 73h */
__IO_EXTERN __UNION_D(io_purr2,IO_PURR2)	/* addr 74h */
__IO_EXTERN __UNION_D(io_purr4,IO_PURR4)	/* addr 75h */
__IO_STATIC __RESERVE_D(dmy_76,1)		/* addr 76h */
__IO_EXTERN __UNION_D(io_wren,IO_WREN)		/* addr 77h */
__IO_EXTERN __UNION_D(io_wror,IO_WROR)		/* addr 78h */
__IO_EXTERN __UNION_D(io_aden,IO_ADEN)		/* addr 79h */
__IO_STATIC __RESERVE_D(dmy_7A,1)		/* addr 7Ah */
__IO_EXTERN __UCHAR_D(IO_ILR1)			/* addr 7Bh */
__IO_EXTERN __UCHAR_D(IO_ILR2)			/* addr 7Ch */
__IO_EXTERN __UCHAR_D(IO_ILR3)			/* addr 7Dh */
__IO_EXTERN __UCHAR_D(IO_ILR4)			/* addr 7Eh */
__IO_STATIC __RESERVE_D(dmy_7F,1)		/* addr 7Fh */

#ifdef __FASM__
#ifdef __IO_DEFINE
  .section IO_WILDR, COMMON, locate=0x0480
#else
  .section DATA, DATA, ALIGN=1
#endif
#else
#ifdef __IO_DEFINE
  #pragma section DATA=IO_WILDR,locate=0x0480
#endif
#endif

__IO_DATA_EXTERN  __STRUCT_AD(io_wildreg,IO_WILDR,6)	/* addr 480-491h */
