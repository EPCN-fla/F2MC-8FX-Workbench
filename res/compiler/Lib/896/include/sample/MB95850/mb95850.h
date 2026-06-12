/*
 MB95850 Series I/O register declaration file V01L02
 ALL RIGHTS RESERVED, COPYRIGHT (C) FUJITSU SEMICONDUCTOR LIMITED 2012
 LICENSED MATERIAL - PROGRAM PROPERTY OF FUJITSU SEMICONDUCTOR LIMITED
*/

#ifdef  __IO_NEAR
#ifdef  __IO_FAR
#error "__IO_NEAR and __IO_FAR must not be defined at the same time"
#else
#define ___IOWIDTH __near
#endif
#else
#ifdef __IO_FAR
#define ___IOWIDTH __far
#else                               /* specified by memory model */
#define ___IOWIDTH
#endif
#endif

#ifdef  __IO_DEFINE
#define __IO_EXTERN __io
#define __IO_EXTENDED volatile ___IOWIDTH
#else
#define __IO_EXTERN   extern __io      /* for data, which can have __io */
#define __IO_EXTENDED extern volatile ___IOWIDTH
#endif

typedef unsigned char        __BYTE;
typedef unsigned short       __WORD;
typedef unsigned long        __LWORD;
typedef const unsigned short __WORD_READ;


#ifdef __IO_DEFINE
#pragma segment IO=IO_PDR0, locate=0x0
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	RESV0:1;
			__BYTE	RESV1:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	P04:1;
			__BYTE	P05:1;
			__BYTE	P06:1;
			__BYTE	P07:1;
	} bit;
	struct {
			__BYTE	RESV0:1;
			__BYTE	RESV1:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	P04:1;
			__BYTE	P05:1;
			__BYTE	P06:1;
			__BYTE	P07:1;
	} bitc;
} PDR0STR;

__IO_EXTERN	  PDR0STR	IO_PDR0;
#define	_pdr0		(IO_PDR0)
#define	PDR0		(IO_PDR0.byte)
#define	PDR0_P04  	(IO_PDR0.bit.P04)
#define	PDR0_P05  	(IO_PDR0.bit.P05)
#define	PDR0_P06  	(IO_PDR0.bit.P06)
#define	PDR0_P07  	(IO_PDR0.bit.P07)

#ifdef __IO_DEFINE
#pragma segment IO=IO_DDR0, locate=0x1
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	RESV0:1;
			__BYTE	RESV1:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	P04:1;
			__BYTE	P05:1;
			__BYTE	P06:1;
			__BYTE	P07:1;
	} bit;
	struct {
			__BYTE	RESV0:1;
			__BYTE	RESV1:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	P04:1;
			__BYTE	P05:1;
			__BYTE	P06:1;
			__BYTE	P07:1;
	} bitc;
} DDR0STR;

__IO_EXTERN	  DDR0STR	IO_DDR0;
#define	_ddr0		(IO_DDR0)
#define	DDR0		(IO_DDR0.byte)
#define	DDR0_P04  	(IO_DDR0.bit.P04)
#define	DDR0_P05  	(IO_DDR0.bit.P05)
#define	DDR0_P06  	(IO_DDR0.bit.P06)
#define	DDR0_P07  	(IO_DDR0.bit.P07)

#ifdef __IO_DEFINE
#pragma segment IO=IO_PDR1, locate=0x2
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	P10:1;
			__BYTE	RESV1:1;
			__BYTE	RESV2:1;
			__BYTE	P13:1;
			__BYTE	P14:1;
			__BYTE	P15:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	P10:1;
			__BYTE	RESV1:1;
			__BYTE	RESV2:1;
			__BYTE	P13:1;
			__BYTE	P14:1;
			__BYTE	P15:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} PDR1STR;

__IO_EXTERN	  PDR1STR	IO_PDR1;
#define	_pdr1		(IO_PDR1)
#define	PDR1		(IO_PDR1.byte)
#define	PDR1_P10  	(IO_PDR1.bit.P10)
#define	PDR1_P13  	(IO_PDR1.bit.P13)
#define	PDR1_P14  	(IO_PDR1.bit.P14)
#define	PDR1_P15  	(IO_PDR1.bit.P15)

#ifdef __IO_DEFINE
#pragma segment IO=IO_DDR1, locate=0x3
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	P10:1;
			__BYTE	RESV1:1;
			__BYTE	RESV2:1;
			__BYTE	P13:1;
			__BYTE	P14:1;
			__BYTE	P15:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	P10:1;
			__BYTE	RESV1:1;
			__BYTE	RESV2:1;
			__BYTE	P13:1;
			__BYTE	P14:1;
			__BYTE	P15:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} DDR1STR;

__IO_EXTERN	  DDR1STR	IO_DDR1;
#define	_ddr1		(IO_DDR1)
#define	DDR1		(IO_DDR1.byte)
#define	DDR1_P10  	(IO_DDR1.bit.P10)
#define	DDR1_P13  	(IO_DDR1.bit.P13)
#define	DDR1_P14  	(IO_DDR1.bit.P14)
#define	DDR1_P15  	(IO_DDR1.bit.P15)

#ifdef __IO_DEFINE
#pragma segment IO=IO_WATR, locate=0x5
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	MWT0:1;
			__BYTE	MWT1:1;
			__BYTE	MWT2:1;
			__BYTE	MWT3:1;
			__BYTE	SWT0:1;
			__BYTE	SWT1:1;
			__BYTE	SWT2:1;
			__BYTE	SWT3:1;
	} bit;
	struct {
			__BYTE	MWT0:1;
			__BYTE	MWT1:1;
			__BYTE	MWT2:1;
			__BYTE	MWT3:1;
			__BYTE	SWT0:1;
			__BYTE	SWT1:1;
			__BYTE	SWT2:1;
			__BYTE	SWT3:1;
	} bitc;
} WATRSTR;

__IO_EXTERN	  WATRSTR	IO_WATR;
#define	_watr		(IO_WATR)
#define	WATR		(IO_WATR.byte)
#define	WATR_MWT0  	(IO_WATR.bit.MWT0)
#define	WATR_MWT1  	(IO_WATR.bit.MWT1)
#define	WATR_MWT2  	(IO_WATR.bit.MWT2)
#define	WATR_MWT3  	(IO_WATR.bit.MWT3)
#define	WATR_SWT0  	(IO_WATR.bit.SWT0)
#define	WATR_SWT1  	(IO_WATR.bit.SWT1)
#define	WATR_SWT2  	(IO_WATR.bit.SWT2)
#define	WATR_SWT3  	(IO_WATR.bit.SWT3)

#ifdef __IO_DEFINE
#pragma segment IO=IO_PLLC, locate=0x6
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	RESV0:1;
			__BYTE	RESV1:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	MPRDY:1;
			__BYTE	MPMC0:1;
			__BYTE	MPMC1:1;
			__BYTE	MPEN:1;
	} bit;
	struct {
			__BYTE	RESV0:1;
			__BYTE	RESV1:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	MPRDY:1;
			__BYTE	MPMC0:1;
			__BYTE	MPMC1:1;
			__BYTE	MPEN:1;
	} bitc;
} PLLCSTR;

__IO_EXTERN	  PLLCSTR	IO_PLLC;
#define	_pllc		(IO_PLLC)
#define	PLLC		(IO_PLLC.byte)
#define	PLLC_MPRDY  	(IO_PLLC.bit.MPRDY)
#define	PLLC_MPMC0  	(IO_PLLC.bit.MPMC0)
#define	PLLC_MPMC1  	(IO_PLLC.bit.MPMC1)
#define	PLLC_MPEN  	(IO_PLLC.bit.MPEN)

#ifdef __IO_DEFINE
#pragma segment IO=IO_SYCC, locate=0x7
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	DIV0:1;
			__BYTE	DIV1:1;
			__BYTE	SCS0:1;
			__BYTE	SCS1:1;
			__BYTE	SCS2:1;
			__BYTE	SCM0:1;
			__BYTE	SCM1:1;
			__BYTE	SCM2:1;
	} bit;
	struct {
			__BYTE	DIV0:1;
			__BYTE	DIV1:1;
			__BYTE	SCS0:1;
			__BYTE	SCS1:1;
			__BYTE	SCS2:1;
			__BYTE	SCM0:1;
			__BYTE	SCM1:1;
			__BYTE	SCM2:1;
	} bitc;
} SYCCSTR;

__IO_EXTERN	  SYCCSTR	IO_SYCC;
#define	_sycc		(IO_SYCC)
#define	SYCC		(IO_SYCC.byte)
#define	SYCC_DIV0  	(IO_SYCC.bit.DIV0)
#define	SYCC_DIV1  	(IO_SYCC.bit.DIV1)
#define	SYCC_SCS0  	(IO_SYCC.bit.SCS0)
#define	SYCC_SCS1  	(IO_SYCC.bit.SCS1)
#define	SYCC_SCS2  	(IO_SYCC.bit.SCS2)
#define	SYCC_SCM0  	(IO_SYCC.bit.SCM0)
#define	SYCC_SCM1  	(IO_SYCC.bit.SCM1)
#define	SYCC_SCM2  	(IO_SYCC.bit.SCM2)

#ifdef __IO_DEFINE
#pragma segment IO=IO_STBC, locate=0x8
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	RESV0:1;
			__BYTE	RESV1:1;
			__BYTE	RESV2:1;
			__BYTE	TMD:1;
			__BYTE	SRST:1;
			__BYTE	SPL:1;
			__BYTE	SLP:1;
			__BYTE	STP:1;
	} bit;
	struct {
			__BYTE	RESV0:1;
			__BYTE	RESV1:1;
			__BYTE	RESV2:1;
			__BYTE	TMD:1;
			__BYTE	SRST:1;
			__BYTE	SPL:1;
			__BYTE	SLP:1;
			__BYTE	STP:1;
	} bitc;
} STBCSTR;

__IO_EXTERN	  STBCSTR	IO_STBC;
#define	_stbc		(IO_STBC)
#define	STBC		(IO_STBC.byte)
#define	STBC_TMD  	(IO_STBC.bit.TMD)
#define	STBC_SRST  	(IO_STBC.bit.SRST)
#define	STBC_SPL  	(IO_STBC.bit.SPL)
#define	STBC_SLP  	(IO_STBC.bit.SLP)
#define	STBC_STP  	(IO_STBC.bit.STP)

#ifdef __IO_DEFINE
#pragma segment IO=IO_RSRR, locate=0x9
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	SWR:1;
			__BYTE	HWR:1;
			__BYTE	PONR:1;
			__BYTE	WDTR:1;
			__BYTE	EXTS:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	SWR:1;
			__BYTE	HWR:1;
			__BYTE	PONR:1;
			__BYTE	WDTR:1;
			__BYTE	EXTS:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} RSRRSTR;

__IO_EXTERN	 const  RSRRSTR	IO_RSRR;
#define	_rsrr		(IO_RSRR)
#define	RSRR		(IO_RSRR.byte)
#define	RSRR_SWR  	(IO_RSRR.bit.SWR)
#define	RSRR_HWR  	(IO_RSRR.bit.HWR)
#define	RSRR_PONR  	(IO_RSRR.bit.PONR)
#define	RSRR_WDTR  	(IO_RSRR.bit.WDTR)
#define	RSRR_EXTS  	(IO_RSRR.bit.EXTS)

#ifdef __IO_DEFINE
#pragma segment IO=IO_TBTC, locate=0xA
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	TCLR:1;
			__BYTE	TBC0:1;
			__BYTE	TBC1:1;
			__BYTE	TBC2:1;
			__BYTE	TBC3:1;
			__BYTE	RESV5:1;
			__BYTE	TBIE:1;
			__BYTE	TBIF:1;
	} bit;
	struct {
			__BYTE	TCLR:1;
			__BYTE	TBC0:1;
			__BYTE	TBC1:1;
			__BYTE	TBC2:1;
			__BYTE	TBC3:1;
			__BYTE	RESV5:1;
			__BYTE	TBIE:1;
			__BYTE	TBIF:1;
	} bitc;
} TBTCSTR;

__IO_EXTERN	  TBTCSTR	IO_TBTC;
#define	_tbtc		(IO_TBTC)
#define	TBTC		(IO_TBTC.byte)
#define	TBTC_TCLR  	(IO_TBTC.bit.TCLR)
#define	TBTC_TBC0  	(IO_TBTC.bit.TBC0)
#define	TBTC_TBC1  	(IO_TBTC.bit.TBC1)
#define	TBTC_TBC2  	(IO_TBTC.bit.TBC2)
#define	TBTC_TBC3  	(IO_TBTC.bit.TBC3)
#define	TBTC_TBIE  	(IO_TBTC.bit.TBIE)
#define	TBTC_TBIF  	(IO_TBTC.bit.TBIF)

#ifdef __IO_DEFINE
#pragma segment IO=IO_WPCR, locate=0xB
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	WCLR:1;
			__BYTE	WTC0:1;
			__BYTE	WTC1:1;
			__BYTE	WTC2:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	WTIE:1;
			__BYTE	WTIF:1;
	} bit;
	struct {
			__BYTE	WCLR:1;
			__BYTE	WTC0:1;
			__BYTE	WTC1:1;
			__BYTE	WTC2:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	WTIE:1;
			__BYTE	WTIF:1;
	} bitc;
} WPCRSTR;

__IO_EXTERN	  WPCRSTR	IO_WPCR;
#define	_wpcr		(IO_WPCR)
#define	WPCR		(IO_WPCR.byte)
#define	WPCR_WCLR  	(IO_WPCR.bit.WCLR)
#define	WPCR_WTC0  	(IO_WPCR.bit.WTC0)
#define	WPCR_WTC1  	(IO_WPCR.bit.WTC1)
#define	WPCR_WTC2  	(IO_WPCR.bit.WTC2)
#define	WPCR_WTIE  	(IO_WPCR.bit.WTIE)
#define	WPCR_WTIF  	(IO_WPCR.bit.WTIF)

#ifdef __IO_DEFINE
#pragma segment IO=IO_WDTC, locate=0xC
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	WTE0:1;
			__BYTE	WTE1:1;
			__BYTE	WTE2:1;
			__BYTE	WTE3:1;
			__BYTE	HWWDT:1;
			__BYTE	CSP:1;
			__BYTE	CS0:1;
			__BYTE	CS1:1;
	} bit;
	struct {
			__BYTE	WTE0:1;
			__BYTE	WTE1:1;
			__BYTE	WTE2:1;
			__BYTE	WTE3:1;
			__BYTE	HWWDT:1;
			__BYTE	CSP:1;
			__BYTE	CS0:1;
			__BYTE	CS1:1;
	} bitc;
} WDTCSTR;

__IO_EXTERN	  WDTCSTR	IO_WDTC;
#define	_wdtc		(IO_WDTC)
#define	WDTC		(IO_WDTC.byte)
#define	WDTC_WTE0  	(IO_WDTC.bit.WTE0)
#define	WDTC_WTE1  	(IO_WDTC.bit.WTE1)
#define	WDTC_WTE2  	(IO_WDTC.bit.WTE2)
#define	WDTC_WTE3  	(IO_WDTC.bit.WTE3)
#define	WDTC_HWWDT  	(IO_WDTC.bit.HWWDT)
#define	WDTC_CSP  	(IO_WDTC.bit.CSP)
#define	WDTC_CS0  	(IO_WDTC.bit.CS0)
#define	WDTC_CS1  	(IO_WDTC.bit.CS1)

#ifdef __IO_DEFINE
#pragma segment IO=IO_SYCC2, locate=0xD
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	MCRE:1;
			__BYTE	SCRE:1;
			__BYTE	MOSCE:1;
			__BYTE	SOSCE:1;
			__BYTE	MCRDY:1;
			__BYTE	SCRDY:1;
			__BYTE	MRDY:1;
			__BYTE	SRDY:1;
	} bit;
	struct {
			__BYTE	MCRE:1;
			__BYTE	SCRE:1;
			__BYTE	MOSCE:1;
			__BYTE	SOSCE:1;
			__BYTE	MCRDY:1;
			__BYTE	SCRDY:1;
			__BYTE	MRDY:1;
			__BYTE	SRDY:1;
	} bitc;
} SYCC2STR;

__IO_EXTERN	  SYCC2STR	IO_SYCC2;
#define	_sycc2		(IO_SYCC2)
#define	SYCC2		(IO_SYCC2.byte)
#define	SYCC2_MCRE  	(IO_SYCC2.bit.MCRE)
#define	SYCC2_SCRE  	(IO_SYCC2.bit.SCRE)
#define	SYCC2_MOSCE  	(IO_SYCC2.bit.MOSCE)
#define	SYCC2_SOSCE  	(IO_SYCC2.bit.SOSCE)
#define	SYCC2_MCRDY  	(IO_SYCC2.bit.MCRDY)
#define	SYCC2_SCRDY  	(IO_SYCC2.bit.SCRDY)
#define	SYCC2_MRDY  	(IO_SYCC2.bit.MRDY)
#define	SYCC2_SRDY  	(IO_SYCC2.bit.SRDY)

#ifdef __IO_DEFINE
#pragma segment IO=IO_PDR4, locate=0x12
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	RESV0:1;
			__BYTE	RESV1:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	P46:1;
			__BYTE	P47:1;
	} bit;
	struct {
			__BYTE	RESV0:1;
			__BYTE	RESV1:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	P46:1;
			__BYTE	P47:1;
	} bitc;
} PDR4STR;

__IO_EXTERN	  PDR4STR	IO_PDR4;
#define	_pdr4		(IO_PDR4)
#define	PDR4		(IO_PDR4.byte)
#define	PDR4_P46  	(IO_PDR4.bit.P46)
#define	PDR4_P47  	(IO_PDR4.bit.P47)

#ifdef __IO_DEFINE
#pragma segment IO=IO_DDR4, locate=0x13
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	RESV0:1;
			__BYTE	RESV1:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	P46:1;
			__BYTE	P47:1;
	} bit;
	struct {
			__BYTE	RESV0:1;
			__BYTE	RESV1:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	P46:1;
			__BYTE	P47:1;
	} bitc;
} DDR4STR;

__IO_EXTERN	  DDR4STR	IO_DDR4;
#define	_ddr4		(IO_DDR4)
#define	DDR4		(IO_DDR4.byte)
#define	DDR4_P46  	(IO_DDR4.bit.P46)
#define	DDR4_P47  	(IO_DDR4.bit.P47)

#ifdef __IO_DEFINE
#pragma segment IO=IO_PDR6, locate=0x16
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	RESV0:1;
			__BYTE	RESV1:1;
			__BYTE	RESV2:1;
			__BYTE	P63:1;
			__BYTE	RESV4:1;
			__BYTE	P65:1;
			__BYTE	P66:1;
			__BYTE	P67:1;
	} bit;
	struct {
			__BYTE	RESV0:1;
			__BYTE	RESV1:1;
			__BYTE	RESV2:1;
			__BYTE	P63:1;
			__BYTE	RESV4:1;
			__BYTE	P65:1;
			__BYTE	P66:1;
			__BYTE	P67:1;
	} bitc;
} PDR6STR;

__IO_EXTERN	  PDR6STR	IO_PDR6;
#define	_pdr6		(IO_PDR6)
#define	PDR6		(IO_PDR6.byte)
#define	PDR6_P63  	(IO_PDR6.bit.P63)
#define	PDR6_P65  	(IO_PDR6.bit.P65)
#define	PDR6_P66  	(IO_PDR6.bit.P66)
#define	PDR6_P67  	(IO_PDR6.bit.P67)

#ifdef __IO_DEFINE
#pragma segment IO=IO_DDR6, locate=0x17
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	RESV0:1;
			__BYTE	RESV1:1;
			__BYTE	RESV2:1;
			__BYTE	P63:1;
			__BYTE	RESV4:1;
			__BYTE	P65:1;
			__BYTE	P66:1;
			__BYTE	P67:1;
	} bit;
	struct {
			__BYTE	RESV0:1;
			__BYTE	RESV1:1;
			__BYTE	RESV2:1;
			__BYTE	P63:1;
			__BYTE	RESV4:1;
			__BYTE	P65:1;
			__BYTE	P66:1;
			__BYTE	P67:1;
	} bitc;
} DDR6STR;

