/*
 MB89680 Series I/O register declaration file V30L08
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
__IO_STATIC __RESERVE_D(dmy_05_06,2)		/* addr 05-06h */
__IO_EXTERN __UNION_D(io_sycc,IO_SYCC)		/* addr 07h */
__IO_EXTERN __UNION_D(io_stbc,IO_STBC)		/* addr 08h */
__IO_EXTERN __UCHAR_D(IO_WDTC)			/* addr 09h */
__IO_EXTERN __UNION_D(io_tbtc,IO_TBTC)		/* addr 0Ah */
__IO_EXTERN __UNION_D(io_wpcr,IO_WPCR)		/* addr 0Bh */
__IO_EXTERN __UNION_D(io_pdr3,IO_PDR3)		/* addr 0Ch */
__IO_EXTERN __UNION_D(io_ddr3,IO_DDR3)		/* addr 0Dh */
__IO_EXTERN __UNION_D(io_pdr4,IO_PDR4)		/* addr 0Eh */
__IO_EXTERN __UNION_D(io_bzcr,IO_BZCR)		/* addr 0Fh */
__IO_EXTERN __UNION_D(io_pdr5,IO_PDR5)		/* addr 10h */
__IO_STATIC __RESERVE_D(dmy_11,1)		/* addr 11h */
__IO_EXTERN __UNION_D(io_pdr6,IO_PDR6)		/* addr 12h */
__IO_EXTERN __UNION_D(io_ddr6,IO_DDR6)		/* addr 13h */
__IO_EXTERN __UNION_D(io_pdr7,IO_PDR7)		/* addr 14h */
__IO_STATIC __RESERVE_D(dmy_15,1)		/* addr 15h */
__IO_EXTERN __UNION_D(io_pdr8,IO_PDR8)		/* addr 16h */
__IO_STATIC __RESERVE_D(dmy_17,1)		/* addr 17h */
__IO_EXTERN __UNION_D(io_pdr9,IO_PDR9)		/* addr 18h */
__IO_EXTERN __UNION_D(io_ddr9,IO_DDR9)		/* addr 19h */
__IO_EXTERN __UNION_D(io_pdra,IO_PDRA)		/* addr 1Ah */
__IO_EXTERN __UNION_D(io_ddra,IO_DDRA)		/* addr 1Bh */
__IO_STATIC __RESERVE_D(dmy_1C_1D,2)		/* addr 1C-1Dh */
__IO_EXTERN __UNION_D(io_cntr,IO_CNTR)		/* addr 1Eh */
__IO_EXTERN __UCHAR_D(IO_COMR)			/* addr 1Fh */
__IO_STATIC __RESERVE_D(dmy_20_21,2)		/* addr 20-21h */
__IO_EXTERN __UNION_D(io_smr,IO_SMR)		/* addr 22h */
__IO_EXTERN __UNION_D(io_sfr,IO_SFR)		/* addr 23h */
__IO_EXTERN __UCHAR_D(IO_SBUF)			/* addr 24h */
__IO_EXTERN __UCHAR_D(IO_SDR)			/* addr 25h */
__IO_EXTERN __UNION_D(io_t2cr,IO_T2CR)		/* addr 26h */
__IO_EXTERN __UNION_D(io_t1cr,IO_T1CR)		/* addr 27h */
__IO_EXTERN __UNION_D(io_t12dr,IO_T12DR)	/* addr 28-29h */
__IO_EXTERN __UNION_D(io_modc,IO_MODC)		/* addr 2Ah */
__IO_EXTERN __UNION_D(io_moda,IO_MODA)		/* addr 2Bh */
__IO_STATIC __RESERVE_D(dmy_2C,1)		/* addr 2Ch */
__IO_EXTERN __UNION_D(io_adc1,IO_ADC1)		/* addr 2Dh */
__IO_EXTERN __UNION_D(io_adc2,IO_ADC2)		/* addr 2Eh */
__IO_EXTERN __UCHAR_D(IO_ADCD)			/* addr 2Fh */
__IO_EXTERN __UNION_D(io_eie1,IO_EIE1)		/* addr 30h */
__IO_EXTERN __UNION_D(io_eif1,IO_EIF1)		/* addr 31h */
__IO_EXTERN __UNION_D(io_eie2,IO_EIE2)		/* addr 32h */
__IO_EXTERN __UNION_D(io_eif2,IO_EIF2)		/* addr 33h */
__IO_EXTERN __UNION_D(io_mdc1,IO_MDC1)		/* addr 34h */
__IO_EXTERN __UNION_D(io_mdc2,IO_MDC2)		/* addr 35h */
__IO_EXTERN __UNION_D(io_mld,IO_MLD)		/* addr 36-37h */
__IO_EXTERN __UNION_D(io_smc,IO_SMC)		/* addr 38h */
__IO_EXTERN __UNION_D(io_src,IO_SRC)		/* addr 39h */
__IO_EXTERN __UNION_D(io_ssd,IO_SSD)		/* addr 3Ah */
__IO_EXTERN __CONST __UCHAR_D(IO_SIDR)		/* addr 3Bh */
__IO_EXTERN __UCHAR_D(IO_SODR)			/* addr 3Ch */
__IO_EXTERN __UNION_D(io_ssel,IO_SSEL)		/* addr 3Dh */
__IO_STATIC __RESERVE_D(dmy_3E_7B,62)		/* addr 3E-7Bh */
__IO_EXTERN __UCHAR_D(IO_ILR1)			/* addr 7Ch */
__IO_EXTERN __UCHAR_D(IO_ILR2)			/* addr 7Dh */
__IO_EXTERN __UCHAR_D(IO_ILR3)			/* addr 7Eh */
__IO_STATIC __RESERVE_D(dmy_7F,1)		/* addr 7Fh */
