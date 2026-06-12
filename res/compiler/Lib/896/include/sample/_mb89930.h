/*
 MB89930 Series I/O register declaration file V30L08
 ALL RIGHTS RESERVED, COPYRIGHT (C) FUJITSU LIMITED 1998
 LICENSED MATERIAL - PROGRAM PROPERTY OF FUJITSU LIMITED
*/
#ifdef __FASM__
#include "_mb899xx_a.h"
#else
#include "_mb899xx.h"
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
__IO_STATIC __RESERVE_D(dmy_02_06,5)		/* addr 02-06h */
__IO_EXTERN __UNION_D(io_sycc,IO_SYCC)		/* addr 07h */
__IO_EXTERN __UNION_D(io_stbc,IO_STBC)		/* addr 08h */
__IO_EXTERN __UCHAR_D(IO_WDTC)			/* addr 09h */
__IO_EXTERN __UNION_D(io_tbtc,IO_TBTC)		/* addr 0Ah */
__IO_STATIC __RESERVE_D(dmy_0B,1)		/* addr 0Bh */
__IO_EXTERN __UNION_D(io_pdr3,IO_PDR3)		/* addr 0Ch */
__IO_EXTERN __UCHAR_D(IO_DDR3)			/* addr 0Dh */
__IO_EXTERN __UNION_D(io_rsfr,IO_RSFR)		/* addr 0Eh */
__IO_EXTERN __UNION_D(io_pdr4,IO_PDR4)		/* addr 0Fh */
__IO_EXTERN __UNION_D(io_pdr4,IO_DDR4)		/* addr 10h */
__IO_EXTERN __UNION_D(io_pdr4,IO_OUT4)		/* addr 11h */
__IO_EXTERN __UNION_D(io_pdr5,IO_PDR5)		/* addr 12h */
__IO_EXTERN __UNION_D(io_pdr5,IO_DDR5)		/* addr 13h */
__IO_EXTERN __UNION_D(io_rcr21,IO_RCR21)	/* addr 14h */
__IO_EXTERN __UNION_D(io_rcr22,IO_RCR22)	/* addr 15h */
__IO_EXTERN __UNION_D(io_rcr23,IO_RCR23)	/* addr 16h */
__IO_EXTERN __UNION_D(io_rcr24,IO_RCR24)	/* addr 17h */
__IO_EXTERN __UNION_D(io_bzcr,IO_BZCR)		/* addr 18h */
__IO_EXTERN __UNION_D(io_tccr,IO_TCCR)		/* addr 19h */
__IO_EXTERN __UNION_D(io_tcr1,IO_TCR1)		/* addr 1Ah */
__IO_EXTERN __UNION_D(io_tcr0,IO_TCR0)		/* addr 1Bh */
__IO_EXTERN __UNION_D(io_tdr01,IO_TDR01)	/* addr 1C-1Dh */
__IO_EXTERN __UNION_D(io_tcp,IO_TCP)		/* addr 1E-1Fh */
__IO_EXTERN __UNION_D(io_tcr2,IO_TCR2)		/* addr 20h */
__IO_STATIC __RESERVE_D(dmy_21,1)		/* addr 21h */
__IO_EXTERN __UNION_D(io_cntr,IO_CNTR)		/* addr 22h */
__IO_EXTERN __UCHAR_D(IO_COMR)			/* addr 23h */
__IO_EXTERN __UNION_D(io_eic1,IO_EIC1)		/* addr 24h */
__IO_EXTERN __UNION_D(io_eic2,IO_EIC2)		/* addr 25h */
__IO_STATIC __RESERVE_D(dmy_26_27,2)		/* addr 26-27h */
__IO_EXTERN __UNION_D(io_smc1,IO_SMC)		/* addr 28h */
__IO_EXTERN __UNION_D(io_src,IO_SRC)		/* addr 29h */
__IO_EXTERN __UNION_D(io_ssd,IO_SSD)		/* addr 2Ah */
__IO_EXTERN __UCHAR_D(IO_SIDR)			/* addr 2Bh */
__IO_EXTERN __UNION_D(io_upc,IO_UPC)		/* addr 2Ch */
__IO_STATIC __RESERVE_D(dmy_2D_2F,3)		/* addr 2D-2Fh */
__IO_EXTERN __UNION_D(io_adc1,IO_ADC1)		/* addr 30h */
__IO_EXTERN __UNION_D(io_adc2,IO_ADC2)		/* addr 31h */
__IO_EXTERN __UNION_D(io_add,IO_ADD)		/* addr 32-33h */
__IO_EXTERN __UNION_D(io_aden,IO_ADEN)		/* addr 34h */
__IO_STATIC __RESERVE_D(dmy_35,1)		/* addr 35h */
__IO_EXTERN __UNION_D(io_eie2,IO_EIE2)		/* addr 36h */
__IO_EXTERN __UNION_D(io_eif2,IO_EIF2)		/* addr 37h */
__IO_STATIC __RESERVE_D(dmy_38,1)		/* addr 38h */
__IO_EXTERN __UNION_D(io_smr,IO_SMR)		/* addr 39h */
__IO_EXTERN __UCHAR_D(IO_SDR)			/* addr 3Ah */
__IO_EXTERN __UNION_D(io_ssel,IO_SSEL)		/* addr 3Bh */
__IO_STATIC __RESERVE_D(dmy_3C_3F,4)		/* addr 3C-3Fh */
__IO_EXTERN __STRUCT_AD(io_wildreg,IO_WILDR,2)	/* addr 40-45h */
__IO_EXTERN __UNION_D(io_wren,IO_WREN)		/* addr 46h */
__IO_EXTERN __UNION_D(io_wror,IO_WROR)		/* addr 47h */
__IO_STATIC __RESERVE_D(dmy_48_6F,40)		/* addr 48-6Fh */
__IO_EXTERN __UNION_D(io_pul0,IO_PUL0)		/* addr 70h */
__IO_EXTERN __UNION_D(io_pul3,IO_PUL3)		/* addr 71h */
__IO_EXTERN __UNION_D(io_pul5,IO_PUL5)		/* addr 72h */
__IO_STATIC __RESERVE_D(dmy_73_7A,8)		/* addr 73-7Ah */
__IO_EXTERN __UCHAR_D(IO_ILR1)			/* addr 7Bh */
__IO_EXTERN __UCHAR_D(IO_ILR2)			/* addr 7Ch */
__IO_EXTERN __UCHAR_D(IO_ILR3)			/* addr 7Dh */
__IO_EXTERN __UCHAR_D(IO_ILR4)			/* addr 7Eh */
__IO_STATIC __RESERVE_D(dmy_7F,1)		/* addr 7Fh */
