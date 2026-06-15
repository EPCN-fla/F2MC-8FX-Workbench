/*
 MB89690 Series I/O register declaration file V30L08
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
__IO_STATIC __RESERVE_D(dmy_0C_0D,2)		/* addr 0C-0Dh */
__IO_EXTERN __UNION_D(io_rsfr,IO_RSFR)		/* addr 0Eh */
__IO_EXTERN __UNION_D(io_pdr3,IO_PDR3)		/* addr 0Fh */
__IO_EXTERN __UNION_D(io_ddr3,IO_DDR3)		/* addr 10h */
__IO_STATIC __RESERVE_D(dmy_15,1)		/* addr 11h */
__IO_EXTERN __UNION_D(io_pdr4,IO_PDR4)		/* addr 12h */
__IO_EXTERN __UNION_D(io_ddr4,IO_DDR4)		/* addr 13h */
__IO_EXTERN __UNION_D(io_pdr5,IO_PDR5)		/* addr 14h */
__IO_EXTERN __UNION_D(io_pdr6,IO_PDR6)		/* addr 15h */
__IO_EXTERN __UNION_D(io_ddr6,IO_DDR6)		/* addr 16h */
__IO_STATIC __RESERVE_D(dmy_17,1)		/* addr 17h */
__IO_EXTERN __UNION_D(io_tmcr,IO_TMCR)		/* addr 18h */
__IO_EXTERN __USHORT_D(IO_TCR)			/* addr 19-1Ah */
__IO_STATIC __RESERVE_D(dmy_1B,1)		/* addr 1Bh */
__IO_EXTERN __UNION_D(io_smr,IO_SMR)		/* addr 1Ch */
__IO_EXTERN __UCHAR_D(IO_SDR)			/* addr 1Dh */
__IO_STATIC __RESERVE_D(dmy_1E_1F,2)		/* addr 1E-1Fh */
__IO_EXTERN __UNION_D(io_adc1,IO_ADC1)		/* addr 20h */
__IO_EXTERN __UNION_D(io_adc2,IO_ADC2)		/* addr 21h */
__IO_EXTERN __UNION_D(io_add ,IO_ADD)		/* addr 22-23h */
__IO_EXTERN __UNION_D(io_eic1,IO_EIC1)		/* addr 24h */
__IO_EXTERN __UNION_D(io_eic2,IO_EIC2)		/* addr 25h */
__IO_EXTERN __UNION_D(io_eisr,IO_EISR)		/* addr 26h */
__IO_STATIC __RESERVE_D(dmy_27,1)		/* addr 27h */
__IO_EXTERN __UNION_D(io_cntr1,IO_CNTR11)	/* addr 28h */
__IO_EXTERN __UNION_D(io_cntr2,IO_CNTR12)	/* addr 29h */
__IO_EXTERN __UNION_D(io_cntr3,IO_CNTR13)	/* addr 2Ah */
__IO_EXTERN __UCHAR_D(IO_COMR11)		/* addr 2Bh */
__IO_EXTERN __UCHAR_D(IO_COMR12)		/* addr 2Ch */
__IO_EXTERN __UNION_D(io_smc,IO_SMC1)		/* addr 2Dh */
__IO_EXTERN __UNION_D(io_src,IO_SRC1)		/* addr 2Eh */
__IO_EXTERN __UNION_D(io_ssd,IO_SSD1)		/* addr 2Fh */
__IO_EXTERN __UCHAR_D(IO_SIDR1)			/* addr 30h */
__IO_EXTERN __UNION_D(io_cntr1,IO_CNTR21)	/* addr 31h */
__IO_EXTERN __UNION_D(io_cntr2,IO_CNTR22)	/* addr 32h */
__IO_EXTERN __UNION_D(io_cntr3,IO_CNTR23)	/* addr 33h */
__IO_EXTERN __UCHAR_D(IO_COMR21)		/* addr 34h */
__IO_EXTERN __UCHAR_D(IO_COMR22)		/* addr 35h */
__IO_EXTERN __UNION_D(io_smc,IO_SMC2)		/* addr 36h */
__IO_EXTERN __UNION_D(io_src,IO_SRC2)		/* addr 37h */
__IO_EXTERN __UNION_D(io_ssd,IO_SSD2)		/* addr 38h */
__IO_EXTERN __UCHAR_D(IO_SIDR2)			/* addr 39h */
__IO_STATIC __RESERVE_D(dmy_3A_3F,6)		/* addr 3A-3Fh */
__IO_EXTERN __UNION_D(io_ctlreg1,IO_CTLREG1)	/* addr 40h */
__IO_EXTERN __UNION_D(io_ctlreg2,IO_CTLREG2)	/* addr 41h */
__IO_EXTERN __UCHAR_D(IO_TBUFFREG)		/* addr 42h */
__IO_EXTERN __UNION_D(io_mlreg,IO_MLREG)	/* addr 43h */
__IO_EXTERN __UNION_D(io_statreg1,IO_STATREG1)	/* addr 44h */
__IO_EXTERN __UNION_D(io_statreg2,IO_STATREG2)	/* addr 45h */
__IO_EXTERN __UCHAR_D(IO_RBUFFREG)		/* addr 46h */
__IO_EXTERN __UCHAR_D(IO_RLREG)			/* addr 47h */
__IO_STATIC __RESERVE_D(dmy_48_4F,8)		/* addr 48-4Fh */
__IO_EXTERN __UNION_D(io_p0up,IO_P0UP)		/* addr 50h */
__IO_EXTERN __UNION_D(io_p1up,IO_P1UP)		/* addr 51h */
__IO_STATIC __RESERVE_D(dmy_52,1)		/* addr 52h */
__IO_EXTERN __UNION_D(io_p3up,IO_P3UP)		/* addr 53h */
__IO_EXTERN __UNION_D(io_p4up,IO_P4UP)		/* addr 54h */
__IO_STATIC __RESERVE_D(dmy_55,1)		/* addr 55h */
__IO_EXTERN __UNION_D(io_p6up,IO_P6UP)		/* addr 56h */
__IO_STATIC __RESERVE_D(dmy_57_7B,37)		/* addr 57-7Bh */
__IO_EXTERN __UCHAR_D(IO_ILR1)			/* addr 7Ch */
__IO_EXTERN __UCHAR_D(IO_ILR2)			/* addr 7Dh */
__IO_EXTERN __UCHAR_D(IO_ILR3)			/* addr 7Eh */
__IO_STATIC __RESERVE_D(dmy_7F,1)		/* addr 7Fh */