__IO_EXTERN	  DDR6STR	IO_DDR6;
#define	_ddr6		(IO_DDR6)
#define	DDR6		(IO_DDR6.byte)
#define	DDR6_P63  	(IO_DDR6.bit.P63)
#define	DDR6_P65  	(IO_DDR6.bit.P65)
#define	DDR6_P66  	(IO_DDR6.bit.P66)
#define	DDR6_P67  	(IO_DDR6.bit.P67)

#ifdef __IO_DEFINE
#pragma segment IO=IO_PDR7, locate=0x18
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	P70:1;
			__BYTE	P71:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	P70:1;
			__BYTE	P71:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} PDR7STR;

__IO_EXTERN	  PDR7STR	IO_PDR7;
#define	_pdr7		(IO_PDR7)
#define	PDR7		(IO_PDR7.byte)
#define	PDR7_P70  	(IO_PDR7.bit.P70)
#define	PDR7_P71  	(IO_PDR7.bit.P71)

#ifdef __IO_DEFINE
#pragma segment IO=IO_DDR7, locate=0x19
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	P70:1;
			__BYTE	P71:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	P70:1;
			__BYTE	P71:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} DDR7STR;

__IO_EXTERN	  DDR7STR	IO_DDR7;
#define	_ddr7		(IO_DDR7)
#define	DDR7		(IO_DDR7.byte)
#define	DDR7_P70  	(IO_DDR7.bit.P70)
#define	DDR7_P71  	(IO_DDR7.bit.P71)

#ifdef __IO_DEFINE
#pragma segment IO=IO_STBC2, locate=0x1C
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	DSTBYX:1;
			__BYTE	RESV1:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	DSTBYX:1;
			__BYTE	RESV1:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} STBC2STR;

__IO_EXTERN	  STBC2STR	IO_STBC2;
#define	_stbc2		(IO_STBC2)
#define	STBC2		(IO_STBC2.byte)
#define	STBC2_DSTBYX  	(IO_STBC2.bit.DSTBYX)

#ifdef __IO_DEFINE
#pragma segment IO=IO_PDRF, locate=0x28
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	PF0:1;
			__BYTE	PF1:1;
			__BYTE	PF2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	PF0:1;
			__BYTE	PF1:1;
			__BYTE	PF2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} PDRFSTR;

__IO_EXTERN	  PDRFSTR	IO_PDRF;
#define	_pdrf		(IO_PDRF)
#define	PDRF		(IO_PDRF.byte)
#define	PDRF_PF0  	(IO_PDRF.bit.PF0)
#define	PDRF_PF1  	(IO_PDRF.bit.PF1)
#define	PDRF_PF2  	(IO_PDRF.bit.PF2)

#ifdef __IO_DEFINE
#pragma segment IO=IO_DDRF, locate=0x29
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	PF0:1;
			__BYTE	PF1:1;
			__BYTE	PF2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	PF0:1;
			__BYTE	PF1:1;
			__BYTE	PF2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} DDRFSTR;

__IO_EXTERN	  DDRFSTR	IO_DDRF;
#define	_ddrf		(IO_DDRF)
#define	DDRF		(IO_DDRF.byte)
#define	DDRF_PF0  	(IO_DDRF.bit.PF0)
#define	DDRF_PF1  	(IO_DDRF.bit.PF1)
#define	DDRF_PF2  	(IO_DDRF.bit.PF2)

#ifdef __IO_DEFINE
#pragma segment IO=IO_PDRG, locate=0x2A
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	RESV0:1;
			__BYTE	PG1:1;
			__BYTE	PG2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	RESV0:1;
			__BYTE	PG1:1;
			__BYTE	PG2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} PDRGSTR;

__IO_EXTERN	  PDRGSTR	IO_PDRG;
#define	_pdrg		(IO_PDRG)
#define	PDRG		(IO_PDRG.byte)
#define	PDRG_PG1  	(IO_PDRG.bit.PG1)
#define	PDRG_PG2  	(IO_PDRG.bit.PG2)

#ifdef __IO_DEFINE
#pragma segment IO=IO_DDRG, locate=0x2B
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	RESV0:1;
			__BYTE	PG1:1;
			__BYTE	PG2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	RESV0:1;
			__BYTE	PG1:1;
			__BYTE	PG2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} DDRGSTR;

__IO_EXTERN	  DDRGSTR	IO_DDRG;
#define	_ddrg		(IO_DDRG)
#define	DDRG		(IO_DDRG.byte)
#define	DDRG_PG1  	(IO_DDRG.bit.PG1)
#define	DDRG_PG2  	(IO_DDRG.bit.PG2)

#ifdef __IO_DEFINE
#pragma segment IO=IO_PUL0, locate=0x2C
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	RESV0:1;
			__BYTE	RESV1:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	P04:1;
			__BYTE	P05:1;
			__BYTE	P06:1;
			__BYTE	P07:1;
	} bit;
	struct {
			__BYTE	RESV0:1;
			__BYTE	RESV1:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	P04:1;
			__BYTE	P05:1;
			__BYTE	P06:1;
			__BYTE	P07:1;
	} bitc;
} PUL0STR;

__IO_EXTERN	  PUL0STR	IO_PUL0;
#define	_pul0		(IO_PUL0)
#define	PUL0		(IO_PUL0.byte)
#define	PUL0_P04  	(IO_PUL0.bit.P04)
#define	PUL0_P05  	(IO_PUL0.bit.P05)
#define	PUL0_P06  	(IO_PUL0.bit.P06)
#define	PUL0_P07  	(IO_PUL0.bit.P07)

#ifdef __IO_DEFINE
#pragma segment IO=IO_PUL1, locate=0x2D
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	P10:1;
			__BYTE	RESV1:1;
			__BYTE	RESV2:1;
			__BYTE	P13:1;
			__BYTE	P14:1;
			__BYTE	P15:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	P10:1;
			__BYTE	RESV1:1;
			__BYTE	RESV2:1;
			__BYTE	P13:1;
			__BYTE	P14:1;
			__BYTE	P15:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} PUL1STR;

__IO_EXTERN	  PUL1STR	IO_PUL1;
#define	_pul1		(IO_PUL1)
#define	PUL1		(IO_PUL1.byte)
#define	PUL1_P10  	(IO_PUL1.bit.P10)
#define	PUL1_P13  	(IO_PUL1.bit.P13)
#define	PUL1_P14  	(IO_PUL1.bit.P14)
#define	PUL1_P15  	(IO_PUL1.bit.P15)

#ifdef __IO_DEFINE
#pragma segment IO=IO_PUL7, locate=0x32
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	P70:1;
			__BYTE	P71:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	P70:1;
			__BYTE	P71:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} PUL7STR;

__IO_EXTERN	  PUL7STR	IO_PUL7;
#define	_pul7		(IO_PUL7)
#define	PUL7		(IO_PUL7.byte)
#define	PUL7_P70  	(IO_PUL7.bit.P70)
#define	PUL7_P71  	(IO_PUL7.bit.P71)

#ifdef __IO_DEFINE
#pragma segment IO=IO_PUL6, locate=0x33
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	RESV0:1;
			__BYTE	RESV1:1;
			__BYTE	RESV2:1;
			__BYTE	P63:1;
			__BYTE	RESV4:1;
			__BYTE	P65:1;
			__BYTE	P66:1;
			__BYTE	P67:1;
	} bit;
	struct {
			__BYTE	RESV0:1;
			__BYTE	RESV1:1;
			__BYTE	RESV2:1;
			__BYTE	P63:1;
			__BYTE	RESV4:1;
			__BYTE	P65:1;
			__BYTE	P66:1;
			__BYTE	P67:1;
	} bitc;
} PUL6STR;

__IO_EXTERN	  PUL6STR	IO_PUL6;
#define	_pul6		(IO_PUL6)
#define	PUL6		(IO_PUL6.byte)
#define	PUL6_P63  	(IO_PUL6.bit.P63)
#define	PUL6_P65  	(IO_PUL6.bit.P65)
#define	PUL6_P66  	(IO_PUL6.bit.P66)
#define	PUL6_P67  	(IO_PUL6.bit.P67)

#ifdef __IO_DEFINE
#pragma segment IO=IO_PULG, locate=0x35
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	RESV0:1;
			__BYTE	PG1:1;
			__BYTE	PG2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	RESV0:1;
			__BYTE	PG1:1;
			__BYTE	PG2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} PULGSTR;

__IO_EXTERN	  PULGSTR	IO_PULG;
#define	_pulg		(IO_PULG)
#define	PULG		(IO_PULG.byte)
#define	PULG_PG1  	(IO_PULG.bit.PG1)
#define	PULG_PG2  	(IO_PULG.bit.PG2)

#ifdef __IO_DEFINE
#pragma segment IO=IO_T01CR1, locate=0x36
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	OE:1;
			__BYTE	SO:1;
			__BYTE	IF:1;
			__BYTE	BF:1;
			__BYTE	IR:1;
			__BYTE	IE:1;
			__BYTE	HO:1;
			__BYTE	STA:1;
	} bit;
	struct {
			__BYTE	OE:1;
			__BYTE	SO:1;
			__BYTE	IF:1;
			__BYTE	BF:1;
			__BYTE	IR:1;
			__BYTE	IE:1;
			__BYTE	HO:1;
			__BYTE	STA:1;
	} bitc;
} T01CR1STR;

__IO_EXTERN	  T01CR1STR	IO_T01CR1;
#define	_t01cr1		(IO_T01CR1)
#define	T01CR1		(IO_T01CR1.byte)
#define	T01CR1_OE  	(IO_T01CR1.bit.OE)
#define	T01CR1_SO  	(IO_T01CR1.bit.SO)
#define	T01CR1_IF  	(IO_T01CR1.bit.IF)
#define	T01CR1_BF  	(IO_T01CR1.bit.BF)
#define	T01CR1_IR  	(IO_T01CR1.bit.IR)
#define	T01CR1_IE  	(IO_T01CR1.bit.IE)
#define	T01CR1_HO  	(IO_T01CR1.bit.HO)
#define	T01CR1_STA  	(IO_T01CR1.bit.STA)

#ifdef __IO_DEFINE
#pragma segment IO=IO_T00CR1, locate=0x37
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	OE:1;
			__BYTE	SO:1;
			__BYTE	IF:1;
			__BYTE	BF:1;
			__BYTE	IR:1;
			__BYTE	IE:1;
			__BYTE	HO:1;
			__BYTE	STA:1;
	} bit;
	struct {
			__BYTE	OE:1;
			__BYTE	SO:1;
			__BYTE	IF:1;
			__BYTE	BF:1;
			__BYTE	IR:1;
			__BYTE	IE:1;
			__BYTE	HO:1;
			__BYTE	STA:1;
	} bitc;
} T00CR1STR;

__IO_EXTERN	  T00CR1STR	IO_T00CR1;
#define	_t00cr1		(IO_T00CR1)
#define	T00CR1		(IO_T00CR1.byte)
#define	T00CR1_OE  	(IO_T00CR1.bit.OE)
#define	T00CR1_SO  	(IO_T00CR1.bit.SO)
#define	T00CR1_IF  	(IO_T00CR1.bit.IF)
#define	T00CR1_BF  	(IO_T00CR1.bit.BF)
#define	T00CR1_IR  	(IO_T00CR1.bit.IR)
#define	T00CR1_IE  	(IO_T00CR1.bit.IE)
#define	T00CR1_HO  	(IO_T00CR1.bit.HO)
#define	T00CR1_STA  	(IO_T00CR1.bit.STA)

#ifdef __IO_DEFINE
#pragma segment IO=IO_T11CR1, locate=0x38
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	OE:1;
			__BYTE	SO:1;
			__BYTE	IF:1;
			__BYTE	BF:1;
			__BYTE	IR:1;
			__BYTE	IE:1;
			__BYTE	HO:1;
			__BYTE	STA:1;
	} bit;
	struct {
			__BYTE	OE:1;
			__BYTE	SO:1;
			__BYTE	IF:1;
			__BYTE	BF:1;
			__BYTE	IR:1;
			__BYTE	IE:1;
			__BYTE	HO:1;
			__BYTE	STA:1;
	} bitc;
} T11CR1STR;

__IO_EXTERN	  T11CR1STR	IO_T11CR1;
#define	_t11cr1		(IO_T11CR1)
#define	T11CR1		(IO_T11CR1.byte)
#define	T11CR1_OE  	(IO_T11CR1.bit.OE)
#define	T11CR1_SO  	(IO_T11CR1.bit.SO)
#define	T11CR1_IF  	(IO_T11CR1.bit.IF)
#define	T11CR1_BF  	(IO_T11CR1.bit.BF)
#define	T11CR1_IR  	(IO_T11CR1.bit.IR)
#define	T11CR1_IE  	(IO_T11CR1.bit.IE)
#define	T11CR1_HO  	(IO_T11CR1.bit.HO)
#define	T11CR1_STA  	(IO_T11CR1.bit.STA)

#ifdef __IO_DEFINE
#pragma segment IO=IO_T10CR1, locate=0x39
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	OE:1;
			__BYTE	SO:1;
			__BYTE	IF:1;
			__BYTE	BF:1;
			__BYTE	IR:1;
			__BYTE	IE:1;
			__BYTE	HO:1;
			__BYTE	STA:1;
	} bit;
	struct {
			__BYTE	OE:1;
			__BYTE	SO:1;
			__BYTE	IF:1;
			__BYTE	BF:1;
			__BYTE	IR:1;
			__BYTE	IE:1;
			__BYTE	HO:1;
			__BYTE	STA:1;
	} bitc;
} T10CR1STR;

__IO_EXTERN	  T10CR1STR	IO_T10CR1;
#define	_t10cr1		(IO_T10CR1)
#define	T10CR1		(IO_T10CR1.byte)
#define	T10CR1_OE  	(IO_T10CR1.bit.OE)
#define	T10CR1_SO  	(IO_T10CR1.bit.SO)
#define	T10CR1_IF  	(IO_T10CR1.bit.IF)
#define	T10CR1_BF  	(IO_T10CR1.bit.BF)
#define	T10CR1_IR  	(IO_T10CR1.bit.IR)
#define	T10CR1_IE  	(IO_T10CR1.bit.IE)
#define	T10CR1_HO  	(IO_T10CR1.bit.HO)
#define	T10CR1_STA  	(IO_T10CR1.bit.STA)

#ifdef __IO_DEFINE
#pragma segment IO=IO_PC01, locate=0x3A
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	CKS10:1;
			__BYTE	CKS11:1;
			__BYTE	CKS12:1;
			__BYTE	POEN1:1;
			__BYTE	PUF1:1;
			__BYTE	PIE1:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	CKS10:1;
			__BYTE	CKS11:1;
			__BYTE	CKS12:1;
			__BYTE	POEN1:1;
			__BYTE	PUF1:1;
			__BYTE	PIE1:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} PC01STR;

__IO_EXTERN	  PC01STR	IO_PC01;
#define	_pc01		(IO_PC01)
#define	PC01		(IO_PC01.byte)
#define	PC01_CKS10  	(IO_PC01.bit.CKS10)
#define	PC01_CKS11  	(IO_PC01.bit.CKS11)
#define	PC01_CKS12  	(IO_PC01.bit.CKS12)
#define	PC01_POEN1  	(IO_PC01.bit.POEN1)
#define	PC01_PUF1  	(IO_PC01.bit.PUF1)
#define	PC01_PIE1  	(IO_PC01.bit.PIE1)

#ifdef __IO_DEFINE
#pragma segment IO=IO_PC00, locate=0x3B
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	CKS00:1;
			__BYTE	CKS01:1;
			__BYTE	CKS02:1;
			__BYTE	POEN0:1;
			__BYTE	PUF0:1;
			__BYTE	PIE0:1;
			__BYTE	MD0:1;
			__BYTE	MD1:1;
	} bit;
	struct {
			__BYTE	CKS00:1;
			__BYTE	CKS01:1;
			__BYTE	CKS02:1;
			__BYTE	POEN0:1;
			__BYTE	PUF0:1;
			__BYTE	PIE0:1;
			__BYTE	MD0:1;
			__BYTE	MD1:1;
	} bitc;
} PC00STR;

__IO_EXTERN	  PC00STR	IO_PC00;
#define	_pc00		(IO_PC00)
#define	PC00		(IO_PC00.byte)
#define	PC00_CKS00  	(IO_PC00.bit.CKS00)
#define	PC00_CKS01  	(IO_PC00.bit.CKS01)
#define	PC00_CKS02  	(IO_PC00.bit.CKS02)
#define	PC00_POEN0  	(IO_PC00.bit.POEN0)
#define	PC00_PUF0  	(IO_PC00.bit.PUF0)
#define	PC00_PIE0  	(IO_PC00.bit.PIE0)
#define	PC00_MD0  	(IO_PC00.bit.MD0)
#define	PC00_MD1  	(IO_PC00.bit.MD1)

#ifdef __IO_DEFINE
#pragma segment IO=IO_EIC00, locate=0x48
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	EIE0:1;
			__BYTE	SL00:1;
			__BYTE	SL01:1;
			__BYTE	EIR0:1;
			__BYTE	EIE1:1;
			__BYTE	SL10:1;
			__BYTE	SL11:1;
			__BYTE	EIR1:1;
	} bit;
	struct {
			__BYTE	EIE0:1;
			__BYTE	SL00:1;
			__BYTE	SL01:1;
			__BYTE	EIR0:1;
			__BYTE	EIE1:1;
			__BYTE	SL10:1;
			__BYTE	SL11:1;
			__BYTE	EIR1:1;
	} bitc;
} EIC00STR;

__IO_EXTERN	  EIC00STR	IO_EIC00;
#define	_eic00		(IO_EIC00)
#define	EIC00		(IO_EIC00.byte)
#define	EIC00_EIE0  	(IO_EIC00.bit.EIE0)
#define	EIC00_SL00  	(IO_EIC00.bit.SL00)
#define	EIC00_SL01  	(IO_EIC00.bit.SL01)
#define	EIC00_EIR0  	(IO_EIC00.bit.EIR0)
#define	EIC00_EIE1  	(IO_EIC00.bit.EIE1)
#define	EIC00_SL10  	(IO_EIC00.bit.SL10)
#define	EIC00_SL11  	(IO_EIC00.bit.SL11)
#define	EIC00_EIR1  	(IO_EIC00.bit.EIR1)

#ifdef __IO_DEFINE
#pragma segment IO=IO_EIC20, locate=0x4A
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	EIE0:1;
			__BYTE	SL00:1;
			__BYTE	SL01:1;
			__BYTE	EIR0:1;
			__BYTE	EIE1:1;
			__BYTE	SL10:1;
			__BYTE	SL11:1;
			__BYTE	EIR1:1;
	} bit;
	struct {
			__BYTE	EIE0:1;
			__BYTE	SL00:1;
			__BYTE	SL01:1;
			__BYTE	EIR0:1;
			__BYTE	EIE1:1;
			__BYTE	SL10:1;
			__BYTE	SL11:1;
			__BYTE	EIR1:1;
	} bitc;
} EIC20STR;

__IO_EXTERN	  EIC20STR	IO_EIC20;
#define	_eic20		(IO_EIC20)
#define	EIC20		(IO_EIC20.byte)
#define	EIC20_EIE0  	(IO_EIC20.bit.EIE0)
#define	EIC20_SL00  	(IO_EIC20.bit.SL00)
#define	EIC20_SL01  	(IO_EIC20.bit.SL01)
#define	EIC20_EIR0  	(IO_EIC20.bit.EIR0)
#define	EIC20_EIE1  	(IO_EIC20.bit.EIE1)
#define	EIC20_SL10  	(IO_EIC20.bit.SL10)
#define	EIC20_SL11  	(IO_EIC20.bit.SL11)
#define	EIC20_EIR1  	(IO_EIC20.bit.EIR1)

