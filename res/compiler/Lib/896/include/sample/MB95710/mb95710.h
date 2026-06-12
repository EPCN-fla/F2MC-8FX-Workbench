/*
 MB95710 Series I/O register declaration file V01L02
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

#define	CONSTANT_0	(0)
#define	CONSTANT_1	(1)
#define	CONSTANT_2	(2)
#define	CONSTANT_3	(3)
#define	CONSTANT_4	(4)
#define	CONSTANT_5	(5)
#define	CONSTANT_6	(6)
#define	CONSTANT_7	(7)
#define	CONSTANT_8	(8)
#define	CONSTANT_9	(9)
#define	CONSTANT_10	(10)
#define	CONSTANT_11	(11)
#define	CONSTANT_12	(12)
#define	CONSTANT_13	(13)
#define	CONSTANT_14	(14)
#define	CONSTANT_15	(15)
#define	CONSTANT_16	(16)
#define	CONSTANT_17	(17)
#define	CONSTANT_18	(18)
#define	CONSTANT_19	(19)
#define	CONSTANT_20	(20)
#define	CONSTANT_21	(21)
#define	CONSTANT_22	(22)
#define	CONSTANT_23	(23)
#define	CONSTANT_24	(24)
#define	CONSTANT_25	(25)
#define	CONSTANT_26	(26)
#define	CONSTANT_27	(27)
#define	CONSTANT_28	(28)
#define	CONSTANT_29	(29)
#define	CONSTANT_30	(30)
#define	CONSTANT_31	(31)
#define	CONSTANT_32	(32)
#define	CONSTANT_33	(33)
#define	CONSTANT_34	(34)
#define	CONSTANT_35	(35)
#define	CONSTANT_36	(36)
#define	CONSTANT_37	(37)
#define	CONSTANT_38	(38)
#define	CONSTANT_39	(39)
#define	CONSTANT_40	(40)
#define	CONSTANT_41	(41)
#define	CONSTANT_42	(42)
#define	CONSTANT_43	(43)
#define	CONSTANT_44	(44)
#define	CONSTANT_45	(45)
#define	CONSTANT_46	(46)
#define	CONSTANT_47	(47)
#define	CONSTANT_48	(48)
#define	CONSTANT_49	(49)
#define	CONSTANT_50	(50)
#define	CONSTANT_51	(51)
#define	CONSTANT_52	(52)
#define	CONSTANT_53	(53)
#define	CONSTANT_54	(54)
#define	CONSTANT_55	(55)
#define	CONSTANT_56	(56)
#define	CONSTANT_57	(57)
#define	CONSTANT_58	(58)
#define	CONSTANT_59	(59)
#define	CONSTANT_60	(60)
#define	CONSTANT_61	(61)
#define	CONSTANT_62	(62)
#define	CONSTANT_63	(63)


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
			__BYTE	P10:1;
			__BYTE	P11:1;
			__BYTE	P12:1;
			__BYTE	P13:1;
			__BYTE	P14:1;
			__BYTE	P15:1;
			__BYTE	P16:1;
			__BYTE	P17:1;
	} bit;
	struct {
			__BYTE	P10:1;
			__BYTE	P11:1;
			__BYTE	P12:1;
			__BYTE	P13:1;
			__BYTE	P14:1;
			__BYTE	P15:1;
			__BYTE	P16:1;
			__BYTE	P17:1;
	} bitc;
} PDR1STR;

__IO_EXTERN	  PDR1STR	IO_PDR1;
#define	_pdr1		(IO_PDR1)
#define	PDR1		(IO_PDR1.byte)
#define	PDR1_P10  	(IO_PDR1.bit.P10)
#define	PDR1_P11  	(IO_PDR1.bit.P11)
#define	PDR1_P12  	(IO_PDR1.bit.P12)
#define	PDR1_P13  	(IO_PDR1.bit.P13)
#define	PDR1_P14  	(IO_PDR1.bit.P14)
#define	PDR1_P15  	(IO_PDR1.bit.P15)
#define	PDR1_P16  	(IO_PDR1.bit.P16)
#define	PDR1_P17  	(IO_PDR1.bit.P17)

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
			__BYTE	P17:1;
	} bit;
	struct {
			__BYTE	P10:1;
			__BYTE	P11:1;
			__BYTE	P12:1;
			__BYTE	P13:1;
			__BYTE	P14:1;
			__BYTE	P15:1;
			__BYTE	P16:1;
			__BYTE	P17:1;
	} bitc;
} DDR1STR;

__IO_EXTERN	  DDR1STR	IO_DDR1;
#define	_ddr1		(IO_DDR1)
#define	DDR1		(IO_DDR1.byte)
#define	DDR1_P10  	(IO_DDR1.bit.P10)
#define	DDR1_P11  	(IO_DDR1.bit.P11)
#define	DDR1_P12  	(IO_DDR1.bit.P12)
#define	DDR1_P13  	(IO_DDR1.bit.P13)
#define	DDR1_P14  	(IO_DDR1.bit.P14)
#define	DDR1_P15  	(IO_DDR1.bit.P15)
#define	DDR1_P16  	(IO_DDR1.bit.P16)
#define	DDR1_P17  	(IO_DDR1.bit.P17)

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

__IO_EXTERN	  RSRRSTR	IO_RSRR;
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
#pragma segment IO=IO_PDR2, locate=0xE
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	P20:1;
			__BYTE	P21:1;
			__BYTE	P22:1;
			__BYTE	P23:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	P20:1;
			__BYTE	P21:1;
			__BYTE	P22:1;
			__BYTE	P23:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} PDR2STR;

__IO_EXTERN	  PDR2STR	IO_PDR2;
#define	_pdr2		(IO_PDR2)
#define	PDR2		(IO_PDR2.byte)
#define	PDR2_P20  	(IO_PDR2.bit.P20)
#define	PDR2_P21  	(IO_PDR2.bit.P21)
#define	PDR2_P22  	(IO_PDR2.bit.P22)
#define	PDR2_P23  	(IO_PDR2.bit.P23)

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
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	P20:1;
			__BYTE	P21:1;
			__BYTE	P22:1;
			__BYTE	P23:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} DDR2STR;

__IO_EXTERN	  DDR2STR	IO_DDR2;
#define	_ddr2		(IO_DDR2)
#define	DDR2		(IO_DDR2.byte)
#define	DDR2_P20  	(IO_DDR2.bit.P20)
#define	DDR2_P21  	(IO_DDR2.bit.P21)
#define	DDR2_P22  	(IO_DDR2.bit.P22)
#define	DDR2_P23  	(IO_DDR2.bit.P23)

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
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	P40:1;
			__BYTE	P41:1;
			__BYTE	P42:1;
			__BYTE	P43:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} PDR4STR;

__IO_EXTERN	  PDR4STR	IO_PDR4;
#define	_pdr4		(IO_PDR4)
#define	PDR4		(IO_PDR4.byte)
#define	PDR4_P40  	(IO_PDR4.bit.P40)
#define	PDR4_P41  	(IO_PDR4.bit.P41)
#define	PDR4_P42  	(IO_PDR4.bit.P42)
#define	PDR4_P43  	(IO_PDR4.bit.P43)

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
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	P40:1;
			__BYTE	P41:1;
			__BYTE	P42:1;
			__BYTE	P43:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} DDR4STR;

__IO_EXTERN	  DDR4STR	IO_DDR4;
#define	_ddr4		(IO_DDR4)
#define	DDR4		(IO_DDR4.byte)
#define	DDR4_P40  	(IO_DDR4.bit.P40)
#define	DDR4_P41  	(IO_DDR4.bit.P41)
#define	DDR4_P42  	(IO_DDR4.bit.P42)
#define	DDR4_P43  	(IO_DDR4.bit.P43)

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
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	P50:1;
			__BYTE	P51:1;
			__BYTE	P52:1;
			__BYTE	P53:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} PDR5STR;

__IO_EXTERN	  PDR5STR	IO_PDR5;
#define	_pdr5		(IO_PDR5)
#define	PDR5		(IO_PDR5.byte)
#define	PDR5_P50  	(IO_PDR5.bit.P50)
#define	PDR5_P51  	(IO_PDR5.bit.P51)
#define	PDR5_P52  	(IO_PDR5.bit.P52)
#define	PDR5_P53  	(IO_PDR5.bit.P53)

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
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	P50:1;
			__BYTE	P51:1;
			__BYTE	P52:1;
			__BYTE	P53:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} DDR5STR;

__IO_EXTERN	  DDR5STR	IO_DDR5;
#define	_ddr5		(IO_DDR5)
#define	DDR5		(IO_DDR5.byte)
#define	DDR5_P50  	(IO_DDR5.bit.P50)
#define	DDR5_P51  	(IO_DDR5.bit.P51)
#define	DDR5_P52  	(IO_DDR5.bit.P52)
#define	DDR5_P53  	(IO_DDR5.bit.P53)

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
#define	_pdr6		(IO_PDR6)
#define	PDR6		(IO_PDR6.byte)
#define	PDR6_P60  	(IO_PDR6.bit.P60)
#define	PDR6_P61  	(IO_PDR6.bit.P61)
#define	PDR6_P62  	(IO_PDR6.bit.P62)
#define	PDR6_P63  	(IO_PDR6.bit.P63)
#define	PDR6_P64  	(IO_PDR6.bit.P64)
#define	PDR6_P65  	(IO_PDR6.bit.P65)
#define	PDR6_P66  	(IO_PDR6.bit.P66)
#define	PDR6_P67  	(IO_PDR6.bit.P67)

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
#define	_ddr6		(IO_DDR6)
#define	DDR6		(IO_DDR6.byte)
#define	DDR6_P60  	(IO_DDR6.bit.P60)
#define	DDR6_P61  	(IO_DDR6.bit.P61)
#define	DDR6_P62  	(IO_DDR6.bit.P62)
#define	DDR6_P63  	(IO_DDR6.bit.P63)
#define	DDR6_P64  	(IO_DDR6.bit.P64)
#define	DDR6_P65  	(IO_DDR6.bit.P65)
#define	DDR6_P66  	(IO_DDR6.bit.P66)
#define	DDR6_P67  	(IO_DDR6.bit.P67)

#ifdef __IO_DEFINE
#pragma segment IO=IO_PDR9, locate=0x1C
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	P90:1;
			__BYTE	P91:1;
			__BYTE	P92:1;
			__BYTE	P93:1;
			__BYTE	P94:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	P90:1;
			__BYTE	P91:1;
			__BYTE	P92:1;
			__BYTE	P93:1;
			__BYTE	P94:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} PDR9STR;

__IO_EXTERN	  PDR9STR	IO_PDR9;
#define	_pdr9		(IO_PDR9)
#define	PDR9		(IO_PDR9.byte)
#define	PDR9_P90  	(IO_PDR9.bit.P90)
#define	PDR9_P91  	(IO_PDR9.bit.P91)
#define	PDR9_P92  	(IO_PDR9.bit.P92)
#define	PDR9_P93  	(IO_PDR9.bit.P93)
#define	PDR9_P94  	(IO_PDR9.bit.P94)

#ifdef __IO_DEFINE
#pragma segment IO=IO_DDR9, locate=0x1D
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	P90:1;
			__BYTE	P91:1;
			__BYTE	P92:1;
			__BYTE	P93:1;
			__BYTE	P94:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	P90:1;
			__BYTE	P91:1;
			__BYTE	P92:1;
			__BYTE	P93:1;
			__BYTE	P94:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} DDR9STR;

__IO_EXTERN	  DDR9STR	IO_DDR9;
#define	_ddr9		(IO_DDR9)
#define	DDR9		(IO_DDR9.byte)
#define	DDR9_P90  	(IO_DDR9.bit.P90)
#define	DDR9_P91  	(IO_DDR9.bit.P91)
#define	DDR9_P92  	(IO_DDR9.bit.P92)
#define	DDR9_P93  	(IO_DDR9.bit.P93)
#define	DDR9_P94  	(IO_DDR9.bit.P94)

#ifdef __IO_DEFINE
#pragma segment IO=IO_PDRA, locate=0x1E
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	PA0:1;
			__BYTE	PA1:1;
			__BYTE	PA2:1;
			__BYTE	PA3:1;
			__BYTE	PA4:1;
			__BYTE	PA5:1;
			__BYTE	PA6:1;
			__BYTE	PA7:1;
	} bit;
	struct {
			__BYTE	PA0:1;
			__BYTE	PA1:1;
			__BYTE	PA2:1;
			__BYTE	PA3:1;
			__BYTE	PA4:1;
			__BYTE	PA5:1;
			__BYTE	PA6:1;
			__BYTE	PA7:1;
	} bitc;
} PDRASTR;

__IO_EXTERN	  PDRASTR	IO_PDRA;
#define	_pdra		(IO_PDRA)
#define	PDRA		(IO_PDRA.byte)
#define	PDRA_PA0  	(IO_PDRA.bit.PA0)
#define	PDRA_PA1  	(IO_PDRA.bit.PA1)
#define	PDRA_PA2  	(IO_PDRA.bit.PA2)
#define	PDRA_PA3  	(IO_PDRA.bit.PA3)
#define	PDRA_PA4  	(IO_PDRA.bit.PA4)
#define	PDRA_PA5  	(IO_PDRA.bit.PA5)
#define	PDRA_PA6  	(IO_PDRA.bit.PA6)
#define	PDRA_PA7  	(IO_PDRA.bit.PA7)

#ifdef __IO_DEFINE
#pragma segment IO=IO_DDRA, locate=0x1F
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	PA0:1;
			__BYTE	PA1:1;
			__BYTE	PA2:1;
			__BYTE	PA3:1;
			__BYTE	PA4:1;
			__BYTE	PA5:1;
			__BYTE	PA6:1;
			__BYTE	PA7:1;
	} bit;
	struct {
			__BYTE	PA0:1;
			__BYTE	PA1:1;
			__BYTE	PA2:1;
			__BYTE	PA3:1;
			__BYTE	PA4:1;
			__BYTE	PA5:1;
			__BYTE	PA6:1;
			__BYTE	PA7:1;
	} bitc;
} DDRASTR;

__IO_EXTERN	  DDRASTR	IO_DDRA;
#define	_ddra		(IO_DDRA)
#define	DDRA		(IO_DDRA.byte)
#define	DDRA_PA0  	(IO_DDRA.bit.PA0)
#define	DDRA_PA1  	(IO_DDRA.bit.PA1)
#define	DDRA_PA2  	(IO_DDRA.bit.PA2)
#define	DDRA_PA3  	(IO_DDRA.bit.PA3)
#define	DDRA_PA4  	(IO_DDRA.bit.PA4)
#define	DDRA_PA5  	(IO_DDRA.bit.PA5)
#define	DDRA_PA6  	(IO_DDRA.bit.PA6)
#define	DDRA_PA7  	(IO_DDRA.bit.PA7)

#ifdef __IO_DEFINE
#pragma segment IO=IO_PDRB, locate=0x20
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	PB0:1;
			__BYTE	PB1:1;
			__BYTE	PB2:1;
			__BYTE	PB3:1;
			__BYTE	PB4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	PB0:1;
			__BYTE	PB1:1;
			__BYTE	PB2:1;
			__BYTE	PB3:1;
			__BYTE	PB4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} PDRBSTR;

__IO_EXTERN	  PDRBSTR	IO_PDRB;
#define	_pdrb		(IO_PDRB)
#define	PDRB		(IO_PDRB.byte)
#define	PDRB_PB0  	(IO_PDRB.bit.PB0)
#define	PDRB_PB1  	(IO_PDRB.bit.PB1)
#define	PDRB_PB2  	(IO_PDRB.bit.PB2)
#define	PDRB_PB3  	(IO_PDRB.bit.PB3)
#define	PDRB_PB4  	(IO_PDRB.bit.PB4)

#ifdef __IO_DEFINE
#pragma segment IO=IO_DDRB, locate=0x21
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	PB0:1;
			__BYTE	PB1:1;
			__BYTE	PB2:1;
			__BYTE	PB3:1;
			__BYTE	PB4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	PB0:1;
			__BYTE	PB1:1;
			__BYTE	PB2:1;
			__BYTE	PB3:1;
			__BYTE	PB4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} DDRBSTR;

__IO_EXTERN	  DDRBSTR	IO_DDRB;
#define	_ddrb		(IO_DDRB)
#define	DDRB		(IO_DDRB.byte)
#define	DDRB_PB0  	(IO_DDRB.bit.PB0)
#define	DDRB_PB1  	(IO_DDRB.bit.PB1)
#define	DDRB_PB2  	(IO_DDRB.bit.PB2)
#define	DDRB_PB3  	(IO_DDRB.bit.PB3)
#define	DDRB_PB4  	(IO_DDRB.bit.PB4)

#ifdef __IO_DEFINE
#pragma segment IO=IO_PDRC, locate=0x22
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	PC0:1;
			__BYTE	PC1:1;
			__BYTE	PC2:1;
			__BYTE	PC3:1;
			__BYTE	PC4:1;
			__BYTE	PC5:1;
			__BYTE	PC6:1;
			__BYTE	PC7:1;
	} bit;
	struct {
			__BYTE	PC0:1;
			__BYTE	PC1:1;
			__BYTE	PC2:1;
			__BYTE	PC3:1;
			__BYTE	PC4:1;
			__BYTE	PC5:1;
			__BYTE	PC6:1;
			__BYTE	PC7:1;
	} bitc;
} PDRCSTR;

__IO_EXTERN	  PDRCSTR	IO_PDRC;
#define	_pdrc		(IO_PDRC)
#define	PDRC		(IO_PDRC.byte)
#define	PDRC_PC0  	(IO_PDRC.bit.PC0)
#define	PDRC_PC1  	(IO_PDRC.bit.PC1)
#define	PDRC_PC2  	(IO_PDRC.bit.PC2)
#define	PDRC_PC3  	(IO_PDRC.bit.PC3)
#define	PDRC_PC4  	(IO_PDRC.bit.PC4)
#define	PDRC_PC5  	(IO_PDRC.bit.PC5)
#define	PDRC_PC6  	(IO_PDRC.bit.PC6)
#define	PDRC_PC7  	(IO_PDRC.bit.PC7)

#ifdef __IO_DEFINE
#pragma segment IO=IO_DDRC, locate=0x23
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	PC0:1;
			__BYTE	PC1:1;
			__BYTE	PC2:1;
			__BYTE	PC3:1;
			__BYTE	PC4:1;
			__BYTE	PC5:1;
			__BYTE	PC6:1;
			__BYTE	PC7:1;
	} bit;
	struct {
			__BYTE	PC0:1;
			__BYTE	PC1:1;
			__BYTE	PC2:1;
			__BYTE	PC3:1;
			__BYTE	PC4:1;
			__BYTE	PC5:1;
			__BYTE	PC6:1;
			__BYTE	PC7:1;
	} bitc;
} DDRCSTR;

__IO_EXTERN	  DDRCSTR	IO_DDRC;
#define	_ddrc		(IO_DDRC)
#define	DDRC		(IO_DDRC.byte)
#define	DDRC_PC0  	(IO_DDRC.bit.PC0)
#define	DDRC_PC1  	(IO_DDRC.bit.PC1)
#define	DDRC_PC2  	(IO_DDRC.bit.PC2)
#define	DDRC_PC3  	(IO_DDRC.bit.PC3)
#define	DDRC_PC4  	(IO_DDRC.bit.PC4)
#define	DDRC_PC5  	(IO_DDRC.bit.PC5)
#define	DDRC_PC6  	(IO_DDRC.bit.PC6)
#define	DDRC_PC7  	(IO_DDRC.bit.PC7)

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
#define	_pdre		(IO_PDRE)
#define	PDRE		(IO_PDRE.byte)
#define	PDRE_PE0  	(IO_PDRE.bit.PE0)
#define	PDRE_PE1  	(IO_PDRE.bit.PE1)
#define	PDRE_PE2  	(IO_PDRE.bit.PE2)
#define	PDRE_PE3  	(IO_PDRE.bit.PE3)
#define	PDRE_PE4  	(IO_PDRE.bit.PE4)
#define	PDRE_PE5  	(IO_PDRE.bit.PE5)
#define	PDRE_PE6  	(IO_PDRE.bit.PE6)
#define	PDRE_PE7  	(IO_PDRE.bit.PE7)

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
#define	_ddre		(IO_DDRE)
#define	DDRE		(IO_DDRE.byte)
#define	DDRE_PE0  	(IO_DDRE.bit.PE0)
#define	DDRE_PE1  	(IO_DDRE.bit.PE1)
#define	DDRE_PE2  	(IO_DDRE.bit.PE2)
#define	DDRE_PE3  	(IO_DDRE.bit.PE3)
#define	DDRE_PE4  	(IO_DDRE.bit.PE4)
#define	DDRE_PE5  	(IO_DDRE.bit.PE5)
#define	DDRE_PE6  	(IO_DDRE.bit.PE6)
#define	DDRE_PE7  	(IO_DDRE.bit.PE7)

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
#pragma segment IO=IO_PUL1, locate=0x2D
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	P10:1;
			__BYTE	P11:1;
			__BYTE	RESV2:1;
			__BYTE	P13:1;
			__BYTE	P14:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	P17:1;
	} bit;
	struct {
			__BYTE	P10:1;
			__BYTE	P11:1;
			__BYTE	RESV2:1;
			__BYTE	P13:1;
			__BYTE	P14:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	P17:1;
	} bitc;
} PUL1STR;

__IO_EXTERN	  PUL1STR	IO_PUL1;
#define	_pul1		(IO_PUL1)
#define	PUL1		(IO_PUL1.byte)
#define	PUL1_P10  	(IO_PUL1.bit.P10)
#define	PUL1_P11  	(IO_PUL1.bit.P11)
#define	PUL1_P13  	(IO_PUL1.bit.P13)
#define	PUL1_P14  	(IO_PUL1.bit.P14)
#define	PUL1_P17  	(IO_PUL1.bit.P17)

#ifdef __IO_DEFINE
#pragma segment IO=IO_PUL2, locate=0x2E
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	P20:1;
			__BYTE	P21:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	P20:1;
			__BYTE	P21:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} PUL2STR;

__IO_EXTERN	  PUL2STR	IO_PUL2;
#define	_pul2		(IO_PUL2)
#define	PUL2		(IO_PUL2.byte)
#define	PUL2_P20  	(IO_PUL2.bit.P20)
#define	PUL2_P21  	(IO_PUL2.bit.P21)

#ifdef __IO_DEFINE
#pragma segment IO=IO_PUL5, locate=0x31
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	P50:1;
			__BYTE	P51:1;
			__BYTE	P52:1;
			__BYTE	P53:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	P50:1;
			__BYTE	P51:1;
			__BYTE	P52:1;
			__BYTE	P53:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} PUL5STR;

__IO_EXTERN	  PUL5STR	IO_PUL5;
#define	_pul5		(IO_PUL5)
#define	PUL5		(IO_PUL5.byte)
#define	PUL5_P50  	(IO_PUL5.bit.P50)
#define	PUL5_P51  	(IO_PUL5.bit.P51)
#define	PUL5_P52  	(IO_PUL5.bit.P52)
#define	PUL5_P53  	(IO_PUL5.bit.P53)

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
#define	_pc11		(IO_PC11)
#define	PC11		(IO_PC11.byte)
#define	PC11_CKS10  	(IO_PC11.bit.CKS10)
#define	PC11_CKS11  	(IO_PC11.bit.CKS11)
#define	PC11_CKS12  	(IO_PC11.bit.CKS12)
#define	PC11_POEN1  	(IO_PC11.bit.POEN1)
#define	PC11_PUF1  	(IO_PC11.bit.PUF1)
#define	PC11_PIE1  	(IO_PC11.bit.PIE1)

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
#define	_pc10		(IO_PC10)
#define	PC10		(IO_PC10.byte)
#define	PC10_CKS00  	(IO_PC10.bit.CKS00)
#define	PC10_CKS01  	(IO_PC10.bit.CKS01)
#define	PC10_CKS02  	(IO_PC10.bit.CKS02)
#define	PC10_POEN0  	(IO_PC10.bit.POEN0)
#define	PC10_PUF0  	(IO_PC10.bit.PUF0)
#define	PC10_PIE0  	(IO_PC10.bit.PIE0)
#define	PC10_MD0  	(IO_PC10.bit.MD0)
#define	PC10_MD1  	(IO_PC10.bit.MD1)

#ifdef __IO_DEFINE
#pragma segment IO=IO_TMCSRH, locate=0x3E
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
} TMCSRHSTR;

__IO_EXTERN	  TMCSRHSTR	IO_TMCSRH;
#define	_tmcsrh		(IO_TMCSRH)
#define	TMCSRH		(IO_TMCSRH.byte)
#define	TMCSRH_MOD0  	(IO_TMCSRH.bit.MOD0)
#define	TMCSRH_MOD1  	(IO_TMCSRH.bit.MOD1)
#define	TMCSRH_MOD2  	(IO_TMCSRH.bit.MOD2)
#define	TMCSRH_CSL0  	(IO_TMCSRH.bit.CSL0)
#define	TMCSRH_CSL1  	(IO_TMCSRH.bit.CSL1)
#define	TMCSRH_CSL2  	(IO_TMCSRH.bit.CSL2)

#ifdef __IO_DEFINE
#pragma segment IO=IO_TMCSRL, locate=0x3F
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
} TMCSRLSTR;

__IO_EXTERN	  TMCSRLSTR	IO_TMCSRL;
#define	_tmcsrl		(IO_TMCSRL)
#define	TMCSRL		(IO_TMCSRL.byte)
#define	TMCSRL_TRG  	(IO_TMCSRL.bit.TRG)
#define	TMCSRL_CNTE  	(IO_TMCSRL.bit.CNTE)
#define	TMCSRL_UF  	(IO_TMCSRL.bit.UF)
#define	TMCSRL_INTE  	(IO_TMCSRL.bit.INTE)
#define	TMCSRL_RELD  	(IO_TMCSRL.bit.RELD)
#define	TMCSRL_OUTL  	(IO_TMCSRL.bit.OUTL)
#define	TMCSRL_OUTE  	(IO_TMCSRL.bit.OUTE)

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
#pragma segment IO=IO_LVDC, locate=0x4E
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	LVIF:1;
			__BYTE	LVDSEL0:1;
			__BYTE	LVDSEL1:1;
			__BYTE	LVDSEL2:1;
			__BYTE	LVDSEL3:1;
			__BYTE	LVDLP:1;
			__BYTE	LVIEN:1;
			__BYTE	LVIIF:1;
	} bit;
	struct {
			__BYTE	LVIF:1;
			__BYTE	LVDSEL0:1;
			__BYTE	LVDSEL1:1;
			__BYTE	LVDSEL2:1;
			__BYTE	LVDSEL3:1;
			__BYTE	LVDLP:1;
			__BYTE	LVIEN:1;
			__BYTE	LVIIF:1;
	} bitc;
} LVDCSTR;

__IO_EXTERN	  LVDCSTR	IO_LVDC;
#define	_lvdc		(IO_LVDC)
#define	LVDC		(IO_LVDC.byte)
#define	LVDC_LVIF  	(IO_LVDC.bit.LVIF)
#define	LVDC_LVDSEL0  	(IO_LVDC.bit.LVDSEL0)
#define	LVDC_LVDSEL1  	(IO_LVDC.bit.LVDSEL1)
#define	LVDC_LVDSEL2  	(IO_LVDC.bit.LVDSEL2)
#define	LVDC_LVDSEL3  	(IO_LVDC.bit.LVDSEL3)
#define	LVDC_LVDLP  	(IO_LVDC.bit.LVDLP)
#define	LVDC_LVIEN  	(IO_LVDC.bit.LVIEN)
#define	LVDC_LVIIF  	(IO_LVDC.bit.LVIIF)

#ifdef __IO_DEFINE
#pragma segment IO=IO_LCDCC2, locate=0x4F
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	LCDIF:1;
			__BYTE	LCDIEN:1;
			__BYTE	BK:1;
			__BYTE	INV:1;
			__BYTE	BLS8:1;
			__BYTE	RSEL:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	LCDIF:1;
			__BYTE	LCDIEN:1;
			__BYTE	BK:1;
			__BYTE	INV:1;
			__BYTE	BLS8:1;
			__BYTE	RSEL:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} LCDCC2STR;

__IO_EXTERN	  LCDCC2STR	IO_LCDCC2;
#define	_lcdcc2		(IO_LCDCC2)
#define	LCDCC2		(IO_LCDCC2.byte)
#define	LCDCC2_LCDIF  	(IO_LCDCC2.bit.LCDIF)
#define	LCDCC2_LCDIEN  	(IO_LCDCC2.bit.LCDIEN)
#define	LCDCC2_BK  	(IO_LCDCC2.bit.BK)
#define	LCDCC2_INV  	(IO_LCDCC2.bit.INV)
#define	LCDCC2_BLS8  	(IO_LCDCC2.bit.BLS8)
#define	LCDCC2_RSEL  	(IO_LCDCC2.bit.RSEL)

#ifdef __IO_DEFINE
#pragma segment IO=IO_CMR0, locate=0x50
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
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	PD:1;
			__BYTE	VCOE:1;
			__BYTE	VCID:1;
			__BYTE	IE:1;
			__BYTE	IF:1;
			__BYTE	OS:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
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
#pragma segment IO=IO_SMC11, locate=0x5B
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
} SMC11STR;

__IO_EXTERN	  SMC11STR	IO_SMC11;
#define	_smc11		(IO_SMC11)
#define	SMC11		(IO_SMC11.byte)
#define	SMC11_MD  	(IO_SMC11.bit.MD)
#define	SMC11_CKS  	(IO_SMC11.bit.CKS)
#define	SMC11_CBL0  	(IO_SMC11.bit.CBL0)
#define	SMC11_CBL1  	(IO_SMC11.bit.CBL1)
#define	SMC11_SBL  	(IO_SMC11.bit.SBL)
#define	SMC11_TDP  	(IO_SMC11.bit.TDP)
#define	SMC11_PEN  	(IO_SMC11.bit.PEN)
#define	SMC11_BDS  	(IO_SMC11.bit.BDS)

#ifdef __IO_DEFINE
#pragma segment IO=IO_SMC21, locate=0x5C
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
} SMC21STR;

__IO_EXTERN	  SMC21STR	IO_SMC21;
#define	_smc21		(IO_SMC21)
#define	SMC21		(IO_SMC21.byte)
#define	SMC21_TEIE  	(IO_SMC21.bit.TEIE)
#define	SMC21_TCIE  	(IO_SMC21.bit.TCIE)
#define	SMC21_RIE  	(IO_SMC21.bit.RIE)
#define	SMC21_TXE  	(IO_SMC21.bit.TXE)
#define	SMC21_RXE  	(IO_SMC21.bit.RXE)
#define	SMC21_RERC  	(IO_SMC21.bit.RERC)
#define	SMC21_TXOE  	(IO_SMC21.bit.TXOE)
#define	SMC21_SCKE  	(IO_SMC21.bit.SCKE)

#ifdef __IO_DEFINE
#pragma segment IO=IO_SSR1, locate=0x5D
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
} SSR1STR;

__IO_EXTERN	  SSR1STR	IO_SSR1;
#define	_ssr1		(IO_SSR1)
#define	SSR1		(IO_SSR1.byte)
#define	SSR1_TDRE  	(IO_SSR1.bit.TDRE)
#define	SSR1_TCPL  	(IO_SSR1.bit.TCPL)
#define	SSR1_RDRF  	(IO_SSR1.bit.RDRF)
#define	SSR1_FER  	(IO_SSR1.bit.FER)
#define	SSR1_OVE  	(IO_SSR1.bit.OVE)
#define	SSR1_PER  	(IO_SSR1.bit.PER)

#ifdef __IO_DEFINE
#pragma segment IO=IO_TDR1, locate=0x5E
#endif

__IO_EXTERN	__BYTE	IO_TDR1;
#define	_tdr1		(IO_TDR1)
#define	TDR1	(_tdr1)

#ifdef __IO_DEFINE
#pragma segment IO=IO_RDR1, locate=0x5F
#endif

__IO_EXTERN	const __BYTE	IO_RDR1;
#define	_rdr1		(IO_RDR1)
#define	RDR1	(_rdr1)

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
			__BYTE	FBE:1;
			__BYTE	GCA:1;
			__BYTE	AAS:1;
			__BYTE	TRX:1;
			__BYTE	LRB:1;
			__BYTE	RESV5:1;
			__BYTE	RSC:1;
			__BYTE	BB:1;
	} bit;
	struct {
			__BYTE	FBE:1;
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
#define	IBSR0_FBE  	(IO_IBSR0.bit.FBE)
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
#pragma segment IO=IO_SMC12, locate=0x66
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
} SMC12STR;

__IO_EXTERN	  SMC12STR	IO_SMC12;
#define	_smc12		(IO_SMC12)
#define	SMC12		(IO_SMC12.byte)
#define	SMC12_MD  	(IO_SMC12.bit.MD)
#define	SMC12_CKS  	(IO_SMC12.bit.CKS)
#define	SMC12_CBL0  	(IO_SMC12.bit.CBL0)
#define	SMC12_CBL1  	(IO_SMC12.bit.CBL1)
#define	SMC12_SBL  	(IO_SMC12.bit.SBL)
#define	SMC12_TDP  	(IO_SMC12.bit.TDP)
#define	SMC12_PEN  	(IO_SMC12.bit.PEN)
#define	SMC12_BDS  	(IO_SMC12.bit.BDS)

#ifdef __IO_DEFINE
#pragma segment IO=IO_SMC22, locate=0x67
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
} SMC22STR;

__IO_EXTERN	  SMC22STR	IO_SMC22;
#define	_smc22		(IO_SMC22)
#define	SMC22		(IO_SMC22.byte)
#define	SMC22_TEIE  	(IO_SMC22.bit.TEIE)
#define	SMC22_TCIE  	(IO_SMC22.bit.TCIE)
#define	SMC22_RIE  	(IO_SMC22.bit.RIE)
#define	SMC22_TXE  	(IO_SMC22.bit.TXE)
#define	SMC22_RXE  	(IO_SMC22.bit.RXE)
#define	SMC22_RERC  	(IO_SMC22.bit.RERC)
#define	SMC22_TXOE  	(IO_SMC22.bit.TXOE)
#define	SMC22_SCKE  	(IO_SMC22.bit.SCKE)

#ifdef __IO_DEFINE
#pragma segment IO=IO_SSR2, locate=0x68
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
} SSR2STR;

__IO_EXTERN	  SSR2STR	IO_SSR2;
#define	_ssr2		(IO_SSR2)
#define	SSR2		(IO_SSR2.byte)
#define	SSR2_TDRE  	(IO_SSR2.bit.TDRE)
#define	SSR2_TCPL  	(IO_SSR2.bit.TCPL)
#define	SSR2_RDRF  	(IO_SSR2.bit.RDRF)
#define	SSR2_FER  	(IO_SSR2.bit.FER)
#define	SSR2_OVE  	(IO_SSR2.bit.OVE)
#define	SSR2_PER  	(IO_SSR2.bit.PER)

#ifdef __IO_DEFINE
#pragma segment IO=IO_TDR2, locate=0x69
#endif

__IO_EXTERN	__BYTE	IO_TDR2;
#define	_tdr2		(IO_TDR2)
#define	TDR2	(_tdr2)

#ifdef __IO_DEFINE
#pragma segment IO=IO_RDR2, locate=0x6A
#endif

__IO_EXTERN	const __BYTE	IO_RDR2;
#define	_rdr2		(IO_RDR2)
#define	RDR2	(_rdr2)

#ifdef __IO_DEFINE
#pragma segment IO=IO_ADC3, locate=0x6B
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	ENBL:1;
			__BYTE	READY:1;
			__BYTE	ENTM0:1;
			__BYTE	ENTM1:1;
			__BYTE	ENTM2:1;
			__BYTE	ENTM3:1;
			__BYTE	ENTM4:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	ENBL:1;
			__BYTE	READY:1;
			__BYTE	ENTM0:1;
			__BYTE	ENTM1:1;
			__BYTE	ENTM2:1;
			__BYTE	ENTM3:1;
			__BYTE	ENTM4:1;
			__BYTE	RESV7:1;
	} bitc;
} ADC3STR;

__IO_EXTERN	  ADC3STR	IO_ADC3;
#define	_adc3		(IO_ADC3)
#define	ADC3		(IO_ADC3.byte)
#define	ADC3_ENBL  	(IO_ADC3.bit.ENBL)
#define	ADC3_READY  	(IO_ADC3.bit.READY)
#define	ADC3_ENTM0  	(IO_ADC3.bit.ENTM0)
#define	ADC3_ENTM1  	(IO_ADC3.bit.ENTM1)
#define	ADC3_ENTM2  	(IO_ADC3.bit.ENTM2)
#define	ADC3_ENTM3  	(IO_ADC3.bit.ENTM3)
#define	ADC3_ENTM4  	(IO_ADC3.bit.ENTM4)

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
#define	_wcsr		(IO_WCSR)
#define	WCSR		(IO_WCSR.byte)
#define	WCSR_CTR0  	(IO_WCSR.bit.CTR0)
#define	WCSR_CTR1  	(IO_WCSR.bit.CTR1)
#define	WCSR_CTR2  	(IO_WCSR.bit.CTR2)
#define	WCSR_CTR3  	(IO_WCSR.bit.CTR3)
#define	WCSR_CTR4  	(IO_WCSR.bit.CTR4)
#define	WCSR_CTR5  	(IO_WCSR.bit.CTR5)
#define	WCSR_WCFLG  	(IO_WCSR.bit.WCFLG)
#define	WCSR_ISEL  	(IO_WCSR.bit.ISEL)

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

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	L000:1;
			__BYTE	L001:1;
			__BYTE	L010:1;
			__BYTE	L011:1;
			__BYTE	L020:1;
			__BYTE	L021:1;
			__BYTE	L030:1;
			__BYTE	L031:1;
	} bit;
	struct {
			__BYTE	L000:1;
			__BYTE	L001:1;
			__BYTE	L010:1;
			__BYTE	L011:1;
			__BYTE	L020:1;
			__BYTE	L021:1;
			__BYTE	L030:1;
			__BYTE	L031:1;
	} bitc;
} ILR0STR;

__IO_EXTERN	  ILR0STR	IO_ILR0;
#define	_ilr0		(IO_ILR0)
#define	ILR0		(IO_ILR0.byte)
#define	ILR0_L000  	(IO_ILR0.bit.L000)
#define	ILR0_L001  	(IO_ILR0.bit.L001)
#define	ILR0_L010  	(IO_ILR0.bit.L010)
#define	ILR0_L011  	(IO_ILR0.bit.L011)
#define	ILR0_L020  	(IO_ILR0.bit.L020)
#define	ILR0_L021  	(IO_ILR0.bit.L021)
#define	ILR0_L030  	(IO_ILR0.bit.L030)
#define	ILR0_L031  	(IO_ILR0.bit.L031)

#ifdef __IO_DEFINE
#pragma segment IO=IO_ILR1, locate=0x7A
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	L040:1;
			__BYTE	L041:1;
			__BYTE	L050:1;
			__BYTE	L051:1;
			__BYTE	L060:1;
			__BYTE	L061:1;
			__BYTE	L070:1;
			__BYTE	L071:1;
	} bit;
	struct {
			__BYTE	L040:1;
			__BYTE	L041:1;
			__BYTE	L050:1;
			__BYTE	L051:1;
			__BYTE	L060:1;
			__BYTE	L061:1;
			__BYTE	L070:1;
			__BYTE	L071:1;
	} bitc;
} ILR1STR;

__IO_EXTERN	  ILR1STR	IO_ILR1;
#define	_ilr1		(IO_ILR1)
#define	ILR1		(IO_ILR1.byte)
#define	ILR1_L040  	(IO_ILR1.bit.L040)
#define	ILR1_L041  	(IO_ILR1.bit.L041)
#define	ILR1_L050  	(IO_ILR1.bit.L050)
#define	ILR1_L051  	(IO_ILR1.bit.L051)
#define	ILR1_L060  	(IO_ILR1.bit.L060)
#define	ILR1_L061  	(IO_ILR1.bit.L061)
#define	ILR1_L070  	(IO_ILR1.bit.L070)
#define	ILR1_L071  	(IO_ILR1.bit.L071)

#ifdef __IO_DEFINE
#pragma segment IO=IO_ILR2, locate=0x7B
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	L080:1;
			__BYTE	L081:1;
			__BYTE	L090:1;
			__BYTE	L091:1;
			__BYTE	L100:1;
			__BYTE	L101:1;
			__BYTE	L110:1;
			__BYTE	L111:1;
	} bit;
	struct {
			__BYTE	L080:1;
			__BYTE	L081:1;
			__BYTE	L090:1;
			__BYTE	L091:1;
			__BYTE	L100:1;
			__BYTE	L101:1;
			__BYTE	L110:1;
			__BYTE	L111:1;
	} bitc;
} ILR2STR;

__IO_EXTERN	  ILR2STR	IO_ILR2;
#define	_ilr2		(IO_ILR2)
#define	ILR2		(IO_ILR2.byte)
#define	ILR2_L080  	(IO_ILR2.bit.L080)
#define	ILR2_L081  	(IO_ILR2.bit.L081)
#define	ILR2_L090  	(IO_ILR2.bit.L090)
#define	ILR2_L091  	(IO_ILR2.bit.L091)
#define	ILR2_L100  	(IO_ILR2.bit.L100)
#define	ILR2_L101  	(IO_ILR2.bit.L101)
#define	ILR2_L110  	(IO_ILR2.bit.L110)
#define	ILR2_L111  	(IO_ILR2.bit.L111)

#ifdef __IO_DEFINE
#pragma segment IO=IO_ILR3, locate=0x7C
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	L120:1;
			__BYTE	L121:1;
			__BYTE	L130:1;
			__BYTE	L131:1;
			__BYTE	L140:1;
			__BYTE	L141:1;
			__BYTE	L150:1;
			__BYTE	L151:1;
	} bit;
	struct {
			__BYTE	L120:1;
			__BYTE	L121:1;
			__BYTE	L130:1;
			__BYTE	L131:1;
			__BYTE	L140:1;
			__BYTE	L141:1;
			__BYTE	L150:1;
			__BYTE	L151:1;
	} bitc;
} ILR3STR;

__IO_EXTERN	  ILR3STR	IO_ILR3;
#define	_ilr3		(IO_ILR3)
#define	ILR3		(IO_ILR3.byte)
#define	ILR3_L120  	(IO_ILR3.bit.L120)
#define	ILR3_L121  	(IO_ILR3.bit.L121)
#define	ILR3_L130  	(IO_ILR3.bit.L130)
#define	ILR3_L131  	(IO_ILR3.bit.L131)
#define	ILR3_L140  	(IO_ILR3.bit.L140)
#define	ILR3_L141  	(IO_ILR3.bit.L141)
#define	ILR3_L150  	(IO_ILR3.bit.L150)
#define	ILR3_L151  	(IO_ILR3.bit.L151)

#ifdef __IO_DEFINE
#pragma segment IO=IO_ILR4, locate=0x7D
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	L160:1;
			__BYTE	L161:1;
			__BYTE	L170:1;
			__BYTE	L171:1;
			__BYTE	L180:1;
			__BYTE	L181:1;
			__BYTE	L190:1;
			__BYTE	L191:1;
	} bit;
	struct {
			__BYTE	L160:1;
			__BYTE	L161:1;
			__BYTE	L170:1;
			__BYTE	L171:1;
			__BYTE	L180:1;
			__BYTE	L181:1;
			__BYTE	L190:1;
			__BYTE	L191:1;
	} bitc;
} ILR4STR;

__IO_EXTERN	  ILR4STR	IO_ILR4;
#define	_ilr4		(IO_ILR4)
#define	ILR4		(IO_ILR4.byte)
#define	ILR4_L160  	(IO_ILR4.bit.L160)
#define	ILR4_L161  	(IO_ILR4.bit.L161)
#define	ILR4_L170  	(IO_ILR4.bit.L170)
#define	ILR4_L171  	(IO_ILR4.bit.L171)
#define	ILR4_L180  	(IO_ILR4.bit.L180)
#define	ILR4_L181  	(IO_ILR4.bit.L181)
#define	ILR4_L190  	(IO_ILR4.bit.L190)
#define	ILR4_L191  	(IO_ILR4.bit.L191)

#ifdef __IO_DEFINE
#pragma segment IO=IO_ILR5, locate=0x7E
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	L200:1;
			__BYTE	L201:1;
			__BYTE	L210:1;
			__BYTE	L211:1;
			__BYTE	L220:1;
			__BYTE	L221:1;
			__BYTE	L230:1;
			__BYTE	L231:1;
	} bit;
	struct {
			__BYTE	L200:1;
			__BYTE	L201:1;
			__BYTE	L210:1;
			__BYTE	L211:1;
			__BYTE	L220:1;
			__BYTE	L221:1;
			__BYTE	L230:1;
			__BYTE	L231:1;
	} bitc;
} ILR5STR;

__IO_EXTERN	  ILR5STR	IO_ILR5;
#define	_ilr5		(IO_ILR5)
#define	ILR5		(IO_ILR5.byte)
#define	ILR5_L200  	(IO_ILR5.bit.L200)
#define	ILR5_L201  	(IO_ILR5.bit.L201)
#define	ILR5_L210  	(IO_ILR5.bit.L210)
#define	ILR5_L211  	(IO_ILR5.bit.L211)
#define	ILR5_L220  	(IO_ILR5.bit.L220)
#define	ILR5_L221  	(IO_ILR5.bit.L221)
#define	ILR5_L230  	(IO_ILR5.bit.L230)
#define	ILR5_L231  	(IO_ILR5.bit.L231)

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
#pragma segment     DATA=IO_PPS11,   locate=0xFA0
#endif

__IO_EXTENDED	__BYTE	IO_PPS11;
#define	_pps11		(IO_PPS11)
#define	PPS11	(_pps11)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_PPS10,   locate=0xFA1
#endif

__IO_EXTENDED	__BYTE	IO_PPS10;
#define	_pps10		(IO_PPS10)
#define	PPS10	(_pps10)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_PDS11,   locate=0xFA2
#endif

__IO_EXTENDED	__BYTE	IO_PDS11;
#define	_pds11		(IO_PDS11)
#define	PDS11	(_pds11)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_PDS10,   locate=0xFA3
#endif

__IO_EXTENDED	__BYTE	IO_PDS10;
#define	_pds10		(IO_PDS10)
#define	PDS10	(_pds10)

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
#pragma segment     DATA=IO_TMR0,   locate=0xFA6
#endif

__IO_EXTENDED	__WORD	IO_TMR0;
#define	_tmr0		(IO_TMR0)
#define	TMR0	(_tmr0)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_PSSR0,   locate=0xFA8
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
#pragma segment     DATA=IO_BRSR0,   locate=0xFA9
#endif

__IO_EXTENDED	__BYTE	IO_BRSR0;
#define	_brsr0		(IO_BRSR0)
#define	BRSR0	(_brsr0)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_PSSR1,   locate=0xFAA
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
} PSSR1STR;

__IO_EXTENDED	  PSSR1STR	IO_PSSR1;
#define	_pssr1		(IO_PSSR1)
#define	PSSR1		(IO_PSSR1.byte)
#define	PSSR1_PSS0  	(IO_PSSR1.bit.PSS0)
#define	PSSR1_PSS1  	(IO_PSSR1.bit.PSS1)
#define	PSSR1_BRGE  	(IO_PSSR1.bit.BRGE)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_BRSR1,   locate=0xFAB
#endif

__IO_EXTENDED	__BYTE	IO_BRSR1;
#define	_brsr1		(IO_BRSR1)
#define	BRSR1	(_brsr1)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_PSSR2,   locate=0xFAC
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
} PSSR2STR;

__IO_EXTENDED	  PSSR2STR	IO_PSSR2;
#define	_pssr2		(IO_PSSR2)
#define	PSSR2		(IO_PSSR2.byte)
#define	PSSR2_PSS0  	(IO_PSSR2.bit.PSS0)
#define	PSSR2_PSS1  	(IO_PSSR2.bit.PSS1)
#define	PSSR2_BRGE  	(IO_PSSR2.bit.BRGE)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_BRSR2,   locate=0xFAD
#endif

__IO_EXTENDED	__BYTE	IO_BRSR2;
#define	_brsr2		(IO_BRSR2)
#define	BRSR2	(_brsr2)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_AIDRL,   locate=0xFAF
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
#define	AIDRL_P06  	(IO_AIDRL.bit.P06)
#define	AIDRL_P07  	(IO_AIDRL.bit.P07)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_LCDCC1,   locate=0xFB0
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	FP0:1;
			__BYTE	FP1:1;
			__BYTE	MS0:1;
			__BYTE	MS1:1;
			__BYTE	MS2:1;
			__BYTE	VSEL:1;
			__BYTE	LCDEN:1;
			__BYTE	CSS:1;
	} bit;
	struct {
			__BYTE	FP0:1;
			__BYTE	FP1:1;
			__BYTE	MS0:1;
			__BYTE	MS1:1;
			__BYTE	MS2:1;
			__BYTE	VSEL:1;
			__BYTE	LCDEN:1;
			__BYTE	CSS:1;
	} bitc;
} LCDCC1STR;

__IO_EXTENDED	  LCDCC1STR	IO_LCDCC1;
#define	_lcdcc1		(IO_LCDCC1)
#define	LCDCC1		(IO_LCDCC1.byte)
#define	LCDCC1_FP0  	(IO_LCDCC1.bit.FP0)
#define	LCDCC1_FP1  	(IO_LCDCC1.bit.FP1)
#define	LCDCC1_MS0  	(IO_LCDCC1.bit.MS0)
#define	LCDCC1_MS1  	(IO_LCDCC1.bit.MS1)
#define	LCDCC1_MS2  	(IO_LCDCC1.bit.MS2)
#define	LCDCC1_VSEL  	(IO_LCDCC1.bit.VSEL)
#define	LCDCC1_LCDEN  	(IO_LCDCC1.bit.LCDEN)
#define	LCDCC1_CSS  	(IO_LCDCC1.bit.CSS)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_LCDCE1,   locate=0xFB2
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	RESV0:1;
			__BYTE	VE0:1;
			__BYTE	VE1:1;
			__BYTE	VE2:1;
			__BYTE	VE3:1;
			__BYTE	VE4:1;
			__BYTE	BLSEL:1;
			__BYTE	PICTL:1;
	} bit;
	struct {
			__BYTE	RESV0:1;
			__BYTE	VE0:1;
			__BYTE	VE1:1;
			__BYTE	VE2:1;
			__BYTE	VE3:1;
			__BYTE	VE4:1;
			__BYTE	BLSEL:1;
			__BYTE	PICTL:1;
	} bitc;
} LCDCE1STR;

__IO_EXTENDED	  LCDCE1STR	IO_LCDCE1;
#define	_lcdce1		(IO_LCDCE1)
#define	LCDCE1		(IO_LCDCE1.byte)
#define	LCDCE1_VE0  	(IO_LCDCE1.bit.VE0)
#define	LCDCE1_VE1  	(IO_LCDCE1.bit.VE1)
#define	LCDCE1_VE2  	(IO_LCDCE1.bit.VE2)
#define	LCDCE1_VE3  	(IO_LCDCE1.bit.VE3)
#define	LCDCE1_VE4  	(IO_LCDCE1.bit.VE4)
#define	LCDCE1_BLSEL  	(IO_LCDCE1.bit.BLSEL)
#define	LCDCE1_PICTL  	(IO_LCDCE1.bit.PICTL)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_LCDCE2,   locate=0xFB3
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	COM0:1;
			__BYTE	COM1:1;
			__BYTE	COM2:1;
			__BYTE	COM3:1;
			__BYTE	COM4:1;
			__BYTE	COM5:1;
			__BYTE	COM6:1;
			__BYTE	COM7:1;
	} bit;
	struct {
			__BYTE	COM0:1;
			__BYTE	COM1:1;
			__BYTE	COM2:1;
			__BYTE	COM3:1;
			__BYTE	COM4:1;
			__BYTE	COM5:1;
			__BYTE	COM6:1;
			__BYTE	COM7:1;
	} bitc;
} LCDCE2STR;

__IO_EXTENDED	  LCDCE2STR	IO_LCDCE2;
#define	_lcdce2		(IO_LCDCE2)
#define	LCDCE2		(IO_LCDCE2.byte)
#define	LCDCE2_COM0  	(IO_LCDCE2.bit.COM0)
#define	LCDCE2_COM1  	(IO_LCDCE2.bit.COM1)
#define	LCDCE2_COM2  	(IO_LCDCE2.bit.COM2)
#define	LCDCE2_COM3  	(IO_LCDCE2.bit.COM3)
#define	LCDCE2_COM4  	(IO_LCDCE2.bit.COM4)
#define	LCDCE2_COM5  	(IO_LCDCE2.bit.COM5)
#define	LCDCE2_COM6  	(IO_LCDCE2.bit.COM6)
#define	LCDCE2_COM7  	(IO_LCDCE2.bit.COM7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_LCDCE3,   locate=0xFB4
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	SEG00:1;
			__BYTE	SEG01:1;
			__BYTE	SEG02:1;
			__BYTE	SEG03:1;
			__BYTE	SEG04:1;
			__BYTE	SEG05:1;
			__BYTE	SEG06:1;
			__BYTE	SEG07:1;
	} bit;
	struct {
			__BYTE	SEG00:1;
			__BYTE	SEG01:1;
			__BYTE	SEG02:1;
			__BYTE	SEG03:1;
			__BYTE	SEG04:1;
			__BYTE	SEG05:1;
			__BYTE	SEG06:1;
			__BYTE	SEG07:1;
	} bitc;
} LCDCE3STR;

__IO_EXTENDED	  LCDCE3STR	IO_LCDCE3;
#define	_lcdce3		(IO_LCDCE3)
#define	LCDCE3		(IO_LCDCE3.byte)
#define	LCDCE3_SEG00  	(IO_LCDCE3.bit.SEG00)
#define	LCDCE3_SEG01  	(IO_LCDCE3.bit.SEG01)
#define	LCDCE3_SEG02  	(IO_LCDCE3.bit.SEG02)
#define	LCDCE3_SEG03  	(IO_LCDCE3.bit.SEG03)
#define	LCDCE3_SEG04  	(IO_LCDCE3.bit.SEG04)
#define	LCDCE3_SEG05  	(IO_LCDCE3.bit.SEG05)
#define	LCDCE3_SEG06  	(IO_LCDCE3.bit.SEG06)
#define	LCDCE3_SEG07  	(IO_LCDCE3.bit.SEG07)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_LCDCE4,   locate=0xFB5
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	SEG08:1;
			__BYTE	SEG09:1;
			__BYTE	SEG10:1;
			__BYTE	SEG11:1;
			__BYTE	SEG12:1;
			__BYTE	SEG13:1;
			__BYTE	SEG14:1;
			__BYTE	SEG15:1;
	} bit;
	struct {
			__BYTE	SEG08:1;
			__BYTE	SEG09:1;
			__BYTE	SEG10:1;
			__BYTE	SEG11:1;
			__BYTE	SEG12:1;
			__BYTE	SEG13:1;
			__BYTE	SEG14:1;
			__BYTE	SEG15:1;
	} bitc;
} LCDCE4STR;

__IO_EXTENDED	  LCDCE4STR	IO_LCDCE4;
#define	_lcdce4		(IO_LCDCE4)
#define	LCDCE4		(IO_LCDCE4.byte)
#define	LCDCE4_SEG08  	(IO_LCDCE4.bit.SEG08)
#define	LCDCE4_SEG09  	(IO_LCDCE4.bit.SEG09)
#define	LCDCE4_SEG10  	(IO_LCDCE4.bit.SEG10)
#define	LCDCE4_SEG11  	(IO_LCDCE4.bit.SEG11)
#define	LCDCE4_SEG12  	(IO_LCDCE4.bit.SEG12)
#define	LCDCE4_SEG13  	(IO_LCDCE4.bit.SEG13)
#define	LCDCE4_SEG14  	(IO_LCDCE4.bit.SEG14)
#define	LCDCE4_SEG15  	(IO_LCDCE4.bit.SEG15)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_LCDCE5,   locate=0xFB6
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	SEG16:1;
			__BYTE	SEG17:1;
			__BYTE	SEG18:1;
			__BYTE	SEG19:1;
			__BYTE	SEG20:1;
			__BYTE	SEG21:1;
			__BYTE	SEG22:1;
			__BYTE	SEG23:1;
	} bit;
	struct {
			__BYTE	SEG16:1;
			__BYTE	SEG17:1;
			__BYTE	SEG18:1;
			__BYTE	SEG19:1;
			__BYTE	SEG20:1;
			__BYTE	SEG21:1;
			__BYTE	SEG22:1;
			__BYTE	SEG23:1;
	} bitc;
} LCDCE5STR;

__IO_EXTENDED	  LCDCE5STR	IO_LCDCE5;
#define	_lcdce5		(IO_LCDCE5)
#define	LCDCE5		(IO_LCDCE5.byte)
#define	LCDCE5_SEG16  	(IO_LCDCE5.bit.SEG16)
#define	LCDCE5_SEG17  	(IO_LCDCE5.bit.SEG17)
#define	LCDCE5_SEG18  	(IO_LCDCE5.bit.SEG18)
#define	LCDCE5_SEG19  	(IO_LCDCE5.bit.SEG19)
#define	LCDCE5_SEG20  	(IO_LCDCE5.bit.SEG20)
#define	LCDCE5_SEG21  	(IO_LCDCE5.bit.SEG21)
#define	LCDCE5_SEG22  	(IO_LCDCE5.bit.SEG22)
#define	LCDCE5_SEG23  	(IO_LCDCE5.bit.SEG23)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_LCDCE6,   locate=0xFB7
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	SEG24:1;
			__BYTE	SEG25:1;
			__BYTE	SEG26:1;
			__BYTE	SEG27:1;
			__BYTE	SEG28:1;
			__BYTE	SEG29:1;
			__BYTE	SEG30:1;
			__BYTE	SEG31:1;
	} bit;
	struct {
			__BYTE	SEG24:1;
			__BYTE	SEG25:1;
			__BYTE	SEG26:1;
			__BYTE	SEG27:1;
			__BYTE	SEG28:1;
			__BYTE	SEG29:1;
			__BYTE	SEG30:1;
			__BYTE	SEG31:1;
	} bitc;
} LCDCE6STR;

__IO_EXTENDED	  LCDCE6STR	IO_LCDCE6;
#define	_lcdce6		(IO_LCDCE6)
#define	LCDCE6		(IO_LCDCE6.byte)
#define	LCDCE6_SEG24  	(IO_LCDCE6.bit.SEG24)
#define	LCDCE6_SEG25  	(IO_LCDCE6.bit.SEG25)
#define	LCDCE6_SEG26  	(IO_LCDCE6.bit.SEG26)
#define	LCDCE6_SEG27  	(IO_LCDCE6.bit.SEG27)
#define	LCDCE6_SEG28  	(IO_LCDCE6.bit.SEG28)
#define	LCDCE6_SEG29  	(IO_LCDCE6.bit.SEG29)
#define	LCDCE6_SEG30  	(IO_LCDCE6.bit.SEG30)
#define	LCDCE6_SEG31  	(IO_LCDCE6.bit.SEG31)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_LCDCE7,   locate=0xFB8
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	SEG32:1;
			__BYTE	SEG33:1;
			__BYTE	SEG34:1;
			__BYTE	SEG35:1;
			__BYTE	SEG36:1;
			__BYTE	SEG37:1;
			__BYTE	SEG38:1;
			__BYTE	SEG39:1;
	} bit;
	struct {
			__BYTE	SEG32:1;
			__BYTE	SEG33:1;
			__BYTE	SEG34:1;
			__BYTE	SEG35:1;
			__BYTE	SEG36:1;
			__BYTE	SEG37:1;
			__BYTE	SEG38:1;
			__BYTE	SEG39:1;
	} bitc;
} LCDCE7STR;

__IO_EXTENDED	  LCDCE7STR	IO_LCDCE7;
#define	_lcdce7		(IO_LCDCE7)
#define	LCDCE7		(IO_LCDCE7.byte)
#define	LCDCE7_SEG32  	(IO_LCDCE7.bit.SEG32)
#define	LCDCE7_SEG33  	(IO_LCDCE7.bit.SEG33)
#define	LCDCE7_SEG34  	(IO_LCDCE7.bit.SEG34)
#define	LCDCE7_SEG35  	(IO_LCDCE7.bit.SEG35)
#define	LCDCE7_SEG36  	(IO_LCDCE7.bit.SEG36)
#define	LCDCE7_SEG37  	(IO_LCDCE7.bit.SEG37)
#define	LCDCE7_SEG38  	(IO_LCDCE7.bit.SEG38)
#define	LCDCE7_SEG39  	(IO_LCDCE7.bit.SEG39)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_LCDCB1,   locate=0xFB9
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	BLD0:1;
			__BYTE	BLD1:1;
			__BYTE	BLD2:1;
			__BYTE	BLD3:1;
			__BYTE	BLD4:1;
			__BYTE	BLD5:1;
			__BYTE	BLD6:1;
			__BYTE	BLD7:1;
	} bit;
	struct {
			__BYTE	BLD0:1;
			__BYTE	BLD1:1;
			__BYTE	BLD2:1;
			__BYTE	BLD3:1;
			__BYTE	BLD4:1;
			__BYTE	BLD5:1;
			__BYTE	BLD6:1;
			__BYTE	BLD7:1;
	} bitc;
} LCDCB1STR;

__IO_EXTENDED	  LCDCB1STR	IO_LCDCB1;
#define	_lcdcb1		(IO_LCDCB1)
#define	LCDCB1		(IO_LCDCB1.byte)
#define	LCDCB1_BLD0  	(IO_LCDCB1.bit.BLD0)
#define	LCDCB1_BLD1  	(IO_LCDCB1.bit.BLD1)
#define	LCDCB1_BLD2  	(IO_LCDCB1.bit.BLD2)
#define	LCDCB1_BLD3  	(IO_LCDCB1.bit.BLD3)
#define	LCDCB1_BLD4  	(IO_LCDCB1.bit.BLD4)
#define	LCDCB1_BLD5  	(IO_LCDCB1.bit.BLD5)
#define	LCDCB1_BLD6  	(IO_LCDCB1.bit.BLD6)
#define	LCDCB1_BLD7  	(IO_LCDCB1.bit.BLD7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_LCDCB2,   locate=0xFBA
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	BLD8:1;
			__BYTE	BLD9:1;
			__BYTE	BLD10:1;
			__BYTE	BLD11:1;
			__BYTE	BLD12:1;
			__BYTE	BLD13:1;
			__BYTE	BLD14:1;
			__BYTE	BLD15:1;
	} bit;
	struct {
			__BYTE	BLD8:1;
			__BYTE	BLD9:1;
			__BYTE	BLD10:1;
			__BYTE	BLD11:1;
			__BYTE	BLD12:1;
			__BYTE	BLD13:1;
			__BYTE	BLD14:1;
			__BYTE	BLD15:1;
	} bitc;
} LCDCB2STR;

__IO_EXTENDED	  LCDCB2STR	IO_LCDCB2;
#define	_lcdcb2		(IO_LCDCB2)
#define	LCDCB2		(IO_LCDCB2.byte)
#define	LCDCB2_BLD8  	(IO_LCDCB2.bit.BLD8)
#define	LCDCB2_BLD9  	(IO_LCDCB2.bit.BLD9)
#define	LCDCB2_BLD10  	(IO_LCDCB2.bit.BLD10)
#define	LCDCB2_BLD11  	(IO_LCDCB2.bit.BLD11)
#define	LCDCB2_BLD12  	(IO_LCDCB2.bit.BLD12)
#define	LCDCB2_BLD13  	(IO_LCDCB2.bit.BLD13)
#define	LCDCB2_BLD14  	(IO_LCDCB2.bit.BLD14)
#define	LCDCB2_BLD15  	(IO_LCDCB2.bit.BLD15)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_SEG_00,   locate=0xFBD
#endif

__IO_EXTENDED	__BYTE	IO_SEG_00;
#define	_seg_00		(IO_SEG_00)
#define	SEG_00	(_seg_00)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_SEG_01,   locate=0xFBE
#endif

__IO_EXTENDED	__BYTE	IO_SEG_01;
#define	_seg_01		(IO_SEG_01)
#define	SEG_01	(_seg_01)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_SEG_02,   locate=0xFBF
#endif

__IO_EXTENDED	__BYTE	IO_SEG_02;
#define	_seg_02		(IO_SEG_02)
#define	SEG_02	(_seg_02)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_SEG_03,   locate=0xFC0
#endif

__IO_EXTENDED	__BYTE	IO_SEG_03;
#define	_seg_03		(IO_SEG_03)
#define	SEG_03	(_seg_03)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_SEG_04,   locate=0xFC1
#endif

__IO_EXTENDED	__BYTE	IO_SEG_04;
#define	_seg_04		(IO_SEG_04)
#define	SEG_04	(_seg_04)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_SEG_05,   locate=0xFC2
#endif

__IO_EXTENDED	__BYTE	IO_SEG_05;
#define	_seg_05		(IO_SEG_05)
#define	SEG_05	(_seg_05)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_SEG_06,   locate=0xFC3
#endif

__IO_EXTENDED	__BYTE	IO_SEG_06;
#define	_seg_06		(IO_SEG_06)
#define	SEG_06	(_seg_06)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_SEG_07,   locate=0xFC4
#endif

__IO_EXTENDED	__BYTE	IO_SEG_07;
#define	_seg_07		(IO_SEG_07)
#define	SEG_07	(_seg_07)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_SEG_08,   locate=0xFC5
#endif

__IO_EXTENDED	__BYTE	IO_SEG_08;
#define	_seg_08		(IO_SEG_08)
#define	SEG_08	(_seg_08)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_SEG_09,   locate=0xFC6
#endif

__IO_EXTENDED	__BYTE	IO_SEG_09;
#define	_seg_09		(IO_SEG_09)
#define	SEG_09	(_seg_09)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_SEG_10,   locate=0xFC7
#endif

__IO_EXTENDED	__BYTE	IO_SEG_10;
#define	_seg_10		(IO_SEG_10)
#define	SEG_10	(_seg_10)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_SEG_11,   locate=0xFC8
#endif

__IO_EXTENDED	__BYTE	IO_SEG_11;
#define	_seg_11		(IO_SEG_11)
#define	SEG_11	(_seg_11)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_SEG_12,   locate=0xFC9
#endif

__IO_EXTENDED	__BYTE	IO_SEG_12;
#define	_seg_12		(IO_SEG_12)
#define	SEG_12	(_seg_12)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_SEG_13,   locate=0xFCA
#endif

__IO_EXTENDED	__BYTE	IO_SEG_13;
#define	_seg_13		(IO_SEG_13)
#define	SEG_13	(_seg_13)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_SEG_14,   locate=0xFCB
#endif

__IO_EXTENDED	__BYTE	IO_SEG_14;
#define	_seg_14		(IO_SEG_14)
#define	SEG_14	(_seg_14)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_SEG_15,   locate=0xFCC
#endif

__IO_EXTENDED	__BYTE	IO_SEG_15;
#define	_seg_15		(IO_SEG_15)
#define	SEG_15	(_seg_15)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_SEG_16,   locate=0xFCD
#endif

__IO_EXTENDED	__BYTE	IO_SEG_16;
#define	_seg_16		(IO_SEG_16)
#define	SEG_16	(_seg_16)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_SEG_17,   locate=0xFCE
#endif

__IO_EXTENDED	__BYTE	IO_SEG_17;
#define	_seg_17		(IO_SEG_17)
#define	SEG_17	(_seg_17)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_SEG_18,   locate=0xFCF
#endif

__IO_EXTENDED	__BYTE	IO_SEG_18;
#define	_seg_18		(IO_SEG_18)
#define	SEG_18	(_seg_18)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_SEG_19,   locate=0xFD0
#endif

__IO_EXTENDED	__BYTE	IO_SEG_19;
#define	_seg_19		(IO_SEG_19)
#define	SEG_19	(_seg_19)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_SEG_20,   locate=0xFD1
#endif

__IO_EXTENDED	__BYTE	IO_SEG_20;
#define	_seg_20		(IO_SEG_20)
#define	SEG_20	(_seg_20)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_SEG_21,   locate=0xFD2
#endif

__IO_EXTENDED	__BYTE	IO_SEG_21;
#define	_seg_21		(IO_SEG_21)
#define	SEG_21	(_seg_21)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_SEG_22,   locate=0xFD3
#endif

__IO_EXTENDED	__BYTE	IO_SEG_22;
#define	_seg_22		(IO_SEG_22)
#define	SEG_22	(_seg_22)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_SEG_23,   locate=0xFD4
#endif

__IO_EXTENDED	__BYTE	IO_SEG_23;
#define	_seg_23		(IO_SEG_23)
#define	SEG_23	(_seg_23)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_SEG_24,   locate=0xFD5
#endif

__IO_EXTENDED	__BYTE	IO_SEG_24;
#define	_seg_24		(IO_SEG_24)
#define	SEG_24	(_seg_24)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_SEG_25,   locate=0xFD6
#endif

__IO_EXTENDED	__BYTE	IO_SEG_25;
#define	_seg_25		(IO_SEG_25)
#define	SEG_25	(_seg_25)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_SEG_26,   locate=0xFD7
#endif

__IO_EXTENDED	__BYTE	IO_SEG_26;
#define	_seg_26		(IO_SEG_26)
#define	SEG_26	(_seg_26)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_SEG_27,   locate=0xFD8
#endif

__IO_EXTENDED	__BYTE	IO_SEG_27;
#define	_seg_27		(IO_SEG_27)
#define	SEG_27	(_seg_27)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_SEG_28,   locate=0xFD9
#endif

__IO_EXTENDED	__BYTE	IO_SEG_28;
#define	_seg_28		(IO_SEG_28)
#define	SEG_28	(_seg_28)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_SEG_29,   locate=0xFDA
#endif

__IO_EXTENDED	__BYTE	IO_SEG_29;
#define	_seg_29		(IO_SEG_29)
#define	SEG_29	(_seg_29)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_SEG_30,   locate=0xFDB
#endif

__IO_EXTENDED	__BYTE	IO_SEG_30;
#define	_seg_30		(IO_SEG_30)
#define	SEG_30	(_seg_30)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_SEG_31,   locate=0xFDC
#endif

__IO_EXTENDED	__BYTE	IO_SEG_31;
#define	_seg_31		(IO_SEG_31)
#define	SEG_31	(_seg_31)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_SEG_32,   locate=0xFDD
#endif

__IO_EXTENDED	__BYTE	IO_SEG_32;
#define	_seg_32		(IO_SEG_32)
#define	SEG_32	(_seg_32)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_SEG_33,   locate=0xFDE
#endif

__IO_EXTENDED	__BYTE	IO_SEG_33;
#define	_seg_33		(IO_SEG_33)
#define	SEG_33	(_seg_33)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_SEG_34,   locate=0xFDF
#endif

__IO_EXTENDED	__BYTE	IO_SEG_34;
#define	_seg_34		(IO_SEG_34)
#define	SEG_34	(_seg_34)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_SEG_35,   locate=0xFE0
#endif

__IO_EXTENDED	__BYTE	IO_SEG_35;
#define	_seg_35		(IO_SEG_35)
#define	SEG_35	(_seg_35)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_EVCR,   locate=0xFE2
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	MD:1;
			__BYTE	SEL0:1;
			__BYTE	SEL1:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	MD:1;
			__BYTE	SEL0:1;
			__BYTE	SEL1:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} EVCRSTR;

__IO_EXTENDED	  EVCRSTR	IO_EVCR;
#define	_evcr		(IO_EVCR)
#define	EVCR		(IO_EVCR.byte)
#define	EVCR_MD  	(IO_EVCR.bit.MD)
#define	EVCR_SEL0  	(IO_EVCR.bit.SEL0)
#define	EVCR_SEL1  	(IO_EVCR.bit.SEL1)

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
#pragma segment     DATA=IO_SYSC2,   locate=0xFE6
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	VBGRSELX:1;
			__BYTE	PLLSEL:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	VBGRSELX:1;
			__BYTE	PLLSEL:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} SYSC2STR;

__IO_EXTENDED	  SYSC2STR	IO_SYSC2;
#define	_sysc2		(IO_SYSC2)
#define	SYSC2		(IO_SYSC2.byte)
#define	SYSC2_VBGRSELX  	(IO_SYSC2.bit.VBGRSELX)
#define	SYSC2_PLLSEL  	(IO_SYSC2.bit.PLLSEL)

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
			__BYTE	PFSEL0:1;
			__BYTE	PFSEL1:1;
			__BYTE	PGSEL0:1;
			__BYTE	PGSEL1:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	RSTEN:1;
			__BYTE	RSTOE:1;
			__BYTE	PFSEL0:1;
			__BYTE	PFSEL1:1;
			__BYTE	PGSEL0:1;
			__BYTE	PGSEL1:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} SYSCSTR;

__IO_EXTENDED	  SYSCSTR	IO_SYSC;
#define	_sysc		(IO_SYSC)
#define	SYSC		(IO_SYSC.byte)
#define	SYSC_RSTEN  	(IO_SYSC.bit.RSTEN)
#define	SYSC_RSTOE  	(IO_SYSC.bit.RSTOE)
#define	SYSC_PFSEL0  	(IO_SYSC.bit.PFSEL0)
#define	SYSC_PFSEL1  	(IO_SYSC.bit.PFSEL1)
#define	SYSC_PGSEL0  	(IO_SYSC.bit.PGSEL0)
#define	SYSC_PGSEL1  	(IO_SYSC.bit.PGSEL1)

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
			__BYTE	UCK0:1;
			__BYTE	UI0:1;
			__BYTE	EC0:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	INT00:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	RESV0:1;
			__BYTE	UCK0:1;
			__BYTE	UI0:1;
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
#define	WICR_UCK0  	(IO_WICR.bit.UCK0)
#define	WICR_UI0  	(IO_WICR.bit.UI0)
#define	WICR_EC0  	(IO_WICR.bit.EC0)
#define	WICR_INT00  	(IO_WICR.bit.INT00)
