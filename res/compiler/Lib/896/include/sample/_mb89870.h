/*
 MB89870 Series I/O register declaration file V30L08
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
__IO_EXTERN __UCHAR_D(IO_DDR0)			/* addr 01h */
__IO_EXTERN __UNION_D(io_pdr1,IO_PDR1)		/* addr 02h */
__IO_EXTERN __UCHAR_D(IO_DDR1)			/* addr 03h */
__IO_EXTERN __UNION_D(io_pdr2,IO_PDR2)		/* addr 04h */
__IO_EXTERN __UNION_D(io_pdr2,IO_DDR2)		/* addr 05h */
__IO_STATIC __RESERVE_D(dmy_06,1)		/* addr 06h */
__IO_EXTERN __UNION_D(io_sycc,IO_SYCC)		/* addr 07h */
__IO_EXTERN __UNION_D(io_stbc,IO_STBC)		/* addr 08h */
__IO_EXTERN __UCHAR_D(IO_WDTC)			/* addr 09h */
__IO_EXTERN __UNION_D(io_tbtc,IO_TBTC)		/* addr 0Ah */
__IO_EXTERN __UNION_D(io_wpcr,IO_WPCR)		/* addr 0Bh */
__IO_EXTERN __UNION_D(io_pdr3,IO_PDR3)		/* addr 0Ch */
__IO_EXTERN __UNION_D(io_pdr3,IO_DDR3)		/* addr 0Dh */
__IO_EXTERN __UNION_D(io_pdr4,IO_PDR4)		/* addr 0Eh */
__IO_EXTERN __UNION_D(io_pdr4,IO_DDR4)		/* addr 0Fh */
__IO_STATIC __RESERVE_D(dmy_10_15,6)		/* addr 10-15h */
__IO_EXTERN __UNION_D(io_pdr5,IO_PDR5)		/* addr 16h */
__IO_EXTERN __UNION_D(io_pdr5,IO_DDR5)		/* addr 17h */
__IO_STATIC __RESERVE_D(dmy_18_19,2)		/* addr 18-19h */
__IO_EXTERN __UNION_D(io_chg5,IO_CHG5)		/* addr 1Ah */
__IO_STATIC __RESERVE_D(dmy_1B_1C,2)		/* addr 1B-1Ch */
__IO_EXTERN __UCHAR_D(IO_ICR3)			/* addr 1Dh */
__IO_EXTERN __UNION_D(io_cntr,IO_CNTR)		/* addr 1Eh */
__IO_EXTERN __UCHAR_D(IO_COMR)			/* addr 1Fh */
__IO_STATIC __RESERVE_D(dmy_20_23,4)		/* addr 20-23h */
__IO_EXTERN __UNION_D(io_t2cr,IO_T2CR)		/* addr 24h */
__IO_EXTERN __UNION_D(io_t1cr,IO_T1CR)		/* addr 25h */
__IO_EXTERN __UNION_D(io_t12dr,IO_T12DR)	/* addr 26-27h */
__IO_EXTERN __UNION_D(io_smr,IO_SMR)		/* addr 28h */
__IO_EXTERN __UCHAR_D(IO_SDR)			/* addr 29h */
__IO_STATIC __RESERVE_D(dmy_2A_2B,2)		/* addr 2A-2Bh */
__IO_EXTERN __UNION_D(io_opc,IO_OPC)		/* addr 2Ch */
__IO_EXTERN __UNION_D(io_adc1,IO_ADC1)		/* addr 2Dh */
__IO_EXTERN __UNION_D(io_adc2,IO_ADC2)		/* addr 2Eh */
__IO_EXTERN __UNION_D(io_add,IO_ADD)		/* addr 2F-30h */
__IO_EXTERN __UNION_D(io_eie1,IO_EIE1)		/* addr 31h */
__IO_EXTERN __UNION_D(io_eif1,IO_EIF1)		/* addr 32h */
__IO_EXTERN __UNION_D(io_eie2,IO_EIE2)		/* addr 33h */
__IO_STATIC __RESERVE_D(dmy_34_5F,44)		/* addr 34-5Fh */
__IO_EXTERN __UNION_D(io_vram,IO_VRAM)		/* addr 60-6Bh */
__IO_STATIC __RESERVE_D(dmy_6C_6F,4)		/* addr 6C-6Fh */
__IO_EXTERN __UNION_D(io_lcr,IO_LCR1)		/* addr 70h */
__IO_EXTERN __UNION_D(io_lcr2,IO_LCR2)		/* addr 71h */
__IO_STATIC __RESERVE_D(dmy_72_7B,10)		/* addr 72-7Bh */
__IO_EXTERN __UCHAR_D(IO_ILR1)			/* addr 7Ch */
__IO_EXTERN __UCHAR_D(IO_ILR2)			/* addr 7Dh */
__IO_EXTERN __UCHAR_D(IO_ILR3)			/* addr 7Eh */
__IO_STATIC __RESERVE_D(dmy_7F,1)		/* addr 7Fh */