#ifdef __IO_DEFINE
#pragma segment IO=IO_EIC30, locate=0x4B
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	EIE0:1;
			__BYTE	SL00:1;
			__BYTE	SL01:1;
			__BYTE	EIR0:1;
			__BYTE	EIE1:1;
			__BYTE	SL10:1;
			__BYTE	SL11:1;
			__BYTE	EIR1:1;
	} bit;
	struct {
			__BYTE	EIE0:1;
			__BYTE	SL00:1;
			__BYTE	SL01:1;
			__BYTE	EIR0:1;
			__BYTE	EIE1:1;
			__BYTE	SL10:1;
			__BYTE	SL11:1;
			__BYTE	EIR1:1;
	} bitc;
} EIC30STR;

__IO_EXTERN	  EIC30STR	IO_EIC30;
#define	_eic30		(IO_EIC30)
#define	EIC30		(IO_EIC30.byte)
#define	EIC30_EIE0  	(IO_EIC30.bit.EIE0)
#define	EIC30_SL00  	(IO_EIC30.bit.SL00)
#define	EIC30_SL01  	(IO_EIC30.bit.SL01)
#define	EIC30_EIR0  	(IO_EIC30.bit.EIR0)
#define	EIC30_EIE1  	(IO_EIC30.bit.EIE1)
#define	EIC30_SL10  	(IO_EIC30.bit.SL10)
#define	EIC30_SL11  	(IO_EIC30.bit.SL11)
#define	EIC30_EIR1  	(IO_EIC30.bit.EIR1)

#ifdef __IO_DEFINE
#pragma segment IO=IO_LVDR, locate=0x4E
#endif

__IO_EXTERN	__BYTE	IO_LVDR;
#define	_lvdr		(IO_LVDR)
#define	LVDR	(_lvdr)

#ifdef __IO_DEFINE
#pragma segment IO=IO_LVDCC, locate=0x4F
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	LVDEON:1;
			__BYTE	RESV1:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	LVDEON:1;
			__BYTE	RESV1:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} LVDCCSTR;

__IO_EXTERN	  LVDCCSTR	IO_LVDCC;
#define	_lvdcc		(IO_LVDCC)
#define	LVDCC		(IO_LVDCC.byte)
#define	LVDCC_LVDEON  	(IO_LVDCC.bit.LVDEON)

#ifdef __IO_DEFINE
#pragma segment IO=IO_SMC10, locate=0x56
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	MD:1;
			__BYTE	CKS:1;
			__BYTE	CBL0:1;
			__BYTE	CBL1:1;
			__BYTE	SBL:1;
			__BYTE	TDP:1;
			__BYTE	PEN:1;
			__BYTE	BDS:1;
	} bit;
	struct {
			__BYTE	MD:1;
			__BYTE	CKS:1;
			__BYTE	CBL0:1;
			__BYTE	CBL1:1;
			__BYTE	SBL:1;
			__BYTE	TDP:1;
			__BYTE	PEN:1;
			__BYTE	BDS:1;
	} bitc;
} SMC10STR;

__IO_EXTERN	  SMC10STR	IO_SMC10;
#define	_smc10		(IO_SMC10)
#define	SMC10		(IO_SMC10.byte)
#define	SMC10_MD  	(IO_SMC10.bit.MD)
#define	SMC10_CKS  	(IO_SMC10.bit.CKS)
#define	SMC10_CBL0  	(IO_SMC10.bit.CBL0)
#define	SMC10_CBL1  	(IO_SMC10.bit.CBL1)
#define	SMC10_SBL  	(IO_SMC10.bit.SBL)
#define	SMC10_TDP  	(IO_SMC10.bit.TDP)
#define	SMC10_PEN  	(IO_SMC10.bit.PEN)
#define	SMC10_BDS  	(IO_SMC10.bit.BDS)

#ifdef __IO_DEFINE
#pragma segment IO=IO_SMC20, locate=0x57
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	TEIE:1;
			__BYTE	TCIE:1;
			__BYTE	RIE:1;
			__BYTE	TXE:1;
			__BYTE	RXE:1;
			__BYTE	RERC:1;
			__BYTE	TXOE:1;
			__BYTE	SCKE:1;
	} bit;
	struct {
			__BYTE	TEIE:1;
			__BYTE	TCIE:1;
			__BYTE	RIE:1;
			__BYTE	TXE:1;
			__BYTE	RXE:1;
			__BYTE	RERC:1;
			__BYTE	TXOE:1;
			__BYTE	SCKE:1;
	} bitc;
} SMC20STR;

__IO_EXTERN	  SMC20STR	IO_SMC20;
#define	_smc20		(IO_SMC20)
#define	SMC20		(IO_SMC20.byte)
#define	SMC20_TEIE  	(IO_SMC20.bit.TEIE)
#define	SMC20_TCIE  	(IO_SMC20.bit.TCIE)
#define	SMC20_RIE  	(IO_SMC20.bit.RIE)
#define	SMC20_TXE  	(IO_SMC20.bit.TXE)
#define	SMC20_RXE  	(IO_SMC20.bit.RXE)
#define	SMC20_RERC  	(IO_SMC20.bit.RERC)
#define	SMC20_TXOE  	(IO_SMC20.bit.TXOE)
#define	SMC20_SCKE  	(IO_SMC20.bit.SCKE)

#ifdef __IO_DEFINE
#pragma segment IO=IO_SSR0, locate=0x58
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	TDRE:1;
			__BYTE	TCPL:1;
			__BYTE	RDRF:1;
			__BYTE	FER:1;
			__BYTE	OVE:1;
			__BYTE	PER:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	TDRE:1;
			__BYTE	TCPL:1;
			__BYTE	RDRF:1;
			__BYTE	FER:1;
			__BYTE	OVE:1;
			__BYTE	PER:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} SSR0STR;

__IO_EXTERN	  SSR0STR	IO_SSR0;
#define	_ssr0		(IO_SSR0)
#define	SSR0		(IO_SSR0.byte)
#define	SSR0_TDRE  	(IO_SSR0.bit.TDRE)
#define	SSR0_TCPL  	(IO_SSR0.bit.TCPL)
#define	SSR0_RDRF  	(IO_SSR0.bit.RDRF)
#define	SSR0_FER  	(IO_SSR0.bit.FER)
#define	SSR0_OVE  	(IO_SSR0.bit.OVE)
#define	SSR0_PER  	(IO_SSR0.bit.PER)

#ifdef __IO_DEFINE
#pragma segment IO=IO_TDR0, locate=0x59
#endif

__IO_EXTERN	__BYTE	IO_TDR0;
#define	_tdr0		(IO_TDR0)
#define	TDR0	(_tdr0)

#ifdef __IO_DEFINE
#pragma segment IO=IO_RDR0, locate=0x5A
#endif

__IO_EXTERN	const __BYTE	IO_RDR0;
#define	_rdr0		(IO_RDR0)
#define	RDR0	(_rdr0)

#ifdef __IO_DEFINE
#pragma segment IO=IO_CMR0, locate=0x5B
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	PD:1;
			__BYTE	VCOE:1;
			__BYTE	VCID:1;
			__BYTE	IE:1;
			__BYTE	IF:1;
			__BYTE	OS:1;
			__BYTE	BGRS:1;
			__BYTE	BGRPD:1;
	} bit;
	struct {
			__BYTE	PD:1;
			__BYTE	VCOE:1;
			__BYTE	VCID:1;
			__BYTE	IE:1;
			__BYTE	IF:1;
			__BYTE	OS:1;
			__BYTE	BGRS:1;
			__BYTE	BGRPD:1;
	} bitc;
} CMR0STR;

__IO_EXTERN	  CMR0STR	IO_CMR0;
#define	_cmr0		(IO_CMR0)
#define	CMR0		(IO_CMR0.byte)
#define	CMR0_PD  	(IO_CMR0.bit.PD)
#define	CMR0_VCOE  	(IO_CMR0.bit.VCOE)
#define	CMR0_VCID  	(IO_CMR0.bit.VCID)
#define	CMR0_IE  	(IO_CMR0.bit.IE)
#define	CMR0_IF  	(IO_CMR0.bit.IF)
#define	CMR0_OS  	(IO_CMR0.bit.OS)
#define	CMR0_BGRS  	(IO_CMR0.bit.BGRS)
#define	CMR0_BGRPD  	(IO_CMR0.bit.BGRPD)

#ifdef __IO_DEFINE
#pragma segment IO=IO_IBCR00, locate=0x60
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	WUE:1;
			__BYTE	WUF:1;
			__BYTE	SPE:1;
			__BYTE	SPF:1;
			__BYTE	ALE:1;
			__BYTE	ALF:1;
			__BYTE	INTS:1;
			__BYTE	AACKX:1;
	} bit;
	struct {
			__BYTE	WUE:1;
			__BYTE	WUF:1;
			__BYTE	SPE:1;
			__BYTE	SPF:1;
			__BYTE	ALE:1;
			__BYTE	ALF:1;
			__BYTE	INTS:1;
			__BYTE	AACKX:1;
	} bitc;
} IBCR00STR;

__IO_EXTERN	  IBCR00STR	IO_IBCR00;
#define	_ibcr00		(IO_IBCR00)
#define	IBCR00		(IO_IBCR00.byte)
#define	IBCR00_WUE  	(IO_IBCR00.bit.WUE)
#define	IBCR00_WUF  	(IO_IBCR00.bit.WUF)
#define	IBCR00_SPE  	(IO_IBCR00.bit.SPE)
#define	IBCR00_SPF  	(IO_IBCR00.bit.SPF)
#define	IBCR00_ALE  	(IO_IBCR00.bit.ALE)
#define	IBCR00_ALF  	(IO_IBCR00.bit.ALF)
#define	IBCR00_INTS  	(IO_IBCR00.bit.INTS)
#define	IBCR00_AACKX  	(IO_IBCR00.bit.AACKX)

#ifdef __IO_DEFINE
#pragma segment IO=IO_IBCR10, locate=0x61
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	INT:1;
			__BYTE	INTE:1;
			__BYTE	GACKE:1;
			__BYTE	DACKE:1;
			__BYTE	MSS:1;
			__BYTE	SCC:1;
			__BYTE	BEIE:1;
			__BYTE	BER:1;
	} bit;
	struct {
			__BYTE	INT:1;
			__BYTE	INTE:1;
			__BYTE	GACKE:1;
			__BYTE	DACKE:1;
			__BYTE	MSS:1;
			__BYTE	SCC:1;
			__BYTE	BEIE:1;
			__BYTE	BER:1;
	} bitc;
} IBCR10STR;

__IO_EXTERN	  IBCR10STR	IO_IBCR10;
#define	_ibcr10		(IO_IBCR10)
#define	IBCR10		(IO_IBCR10.byte)
#define	IBCR10_INT  	(IO_IBCR10.bit.INT)
#define	IBCR10_INTE  	(IO_IBCR10.bit.INTE)
#define	IBCR10_GACKE  	(IO_IBCR10.bit.GACKE)
#define	IBCR10_DACKE  	(IO_IBCR10.bit.DACKE)
#define	IBCR10_MSS  	(IO_IBCR10.bit.MSS)
#define	IBCR10_SCC  	(IO_IBCR10.bit.SCC)
#define	IBCR10_BEIE  	(IO_IBCR10.bit.BEIE)
#define	IBCR10_BER  	(IO_IBCR10.bit.BER)

#ifdef __IO_DEFINE
#pragma segment IO=IO_IBSR0, locate=0x62
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	FBT:1;
			__BYTE	GCA:1;
			__BYTE	AAS:1;
			__BYTE	TRX:1;
			__BYTE	LRB:1;
			__BYTE	RESV5:1;
			__BYTE	RSC:1;
			__BYTE	BB:1;
	} bit;
	struct {
			__BYTE	FBT:1;
			__BYTE	GCA:1;
			__BYTE	AAS:1;
			__BYTE	TRX:1;
			__BYTE	LRB:1;
			__BYTE	RESV5:1;
			__BYTE	RSC:1;
			__BYTE	BB:1;
	} bitc;
} IBSR0STR;

__IO_EXTERN	 const  IBSR0STR	IO_IBSR0;
#define	_ibsr0		(IO_IBSR0)
#define	IBSR0		(IO_IBSR0.byte)
#define	IBSR0_FBT  	(IO_IBSR0.bit.FBT)
#define	IBSR0_GCA  	(IO_IBSR0.bit.GCA)
#define	IBSR0_AAS  	(IO_IBSR0.bit.AAS)
#define	IBSR0_TRX  	(IO_IBSR0.bit.TRX)
#define	IBSR0_LRB  	(IO_IBSR0.bit.LRB)
#define	IBSR0_RSC  	(IO_IBSR0.bit.RSC)
#define	IBSR0_BB  	(IO_IBSR0.bit.BB)

#ifdef __IO_DEFINE
#pragma segment IO=IO_IDDR0, locate=0x63
#endif

__IO_EXTERN	__BYTE	IO_IDDR0;
#define	_iddr0		(IO_IDDR0)
#define	IDDR0	(_iddr0)

#ifdef __IO_DEFINE
#pragma segment IO=IO_IAAR0, locate=0x64
#endif

__IO_EXTERN	__BYTE	IO_IAAR0;
#define	_iaar0		(IO_IAAR0)
#define	IAAR0	(_iaar0)

#ifdef __IO_DEFINE
#pragma segment IO=IO_ICCR0, locate=0x65
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	CS0:1;
			__BYTE	CS1:1;
			__BYTE	CS2:1;
			__BYTE	CS3:1;
			__BYTE	CS4:1;
			__BYTE	EN:1;
			__BYTE	RESV6:1;
			__BYTE	DMBP:1;
	} bit;
	struct {
			__BYTE	CS0:1;
			__BYTE	CS1:1;
			__BYTE	CS2:1;
			__BYTE	CS3:1;
			__BYTE	CS4:1;
			__BYTE	EN:1;
			__BYTE	RESV6:1;
			__BYTE	DMBP:1;
	} bitc;
} ICCR0STR;

__IO_EXTERN	  ICCR0STR	IO_ICCR0;
#define	_iccr0		(IO_ICCR0)
#define	ICCR0		(IO_ICCR0.byte)
#define	ICCR0_CS0  	(IO_ICCR0.bit.CS0)
#define	ICCR0_CS1  	(IO_ICCR0.bit.CS1)
#define	ICCR0_CS2  	(IO_ICCR0.bit.CS2)
#define	ICCR0_CS3  	(IO_ICCR0.bit.CS3)
#define	ICCR0_CS4  	(IO_ICCR0.bit.CS4)
#define	ICCR0_EN  	(IO_ICCR0.bit.EN)
#define	ICCR0_DMBP  	(IO_ICCR0.bit.DMBP)

#ifdef __IO_DEFINE
#pragma segment IO=IO_ADC1, locate=0x6C
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	AD:1;
			__BYTE	RESV1:1;
			__BYTE	ADMV:1;
			__BYTE	ADI:1;
			__BYTE	ANS0:1;
			__BYTE	ANS1:1;
			__BYTE	ANS2:1;
			__BYTE	ANS3:1;
	} bit;
	struct {
			__BYTE	AD:1;
			__BYTE	RESV1:1;
			__BYTE	ADMV:1;
			__BYTE	ADI:1;
			__BYTE	ANS0:1;
			__BYTE	ANS1:1;
			__BYTE	ANS2:1;
			__BYTE	ANS3:1;
	} bitc;
} ADC1STR;

__IO_EXTERN	  ADC1STR	IO_ADC1;
#define	_adc1		(IO_ADC1)
#define	ADC1		(IO_ADC1.byte)
#define	ADC1_AD  	(IO_ADC1.bit.AD)
#define	ADC1_ADMV  	(IO_ADC1.bit.ADMV)
#define	ADC1_ADI  	(IO_ADC1.bit.ADI)
#define	ADC1_ANS0  	(IO_ADC1.bit.ANS0)
#define	ADC1_ANS1  	(IO_ADC1.bit.ANS1)
#define	ADC1_ANS2  	(IO_ADC1.bit.ANS2)
#define	ADC1_ANS3  	(IO_ADC1.bit.ANS3)

#ifdef __IO_DEFINE
#pragma segment IO=IO_ADC2, locate=0x6D
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	CKDIV0:1;
			__BYTE	CKDIV1:1;
			__BYTE	EXT:1;
			__BYTE	ADIE:1;
			__BYTE	ADCK:1;
			__BYTE	TIM0:1;
			__BYTE	TIM1:1;
			__BYTE	AD8:1;
	} bit;
	struct {
			__BYTE	CKDIV0:1;
			__BYTE	CKDIV1:1;
			__BYTE	EXT:1;
			__BYTE	ADIE:1;
			__BYTE	ADCK:1;
			__BYTE	TIM0:1;
			__BYTE	TIM1:1;
			__BYTE	AD8:1;
	} bitc;
} ADC2STR;

__IO_EXTERN	  ADC2STR	IO_ADC2;
#define	_adc2		(IO_ADC2)
#define	ADC2		(IO_ADC2.byte)
#define	ADC2_CKDIV0  	(IO_ADC2.bit.CKDIV0)
#define	ADC2_CKDIV1  	(IO_ADC2.bit.CKDIV1)
#define	ADC2_EXT  	(IO_ADC2.bit.EXT)
#define	ADC2_ADIE  	(IO_ADC2.bit.ADIE)
#define	ADC2_ADCK  	(IO_ADC2.bit.ADCK)
#define	ADC2_TIM0  	(IO_ADC2.bit.TIM0)
#define	ADC2_TIM1  	(IO_ADC2.bit.TIM1)
#define	ADC2_AD8  	(IO_ADC2.bit.AD8)

#ifdef __IO_DEFINE
#pragma segment IO=IO_ADD, locate=0x6E
#endif

__IO_EXTERN	const	union {
	__WORD	word;
	struct {
		__BYTE	ADDH;
		__BYTE	ADDL;
	} byte;
} IO_ADD;

#define	ADD		(IO_ADD.word)
#define	ADD_ADDH	(IO_ADD.byte.ADDH)
#define	ADD_ADDL	(IO_ADD.byte.ADDL)

#ifdef __IO_DEFINE
#pragma segment IO=IO_WCSR, locate=0x70
#endif

__IO_EXTERN	__BYTE	IO_WCSR;
#define	_wcsr		(IO_WCSR)
#define	WCSR	(_wcsr)

#ifdef __IO_DEFINE
#pragma segment IO=IO_FSR2, locate=0x71
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	ERSTO:1;
			__BYTE	ETIEN:1;
			__BYTE	ERSEND:1;
			__BYTE	EEIEN:1;
			__BYTE	PGMTO:1;
			__BYTE	PTIEN:1;
			__BYTE	PGMEND:1;
			__BYTE	PEIEN:1;
	} bit;
	struct {
			__BYTE	ERSTO:1;
			__BYTE	ETIEN:1;
			__BYTE	ERSEND:1;
			__BYTE	EEIEN:1;
			__BYTE	PGMTO:1;
			__BYTE	PTIEN:1;
			__BYTE	PGMEND:1;
			__BYTE	PEIEN:1;
	} bitc;
} FSR2STR;

__IO_EXTERN	  FSR2STR	IO_FSR2;
#define	_fsr2		(IO_FSR2)
#define	FSR2		(IO_FSR2.byte)
#define	FSR2_ERSTO  	(IO_FSR2.bit.ERSTO)
#define	FSR2_ETIEN  	(IO_FSR2.bit.ETIEN)
#define	FSR2_ERSEND  	(IO_FSR2.bit.ERSEND)
#define	FSR2_EEIEN  	(IO_FSR2.bit.EEIEN)
#define	FSR2_PGMTO  	(IO_FSR2.bit.PGMTO)
#define	FSR2_PTIEN  	(IO_FSR2.bit.PTIEN)
#define	FSR2_PGMEND  	(IO_FSR2.bit.PGMEND)
#define	FSR2_PEIEN  	(IO_FSR2.bit.PEIEN)

