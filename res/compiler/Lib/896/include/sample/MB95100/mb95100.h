/*
 MB95100 Series I/O register declaration file V01L02
 ALL RIGHTS RESERVED, COPYRIGHT (C) FUJITSU LIMITED 2004
 LICENSED MATERIAL - PROGRAM PROPERTY OF FUJITSU LIMITED
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
#define	_pdr0		IO_PDR0
#define	PDR0		IO_PDR0.byte
#define	PDR0_P00  	IO_PDR0.bit.P00
#define	PDR0_P01  	IO_PDR0.bit.P01
#define	PDR0_P02  	IO_PDR0.bit.P02
#define	PDR0_P03  	IO_PDR0.bit.P03
#define	PDR0_P04  	IO_PDR0.bit.P04
#define	PDR0_P05  	IO_PDR0.bit.P05
#define	PDR0_P06  	IO_PDR0.bit.P06
#define	PDR0_P07  	IO_PDR0.bit.P07

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
#define	_ddr0		IO_DDR0
#define	DDR0		IO_DDR0.byte
#define	DDR0_P00  	IO_DDR0.bit.P00
#define	DDR0_P01  	IO_DDR0.bit.P01
#define	DDR0_P02  	IO_DDR0.bit.P02
#define	DDR0_P03  	IO_DDR0.bit.P03
#define	DDR0_P04  	IO_DDR0.bit.P04
#define	DDR0_P05  	IO_DDR0.bit.P05
#define	DDR0_P06  	IO_DDR0.bit.P06
#define	DDR0_P07  	IO_DDR0.bit.P07

#ifdef __IO_DEFINE
#pragma segment IO=IO_PDR1, locate=0x2
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	P10:1;
			__BYTE	P11:1;
			__BYTE	P12:1;
			__BYTE	P13:1;
			__BYTE	P14:1;
			__BYTE	P15:1;
			__BYTE	P16:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	P10:1;
			__BYTE	P11:1;
			__BYTE	P12:1;
			__BYTE	P13:1;
			__BYTE	P14:1;
			__BYTE	P15:1;
			__BYTE	P16:1;
			__BYTE	RESV7:1;
	} bitc;
} PDR1STR;

__IO_EXTERN	  PDR1STR	IO_PDR1;
#define	_pdr1		IO_PDR1
#define	PDR1		IO_PDR1.byte
#define	PDR1_P10  	IO_PDR1.bit.P10
#define	PDR1_P11  	IO_PDR1.bit.P11
#define	PDR1_P12  	IO_PDR1.bit.P12
#define	PDR1_P13  	IO_PDR1.bit.P13
#define	PDR1_P14  	IO_PDR1.bit.P14
#define	PDR1_P15  	IO_PDR1.bit.P15
#define	PDR1_P16  	IO_PDR1.bit.P16

#ifdef __IO_DEFINE
#pragma segment IO=IO_DDR1, locate=0x3
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	P10:1;
			__BYTE	P11:1;
			__BYTE	P12:1;
			__BYTE	P13:1;
			__BYTE	P14:1;
			__BYTE	P15:1;
			__BYTE	P16:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	P10:1;
			__BYTE	P11:1;
			__BYTE	P12:1;
			__BYTE	P13:1;
			__BYTE	P14:1;
			__BYTE	P15:1;
			__BYTE	P16:1;
			__BYTE	RESV7:1;
	} bitc;
} DDR1STR;

__IO_EXTERN	  DDR1STR	IO_DDR1;
#define	_ddr1		IO_DDR1
#define	DDR1		IO_DDR1.byte
#define	DDR1_P10  	IO_DDR1.bit.P10
#define	DDR1_P11  	IO_DDR1.bit.P11
#define	DDR1_P12  	IO_DDR1.bit.P12
#define	DDR1_P13  	IO_DDR1.bit.P13
#define	DDR1_P14  	IO_DDR1.bit.P14
#define	DDR1_P15  	IO_DDR1.bit.P15
#define	DDR1_P16  	IO_DDR1.bit.P16

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
#define	_watr		IO_WATR
#define	WATR		IO_WATR.byte
#define	WATR_MWT0  	IO_WATR.bit.MWT0
#define	WATR_MWT1  	IO_WATR.bit.MWT1
#define	WATR_MWT2  	IO_WATR.bit.MWT2
#define	WATR_MWT3  	IO_WATR.bit.MWT3
#define	WATR_SWT0  	IO_WATR.bit.SWT0
#define	WATR_SWT1  	IO_WATR.bit.SWT1
#define	WATR_SWT2  	IO_WATR.bit.SWT2
#define	WATR_SWT3  	IO_WATR.bit.SWT3

#ifdef __IO_DEFINE
#pragma segment IO=IO_PLLC, locate=0x6
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	SPRDY:1;
			__BYTE	SPMC0:1;
			__BYTE	SPMC1:1;
			__BYTE	SPEN:1;
			__BYTE	MPRDY:1;
			__BYTE	MPMC0:1;
			__BYTE	MPMC1:1;
			__BYTE	MPEN:1;
	} bit;
	struct {
			__BYTE	SPRDY:1;
			__BYTE	SPMC0:1;
			__BYTE	SPMC1:1;
			__BYTE	SPEN:1;
			__BYTE	MPRDY:1;
			__BYTE	MPMC0:1;
			__BYTE	MPMC1:1;
			__BYTE	MPEN:1;
	} bitc;
} PLLCSTR;

__IO_EXTERN	  PLLCSTR	IO_PLLC;
#define	_pllc		IO_PLLC
#define	PLLC		IO_PLLC.byte
#define	PLLC_SPRDY  	IO_PLLC.bit.SPRDY
#define	PLLC_SPMC0  	IO_PLLC.bit.SPMC0
#define	PLLC_SPMC1  	IO_PLLC.bit.SPMC1
#define	PLLC_SPEN  	IO_PLLC.bit.SPEN
#define	PLLC_MPRDY  	IO_PLLC.bit.MPRDY
#define	PLLC_MPMC0  	IO_PLLC.bit.MPMC0
#define	PLLC_MPMC1  	IO_PLLC.bit.MPMC1
#define	PLLC_MPEN  	IO_PLLC.bit.MPEN

#ifdef __IO_DEFINE
#pragma segment IO=IO_SYCC, locate=0x7
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	DIV0:1;
			__BYTE	DIV1:1;
			__BYTE	SUBS:1;
			__BYTE	SRDY:1;
			__BYTE	SCS0:1;
			__BYTE	SCS1:1;
			__BYTE	SCM0:1;
			__BYTE	SCM1:1;
	} bit;
	struct {
			__BYTE	DIV0:1;
			__BYTE	DIV1:1;
			__BYTE	SUBS:1;
			__BYTE	SRDY:1;
			__BYTE	SCS0:1;
			__BYTE	SCS1:1;
			__BYTE	SCM0:1;
			__BYTE	SCM1:1;
	} bitc;
} SYCCSTR;

__IO_EXTERN	  SYCCSTR	IO_SYCC;
#define	_sycc		IO_SYCC
#define	SYCC		IO_SYCC.byte
#define	SYCC_DIV0  	IO_SYCC.bit.DIV0
#define	SYCC_DIV1  	IO_SYCC.bit.DIV1
#define	SYCC_SUBS  	IO_SYCC.bit.SUBS
#define	SYCC_SRDY  	IO_SYCC.bit.SRDY
#define	SYCC_SCS0  	IO_SYCC.bit.SCS0
#define	SYCC_SCS1  	IO_SYCC.bit.SCS1
#define	SYCC_SCM0  	IO_SYCC.bit.SCM0
#define	SYCC_SCM1  	IO_SYCC.bit.SCM1

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
#define	_stbc		IO_STBC
#define	STBC		IO_STBC.byte
#define	STBC_TMD  	IO_STBC.bit.TMD
#define	STBC_SRST  	IO_STBC.bit.SRST
#define	STBC_SPL  	IO_STBC.bit.SPL
#define	STBC_SLP  	IO_STBC.bit.SLP
#define	STBC_STP  	IO_STBC.bit.STP

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
			__BYTE	CSVR:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	SWR:1;
			__BYTE	HWR:1;
			__BYTE	PONR:1;
			__BYTE	WDTR:1;
			__BYTE	EXTS:1;
			__BYTE	CSVR:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} RSRRSTR;

__IO_EXTERN	 const  RSRRSTR	IO_RSRR;
#define	_rsrr		IO_RSRR
#define	RSRR		IO_RSRR.byte
#define	RSRR_SWR  	IO_RSRR.bit.SWR
#define	RSRR_HWR  	IO_RSRR.bit.HWR
#define	RSRR_PONR  	IO_RSRR.bit.PONR
#define	RSRR_WDTR  	IO_RSRR.bit.WDTR
#define	RSRR_EXTS  	IO_RSRR.bit.EXTS
#define	RSRR_CSVR  	IO_RSRR.bit.CSVR

#ifdef __IO_DEFINE
#pragma segment IO=IO_TBTC, locate=0xA
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	TCLR:1;
			__BYTE	TBC0:1;
			__BYTE	TBC1:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	TBIE:1;
			__BYTE	TBIF:1;
	} bit;
	struct {
			__BYTE	TCLR:1;
			__BYTE	TBC0:1;
			__BYTE	TBC1:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	TBIE:1;
			__BYTE	TBIF:1;
	} bitc;
} TBTCSTR;

__IO_EXTERN	  TBTCSTR	IO_TBTC;
#define	_tbtc		IO_TBTC
#define	TBTC		IO_TBTC.byte
#define	TBTC_TCLR  	IO_TBTC.bit.TCLR
#define	TBTC_TBC0  	IO_TBTC.bit.TBC0
#define	TBTC_TBC1  	IO_TBTC.bit.TBC1
#define	TBTC_TBIE  	IO_TBTC.bit.TBIE
#define	TBTC_TBIF  	IO_TBTC.bit.TBIF

#ifdef __IO_DEFINE
#pragma segment IO=IO_WPCR, locate=0xB
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	WCLR:1;
			__BYTE	WTC0:1;
			__BYTE	WTC1:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	WTIE:1;
			__BYTE	WTIF:1;
	} bit;
	struct {
			__BYTE	WCLR:1;
			__BYTE	WTC0:1;
			__BYTE	WTC1:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	WTIE:1;
			__BYTE	WTIF:1;
	} bitc;
} WPCRSTR;

__IO_EXTERN	  WPCRSTR	IO_WPCR;
#define	_wpcr		IO_WPCR
#define	WPCR		IO_WPCR.byte
#define	WPCR_WCLR  	IO_WPCR.bit.WCLR
#define	WPCR_WTC0  	IO_WPCR.bit.WTC0
#define	WPCR_WTC1  	IO_WPCR.bit.WTC1
#define	WPCR_WTIE  	IO_WPCR.bit.WTIE
#define	WPCR_WTIF  	IO_WPCR.bit.WTIF

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
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	CS0:1;
			__BYTE	CS1:1;
	} bit;
	struct {
			__BYTE	WTE0:1;
			__BYTE	WTE1:1;
			__BYTE	WTE2:1;
			__BYTE	WTE3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	CS0:1;
			__BYTE	CS1:1;
	} bitc;
} WDTCSTR;

__IO_EXTERN	  WDTCSTR	IO_WDTC;
#define	_wdtc		IO_WDTC
#define	WDTC		IO_WDTC.byte
#define	WDTC_WTE0  	IO_WDTC.bit.WTE0
#define	WDTC_WTE1  	IO_WDTC.bit.WTE1
#define	WDTC_WTE2  	IO_WDTC.bit.WTE2
#define	WDTC_WTE3  	IO_WDTC.bit.WTE3
#define	WDTC_CS0  	IO_WDTC.bit.CS0
#define	WDTC_CS1  	IO_WDTC.bit.CS1

#ifdef __IO_DEFINE
#pragma segment IO=IO_PDR2, locate=0xE
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	P20:1;
			__BYTE	P21:1;
			__BYTE	P22:1;
			__BYTE	P23:1;
			__BYTE	P24:1;
			__BYTE	P25:1;
			__BYTE	P26:1;
			__BYTE	P27:1;
	} bit;
	struct {
			__BYTE	P20:1;
			__BYTE	P21:1;
			__BYTE	P22:1;
			__BYTE	P23:1;
			__BYTE	P24:1;
			__BYTE	P25:1;
			__BYTE	P26:1;
			__BYTE	P27:1;
	} bitc;
} PDR2STR;

__IO_EXTERN	  PDR2STR	IO_PDR2;
#define	_pdr2		IO_PDR2
#define	PDR2		IO_PDR2.byte
#define	PDR2_P20  	IO_PDR2.bit.P20
#define	PDR2_P21  	IO_PDR2.bit.P21
#define	PDR2_P22  	IO_PDR2.bit.P22
#define	PDR2_P23  	IO_PDR2.bit.P23
#define	PDR2_P24  	IO_PDR2.bit.P24
#define	PDR2_P25  	IO_PDR2.bit.P25
#define	PDR2_P26  	IO_PDR2.bit.P26
#define	PDR2_P27  	IO_PDR2.bit.P27

#ifdef __IO_DEFINE
#pragma segment IO=IO_DDR2, locate=0xF
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	P20:1;
			__BYTE	P21:1;
			__BYTE	P22:1;
			__BYTE	P23:1;
			__BYTE	P24:1;
			__BYTE	P25:1;
			__BYTE	P26:1;
			__BYTE	P27:1;
	} bit;
	struct {
			__BYTE	P20:1;
			__BYTE	P21:1;
			__BYTE	P22:1;
			__BYTE	P23:1;
			__BYTE	P24:1;
			__BYTE	P25:1;
			__BYTE	P26:1;
			__BYTE	P27:1;
	} bitc;
} DDR2STR;

__IO_EXTERN	  DDR2STR	IO_DDR2;
#define	_ddr2		IO_DDR2
#define	DDR2		IO_DDR2.byte
#define	DDR2_P20  	IO_DDR2.bit.P20
#define	DDR2_P21  	IO_DDR2.bit.P21
#define	DDR2_P22  	IO_DDR2.bit.P22
#define	DDR2_P23  	IO_DDR2.bit.P23
#define	DDR2_P24  	IO_DDR2.bit.P24
#define	DDR2_P25  	IO_DDR2.bit.P25
#define	DDR2_P26  	IO_DDR2.bit.P26
#define	DDR2_P27  	IO_DDR2.bit.P27

#ifdef __IO_DEFINE
#pragma segment IO=IO_PDR3, locate=0x10
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	P30:1;
			__BYTE	P31:1;
			__BYTE	P32:1;
			__BYTE	P33:1;
			__BYTE	P34:1;
			__BYTE	P35:1;
			__BYTE	P36:1;
			__BYTE	P37:1;
	} bit;
	struct {
			__BYTE	P30:1;
			__BYTE	P31:1;
			__BYTE	P32:1;
			__BYTE	P33:1;
			__BYTE	P34:1;
			__BYTE	P35:1;
			__BYTE	P36:1;
			__BYTE	P37:1;
	} bitc;
} PDR3STR;

__IO_EXTERN	  PDR3STR	IO_PDR3;
#define	_pdr3		IO_PDR3
#define	PDR3		IO_PDR3.byte
#define	PDR3_P30  	IO_PDR3.bit.P30
#define	PDR3_P31  	IO_PDR3.bit.P31
#define	PDR3_P32  	IO_PDR3.bit.P32
#define	PDR3_P33  	IO_PDR3.bit.P33
#define	PDR3_P34  	IO_PDR3.bit.P34
#define	PDR3_P35  	IO_PDR3.bit.P35
#define	PDR3_P36  	IO_PDR3.bit.P36
#define	PDR3_P37  	IO_PDR3.bit.P37

#ifdef __IO_DEFINE
#pragma segment IO=IO_DDR3, locate=0x11
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	P30:1;
			__BYTE	P31:1;
			__BYTE	P32:1;
			__BYTE	P33:1;
			__BYTE	P34:1;
			__BYTE	P35:1;
			__BYTE	P36:1;
			__BYTE	P37:1;
	} bit;
	struct {
			__BYTE	P30:1;
			__BYTE	P31:1;
			__BYTE	P32:1;
			__BYTE	P33:1;
			__BYTE	P34:1;
			__BYTE	P35:1;
			__BYTE	P36:1;
			__BYTE	P37:1;
	} bitc;
} DDR3STR;

__IO_EXTERN	  DDR3STR	IO_DDR3;
#define	_ddr3		IO_DDR3
#define	DDR3		IO_DDR3.byte
#define	DDR3_P30  	IO_DDR3.bit.P30
#define	DDR3_P31  	IO_DDR3.bit.P31
#define	DDR3_P32  	IO_DDR3.bit.P32
#define	DDR3_P33  	IO_DDR3.bit.P33
#define	DDR3_P34  	IO_DDR3.bit.P34
#define	DDR3_P35  	IO_DDR3.bit.P35
#define	DDR3_P36  	IO_DDR3.bit.P36
#define	DDR3_P37  	IO_DDR3.bit.P37

#ifdef __IO_DEFINE
#pragma segment IO=IO_PDR4, locate=0x12
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	P40:1;
			__BYTE	P41:1;
			__BYTE	P42:1;
			__BYTE	P43:1;
			__BYTE	P44:1;
			__BYTE	P45:1;
			__BYTE	P46:1;
			__BYTE	P47:1;
	} bit;
	struct {
			__BYTE	P40:1;
			__BYTE	P41:1;
			__BYTE	P42:1;
			__BYTE	P43:1;
			__BYTE	P44:1;
			__BYTE	P45:1;
			__BYTE	P46:1;
			__BYTE	P47:1;
	} bitc;
} PDR4STR;

__IO_EXTERN	  PDR4STR	IO_PDR4;
#define	_pdr4		IO_PDR4
#define	PDR4		IO_PDR4.byte
#define	PDR4_P40  	IO_PDR4.bit.P40
#define	PDR4_P41  	IO_PDR4.bit.P41
#define	PDR4_P42  	IO_PDR4.bit.P42
#define	PDR4_P43  	IO_PDR4.bit.P43
#define	PDR4_P44  	IO_PDR4.bit.P44
#define	PDR4_P45  	IO_PDR4.bit.P45
#define	PDR4_P46  	IO_PDR4.bit.P46
#define	PDR4_P47  	IO_PDR4.bit.P47

#ifdef __IO_DEFINE
#pragma segment IO=IO_DDR4, locate=0x13
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	P40:1;
			__BYTE	P41:1;
			__BYTE	P42:1;
			__BYTE	P43:1;
			__BYTE	P44:1;
			__BYTE	P45:1;
			__BYTE	P46:1;
			__BYTE	P47:1;
	} bit;
	struct {
			__BYTE	P40:1;
			__BYTE	P41:1;
			__BYTE	P42:1;
			__BYTE	P43:1;
			__BYTE	P44:1;
			__BYTE	P45:1;
			__BYTE	P46:1;
			__BYTE	P47:1;
	} bitc;
} DDR4STR;

__IO_EXTERN	  DDR4STR	IO_DDR4;
#define	_ddr4		IO_DDR4
#define	DDR4		IO_DDR4.byte
#define	DDR4_P40  	IO_DDR4.bit.P40
#define	DDR4_P41  	IO_DDR4.bit.P41
#define	DDR4_P42  	IO_DDR4.bit.P42
#define	DDR4_P43  	IO_DDR4.bit.P43
#define	DDR4_P44  	IO_DDR4.bit.P44
#define	DDR4_P45  	IO_DDR4.bit.P45
#define	DDR4_P46  	IO_DDR4.bit.P46
#define	DDR4_P47  	IO_DDR4.bit.P47

#ifdef __IO_DEFINE
#pragma segment IO=IO_PDR5, locate=0x14
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	P50:1;
			__BYTE	P51:1;
			__BYTE	P52:1;
			__BYTE	P53:1;
			__BYTE	P54:1;
			__BYTE	P55:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	P50:1;
			__BYTE	P51:1;
			__BYTE	P52:1;
			__BYTE	P53:1;
			__BYTE	P54:1;
			__BYTE	P55:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} PDR5STR;

__IO_EXTERN	  PDR5STR	IO_PDR5;
#define	_pdr5		IO_PDR5
#define	PDR5		IO_PDR5.byte
#define	PDR5_P50  	IO_PDR5.bit.P50
#define	PDR5_P51  	IO_PDR5.bit.P51
#define	PDR5_P52  	IO_PDR5.bit.P52
#define	PDR5_P53  	IO_PDR5.bit.P53
#define	PDR5_P54  	IO_PDR5.bit.P54
#define	PDR5_P55  	IO_PDR5.bit.P55

#ifdef __IO_DEFINE
#pragma segment IO=IO_DDR5, locate=0x15
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	P50:1;
			__BYTE	P51:1;
			__BYTE	P52:1;
			__BYTE	P53:1;
			__BYTE	P54:1;
			__BYTE	P55:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	P50:1;
			__BYTE	P51:1;
			__BYTE	P52:1;
			__BYTE	P53:1;
			__BYTE	P54:1;
			__BYTE	P55:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} DDR5STR;

__IO_EXTERN	  DDR5STR	IO_DDR5;
#define	_ddr5		IO_DDR5
#define	DDR5		IO_DDR5.byte
#define	DDR5_P50  	IO_DDR5.bit.P50
#define	DDR5_P51  	IO_DDR5.bit.P51
#define	DDR5_P52  	IO_DDR5.bit.P52
#define	DDR5_P53  	IO_DDR5.bit.P53
#define	DDR5_P54  	IO_DDR5.bit.P54
#define	DDR5_P55  	IO_DDR5.bit.P55

#ifdef __IO_DEFINE
#pragma segment IO=IO_PDR6, locate=0x16
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	P60:1;
			__BYTE	P61:1;
			__BYTE	P62:1;
			__BYTE	P63:1;
			__BYTE	P64:1;
			__BYTE	P65:1;
			__BYTE	P66:1;
			__BYTE	P67:1;
	} bit;
	struct {
			__BYTE	P60:1;
			__BYTE	P61:1;
			__BYTE	P62:1;
			__BYTE	P63:1;
			__BYTE	P64:1;
			__BYTE	P65:1;
			__BYTE	P66:1;
			__BYTE	P67:1;
	} bitc;
} PDR6STR;

__IO_EXTERN	  PDR6STR	IO_PDR6;
#define	_pdr6		IO_PDR6
#define	PDR6		IO_PDR6.byte
#define	PDR6_P60  	IO_PDR6.bit.P60
#define	PDR6_P61  	IO_PDR6.bit.P61
#define	PDR6_P62  	IO_PDR6.bit.P62
#define	PDR6_P63  	IO_PDR6.bit.P63
#define	PDR6_P64  	IO_PDR6.bit.P64
#define	PDR6_P65  	IO_PDR6.bit.P65
#define	PDR6_P66  	IO_PDR6.bit.P66
#define	PDR6_P67  	IO_PDR6.bit.P67

#ifdef __IO_DEFINE
#pragma segment IO=IO_DDR6, locate=0x17
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	P60:1;
			__BYTE	P61:1;
			__BYTE	P62:1;
			__BYTE	P63:1;
			__BYTE	P64:1;
			__BYTE	P65:1;
			__BYTE	P66:1;
			__BYTE	P67:1;
	} bit;
	struct {
			__BYTE	P60:1;
			__BYTE	P61:1;
			__BYTE	P62:1;
			__BYTE	P63:1;
			__BYTE	P64:1;
			__BYTE	P65:1;
			__BYTE	P66:1;
			__BYTE	P67:1;
	} bitc;
} DDR6STR;

__IO_EXTERN	  DDR6STR	IO_DDR6;
#define	_ddr6		IO_DDR6
#define	DDR6		IO_DDR6.byte
#define	DDR6_P60  	IO_DDR6.bit.P60
#define	DDR6_P61  	IO_DDR6.bit.P61
#define	DDR6_P62  	IO_DDR6.bit.P62
#define	DDR6_P63  	IO_DDR6.bit.P63
#define	DDR6_P64  	IO_DDR6.bit.P64
#define	DDR6_P65  	IO_DDR6.bit.P65
#define	DDR6_P66  	IO_DDR6.bit.P66
#define	DDR6_P67  	IO_DDR6.bit.P67

#ifdef __IO_DEFINE
#pragma segment IO=IO_PDR7, locate=0x18
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	P70:1;
			__BYTE	P71:1;
			__BYTE	P72:1;
			__BYTE	P73:1;
			__BYTE	P74:1;
			__BYTE	P75:1;
			__BYTE	P76:1;
			__BYTE	P77:1;
	} bit;
	struct {
			__BYTE	P70:1;
			__BYTE	P71:1;
			__BYTE	P72:1;
			__BYTE	P73:1;
			__BYTE	P74:1;
			__BYTE	P75:1;
			__BYTE	P76:1;
			__BYTE	P77:1;
	} bitc;
} PDR7STR;

__IO_EXTERN	  PDR7STR	IO_PDR7;
#define	_pdr7		IO_PDR7
#define	PDR7		IO_PDR7.byte
#define	PDR7_P70  	IO_PDR7.bit.P70
#define	PDR7_P71  	IO_PDR7.bit.P71
#define	PDR7_P72  	IO_PDR7.bit.P72
#define	PDR7_P73  	IO_PDR7.bit.P73
#define	PDR7_P74  	IO_PDR7.bit.P74
#define	PDR7_P75  	IO_PDR7.bit.P75
#define	PDR7_P76  	IO_PDR7.bit.P76
#define	PDR7_P77  	IO_PDR7.bit.P77

#ifdef __IO_DEFINE
#pragma segment IO=IO_DDR7, locate=0x19
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	P70:1;
			__BYTE	P71:1;
			__BYTE	P72:1;
			__BYTE	P73:1;
			__BYTE	P74:1;
			__BYTE	P75:1;
			__BYTE	P76:1;
			__BYTE	P77:1;
	} bit;
	struct {
			__BYTE	P70:1;
			__BYTE	P71:1;
			__BYTE	P72:1;
			__BYTE	P73:1;
			__BYTE	P74:1;
			__BYTE	P75:1;
			__BYTE	P76:1;
			__BYTE	P77:1;
	} bitc;
} DDR7STR;

__IO_EXTERN	  DDR7STR	IO_DDR7;
#define	_ddr7		IO_DDR7
#define	DDR7		IO_DDR7.byte
#define	DDR7_P70  	IO_DDR7.bit.P70
#define	DDR7_P71  	IO_DDR7.bit.P71
#define	DDR7_P72  	IO_DDR7.bit.P72
#define	DDR7_P73  	IO_DDR7.bit.P73
#define	DDR7_P74  	IO_DDR7.bit.P74
#define	DDR7_P75  	IO_DDR7.bit.P75
#define	DDR7_P76  	IO_DDR7.bit.P76
#define	DDR7_P77  	IO_DDR7.bit.P77

#ifdef __IO_DEFINE
#pragma segment IO=IO_PDR8, locate=0x1A
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	P80:1;
			__BYTE	P81:1;
			__BYTE	P82:1;
			__BYTE	P83:1;
			__BYTE	P84:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	P80:1;
			__BYTE	P81:1;
			__BYTE	P82:1;
			__BYTE	P83:1;
			__BYTE	P84:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} PDR8STR;

__IO_EXTERN	  PDR8STR	IO_PDR8;
#define	_pdr8		IO_PDR8
#define	PDR8		IO_PDR8.byte
#define	PDR8_P80  	IO_PDR8.bit.P80
#define	PDR8_P81  	IO_PDR8.bit.P81
#define	PDR8_P82  	IO_PDR8.bit.P82
#define	PDR8_P83  	IO_PDR8.bit.P83
#define	PDR8_P84  	IO_PDR8.bit.P84

#ifdef __IO_DEFINE
#pragma segment IO=IO_DDR8, locate=0x1B
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	P80:1;
			__BYTE	P81:1;
			__BYTE	P82:1;
			__BYTE	P83:1;
			__BYTE	P84:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	P80:1;
			__BYTE	P81:1;
			__BYTE	P82:1;
			__BYTE	P83:1;
			__BYTE	P84:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} DDR8STR;

__IO_EXTERN	  DDR8STR	IO_DDR8;
#define	_ddr8		IO_DDR8
#define	DDR8		IO_DDR8.byte
#define	DDR8_P80  	IO_DDR8.bit.P80
#define	DDR8_P81  	IO_DDR8.bit.P81
#define	DDR8_P82  	IO_DDR8.bit.P82
#define	DDR8_P83  	IO_DDR8.bit.P83
#define	DDR8_P84  	IO_DDR8.bit.P84

#ifdef __IO_DEFINE
#pragma segment IO=IO_PDRE, locate=0x26
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	PE0:1;
			__BYTE	PE1:1;
			__BYTE	PE2:1;
			__BYTE	PE3:1;
			__BYTE	PE4:1;
			__BYTE	PE5:1;
			__BYTE	PE6:1;
			__BYTE	PE7:1;
	} bit;
	struct {
			__BYTE	PE0:1;
			__BYTE	PE1:1;
			__BYTE	PE2:1;
			__BYTE	PE3:1;
			__BYTE	PE4:1;
			__BYTE	PE5:1;
			__BYTE	PE6:1;
			__BYTE	PE7:1;
	} bitc;
} PDRESTR;

__IO_EXTERN	  PDRESTR	IO_PDRE;
#define	_pdre		IO_PDRE
#define	PDRE		IO_PDRE.byte
#define	PDRE_PE0  	IO_PDRE.bit.PE0
#define	PDRE_PE1  	IO_PDRE.bit.PE1
#define	PDRE_PE2  	IO_PDRE.bit.PE2
#define	PDRE_PE3  	IO_PDRE.bit.PE3
#define	PDRE_PE4  	IO_PDRE.bit.PE4
#define	PDRE_PE5  	IO_PDRE.bit.PE5
#define	PDRE_PE6  	IO_PDRE.bit.PE6
#define	PDRE_PE7  	IO_PDRE.bit.PE7

#ifdef __IO_DEFINE
#pragma segment IO=IO_DDRE, locate=0x27
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	PE0:1;
			__BYTE	PE1:1;
			__BYTE	PE2:1;
			__BYTE	PE3:1;
			__BYTE	PE4:1;
			__BYTE	PE5:1;
			__BYTE	PE6:1;
			__BYTE	PE7:1;
	} bit;
	struct {
			__BYTE	PE0:1;
			__BYTE	PE1:1;
			__BYTE	PE2:1;
			__BYTE	PE3:1;
			__BYTE	PE4:1;
			__BYTE	PE5:1;
			__BYTE	PE6:1;
			__BYTE	PE7:1;
	} bitc;
} DDRESTR;

__IO_EXTERN	  DDRESTR	IO_DDRE;
#define	_ddre		IO_DDRE
#define	DDRE		IO_DDRE.byte
#define	DDRE_PE0  	IO_DDRE.bit.PE0
#define	DDRE_PE1  	IO_DDRE.bit.PE1
#define	DDRE_PE2  	IO_DDRE.bit.PE2
#define	DDRE_PE3  	IO_DDRE.bit.PE3
#define	DDRE_PE4  	IO_DDRE.bit.PE4
#define	DDRE_PE5  	IO_DDRE.bit.PE5
#define	DDRE_PE6  	IO_DDRE.bit.PE6
#define	DDRE_PE7  	IO_DDRE.bit.PE7

#ifdef __IO_DEFINE
#pragma segment IO=IO_PDRG, locate=0x2A
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	PG0:1;
			__BYTE	PG1:1;
			__BYTE	PG2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	PG0:1;
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
#define	_pdrg		IO_PDRG
#define	PDRG		IO_PDRG.byte
#define	PDRG_PG0  	IO_PDRG.bit.PG0
#define	PDRG_PG1  	IO_PDRG.bit.PG1
#define	PDRG_PG2  	IO_PDRG.bit.PG2

#ifdef __IO_DEFINE
#pragma segment IO=IO_DDRG, locate=0x2B
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	PG0:1;
			__BYTE	PG1:1;
			__BYTE	PG2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	PG0:1;
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
#define	_ddrg		IO_DDRG
#define	DDRG		IO_DDRG.byte
#define	DDRG_PG0  	IO_DDRG.bit.PG0
#define	DDRG_PG1  	IO_DDRG.bit.PG1
#define	DDRG_PG2  	IO_DDRG.bit.PG2

#ifdef __IO_DEFINE
#pragma segment IO=IO_PUL1, locate=0x2D
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	P10:1;
			__BYTE	P11:1;
			__BYTE	P12:1;
			__BYTE	P13:1;
			__BYTE	P14:1;
			__BYTE	P15:1;
			__BYTE	P16:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	P10:1;
			__BYTE	P11:1;
			__BYTE	P12:1;
			__BYTE	P13:1;
			__BYTE	P14:1;
			__BYTE	P15:1;
			__BYTE	P16:1;
			__BYTE	RESV7:1;
	} bitc;
} PUL1STR;

__IO_EXTERN	  PUL1STR	IO_PUL1;
#define	_pul1		IO_PUL1
#define	PUL1		IO_PUL1.byte
#define	PUL1_P10  	IO_PUL1.bit.P10
#define	PUL1_P11  	IO_PUL1.bit.P11
#define	PUL1_P12  	IO_PUL1.bit.P12
#define	PUL1_P13  	IO_PUL1.bit.P13
#define	PUL1_P14  	IO_PUL1.bit.P14
#define	PUL1_P15  	IO_PUL1.bit.P15
#define	PUL1_P16  	IO_PUL1.bit.P16

#ifdef __IO_DEFINE
#pragma segment IO=IO_PUL2, locate=0x2E
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	P20:1;
			__BYTE	P21:1;
			__BYTE	P22:1;
			__BYTE	P23:1;
			__BYTE	P24:1;
			__BYTE	P25:1;
			__BYTE	P26:1;
			__BYTE	P27:1;
	} bit;
	struct {
			__BYTE	P20:1;
			__BYTE	P21:1;
			__BYTE	P22:1;
			__BYTE	P23:1;
			__BYTE	P24:1;
			__BYTE	P25:1;
			__BYTE	P26:1;
			__BYTE	P27:1;
	} bitc;
} PUL2STR;

__IO_EXTERN	  PUL2STR	IO_PUL2;
#define	_pul2		IO_PUL2
#define	PUL2		IO_PUL2.byte
#define	PUL2_P20  	IO_PUL2.bit.P20
#define	PUL2_P21  	IO_PUL2.bit.P21
#define	PUL2_P22  	IO_PUL2.bit.P22
#define	PUL2_P23  	IO_PUL2.bit.P23
#define	PUL2_P24  	IO_PUL2.bit.P24
#define	PUL2_P25  	IO_PUL2.bit.P25
#define	PUL2_P26  	IO_PUL2.bit.P26
#define	PUL2_P27  	IO_PUL2.bit.P27

#ifdef __IO_DEFINE
#pragma segment IO=IO_PUL3, locate=0x2F
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	P30:1;
			__BYTE	P31:1;
			__BYTE	P32:1;
			__BYTE	P33:1;
			__BYTE	P34:1;
			__BYTE	P35:1;
			__BYTE	P36:1;
			__BYTE	P37:1;
	} bit;
	struct {
			__BYTE	P30:1;
			__BYTE	P31:1;
			__BYTE	P32:1;
			__BYTE	P33:1;
			__BYTE	P34:1;
			__BYTE	P35:1;
			__BYTE	P36:1;
			__BYTE	P37:1;
	} bitc;
} PUL3STR;

__IO_EXTERN	  PUL3STR	IO_PUL3;
#define	_pul3		IO_PUL3
#define	PUL3		IO_PUL3.byte
#define	PUL3_P30  	IO_PUL3.bit.P30
#define	PUL3_P31  	IO_PUL3.bit.P31
#define	PUL3_P32  	IO_PUL3.bit.P32
#define	PUL3_P33  	IO_PUL3.bit.P33
#define	PUL3_P34  	IO_PUL3.bit.P34
#define	PUL3_P35  	IO_PUL3.bit.P35
#define	PUL3_P36  	IO_PUL3.bit.P36
#define	PUL3_P37  	IO_PUL3.bit.P37

#ifdef __IO_DEFINE
#pragma segment IO=IO_PUL4, locate=0x30
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	P40:1;
			__BYTE	P41:1;
			__BYTE	P42:1;
			__BYTE	P43:1;
			__BYTE	P44:1;
			__BYTE	P45:1;
			__BYTE	P46:1;
			__BYTE	P47:1;
	} bit;
	struct {
			__BYTE	P40:1;
			__BYTE	P41:1;
			__BYTE	P42:1;
			__BYTE	P43:1;
			__BYTE	P44:1;
			__BYTE	P45:1;
			__BYTE	P46:1;
			__BYTE	P47:1;
	} bitc;
} PUL4STR;

__IO_EXTERN	  PUL4STR	IO_PUL4;
#define	_pul4		IO_PUL4
#define	PUL4		IO_PUL4.byte
#define	PUL4_P40  	IO_PUL4.bit.P40
#define	PUL4_P41  	IO_PUL4.bit.P41
#define	PUL4_P42  	IO_PUL4.bit.P42
#define	PUL4_P43  	IO_PUL4.bit.P43
#define	PUL4_P44  	IO_PUL4.bit.P44
#define	PUL4_P45  	IO_PUL4.bit.P45
#define	PUL4_P46  	IO_PUL4.bit.P46
#define	PUL4_P47  	IO_PUL4.bit.P47

#ifdef __IO_DEFINE
#pragma segment IO=IO_PUL5, locate=0x31
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	RESV0:1;
			__BYTE	RESV1:1;
			__BYTE	P52:1;
			__BYTE	P53:1;
			__BYTE	P54:1;
			__BYTE	P55:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	RESV0:1;
			__BYTE	RESV1:1;
			__BYTE	P52:1;
			__BYTE	P53:1;
			__BYTE	P54:1;
			__BYTE	P55:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} PUL5STR;

__IO_EXTERN	  PUL5STR	IO_PUL5;
#define	_pul5		IO_PUL5
#define	PUL5		IO_PUL5.byte
#define	PUL5_P52  	IO_PUL5.bit.P52
#define	PUL5_P53  	IO_PUL5.bit.P53
#define	PUL5_P54  	IO_PUL5.bit.P54
#define	PUL5_P55  	IO_PUL5.bit.P55

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
			__BYTE	P74:1;
			__BYTE	P75:1;
			__BYTE	P76:1;
			__BYTE	P77:1;
	} bit;
	struct {
			__BYTE	P70:1;
			__BYTE	P71:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	P74:1;
			__BYTE	P75:1;
			__BYTE	P76:1;
			__BYTE	P77:1;
	} bitc;
} PUL7STR;

__IO_EXTERN	  PUL7STR	IO_PUL7;
#define	_pul7		IO_PUL7
#define	PUL7		IO_PUL7.byte
#define	PUL7_P70  	IO_PUL7.bit.P70
#define	PUL7_P71  	IO_PUL7.bit.P71
#define	PUL7_P74  	IO_PUL7.bit.P74
#define	PUL7_P75  	IO_PUL7.bit.P75
#define	PUL7_P76  	IO_PUL7.bit.P76
#define	PUL7_P77  	IO_PUL7.bit.P77

#ifdef __IO_DEFINE
#pragma segment IO=IO_PULE, locate=0x34
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	PE0:1;
			__BYTE	PE1:1;
			__BYTE	PE2:1;
			__BYTE	PE3:1;
			__BYTE	PE4:1;
			__BYTE	PE5:1;
			__BYTE	PE6:1;
			__BYTE	PE7:1;
	} bit;
	struct {
			__BYTE	PE0:1;
			__BYTE	PE1:1;
			__BYTE	PE2:1;
			__BYTE	PE3:1;
			__BYTE	PE4:1;
			__BYTE	PE5:1;
			__BYTE	PE6:1;
			__BYTE	PE7:1;
	} bitc;
} PULESTR;

__IO_EXTERN	  PULESTR	IO_PULE;
#define	_pule		IO_PULE
#define	PULE		IO_PULE.byte
#define	PULE_PE0  	IO_PULE.bit.PE0
#define	PULE_PE1  	IO_PULE.bit.PE1
#define	PULE_PE2  	IO_PULE.bit.PE2
#define	PULE_PE3  	IO_PULE.bit.PE3
#define	PULE_PE4  	IO_PULE.bit.PE4
#define	PULE_PE5  	IO_PULE.bit.PE5
#define	PULE_PE6  	IO_PULE.bit.PE6
#define	PULE_PE7  	IO_PULE.bit.PE7

#ifdef __IO_DEFINE
#pragma segment IO=IO_PULG, locate=0x35
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	PG0:1;
			__BYTE	PG1:1;
			__BYTE	PG2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	PG0:1;
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
#define	_pulg		IO_PULG
#define	PULG		IO_PULG.byte
#define	PULG_PG0  	IO_PULG.bit.PG0
#define	PULG_PG1  	IO_PULG.bit.PG1
#define	PULG_PG2  	IO_PULG.bit.PG2

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
#define	_t01cr1		IO_T01CR1
#define	T01CR1		IO_T01CR1.byte
#define	T01CR1_OE  	IO_T01CR1.bit.OE
#define	T01CR1_SO  	IO_T01CR1.bit.SO
#define	T01CR1_IF  	IO_T01CR1.bit.IF
#define	T01CR1_BF  	IO_T01CR1.bit.BF
#define	T01CR1_IR  	IO_T01CR1.bit.IR
#define	T01CR1_IE  	IO_T01CR1.bit.IE
#define	T01CR1_HO  	IO_T01CR1.bit.HO
#define	T01CR1_STA  	IO_T01CR1.bit.STA

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
#define	_t00cr1		IO_T00CR1
#define	T00CR1		IO_T00CR1.byte
#define	T00CR1_OE  	IO_T00CR1.bit.OE
#define	T00CR1_SO  	IO_T00CR1.bit.SO
#define	T00CR1_IF  	IO_T00CR1.bit.IF
#define	T00CR1_BF  	IO_T00CR1.bit.BF
#define	T00CR1_IR  	IO_T00CR1.bit.IR
#define	T00CR1_IE  	IO_T00CR1.bit.IE
#define	T00CR1_HO  	IO_T00CR1.bit.HO
#define	T00CR1_STA  	IO_T00CR1.bit.STA

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
#define	_t11cr1		IO_T11CR1
#define	T11CR1		IO_T11CR1.byte
#define	T11CR1_OE  	IO_T11CR1.bit.OE
#define	T11CR1_SO  	IO_T11CR1.bit.SO
#define	T11CR1_IF  	IO_T11CR1.bit.IF
#define	T11CR1_BF  	IO_T11CR1.bit.BF
#define	T11CR1_IR  	IO_T11CR1.bit.IR
#define	T11CR1_IE  	IO_T11CR1.bit.IE
#define	T11CR1_HO  	IO_T11CR1.bit.HO
#define	T11CR1_STA  	IO_T11CR1.bit.STA

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
#define	_t10cr1		IO_T10CR1
#define	T10CR1		IO_T10CR1.byte
#define	T10CR1_OE  	IO_T10CR1.bit.OE
#define	T10CR1_SO  	IO_T10CR1.bit.SO
#define	T10CR1_IF  	IO_T10CR1.bit.IF
#define	T10CR1_BF  	IO_T10CR1.bit.BF
#define	T10CR1_IR  	IO_T10CR1.bit.IR
#define	T10CR1_IE  	IO_T10CR1.bit.IE
#define	T10CR1_HO  	IO_T10CR1.bit.HO
#define	T10CR1_STA  	IO_T10CR1.bit.STA

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
#define	_pc01		IO_PC01
#define	PC01		IO_PC01.byte
#define	PC01_CKS10  	IO_PC01.bit.CKS10
#define	PC01_CKS11  	IO_PC01.bit.CKS11
#define	PC01_CKS12  	IO_PC01.bit.CKS12
#define	PC01_POEN1  	IO_PC01.bit.POEN1
#define	PC01_PUF1  	IO_PC01.bit.PUF1
#define	PC01_PIE1  	IO_PC01.bit.PIE1

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
#define	_pc00		IO_PC00
#define	PC00		IO_PC00.byte
#define	PC00_CKS00  	IO_PC00.bit.CKS00
#define	PC00_CKS01  	IO_PC00.bit.CKS01
#define	PC00_CKS02  	IO_PC00.bit.CKS02
#define	PC00_POEN0  	IO_PC00.bit.POEN0
#define	PC00_PUF0  	IO_PC00.bit.PUF0
#define	PC00_PIE0  	IO_PC00.bit.PIE0
#define	PC00_MD0  	IO_PC00.bit.MD0
#define	PC00_MD1  	IO_PC00.bit.MD1

#ifdef __IO_DEFINE
#pragma segment IO=IO_PC11, locate=0x3C
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
} PC11STR;

__IO_EXTERN	  PC11STR	IO_PC11;
#define	_pc11		IO_PC11
#define	PC11		IO_PC11.byte
#define	PC11_CKS10  	IO_PC11.bit.CKS10
#define	PC11_CKS11  	IO_PC11.bit.CKS11
#define	PC11_CKS12  	IO_PC11.bit.CKS12
#define	PC11_POEN1  	IO_PC11.bit.POEN1
#define	PC11_PUF1  	IO_PC11.bit.PUF1
#define	PC11_PIE1  	IO_PC11.bit.PIE1

#ifdef __IO_DEFINE
#pragma segment IO=IO_PC10, locate=0x3D
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
} PC10STR;

__IO_EXTERN	  PC10STR	IO_PC10;
#define	_pc10		IO_PC10
#define	PC10		IO_PC10.byte
#define	PC10_CKS00  	IO_PC10.bit.CKS00
#define	PC10_CKS01  	IO_PC10.bit.CKS01
#define	PC10_CKS02  	IO_PC10.bit.CKS02
#define	PC10_POEN0  	IO_PC10.bit.POEN0
#define	PC10_PUF0  	IO_PC10.bit.PUF0
#define	PC10_PIE0  	IO_PC10.bit.PIE0
#define	PC10_MD0  	IO_PC10.bit.MD0
#define	PC10_MD1  	IO_PC10.bit.MD1

#ifdef __IO_DEFINE
#pragma segment IO=IO_TMCSRH0, locate=0x3E
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	MOD0:1;
			__BYTE	MOD1:1;
			__BYTE	MOD2:1;
			__BYTE	CSL0:1;
			__BYTE	CSL1:1;
			__BYTE	CSL2:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	MOD0:1;
			__BYTE	MOD1:1;
			__BYTE	MOD2:1;
			__BYTE	CSL0:1;
			__BYTE	CSL1:1;
			__BYTE	CSL2:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} TMCSRH0STR;

__IO_EXTERN	  TMCSRH0STR	IO_TMCSRH0;
#define	_tmcsrh0		IO_TMCSRH0
#define	TMCSRH0		IO_TMCSRH0.byte
#define	TMCSRH0_MOD0  	IO_TMCSRH0.bit.MOD0
#define	TMCSRH0_MOD1  	IO_TMCSRH0.bit.MOD1
#define	TMCSRH0_MOD2  	IO_TMCSRH0.bit.MOD2
#define	TMCSRH0_CSL0  	IO_TMCSRH0.bit.CSL0
#define	TMCSRH0_CSL1  	IO_TMCSRH0.bit.CSL1
#define	TMCSRH0_CSL2  	IO_TMCSRH0.bit.CSL2

#ifdef __IO_DEFINE
#pragma segment IO=IO_TMCSRL0, locate=0x3F
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	TRG:1;
			__BYTE	CNTE:1;
			__BYTE	UF:1;
			__BYTE	INTE:1;
			__BYTE	RELD:1;
			__BYTE	OUTL:1;
			__BYTE	OUTE:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	TRG:1;
			__BYTE	CNTE:1;
			__BYTE	UF:1;
			__BYTE	INTE:1;
			__BYTE	RELD:1;
			__BYTE	OUTL:1;
			__BYTE	OUTE:1;
			__BYTE	RESV7:1;
	} bitc;
} TMCSRL0STR;

__IO_EXTERN	  TMCSRL0STR	IO_TMCSRL0;
#define	_tmcsrl0		IO_TMCSRL0
#define	TMCSRL0		IO_TMCSRL0.byte
#define	TMCSRL0_TRG  	IO_TMCSRL0.bit.TRG
#define	TMCSRL0_CNTE  	IO_TMCSRL0.bit.CNTE
#define	TMCSRL0_UF  	IO_TMCSRL0.bit.UF
#define	TMCSRL0_INTE  	IO_TMCSRL0.bit.INTE
#define	TMCSRL0_RELD  	IO_TMCSRL0.bit.RELD
#define	TMCSRL0_OUTL  	IO_TMCSRL0.bit.OUTL
#define	TMCSRL0_OUTE  	IO_TMCSRL0.bit.OUTE

#ifdef __IO_DEFINE
#pragma segment IO=IO_PCNTH0, locate=0x42
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	PGMS:1;
			__BYTE	CKS0:1;
			__BYTE	CKS1:1;
			__BYTE	CKS2:1;
			__BYTE	RTRG:1;
			__BYTE	MDSE:1;
			__BYTE	STGR:1;
			__BYTE	CNTE:1;
	} bit;
	struct {
			__BYTE	PGMS:1;
			__BYTE	CKS0:1;
			__BYTE	CKS1:1;
			__BYTE	CKS2:1;
			__BYTE	RTRG:1;
			__BYTE	MDSE:1;
			__BYTE	STGR:1;
			__BYTE	CNTE:1;
	} bitc;
} PCNTH0STR;

__IO_EXTERN	  PCNTH0STR	IO_PCNTH0;
#define	_pcnth0		IO_PCNTH0
#define	PCNTH0		IO_PCNTH0.byte
#define	PCNTH0_PGMS  	IO_PCNTH0.bit.PGMS
#define	PCNTH0_CKS0  	IO_PCNTH0.bit.CKS0
#define	PCNTH0_CKS1  	IO_PCNTH0.bit.CKS1
#define	PCNTH0_CKS2  	IO_PCNTH0.bit.CKS2
#define	PCNTH0_RTRG  	IO_PCNTH0.bit.RTRG
#define	PCNTH0_MDSE  	IO_PCNTH0.bit.MDSE
#define	PCNTH0_STGR  	IO_PCNTH0.bit.STGR
#define	PCNTH0_CNTE  	IO_PCNTH0.bit.CNTE

#ifdef __IO_DEFINE
#pragma segment IO=IO_PCNTL0, locate=0x43
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	OSEL:1;
			__BYTE	POEN:1;
			__BYTE	IRS0:1;
			__BYTE	IRS1:1;
			__BYTE	IRQF:1;
			__BYTE	IREN:1;
			__BYTE	EGS0:1;
			__BYTE	EGS1:1;
	} bit;
	struct {
			__BYTE	OSEL:1;
			__BYTE	POEN:1;
			__BYTE	IRS0:1;
			__BYTE	IRS1:1;
			__BYTE	IRQF:1;
			__BYTE	IREN:1;
			__BYTE	EGS0:1;
			__BYTE	EGS1:1;
	} bitc;
} PCNTL0STR;

__IO_EXTERN	  PCNTL0STR	IO_PCNTL0;
#define	_pcntl0		IO_PCNTL0
#define	PCNTL0		IO_PCNTL0.byte
#define	PCNTL0_OSEL  	IO_PCNTL0.bit.OSEL
#define	PCNTL0_POEN  	IO_PCNTL0.bit.POEN
#define	PCNTL0_IRS0  	IO_PCNTL0.bit.IRS0
#define	PCNTL0_IRS1  	IO_PCNTL0.bit.IRS1
#define	PCNTL0_IRQF  	IO_PCNTL0.bit.IRQF
#define	PCNTL0_IREN  	IO_PCNTL0.bit.IREN
#define	PCNTL0_EGS0  	IO_PCNTL0.bit.EGS0
#define	PCNTL0_EGS1  	IO_PCNTL0.bit.EGS1

#ifdef __IO_DEFINE
#pragma segment IO=IO_PCNTH1, locate=0x44
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	PGMS:1;
			__BYTE	CKS0:1;
			__BYTE	CKS1:1;
			__BYTE	CKS2:1;
			__BYTE	RTRG:1;
			__BYTE	MDSE:1;
			__BYTE	STGR:1;
			__BYTE	CNTE:1;
	} bit;
	struct {
			__BYTE	PGMS:1;
			__BYTE	CKS0:1;
			__BYTE	CKS1:1;
			__BYTE	CKS2:1;
			__BYTE	RTRG:1;
			__BYTE	MDSE:1;
			__BYTE	STGR:1;
			__BYTE	CNTE:1;
	} bitc;
} PCNTH1STR;

__IO_EXTERN	  PCNTH1STR	IO_PCNTH1;
#define	_pcnth1		IO_PCNTH1
#define	PCNTH1		IO_PCNTH1.byte
#define	PCNTH1_PGMS  	IO_PCNTH1.bit.PGMS
#define	PCNTH1_CKS0  	IO_PCNTH1.bit.CKS0
#define	PCNTH1_CKS1  	IO_PCNTH1.bit.CKS1
#define	PCNTH1_CKS2  	IO_PCNTH1.bit.CKS2
#define	PCNTH1_RTRG  	IO_PCNTH1.bit.RTRG
#define	PCNTH1_MDSE  	IO_PCNTH1.bit.MDSE
#define	PCNTH1_STGR  	IO_PCNTH1.bit.STGR
#define	PCNTH1_CNTE  	IO_PCNTH1.bit.CNTE

#ifdef __IO_DEFINE
#pragma segment IO=IO_PCNTL1, locate=0x45
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	OSEL:1;
			__BYTE	POEN:1;
			__BYTE	IRS0:1;
			__BYTE	IRS1:1;
			__BYTE	IRQF:1;
			__BYTE	IREN:1;
			__BYTE	EGS0:1;
			__BYTE	EGS1:1;
	} bit;
	struct {
			__BYTE	OSEL:1;
			__BYTE	POEN:1;
			__BYTE	IRS0:1;
			__BYTE	IRS1:1;
			__BYTE	IRQF:1;
			__BYTE	IREN:1;
			__BYTE	EGS0:1;
			__BYTE	EGS1:1;
	} bitc;
} PCNTL1STR;

__IO_EXTERN	  PCNTL1STR	IO_PCNTL1;
#define	_pcntl1		IO_PCNTL1
#define	PCNTL1		IO_PCNTL1.byte
#define	PCNTL1_OSEL  	IO_PCNTL1.bit.OSEL
#define	PCNTL1_POEN  	IO_PCNTL1.bit.POEN
#define	PCNTL1_IRS0  	IO_PCNTL1.bit.IRS0
#define	PCNTL1_IRS1  	IO_PCNTL1.bit.IRS1
#define	PCNTL1_IRQF  	IO_PCNTL1.bit.IRQF
#define	PCNTL1_IREN  	IO_PCNTL1.bit.IREN
#define	PCNTL1_EGS0  	IO_PCNTL1.bit.EGS0
#define	PCNTL1_EGS1  	IO_PCNTL1.bit.EGS1

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
#define	_eic00		IO_EIC00
#define	EIC00		IO_EIC00.byte
#define	EIC00_EIE0  	IO_EIC00.bit.EIE0
#define	EIC00_SL00  	IO_EIC00.bit.SL00
#define	EIC00_SL01  	IO_EIC00.bit.SL01
#define	EIC00_EIR0  	IO_EIC00.bit.EIR0
#define	EIC00_EIE1  	IO_EIC00.bit.EIE1
#define	EIC00_SL10  	IO_EIC00.bit.SL10
#define	EIC00_SL11  	IO_EIC00.bit.SL11
#define	EIC00_EIR1  	IO_EIC00.bit.EIR1

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
#define	_eic10		IO_EIC10
#define	EIC10		IO_EIC10.byte
#define	EIC10_EIE0  	IO_EIC10.bit.EIE0
#define	EIC10_SL00  	IO_EIC10.bit.SL00
#define	EIC10_SL01  	IO_EIC10.bit.SL01
#define	EIC10_EIR0  	IO_EIC10.bit.EIR0
#define	EIC10_EIE1  	IO_EIC10.bit.EIE1
#define	EIC10_SL10  	IO_EIC10.bit.SL10
#define	EIC10_SL11  	IO_EIC10.bit.SL11
#define	EIC10_EIR1  	IO_EIC10.bit.EIR1

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
#define	_eic20		IO_EIC20
#define	EIC20		IO_EIC20.byte
#define	EIC20_EIE0  	IO_EIC20.bit.EIE0
#define	EIC20_SL00  	IO_EIC20.bit.SL00
#define	EIC20_SL01  	IO_EIC20.bit.SL01
#define	EIC20_EIR0  	IO_EIC20.bit.EIR0
#define	EIC20_EIE1  	IO_EIC20.bit.EIE1
#define	EIC20_SL10  	IO_EIC20.bit.SL10
#define	EIC20_SL11  	IO_EIC20.bit.SL11
#define	EIC20_EIR1  	IO_EIC20.bit.EIR1

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
#define	_eic30		IO_EIC30
#define	EIC30		IO_EIC30.byte
#define	EIC30_EIE0  	IO_EIC30.bit.EIE0
#define	EIC30_SL00  	IO_EIC30.bit.SL00
#define	EIC30_SL01  	IO_EIC30.bit.SL01
#define	EIC30_EIR0  	IO_EIC30.bit.EIR0
#define	EIC30_EIE1  	IO_EIC30.bit.EIE1
#define	EIC30_SL10  	IO_EIC30.bit.SL10
#define	EIC30_SL11  	IO_EIC30.bit.SL11
#define	EIC30_EIR1  	IO_EIC30.bit.EIR1

#ifdef __IO_DEFINE
#pragma segment IO=IO_EIC01, locate=0x4C
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
} EIC01STR;

__IO_EXTERN	  EIC01STR	IO_EIC01;
#define	_eic01		IO_EIC01
#define	EIC01		IO_EIC01.byte
#define	EIC01_EIE0  	IO_EIC01.bit.EIE0
#define	EIC01_SL00  	IO_EIC01.bit.SL00
#define	EIC01_SL01  	IO_EIC01.bit.SL01
#define	EIC01_EIR0  	IO_EIC01.bit.EIR0
#define	EIC01_EIE1  	IO_EIC01.bit.EIE1
#define	EIC01_SL10  	IO_EIC01.bit.SL10
#define	EIC01_SL11  	IO_EIC01.bit.SL11
#define	EIC01_EIR1  	IO_EIC01.bit.EIR1

#ifdef __IO_DEFINE
#pragma segment IO=IO_EIC11, locate=0x4D
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
} EIC11STR;

__IO_EXTERN	  EIC11STR	IO_EIC11;
#define	_eic11		IO_EIC11
#define	EIC11		IO_EIC11.byte
#define	EIC11_EIE0  	IO_EIC11.bit.EIE0
#define	EIC11_SL00  	IO_EIC11.bit.SL00
#define	EIC11_SL01  	IO_EIC11.bit.SL01
#define	EIC11_EIR0  	IO_EIC11.bit.EIR0
#define	EIC11_EIE1  	IO_EIC11.bit.EIE1
#define	EIC11_SL10  	IO_EIC11.bit.SL10
#define	EIC11_SL11  	IO_EIC11.bit.SL11
#define	EIC11_EIR1  	IO_EIC11.bit.EIR1

#ifdef __IO_DEFINE
#pragma segment IO=IO_SCR, locate=0x50
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	TXE:1;
			__BYTE	RXE:1;
			__BYTE	CRE:1;
			__BYTE	AD:1;
			__BYTE	CL:1;
			__BYTE	SBL:1;
			__BYTE	P:1;
			__BYTE	PEN:1;
	} bit;
	struct {
			__BYTE	TXE:1;
			__BYTE	RXE:1;
			__BYTE	CRE:1;
			__BYTE	AD:1;
			__BYTE	CL:1;
			__BYTE	SBL:1;
			__BYTE	P:1;
			__BYTE	PEN:1;
	} bitc;
} SCRSTR;

__IO_EXTERN	  SCRSTR	IO_SCR;
#define	_scr		IO_SCR
#define	SCR		IO_SCR.byte
#define	SCR_TXE  	IO_SCR.bit.TXE
#define	SCR_RXE  	IO_SCR.bit.RXE
#define	SCR_CRE  	IO_SCR.bit.CRE
#define	SCR_AD  	IO_SCR.bit.AD
#define	SCR_CL  	IO_SCR.bit.CL
#define	SCR_SBL  	IO_SCR.bit.SBL
#define	SCR_P  	IO_SCR.bit.P
#define	SCR_PEN  	IO_SCR.bit.PEN

#ifdef __IO_DEFINE
#pragma segment IO=IO_SMR, locate=0x51
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	SOE:1;
			__BYTE	SCKE:1;
			__BYTE	UPCL:1;
			__BYTE	REST:1;
			__BYTE	EXT:1;
			__BYTE	OTO:1;
			__BYTE	MD0:1;
			__BYTE	MD1:1;
	} bit;
	struct {
			__BYTE	SOE:1;
			__BYTE	SCKE:1;
			__BYTE	UPCL:1;
			__BYTE	REST:1;
			__BYTE	EXT:1;
			__BYTE	OTO:1;
			__BYTE	MD0:1;
			__BYTE	MD1:1;
	} bitc;
} SMRSTR;

__IO_EXTERN	  SMRSTR	IO_SMR;
#define	_smr		IO_SMR
#define	SMR		IO_SMR.byte
#define	SMR_SOE  	IO_SMR.bit.SOE
#define	SMR_SCKE  	IO_SMR.bit.SCKE
#define	SMR_UPCL  	IO_SMR.bit.UPCL
#define	SMR_REST  	IO_SMR.bit.REST
#define	SMR_EXT  	IO_SMR.bit.EXT
#define	SMR_OTO  	IO_SMR.bit.OTO
#define	SMR_MD0  	IO_SMR.bit.MD0
#define	SMR_MD1  	IO_SMR.bit.MD1

#ifdef __IO_DEFINE
#pragma segment IO=IO_SSR, locate=0x52
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	TIE:1;
			__BYTE	RIE:1;
			__BYTE	BDS:1;
			__BYTE	TDRE:1;
			__BYTE	RDRF:1;
			__BYTE	FRE:1;
			__BYTE	ORE:1;
			__BYTE	PE:1;
	} bit;
	struct {
			__BYTE	TIE:1;
			__BYTE	RIE:1;
			__BYTE	BDS:1;
			__BYTE	TDRE:1;
			__BYTE	RDRF:1;
			__BYTE	FRE:1;
			__BYTE	ORE:1;
			__BYTE	PE:1;
	} bitc;
} SSRSTR;

__IO_EXTERN	  SSRSTR	IO_SSR;
#define	_ssr		IO_SSR
#define	SSR		IO_SSR.byte
#define	SSR_TIE  	IO_SSR.bit.TIE
#define	SSR_RIE  	IO_SSR.bit.RIE
#define	SSR_BDS  	IO_SSR.bit.BDS
#define	SSR_TDRE  	IO_SSR.bit.TDRE
#define	SSR_RDRF  	IO_SSR.bit.RDRF
#define	SSR_FRE  	IO_SSR.bit.FRE
#define	SSR_ORE  	IO_SSR.bit.ORE
#define	SSR_PE  	IO_SSR.bit.PE

#ifdef __IO_DEFINE
#pragma segment IO=IO_RDR, locate=0x53
#endif

__IO_EXTERN	__BYTE	IO_RDR;
#define	_rdr		IO_RDR
#define	RDR	_rdr

#ifdef __IO_DEFINE
#pragma segment IO=IO_ESCR, locate=0x54
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	SCES:1;
			__BYTE	CCO:1;
			__BYTE	SIOP:1;
			__BYTE	SOPE:1;
			__BYTE	LBL0:1;
			__BYTE	LBL1:1;
			__BYTE	LBD:1;
			__BYTE	LBIE:1;
	} bit;
	struct {
			__BYTE	SCES:1;
			__BYTE	CCO:1;
			__BYTE	SIOP:1;
			__BYTE	SOPE:1;
			__BYTE	LBL0:1;
			__BYTE	LBL1:1;
			__BYTE	LBD:1;
			__BYTE	LBIE:1;
	} bitc;
} ESCRSTR;

__IO_EXTERN	  ESCRSTR	IO_ESCR;
#define	_escr		IO_ESCR
#define	ESCR		IO_ESCR.byte
#define	ESCR_SCES  	IO_ESCR.bit.SCES
#define	ESCR_CCO  	IO_ESCR.bit.CCO
#define	ESCR_SIOP  	IO_ESCR.bit.SIOP
#define	ESCR_SOPE  	IO_ESCR.bit.SOPE
#define	ESCR_LBL0  	IO_ESCR.bit.LBL0
#define	ESCR_LBL1  	IO_ESCR.bit.LBL1
#define	ESCR_LBD  	IO_ESCR.bit.LBD
#define	ESCR_LBIE  	IO_ESCR.bit.LBIE

#ifdef __IO_DEFINE
#pragma segment IO=IO_ECCR, locate=0x55
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	TBI:1;
			__BYTE	RBI:1;
			__BYTE	RESV2:1;
			__BYTE	SSM:1;
			__BYTE	SCDE:1;
			__BYTE	MS:1;
			__BYTE	LBR:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	TBI:1;
			__BYTE	RBI:1;
			__BYTE	RESV2:1;
			__BYTE	SSM:1;
			__BYTE	SCDE:1;
			__BYTE	MS:1;
			__BYTE	LBR:1;
			__BYTE	RESV7:1;
	} bitc;
} ECCRSTR;

__IO_EXTERN	  ECCRSTR	IO_ECCR;
#define	_eccr		IO_ECCR
#define	ECCR		IO_ECCR.byte
#define	ECCR_TBI  	IO_ECCR.bit.TBI
#define	ECCR_RBI  	IO_ECCR.bit.RBI
#define	ECCR_SSM  	IO_ECCR.bit.SSM
#define	ECCR_SCDE  	IO_ECCR.bit.SCDE
#define	ECCR_MS  	IO_ECCR.bit.MS
#define	ECCR_LBR  	IO_ECCR.bit.LBR

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
#define	_smc10		IO_SMC10
#define	SMC10		IO_SMC10.byte
#define	SMC10_MD  	IO_SMC10.bit.MD
#define	SMC10_CKS  	IO_SMC10.bit.CKS
#define	SMC10_CBL0  	IO_SMC10.bit.CBL0
#define	SMC10_CBL1  	IO_SMC10.bit.CBL1
#define	SMC10_SBL  	IO_SMC10.bit.SBL
#define	SMC10_TDP  	IO_SMC10.bit.TDP
#define	SMC10_PEN  	IO_SMC10.bit.PEN
#define	SMC10_BDS  	IO_SMC10.bit.BDS

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
#define	_smc20		IO_SMC20
#define	SMC20		IO_SMC20.byte
#define	SMC20_TEIE  	IO_SMC20.bit.TEIE
#define	SMC20_TCIE  	IO_SMC20.bit.TCIE
#define	SMC20_RIE  	IO_SMC20.bit.RIE
#define	SMC20_TXE  	IO_SMC20.bit.TXE
#define	SMC20_RXE  	IO_SMC20.bit.RXE
#define	SMC20_RERC  	IO_SMC20.bit.RERC
#define	SMC20_TXOE  	IO_SMC20.bit.TXOE
#define	SMC20_SCKE  	IO_SMC20.bit.SCKE

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
#define	_ssr0		IO_SSR0
#define	SSR0		IO_SSR0.byte
#define	SSR0_TDRE  	IO_SSR0.bit.TDRE
#define	SSR0_TCPL  	IO_SSR0.bit.TCPL
#define	SSR0_RDRF  	IO_SSR0.bit.RDRF
#define	SSR0_FER  	IO_SSR0.bit.FER
#define	SSR0_OVE  	IO_SSR0.bit.OVE
#define	SSR0_PER  	IO_SSR0.bit.PER

#ifdef __IO_DEFINE
#pragma segment IO=IO_TDR0, locate=0x59
#endif

__IO_EXTERN	__BYTE	IO_TDR0;
#define	_tdr0		IO_TDR0
#define	TDR0	_tdr0

#ifdef __IO_DEFINE
#pragma segment IO=IO_RDR0, locate=0x5A
#endif

__IO_EXTERN	const __BYTE	IO_RDR0;
#define	_rdr0		IO_RDR0
#define	RDR0	_rdr0

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
#define	_ibcr00		IO_IBCR00
#define	IBCR00		IO_IBCR00.byte
#define	IBCR00_WUE  	IO_IBCR00.bit.WUE
#define	IBCR00_WUF  	IO_IBCR00.bit.WUF
#define	IBCR00_SPE  	IO_IBCR00.bit.SPE
#define	IBCR00_SPF  	IO_IBCR00.bit.SPF
#define	IBCR00_ALE  	IO_IBCR00.bit.ALE
#define	IBCR00_ALF  	IO_IBCR00.bit.ALF
#define	IBCR00_INTS  	IO_IBCR00.bit.INTS
#define	IBCR00_AACKX  	IO_IBCR00.bit.AACKX

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
#define	_ibcr10		IO_IBCR10
#define	IBCR10		IO_IBCR10.byte
#define	IBCR10_INT  	IO_IBCR10.bit.INT
#define	IBCR10_INTE  	IO_IBCR10.bit.INTE
#define	IBCR10_GACKE  	IO_IBCR10.bit.GACKE
#define	IBCR10_DACKE  	IO_IBCR10.bit.DACKE
#define	IBCR10_MSS  	IO_IBCR10.bit.MSS
#define	IBCR10_SCC  	IO_IBCR10.bit.SCC
#define	IBCR10_BEIE  	IO_IBCR10.bit.BEIE
#define	IBCR10_BER  	IO_IBCR10.bit.BER

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
#define	_ibsr0		IO_IBSR0
#define	IBSR0		IO_IBSR0.byte
#define	IBSR0_FBT  	IO_IBSR0.bit.FBT
#define	IBSR0_GCA  	IO_IBSR0.bit.GCA
#define	IBSR0_AAS  	IO_IBSR0.bit.AAS
#define	IBSR0_TRX  	IO_IBSR0.bit.TRX
#define	IBSR0_LRB  	IO_IBSR0.bit.LRB
#define	IBSR0_RSC  	IO_IBSR0.bit.RSC
#define	IBSR0_BB  	IO_IBSR0.bit.BB

#ifdef __IO_DEFINE
#pragma segment IO=IO_IDDR0, locate=0x63
#endif

__IO_EXTERN	__BYTE	IO_IDDR0;
#define	_iddr0		IO_IDDR0
#define	IDDR0	_iddr0

#ifdef __IO_DEFINE
#pragma segment IO=IO_IAAR0, locate=0x64
#endif

__IO_EXTERN	__BYTE	IO_IAAR0;
#define	_iaar0		IO_IAAR0
#define	IAAR0	_iaar0

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
#define	_iccr0		IO_ICCR0
#define	ICCR0		IO_ICCR0.byte
#define	ICCR0_CS0  	IO_ICCR0.bit.CS0
#define	ICCR0_CS1  	IO_ICCR0.bit.CS1
#define	ICCR0_CS2  	IO_ICCR0.bit.CS2
#define	ICCR0_CS3  	IO_ICCR0.bit.CS3
#define	ICCR0_CS4  	IO_ICCR0.bit.CS4
#define	ICCR0_EN  	IO_ICCR0.bit.EN
#define	ICCR0_DMBP  	IO_ICCR0.bit.DMBP

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
#define	_adc1		IO_ADC1
#define	ADC1		IO_ADC1.byte
#define	ADC1_AD  	IO_ADC1.bit.AD
#define	ADC1_ADMVX  	IO_ADC1.bit.ADMVX
#define	ADC1_ADMV  	IO_ADC1.bit.ADMV
#define	ADC1_ADI  	IO_ADC1.bit.ADI
#define	ADC1_ANS0  	IO_ADC1.bit.ANS0
#define	ADC1_ANS1  	IO_ADC1.bit.ANS1
#define	ADC1_ANS2  	IO_ADC1.bit.ANS2
#define	ADC1_ANS3  	IO_ADC1.bit.ANS3

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
#define	_adc2		IO_ADC2
#define	ADC2		IO_ADC2.byte
#define	ADC2_CKDIV0  	IO_ADC2.bit.CKDIV0
#define	ADC2_CKDIV1  	IO_ADC2.bit.CKDIV1
#define	ADC2_EXT  	IO_ADC2.bit.EXT
#define	ADC2_ADIE  	IO_ADC2.bit.ADIE
#define	ADC2_ADCK  	IO_ADC2.bit.ADCK
#define	ADC2_TIM0  	IO_ADC2.bit.TIM0
#define	ADC2_TIM1  	IO_ADC2.bit.TIM1
#define	ADC2_AD8  	IO_ADC2.bit.AD8

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

#define	ADD		IO_ADD.word
#define	ADD_ADDH	IO_ADD.byte.ADDH
#define	ADD_ADDL	IO_ADD.byte.ADDL

#ifdef __IO_DEFINE
#pragma segment IO=IO_WCSR, locate=0x70
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	CTR0:1;
			__BYTE	CTR1:1;
			__BYTE	CTR2:1;
			__BYTE	CTR3:1;
			__BYTE	CTR4:1;
			__BYTE	CTR5:1;
			__BYTE	WCFLG:1;
			__BYTE	ISEL:1;
	} bit;
	struct {
			__BYTE	CTR0:1;
			__BYTE	CTR1:1;
			__BYTE	CTR2:1;
			__BYTE	CTR3:1;
			__BYTE	CTR4:1;
			__BYTE	CTR5:1;
			__BYTE	WCFLG:1;
			__BYTE	ISEL:1;
	} bitc;
} WCSRSTR;

__IO_EXTERN	  WCSRSTR	IO_WCSR;
#define	_wcsr		IO_WCSR
#define	WCSR		IO_WCSR.byte
#define	WCSR_CTR0  	IO_WCSR.bit.CTR0
#define	WCSR_CTR1  	IO_WCSR.bit.CTR1
#define	WCSR_CTR2  	IO_WCSR.bit.CTR2
#define	WCSR_CTR3  	IO_WCSR.bit.CTR3
#define	WCSR_CTR4  	IO_WCSR.bit.CTR4
#define	WCSR_CTR5  	IO_WCSR.bit.CTR5
#define	WCSR_WCFLG  	IO_WCSR.bit.WCFLG
#define	WCSR_ISEL  	IO_WCSR.bit.ISEL

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
#define	_fsr		IO_FSR
#define	FSR		IO_FSR.byte
#define	FSR_SSEN  	IO_FSR.bit.SSEN
#define	FSR_WRE  	IO_FSR.bit.WRE
#define	FSR_IRQEN  	IO_FSR.bit.IRQEN
#define	FSR_RDY  	IO_FSR.bit.RDY
#define	FSR_RDYIRQ  	IO_FSR.bit.RDYIRQ

#ifdef __IO_DEFINE
#pragma segment IO=IO_SWRE, locate=0x73
#endif

__IO_EXTERN	__WORD	IO_SWRE;
#define	_swre		IO_SWRE
#define	SWRE	_swre

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
#define	_wren		IO_WREN
#define	WREN		IO_WREN.byte
#define	WREN_EN0  	IO_WREN.bit.EN0
#define	WREN_EN1  	IO_WREN.bit.EN1
#define	WREN_EN2  	IO_WREN.bit.EN2

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
#define	_wror		IO_WROR
#define	WROR		IO_WROR.byte
#define	WROR_DRR0  	IO_WROR.bit.DRR0
#define	WROR_DRR1  	IO_WROR.bit.DRR1
#define	WROR_DRR2  	IO_WROR.bit.DRR2

#ifdef __IO_DEFINE
#pragma segment IO=IO_ILR0, locate=0x79
#endif

__IO_EXTERN	__BYTE	IO_ILR0;
#define	_ilr0		IO_ILR0
#define	ILR0	_ilr0

#ifdef __IO_DEFINE
#pragma segment IO=IO_ILR1, locate=0x7A
#endif

__IO_EXTERN	__BYTE	IO_ILR1;
#define	_ilr1		IO_ILR1
#define	ILR1	_ilr1

#ifdef __IO_DEFINE
#pragma segment IO=IO_ILR2, locate=0x7B
#endif

__IO_EXTERN	__BYTE	IO_ILR2;
#define	_ilr2		IO_ILR2
#define	ILR2	_ilr2

#ifdef __IO_DEFINE
#pragma segment IO=IO_ILR3, locate=0x7C
#endif

__IO_EXTERN	__BYTE	IO_ILR3;
#define	_ilr3		IO_ILR3
#define	ILR3	_ilr3

#ifdef __IO_DEFINE
#pragma segment IO=IO_ILR4, locate=0x7D
#endif

__IO_EXTERN	__BYTE	IO_ILR4;
#define	_ilr4		IO_ILR4
#define	ILR4	_ilr4

#ifdef __IO_DEFINE
#pragma segment IO=IO_ILR5, locate=0x7E
#endif

__IO_EXTERN	__BYTE	IO_ILR5;
#define	_ilr5		IO_ILR5
#define	ILR5	_ilr5

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_WRAR0,   locate=0xF80
#endif

__IO_EXTENDED	__WORD	IO_WRAR0;
#define	_wrar0		IO_WRAR0
#define	WRAR0	_wrar0

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_WRDR0,   locate=0xF82
#endif

__IO_EXTENDED	__BYTE	IO_WRDR0;
#define	_wrdr0		IO_WRDR0
#define	WRDR0	_wrdr0

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_WRAR1,   locate=0xF83
#endif

__IO_EXTENDED	__WORD	IO_WRAR1;
#define	_wrar1		IO_WRAR1
#define	WRAR1	_wrar1

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_WRDR1,   locate=0xF85
#endif

__IO_EXTENDED	__BYTE	IO_WRDR1;
#define	_wrdr1		IO_WRDR1
#define	WRDR1	_wrdr1

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_WRAR2,   locate=0xF86
#endif

__IO_EXTENDED	__WORD	IO_WRAR2;
#define	_wrar2		IO_WRAR2
#define	WRAR2	_wrar2

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_WRDR2,   locate=0xF88
#endif

__IO_EXTENDED	__BYTE	IO_WRDR2;
#define	_wrdr2		IO_WRDR2
#define	WRDR2	_wrdr2

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
#define	_t01cr0		IO_T01CR0
#define	T01CR0		IO_T01CR0.byte
#define	T01CR0_F0  	IO_T01CR0.bit.F0
#define	T01CR0_F1  	IO_T01CR0.bit.F1
#define	T01CR0_F2  	IO_T01CR0.bit.F2
#define	T01CR0_F3  	IO_T01CR0.bit.F3
#define	T01CR0_C0  	IO_T01CR0.bit.C0
#define	T01CR0_C1  	IO_T01CR0.bit.C1
#define	T01CR0_C2  	IO_T01CR0.bit.C2
#define	T01CR0_IFE  	IO_T01CR0.bit.IFE

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
#define	_t00cr0		IO_T00CR0
#define	T00CR0		IO_T00CR0.byte
#define	T00CR0_F0  	IO_T00CR0.bit.F0
#define	T00CR0_F1  	IO_T00CR0.bit.F1
#define	T00CR0_F2  	IO_T00CR0.bit.F2
#define	T00CR0_F3  	IO_T00CR0.bit.F3
#define	T00CR0_C0  	IO_T00CR0.bit.C0
#define	T00CR0_C1  	IO_T00CR0.bit.C1
#define	T00CR0_C2  	IO_T00CR0.bit.C2
#define	T00CR0_IFE  	IO_T00CR0.bit.IFE

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_T01DR,   locate=0xF94
#endif

__IO_EXTENDED	__BYTE	IO_T01DR;
#define	_t01dr		IO_T01DR
#define	T01DR	_t01dr

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_T00DR,   locate=0xF95
#endif

__IO_EXTENDED	__BYTE	IO_T00DR;
#define	_t00dr		IO_T00DR
#define	T00DR	_t00dr

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
			__BYTE	IIS:1;
			__BYTE	T00:1;
			__BYTE	T01:1;
	} bit;
	struct {
			__BYTE	FE00:1;
			__BYTE	FE01:1;
			__BYTE	FE10:1;
			__BYTE	FE11:1;
			__BYTE	MOD:1;
			__BYTE	IIS:1;
			__BYTE	T00:1;
			__BYTE	T01:1;
	} bitc;
} TMCR0STR;

__IO_EXTENDED	  TMCR0STR	IO_TMCR0;
#define	_tmcr0		IO_TMCR0
#define	TMCR0		IO_TMCR0.byte
#define	TMCR0_FE00  	IO_TMCR0.bit.FE00
#define	TMCR0_FE01  	IO_TMCR0.bit.FE01
#define	TMCR0_FE10  	IO_TMCR0.bit.FE10
#define	TMCR0_FE11  	IO_TMCR0.bit.FE11
#define	TMCR0_MOD  	IO_TMCR0.bit.MOD
#define	TMCR0_IIS  	IO_TMCR0.bit.IIS
#define	TMCR0_T00  	IO_TMCR0.bit.T00
#define	TMCR0_T01  	IO_TMCR0.bit.T01

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
#define	_t11cr0		IO_T11CR0
#define	T11CR0		IO_T11CR0.byte
#define	T11CR0_F0  	IO_T11CR0.bit.F0
#define	T11CR0_F1  	IO_T11CR0.bit.F1
#define	T11CR0_F2  	IO_T11CR0.bit.F2
#define	T11CR0_F3  	IO_T11CR0.bit.F3
#define	T11CR0_C0  	IO_T11CR0.bit.C0
#define	T11CR0_C1  	IO_T11CR0.bit.C1
#define	T11CR0_C2  	IO_T11CR0.bit.C2
#define	T11CR0_IFE  	IO_T11CR0.bit.IFE

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
#define	_t10cr0		IO_T10CR0
#define	T10CR0		IO_T10CR0.byte
#define	T10CR0_F0  	IO_T10CR0.bit.F0
#define	T10CR0_F1  	IO_T10CR0.bit.F1
#define	T10CR0_F2  	IO_T10CR0.bit.F2
#define	T10CR0_F3  	IO_T10CR0.bit.F3
#define	T10CR0_C0  	IO_T10CR0.bit.C0
#define	T10CR0_C1  	IO_T10CR0.bit.C1
#define	T10CR0_C2  	IO_T10CR0.bit.C2
#define	T10CR0_IFE  	IO_T10CR0.bit.IFE

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_T11DR,   locate=0xF99
#endif

__IO_EXTENDED	__BYTE	IO_T11DR;
#define	_t11dr		IO_T11DR
#define	T11DR	_t11dr

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_T10DR,   locate=0xF9A
#endif

__IO_EXTENDED	__BYTE	IO_T10DR;
#define	_t10dr		IO_T10DR
#define	T10DR	_t10dr

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
			__BYTE	IIS:1;
			__BYTE	T00:1;
			__BYTE	T01:1;
	} bit;
	struct {
			__BYTE	FE00:1;
			__BYTE	FE01:1;
			__BYTE	FE10:1;
			__BYTE	FE11:1;
			__BYTE	MOD:1;
			__BYTE	IIS:1;
			__BYTE	T00:1;
			__BYTE	T01:1;
	} bitc;
} TMCR1STR;

__IO_EXTENDED	  TMCR1STR	IO_TMCR1;
#define	_tmcr1		IO_TMCR1
#define	TMCR1		IO_TMCR1.byte
#define	TMCR1_FE00  	IO_TMCR1.bit.FE00
#define	TMCR1_FE01  	IO_TMCR1.bit.FE01
#define	TMCR1_FE10  	IO_TMCR1.bit.FE10
#define	TMCR1_FE11  	IO_TMCR1.bit.FE11
#define	TMCR1_MOD  	IO_TMCR1.bit.MOD
#define	TMCR1_IIS  	IO_TMCR1.bit.IIS
#define	TMCR1_T00  	IO_TMCR1.bit.T00
#define	TMCR1_T01  	IO_TMCR1.bit.T01

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_PPS01,   locate=0xF9C
#endif

__IO_EXTENDED	__BYTE	IO_PPS01;
#define	_pps01		IO_PPS01
#define	PPS01	_pps01

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_PPS00,   locate=0xF9D
#endif

__IO_EXTENDED	__BYTE	IO_PPS00;
#define	_pps00		IO_PPS00
#define	PPS00	_pps00

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_PDS01,   locate=0xF9E
#endif

__IO_EXTENDED	__BYTE	IO_PDS01;
#define	_pds01		IO_PDS01
#define	PDS01	_pds01

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_PDS00,   locate=0xF9F
#endif

__IO_EXTENDED	__BYTE	IO_PDS00;
#define	_pds00		IO_PDS00
#define	PDS00	_pds00

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_PPS11,   locate=0xFA0
#endif

__IO_EXTENDED	__BYTE	IO_PPS11;
#define	_pps11		IO_PPS11
#define	PPS11	_pps11

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_PPS10,   locate=0xFA1
#endif

__IO_EXTENDED	__BYTE	IO_PPS10;
#define	_pps10		IO_PPS10
#define	PPS10	_pps10

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_PDS11,   locate=0xFA2
#endif

__IO_EXTENDED	__BYTE	IO_PDS11;
#define	_pds11		IO_PDS11
#define	PDS11	_pds11

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_PDS10,   locate=0xFA3
#endif

__IO_EXTENDED	__BYTE	IO_PDS10;
#define	_pds10		IO_PDS10
#define	PDS10	_pds10

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
			__BYTE	PEN30:1;
			__BYTE	PEN31:1;
	} bit;
	struct {
			__BYTE	PEN00:1;
			__BYTE	PEN01:1;
			__BYTE	PEN10:1;
			__BYTE	PEN11:1;
			__BYTE	PEN20:1;
			__BYTE	PEN21:1;
			__BYTE	PEN30:1;
			__BYTE	PEN31:1;
	} bitc;
} PPGSSTR;

__IO_EXTENDED	  PPGSSTR	IO_PPGS;
#define	_ppgs		IO_PPGS
#define	PPGS		IO_PPGS.byte
#define	PPGS_PEN00  	IO_PPGS.bit.PEN00
#define	PPGS_PEN01  	IO_PPGS.bit.PEN01
#define	PPGS_PEN10  	IO_PPGS.bit.PEN10
#define	PPGS_PEN11  	IO_PPGS.bit.PEN11
#define	PPGS_PEN20  	IO_PPGS.bit.PEN20
#define	PPGS_PEN21  	IO_PPGS.bit.PEN21
#define	PPGS_PEN30  	IO_PPGS.bit.PEN30
#define	PPGS_PEN31  	IO_PPGS.bit.PEN31

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
			__BYTE	REV30:1;
			__BYTE	REV31:1;
	} bit;
	struct {
			__BYTE	REV00:1;
			__BYTE	REV01:1;
			__BYTE	REV10:1;
			__BYTE	REV11:1;
			__BYTE	REV20:1;
			__BYTE	REV21:1;
			__BYTE	REV30:1;
			__BYTE	REV31:1;
	} bitc;
} REVCSTR;

__IO_EXTENDED	  REVCSTR	IO_REVC;
#define	_revc		IO_REVC
#define	REVC		IO_REVC.byte
#define	REVC_REV00  	IO_REVC.bit.REV00
#define	REVC_REV01  	IO_REVC.bit.REV01
#define	REVC_REV10  	IO_REVC.bit.REV10
#define	REVC_REV11  	IO_REVC.bit.REV11
#define	REVC_REV20  	IO_REVC.bit.REV20
#define	REVC_REV21  	IO_REVC.bit.REV21
#define	REVC_REV30  	IO_REVC.bit.REV30
#define	REVC_REV31  	IO_REVC.bit.REV31

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_TMR0,   locate=0xFA6
#endif

__IO_EXTENDED	union {
	__WORD	word;
	struct {
		__BYTE	TMRH;
		__BYTE	TMRL;
	} byte;
} IO_TMR0;

#define	TMR0		IO_TMR0.word
#define	TMR0_TMRH	IO_TMR0.byte.TMRH
#define	TMR0_TMRL	IO_TMR0.byte.TMRL

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_PDCR0,   locate=0xFAA
#endif

__IO_EXTENDED	const	union {
	__WORD	word;
	struct {
		__BYTE	PDCRH;
		__BYTE	PDCRL;
	} byte;
} IO_PDCR0;

#define	PDCR0		IO_PDCR0.word
#define	PDCR0_PDCRH	IO_PDCR0.byte.PDCRH
#define	PDCR0_PDCRL	IO_PDCR0.byte.PDCRL

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_PCSR0,   locate=0xFAC
#endif

__IO_EXTENDED	union {
	__WORD	word;
	struct {
		__BYTE	PCSRH;
		__BYTE	PCSRL;
	} byte;
} IO_PCSR0;

#define	PCSR0		IO_PCSR0.word
#define	PCSR0_PCSRH	IO_PCSR0.byte.PCSRH
#define	PCSR0_PCSRL	IO_PCSR0.byte.PCSRL

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_PDUT0,   locate=0xFAE
#endif

__IO_EXTENDED	union {
	__WORD	word;
	struct {
		__BYTE	PDUTH;
		__BYTE	PDUTL;
	} byte;
} IO_PDUT0;

#define	PDUT0		IO_PDUT0.word
#define	PDUT0_PDUTH	IO_PDUT0.byte.PDUTH
#define	PDUT0_PDUTL	IO_PDUT0.byte.PDUTL

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_PDCR1,   locate=0xFB0
#endif

__IO_EXTENDED	const	union {
	__WORD	word;
	struct {
		__BYTE	PDCRH;
		__BYTE	PDCRL;
	} byte;
} IO_PDCR1;

#define	PDCR1		IO_PDCR1.word
#define	PDCR1_PDCRH	IO_PDCR1.byte.PDCRH
#define	PDCR1_PDCRL	IO_PDCR1.byte.PDCRL

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_PCSR1,   locate=0xFB2
#endif

__IO_EXTENDED	union {
	__WORD	word;
	struct {
		__BYTE	PCSRH;
		__BYTE	PCSRL;
	} byte;
} IO_PCSR1;

#define	PCSR1		IO_PCSR1.word
#define	PCSR1_PCSRH	IO_PCSR1.byte.PCSRH
#define	PCSR1_PCSRL	IO_PCSR1.byte.PCSRL

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_PDUT1,   locate=0xFB4
#endif

__IO_EXTENDED	union {
	__WORD	word;
	struct {
		__BYTE	PDUTH;
		__BYTE	PDUTL;
	} byte;
} IO_PDUT1;

#define	PDUT1		IO_PDUT1.word
#define	PDUT1_PDUTH	IO_PDUT1.byte.PDUTH
#define	PDUT1_PDUTL	IO_PDUT1.byte.PDUTL

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_BGR,   locate=0xFBC
#endif

__IO_EXTENDED	union {
	__WORD	word;
	struct {
		__BYTE	BGR1;
		__BYTE	BGR0;
	} byte;
} IO_BGR;

#define	BGR		IO_BGR.word
#define	BGR_BGR1	IO_BGR.byte.BGR1
#define	BGR_BGR0	IO_BGR.byte.BGR0

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
#define	_pssr0		IO_PSSR0
#define	PSSR0		IO_PSSR0.byte
#define	PSSR0_PSS0  	IO_PSSR0.bit.PSS0
#define	PSSR0_PSS1  	IO_PSSR0.bit.PSS1
#define	PSSR0_BRGE  	IO_PSSR0.bit.BRGE

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_BRSR0,   locate=0xFBF
#endif

__IO_EXTENDED	__BYTE	IO_BRSR0;
#define	_brsr0		IO_BRSR0
#define	BRSR0	_brsr0

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_AIDRH,   locate=0xFC2
#endif

__IO_EXTENDED	__BYTE	IO_AIDRH;
#define	_aidrh		IO_AIDRH
#define	AIDRH	_aidrh

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_AIDRL,   locate=0xFC3
#endif

__IO_EXTENDED	__BYTE	IO_AIDRL;
#define	_aidrl		IO_AIDRL
#define	AIDRL	_aidrl

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
#define	_wcdr		IO_WCDR
#define	WCDR		IO_WCDR.byte
#define	WCDR_RCTR0  	IO_WCDR.bit.RCTR0
#define	WCDR_RCTR1  	IO_WCDR.bit.RCTR1
#define	WCDR_RCTR2  	IO_WCDR.bit.RCTR2
#define	WCDR_RCTR3  	IO_WCDR.bit.RCTR3
#define	WCDR_RCTR4  	IO_WCDR.bit.RCTR4
#define	WCDR_RCTR5  	IO_WCDR.bit.RCTR5
#define	WCDR_CS0  	IO_WCDR.bit.CS0
#define	WCDR_CS1  	IO_WCDR.bit.CS1

#if defined(__CPU_MB95F108HS__) || \
    defined(__CPU_MB95F108HW__) || \
    defined(__CPU_MB95108H__) || \
    defined(__CPU_MB95F104AMS__) || \
    defined(__CPU_MB95F104AMW__) || \
    defined(__CPU_MB95F106AMS__) || \
    defined(__CPU_MB95F106AMW__) || \
    defined(__CPU_MB95108AM__) || \
    defined(__CPU_MB95F108AMS__) || \
    defined(__CPU_MB95F108AMW__)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_ILSR3,   locate=0xFE6
#endif

__IO_EXTENDED	__BYTE	IO_ILSR3;
#define	_ilsr3		(IO_ILSR3)
#define	ILSR3	(_ilsr3)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_ILSR2,   locate=0xFE7
#endif

__IO_EXTENDED	__BYTE	IO_ILSR2;
#define	_ilsr2		(IO_ILSR2)
#define	ILSR2	(_ilsr2)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_CSVCR,   locate=0xFEA
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	RESV0:1;
			__BYTE	SRST:1;
			__BYTE	SSVE:1;
			__BYTE	MSVE:1;
			__BYTE	RCE:1;
			__BYTE	SM:1;
			__BYTE	MM:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	RESV0:1;
			__BYTE	SRST:1;
			__BYTE	SSVE:1;
			__BYTE	MSVE:1;
			__BYTE	RCE:1;
			__BYTE	SM:1;
			__BYTE	MM:1;
			__BYTE	RESV7:1;
	} bitc;
} CSVCRSTR;

__IO_EXTENDED	  CSVCRSTR	IO_CSVCR;
#define	_csvcr		IO_CSVCR
#define	CSVCR		IO_CSVCR.byte
#define	CSVCR_SRST  	IO_CSVCR.bit.SRST
#define	CSVCR_SSVE  	IO_CSVCR.bit.SSVE
#define	CSVCR_MSVE  	IO_CSVCR.bit.MSVE
#define	CSVCR_RCE  	IO_CSVCR.bit.RCE
#define	CSVCR_SM  	IO_CSVCR.bit.SM
#define	CSVCR_MM  	IO_CSVCR.bit.MM

#endif

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_ILSR,   locate=0xFEE
#endif

__IO_EXTENDED	__BYTE	IO_ILSR;
#define	_ilsr		IO_ILSR
#define	ILSR	_ilsr

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_WICR,   locate=0xFEF
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	TRG0:1;
			__BYTE	UCK0:1;
			__BYTE	UI0:1;
			__BYTE	EC0:1;
			__BYTE	SCK:1;
			__BYTE	SI:1;
			__BYTE	INT00:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	TRG0:1;
			__BYTE	UCK0:1;
			__BYTE	UI0:1;
			__BYTE	EC0:1;
			__BYTE	SCK:1;
			__BYTE	SI:1;
			__BYTE	INT00:1;
			__BYTE	RESV7:1;
	} bitc;
} WICRSTR;

__IO_EXTENDED	  WICRSTR	IO_WICR;
#define	_wicr		IO_WICR
#define	WICR		IO_WICR.byte
#define	WICR_TRG0  	IO_WICR.bit.TRG0
#define	WICR_UCK0  	IO_WICR.bit.UCK0
#define	WICR_UI0  	IO_WICR.bit.UI0
#define	WICR_EC0  	IO_WICR.bit.EC0
#define	WICR_SCK  	IO_WICR.bit.SCK
#define	WICR_SI  	IO_WICR.bit.SI
#define	WICR_INT00  	IO_WICR.bit.INT00
