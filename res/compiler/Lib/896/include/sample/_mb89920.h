/*
 MB89920 Series I/O register declaration file V30L08
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
__IO_STATIC __RESERVE_D(dmy_04_07,4)		/* addr 04-07h */
__IO_EXTERN __UNION_D(io_stbc,IO_STBC)		/* addr 08h */
__IO_EXTERN __UCHAR_D(IO_WDTC)			/* addr 09h */
__IO_EXTERN __UNION_D(io_tbtc,IO_TBTC)		/* addr 0Ah */
__IO_EXTERN __UNION_D(io_lvrc,IO_LVRC)		/* addr 0Bh */
__IO_EXTERN __UNION_D(io_pdr3,IO_PDR3)		/* addr 0Ch */
__IO_EXTERN __UCHAR_D(IO_DDR3)			/* addr 0Dh */
__IO_EXTERN __UNION_D(io_pdr4,IO_PDR4)		/* addr 0Eh */
__IO_EXTERN __UNION_D(io_pdr5,IO_PDR5)		/* addr 0Fh */
__IO_EXTERN __UNION_D(io_pdr6,IO_PDR6)		/* addr 10h */
__IO_EXTERN __UNION_D(io_pdr7,IO_PDR7)		/* addr 11h */
__IO_EXTERN __UNION_D(io_pdr8,IO_PDR8)		/* addr 12h */
__IO_EXTERN __UNION_D(io_pdr9,IO_PDR9)		/* addr 13h */
__IO_EXTERN __UCHAR_D(IO_DDR9)			/* addr 14h */
__IO_EXTERN __UNION_D(io_pdr2,IO_PDR2)		/* addr 15h */
__IO_EXTERN __UCHAR_D(IO_DDR2)			/* addr 16h */
__IO_EXTERN __UNION_D(io_bzcr,IO_BZCR)		/* addr 17h */
__IO_EXTERN __UNION_D(io_adc1,IO_ADC1)		/* addr 18h */
__IO_EXTERN __UNION_D(io_adc2,IO_ADC2)		/* addr 19h */
__IO_EXTERN __UNION_D(io_add,IO_ADD)		/* addr 1A-1Bh */
__IO_EXTERN __UNION_D(io_smr,IO_SMR)		/* addr 1Ch */
__IO_EXTERN __UCHAR_D(IO_SDR)			/* addr 1Dh */
__IO_STATIC __RESERVE_D(dmy_1E,1)		/* addr 1Eh */
__IO_EXTERN __UCHAR_D(IO_PCR1)			/* addr 1Fh */
__IO_EXTERN __UNION_D(io_cntr1,IO_CNTR1)	/* addr 20h */
__IO_EXTERN __UNION_D(io_cntr2,IO_CNTR2)	/* addr 21h */
__IO_EXTERN __UNION_D(io_cntr3,IO_CNTR3)	/* addr 22h */
__IO_EXTERN __UCHAR_D(IO_COMR2)			/* addr 23h */
__IO_EXTERN __UCHAR_D(IO_COMR1)			/* addr 24h */
__IO_STATIC __RESERVE_D(dmy_25_27,3)		/* addr 25-27h */
__IO_EXTERN __UNION_D(io_tmcr,IO_TMCR)		/* addr 28h */
__IO_EXTERN __USHORT_D(IO_TCR)			/* addr 29-2Ah */
__IO_EXTERN __UNION_D(io_opcr,IO_OPCR)		/* addr 2Bh */
__IO_EXTERN __USHORT_D(IO_CPR0)			/* addr 2C-2Dh */
__IO_EXTERN __USHORT_D(IO_CPR1)			/* addr 2E-2Fh */
__IO_EXTERN __UNION_D(io_iccr,IO_ICCR)		/* addr 30h */
__IO_EXTERN __UNION_D(io_icic,IO_ICIC)		/* addr 31h */
__IO_EXTERN __USHORT_D(IO_ICR0)			/* addr 32-33h */
__IO_EXTERN __USHORT_D(IO_ICR1)			/* addr 34-35h */
__IO_STATIC __RESERVE_D(dmy_36_37,2)		/* addr 36-37h */
__IO_EXTERN __UNION_D(io_eic1,IO_EIC1)		/* addr 38h */
__IO_EXTERN __UNION_D(io_eic2,IO_EIC2)		/* addr 39h */
__IO_STATIC __RESERVE_D(dmy_3A_3F,6)		/* addr 3A-3Fh */
__IO_EXTERN __UNION_D(io_usmr,IO_USMR)		/* addr 40h */
__IO_EXTERN __UNION_D(io_uscr,IO_USCR)		/* addr 41h */
__IO_EXTERN __UNION_D(io_ustr,IO_USTR)		/* addr 42h */
__IO_EXTERN __UCHAR_D(IO_RXDR)			/* addr 43h */
__IO_STATIC __RESERVE_D(dmy_44,1)		/* addr 44h */
__IO_EXTERN __UCHAR_D(IO_RRDR)			/* addr 45h */
__IO_STATIC __RESERVE_D(dmy_46_5F,26)		/* addr 46-5Fh */
__IO_EXTERN __UNION_D(io_vram,IO_VRAM)		/* addr 60-6Dh */
__IO_STATIC __RESERVE_D(dmy_6E_6F,2)		/* addr 6E-6Fh */
__IO_EXTERN __UNION_D(io_lcr ,IO_LCR1)		/* addr 70h */
__IO_EXTERN __UNION_D(io_lcr2,IO_LCR2)		/* addr 71h */
__IO_EXTERN __UNION_D(io_lcr3,IO_LCR3)		/* addr 72h */
__IO_STATIC __RESERVE_D(dmy_73_7B,9)		/* addr 73-7Bh */
__IO_EXTERN __UCHAR_D(IO_ILR1)			/* addr 7Ch */
__IO_EXTERN __UCHAR_D(IO_ILR2)			/* addr 7Dh */
__IO_EXTERN __UCHAR_D(IO_ILR3)			/* addr 7Eh */
__IO_STATIC __RESERVE_D(dmy_7F,1)		/* addr 7Fh */