#ifdef __IO_DEFINE
#pragma segment IO=IO_FSR, locate=0x72
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	SSEN:1;
			__BYTE	WRE:1;
			__BYTE	IRQEN:1;
			__BYTE	RESV3:1;
			__BYTE	RDY:1;
			__BYTE	RDYIRQ:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	SSEN:1;
			__BYTE	WRE:1;
			__BYTE	IRQEN:1;
			__BYTE	RESV3:1;
			__BYTE	RDY:1;
			__BYTE	RDYIRQ:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} FSRSTR;

__IO_EXTERN	  FSRSTR	IO_FSR;
#define	_fsr		(IO_FSR)
#define	FSR		(IO_FSR.byte)
#define	FSR_SSEN  	(IO_FSR.bit.SSEN)
#define	FSR_WRE  	(IO_FSR.bit.WRE)
#define	FSR_IRQEN  	(IO_FSR.bit.IRQEN)
#define	FSR_RDY  	(IO_FSR.bit.RDY)
#define	FSR_RDYIRQ  	(IO_FSR.bit.RDYIRQ)

#ifdef __IO_DEFINE
#pragma segment IO=IO_SWRE0, locate=0x73
#endif

typedef union {
	__BYTE	byte;
} SWRE0STR;

__IO_EXTERN	  SWRE0STR	IO_SWRE0;
#define	_swre0		(IO_SWRE0)
#define	SWRE0		(IO_SWRE0.byte)

#ifdef __IO_DEFINE
#pragma segment IO=IO_FSR3, locate=0x74
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	HANG:1;
			__BYTE	PGMS:1;
			__BYTE	SERS:1;
			__BYTE	ESPS:1;
			__BYTE	CERS:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	HANG:1;
			__BYTE	PGMS:1;
			__BYTE	SERS:1;
			__BYTE	ESPS:1;
			__BYTE	CERS:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} FSR3STR;

__IO_EXTERN	 const  FSR3STR	IO_FSR3;
#define	_fsr3		(IO_FSR3)
#define	FSR3		(IO_FSR3.byte)
#define	FSR3_HANG  	(IO_FSR3.bit.HANG)
#define	FSR3_PGMS  	(IO_FSR3.bit.PGMS)
#define	FSR3_SERS  	(IO_FSR3.bit.SERS)
#define	FSR3_ESPS  	(IO_FSR3.bit.ESPS)
#define	FSR3_CERS  	(IO_FSR3.bit.CERS)

#ifdef __IO_DEFINE
#pragma segment IO=IO_FSR4, locate=0x75
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	RESV0:1;
			__BYTE	RESV1:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	CERTO:1;
			__BYTE	CTIEN:1;
			__BYTE	CEREND:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	RESV0:1;
			__BYTE	RESV1:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	CERTO:1;
			__BYTE	CTIEN:1;
			__BYTE	CEREND:1;
			__BYTE	RESV7:1;
	} bitc;
} FSR4STR;

__IO_EXTERN	  FSR4STR	IO_FSR4;
#define	_fsr4		(IO_FSR4)
#define	FSR4		(IO_FSR4.byte)
#define	FSR4_CERTO  	(IO_FSR4.bit.CERTO)
#define	FSR4_CTIEN  	(IO_FSR4.bit.CTIEN)
#define	FSR4_CEREND  	(IO_FSR4.bit.CEREND)

#ifdef __IO_DEFINE
#pragma segment IO=IO_WREN, locate=0x76
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	EN0:1;
			__BYTE	EN1:1;
			__BYTE	EN2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	EN0:1;
			__BYTE	EN1:1;
			__BYTE	EN2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} WRENSTR;

__IO_EXTERN	  WRENSTR	IO_WREN;
#define	_wren		(IO_WREN)
#define	WREN		(IO_WREN.byte)
#define	WREN_EN0  	(IO_WREN.bit.EN0)
#define	WREN_EN1  	(IO_WREN.bit.EN1)
#define	WREN_EN2  	(IO_WREN.bit.EN2)

#ifdef __IO_DEFINE
#pragma segment IO=IO_WROR, locate=0x77
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	DRR0:1;
			__BYTE	DRR1:1;
			__BYTE	DRR2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	DRR0:1;
			__BYTE	DRR1:1;
			__BYTE	DRR2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} WRORSTR;

__IO_EXTERN	  WRORSTR	IO_WROR;
#define	_wror		(IO_WROR)
#define	WROR		(IO_WROR.byte)
#define	WROR_DRR0  	(IO_WROR.bit.DRR0)
#define	WROR_DRR1  	(IO_WROR.bit.DRR1)
#define	WROR_DRR2  	(IO_WROR.bit.DRR2)

#ifdef __IO_DEFINE
#pragma segment IO=IO_ILR0, locate=0x79
#endif

__IO_EXTERN	__BYTE	IO_ILR0;
#define	_ilr0		(IO_ILR0)
#define	ILR0	(_ilr0)

#ifdef __IO_DEFINE
#pragma segment IO=IO_ILR1, locate=0x7A
#endif

__IO_EXTERN	__BYTE	IO_ILR1;
#define	_ilr1		(IO_ILR1)
#define	ILR1	(_ilr1)

#ifdef __IO_DEFINE
#pragma segment IO=IO_ILR2, locate=0x7B
#endif

__IO_EXTERN	__BYTE	IO_ILR2;
#define	_ilr2		(IO_ILR2)
#define	ILR2	(_ilr2)

#ifdef __IO_DEFINE
#pragma segment IO=IO_ILR3, locate=0x7C
#endif

__IO_EXTERN	__BYTE	IO_ILR3;
#define	_ilr3		(IO_ILR3)
#define	ILR3	(_ilr3)

#ifdef __IO_DEFINE
#pragma segment IO=IO_ILR4, locate=0x7D
#endif

__IO_EXTERN	__BYTE	IO_ILR4;
#define	_ilr4		(IO_ILR4)
#define	ILR4	(_ilr4)

#ifdef __IO_DEFINE
#pragma segment IO=IO_ILR5, locate=0x7E
#endif

__IO_EXTERN	__BYTE	IO_ILR5;
#define	_ilr5		(IO_ILR5)
#define	ILR5	(_ilr5)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_BPFREQ,   locate=0xE10
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	BP0:1;
			__BYTE	BP1:1;
			__BYTE	BP2:1;
			__BYTE	BP3:1;
			__BYTE	SW:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	BP0:1;
			__BYTE	BP1:1;
			__BYTE	BP2:1;
			__BYTE	BP3:1;
			__BYTE	SW:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} BPFREQSTR;

__IO_EXTENDED	  BPFREQSTR	IO_BPFREQ;
#define	_bpfreq		(IO_BPFREQ)
#define	BPFREQ		(IO_BPFREQ.byte)
#define	BPFREQ_BP0  	(IO_BPFREQ.bit.BP0)
#define	BPFREQ_BP1  	(IO_BPFREQ.bit.BP1)
#define	BPFREQ_BP2  	(IO_BPFREQ.bit.BP2)
#define	BPFREQ_BP3  	(IO_BPFREQ.bit.BP3)
#define	BPFREQ_SW  	(IO_BPFREQ.bit.SW)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_TER0,   locate=0xE11
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	ENS00:1;
			__BYTE	ENS01:1;
			__BYTE	ENS02:1;
			__BYTE	ENS03:1;
			__BYTE	ENS04:1;
			__BYTE	ENS05:1;
			__BYTE	ENS06:1;
			__BYTE	ENS07:1;
	} bit;
	struct {
			__BYTE	ENS00:1;
			__BYTE	ENS01:1;
			__BYTE	ENS02:1;
			__BYTE	ENS03:1;
			__BYTE	ENS04:1;
			__BYTE	ENS05:1;
			__BYTE	ENS06:1;
			__BYTE	ENS07:1;
	} bitc;
} TER0STR;

__IO_EXTENDED	  TER0STR	IO_TER0;
#define	_ter0		(IO_TER0)
#define	TER0		(IO_TER0.byte)
#define	TER0_ENS00  	(IO_TER0.bit.ENS00)
#define	TER0_ENS01  	(IO_TER0.bit.ENS01)
#define	TER0_ENS02  	(IO_TER0.bit.ENS02)
#define	TER0_ENS03  	(IO_TER0.bit.ENS03)
#define	TER0_ENS04  	(IO_TER0.bit.ENS04)
#define	TER0_ENS05  	(IO_TER0.bit.ENS05)
#define	TER0_ENS06  	(IO_TER0.bit.ENS06)
#define	TER0_ENS07  	(IO_TER0.bit.ENS07)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_TER1,   locate=0xE12
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	ENS08:1;
			__BYTE	ENS09:1;
			__BYTE	ENS10:1;
			__BYTE	ENS11:1;
			__BYTE	EN_REF:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	ENS08:1;
			__BYTE	ENS09:1;
			__BYTE	ENS10:1;
			__BYTE	ENS11:1;
			__BYTE	EN_REF:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} TER1STR;

__IO_EXTENDED	  TER1STR	IO_TER1;
#define	_ter1		(IO_TER1)
#define	TER1		(IO_TER1.byte)
#define	TER1_ENS08  	(IO_TER1.bit.ENS08)
#define	TER1_ENS09  	(IO_TER1.bit.ENS09)
#define	TER1_ENS10  	(IO_TER1.bit.ENS10)
#define	TER1_ENS11  	(IO_TER1.bit.ENS11)
#define	TER1_EN_REF  	(IO_TER1.bit.EN_REF)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_PSC,   locate=0xE13
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	DIVSEL0:1;
			__BYTE	DIVSEL1:1;
			__BYTE	DIVSEL2:1;
			__BYTE	DIVSEL3:1;
			__BYTE	STPE:1;
			__BYTE	TRDY:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	DIVSEL0:1;
			__BYTE	DIVSEL1:1;
			__BYTE	DIVSEL2:1;
			__BYTE	DIVSEL3:1;
			__BYTE	STPE:1;
			__BYTE	TRDY:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} PSCSTR;

__IO_EXTENDED	  PSCSTR	IO_PSC;
#define	_psc		(IO_PSC)
#define	PSC		(IO_PSC.byte)
#define	PSC_DIVSEL0  	(IO_PSC.bit.DIVSEL0)
#define	PSC_DIVSEL1  	(IO_PSC.bit.DIVSEL1)
#define	PSC_DIVSEL2  	(IO_PSC.bit.DIVSEL2)
#define	PSC_DIVSEL3  	(IO_PSC.bit.DIVSEL3)
#define	PSC_STPE  	(IO_PSC.bit.STPE)
#define	PSC_TRDY  	(IO_PSC.bit.TRDY)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_WRESET,   locate=0xE14
#endif

__IO_EXTENDED	__BYTE	IO_WRESET;
#define	_wreset		(IO_WRESET)
#define	WRESET	(_wreset)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_RSEL0,   locate=0xE15
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	SREFB0:1;
			__BYTE	SREFB1:1;
			__BYTE	SREFB2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	SREFB0:1;
			__BYTE	SREFB1:1;
			__BYTE	SREFB2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} RSEL0STR;

__IO_EXTENDED	  RSEL0STR	IO_RSEL0;
#define	_rsel0		(IO_RSEL0)
#define	RSEL0		(IO_RSEL0.byte)
#define	RSEL0_SREFB0  	(IO_RSEL0.bit.SREFB0)
#define	RSEL0_SREFB1  	(IO_RSEL0.bit.SREFB1)
#define	RSEL0_SREFB2  	(IO_RSEL0.bit.SREFB2)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_RSEL1,   locate=0xE16
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	S00B0:1;
			__BYTE	S00B1:1;
			__BYTE	S00B2:1;
			__BYTE	S01B0:1;
			__BYTE	S01B1:1;
			__BYTE	S01B2:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	S00B0:1;
			__BYTE	S00B1:1;
			__BYTE	S00B2:1;
			__BYTE	S01B0:1;
			__BYTE	S01B1:1;
			__BYTE	S01B2:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} RSEL1STR;

__IO_EXTENDED	  RSEL1STR	IO_RSEL1;
#define	_rsel1		(IO_RSEL1)
#define	RSEL1		(IO_RSEL1.byte)
#define	RSEL1_S00B0  	(IO_RSEL1.bit.S00B0)
#define	RSEL1_S00B1  	(IO_RSEL1.bit.S00B1)
#define	RSEL1_S00B2  	(IO_RSEL1.bit.S00B2)
#define	RSEL1_S01B0  	(IO_RSEL1.bit.S01B0)
#define	RSEL1_S01B1  	(IO_RSEL1.bit.S01B1)
#define	RSEL1_S01B2  	(IO_RSEL1.bit.S01B2)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_RSEL2,   locate=0xE17
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	S02B0:1;
			__BYTE	S02B1:1;
			__BYTE	S02B2:1;
			__BYTE	S03B0:1;
			__BYTE	S03B1:1;
			__BYTE	S03B2:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	S02B0:1;
			__BYTE	S02B1:1;
			__BYTE	S02B2:1;
			__BYTE	S03B0:1;
			__BYTE	S03B1:1;
			__BYTE	S03B2:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} RSEL2STR;

__IO_EXTENDED	  RSEL2STR	IO_RSEL2;
#define	_rsel2		(IO_RSEL2)
#define	RSEL2		(IO_RSEL2.byte)
#define	RSEL2_S02B0  	(IO_RSEL2.bit.S02B0)
#define	RSEL2_S02B1  	(IO_RSEL2.bit.S02B1)
#define	RSEL2_S02B2  	(IO_RSEL2.bit.S02B2)
#define	RSEL2_S03B0  	(IO_RSEL2.bit.S03B0)
#define	RSEL2_S03B1  	(IO_RSEL2.bit.S03B1)
#define	RSEL2_S03B2  	(IO_RSEL2.bit.S03B2)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_RSEL3,   locate=0xE18
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	S04B0:1;
			__BYTE	S04B1:1;
			__BYTE	S04B2:1;
			__BYTE	S05B0:1;
			__BYTE	S05B1:1;
			__BYTE	S05B2:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	S04B0:1;
			__BYTE	S04B1:1;
			__BYTE	S04B2:1;
			__BYTE	S05B0:1;
			__BYTE	S05B1:1;
			__BYTE	S05B2:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} RSEL3STR;

__IO_EXTENDED	  RSEL3STR	IO_RSEL3;
#define	_rsel3		(IO_RSEL3)
#define	RSEL3		(IO_RSEL3.byte)
#define	RSEL3_S04B0  	(IO_RSEL3.bit.S04B0)
#define	RSEL3_S04B1  	(IO_RSEL3.bit.S04B1)
#define	RSEL3_S04B2  	(IO_RSEL3.bit.S04B2)
#define	RSEL3_S05B0  	(IO_RSEL3.bit.S05B0)
#define	RSEL3_S05B1  	(IO_RSEL3.bit.S05B1)
#define	RSEL3_S05B2  	(IO_RSEL3.bit.S05B2)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_BPDUR,   locate=0xE1C
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	BDR0:1;
			__BYTE	BDR1:1;
			__BYTE	BDR2:1;
			__BYTE	BDR3:1;
			__BYTE	BDR4:1;
			__BYTE	BDR5:1;
			__BYTE	BDR6:1;
			__BYTE	BDR7:1;
	} bit;
	struct {
			__BYTE	BDR0:1;
			__BYTE	BDR1:1;
			__BYTE	BDR2:1;
			__BYTE	BDR3:1;
			__BYTE	BDR4:1;
			__BYTE	BDR5:1;
			__BYTE	BDR6:1;
			__BYTE	BDR7:1;
	} bitc;
} BPDURSTR;

__IO_EXTENDED	  BPDURSTR	IO_BPDUR;
#define	_bpdur		(IO_BPDUR)
#define	BPDUR		(IO_BPDUR.byte)
#define	BPDUR_BDR0  	(IO_BPDUR.bit.BDR0)
#define	BPDUR_BDR1  	(IO_BPDUR.bit.BDR1)
#define	BPDUR_BDR2  	(IO_BPDUR.bit.BDR2)
#define	BPDUR_BDR3  	(IO_BPDUR.bit.BDR3)
#define	BPDUR_BDR4  	(IO_BPDUR.bit.BDR4)
#define	BPDUR_BDR5  	(IO_BPDUR.bit.BDR5)
#define	BPDUR_BDR6  	(IO_BPDUR.bit.BDR6)
#define	BPDUR_BDR7  	(IO_BPDUR.bit.BDR7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_DIOR1,   locate=0xE1D
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	DIO00S0:1;
			__BYTE	DIO00S1:1;
			__BYTE	DIO00S2:1;
			__BYTE	DIO00S3:1;
			__BYTE	DIO01S0:1;
			__BYTE	DIO01S1:1;
			__BYTE	DIO01S2:1;
			__BYTE	DIO01S3:1;
	} bit;
	struct {
			__BYTE	DIO00S0:1;
			__BYTE	DIO00S1:1;
			__BYTE	DIO00S2:1;
			__BYTE	DIO00S3:1;
			__BYTE	DIO01S0:1;
			__BYTE	DIO01S1:1;
			__BYTE	DIO01S2:1;
			__BYTE	DIO01S3:1;
	} bitc;
} DIOR1STR;

__IO_EXTENDED	  DIOR1STR	IO_DIOR1;
#define	_dior1		(IO_DIOR1)
#define	DIOR1		(IO_DIOR1.byte)
#define	DIOR1_DIO00S0  	(IO_DIOR1.bit.DIO00S0)
#define	DIOR1_DIO00S1  	(IO_DIOR1.bit.DIO00S1)
#define	DIOR1_DIO00S2  	(IO_DIOR1.bit.DIO00S2)
#define	DIOR1_DIO00S3  	(IO_DIOR1.bit.DIO00S3)
#define	DIOR1_DIO01S0  	(IO_DIOR1.bit.DIO01S0)
#define	DIOR1_DIO01S1  	(IO_DIOR1.bit.DIO01S1)
#define	DIOR1_DIO01S2  	(IO_DIOR1.bit.DIO01S2)
#define	DIOR1_DIO01S3  	(IO_DIOR1.bit.DIO01S3)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_DIOR2,   locate=0xE1E
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	DIO02S0:1;
			__BYTE	DIO02S1:1;
			__BYTE	DIO02S2:1;
			__BYTE	DIO02S3:1;
			__BYTE	DIO03S0:1;
			__BYTE	DIO03S1:1;
			__BYTE	DIO03S2:1;
			__BYTE	DIO03S3:1;
	} bit;
	struct {
			__BYTE	DIO02S0:1;
			__BYTE	DIO02S1:1;
			__BYTE	DIO02S2:1;
			__BYTE	DIO02S3:1;
			__BYTE	DIO03S0:1;
			__BYTE	DIO03S1:1;
			__BYTE	DIO03S2:1;
			__BYTE	DIO03S3:1;
	} bitc;
} DIOR2STR;

__IO_EXTENDED	  DIOR2STR	IO_DIOR2;
#define	_dior2		(IO_DIOR2)
#define	DIOR2		(IO_DIOR2.byte)
#define	DIOR2_DIO02S0  	(IO_DIOR2.bit.DIO02S0)
#define	DIOR2_DIO02S1  	(IO_DIOR2.bit.DIO02S1)
#define	DIOR2_DIO02S2  	(IO_DIOR2.bit.DIO02S2)
#define	DIOR2_DIO02S3  	(IO_DIOR2.bit.DIO02S3)
#define	DIOR2_DIO03S0  	(IO_DIOR2.bit.DIO03S0)
#define	DIOR2_DIO03S1  	(IO_DIOR2.bit.DIO03S1)
#define	DIOR2_DIO03S2  	(IO_DIOR2.bit.DIO03S2)
#define	DIOR2_DIO03S3  	(IO_DIOR2.bit.DIO03S3)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_DIOR3,   locate=0xE1F
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	DIO04S0:1;
			__BYTE	DIO04S1:1;
			__BYTE	DIO04S2:1;
			__BYTE	DIO04S3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	DIO04S0:1;
			__BYTE	DIO04S1:1;
			__BYTE	DIO04S2:1;
			__BYTE	DIO04S3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} DIOR3STR;

