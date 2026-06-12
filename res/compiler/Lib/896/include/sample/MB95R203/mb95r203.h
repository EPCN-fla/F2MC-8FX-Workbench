/*
 MB95R203 Series I/O register declaration file V01L03
 ALL RIGHTS RESERVED, COPYRIGHT (C) FUJITSU MICROELECTRONICS LIMITED 2008
 LICENSED MATERIAL - PROGRAM PROPERTY OF FUJITSU MICROELECTRONICS LIMITED
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
			__BYTE	P00:1;
			__BYTE	P01:1;
			__BYTE	P02:1;
			__BYTE	P03:1;
			__BYTE	P04:1;
			__BYTE	P05:1;
			__BYTE	P06:1;
			__BYTE	P07:1;
	} bit;
	struct {
			__BYTE	P00:1;
			__BYTE	P01:1;
			__BYTE	P02:1;
			__BYTE	P03:1;
			__BYTE	P04:1;
			__BYTE	P05:1;
			__BYTE	P06:1;
			__BYTE	P07:1;
	} bitc;
} PDR0STR;

__IO_EXTERN	  PDR0STR	IO_PDR0;
#define	_pdr0		(IO_PDR0)
#define	PDR0		(IO_PDR0.byte)
#define	PDR0_P00  	(IO_PDR0.bit.P00)
#define	PDR0_P01  	(IO_PDR0.bit.P01)
#define	PDR0_P02  	(IO_PDR0.bit.P02)
#define	PDR0_P03  	(IO_PDR0.bit.P03)
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
			__BYTE	P00:1;
			__BYTE	P01:1;
			__BYTE	P02:1;
			__BYTE	P03:1;
			__BYTE	P04:1;
			__BYTE	P05:1;
			__BYTE	P06:1;
			__BYTE	P07:1;
	} bit;
	struct {
			__BYTE	P00:1;
			__BYTE	P01:1;
			__BYTE	P02:1;
			__BYTE	P03:1;
			__BYTE	P04:1;
			__BYTE	P05:1;
			__BYTE	P06:1;
			__BYTE	P07:1;
	} bitc;
} DDR0STR;

__IO_EXTERN	  DDR0STR	IO_DDR0;
#define	_ddr0		(IO_DDR0)
#define	DDR0		(IO_DDR0.byte)
#define	DDR0_P00  	(IO_DDR0.bit.P00)
#define	DDR0_P01  	(IO_DDR0.bit.P01)
#define	DDR0_P02  	(IO_DDR0.bit.P02)
#define	DDR0_P03  	(IO_DDR0.bit.P03)
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
			__BYTE	RESV0:1;
			__BYTE	RESV1:1;
			__BYTE	P12:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	RESV0:1;
			__BYTE	RESV1:1;
			__BYTE	P12:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} PDR1STR;

__IO_EXTERN	  PDR1STR	IO_PDR1;
#define	_pdr1		(IO_PDR1)
#define	PDR1		(IO_PDR1.byte)
#define	PDR1_P12  	(IO_PDR1.bit.P12)

#ifdef __IO_DEFINE
#pragma segment IO=IO_DDR1, locate=0x3
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	RESV0:1;
			__BYTE	RESV1:1;
			__BYTE	P12:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	RESV0:1;
			__BYTE	RESV1:1;
			__BYTE	P12:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} DDR1STR;

__IO_EXTERN	  DDR1STR	IO_DDR1;
#define	_ddr1		(IO_DDR1)
#define	DDR1		(IO_DDR1.byte)
#define	DDR1_P12  	(IO_DDR1.bit.P12)

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
#pragma segment IO=IO_SYCC, locate=0x7
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	DIV0:1;
			__BYTE	DIV1:1;
			__BYTE	RESV2:1;
			__BYTE	SRDY:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	DIV0:1;
			__BYTE	DIV1:1;
			__BYTE	RESV2:1;
			__BYTE	SRDY:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} SYCCSTR;

__IO_EXTERN	  SYCCSTR	IO_SYCC;
#define	_sycc		(IO_SYCC)
#define	SYCC		(IO_SYCC.byte)
#define	SYCC_DIV0  	(IO_SYCC.bit.DIV0)
#define	SYCC_DIV1  	(IO_SYCC.bit.DIV1)
#define	SYCC_SRDY  	(IO_SYCC.bit.SRDY)

#ifdef __IO_DEFINE
#pragma segment IO=IO_STBC, locate=0x8
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	MRDY:1;
			__BYTE	MCRDY:1;
			__BYTE	SCRDY:1;
			__BYTE	TMD:1;
			__BYTE	SRST:1;
			__BYTE	SPL:1;
			__BYTE	SLP:1;
			__BYTE	STP:1;
	} bit;
	struct {
			__BYTE	MRDY:1;
			__BYTE	MCRDY:1;
			__BYTE	SCRDY:1;
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
#define	STBC_MRDY  	(IO_STBC.bit.MRDY)
#define	STBC_MCRDY  	(IO_STBC.bit.MCRDY)
#define	STBC_SCRDY  	(IO_STBC.bit.SCRDY)
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
			__BYTE	RCS0:1;
			__BYTE	RCS1:1;
			__BYTE	RCM0:1;
			__BYTE	RCM1:1;
	} bit;
	struct {
			__BYTE	MCRE:1;
			__BYTE	SCRE:1;
			__BYTE	MOSCE:1;
			__BYTE	SOSCE:1;
			__BYTE	RCS0:1;
			__BYTE	RCS1:1;
			__BYTE	RCM0:1;
			__BYTE	RCM1:1;
	} bitc;
} SYCC2STR;

__IO_EXTERN	  SYCC2STR	IO_SYCC2;
#define	_sycc2		(IO_SYCC2)
#define	SYCC2		(IO_SYCC2.byte)
#define	SYCC2_MCRE  	(IO_SYCC2.bit.MCRE)
#define	SYCC2_SCRE  	(IO_SYCC2.bit.SCRE)
#define	SYCC2_MOSCE  	(IO_SYCC2.bit.MOSCE)
#define	SYCC2_SOSCE  	(IO_SYCC2.bit.SOSCE)
#define	SYCC2_RCS0  	(IO_SYCC2.bit.RCS0)
#define	SYCC2_RCS1  	(IO_SYCC2.bit.RCS1)
#define	SYCC2_RCM0  	(IO_SYCC2.bit.RCM0)
#define	SYCC2_RCM1  	(IO_SYCC2.bit.RCM1)

#ifdef __IO_DEFINE
#pragma segment IO=IO_PDR6, locate=0x16
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	RESV0:1;
			__BYTE	RESV1:1;
			__BYTE	P62:1;
			__BYTE	P63:1;
			__BYTE	P64:1;
			__BYTE	P65:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	RESV0:1;
			__BYTE	RESV1:1;
			__BYTE	P62:1;
			__BYTE	P63:1;
			__BYTE	P64:1;
			__BYTE	P65:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} PDR6STR;

__IO_EXTERN	  PDR6STR	IO_PDR6;
#define	_pdr6		(IO_PDR6)
#define	PDR6		(IO_PDR6.byte)
#define	PDR6_P62  	(IO_PDR6.bit.P62)
#define	PDR6_P63  	(IO_PDR6.bit.P63)
#define	PDR6_P64  	(IO_PDR6.bit.P64)
#define	PDR6_P65  	(IO_PDR6.bit.P65)

#ifdef __IO_DEFINE
#pragma segment IO=IO_DDR6, locate=0x17
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	RESV0:1;
			__BYTE	RESV1:1;
			__BYTE	P62:1;
			__BYTE	P63:1;
			__BYTE	P64:1;
			__BYTE	P65:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	RESV0:1;
			__BYTE	RESV1:1;
			__BYTE	P62:1;
			__BYTE	P63:1;
			__BYTE	P64:1;
			__BYTE	P65:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} DDR6STR;

__IO_EXTERN	  DDR6STR	IO_DDR6;
#define	_ddr6		(IO_DDR6)
#define	DDR6		(IO_DDR6.byte)
#define	DDR6_P62  	(IO_DDR6.bit.P62)
#define	DDR6_P63  	(IO_DDR6.bit.P63)
#define	DDR6_P64  	(IO_DDR6.bit.P64)
#define	DDR6_P65  	(IO_DDR6.bit.P65)

#ifdef __IO_DEFINE
#pragma segment IO=IO_PDRF, locate=0x28
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	RESV0:1;
			__BYTE	RESV1:1;
			__BYTE	PF2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	RESV0:1;
			__BYTE	RESV1:1;
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
#define	PDRF_PF2  	(IO_PDRF.bit.PF2)

#ifdef __IO_DEFINE
#pragma segment IO=IO_DDRF, locate=0x29
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	RESV0:1;
			__BYTE	RESV1:1;
			__BYTE	PF2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	RESV0:1;
			__BYTE	RESV1:1;
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
			__BYTE	P00:1;
			__BYTE	P01:1;
			__BYTE	P02:1;
			__BYTE	P03:1;
			__BYTE	P04:1;
			__BYTE	P05:1;
			__BYTE	P06:1;
			__BYTE	P07:1;
	} bit;
	struct {
			__BYTE	P00:1;
			__BYTE	P01:1;
			__BYTE	P02:1;
			__BYTE	P03:1;
			__BYTE	P04:1;
			__BYTE	P05:1;
			__BYTE	P06:1;
			__BYTE	P07:1;
	} bitc;
} PUL0STR;

__IO_EXTERN	  PUL0STR	IO_PUL0;
#define	_pul0		(IO_PUL0)
#define	PUL0		(IO_PUL0.byte)
#define	PUL0_P00  	(IO_PUL0.bit.P00)
#define	PUL0_P01  	(IO_PUL0.bit.P01)
#define	PUL0_P02  	(IO_PUL0.bit.P02)
#define	PUL0_P03  	(IO_PUL0.bit.P03)
#define	PUL0_P04  	(IO_PUL0.bit.P04)
#define	PUL0_P05  	(IO_PUL0.bit.P05)
#define	PUL0_P06  	(IO_PUL0.bit.P06)
#define	PUL0_P07  	(IO_PUL0.bit.P07)

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

#if defined(__CPU_MB95R203A__) 

#ifdef __IO_DEFINE
#pragma segment IO=IO_LVDCR, locate=0x47
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	LS0:1;
			__BYTE	LS1:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	LVDEN:1;
			__BYTE	RESV5:1;
			__BYTE	LVDIE:1;
			__BYTE	LVDF:1;
	} bit;
	struct {
			__BYTE	LS0:1;
			__BYTE	LS1:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	LVDEN:1;
			__BYTE	RESV5:1;
			__BYTE	LVDIE:1;
			__BYTE	LVDF:1;
	} bitc;
} LVDCRSTR;

__IO_EXTERN	  LVDCRSTR	IO_LVDCR;
#define	_lvdcr		(IO_LVDCR)
#define	LVDCR		(IO_LVDCR.byte)
#define	LVDCR_LS0  	(IO_LVDCR.bit.LS0)
#define	LVDCR_LS1  	(IO_LVDCR.bit.LS1)
#define	LVDCR_LVDEN  	(IO_LVDCR.bit.LVDEN)
#define	LVDCR_LVDIE  	(IO_LVDCR.bit.LVDIE)
#define	LVDCR_LVDF  	(IO_LVDCR.bit.LVDF)

#endif

#ifdef __IO_DEFINE
#pragma segment IO=IO_EIC10, locate=0x49
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
} EIC10STR;

__IO_EXTERN	  EIC10STR	IO_EIC10;
#define	_eic10		(IO_EIC10)
#define	EIC10		(IO_EIC10.byte)
#define	EIC10_EIE0  	(IO_EIC10.bit.EIE0)
#define	EIC10_SL00  	(IO_EIC10.bit.SL00)
#define	EIC10_SL01  	(IO_EIC10.bit.SL01)
#define	EIC10_EIR0  	(IO_EIC10.bit.EIR0)
#define	EIC10_EIE1  	(IO_EIC10.bit.EIE1)
#define	EIC10_SL10  	(IO_EIC10.bit.SL10)
#define	EIC10_SL11  	(IO_EIC10.bit.SL11)
#define	EIC10_EIR1  	(IO_EIC10.bit.EIR1)

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
#pragma segment IO=IO_FSCR, locate=0x66
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	RESV0:1;
			__BYTE	RESV1:1;
			__BYTE	AIE:1;
			__BYTE	UIE:1;
			__BYTE	LVD:1;
			__BYTE	AREA:1;
			__BYTE	PROT:1;
			__BYTE	UDEF:1;
	} bit;
	struct {
			__BYTE	RESV0:1;
			__BYTE	RESV1:1;
			__BYTE	AIE:1;
			__BYTE	UIE:1;
			__BYTE	LVD:1;
			__BYTE	AREA:1;
			__BYTE	PROT:1;
			__BYTE	UDEF:1;
	} bitc;
} FSCRSTR;

__IO_EXTERN	  FSCRSTR	IO_FSCR;
#define	_fscr		(IO_FSCR)
#define	FSCR		(IO_FSCR.byte)
#define	FSCR_AIE  	(IO_FSCR.bit.AIE)
#define	FSCR_UIE  	(IO_FSCR.bit.UIE)
#define	FSCR_LVD  	(IO_FSCR.bit.LVD)
#define	FSCR_AREA  	(IO_FSCR.bit.AREA)
#define	FSCR_PROT  	(IO_FSCR.bit.PROT)
#define	FSCR_UDEF  	(IO_FSCR.bit.UDEF)

#ifdef __IO_DEFINE
#pragma segment IO=IO_FRAC, locate=0x67
#endif

__IO_EXTERN	__BYTE	IO_FRAC;
#define	_frac		(IO_FRAC)
#define	FRAC	(_frac)

#ifdef __IO_DEFINE
#pragma segment IO=IO_FAB, locate=0x68
#endif

__IO_EXTERN	union {
	__WORD	word;
	struct {
		__BYTE	FABH;
		__BYTE	FABL;
	} byte;
} IO_FAB;

#define	FAB		(IO_FAB.word)
#define	FAB_FABH	(IO_FAB.byte.FABH)
#define	FAB_FABL	(IO_FAB.byte.FABL)

#ifdef __IO_DEFINE
#pragma segment IO=IO_FAS, locate=0x6A
#endif

__IO_EXTERN	union {
	__WORD	word;
	struct {
		__BYTE	FASH;
		__BYTE	FASL;
	} byte;
} IO_FAS;

#define	FAS		(IO_FAS.word)
#define	FAS_FASH	(IO_FAS.byte.FASH)
#define	FAS_FASL	(IO_FAS.byte.FASL)

#ifdef __IO_DEFINE
#pragma segment IO=IO_ADC1, locate=0x6C
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	AD:1;
			__BYTE	ADMVX:1;
			__BYTE	ADMV:1;
			__BYTE	ADI:1;
			__BYTE	ANS0:1;
			__BYTE	ANS1:1;
			__BYTE	ANS2:1;
			__BYTE	ANS3:1;
	} bit;
	struct {
			__BYTE	AD:1;
			__BYTE	ADMVX:1;
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
#define	ADC1_ADMVX  	(IO_ADC1.bit.ADMVX)
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
#pragma segment IO=IO_FVA, locate=0x70
#endif

__IO_EXTERN	const	union {
	__WORD	word;
	struct {
		__BYTE	FVAH;
		__BYTE	FVAL;
	} byte;
} IO_FVA;

#define	FVA		(IO_FVA.word)
#define	FVA_FVAH	(IO_FVA.byte.FVAH)
#define	FVA_FVAL	(IO_FVA.byte.FVAL)

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
#pragma segment     DATA=IO_WRAR0,   locate=0xF80
#endif

__IO_EXTENDED	union {
	__WORD	word;
	struct {
		__BYTE	WRARH0;
		__BYTE	WRARL0;
	} byte;
} IO_WRAR0;

#define	WRAR0		(IO_WRAR0.word)
#define	WRAR0_WRARH0	(IO_WRAR0.byte.WRARH0)
#define	WRAR0_WRARL0	(IO_WRAR0.byte.WRARL0)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_WRDR0,   locate=0xF82
#endif

__IO_EXTENDED	__BYTE	IO_WRDR0;
#define	_wrdr0		(IO_WRDR0)
#define	WRDR0	(_wrdr0)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_WRAR1,   locate=0xF83
#endif

__IO_EXTENDED	union {
	__WORD	word;
	struct {
		__BYTE	WRARH1;
		__BYTE	WRARL1;
	} byte;
} IO_WRAR1;

#define	WRAR1		(IO_WRAR1.word)
#define	WRAR1_WRARH1	(IO_WRAR1.byte.WRARH1)
#define	WRAR1_WRARL1	(IO_WRAR1.byte.WRARL1)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_WRDR1,   locate=0xF85
#endif

__IO_EXTENDED	__BYTE	IO_WRDR1;
#define	_wrdr1		(IO_WRDR1)
#define	WRDR1	(_wrdr1)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_WRAR2,   locate=0xF86
#endif

__IO_EXTENDED	union {
	__WORD	word;
	struct {
		__BYTE	WRARH2;
		__BYTE	WRARL2;
	} byte;
} IO_WRAR2;

#define	WRAR2		(IO_WRAR2.word)
#define	WRAR2_WRARH2	(IO_WRAR2.byte.WRARH2)
#define	WRAR2_WRARL2	(IO_WRAR2.byte.WRARL2)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_WRDR2,   locate=0xF88
#endif

__IO_EXTENDED	__BYTE	IO_WRDR2;
#define	_wrdr2		(IO_WRDR2)
#define	WRDR2	(_wrdr2)

#if defined(__CPU_MB95R203__) 

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_WRAR3,   locate=0xF89
#endif

__IO_EXTENDED	union {
	__WORD	word;
	struct {
		__BYTE	WRARH3;
		__BYTE	WRARL3;
	} byte;
} IO_WRAR3;

#define	WRAR3		(IO_WRAR3.word)
#define	WRAR3_WRARH3	(IO_WRAR3.byte.WRARH3)
#define	WRAR3_WRARL3	(IO_WRAR3.byte.WRARL3)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_WRDR3,   locate=0xF8B
#endif

__IO_EXTENDED	__BYTE	IO_WRDR3;
#define	_wrdr3		(IO_WRDR3)
#define	WRDR3	(_wrdr3)

#endif

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
#pragma segment     DATA=IO_AIDRL,   locate=0xFC3
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	P00:1;
			__BYTE	P01:1;
			__BYTE	P02:1;
			__BYTE	P03:1;
			__BYTE	P04:1;
			__BYTE	P05:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	P00:1;
			__BYTE	P01:1;
			__BYTE	P02:1;
			__BYTE	P03:1;
			__BYTE	P04:1;
			__BYTE	P05:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} AIDRLSTR;

__IO_EXTENDED	  AIDRLSTR	IO_AIDRL;
#define	_aidrl		(IO_AIDRL)
#define	AIDRL		(IO_AIDRL.byte)
#define	AIDRL_P00  	(IO_AIDRL.bit.P00)
#define	AIDRL_P01  	(IO_AIDRL.bit.P01)
#define	AIDRL_P02  	(IO_AIDRL.bit.P02)
#define	AIDRL_P03  	(IO_AIDRL.bit.P03)
#define	AIDRL_P04  	(IO_AIDRL.bit.P04)
#define	AIDRL_P05  	(IO_AIDRL.bit.P05)

#if defined(__CPU_MB95R203__) 

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_CRTH,   locate=0xFE4
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	CRTH0:1;
			__BYTE	CRTH1:1;
			__BYTE	CRTH2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	CRTH0:1;
			__BYTE	CRTH1:1;
			__BYTE	CRTH2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
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

#else


#ifdef __IO_DEFINE
#pragma segment     DATA=IO_CRTH,   locate=0xFE4
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	CRTH0:1;
			__BYTE	CRTH1:1;
			__BYTE	CRTH2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	CRSEL:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	CRTH0:1;
			__BYTE	CRTH1:1;
			__BYTE	CRTH2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	CRSEL:1;
			__BYTE	RESV7:1;
	} bitc;
} CRTHSTR;

__IO_EXTENDED	  CRTHSTR	IO_CRTH;
#define	_crth		(IO_CRTH)
#define	CRTH		(IO_CRTH.byte)
#define	CRTH_CRTH0  	(IO_CRTH.bit.CRTH0)
#define	CRTH_CRTH1  	(IO_CRTH.bit.CRTH1)
#define	CRTH_CRTH2  	(IO_CRTH.bit.CRTH2)
#define	CRTH_CRSEL  	(IO_CRTH.bit.CRSEL)

#endif

#if defined(__CPU_MB95R203__) 

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_CRTL,   locate=0xFE5
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	CRTL0:1;
			__BYTE	CRTL1:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	CRTL0:1;
			__BYTE	CRTL1:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
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

#else


#ifdef __IO_DEFINE
#pragma segment     DATA=IO_CRTL,   locate=0xFE5
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	CRTL0:1;
			__BYTE	CRTL1:1;
			__BYTE	CRTL2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	CRTL0:1;
			__BYTE	CRTL1:1;
			__BYTE	CRTL2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
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

#endif

#if defined(__CPU_MB95R203A__) 

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_LVDCR2,   locate=0xFE6
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
			__BYTE	RESV6:1;
			__BYTE	LVDSTP:1;
	} bit;
	struct {
			__BYTE	RESV0:1;
			__BYTE	RESV1:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	LVDSTP:1;
	} bitc;
} LVDCR2STR;

__IO_EXTENDED	  LVDCR2STR	IO_LVDCR2;
#define	_lvdcr2		(IO_LVDCR2)
#define	LVDCR2		(IO_LVDCR2.byte)
#define	LVDCR2_LVDSTP  	(IO_LVDCR2.bit.LVDSTP)

#endif

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_SYSC,   locate=0xFE8
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	RSTEN:1;
			__BYTE	RSTOE:1;
			__BYTE	RESV2:1;
			__BYTE	EC0SL:1;
			__BYTE	EXCK0:1;
			__BYTE	EXCK1:1;
			__BYTE	RESV6:1;
			__BYTE	PGSEL:1;
	} bit;
	struct {
			__BYTE	RSTEN:1;
			__BYTE	RSTOE:1;
			__BYTE	RESV2:1;
			__BYTE	EC0SL:1;
			__BYTE	EXCK0:1;
			__BYTE	EXCK1:1;
			__BYTE	RESV6:1;
			__BYTE	PGSEL:1;
	} bitc;
} SYSCSTR;

__IO_EXTENDED	  SYSCSTR	IO_SYSC;
#define	_sysc		(IO_SYSC)
#define	SYSC		(IO_SYSC.byte)
#define	SYSC_RSTEN  	(IO_SYSC.bit.RSTEN)
#define	SYSC_RSTOE  	(IO_SYSC.bit.RSTOE)
#define	SYSC_EC0SL  	(IO_SYSC.bit.EC0SL)
#define	SYSC_EXCK0  	(IO_SYSC.bit.EXCK0)
#define	SYSC_EXCK1  	(IO_SYSC.bit.EXCK1)
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

__IO_EXTENDED	__BYTE	IO_CMDR;
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
#pragma segment     DATA=IO_ILSR,   locate=0xFEE
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
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	RESV0:1;
			__BYTE	RESV1:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	P04:1;
			__BYTE	P05:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} ILSRSTR;

__IO_EXTENDED	  ILSRSTR	IO_ILSR;
#define	_ilsr		(IO_ILSR)
#define	ILSR		(IO_ILSR.byte)
#define	ILSR_P04  	(IO_ILSR.bit.P04)
#define	ILSR_P05  	(IO_ILSR.bit.P05)
