/*
 MB89670/670A Series I/O register declaration file V30L08
 ALL RIGHTS RESERVED, COPYRIGHT (C) FUJITSU LIMITED 1998
 LICENSED MATERIAL - PROGRAM PROPERTY OF FUJITSU LIMITED
*/
#ifdef __FASM__
#include "_mb896xx_a.h"
#else
#include "_mb896xx.h"
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
__IO_EXTERN __UCHAR_D(IO_BCTR)			/* addr 05h */
__IO_STATIC __RESERVE_D(dmy_06,1)		/* addr 06h */
__IO_EXTERN __UNION_D(io_sycc,IO_SYCC)		/* addr 07h */
__IO_EXTERN __UNION_D(io_stbc,IO_STBC)		/* addr 08h */
__IO_EXTERN __UCHAR_D(IO_WDTC)			/* addr 09h */
__IO_EXTERN __UNION_D(io_tbtc,IO_TBTC)		/* addr 0Ah */
__IO_STATIC __RESERVE_D(dmy_0B,1)		/* addr 0Bh */
__IO_EXTERN __UNION_D(io_pdr3,IO_PDR3)		/* addr 0Ch */
__IO_EXTERN __UCHAR_D(IO_DDR3)			/* addr 0Dh */
__IO_EXTERN __UNION_D(io_pdr4,IO_PDR4)		/* addr 0Eh */
__IO_EXTERN __UCHAR_D(IO_DDR4)			/* addr 0Fh */
__IO_EXTERN __UNION_D(io_pdr5,IO_PDR5)		/* addr 10h */
__IO_EXTERN __CONST __UNION_D(io_pdr6,IO_PDR6)	/* addr 11h */
__IO_EXTERN __UNION_D(io_ppcr,IO_PPCR)		/* addr 12h */
__IO_EXTERN __UNION_D(io_pdr7,IO_PDR7)		/* addr 13h */
__IO_EXTERN __UNION_D(io_pdr8,IO_PDR8)		/* addr 14h */
__IO_EXTERN __UNION_D(io_bzcr,IO_BZCR)		/* addr 15h */
__IO_EXTERN __UNION_D(io_cntr_3,IO_CNTR_3)	/* addr 16h */
__IO_EXTERN __UCHAR_D(IO_COMP_3)		/* addr 17h */
__IO_EXTERN __UNION_D(io_tmcr,IO_TMCR)		/* addr 18h */
__IO_EXTERN __USHORT_D(IO_TCR)			/* addr 19-1Ah */
__IO_STATIC __RESERVE_D(dmy_1B,1)		/* addr 1Bh */
__IO_EXTERN __UNION_D(io_smr,IO_SMR)		/* addr 1Ch */
__IO_EXTERN __UCHAR_D(IO_SDR)			/* addr 1Dh */
__IO_STATIC __RESERVE_D(dmy_1E_1F,2)		/* addr 1E-1Fh */
__IO_EXTERN __UNION_D(io_adc1,IO_ADC1)		/* addr 20h */
__IO_EXTERN __UNION_D(io_adc2,IO_ADC2)		/* addr 21h */
__IO_EXTERN __UNION_D(io_add ,IO_ADD)		/* addr 22-23h */
__IO_EXTERN __UNION_D(io_t2cr,IO_T2CR)		/* addr 24h */
__IO_EXTERN __UNION_D(io_t1cr,IO_T1CR)		/* addr 25h */
__IO_EXTERN __UNION_D(io_t12dr,IO_T12DR)	/* addr 26-27h */
__IO_EXTERN __UNION_D(io_cntr1,IO_CNTR1)	/* addr 28h */
__IO_EXTERN __UNION_D(io_cntr2,IO_CNTR2)	/* addr 29h */
__IO_EXTERN __UNION_D(io_cntr3,IO_CNTR3)	/* addr 2Ah */
__IO_EXTERN __UCHAR_D(IO_COMR2)			/* addr 2Bh */
__IO_EXTERN __UCHAR_D(IO_COMR1)			/* addr 2Ch */
__IO_STATIC __RESERVE_D(dmy_2D_2F,3)		/* addr 2D-2Fh */
__IO_EXTERN __UNION_D(io_udcr,IO_UDCR)		/* addr 30-31h */
__IO_EXTERN __UNION_D(io_ccra1,IO_CCRA1)	/* addr 32h */
__IO_EXTERN __UNION_D(io_ccra2,IO_CCRA2)	/* addr 33h */
__IO_EXTERN __UNION_D(io_ccrb,IO_CCRB1)		/* addr 34h */
__IO_EXTERN __UNION_D(io_ccrb,IO_CCRB2)		/* addr 35h */
__IO_EXTERN __UNION_D(io_csr,IO_CSR1)		/* addr 36h */
__IO_EXTERN __UNION_D(io_csr,IO_CSR2)		/* addr 37h */
__IO_EXTERN __UNION_D(io_eic1,IO_EIC1)		/* addr 38h */
__IO_EXTERN __UNION_D(io_eic2,IO_EIC2)		/* addr 39h */
__IO_EXTERN __UNION_D(io_eie2,IO_EIE2)		/* addr 3Ah */
__IO_EXTERN __UNION_D(io_eif2,IO_EIF2)		/* addr 3Bh */
__IO_STATIC __RESERVE_D(dmy_3C_3F,4)		/* addr 3C-3Fh */
__IO_EXTERN __UNION_D(io_usmr,IO_USMR)		/* addr 40h */
__IO_EXTERN __UNION_D(io_uscr,IO_USCR)		/* addr 41h */
__IO_EXTERN __UNION_D(io_ustr,IO_USTR)		/* addr 42h */
__IO_EXTERN __UCHAR_D(IO_RXDR)			/* addr 43h */
__IO_STATIC __RESERVE_D(dmy_44,1)		/* addr 44h */
__IO_EXTERN __UCHAR_D(IO_RRDR)			/* addr 45h */
__IO_STATIC __RESERVE_D(dmy_46_47,2)		/* addr 46-47h */
#if defined(__CPU_MB89670A_SERIES)
__IO_EXTERN __UNION_D(io_cntr_n,IO_CNTR_4)	/* addr 48h */
__IO_EXTERN __UCHAR_D(IO_COMP_4)		/* addr 49h */
__IO_EXTERN __UNION_D(io_cntr_n,IO_CNTR_5)	/* addr 50h */
__IO_EXTERN __UCHAR_D(IO_COMP_5)		/* addr 51h */
__IO_EXTERN __UNION_D(io_cntr_n,IO_CNTR_6)	/* addr 52h */
__IO_EXTERN __UCHAR_D(IO_COMP_6)		/* addr 53h */
#else
#ifdef __IO_DEFINE
__IO_STATIC __RESERVE_D(dmy_48_4D,6)		/* addr 48-4Dh */
#endif
#endif
#ifdef __IO_DEFINE
__IO_STATIC __RESERVE_D(dmy_4E_7B,46)		/* addr 4E-7Bh */
#endif
__IO_EXTERN __UCHAR_D(IO_ILR1)			/* addr 7Ch */
__IO_EXTERN __UCHAR_D(IO_ILR2)			/* addr 7Dh */
__IO_EXTERN __UCHAR_D(IO_ILR3)			/* addr 7Eh */
__IO_STATIC __RESERVE_D(dmy_7F,1)		/* addr 7Fh */