__IO_EXTENDED	  DIOR3STR	IO_DIOR3;
#define	_dior3		(IO_DIOR3)
#define	DIOR3		(IO_DIOR3.byte)
#define	DIOR3_DIO04S0  	(IO_DIOR3.bit.DIO04S0)
#define	DIOR3_DIO04S1  	(IO_DIOR3.bit.DIO04S1)
#define	DIOR3_DIO04S2  	(IO_DIOR3.bit.DIO04S2)
#define	DIOR3_DIO04S3  	(IO_DIOR3.bit.DIO04S3)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_FTSEL,   locate=0xE20
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	ENAF:1;
			__BYTE	APSEL0:1;
			__BYTE	APSEL1:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	ENAF:1;
			__BYTE	APSEL0:1;
			__BYTE	APSEL1:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} FTSELSTR;

__IO_EXTENDED	  FTSELSTR	IO_FTSEL;
#define	_ftsel		(IO_FTSEL)
#define	FTSEL		(IO_FTSEL.byte)
#define	FTSEL_ENAF  	(IO_FTSEL.bit.ENAF)
#define	FTSEL_APSEL0  	(IO_FTSEL.bit.APSEL0)
#define	FTSEL_APSEL1  	(IO_FTSEL.bit.APSEL1)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_AICWAT,   locate=0xE21
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	AICW0:1;
			__BYTE	AICW1:1;
			__BYTE	AICW2:1;
			__BYTE	AICW3:1;
			__BYTE	AICW4:1;
			__BYTE	AICW5:1;
			__BYTE	AICW6:1;
			__BYTE	AICW7:1;
	} bit;
	struct {
			__BYTE	AICW0:1;
			__BYTE	AICW1:1;
			__BYTE	AICW2:1;
			__BYTE	AICW3:1;
			__BYTE	AICW4:1;
			__BYTE	AICW5:1;
			__BYTE	AICW6:1;
			__BYTE	AICW7:1;
	} bitc;
} AICWATSTR;

__IO_EXTENDED	  AICWATSTR	IO_AICWAT;
#define	_aicwat		(IO_AICWAT)
#define	AICWAT		(IO_AICWAT.byte)
#define	AICWAT_AICW0  	(IO_AICWAT.bit.AICW0)
#define	AICWAT_AICW1  	(IO_AICWAT.bit.AICW1)
#define	AICWAT_AICW2  	(IO_AICWAT.bit.AICW2)
#define	AICWAT_AICW3  	(IO_AICWAT.bit.AICW3)
#define	AICWAT_AICW4  	(IO_AICWAT.bit.AICW4)
#define	AICWAT_AICW5  	(IO_AICWAT.bit.AICW5)
#define	AICWAT_AICW6  	(IO_AICWAT.bit.AICW6)
#define	AICWAT_AICW7  	(IO_AICWAT.bit.AICW7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_CALITV,   locate=0xE22
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	CALI0:1;
			__BYTE	CALL1:1;
			__BYTE	CALI2:1;
			__BYTE	CALI3:1;
			__BYTE	CALI4:1;
			__BYTE	CALI5:1;
			__BYTE	CALI6:1;
			__BYTE	CALI7:1;
	} bit;
	struct {
			__BYTE	CALI0:1;
			__BYTE	CALL1:1;
			__BYTE	CALI2:1;
			__BYTE	CALI3:1;
			__BYTE	CALI4:1;
			__BYTE	CALI5:1;
			__BYTE	CALI6:1;
			__BYTE	CALI7:1;
	} bitc;
} CALITVSTR;

__IO_EXTENDED	  CALITVSTR	IO_CALITV;
#define	_calitv		(IO_CALITV)
#define	CALITV		(IO_CALITV.byte)
#define	CALITV_CALI0  	(IO_CALITV.bit.CALI0)
#define	CALITV_CALL1  	(IO_CALITV.bit.CALL1)
#define	CALITV_CALI2  	(IO_CALITV.bit.CALI2)
#define	CALITV_CALI3  	(IO_CALITV.bit.CALI3)
#define	CALITV_CALI4  	(IO_CALITV.bit.CALI4)
#define	CALITV_CALI5  	(IO_CALITV.bit.CALI5)
#define	CALITV_CALI6  	(IO_CALITV.bit.CALI6)
#define	CALITV_CALI7  	(IO_CALITV.bit.CALI7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_ITGTM,   locate=0xE23
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	INTET0:1;
			__BYTE	INTET1:1;
			__BYTE	INTET2:1;
			__BYTE	INTET3:1;
			__BYTE	INTET4:1;
			__BYTE	INTET5:1;
			__BYTE	INTET6:1;
			__BYTE	INTET7:1;
	} bit;
	struct {
			__BYTE	INTET0:1;
			__BYTE	INTET1:1;
			__BYTE	INTET2:1;
			__BYTE	INTET3:1;
			__BYTE	INTET4:1;
			__BYTE	INTET5:1;
			__BYTE	INTET6:1;
			__BYTE	INTET7:1;
	} bitc;
} ITGTMSTR;

__IO_EXTENDED	  ITGTMSTR	IO_ITGTM;
#define	_itgtm		(IO_ITGTM)
#define	ITGTM		(IO_ITGTM.byte)
#define	ITGTM_INTET0  	(IO_ITGTM.bit.INTET0)
#define	ITGTM_INTET1  	(IO_ITGTM.bit.INTET1)
#define	ITGTM_INTET2  	(IO_ITGTM.bit.INTET2)
#define	ITGTM_INTET3  	(IO_ITGTM.bit.INTET3)
#define	ITGTM_INTET4  	(IO_ITGTM.bit.INTET4)
#define	ITGTM_INTET5  	(IO_ITGTM.bit.INTET5)
#define	ITGTM_INTET6  	(IO_ITGTM.bit.INTET6)
#define	ITGTM_INTET7  	(IO_ITGTM.bit.INTET7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_IDLETM,   locate=0xE24
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	IDLET0:1;
			__BYTE	IDLET1:1;
			__BYTE	IDLET2:1;
			__BYTE	IDLET3:1;
			__BYTE	IDLET4:1;
			__BYTE	IDLET5:1;
			__BYTE	IDLET6:1;
			__BYTE	IDLET7:1;
	} bit;
	struct {
			__BYTE	IDLET0:1;
			__BYTE	IDLET1:1;
			__BYTE	IDLET2:1;
			__BYTE	IDLET3:1;
			__BYTE	IDLET4:1;
			__BYTE	IDLET5:1;
			__BYTE	IDLET6:1;
			__BYTE	IDLET7:1;
	} bitc;
} IDLETMSTR;

__IO_EXTENDED	  IDLETMSTR	IO_IDLETM;
#define	_idletm		(IO_IDLETM)
#define	IDLETM		(IO_IDLETM.byte)
#define	IDLETM_IDLET0  	(IO_IDLETM.bit.IDLET0)
#define	IDLETM_IDLET1  	(IO_IDLETM.bit.IDLET1)
#define	IDLETM_IDLET2  	(IO_IDLETM.bit.IDLET2)
#define	IDLETM_IDLET3  	(IO_IDLETM.bit.IDLET3)
#define	IDLETM_IDLET4  	(IO_IDLETM.bit.IDLET4)
#define	IDLETM_IDLET5  	(IO_IDLETM.bit.IDLET5)
#define	IDLETM_IDLET6  	(IO_IDLETM.bit.IDLET6)
#define	IDLETM_IDLET7  	(IO_IDLETM.bit.IDLET7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_CONTROL,   locate=0xE25
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	HOLD:1;
			__BYTE	HDC_C:1;
			__BYTE	HDC_U:1;
			__BYTE	F2A:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	HOLD:1;
			__BYTE	HDC_C:1;
			__BYTE	HDC_U:1;
			__BYTE	F2A:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} CONTROLSTR;

__IO_EXTENDED	  CONTROLSTR	IO_CONTROL;
#define	_control		(IO_CONTROL)
#define	CONTROL		(IO_CONTROL.byte)
#define	CONTROL_HOLD  	(IO_CONTROL.bit.HOLD)
#define	CONTROL_HDC_C  	(IO_CONTROL.bit.HDC_C)
#define	CONTROL_HDC_U  	(IO_CONTROL.bit.HDC_U)
#define	CONTROL_F2A  	(IO_CONTROL.bit.F2A)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_INTMR,   locate=0xE26
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	TINT:1;
			__BYTE	ATI:1;
			__BYTE	ITA:1;
			__BYTE	EOC:1;
			__BYTE	NEW:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	TINT:1;
			__BYTE	ATI:1;
			__BYTE	ITA:1;
			__BYTE	EOC:1;
			__BYTE	NEW:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} INTMRSTR;

__IO_EXTENDED	  INTMRSTR	IO_INTMR;
#define	_intmr		(IO_INTMR)
#define	INTMR		(IO_INTMR.byte)
#define	INTMR_TINT  	(IO_INTMR.bit.TINT)
#define	INTMR_ATI  	(IO_INTMR.bit.ATI)
#define	INTMR_ITA  	(IO_INTMR.bit.ITA)
#define	INTMR_EOC  	(IO_INTMR.bit.EOC)
#define	INTMR_NEW  	(IO_INTMR.bit.NEW)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_INTCR,   locate=0xE27
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	TINT:1;
			__BYTE	ATI:1;
			__BYTE	ITA:1;
			__BYTE	EOC:1;
			__BYTE	NEW:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	TINT:1;
			__BYTE	ATI:1;
			__BYTE	ITA:1;
			__BYTE	EOC:1;
			__BYTE	NEW:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} INTCRSTR;

__IO_EXTENDED	  INTCRSTR	IO_INTCR;
#define	_intcr		(IO_INTCR)
#define	INTCR		(IO_INTCR.byte)
#define	INTCR_TINT  	(IO_INTCR.bit.TINT)
#define	INTCR_ATI  	(IO_INTCR.bit.ATI)
#define	INTCR_ITA  	(IO_INTCR.bit.ITA)
#define	INTCR_EOC  	(IO_INTCR.bit.EOC)
#define	INTCR_NEW  	(IO_INTCR.bit.NEW)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_FLTP,   locate=0xE28
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	FILP0:1;
			__BYTE	FILP1:1;
			__BYTE	FILP2:1;
			__BYTE	FILP3:1;
			__BYTE	FILP4:1;
			__BYTE	FILP5:1;
			__BYTE	FILP6:1;
			__BYTE	FILP7:1;
	} bit;
	struct {
			__BYTE	FILP0:1;
			__BYTE	FILP1:1;
			__BYTE	FILP2:1;
			__BYTE	FILP3:1;
			__BYTE	FILP4:1;
			__BYTE	FILP5:1;
			__BYTE	FILP6:1;
			__BYTE	FILP7:1;
	} bitc;
} FLTPSTR;

__IO_EXTENDED	  FLTPSTR	IO_FLTP;
#define	_fltp		(IO_FLTP)
#define	FLTP		(IO_FLTP.byte)
#define	FLTP_FILP0  	(IO_FLTP.bit.FILP0)
#define	FLTP_FILP1  	(IO_FLTP.bit.FILP1)
#define	FLTP_FILP2  	(IO_FLTP.bit.FILP2)
#define	FLTP_FILP3  	(IO_FLTP.bit.FILP3)
#define	FLTP_FILP4  	(IO_FLTP.bit.FILP4)
#define	FLTP_FILP5  	(IO_FLTP.bit.FILP5)
#define	FLTP_FILP6  	(IO_FLTP.bit.FILP6)
#define	FLTP_FILP7  	(IO_FLTP.bit.FILP7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_FLTTH,   locate=0xE29
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	FILT0:1;
			__BYTE	FILT1:1;
			__BYTE	FILT2:1;
			__BYTE	FILT3:1;
			__BYTE	FILT4:1;
			__BYTE	FILT5:1;
			__BYTE	FILT6:1;
			__BYTE	FILT7:1;
	} bit;
	struct {
			__BYTE	FILT0:1;
			__BYTE	FILT1:1;
			__BYTE	FILT2:1;
			__BYTE	FILT3:1;
			__BYTE	FILT4:1;
			__BYTE	FILT5:1;
			__BYTE	FILT6:1;
			__BYTE	FILT7:1;
	} bitc;
} FLTTHSTR;

__IO_EXTENDED	  FLTTHSTR	IO_FLTTH;
#define	_fltth		(IO_FLTTH)
#define	FLTTH		(IO_FLTTH.byte)
#define	FLTTH_FILT0  	(IO_FLTTH.bit.FILT0)
#define	FLTTH_FILT1  	(IO_FLTTH.bit.FILT1)
#define	FLTTH_FILT2  	(IO_FLTTH.bit.FILT2)
#define	FLTTH_FILT3  	(IO_FLTTH.bit.FILT3)
#define	FLTTH_FILT4  	(IO_FLTTH.bit.FILT4)
#define	FLTTH_FILT5  	(IO_FLTTH.bit.FILT5)
#define	FLTTH_FILT6  	(IO_FLTTH.bit.FILT6)
#define	FLTTH_FILT7  	(IO_FLTTH.bit.FILT7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_REFDLY,   locate=0xE2A
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	REFD0:1;
			__BYTE	REFD1:1;
			__BYTE	REFD2:1;
			__BYTE	REFD33:1;
			__BYTE	REFD4:1;
			__BYTE	REFD5:1;
			__BYTE	REFD6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	REFD0:1;
			__BYTE	REFD1:1;
			__BYTE	REFD2:1;
			__BYTE	REFD33:1;
			__BYTE	REFD4:1;
			__BYTE	REFD5:1;
			__BYTE	REFD6:1;
			__BYTE	RESV7:1;
	} bitc;
} REFDLYSTR;

__IO_EXTENDED	  REFDLYSTR	IO_REFDLY;
#define	_refdly		(IO_REFDLY)
#define	REFDLY		(IO_REFDLY.byte)
#define	REFDLY_REFD0  	(IO_REFDLY.bit.REFD0)
#define	REFDLY_REFD1  	(IO_REFDLY.bit.REFD1)
#define	REFDLY_REFD2  	(IO_REFDLY.bit.REFD2)
#define	REFDLY_REFD33  	(IO_REFDLY.bit.REFD33)
#define	REFDLY_REFD4  	(IO_REFDLY.bit.REFD4)
#define	REFDLY_REFD5  	(IO_REFDLY.bit.REFD5)
#define	REFDLY_REFD6  	(IO_REFDLY.bit.REFD6)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_ALPH1,   locate=0xE31
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	ALP0:1;
			__BYTE	ALP1:1;
			__BYTE	ALP2:1;
			__BYTE	ALP3:1;
			__BYTE	ALP4:1;
			__BYTE	ALP5:1;
			__BYTE	ALP6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	ALP0:1;
			__BYTE	ALP1:1;
			__BYTE	ALP2:1;
			__BYTE	ALP3:1;
			__BYTE	ALP4:1;
			__BYTE	ALP5:1;
			__BYTE	ALP6:1;
			__BYTE	RESV7:1;
	} bitc;
} ALPH1STR;

__IO_EXTENDED	  ALPH1STR	IO_ALPH1;
#define	_alph1		(IO_ALPH1)
#define	ALPH1		(IO_ALPH1.byte)
#define	ALPH1_ALP0  	(IO_ALPH1.bit.ALP0)
#define	ALPH1_ALP1  	(IO_ALPH1.bit.ALP1)
#define	ALPH1_ALP2  	(IO_ALPH1.bit.ALP2)
#define	ALPH1_ALP3  	(IO_ALPH1.bit.ALP3)
#define	ALPH1_ALP4  	(IO_ALPH1.bit.ALP4)
#define	ALPH1_ALP5  	(IO_ALPH1.bit.ALP5)
#define	ALPH1_ALP6  	(IO_ALPH1.bit.ALP6)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_ALPH2,   locate=0xE32
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	ALP0:1;
			__BYTE	ALP1:1;
			__BYTE	ALP2:1;
			__BYTE	ALP3:1;
			__BYTE	ALP4:1;
			__BYTE	ALP5:1;
			__BYTE	ALP6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	ALP0:1;
			__BYTE	ALP1:1;
			__BYTE	ALP2:1;
			__BYTE	ALP3:1;
			__BYTE	ALP4:1;
			__BYTE	ALP5:1;
			__BYTE	ALP6:1;
			__BYTE	RESV7:1;
	} bitc;
} ALPH2STR;

__IO_EXTENDED	  ALPH2STR	IO_ALPH2;
#define	_alph2		(IO_ALPH2)
#define	ALPH2		(IO_ALPH2.byte)
#define	ALPH2_ALP0  	(IO_ALPH2.bit.ALP0)
#define	ALPH2_ALP1  	(IO_ALPH2.bit.ALP1)
#define	ALPH2_ALP2  	(IO_ALPH2.bit.ALP2)
#define	ALPH2_ALP3  	(IO_ALPH2.bit.ALP3)
#define	ALPH2_ALP4  	(IO_ALPH2.bit.ALP4)
#define	ALPH2_ALP5  	(IO_ALPH2.bit.ALP5)
#define	ALPH2_ALP6  	(IO_ALPH2.bit.ALP6)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_ALPH3,   locate=0xE33
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	ALP0:1;
			__BYTE	ALP1:1;
			__BYTE	ALP2:1;
			__BYTE	ALP3:1;
			__BYTE	ALP4:1;
			__BYTE	ALP5:1;
			__BYTE	ALP6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	ALP0:1;
			__BYTE	ALP1:1;
			__BYTE	ALP2:1;
			__BYTE	ALP3:1;
			__BYTE	ALP4:1;
			__BYTE	ALP5:1;
			__BYTE	ALP6:1;
			__BYTE	RESV7:1;
	} bitc;
} ALPH3STR;

__IO_EXTENDED	  ALPH3STR	IO_ALPH3;
#define	_alph3		(IO_ALPH3)
#define	ALPH3		(IO_ALPH3.byte)
#define	ALPH3_ALP0  	(IO_ALPH3.bit.ALP0)
#define	ALPH3_ALP1  	(IO_ALPH3.bit.ALP1)
#define	ALPH3_ALP2  	(IO_ALPH3.bit.ALP2)
#define	ALPH3_ALP3  	(IO_ALPH3.bit.ALP3)
#define	ALPH3_ALP4  	(IO_ALPH3.bit.ALP4)
#define	ALPH3_ALP5  	(IO_ALPH3.bit.ALP5)
#define	ALPH3_ALP6  	(IO_ALPH3.bit.ALP6)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_ALPH4,   locate=0xE34
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	ALP0:1;
			__BYTE	ALP1:1;
			__BYTE	ALP2:1;
			__BYTE	ALP3:1;
			__BYTE	ALP4:1;
			__BYTE	ALP5:1;
			__BYTE	ALP6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	ALP0:1;
			__BYTE	ALP1:1;
			__BYTE	ALP2:1;
			__BYTE	ALP3:1;
			__BYTE	ALP4:1;
			__BYTE	ALP5:1;
			__BYTE	ALP6:1;
			__BYTE	RESV7:1;
	} bitc;
} ALPH4STR;

