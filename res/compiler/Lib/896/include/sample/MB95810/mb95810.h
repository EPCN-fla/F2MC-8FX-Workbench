/*
 MB95810 Series I/O register declaration file V01L01
 ALL RIGHTS RESERVED, COPYRIGHT (C) FUJITSU SEMICONDUCTOR LIMITED 2011
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
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	P10:1;
			__BYTE	P11:1;
			__BYTE	P12:1;
			__BYTE	P13:1;
			__BYTE	P14:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
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
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	P10:1;
			__BYTE	P11:1;
			__BYTE	P12:1;
			__BYTE	P13:1;
			__BYTE	P14:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
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
			__BYTE	P24:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	P20:1;
			__BYTE	P21:1;
			__BYTE	P22:1;
			__BYTE	P23:1;
			__BYTE	P24:1;
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
#define	PDR2_P24  	(IO_PDR2.bit.P24)

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
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	P20:1;
			__BYTE	P21:1;
			__BYTE	P22:1;
			__BYTE	P23:1;
			__BYTE	P24:1;
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
#define	DDR2_P24  	(IO_DDR2.bit.P24)

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
#define	_pdr3		(IO_PDR3)
#define	PDR3		(IO_PDR3.byte)
#define	PDR3_P30  	(IO_PDR3.bit.P30)
#define	PDR3_P31  	(IO_PDR3.bit.P31)
#define	PDR3_P32  	(IO_PDR3.bit.P32)
#define	PDR3_P33  	(IO_PDR3.bit.P33)
#define	PDR3_P34  	(IO_PDR3.bit.P34)
#define	PDR3_P35  	(IO_PDR3.bit.P35)
#define	PDR3_P36  	(IO_PDR3.bit.P36)
#define	PDR3_P37  	(IO_PDR3.bit.P37)

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
#define	_ddr3		(IO_DDR3)
#define	DDR3		(IO_DDR3.byte)
#define	DDR3_P30  	(IO_DDR3.bit.P30)
#define	DDR3_P31  	(IO_DDR3.bit.P31)
#define	DDR3_P32  	(IO_DDR3.bit.P32)
#define	DDR3_P33  	(IO_DDR3.bit.P33)
#define	DDR3_P34  	(IO_DDR3.bit.P34)
#define	DDR3_P35  	(IO_DDR3.bit.P35)
#define	DDR3_P36  	(IO_DDR3.bit.P36)
#define	DDR3_P37  	(IO_DDR3.bit.P37)

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
#pragma segment IO=IO_PDR7, locate=0x18
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	P70:1;
			__BYTE	P71:1;
			__BYTE	P72:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	P70:1;
			__BYTE	P71:1;
			__BYTE	P72:1;
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
#define	PDR7_P72  	(IO_PDR7.bit.P72)

#ifdef __IO_DEFINE
#pragma segment IO=IO_DDR7, locate=0x19
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	P70:1;
			__BYTE	P71:1;
			__BYTE	P72:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	P70:1;
			__BYTE	P71:1;
			__BYTE	P72:1;
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
#define	DDR7_P72  	(IO_DDR7.bit.P72)

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
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	P80:1;
			__BYTE	P81:1;
			__BYTE	P82:1;
			__BYTE	P83:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} PDR8STR;

__IO_EXTERN	  PDR8STR	IO_PDR8;
#define	_pdr8		(IO_PDR8)
#define	PDR8		(IO_PDR8.byte)
#define	PDR8_P80  	(IO_PDR8.bit.P80)
#define	PDR8_P81  	(IO_PDR8.bit.P81)
#define	PDR8_P82  	(IO_PDR8.bit.P82)
#define	PDR8_P83  	(IO_PDR8.bit.P83)

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
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	P80:1;
			__BYTE	P81:1;
			__BYTE	P82:1;
			__BYTE	P83:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} DDR8STR;

__IO_EXTERN	  DDR8STR	IO_DDR8;
#define	_ddr8		(IO_DDR8)
#define	DDR8		(IO_DDR8.byte)
#define	DDR8_P80  	(IO_DDR8.bit.P80)
#define	DDR8_P81  	(IO_DDR8.bit.P81)
#define	DDR8_P82  	(IO_DDR8.bit.P82)
#define	DDR8_P83  	(IO_DDR8.bit.P83)

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
#pragma segment IO=IO_PUL8, locate=0x25
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	P80:1;
			__BYTE	P81:1;
			__BYTE	P82:1;
			__BYTE	P83:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	P80:1;
			__BYTE	P81:1;
			__BYTE	P82:1;
			__BYTE	P83:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} PUL8STR;

__IO_EXTERN	  PUL8STR	IO_PUL8;
#define	_pul8		(IO_PUL8)
#define	PUL8		(IO_PUL8.byte)
#define	PUL8_P80  	(IO_PUL8.bit.P80)
#define	PUL8_P81  	(IO_PUL8.bit.P81)
#define	PUL8_P82  	(IO_PUL8.bit.P82)
#define	PUL8_P83  	(IO_PUL8.bit.P83)

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
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	PE0:1;
			__BYTE	PE1:1;
			__BYTE	PE2:1;
			__BYTE	PE3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} PDRESTR;

__IO_EXTERN	  PDRESTR	IO_PDRE;
#define	_pdre		(IO_PDRE)
#define	PDRE		(IO_PDRE.byte)
#define	PDRE_PE0  	(IO_PDRE.bit.PE0)
#define	PDRE_PE1  	(IO_PDRE.bit.PE1)
#define	PDRE_PE2  	(IO_PDRE.bit.PE2)
#define	PDRE_PE3  	(IO_PDRE.bit.PE3)

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
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	PE0:1;
			__BYTE	PE1:1;
			__BYTE	PE2:1;
			__BYTE	PE3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} DDRESTR;

__IO_EXTERN	  DDRESTR	IO_DDRE;
#define	_ddre		(IO_DDRE)
#define	DDRE		(IO_DDRE.byte)
#define	DDRE_PE0  	(IO_DDRE.bit.PE0)
#define	DDRE_PE1  	(IO_DDRE.bit.PE1)
#define	DDRE_PE2  	(IO_DDRE.bit.PE2)
#define	DDRE_PE3  	(IO_DDRE.bit.PE3)

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
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	P10:1;
			__BYTE	P11:1;
			__BYTE	RESV2:1;
			__BYTE	P13:1;
			__BYTE	P14:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} PUL1STR;

__IO_EXTERN	  PUL1STR	IO_PUL1;
#define	_pul1		(IO_PUL1)
#define	PUL1		(IO_PUL1.byte)
#define	PUL1_P10  	(IO_PUL1.bit.P10)
#define	PUL1_P11  	(IO_PUL1.bit.P11)
#define	PUL1_P13  	(IO_PUL1.bit.P13)
#define	PUL1_P14  	(IO_PUL1.bit.P14)

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
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	P20:1;
			__BYTE	P21:1;
			__BYTE	P22:1;
			__BYTE	P23:1;
			__BYTE	P24:1;
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
#define	PUL2_P22  	(IO_PUL2.bit.P22)
#define	PUL2_P23  	(IO_PUL2.bit.P23)
#define	PUL2_P24  	(IO_PUL2.bit.P24)

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
#define	_pul3		(IO_PUL3)
#define	PUL3		(IO_PUL3.byte)
#define	PUL3_P30  	(IO_PUL3.bit.P30)
#define	PUL3_P31  	(IO_PUL3.bit.P31)
#define	PUL3_P32  	(IO_PUL3.bit.P32)
#define	PUL3_P33  	(IO_PUL3.bit.P33)
#define	PUL3_P34  	(IO_PUL3.bit.P34)
#define	PUL3_P35  	(IO_PUL3.bit.P35)
#define	PUL3_P36  	(IO_PUL3.bit.P36)
#define	PUL3_P37  	(IO_PUL3.bit.P37)

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
} PUL4STR;

__IO_EXTERN	  PUL4STR	IO_PUL4;
#define	_pul4		(IO_PUL4)
#define	PUL4		(IO_PUL4.byte)
#define	PUL4_P40  	(IO_PUL4.bit.P40)
#define	PUL4_P41  	(IO_PUL4.bit.P41)
#define	PUL4_P42  	(IO_PUL4.bit.P42)
#define	PUL4_P43  	(IO_PUL4.bit.P43)

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
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	RESV0:1;
			__BYTE	RESV1:1;
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
#define	PUL5_P52  	(IO_PUL5.bit.P52)
#define	PUL5_P53  	(IO_PUL5.bit.P53)

#ifdef __IO_DEFINE
#pragma segment IO=IO_PUL7, locate=0x32
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	P70:1;
			__BYTE	P71:1;
			__BYTE	P72:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	P70:1;
			__BYTE	P71:1;
			__BYTE	P72:1;
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
#define	PUL7_P72  	(IO_PUL7.bit.P72)

#ifdef __IO_DEFINE
#pragma segment IO=IO_PUL6, locate=0x33
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
} PUL6STR;

__IO_EXTERN	  PUL6STR	IO_PUL6;
#define	_pul6		(IO_PUL6)
#define	PUL6		(IO_PUL6.byte)
#define	PUL6_P60  	(IO_PUL6.bit.P60)
#define	PUL6_P61  	(IO_PUL6.bit.P61)
#define	PUL6_P62  	(IO_PUL6.bit.P62)
#define	PUL6_P63  	(IO_PUL6.bit.P63)
#define	PUL6_P64  	(IO_PUL6.bit.P64)
#define	PUL6_P65  	(IO_PUL6.bit.P65)
#define	PUL6_P66  	(IO_PUL6.bit.P66)
#define	PUL6_P67  	(IO_PUL6.bit.P67)

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
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	PE0:1;
			__BYTE	PE1:1;
			__BYTE	PE2:1;
			__BYTE	PE3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} PULESTR;

__IO_EXTERN	  PULESTR	IO_PULE;
#define	_pule		(IO_PULE)
#define	PULE		(IO_PULE.byte)
#define	PULE_PE0  	(IO_PULE.bit.PE0)
#define	PULE_PE1  	(IO_PULE.bit.PE1)
#define	PULE_PE2  	(IO_PULE.bit.PE2)
#define	PULE_PE3  	(IO_PULE.bit.PE3)

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
#define	_tmcsrh0		(IO_TMCSRH0)
#define	TMCSRH0		(IO_TMCSRH0.byte)
#define	TMCSRH0_MOD0  	(IO_TMCSRH0.bit.MOD0)
#define	TMCSRH0_MOD1  	(IO_TMCSRH0.bit.MOD1)
#define	TMCSRH0_MOD2  	(IO_TMCSRH0.bit.MOD2)
#define	TMCSRH0_CSL0  	(IO_TMCSRH0.bit.CSL0)
#define	TMCSRH0_CSL1  	(IO_TMCSRH0.bit.CSL1)
#define	TMCSRH0_CSL2  	(IO_TMCSRH0.bit.CSL2)

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
#define	_tmcsrl0		(IO_TMCSRL0)
#define	TMCSRL0		(IO_TMCSRL0.byte)
#define	TMCSRL0_TRG  	(IO_TMCSRL0.bit.TRG)
#define	TMCSRL0_CNTE  	(IO_TMCSRL0.bit.CNTE)
#define	TMCSRL0_UF  	(IO_TMCSRL0.bit.UF)
#define	TMCSRL0_INTE  	(IO_TMCSRL0.bit.INTE)
#define	TMCSRL0_RELD  	(IO_TMCSRL0.bit.RELD)
#define	TMCSRL0_OUTL  	(IO_TMCSRL0.bit.OUTL)
#define	TMCSRL0_OUTE  	(IO_TMCSRL0.bit.OUTE)

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
			__BYTE	STRG:1;
			__BYTE	CNTE:1;
	} bit;
	struct {
			__BYTE	PGMS:1;
			__BYTE	CKS0:1;
			__BYTE	CKS1:1;
			__BYTE	CKS2:1;
			__BYTE	RTRG:1;
			__BYTE	MDSE:1;
			__BYTE	STRG:1;
			__BYTE	CNTE:1;
	} bitc;
} PCNTH0STR;

__IO_EXTERN	  PCNTH0STR	IO_PCNTH0;
#define	_pcnth0		(IO_PCNTH0)
#define	PCNTH0		(IO_PCNTH0.byte)
#define	PCNTH0_PGMS  	(IO_PCNTH0.bit.PGMS)
#define	PCNTH0_CKS0  	(IO_PCNTH0.bit.CKS0)
#define	PCNTH0_CKS1  	(IO_PCNTH0.bit.CKS1)
#define	PCNTH0_CKS2  	(IO_PCNTH0.bit.CKS2)
#define	PCNTH0_RTRG  	(IO_PCNTH0.bit.RTRG)
#define	PCNTH0_MDSE  	(IO_PCNTH0.bit.MDSE)
#define	PCNTH0_STRG  	(IO_PCNTH0.bit.STRG)
#define	PCNTH0_CNTE  	(IO_PCNTH0.bit.CNTE)

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
#define	_pcntl0		(IO_PCNTL0)
#define	PCNTL0		(IO_PCNTL0.byte)
#define	PCNTL0_OSEL  	(IO_PCNTL0.bit.OSEL)
#define	PCNTL0_POEN  	(IO_PCNTL0.bit.POEN)
#define	PCNTL0_IRS0  	(IO_PCNTL0.bit.IRS0)
#define	PCNTL0_IRS1  	(IO_PCNTL0.bit.IRS1)
#define	PCNTL0_IRQF  	(IO_PCNTL0.bit.IRQF)
#define	PCNTL0_IREN  	(IO_PCNTL0.bit.IREN)
#define	PCNTL0_EGS0  	(IO_PCNTL0.bit.EGS0)
#define	PCNTL0_EGS1  	(IO_PCNTL0.bit.EGS1)

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
			__BYTE	STRG:1;
			__BYTE	CNTE:1;
	} bit;
	struct {
			__BYTE	PGMS:1;
			__BYTE	CKS0:1;
			__BYTE	CKS1:1;
			__BYTE	CKS2:1;
			__BYTE	RTRG:1;
			__BYTE	MDSE:1;
			__BYTE	STRG:1;
			__BYTE	CNTE:1;
	} bitc;
} PCNTH1STR;

__IO_EXTERN	  PCNTH1STR	IO_PCNTH1;
#define	_pcnth1		(IO_PCNTH1)
#define	PCNTH1		(IO_PCNTH1.byte)
#define	PCNTH1_PGMS  	(IO_PCNTH1.bit.PGMS)
#define	PCNTH1_CKS0  	(IO_PCNTH1.bit.CKS0)
#define	PCNTH1_CKS1  	(IO_PCNTH1.bit.CKS1)
#define	PCNTH1_CKS2  	(IO_PCNTH1.bit.CKS2)
#define	PCNTH1_RTRG  	(IO_PCNTH1.bit.RTRG)
#define	PCNTH1_MDSE  	(IO_PCNTH1.bit.MDSE)
#define	PCNTH1_STRG  	(IO_PCNTH1.bit.STRG)
#define	PCNTH1_CNTE  	(IO_PCNTH1.bit.CNTE)

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
#define	_pcntl1		(IO_PCNTL1)
#define	PCNTL1		(IO_PCNTL1.byte)
#define	PCNTL1_OSEL  	(IO_PCNTL1.bit.OSEL)
#define	PCNTL1_POEN  	(IO_PCNTL1.bit.POEN)
#define	PCNTL1_IRS0  	(IO_PCNTL1.bit.IRS0)
#define	PCNTL1_IRS1  	(IO_PCNTL1.bit.IRS1)
#define	PCNTL1_IRQF  	(IO_PCNTL1.bit.IRQF)
#define	PCNTL1_IREN  	(IO_PCNTL1.bit.IREN)
#define	PCNTL1_EGS0  	(IO_PCNTL1.bit.EGS0)
#define	PCNTL1_EGS1  	(IO_PCNTL1.bit.EGS1)

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
#define	_eic01		(IO_EIC01)
#define	EIC01		(IO_EIC01.byte)
#define	EIC01_EIE0  	(IO_EIC01.bit.EIE0)
#define	EIC01_SL00  	(IO_EIC01.bit.SL00)
#define	EIC01_SL01  	(IO_EIC01.bit.SL01)
#define	EIC01_EIR0  	(IO_EIC01.bit.EIR0)
#define	EIC01_EIE1  	(IO_EIC01.bit.EIE1)
#define	EIC01_SL10  	(IO_EIC01.bit.SL10)
#define	EIC01_SL11  	(IO_EIC01.bit.SL11)
#define	EIC01_EIR1  	(IO_EIC01.bit.EIR1)

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
#define	_eic11		(IO_EIC11)
#define	EIC11		(IO_EIC11.byte)
#define	EIC11_EIE0  	(IO_EIC11.bit.EIE0)
#define	EIC11_SL00  	(IO_EIC11.bit.SL00)
#define	EIC11_SL01  	(IO_EIC11.bit.SL01)
#define	EIC11_EIR0  	(IO_EIC11.bit.EIR0)
#define	EIC11_EIE1  	(IO_EIC11.bit.EIE1)
#define	EIC11_SL10  	(IO_EIC11.bit.SL10)
#define	EIC11_SL11  	(IO_EIC11.bit.SL11)
#define	EIC11_EIR1  	(IO_EIC11.bit.EIR1)

#ifdef __IO_DEFINE
#pragma segment IO=IO_LVDR, locate=0x4E
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	LVRS0:1;
			__BYTE	LVRS1:1;
			__BYTE	LVRS2:1;
			__BYTE	LVRS3:1;
			__BYTE	LVRS4:1;
			__BYTE	LVRS5:1;
			__BYTE	LVRS6:1;
			__BYTE	LVRS7:1;
	} bit;
	struct {
			__BYTE	LVRS0:1;
			__BYTE	LVRS1:1;
			__BYTE	LVRS2:1;
			__BYTE	LVRS3:1;
			__BYTE	LVRS4:1;
			__BYTE	LVRS5:1;
			__BYTE	LVRS6:1;
			__BYTE	LVRS7:1;
	} bitc;
} LVDRSTR;

__IO_EXTERN	  LVDRSTR	IO_LVDR;
#define	_lvdr		(IO_LVDR)
#define	LVDR		(IO_LVDR.byte)
#define	LVDR_LVRS0  	(IO_LVDR.bit.LVRS0)
#define	LVDR_LVRS1  	(IO_LVDR.bit.LVRS1)
#define	LVDR_LVRS2  	(IO_LVDR.bit.LVRS2)
#define	LVDR_LVRS3  	(IO_LVDR.bit.LVRS3)
#define	LVDR_LVRS4  	(IO_LVDR.bit.LVRS4)
#define	LVDR_LVRS5  	(IO_LVDR.bit.LVRS5)
#define	LVDR_LVRS6  	(IO_LVDR.bit.LVRS6)
#define	LVDR_LVRS7  	(IO_LVDR.bit.LVRS7)

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
#define	_scr		(IO_SCR)
#define	SCR		(IO_SCR.byte)
#define	SCR_TXE  	(IO_SCR.bit.TXE)
#define	SCR_RXE  	(IO_SCR.bit.RXE)
#define	SCR_CRE  	(IO_SCR.bit.CRE)
#define	SCR_AD  	(IO_SCR.bit.AD)
#define	SCR_CL  	(IO_SCR.bit.CL)
#define	SCR_SBL  	(IO_SCR.bit.SBL)
#define	SCR_P  	(IO_SCR.bit.P)
#define	SCR_PEN  	(IO_SCR.bit.PEN)

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
#define	_smr		(IO_SMR)
#define	SMR		(IO_SMR.byte)
#define	SMR_SOE  	(IO_SMR.bit.SOE)
#define	SMR_SCKE  	(IO_SMR.bit.SCKE)
#define	SMR_UPCL  	(IO_SMR.bit.UPCL)
#define	SMR_REST  	(IO_SMR.bit.REST)
#define	SMR_EXT  	(IO_SMR.bit.EXT)
#define	SMR_OTO  	(IO_SMR.bit.OTO)
#define	SMR_MD0  	(IO_SMR.bit.MD0)
#define	SMR_MD1  	(IO_SMR.bit.MD1)

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
#define	_ssr		(IO_SSR)
#define	SSR		(IO_SSR.byte)
#define	SSR_TIE  	(IO_SSR.bit.TIE)
#define	SSR_RIE  	(IO_SSR.bit.RIE)
#define	SSR_BDS  	(IO_SSR.bit.BDS)
#define	SSR_TDRE  	(IO_SSR.bit.TDRE)
#define	SSR_RDRF  	(IO_SSR.bit.RDRF)
#define	SSR_FRE  	(IO_SSR.bit.FRE)
#define	SSR_ORE  	(IO_SSR.bit.ORE)
#define	SSR_PE  	(IO_SSR.bit.PE)

#ifdef __IO_DEFINE
#pragma segment IO=IO_RDR_TDR, locate=0x53
#endif

__IO_EXTERN	__BYTE	IO_RDR_TDR;
#define	_rdr_tdr		(IO_RDR_TDR)
#define	RDR_TDR	(_rdr_tdr)

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
#define	_escr		(IO_ESCR)
#define	ESCR		(IO_ESCR.byte)
#define	ESCR_SCES  	(IO_ESCR.bit.SCES)
#define	ESCR_CCO  	(IO_ESCR.bit.CCO)
#define	ESCR_SIOP  	(IO_ESCR.bit.SIOP)
#define	ESCR_SOPE  	(IO_ESCR.bit.SOPE)
#define	ESCR_LBL0  	(IO_ESCR.bit.LBL0)
#define	ESCR_LBL1  	(IO_ESCR.bit.LBL1)
#define	ESCR_LBD  	(IO_ESCR.bit.LBD)
#define	ESCR_LBIE  	(IO_ESCR.bit.LBIE)

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
#define	_eccr		(IO_ECCR)
#define	ECCR		(IO_ECCR.byte)
#define	ECCR_TBI  	(IO_ECCR.bit.TBI)
#define	ECCR_RBI  	(IO_ECCR.bit.RBI)
#define	ECCR_SSM  	(IO_ECCR.bit.SSM)
#define	ECCR_SCDE  	(IO_ECCR.bit.SCDE)
#define	ECCR_MS  	(IO_ECCR.bit.MS)
#define	ECCR_LBR  	(IO_ECCR.bit.LBR)

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
#pragma segment IO=IO_CMR1, locate=0x5C
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
} CMR1STR;

__IO_EXTERN	  CMR1STR	IO_CMR1;
#define	_cmr1		(IO_CMR1)
#define	CMR1		(IO_CMR1.byte)
#define	CMR1_PD  	(IO_CMR1.bit.PD)
#define	CMR1_VCOE  	(IO_CMR1.bit.VCOE)
#define	CMR1_VCID  	(IO_CMR1.bit.VCID)
#define	CMR1_IE  	(IO_CMR1.bit.IE)
#define	CMR1_IF  	(IO_CMR1.bit.IF)
#define	CMR1_OS  	(IO_CMR1.bit.OS)
#define	CMR1_BGRS  	(IO_CMR1.bit.BGRS)
#define	CMR1_BGRPD  	(IO_CMR1.bit.BGRPD)

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
#pragma segment     DATA=IO_PDCR0,   locate=0xFAA
#endif

__IO_EXTENDED	const __WORD	IO_PDCR0;
#define	_pdcr0		(IO_PDCR0)
#define	PDCR0	(_pdcr0)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_PCSR0,   locate=0xFAC
#endif

__IO_EXTENDED	__WORD	IO_PCSR0;
#define	_pcsr0		(IO_PCSR0)
#define	PCSR0	(_pcsr0)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_PDUT0,   locate=0xFAE
#endif

__IO_EXTENDED	__WORD	IO_PDUT0;
#define	_pdut0		(IO_PDUT0)
#define	PDUT0	(_pdut0)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_PDCR1,   locate=0xFB0
#endif

__IO_EXTENDED	const __WORD	IO_PDCR1;
#define	_pdcr1		(IO_PDCR1)
#define	PDCR1	(_pdcr1)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_PCSR1,   locate=0xFB2
#endif

__IO_EXTENDED	__WORD	IO_PCSR1;
#define	_pcsr1		(IO_PCSR1)
#define	PCSR1	(_pcsr1)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_PDUT1,   locate=0xFB4
#endif

__IO_EXTENDED	__WORD	IO_PDUT1;
#define	_pdut1		(IO_PDUT1)
#define	PDUT1	(_pdut1)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_BGR1,   locate=0xFBC
#endif

__IO_EXTENDED	__BYTE	IO_BGR1;
#define	_bgr1		(IO_BGR1)
#define	BGR1	(_bgr1)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_BGR0,   locate=0xFBD
#endif

__IO_EXTENDED	__BYTE	IO_BGR0;
#define	_bgr0		(IO_BGR0)
#define	BGR0	(_bgr0)

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
#pragma segment     DATA=IO_AIDRH,   locate=0xFC2
#endif

__IO_EXTENDED	__BYTE	IO_AIDRH;
#define	_aidrh		(IO_AIDRH)
#define	AIDRH	(_aidrh)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_AIDRL,   locate=0xFC3
#endif

__IO_EXTENDED	__BYTE	IO_AIDRL;
#define	_aidrl		(IO_AIDRL)
#define	AIDRL	(_aidrl)

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
			__BYTE	ADTGSEL:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	PFSEL:1;
			__BYTE	PGSEL:1;
	} bit;
	struct {
			__BYTE	RSTEN:1;
			__BYTE	RSTOE:1;
			__BYTE	ADTGSEL:1;
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
#define	SYSC_ADTGSEL  	(IO_SYSC.bit.ADTGSEL)
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

__IO_EXTENDED	__BYTE	IO_WDTH;
#define	_wdth		(IO_WDTH)
#define	WDTH	(_wdth)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_WDTL,   locate=0xFEC
#endif

__IO_EXTENDED	__BYTE	IO_WDTL;
#define	_wdtl		(IO_WDTL)
#define	WDTL	(_wdtl)

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
			__BYTE	SIN:1;
			__BYTE	INT00:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	TRG0:1;
			__BYTE	UCK0:1;
			__BYTE	UI0:1;
			__BYTE	EC0:1;
			__BYTE	SCK:1;
			__BYTE	SIN:1;
			__BYTE	INT00:1;
			__BYTE	RESV7:1;
	} bitc;
} WICRSTR;

__IO_EXTENDED	  WICRSTR	IO_WICR;
#define	_wicr		(IO_WICR)
#define	WICR		(IO_WICR.byte)
#define	WICR_TRG0  	(IO_WICR.bit.TRG0)
#define	WICR_UCK0  	(IO_WICR.bit.UCK0)
#define	WICR_UI0  	(IO_WICR.bit.UI0)
#define	WICR_EC0  	(IO_WICR.bit.EC0)
#define	WICR_SCK  	(IO_WICR.bit.SCK)
#define	WICR_SIN  	(IO_WICR.bit.SIN)
#define	WICR_INT00  	(IO_WICR.bit.INT00)
