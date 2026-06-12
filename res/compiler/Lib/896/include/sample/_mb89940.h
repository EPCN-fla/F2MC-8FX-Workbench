/*
 MB89940 Series I/O register declaration file V30L08
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
__IO_EXTERN __UNION_D(io_pdr1,IO_PDR1)		/* addr 02h */
__IO_EXTERN __UCHAR_D(IO_DDR1)			/* addr 03h */
__IO_STATIC __RESERVE_D(dmy_04_06,3)		/* addr 04-06h */
__IO_EXTERN __UNION_D(io_sycc,IO_SYCC)		/* addr 07h */
__IO_EXTERN __UNION_D(io_stbc,IO_STBC)		/* addr 08h */
__IO_EXTERN __UCHAR_D(IO_WDTC)			/* addr 09h */
__IO_EXTERN __UNION_D(io_tbtc,IO_TBTC)		/* addr 0Ah */
__IO_EXTERN __UNION_D(io_lvrc,IO_LVRC)		/* addr 0Bh */
__IO_EXTERN __UNION_D(io_pdr2,IO_PDR2)		/* addr 0Ch */
__IO_EXTERN __UCHAR_D(IO_DDR2)			/* addr 0Dh */
__IO_EXTERN __UNION_D(io_pdr3,IO_PDR3)		/* addr 0Eh */
__IO_EXTERN __UCHAR_D(IO_DDR3)			/* addr 0Fh */
__IO_EXTERN __UNION_D(io_pdr4,IO_PDR4)		/* addr 10h */
__IO_EXTERN __UNION_D(io_ade,IO_ADE)		/* addr 11h */
__IO_STATIC __RESERVE_D(dmy_12_17,6)		/* addr 12-17h */
__IO_EXTERN __UNION_D(io_t2cr,IO_T2CR)		/* addr 18h */
__IO_EXTERN __UNION_D(io_t1cr,IO_T1CR)		/* addr 19h */
__IO_EXTERN __UNION_D(io_t12dr,IO_T12DR)	/* addr 1A-1Bh */
__IO_STATIC __RESERVE_D(dmy_1C_1F,4)		/* addr 1C-1Fh */
__IO_EXTERN __UNION_D(io_adc1,IO_ADC1)		/* addr 20h */
__IO_EXTERN __UNION_D(io_adc2,IO_ADC2)		/* addr 21h */
__IO_EXTERN __UCHAR_D(IO_ADCD)			/* addr 22h */
__IO_EXTERN __UNION_D(io_cntr1,IO_CNTR1)	/* addr 23h */
__IO_EXTERN __UCHAR_D(IO_COMR1)			/* addr 24h */
__IO_STATIC __RESERVE_D(dmy_25,1)		/* addr 25h */
__IO_EXTERN __UCHAR_D(IO_COMR2)			/* addr 26h */
__IO_EXTERN __UNION_D(io_sel1,IO_SEL1)		/* addr 27h */
__IO_EXTERN __UNION_D(io_sel2,IO_SEL2)		/* addr 28h */
__IO_EXTERN __UNION_D(io_cntr,IO_CNTR3)		/* addr 29h */
__IO_EXTERN __UCHAR_D(IO_COMR3)			/* addr 2Ah */
__IO_EXTERN __UNION_D(io_cntr,IO_CNTR4)		/* addr 2Bh */
__IO_EXTERN __UCHAR_D(IO_COMR4)			/* addr 2Ch */
__IO_EXTERN __UCHAR_D(IO_SELTEST)		/* addr 2Dh */
__IO_EXTERN __UNION_D(io_vmcntr,IO_VMCNTR)	/* addr 2Eh */
__IO_EXTERN __UNION_D(io_eic1,IO_EIC1)		/* addr 2Fh */
__IO_EXTERN __UNION_D(io_eic2,IO_EIC2)		/* addr 30h */
__IO_STATIC __RESERVE_D(dmy_31_5F,47)		/* addr 31-5Fh */
__IO_EXTERN __UNION_D(io_vram,IO_VRAM)		/* addr 60-68h */
__IO_STATIC __RESERVE_D(dmy_69_71,9)		/* addr 69-71h */
__IO_EXTERN __UNION_D(io_lcr,IO_LCR1)		/* addr 72h */
__IO_EXTERN __UNION_D(io_lcr2,IO_LCR2)		/* addr 73h */
__IO_STATIC __RESERVE_D(dmy_74_7B,8)		/* addr 74-7Bh */
__IO_EXTERN __UCHAR_D(IO_ILR1)			/* addr 7Ch */
__IO_EXTERN __UCHAR_D(IO_ILR2)			/* addr 7Dh */
__IO_EXTERN __UCHAR_D(IO_ILR3)			/* addr 7Eh */
__IO_STATIC __RESERVE_D(dmy_7F,1)		/* addr 7Fh */