__IO_EXTENDED	  ALPH4STR	IO_ALPH4;
#define	_alph4		(IO_ALPH4)
#define	ALPH4		(IO_ALPH4.byte)
#define	ALPH4_ALP0  	(IO_ALPH4.bit.ALP0)
#define	ALPH4_ALP1  	(IO_ALPH4.bit.ALP1)
#define	ALPH4_ALP2  	(IO_ALPH4.bit.ALP2)
#define	ALPH4_ALP3  	(IO_ALPH4.bit.ALP3)
#define	ALPH4_ALP4  	(IO_ALPH4.bit.ALP4)
#define	ALPH4_ALP5  	(IO_ALPH4.bit.ALP5)
#define	ALPH4_ALP6  	(IO_ALPH4.bit.ALP6)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_ALPH5,   locate=0xE35
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	ALP0:1;
			__BYTE	ALP1:1;
			__BYTE	ALP2:1;
			__BYTE	ALP3:1;
			__BYTE	ALP4:1;
			__BYTE	ALP5:1;
			__BYTE	ALP6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	ALP0:1;
			__BYTE	ALP1:1;
			__BYTE	ALP2:1;
			__BYTE	ALP3:1;
			__BYTE	ALP4:1;
			__BYTE	ALP5:1;
			__BYTE	ALP6:1;
			__BYTE	RESV7:1;
	} bitc;
} ALPH5STR;

__IO_EXTENDED	  ALPH5STR	IO_ALPH5;
#define	_alph5		(IO_ALPH5)
#define	ALPH5		(IO_ALPH5.byte)
#define	ALPH5_ALP0  	(IO_ALPH5.bit.ALP0)
#define	ALPH5_ALP1  	(IO_ALPH5.bit.ALP1)
#define	ALPH5_ALP2  	(IO_ALPH5.bit.ALP2)
#define	ALPH5_ALP3  	(IO_ALPH5.bit.ALP3)
#define	ALPH5_ALP4  	(IO_ALPH5.bit.ALP4)
#define	ALPH5_ALP5  	(IO_ALPH5.bit.ALP5)
#define	ALPH5_ALP6  	(IO_ALPH5.bit.ALP6)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_BETA,   locate=0xE40
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	BETA0:1;
			__BYTE	BETA1:1;
			__BYTE	BETA2:1;
			__BYTE	BETA3:1;
			__BYTE	BETA4:1;
			__BYTE	BETA5:1;
			__BYTE	BETA6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	BETA0:1;
			__BYTE	BETA1:1;
			__BYTE	BETA2:1;
			__BYTE	BETA3:1;
			__BYTE	BETA4:1;
			__BYTE	BETA5:1;
			__BYTE	BETA6:1;
			__BYTE	RESV7:1;
	} bitc;
} BETASTR;

__IO_EXTENDED	  BETASTR	IO_BETA;
#define	_beta		(IO_BETA)
#define	BETA		(IO_BETA.byte)
#define	BETA_BETA0  	(IO_BETA.bit.BETA0)
#define	BETA_BETA1  	(IO_BETA.bit.BETA1)
#define	BETA_BETA2  	(IO_BETA.bit.BETA2)
#define	BETA_BETA3  	(IO_BETA.bit.BETA3)
#define	BETA_BETA4  	(IO_BETA.bit.BETA4)
#define	BETA_BETA5  	(IO_BETA.bit.BETA5)
#define	BETA_BETA6  	(IO_BETA.bit.BETA6)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_STRTH1,   locate=0xE51
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	STH0:1;
			__BYTE	STH1:1;
			__BYTE	STH2:1;
			__BYTE	STH3:1;
			__BYTE	STH4:1;
			__BYTE	STH5:1;
			__BYTE	STH6:1;
			__BYTE	STH7:1;
	} bit;
	struct {
			__BYTE	STH0:1;
			__BYTE	STH1:1;
			__BYTE	STH2:1;
			__BYTE	STH3:1;
			__BYTE	STH4:1;
			__BYTE	STH5:1;
			__BYTE	STH6:1;
			__BYTE	STH7:1;
	} bitc;
} STRTH1STR;

__IO_EXTENDED	  STRTH1STR	IO_STRTH1;
#define	_strth1		(IO_STRTH1)
#define	STRTH1		(IO_STRTH1.byte)
#define	STRTH1_STH0  	(IO_STRTH1.bit.STH0)
#define	STRTH1_STH1  	(IO_STRTH1.bit.STH1)
#define	STRTH1_STH2  	(IO_STRTH1.bit.STH2)
#define	STRTH1_STH3  	(IO_STRTH1.bit.STH3)
#define	STRTH1_STH4  	(IO_STRTH1.bit.STH4)
#define	STRTH1_STH5  	(IO_STRTH1.bit.STH5)
#define	STRTH1_STH6  	(IO_STRTH1.bit.STH6)
#define	STRTH1_STH7  	(IO_STRTH1.bit.STH7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_STRTH2,   locate=0xE52
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	STH0:1;
			__BYTE	STH1:1;
			__BYTE	STH2:1;
			__BYTE	STH3:1;
			__BYTE	STH4:1;
			__BYTE	STH5:1;
			__BYTE	STH6:1;
			__BYTE	STH7:1;
	} bit;
	struct {
			__BYTE	STH0:1;
			__BYTE	STH1:1;
			__BYTE	STH2:1;
			__BYTE	STH3:1;
			__BYTE	STH4:1;
			__BYTE	STH5:1;
			__BYTE	STH6:1;
			__BYTE	STH7:1;
	} bitc;
} STRTH2STR;

__IO_EXTENDED	  STRTH2STR	IO_STRTH2;
#define	_strth2		(IO_STRTH2)
#define	STRTH2		(IO_STRTH2.byte)
#define	STRTH2_STH0  	(IO_STRTH2.bit.STH0)
#define	STRTH2_STH1  	(IO_STRTH2.bit.STH1)
#define	STRTH2_STH2  	(IO_STRTH2.bit.STH2)
#define	STRTH2_STH3  	(IO_STRTH2.bit.STH3)
#define	STRTH2_STH4  	(IO_STRTH2.bit.STH4)
#define	STRTH2_STH5  	(IO_STRTH2.bit.STH5)
#define	STRTH2_STH6  	(IO_STRTH2.bit.STH6)
#define	STRTH2_STH7  	(IO_STRTH2.bit.STH7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_STRTH3,   locate=0xE53
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	STH0:1;
			__BYTE	STH1:1;
			__BYTE	STH2:1;
			__BYTE	STH3:1;
			__BYTE	STH4:1;
			__BYTE	STH5:1;
			__BYTE	STH6:1;
			__BYTE	STH7:1;
	} bit;
	struct {
			__BYTE	STH0:1;
			__BYTE	STH1:1;
			__BYTE	STH2:1;
			__BYTE	STH3:1;
			__BYTE	STH4:1;
			__BYTE	STH5:1;
			__BYTE	STH6:1;
			__BYTE	STH7:1;
	} bitc;
} STRTH3STR;

__IO_EXTENDED	  STRTH3STR	IO_STRTH3;
#define	_strth3		(IO_STRTH3)
#define	STRTH3		(IO_STRTH3.byte)
#define	STRTH3_STH0  	(IO_STRTH3.bit.STH0)
#define	STRTH3_STH1  	(IO_STRTH3.bit.STH1)
#define	STRTH3_STH2  	(IO_STRTH3.bit.STH2)
#define	STRTH3_STH3  	(IO_STRTH3.bit.STH3)
#define	STRTH3_STH4  	(IO_STRTH3.bit.STH4)
#define	STRTH3_STH5  	(IO_STRTH3.bit.STH5)
#define	STRTH3_STH6  	(IO_STRTH3.bit.STH6)
#define	STRTH3_STH7  	(IO_STRTH3.bit.STH7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_STRTH4,   locate=0xE54
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	STH0:1;
			__BYTE	STH1:1;
			__BYTE	STH2:1;
			__BYTE	STH3:1;
			__BYTE	STH4:1;
			__BYTE	STH5:1;
			__BYTE	STH6:1;
			__BYTE	STH7:1;
	} bit;
	struct {
			__BYTE	STH0:1;
			__BYTE	STH1:1;
			__BYTE	STH2:1;
			__BYTE	STH3:1;
			__BYTE	STH4:1;
			__BYTE	STH5:1;
			__BYTE	STH6:1;
			__BYTE	STH7:1;
	} bitc;
} STRTH4STR;

__IO_EXTENDED	  STRTH4STR	IO_STRTH4;
#define	_strth4		(IO_STRTH4)
#define	STRTH4		(IO_STRTH4.byte)
#define	STRTH4_STH0  	(IO_STRTH4.bit.STH0)
#define	STRTH4_STH1  	(IO_STRTH4.bit.STH1)
#define	STRTH4_STH2  	(IO_STRTH4.bit.STH2)
#define	STRTH4_STH3  	(IO_STRTH4.bit.STH3)
#define	STRTH4_STH4  	(IO_STRTH4.bit.STH4)
#define	STRTH4_STH5  	(IO_STRTH4.bit.STH5)
#define	STRTH4_STH6  	(IO_STRTH4.bit.STH6)
#define	STRTH4_STH7  	(IO_STRTH4.bit.STH7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_STRTH5,   locate=0xE55
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	STH0:1;
			__BYTE	STH1:1;
			__BYTE	STH2:1;
			__BYTE	STH3:1;
			__BYTE	STH4:1;
			__BYTE	STH5:1;
			__BYTE	STH6:1;
			__BYTE	STH7:1;
	} bit;
	struct {
			__BYTE	STH0:1;
			__BYTE	STH1:1;
			__BYTE	STH2:1;
			__BYTE	STH3:1;
			__BYTE	STH4:1;
			__BYTE	STH5:1;
			__BYTE	STH6:1;
			__BYTE	STH7:1;
	} bitc;
} STRTH5STR;

__IO_EXTENDED	  STRTH5STR	IO_STRTH5;
#define	_strth5		(IO_STRTH5)
#define	STRTH5		(IO_STRTH5.byte)
#define	STRTH5_STH0  	(IO_STRTH5.bit.STH0)
#define	STRTH5_STH1  	(IO_STRTH5.bit.STH1)
#define	STRTH5_STH2  	(IO_STRTH5.bit.STH2)
#define	STRTH5_STH3  	(IO_STRTH5.bit.STH3)
#define	STRTH5_STH4  	(IO_STRTH5.bit.STH4)
#define	STRTH5_STH5  	(IO_STRTH5.bit.STH5)
#define	STRTH5_STH6  	(IO_STRTH5.bit.STH6)
#define	STRTH5_STH7  	(IO_STRTH5.bit.STH7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_STR1,   locate=0xE61
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	SR0:1;
			__BYTE	SR1:1;
			__BYTE	SR2:1;
			__BYTE	SR3:1;
			__BYTE	SR4:1;
			__BYTE	SR5:1;
			__BYTE	SR6:1;
			__BYTE	SR7:1;
	} bit;
	struct {
			__BYTE	SR0:1;
			__BYTE	SR1:1;
			__BYTE	SR2:1;
			__BYTE	SR3:1;
			__BYTE	SR4:1;
			__BYTE	SR5:1;
			__BYTE	SR6:1;
			__BYTE	SR7:1;
	} bitc;
} STR1STR;

__IO_EXTENDED	 const  STR1STR	IO_STR1;
#define	_str1		(IO_STR1)
#define	STR1		(IO_STR1.byte)
#define	STR1_SR0  	(IO_STR1.bit.SR0)
#define	STR1_SR1  	(IO_STR1.bit.SR1)
#define	STR1_SR2  	(IO_STR1.bit.SR2)
#define	STR1_SR3  	(IO_STR1.bit.SR3)
#define	STR1_SR4  	(IO_STR1.bit.SR4)
#define	STR1_SR5  	(IO_STR1.bit.SR5)
#define	STR1_SR6  	(IO_STR1.bit.SR6)
#define	STR1_SR7  	(IO_STR1.bit.SR7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_STR2,   locate=0xE62
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	SR0:1;
			__BYTE	SR1:1;
			__BYTE	SR2:1;
			__BYTE	SR3:1;
			__BYTE	SR4:1;
			__BYTE	SR5:1;
			__BYTE	SR6:1;
			__BYTE	SR7:1;
	} bit;
	struct {
			__BYTE	SR0:1;
			__BYTE	SR1:1;
			__BYTE	SR2:1;
			__BYTE	SR3:1;
			__BYTE	SR4:1;
			__BYTE	SR5:1;
			__BYTE	SR6:1;
			__BYTE	SR7:1;
	} bitc;
} STR2STR;

__IO_EXTENDED	 const  STR2STR	IO_STR2;
#define	_str2		(IO_STR2)
#define	STR2		(IO_STR2.byte)
#define	STR2_SR0  	(IO_STR2.bit.SR0)
#define	STR2_SR1  	(IO_STR2.bit.SR1)
#define	STR2_SR2  	(IO_STR2.bit.SR2)
#define	STR2_SR3  	(IO_STR2.bit.SR3)
#define	STR2_SR4  	(IO_STR2.bit.SR4)
#define	STR2_SR5  	(IO_STR2.bit.SR5)
#define	STR2_SR6  	(IO_STR2.bit.SR6)
#define	STR2_SR7  	(IO_STR2.bit.SR7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_STR3,   locate=0xE63
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	SR0:1;
			__BYTE	SR1:1;
			__BYTE	SR2:1;
			__BYTE	SR3:1;
			__BYTE	SR4:1;
			__BYTE	SR5:1;
			__BYTE	SR6:1;
			__BYTE	SR7:1;
	} bit;
	struct {
			__BYTE	SR0:1;
			__BYTE	SR1:1;
			__BYTE	SR2:1;
			__BYTE	SR3:1;
			__BYTE	SR4:1;
			__BYTE	SR5:1;
			__BYTE	SR6:1;
			__BYTE	SR7:1;
	} bitc;
} STR3STR;

__IO_EXTENDED	 const  STR3STR	IO_STR3;
#define	_str3		(IO_STR3)
#define	STR3		(IO_STR3.byte)
#define	STR3_SR0  	(IO_STR3.bit.SR0)
#define	STR3_SR1  	(IO_STR3.bit.SR1)
#define	STR3_SR2  	(IO_STR3.bit.SR2)
#define	STR3_SR3  	(IO_STR3.bit.SR3)
#define	STR3_SR4  	(IO_STR3.bit.SR4)
#define	STR3_SR5  	(IO_STR3.bit.SR5)
#define	STR3_SR6  	(IO_STR3.bit.SR6)
#define	STR3_SR7  	(IO_STR3.bit.SR7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_STR4,   locate=0xE64
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	SR0:1;
			__BYTE	SR1:1;
			__BYTE	SR2:1;
			__BYTE	SR3:1;
			__BYTE	SR4:1;
			__BYTE	SR5:1;
			__BYTE	SR6:1;
			__BYTE	SR7:1;
	} bit;
	struct {
			__BYTE	SR0:1;
			__BYTE	SR1:1;
			__BYTE	SR2:1;
			__BYTE	SR3:1;
			__BYTE	SR4:1;
			__BYTE	SR5:1;
			__BYTE	SR6:1;
			__BYTE	SR7:1;
	} bitc;
} STR4STR;

__IO_EXTENDED	 const  STR4STR	IO_STR4;
#define	_str4		(IO_STR4)
#define	STR4		(IO_STR4.byte)
#define	STR4_SR0  	(IO_STR4.bit.SR0)
#define	STR4_SR1  	(IO_STR4.bit.SR1)
#define	STR4_SR2  	(IO_STR4.bit.SR2)
#define	STR4_SR3  	(IO_STR4.bit.SR3)
#define	STR4_SR4  	(IO_STR4.bit.SR4)
#define	STR4_SR5  	(IO_STR4.bit.SR5)
#define	STR4_SR6  	(IO_STR4.bit.SR6)
#define	STR4_SR7  	(IO_STR4.bit.SR7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_STR5,   locate=0xE65
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	SR0:1;
			__BYTE	SR1:1;
			__BYTE	SR2:1;
			__BYTE	SR3:1;
			__BYTE	SR4:1;
			__BYTE	SR5:1;
			__BYTE	SR6:1;
			__BYTE	SR7:1;
	} bit;
	struct {
			__BYTE	SR0:1;
			__BYTE	SR1:1;
			__BYTE	SR2:1;
			__BYTE	SR3:1;
			__BYTE	SR4:1;
			__BYTE	SR5:1;
			__BYTE	SR6:1;
			__BYTE	SR7:1;
	} bitc;
} STR5STR;

__IO_EXTENDED	 const  STR5STR	IO_STR5;
#define	_str5		(IO_STR5)
#define	STR5		(IO_STR5.byte)
#define	STR5_SR0  	(IO_STR5.bit.SR0)
#define	STR5_SR1  	(IO_STR5.bit.SR1)
#define	STR5_SR2  	(IO_STR5.bit.SR2)
#define	STR5_SR3  	(IO_STR5.bit.SR3)
#define	STR5_SR4  	(IO_STR5.bit.SR4)
#define	STR5_SR5  	(IO_STR5.bit.SR5)
#define	STR5_SR6  	(IO_STR5.bit.SR6)
#define	STR5_SR7  	(IO_STR5.bit.SR7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_CALIP1,   locate=0xE71
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	CIR0:1;
			__BYTE	CIR1:1;
			__BYTE	CIR2:1;
			__BYTE	CIR3:1;
			__BYTE	CIR4:1;
			__BYTE	CIR5:1;
			__BYTE	CIR6:1;
			__BYTE	CIR7:1;
	} bit;
	struct {
			__BYTE	CIR0:1;
			__BYTE	CIR1:1;
			__BYTE	CIR2:1;
			__BYTE	CIR3:1;
			__BYTE	CIR4:1;
			__BYTE	CIR5:1;
			__BYTE	CIR6:1;
			__BYTE	CIR7:1;
	} bitc;
} CALIP1STR;

__IO_EXTENDED	 const  CALIP1STR	IO_CALIP1;
#define	_calip1		(IO_CALIP1)
#define	CALIP1		(IO_CALIP1.byte)
#define	CALIP1_CIR0  	(IO_CALIP1.bit.CIR0)
#define	CALIP1_CIR1  	(IO_CALIP1.bit.CIR1)
#define	CALIP1_CIR2  	(IO_CALIP1.bit.CIR2)
#define	CALIP1_CIR3  	(IO_CALIP1.bit.CIR3)
#define	CALIP1_CIR4  	(IO_CALIP1.bit.CIR4)
#define	CALIP1_CIR5  	(IO_CALIP1.bit.CIR5)
#define	CALIP1_CIR6  	(IO_CALIP1.bit.CIR6)
#define	CALIP1_CIR7  	(IO_CALIP1.bit.CIR7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_CALIP2,   locate=0xE72
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	CIR0:1;
			__BYTE	CIR1:1;
			__BYTE	CIR2:1;
			__BYTE	CIR3:1;
			__BYTE	CIR4:1;
			__BYTE	CIR5:1;
			__BYTE	CIR6:1;
			__BYTE	CIR7:1;
	} bit;
	struct {
			__BYTE	CIR0:1;
			__BYTE	CIR1:1;
			__BYTE	CIR2:1;
			__BYTE	CIR3:1;
			__BYTE	CIR4:1;
			__BYTE	CIR5:1;
			__BYTE	CIR6:1;
			__BYTE	CIR7:1;
	} bitc;
} CALIP2STR;

__IO_EXTENDED	 const  CALIP2STR	IO_CALIP2;
#define	_calip2		(IO_CALIP2)
#define	CALIP2		(IO_CALIP2.byte)
#define	CALIP2_CIR0  	(IO_CALIP2.bit.CIR0)
#define	CALIP2_CIR1  	(IO_CALIP2.bit.CIR1)
#define	CALIP2_CIR2  	(IO_CALIP2.bit.CIR2)
#define	CALIP2_CIR3  	(IO_CALIP2.bit.CIR3)
#define	CALIP2_CIR4  	(IO_CALIP2.bit.CIR4)
#define	CALIP2_CIR5  	(IO_CALIP2.bit.CIR5)
#define	CALIP2_CIR6  	(IO_CALIP2.bit.CIR6)
#define	CALIP2_CIR7  	(IO_CALIP2.bit.CIR7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_CALIP3,   locate=0xE73
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	CIR0:1;
			__BYTE	CIR1:1;
			__BYTE	CIR2:1;
			__BYTE	CIR3:1;
			__BYTE	CIR4:1;
			__BYTE	CIR5:1;
			__BYTE	CIR6:1;
			__BYTE	CIR7:1;
	} bit;
	struct {
			__BYTE	CIR0:1;
			__BYTE	CIR1:1;
			__BYTE	CIR2:1;
			__BYTE	CIR3:1;
			__BYTE	CIR4:1;
			__BYTE	CIR5:1;
			__BYTE	CIR6:1;
			__BYTE	CIR7:1;
	} bitc;
} CALIP3STR;

__IO_EXTENDED	 const  CALIP3STR	IO_CALIP3;
#define	_calip3		(IO_CALIP3)
#define	CALIP3		(IO_CALIP3.byte)
#define	CALIP3_CIR0  	(IO_CALIP3.bit.CIR0)
#define	CALIP3_CIR1  	(IO_CALIP3.bit.CIR1)
#define	CALIP3_CIR2  	(IO_CALIP3.bit.CIR2)
#define	CALIP3_CIR3  	(IO_CALIP3.bit.CIR3)
#define	CALIP3_CIR4  	(IO_CALIP3.bit.CIR4)
#define	CALIP3_CIR5  	(IO_CALIP3.bit.CIR5)
#define	CALIP3_CIR6  	(IO_CALIP3.bit.CIR6)
#define	CALIP3_CIR7  	(IO_CALIP3.bit.CIR7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_CALIP4,   locate=0xE74
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	CIR0:1;
			__BYTE	CIR1:1;
			__BYTE	CIR2:1;
			__BYTE	CIR3:1;
			__BYTE	CIR4:1;
			__BYTE	CIR5:1;
			__BYTE	CIR6:1;
			__BYTE	CIR7:1;
	} bit;
	struct {
			__BYTE	CIR0:1;
			__BYTE	CIR1:1;
			__BYTE	CIR2:1;
			__BYTE	CIR3:1;
			__BYTE	CIR4:1;
			__BYTE	CIR5:1;
			__BYTE	CIR6:1;
			__BYTE	CIR7:1;
	} bitc;
} CALIP4STR;

__IO_EXTENDED	 const  CALIP4STR	IO_CALIP4;
#define	_calip4		(IO_CALIP4)
#define	CALIP4		(IO_CALIP4.byte)
#define	CALIP4_CIR0  	(IO_CALIP4.bit.CIR0)
#define	CALIP4_CIR1  	(IO_CALIP4.bit.CIR1)
#define	CALIP4_CIR2  	(IO_CALIP4.bit.CIR2)
#define	CALIP4_CIR3  	(IO_CALIP4.bit.CIR3)
#define	CALIP4_CIR4  	(IO_CALIP4.bit.CIR4)
#define	CALIP4_CIR5  	(IO_CALIP4.bit.CIR5)
#define	CALIP4_CIR6  	(IO_CALIP4.bit.CIR6)
#define	CALIP4_CIR7  	(IO_CALIP4.bit.CIR7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_CALIP5,   locate=0xE75
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	CIR0:1;
			__BYTE	CIR1:1;
			__BYTE	CIR2:1;
			__BYTE	CIR3:1;
			__BYTE	CIR4:1;
			__BYTE	CIR5:1;
			__BYTE	CIR6:1;
			__BYTE	CIR7:1;
	} bit;
	struct {
			__BYTE	CIR0:1;
			__BYTE	CIR1:1;
			__BYTE	CIR2:1;
			__BYTE	CIR3:1;
			__BYTE	CIR4:1;
			__BYTE	CIR5:1;
			__BYTE	CIR6:1;
			__BYTE	CIR7:1;
	} bitc;
} CALIP5STR;

__IO_EXTENDED	 const  CALIP5STR	IO_CALIP5;
#define	_calip5		(IO_CALIP5)
#define	CALIP5		(IO_CALIP5.byte)
#define	CALIP5_CIR0  	(IO_CALIP5.bit.CIR0)
#define	CALIP5_CIR1  	(IO_CALIP5.bit.CIR1)
#define	CALIP5_CIR2  	(IO_CALIP5.bit.CIR2)
#define	CALIP5_CIR3  	(IO_CALIP5.bit.CIR3)
#define	CALIP5_CIR4  	(IO_CALIP5.bit.CIR4)
#define	CALIP5_CIR5  	(IO_CALIP5.bit.CIR5)
#define	CALIP5_CIR6  	(IO_CALIP5.bit.CIR6)
#define	CALIP5_CIR7  	(IO_CALIP5.bit.CIR7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_IMPE1,   locate=0xE81
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	IR0:1;
			__BYTE	IR1:1;
			__BYTE	IR2:1;
			__BYTE	IR3:1;
			__BYTE	IR4:1;
			__BYTE	IR5:1;
			__BYTE	IR6:1;
			__BYTE	IR7:1;
	} bit;
	struct {
			__BYTE	IR0:1;
			__BYTE	IR1:1;
			__BYTE	IR2:1;
			__BYTE	IR3:1;
			__BYTE	IR4:1;
			__BYTE	IR5:1;
			__BYTE	IR6:1;
			__BYTE	IR7:1;
	} bitc;
} IMPE1STR;

__IO_EXTENDED	 const  IMPE1STR	IO_IMPE1;
#define	_impe1		(IO_IMPE1)
#define	IMPE1		(IO_IMPE1.byte)
#define	IMPE1_IR0  	(IO_IMPE1.bit.IR0)
#define	IMPE1_IR1  	(IO_IMPE1.bit.IR1)
#define	IMPE1_IR2  	(IO_IMPE1.bit.IR2)
#define	IMPE1_IR3  	(IO_IMPE1.bit.IR3)
#define	IMPE1_IR4  	(IO_IMPE1.bit.IR4)
#define	IMPE1_IR5  	(IO_IMPE1.bit.IR5)
#define	IMPE1_IR6  	(IO_IMPE1.bit.IR6)
#define	IMPE1_IR7  	(IO_IMPE1.bit.IR7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_IMPE2,   locate=0xE82
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	IR0:1;
			__BYTE	IR1:1;
			__BYTE	IR2:1;
			__BYTE	IR3:1;
			__BYTE	IR4:1;
			__BYTE	IR5:1;
			__BYTE	IR6:1;
			__BYTE	IR7:1;
	} bit;
	struct {
			__BYTE	IR0:1;
			__BYTE	IR1:1;
			__BYTE	IR2:1;
			__BYTE	IR3:1;
			__BYTE	IR4:1;
			__BYTE	IR5:1;
			__BYTE	IR6:1;
			__BYTE	IR7:1;
	} bitc;
} IMPE2STR;

__IO_EXTENDED	 const  IMPE2STR	IO_IMPE2;
#define	_impe2		(IO_IMPE2)
#define	IMPE2		(IO_IMPE2.byte)
#define	IMPE2_IR0  	(IO_IMPE2.bit.IR0)
#define	IMPE2_IR1  	(IO_IMPE2.bit.IR1)
#define	IMPE2_IR2  	(IO_IMPE2.bit.IR2)
#define	IMPE2_IR3  	(IO_IMPE2.bit.IR3)
#define	IMPE2_IR4  	(IO_IMPE2.bit.IR4)
#define	IMPE2_IR5  	(IO_IMPE2.bit.IR5)
#define	IMPE2_IR6  	(IO_IMPE2.bit.IR6)
#define	IMPE2_IR7  	(IO_IMPE2.bit.IR7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_IMPE3,   locate=0xE83
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	IR0:1;
			__BYTE	IR1:1;
			__BYTE	IR2:1;
			__BYTE	IR3:1;
			__BYTE	IR4:1;
			__BYTE	IR5:1;
			__BYTE	IR6:1;
			__BYTE	IR7:1;
	} bit;
	struct {
			__BYTE	IR0:1;
			__BYTE	IR1:1;
			__BYTE	IR2:1;
			__BYTE	IR3:1;
			__BYTE	IR4:1;
			__BYTE	IR5:1;
			__BYTE	IR6:1;
			__BYTE	IR7:1;
	} bitc;
} IMPE3STR;

__IO_EXTENDED	 const  IMPE3STR	IO_IMPE3;
#define	_impe3		(IO_IMPE3)
#define	IMPE3		(IO_IMPE3.byte)
#define	IMPE3_IR0  	(IO_IMPE3.bit.IR0)
#define	IMPE3_IR1  	(IO_IMPE3.bit.IR1)
#define	IMPE3_IR2  	(IO_IMPE3.bit.IR2)
#define	IMPE3_IR3  	(IO_IMPE3.bit.IR3)
#define	IMPE3_IR4  	(IO_IMPE3.bit.IR4)
#define	IMPE3_IR5  	(IO_IMPE3.bit.IR5)
#define	IMPE3_IR6  	(IO_IMPE3.bit.IR6)
#define	IMPE3_IR7  	(IO_IMPE3.bit.IR7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_IMPE4,   locate=0xE84
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	IR0:1;
			__BYTE	IR1:1;
			__BYTE	IR2:1;
			__BYTE	IR3:1;
			__BYTE	IR4:1;
			__BYTE	IR5:1;
			__BYTE	IR6:1;
			__BYTE	IR7:1;
	} bit;
	struct {
			__BYTE	IR0:1;
			__BYTE	IR1:1;
			__BYTE	IR2:1;
			__BYTE	IR3:1;
			__BYTE	IR4:1;
			__BYTE	IR5:1;
			__BYTE	IR6:1;
			__BYTE	IR7:1;
	} bitc;
} IMPE4STR;

__IO_EXTENDED	 const  IMPE4STR	IO_IMPE4;
#define	_impe4		(IO_IMPE4)
#define	IMPE4		(IO_IMPE4.byte)
#define	IMPE4_IR0  	(IO_IMPE4.bit.IR0)
#define	IMPE4_IR1  	(IO_IMPE4.bit.IR1)
#define	IMPE4_IR2  	(IO_IMPE4.bit.IR2)
#define	IMPE4_IR3  	(IO_IMPE4.bit.IR3)
#define	IMPE4_IR4  	(IO_IMPE4.bit.IR4)
#define	IMPE4_IR5  	(IO_IMPE4.bit.IR5)
#define	IMPE4_IR6  	(IO_IMPE4.bit.IR6)
#define	IMPE4_IR7  	(IO_IMPE4.bit.IR7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_IMPE5,   locate=0xE85
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	IR0:1;
			__BYTE	IR1:1;
			__BYTE	IR2:1;
			__BYTE	IR3:1;
			__BYTE	IR4:1;
			__BYTE	IR5:1;
			__BYTE	IR6:1;
			__BYTE	IR7:1;
	} bit;
	struct {
			__BYTE	IR0:1;
			__BYTE	IR1:1;
			__BYTE	IR2:1;
			__BYTE	IR3:1;
			__BYTE	IR4:1;
			__BYTE	IR5:1;
			__BYTE	IR6:1;
			__BYTE	IR7:1;
	} bitc;
} IMPE5STR;

__IO_EXTENDED	 const  IMPE5STR	IO_IMPE5;
#define	_impe5		(IO_IMPE5)
#define	IMPE5		(IO_IMPE5.byte)
#define	IMPE5_IR0  	(IO_IMPE5.bit.IR0)
#define	IMPE5_IR1  	(IO_IMPE5.bit.IR1)
#define	IMPE5_IR2  	(IO_IMPE5.bit.IR2)
#define	IMPE5_IR3  	(IO_IMPE5.bit.IR3)
#define	IMPE5_IR4  	(IO_IMPE5.bit.IR4)
#define	IMPE5_IR5  	(IO_IMPE5.bit.IR5)
#define	IMPE5_IR6  	(IO_IMPE5.bit.IR6)
#define	IMPE5_IR7  	(IO_IMPE5.bit.IR7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_TOUCHL,   locate=0xE90
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	TS00:1;
			__BYTE	TS01:1;
			__BYTE	TS02:1;
			__BYTE	TS03:1;
			__BYTE	TS04:1;
			__BYTE	TS05:1;
			__BYTE	TS06:1;
			__BYTE	TS07:1;
	} bit;
	struct {
			__BYTE	TS00:1;
			__BYTE	TS01:1;
			__BYTE	TS02:1;
			__BYTE	TS03:1;
			__BYTE	TS04:1;
			__BYTE	TS05:1;
			__BYTE	TS06:1;
			__BYTE	TS07:1;
	} bitc;
} TOUCHLSTR;

__IO_EXTENDED	 const  TOUCHLSTR	IO_TOUCHL;
#define	_touchl		(IO_TOUCHL)
#define	TOUCHL		(IO_TOUCHL.byte)
#define	TOUCHL_TS00  	(IO_TOUCHL.bit.TS00)
#define	TOUCHL_TS01  	(IO_TOUCHL.bit.TS01)
#define	TOUCHL_TS02  	(IO_TOUCHL.bit.TS02)
#define	TOUCHL_TS03  	(IO_TOUCHL.bit.TS03)
#define	TOUCHL_TS04  	(IO_TOUCHL.bit.TS04)
#define	TOUCHL_TS05  	(IO_TOUCHL.bit.TS05)
#define	TOUCHL_TS06  	(IO_TOUCHL.bit.TS06)
#define	TOUCHL_TS07  	(IO_TOUCHL.bit.TS07)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_TOUCHH,   locate=0xE91
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	TS09:1;
			__BYTE	TS10:1;
			__BYTE	TS11:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	TS09:1;
			__BYTE	TS10:1;
			__BYTE	TS11:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} TOUCHHSTR;

__IO_EXTENDED	 const  TOUCHHSTR	IO_TOUCHH;
#define	_touchh		(IO_TOUCHH)
#define	TOUCHH		(IO_TOUCHH.byte)
#define	TOUCHH_TS09  	(IO_TOUCHH.bit.TS09)
#define	TOUCHH_TS10  	(IO_TOUCHH.bit.TS10)
#define	TOUCHH_TS11  	(IO_TOUCHH.bit.TS11)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_INTPR,   locate=0xE92
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	TINT:1;
			__BYTE	ATI:1;
			__BYTE	ITA:1;
			__BYTE	EOC:1;
			__BYTE	NEW:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	TINT:1;
			__BYTE	ATI:1;
			__BYTE	ITA:1;
			__BYTE	EOC:1;
			__BYTE	NEW:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} INTPRSTR;

__IO_EXTENDED	 const  INTPRSTR	IO_INTPR;
#define	_intpr		(IO_INTPR)
#define	INTPR		(IO_INTPR.byte)
#define	INTPR_TINT  	(IO_INTPR.bit.TINT)
#define	INTPR_ATI  	(IO_INTPR.bit.ATI)
#define	INTPR_ITA  	(IO_INTPR.bit.ITA)
#define	INTPR_EOC  	(IO_INTPR.bit.EOC)
#define	INTPR_NEW  	(IO_INTPR.bit.NEW)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_WRAR0,   locate=0xF80
#endif

__IO_EXTENDED	__WORD	IO_WRAR0;
#define	_wrar0		(IO_WRAR0)
#define	WRAR0	(_wrar0)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_WRDR0,   locate=0xF82
#endif

__IO_EXTENDED	__BYTE	IO_WRDR0;
#define	_wrdr0		(IO_WRDR0)
#define	WRDR0	(_wrdr0)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_WRAR1,   locate=0xF83
#endif

__IO_EXTENDED	__WORD	IO_WRAR1;
#define	_wrar1		(IO_WRAR1)
#define	WRAR1	(_wrar1)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_WRDR1,   locate=0xF85
#endif

__IO_EXTENDED	__BYTE	IO_WRDR1;
#define	_wrdr1		(IO_WRDR1)
#define	WRDR1	(_wrdr1)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_WRAR2,   locate=0xF86
#endif

__IO_EXTENDED	__WORD	IO_WRAR2;
#define	_wrar2		(IO_WRAR2)
#define	WRAR2	(_wrar2)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_WRDR2,   locate=0xF88
#endif

__IO_EXTENDED	__BYTE	IO_WRDR2;
#define	_wrdr2		(IO_WRDR2)
#define	WRDR2	(_wrdr2)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_WRAR3,   locate=0xF89
#endif

__IO_EXTENDED	__WORD	IO_WRAR3;
#define	_wrar3		(IO_WRAR3)
#define	WRAR3	(_wrar3)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_WRDR3,   locate=0xF8B
#endif

__IO_EXTENDED	__BYTE	IO_WRDR3;
#define	_wrdr3		(IO_WRDR3)
#define	WRDR3	(_wrdr3)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_T01CR0,   locate=0xF92
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	F0:1;
			__BYTE	F1:1;
			__BYTE	F2:1;
			__BYTE	F3:1;
			__BYTE	C0:1;
			__BYTE	C1:1;
			__BYTE	C2:1;
			__BYTE	IFE:1;
	} bit;
	struct {
			__BYTE	F0:1;
			__BYTE	F1:1;
			__BYTE	F2:1;
			__BYTE	F3:1;
			__BYTE	C0:1;
			__BYTE	C1:1;
			__BYTE	C2:1;
			__BYTE	IFE:1;
	} bitc;
} T01CR0STR;

__IO_EXTENDED	  T01CR0STR	IO_T01CR0;
#define	_t01cr0		(IO_T01CR0)
#define	T01CR0		(IO_T01CR0.byte)
#define	T01CR0_F0  	(IO_T01CR0.bit.F0)
#define	T01CR0_F1  	(IO_T01CR0.bit.F1)
#define	T01CR0_F2  	(IO_T01CR0.bit.F2)
#define	T01CR0_F3  	(IO_T01CR0.bit.F3)
#define	T01CR0_C0  	(IO_T01CR0.bit.C0)
#define	T01CR0_C1  	(IO_T01CR0.bit.C1)
#define	T01CR0_C2  	(IO_T01CR0.bit.C2)
#define	T01CR0_IFE  	(IO_T01CR0.bit.IFE)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_T00CR0,   locate=0xF93
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	F0:1;
			__BYTE	F1:1;
			__BYTE	F2:1;
			__BYTE	F3:1;
			__BYTE	C0:1;
			__BYTE	C1:1;
			__BYTE	C2:1;
			__BYTE	IFE:1;
	} bit;
	struct {
			__BYTE	F0:1;
			__BYTE	F1:1;
			__BYTE	F2:1;
			__BYTE	F3:1;
			__BYTE	C0:1;
			__BYTE	C1:1;
			__BYTE	C2:1;
			__BYTE	IFE:1;
	} bitc;
} T00CR0STR;

__IO_EXTENDED	  T00CR0STR	IO_T00CR0;
#define	_t00cr0		(IO_T00CR0)
#define	T00CR0		(IO_T00CR0.byte)
#define	T00CR0_F0  	(IO_T00CR0.bit.F0)
#define	T00CR0_F1  	(IO_T00CR0.bit.F1)
#define	T00CR0_F2  	(IO_T00CR0.bit.F2)
#define	T00CR0_F3  	(IO_T00CR0.bit.F3)
#define	T00CR0_C0  	(IO_T00CR0.bit.C0)
#define	T00CR0_C1  	(IO_T00CR0.bit.C1)
#define	T00CR0_C2  	(IO_T00CR0.bit.C2)
#define	T00CR0_IFE  	(IO_T00CR0.bit.IFE)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_T01DR,   locate=0xF94
#endif

__IO_EXTENDED	__BYTE	IO_T01DR;
#define	_t01dr		(IO_T01DR)
#define	T01DR	(_t01dr)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_T00DR,   locate=0xF95
#endif

__IO_EXTENDED	__BYTE	IO_T00DR;
#define	_t00dr		(IO_T00DR)
#define	T00DR	(_t00dr)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_TMCR0,   locate=0xF96
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	FE00:1;
			__BYTE	FE01:1;
			__BYTE	FE10:1;
			__BYTE	FE11:1;
			__BYTE	MOD:1;
			__BYTE	TIS:1;
			__BYTE	TO0:1;
			__BYTE	TO1:1;
	} bit;
	struct {
			__BYTE	FE00:1;
			__BYTE	FE01:1;
			__BYTE	FE10:1;
			__BYTE	FE11:1;
			__BYTE	MOD:1;
			__BYTE	TIS:1;
			__BYTE	TO0:1;
			__BYTE	TO1:1;
	} bitc;
} TMCR0STR;

__IO_EXTENDED	  TMCR0STR	IO_TMCR0;
#define	_tmcr0		(IO_TMCR0)
#define	TMCR0		(IO_TMCR0.byte)
#define	TMCR0_FE00  	(IO_TMCR0.bit.FE00)
#define	TMCR0_FE01  	(IO_TMCR0.bit.FE01)
#define	TMCR0_FE10  	(IO_TMCR0.bit.FE10)
#define	TMCR0_FE11  	(IO_TMCR0.bit.FE11)
#define	TMCR0_MOD  	(IO_TMCR0.bit.MOD)
#define	TMCR0_TIS  	(IO_TMCR0.bit.TIS)
#define	TMCR0_TO0  	(IO_TMCR0.bit.TO0)
#define	TMCR0_TO1  	(IO_TMCR0.bit.TO1)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_T11CR0,   locate=0xF97
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	F0:1;
			__BYTE	F1:1;
			__BYTE	F2:1;
			__BYTE	F3:1;
			__BYTE	C0:1;
			__BYTE	C1:1;
			__BYTE	C2:1;
			__BYTE	IFE:1;
	} bit;
	struct {
			__BYTE	F0:1;
			__BYTE	F1:1;
			__BYTE	F2:1;
			__BYTE	F3:1;
			__BYTE	C0:1;
			__BYTE	C1:1;
			__BYTE	C2:1;
			__BYTE	IFE:1;
	} bitc;
} T11CR0STR;

__IO_EXTENDED	  T11CR0STR	IO_T11CR0;
#define	_t11cr0		(IO_T11CR0)
#define	T11CR0		(IO_T11CR0.byte)
#define	T11CR0_F0  	(IO_T11CR0.bit.F0)
#define	T11CR0_F1  	(IO_T11CR0.bit.F1)
#define	T11CR0_F2  	(IO_T11CR0.bit.F2)
#define	T11CR0_F3  	(IO_T11CR0.bit.F3)
#define	T11CR0_C0  	(IO_T11CR0.bit.C0)
#define	T11CR0_C1  	(IO_T11CR0.bit.C1)
#define	T11CR0_C2  	(IO_T11CR0.bit.C2)
#define	T11CR0_IFE  	(IO_T11CR0.bit.IFE)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_T10CR0,   locate=0xF98
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	F0:1;
			__BYTE	F1:1;
			__BYTE	F2:1;
			__BYTE	F3:1;
			__BYTE	C0:1;
			__BYTE	C1:1;
			__BYTE	C2:1;
			__BYTE	IFE:1;
	} bit;
	struct {
			__BYTE	F0:1;
			__BYTE	F1:1;
			__BYTE	F2:1;
			__BYTE	F3:1;
			__BYTE	C0:1;
			__BYTE	C1:1;
			__BYTE	C2:1;
			__BYTE	IFE:1;
	} bitc;
} T10CR0STR;

__IO_EXTENDED	  T10CR0STR	IO_T10CR0;
#define	_t10cr0		(IO_T10CR0)
#define	T10CR0		(IO_T10CR0.byte)
#define	T10CR0_F0  	(IO_T10CR0.bit.F0)
#define	T10CR0_F1  	(IO_T10CR0.bit.F1)
#define	T10CR0_F2  	(IO_T10CR0.bit.F2)
#define	T10CR0_F3  	(IO_T10CR0.bit.F3)
#define	T10CR0_C0  	(IO_T10CR0.bit.C0)
#define	T10CR0_C1  	(IO_T10CR0.bit.C1)
#define	T10CR0_C2  	(IO_T10CR0.bit.C2)
#define	T10CR0_IFE  	(IO_T10CR0.bit.IFE)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_T11DR,   locate=0xF99
#endif

__IO_EXTENDED	__BYTE	IO_T11DR;
#define	_t11dr		(IO_T11DR)
#define	T11DR	(_t11dr)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_T10DR,   locate=0xF9A
#endif

__IO_EXTENDED	__BYTE	IO_T10DR;
#define	_t10dr		(IO_T10DR)
#define	T10DR	(_t10dr)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_TMCR1,   locate=0xF9B
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	FE00:1;
			__BYTE	FE01:1;
			__BYTE	FE10:1;
			__BYTE	FE11:1;
			__BYTE	MOD:1;
			__BYTE	TIS:1;
			__BYTE	TO0:1;
			__BYTE	TO1:1;
	} bit;
	struct {
			__BYTE	FE00:1;
			__BYTE	FE01:1;
			__BYTE	FE10:1;
			__BYTE	FE11:1;
			__BYTE	MOD:1;
			__BYTE	TIS:1;
			__BYTE	TO0:1;
			__BYTE	TO1:1;
	} bitc;
} TMCR1STR;

__IO_EXTENDED	  TMCR1STR	IO_TMCR1;
#define	_tmcr1		(IO_TMCR1)
#define	TMCR1		(IO_TMCR1.byte)
#define	TMCR1_FE00  	(IO_TMCR1.bit.FE00)
#define	TMCR1_FE01  	(IO_TMCR1.bit.FE01)
#define	TMCR1_FE10  	(IO_TMCR1.bit.FE10)
#define	TMCR1_FE11  	(IO_TMCR1.bit.FE11)
#define	TMCR1_MOD  	(IO_TMCR1.bit.MOD)
#define	TMCR1_TIS  	(IO_TMCR1.bit.TIS)
#define	TMCR1_TO0  	(IO_TMCR1.bit.TO0)
#define	TMCR1_TO1  	(IO_TMCR1.bit.TO1)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_PPS01,   locate=0xF9C
#endif

__IO_EXTENDED	__BYTE	IO_PPS01;
#define	_pps01		(IO_PPS01)
#define	PPS01	(_pps01)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_PPS00,   locate=0xF9D
#endif

__IO_EXTENDED	__BYTE	IO_PPS00;
#define	_pps00		(IO_PPS00)
#define	PPS00	(_pps00)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_PDS01,   locate=0xF9E
#endif

__IO_EXTENDED	__BYTE	IO_PDS01;
#define	_pds01		(IO_PDS01)
#define	PDS01	(_pds01)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_PDS00,   locate=0xF9F
#endif

__IO_EXTENDED	__BYTE	IO_PDS00;
#define	_pds00		(IO_PDS00)
#define	PDS00	(_pds00)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_PPGS,   locate=0xFA4
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	PEN00:1;
			__BYTE	PEN01:1;
			__BYTE	PEN10:1;
			__BYTE	PEN11:1;
			__BYTE	PEN20:1;
			__BYTE	PEN21:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	PEN00:1;
			__BYTE	PEN01:1;
			__BYTE	PEN10:1;
			__BYTE	PEN11:1;
			__BYTE	PEN20:1;
			__BYTE	PEN21:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} PPGSSTR;

__IO_EXTENDED	  PPGSSTR	IO_PPGS;
#define	_ppgs		(IO_PPGS)
#define	PPGS		(IO_PPGS.byte)
#define	PPGS_PEN00  	(IO_PPGS.bit.PEN00)
#define	PPGS_PEN01  	(IO_PPGS.bit.PEN01)
#define	PPGS_PEN10  	(IO_PPGS.bit.PEN10)
#define	PPGS_PEN11  	(IO_PPGS.bit.PEN11)
#define	PPGS_PEN20  	(IO_PPGS.bit.PEN20)
#define	PPGS_PEN21  	(IO_PPGS.bit.PEN21)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_REVC,   locate=0xFA5
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	REV00:1;
			__BYTE	REV01:1;
			__BYTE	REV10:1;
			__BYTE	REV11:1;
			__BYTE	REV20:1;
			__BYTE	REV21:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	REV00:1;
			__BYTE	REV01:1;
			__BYTE	REV10:1;
			__BYTE	REV11:1;
			__BYTE	REV20:1;
			__BYTE	REV21:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} REVCSTR;

__IO_EXTENDED	  REVCSTR	IO_REVC;
#define	_revc		(IO_REVC)
#define	REVC		(IO_REVC.byte)
#define	REVC_REV00  	(IO_REVC.bit.REV00)
#define	REVC_REV01  	(IO_REVC.bit.REV01)
#define	REVC_REV10  	(IO_REVC.bit.REV10)
#define	REVC_REV11  	(IO_REVC.bit.REV11)
#define	REVC_REV20  	(IO_REVC.bit.REV20)
#define	REVC_REV21  	(IO_REVC.bit.REV21)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_PSSR0,   locate=0xFBE
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	PSS0:1;
			__BYTE	PSS1:1;
			__BYTE	BRGE:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	PSS0:1;
			__BYTE	PSS1:1;
			__BYTE	BRGE:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} PSSR0STR;

__IO_EXTENDED	  PSSR0STR	IO_PSSR0;
#define	_pssr0		(IO_PSSR0)
#define	PSSR0		(IO_PSSR0.byte)
#define	PSSR0_PSS0  	(IO_PSSR0.bit.PSS0)
#define	PSSR0_PSS1  	(IO_PSSR0.bit.PSS1)
#define	PSSR0_BRGE  	(IO_PSSR0.bit.BRGE)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_BRSR0,   locate=0xFBF
#endif

__IO_EXTENDED	__BYTE	IO_BRSR0;
#define	_brsr0		(IO_BRSR0)
#define	BRSR0	(_brsr0)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_TIDR0,   locate=0xFC0
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	RESV0:1;
			__BYTE	P65:1;
			__BYTE	P66:1;
			__BYTE	P67:1;
			__BYTE	P63:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	RESV0:1;
			__BYTE	P65:1;
			__BYTE	P66:1;
			__BYTE	P67:1;
			__BYTE	P63:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} TIDR0STR;

__IO_EXTENDED	  TIDR0STR	IO_TIDR0;
#define	_tidr0		(IO_TIDR0)
#define	TIDR0		(IO_TIDR0.byte)
#define	TIDR0_P65  	(IO_TIDR0.bit.P65)
#define	TIDR0_P66  	(IO_TIDR0.bit.P66)
#define	TIDR0_P67  	(IO_TIDR0.bit.P67)
#define	TIDR0_P63  	(IO_TIDR0.bit.P63)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_TIDR1,   locate=0xFC1
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	P70:1;
			__BYTE	P71:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	P70:1;
			__BYTE	P71:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} TIDR1STR;

__IO_EXTENDED	  TIDR1STR	IO_TIDR1;
#define	_tidr1		(IO_TIDR1)
#define	TIDR1		(IO_TIDR1.byte)
#define	TIDR1_P70  	(IO_TIDR1.bit.P70)
#define	TIDR1_P71  	(IO_TIDR1.bit.P71)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_AIDRL,   locate=0xFC3
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	P04:1;
			__BYTE	P05:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	P06:1;
			__BYTE	P07:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	P04:1;
			__BYTE	P05:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	P06:1;
			__BYTE	P07:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} AIDRLSTR;

__IO_EXTENDED	  AIDRLSTR	IO_AIDRL;
#define	_aidrl		(IO_AIDRL)
#define	AIDRL		(IO_AIDRL.byte)
#define	AIDRL_P04  	(IO_AIDRL.bit.P04)
#define	AIDRL_P05  	(IO_AIDRL.bit.P05)
#define	AIDRL_P06  	(IO_AIDRL.bit.P06)
#define	AIDRL_P07  	(IO_AIDRL.bit.P07)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_LVDPW,   locate=0xFC4
#endif

__IO_EXTENDED	__BYTE	IO_LVDPW;
#define	_lvdpw		(IO_LVDPW)
#define	LVDPW	(_lvdpw)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_WCDR,   locate=0xFE3
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	RCTR0:1;
			__BYTE	RCTR1:1;
			__BYTE	RCTR2:1;
			__BYTE	RCTR3:1;
			__BYTE	RCTR4:1;
			__BYTE	RCTR5:1;
			__BYTE	CS0:1;
			__BYTE	CS1:1;
	} bit;
	struct {
			__BYTE	RCTR0:1;
			__BYTE	RCTR1:1;
			__BYTE	RCTR2:1;
			__BYTE	RCTR3:1;
			__BYTE	RCTR4:1;
			__BYTE	RCTR5:1;
			__BYTE	CS0:1;
			__BYTE	CS1:1;
	} bitc;
} WCDRSTR;

__IO_EXTENDED	  WCDRSTR	IO_WCDR;
#define	_wcdr		(IO_WCDR)
#define	WCDR		(IO_WCDR.byte)
#define	WCDR_RCTR0  	(IO_WCDR.bit.RCTR0)
#define	WCDR_RCTR1  	(IO_WCDR.bit.RCTR1)
#define	WCDR_RCTR2  	(IO_WCDR.bit.RCTR2)
#define	WCDR_RCTR3  	(IO_WCDR.bit.RCTR3)
#define	WCDR_RCTR4  	(IO_WCDR.bit.RCTR4)
#define	WCDR_RCTR5  	(IO_WCDR.bit.RCTR5)
#define	WCDR_CS0  	(IO_WCDR.bit.CS0)
#define	WCDR_CS1  	(IO_WCDR.bit.CS1)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_CRTH,   locate=0xFE4
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	CRTH0:1;
			__BYTE	CRTH1:1;
			__BYTE	CRTH2:1;
			__BYTE	CRTH3:1;
			__BYTE	CRTH4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	CRTH0:1;
			__BYTE	CRTH1:1;
			__BYTE	CRTH2:1;
			__BYTE	CRTH3:1;
			__BYTE	CRTH4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} CRTHSTR;

__IO_EXTENDED	  CRTHSTR	IO_CRTH;
#define	_crth		(IO_CRTH)
#define	CRTH		(IO_CRTH.byte)
#define	CRTH_CRTH0  	(IO_CRTH.bit.CRTH0)
#define	CRTH_CRTH1  	(IO_CRTH.bit.CRTH1)
#define	CRTH_CRTH2  	(IO_CRTH.bit.CRTH2)
#define	CRTH_CRTH3  	(IO_CRTH.bit.CRTH3)
#define	CRTH_CRTH4  	(IO_CRTH.bit.CRTH4)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_CRTL,   locate=0xFE5
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	CRTL0:1;
			__BYTE	CRTL1:1;
			__BYTE	CRTL2:1;
			__BYTE	CRTL3:1;
			__BYTE	CRTL4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	CRTL0:1;
			__BYTE	CRTL1:1;
			__BYTE	CRTL2:1;
			__BYTE	CRTL3:1;
			__BYTE	CRTL4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} CRTLSTR;

__IO_EXTENDED	  CRTLSTR	IO_CRTL;
#define	_crtl		(IO_CRTL)
#define	CRTL		(IO_CRTL.byte)
#define	CRTL_CRTL0  	(IO_CRTL.bit.CRTL0)
#define	CRTL_CRTL1  	(IO_CRTL.bit.CRTL1)
#define	CRTL_CRTL2  	(IO_CRTL.bit.CRTL2)
#define	CRTL_CRTL3  	(IO_CRTL.bit.CRTL3)
#define	CRTL_CRTL4  	(IO_CRTL.bit.CRTL4)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_CRTDA,   locate=0xFE7
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	CRTDA0:1;
			__BYTE	CRTDA1:1;
			__BYTE	CRTDA2:1;
			__BYTE	CRTDA3:1;
			__BYTE	CRTDA4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	CRTDA0:1;
			__BYTE	CRTDA1:1;
			__BYTE	CRTDA2:1;
			__BYTE	CRTDA3:1;
			__BYTE	CRTDA4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} CRTDASTR;

__IO_EXTENDED	  CRTDASTR	IO_CRTDA;
#define	_crtda		(IO_CRTDA)
#define	CRTDA		(IO_CRTDA.byte)
#define	CRTDA_CRTDA0  	(IO_CRTDA.bit.CRTDA0)
#define	CRTDA_CRTDA1  	(IO_CRTDA.bit.CRTDA1)
#define	CRTDA_CRTDA2  	(IO_CRTDA.bit.CRTDA2)
#define	CRTDA_CRTDA3  	(IO_CRTDA.bit.CRTDA3)
#define	CRTDA_CRTDA4  	(IO_CRTDA.bit.CRTDA4)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_SYSC,   locate=0xFE8
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	RSTEN:1;
			__BYTE	RSTOE:1;
			__BYTE	DIOSEL:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	PFSEL:1;
			__BYTE	PGSEL:1;
	} bit;
	struct {
			__BYTE	RSTEN:1;
			__BYTE	RSTOE:1;
			__BYTE	DIOSEL:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	PFSEL:1;
			__BYTE	PGSEL:1;
	} bitc;
} SYSCSTR;

__IO_EXTENDED	  SYSCSTR	IO_SYSC;
#define	_sysc		(IO_SYSC)
#define	SYSC		(IO_SYSC.byte)
#define	SYSC_RSTEN  	(IO_SYSC.bit.RSTEN)
#define	SYSC_RSTOE  	(IO_SYSC.bit.RSTOE)
#define	SYSC_DIOSEL  	(IO_SYSC.bit.DIOSEL)
#define	SYSC_PFSEL  	(IO_SYSC.bit.PFSEL)
#define	SYSC_PGSEL  	(IO_SYSC.bit.PGSEL)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_CMCR,   locate=0xFE9
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	CMCEN:1;
			__BYTE	TBTSEL0:1;
			__BYTE	TBTSEL1:1;
			__BYTE	TBTSEL2:1;
			__BYTE	CMCSEL:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	CMCEN:1;
			__BYTE	TBTSEL0:1;
			__BYTE	TBTSEL1:1;
			__BYTE	TBTSEL2:1;
			__BYTE	CMCSEL:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} CMCRSTR;

__IO_EXTENDED	  CMCRSTR	IO_CMCR;
#define	_cmcr		(IO_CMCR)
#define	CMCR		(IO_CMCR.byte)
#define	CMCR_CMCEN  	(IO_CMCR.bit.CMCEN)
#define	CMCR_TBTSEL0  	(IO_CMCR.bit.TBTSEL0)
#define	CMCR_TBTSEL1  	(IO_CMCR.bit.TBTSEL1)
#define	CMCR_TBTSEL2  	(IO_CMCR.bit.TBTSEL2)
#define	CMCR_CMCSEL  	(IO_CMCR.bit.CMCSEL)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_CMDR,   locate=0xFEA
#endif

__IO_EXTENDED	const __BYTE	IO_CMDR;
#define	_cmdr		(IO_CMDR)
#define	CMDR	(_cmdr)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_WDTH,   locate=0xFEB
#endif

__IO_EXTENDED	const __BYTE	IO_WDTH;
#define	_wdth		(IO_WDTH)
#define	WDTH	(_wdth)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_WDTL,   locate=0xFEC
#endif

__IO_EXTENDED	const __BYTE	IO_WDTL;
#define	_wdtl		(IO_WDTL)
#define	WDTL	(_wdtl)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_WICR,   locate=0xFEF
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	RESV0:1;
			__BYTE	RESV1:1;
			__BYTE	RESV2:1;
			__BYTE	EC0:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	INT00:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	RESV0:1;
			__BYTE	RESV1:1;
			__BYTE	RESV2:1;
			__BYTE	EC0:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	INT00:1;
			__BYTE	RESV7:1;
	} bitc;
} WICRSTR;

__IO_EXTENDED	  WICRSTR	IO_WICR;
#define	_wicr		(IO_WICR)
#define	WICR		(IO_WICR.byte)
#define	WICR_EC0  	(IO_WICR.bit.EC0)
#define	WICR_INT00  	(IO_WICR.bit.INT00)
