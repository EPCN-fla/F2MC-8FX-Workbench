/*
 MB89930A Series I/O register declaration file V01L01
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

__IO_EXTERN	__BYTE	IO_DDR0;
#define	_ddr0		(IO_DDR0)
#define	DDR0	(_ddr0)

#ifdef __IO_DEFINE
#pragma segment IO=IO_SYCC, locate=0x7
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	CS:2;
			__BYTE	RESV1:1;
			__BYTE	WT:2;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
	} bit;
	struct {
			__BYTE	CS0:1;
			__BYTE	CS1:1;
			__BYTE	RESV2:1;
			__BYTE	WT0:1;
			__BYTE	WT1:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} SYCCSTR;

__IO_EXTERN	  SYCCSTR	IO_SYCC;
#define	_sycc		(IO_SYCC)
#define	SYCC		(IO_SYCC.byte)
#define	SYCC_CS  	(IO_SYCC.bit.CS)
#define	SYCC_CS0  	(IO_SYCC.bitc.CS0)
#define	SYCC_CS1  	(IO_SYCC.bitc.CS1)
#define	SYCC_WT  	(IO_SYCC.bit.WT)
#define	SYCC_WT0  	(IO_SYCC.bitc.WT0)
#define	SYCC_WT1  	(IO_SYCC.bitc.WT1)

#ifdef __IO_DEFINE
#pragma segment IO=IO_STBC, locate=0x8
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	RESV0:1;
			__BYTE	RESV1:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	RST:1;
			__BYTE	SPL:1;
			__BYTE	SLP:1;
			__BYTE	STP:1;
	} bit;
	struct {
			__BYTE	RESV0:1;
			__BYTE	RESV1:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	RST:1;
			__BYTE	SPL:1;
			__BYTE	SLP:1;
			__BYTE	STP:1;
	} bitc;
} STBCSTR;

__IO_EXTERN	  STBCSTR	IO_STBC;
#define	_stbc		(IO_STBC)
#define	STBC		(IO_STBC.byte)
#define	STBC_RST  	(IO_STBC.bit.RST)
#define	STBC_SPL  	(IO_STBC.bit.SPL)
#define	STBC_SLP  	(IO_STBC.bit.SLP)
#define	STBC_STP  	(IO_STBC.bit.STP)

#ifdef __IO_DEFINE
#pragma segment IO=IO_WDTC, locate=0x9
#endif

__IO_EXTERN	__BYTE	IO_WDTC;
#define	_wdtc		(IO_WDTC)
#define	WDTC	(_wdtc)

#ifdef __IO_DEFINE
#pragma segment IO=IO_TBTC, locate=0xA
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	TBR:1;
			__BYTE	TBC:2;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	TBIE:1;
			__BYTE	TBOF:1;
	} bit;
	struct {
			__BYTE	TBR:1;
			__BYTE	TBC0:1;
			__BYTE	TBC1:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	TBIE:1;
			__BYTE	TBOF:1;
	} bitc;
} TBTCSTR;

__IO_EXTERN	  TBTCSTR	IO_TBTC;
#define	_tbtc		(IO_TBTC)
#define	TBTC		(IO_TBTC.byte)
#define	TBTC_TBR  	(IO_TBTC.bit.TBR)
#define	TBTC_TBC  	(IO_TBTC.bit.TBC)
#define	TBTC_TBC0  	(IO_TBTC.bitc.TBC0)
#define	TBTC_TBC1  	(IO_TBTC.bitc.TBC1)
#define	TBTC_TBIE  	(IO_TBTC.bit.TBIE)
#define	TBTC_TBOF  	(IO_TBTC.bit.TBOF)

#ifdef __IO_DEFINE
#pragma segment IO=IO_PDR3, locate=0xC
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
#pragma segment IO=IO_DDR3, locate=0xD
#endif

__IO_EXTERN	__BYTE	IO_DDR3;
#define	_ddr3		(IO_DDR3)
#define	DDR3	(_ddr3)

#ifdef __IO_DEFINE
#pragma segment IO=IO_RSFR, locate=0xE
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	RESV0:1;
			__BYTE	RESV1:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	SFTR:1;
			__BYTE	WDOG:1;
			__BYTE	ERST:1;
			__BYTE	PONR:1;
	} bit;
	struct {
			__BYTE	RESV0:1;
			__BYTE	RESV1:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	SFTR:1;
			__BYTE	WDOG:1;
			__BYTE	ERST:1;
			__BYTE	PONR:1;
	} bitc;
} RSFRSTR;

__IO_EXTERN	 const  RSFRSTR	IO_RSFR;
#define	_rsfr		(IO_RSFR)
#define	RSFR		(IO_RSFR.byte)
#define	RSFR_SFTR  	(IO_RSFR.bit.SFTR)
#define	RSFR_WDOG  	(IO_RSFR.bit.WDOG)
#define	RSFR_ERST  	(IO_RSFR.bit.ERST)
#define	RSFR_PONR  	(IO_RSFR.bit.PONR)

#ifdef __IO_DEFINE
#pragma segment IO=IO_PDR4, locate=0xF
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
#pragma segment IO=IO_DDR4, locate=0x10
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
#pragma segment IO=IO_OUT4, locate=0x11
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
} OUT4STR;

__IO_EXTERN	  OUT4STR	IO_OUT4;
#define	_out4		(IO_OUT4)
#define	OUT4		(IO_OUT4.byte)
#define	OUT4_P40  	(IO_OUT4.bit.P40)
#define	OUT4_P41  	(IO_OUT4.bit.P41)
#define	OUT4_P42  	(IO_OUT4.bit.P42)
#define	OUT4_P43  	(IO_OUT4.bit.P43)

#ifdef __IO_DEFINE
#pragma segment IO=IO_PDR5, locate=0x12
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	P50:1;
			__BYTE	RESV1:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	P50:1;
			__BYTE	RESV1:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
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

#ifdef __IO_DEFINE
#pragma segment IO=IO_DDR5, locate=0x13
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	P50:1;
			__BYTE	RESV1:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	P50:1;
			__BYTE	RESV1:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
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

#ifdef __IO_DEFINE
#pragma segment IO=IO_RCR21, locate=0x14
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	HSC:6;
			__BYTE	RCK:2;
	} bit;
	struct {
			__BYTE	HSC0:1;
			__BYTE	HSC1:1;
			__BYTE	HSC2:1;
			__BYTE	HSC3:1;
			__BYTE	HSC4:1;
			__BYTE	HSC5:1;
			__BYTE	RCK0:1;
			__BYTE	RCK1:1;
	} bitc;
} RCR21STR;

__IO_EXTERN	  RCR21STR	IO_RCR21;
#define	_rcr21		(IO_RCR21)
#define	RCR21		(IO_RCR21.byte)
#define	RCR21_HSC  	(IO_RCR21.bit.HSC)
#define	RCR21_HSC0  	(IO_RCR21.bitc.HSC0)
#define	RCR21_HSC1  	(IO_RCR21.bitc.HSC1)
#define	RCR21_HSC2  	(IO_RCR21.bitc.HSC2)
#define	RCR21_HSC3  	(IO_RCR21.bitc.HSC3)
#define	RCR21_HSC4  	(IO_RCR21.bitc.HSC4)
#define	RCR21_HSC5  	(IO_RCR21.bitc.HSC5)
#define	RCR21_RCK  	(IO_RCR21.bit.RCK)
#define	RCR21_RCK0  	(IO_RCR21.bitc.RCK0)
#define	RCR21_RCK1  	(IO_RCR21.bitc.RCK1)

#ifdef __IO_DEFINE
#pragma segment IO=IO_RCR22, locate=0x15
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	HSC:6;
			__BYTE	RESV1:1;
			__BYTE	RESV2:1;
	} bit;
	struct {
			__BYTE	HSC6:1;
			__BYTE	HSC7:1;
			__BYTE	HSC8:1;
			__BYTE	HSC9:1;
			__BYTE	HSC10:1;
			__BYTE	HSC11:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} RCR22STR;

__IO_EXTERN	  RCR22STR	IO_RCR22;
#define	_rcr22		(IO_RCR22)
#define	RCR22		(IO_RCR22.byte)
#define	RCR22_HSC  	(IO_RCR22.bit.HSC)
#define	RCR22_HSC6  	(IO_RCR22.bitc.HSC6)
#define	RCR22_HSC7  	(IO_RCR22.bitc.HSC7)
#define	RCR22_HSC8  	(IO_RCR22.bitc.HSC8)
#define	RCR22_HSC9  	(IO_RCR22.bitc.HSC9)
#define	RCR22_HSC10  	(IO_RCR22.bitc.HSC10)
#define	RCR22_HSC11  	(IO_RCR22.bitc.HSC11)

#ifdef __IO_DEFINE
#pragma segment IO=IO_RCR23, locate=0x16
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	SCL:6;
			__BYTE	RESV1:1;
			__BYTE	RCEN:1;
	} bit;
	struct {
			__BYTE	SCL0:1;
			__BYTE	SCL1:1;
			__BYTE	SCL2:1;
			__BYTE	SCL3:1;
			__BYTE	SCL4:1;
			__BYTE	SCL5:1;
			__BYTE	RESV6:1;
			__BYTE	RCEN:1;
	} bitc;
} RCR23STR;

__IO_EXTERN	  RCR23STR	IO_RCR23;
#define	_rcr23		(IO_RCR23)
#define	RCR23		(IO_RCR23.byte)
#define	RCR23_SCL  	(IO_RCR23.bit.SCL)
#define	RCR23_SCL0  	(IO_RCR23.bitc.SCL0)
#define	RCR23_SCL1  	(IO_RCR23.bitc.SCL1)
#define	RCR23_SCL2  	(IO_RCR23.bitc.SCL2)
#define	RCR23_SCL3  	(IO_RCR23.bitc.SCL3)
#define	RCR23_SCL4  	(IO_RCR23.bitc.SCL4)
#define	RCR23_SCL5  	(IO_RCR23.bitc.SCL5)
#define	RCR23_RCEN  	(IO_RCR23.bit.RCEN)

#ifdef __IO_DEFINE
#pragma segment IO=IO_RCR24, locate=0x17
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	SCL:6;
			__BYTE	RESV1:1;
			__BYTE	RESV2:1;
	} bit;
	struct {
			__BYTE	SCL6:1;
			__BYTE	SCL7:1;
			__BYTE	SCL8:1;
			__BYTE	SCL9:1;
			__BYTE	SCL10:1;
			__BYTE	SCL11:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} RCR24STR;

__IO_EXTERN	  RCR24STR	IO_RCR24;
#define	_rcr24		(IO_RCR24)
#define	RCR24		(IO_RCR24.byte)
#define	RCR24_SCL  	(IO_RCR24.bit.SCL)
#define	RCR24_SCL6  	(IO_RCR24.bitc.SCL6)
#define	RCR24_SCL7  	(IO_RCR24.bitc.SCL7)
#define	RCR24_SCL8  	(IO_RCR24.bitc.SCL8)
#define	RCR24_SCL9  	(IO_RCR24.bitc.SCL9)
#define	RCR24_SCL10  	(IO_RCR24.bitc.SCL10)
#define	RCR24_SCL11  	(IO_RCR24.bitc.SCL11)

#ifdef __IO_DEFINE
#pragma segment IO=IO_BZCR, locate=0x18
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	BZ:3;
			__BYTE	RESV1:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
	} bit;
	struct {
			__BYTE	BZ0:1;
			__BYTE	BZ1:1;
			__BYTE	BZ2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} BZCRSTR;

__IO_EXTERN	  BZCRSTR	IO_BZCR;
#define	_bzcr		(IO_BZCR)
#define	BZCR		(IO_BZCR.byte)
#define	BZCR_BZ  	(IO_BZCR.bit.BZ)
#define	BZCR_BZ0  	(IO_BZCR.bitc.BZ0)
#define	BZCR_BZ1  	(IO_BZCR.bitc.BZ1)
#define	BZCR_BZ2  	(IO_BZCR.bitc.BZ2)

#ifdef __IO_DEFINE
#pragma segment IO=IO_TCCR, locate=0x19
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	RESV0:1;
			__BYTE	EDGS:2;
			__BYTE	TCMSK:1;
			__BYTE	CCMSK:1;
			__BYTE	CPIEN:1;
			__BYTE	CFCLR:1;
			__BYTE	CPIF:1;
	} bit;
	struct {
			__BYTE	RESV0:1;
			__BYTE	EDGS0:1;
			__BYTE	EDGS1:1;
			__BYTE	TCMSK:1;
			__BYTE	CCMSK:1;
			__BYTE	CPIEN:1;
			__BYTE	CFCLR:1;
			__BYTE	CPIF:1;
	} bitc;
} TCCRSTR;

__IO_EXTERN	  TCCRSTR	IO_TCCR;
#define	_tccr		(IO_TCCR)
#define	TCCR		(IO_TCCR.byte)
#define	TCCR_EDGS  	(IO_TCCR.bit.EDGS)
#define	TCCR_EDGS0  	(IO_TCCR.bitc.EDGS0)
#define	TCCR_EDGS1  	(IO_TCCR.bitc.EDGS1)
#define	TCCR_TCMSK  	(IO_TCCR.bit.TCMSK)
#define	TCCR_CCMSK  	(IO_TCCR.bit.CCMSK)
#define	TCCR_CPIEN  	(IO_TCCR.bit.CPIEN)
#define	TCCR_CFCLR  	(IO_TCCR.bit.CFCLR)
#define	TCCR_CPIF  	(IO_TCCR.bit.CPIF)

#ifdef __IO_DEFINE
#pragma segment IO=IO_TCR1, locate=0x1A
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	TSTR1:1;
			__BYTE	TCS1:3;
			__BYTE	RESV2:1;
			__BYTE	T1IEN:1;
			__BYTE	TFCR1:1;
			__BYTE	TIF1:1;
	} bit;
	struct {
			__BYTE	TSTR1:1;
			__BYTE	TCS10:1;
			__BYTE	TCS11:1;
			__BYTE	TCS12:1;
			__BYTE	RESV4:1;
			__BYTE	T1IEN:1;
			__BYTE	TFCR1:1;
			__BYTE	TIF1:1;
	} bitc;
} TCR1STR;

__IO_EXTERN	  TCR1STR	IO_TCR1;
#define	_tcr1		(IO_TCR1)
#define	TCR1		(IO_TCR1.byte)
#define	TCR1_TSTR1  	(IO_TCR1.bit.TSTR1)
#define	TCR1_TCS1  	(IO_TCR1.bit.TCS1)
#define	TCR1_TCS10  	(IO_TCR1.bitc.TCS10)
#define	TCR1_TCS11  	(IO_TCR1.bitc.TCS11)
#define	TCR1_TCS12  	(IO_TCR1.bitc.TCS12)
#define	TCR1_T1IEN  	(IO_TCR1.bit.T1IEN)
#define	TCR1_TFCR1  	(IO_TCR1.bit.TFCR1)
#define	TCR1_TIF1  	(IO_TCR1.bit.TIF1)

#ifdef __IO_DEFINE
#pragma segment IO=IO_TCR0, locate=0x1B
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	TSTR0:1;
			__BYTE	TCS0:3;
			__BYTE	CINV:1;
			__BYTE	T0IEN:1;
			__BYTE	TFCR0:1;
			__BYTE	TIF0:1;
	} bit;
	struct {
			__BYTE	TSTR0:1;
			__BYTE	TCS00:1;
			__BYTE	TCS01:1;
			__BYTE	TCS02:1;
			__BYTE	CINV:1;
			__BYTE	T0IEN:1;
			__BYTE	TFCR0:1;
			__BYTE	TIF0:1;
	} bitc;
} TCR0STR;

__IO_EXTERN	  TCR0STR	IO_TCR0;
#define	_tcr0		(IO_TCR0)
#define	TCR0		(IO_TCR0.byte)
#define	TCR0_TSTR0  	(IO_TCR0.bit.TSTR0)
#define	TCR0_TCS0  	(IO_TCR0.bit.TCS0)
#define	TCR0_TCS00  	(IO_TCR0.bitc.TCS00)
#define	TCR0_TCS01  	(IO_TCR0.bitc.TCS01)
#define	TCR0_TCS02  	(IO_TCR0.bitc.TCS02)
#define	TCR0_CINV  	(IO_TCR0.bit.CINV)
#define	TCR0_T0IEN  	(IO_TCR0.bit.T0IEN)
#define	TCR0_TFCR0  	(IO_TCR0.bit.TFCR0)
#define	TCR0_TIF0  	(IO_TCR0.bit.TIF0)

#ifdef __IO_DEFINE
#pragma segment IO=IO_TDR01, locate=0x1C
#endif

__IO_EXTERN	union {
	__WORD	word;
	struct {
		__BYTE	TDR1;
		__BYTE	TDR0;
	} byte;
} IO_TDR01;

#define	TDR01		(IO_TDR01.word)
#define	TDR01_TDR1	(IO_TDR01.byte.TDR1)
#define	TDR01_TDR0	(IO_TDR01.byte.TDR0)

#ifdef __IO_DEFINE
#pragma segment IO=IO_TCP, locate=0x1E
#endif

__IO_EXTERN	const	union {
	__WORD	word;
	struct {
		__BYTE	TCPH;
		__BYTE	TCPL;
	} byte;
} IO_TCP;

#define	TCP		(IO_TCP.word)
#define	TCP_TCPH	(IO_TCP.byte.TCPH)
#define	TCP_TCPL	(IO_TCP.byte.TCPL)

#ifdef __IO_DEFINE
#pragma segment IO=IO_TCR2, locate=0x20
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	TSEL:1;
			__BYTE	PEN:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	TSEL:1;
			__BYTE	PEN:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} TCR2STR;

__IO_EXTERN	  TCR2STR	IO_TCR2;
#define	_tcr2		(IO_TCR2)
#define	TCR2		(IO_TCR2.byte)
#define	TCR2_TSEL  	(IO_TCR2.bit.TSEL)
#define	TCR2_PEN  	(IO_TCR2.bit.PEN)

#ifdef __IO_DEFINE
#pragma segment IO=IO_CNTR, locate=0x22
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	TIE:1;
			__BYTE	OE:1;
			__BYTE	TIR:1;
			__BYTE	TPE:1;
			__BYTE	P:2;
			__BYTE	RESV5:1;
			__BYTE	P_TX:1;
	} bit;
	struct {
			__BYTE	TIE:1;
			__BYTE	OE:1;
			__BYTE	TIR:1;
			__BYTE	TPE:1;
			__BYTE	P0:1;
			__BYTE	P1:1;
			__BYTE	RESV6:1;
			__BYTE	P_TX:1;
	} bitc;
} CNTRSTR;

__IO_EXTERN	  CNTRSTR	IO_CNTR;
#define	_cntr		(IO_CNTR)
#define	CNTR		(IO_CNTR.byte)
#define	CNTR_TIE  	(IO_CNTR.bit.TIE)
#define	CNTR_OE  	(IO_CNTR.bit.OE)
#define	CNTR_TIR  	(IO_CNTR.bit.TIR)
#define	CNTR_TPE  	(IO_CNTR.bit.TPE)
#define	CNTR_P  	(IO_CNTR.bit.P)
#define	CNTR_P0  	(IO_CNTR.bitc.P0)
#define	CNTR_P1  	(IO_CNTR.bitc.P1)
#define	CNTR_P_TX  	(IO_CNTR.bit.P_TX)

#ifdef __IO_DEFINE
#pragma segment IO=IO_COMR, locate=0x23
#endif

__IO_EXTERN	__BYTE	IO_COMR;
#define	_comr		(IO_COMR)
#define	COMR	(_comr)

#ifdef __IO_DEFINE
#pragma segment IO=IO_EIC1, locate=0x24
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	EIE0:1;
			__BYTE	SL0:2;
			__BYTE	EIR0:1;
			__BYTE	EIE1:1;
			__BYTE	SL1:2;
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
} EIC1STR;

__IO_EXTERN	  EIC1STR	IO_EIC1;
#define	_eic1		(IO_EIC1)
#define	EIC1		(IO_EIC1.byte)
#define	EIC1_EIE0  	(IO_EIC1.bit.EIE0)
#define	EIC1_SL0  	(IO_EIC1.bit.SL0)
#define	EIC1_SL00  	(IO_EIC1.bitc.SL00)
#define	EIC1_SL01  	(IO_EIC1.bitc.SL01)
#define	EIC1_EIR0  	(IO_EIC1.bit.EIR0)
#define	EIC1_EIE1  	(IO_EIC1.bit.EIE1)
#define	EIC1_SL1  	(IO_EIC1.bit.SL1)
#define	EIC1_SL10  	(IO_EIC1.bitc.SL10)
#define	EIC1_SL11  	(IO_EIC1.bitc.SL11)
#define	EIC1_EIR1  	(IO_EIC1.bit.EIR1)

#ifdef __IO_DEFINE
#pragma segment IO=IO_EIC2, locate=0x25
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	EIE2:1;
			__BYTE	SL2:2;
			__BYTE	EIR2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
	} bit;
	struct {
			__BYTE	EIE2:1;
			__BYTE	SL20:1;
			__BYTE	SL21:1;
			__BYTE	EIR2:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} EIC2STR;

__IO_EXTERN	  EIC2STR	IO_EIC2;
#define	_eic2		(IO_EIC2)
#define	EIC2		(IO_EIC2.byte)
#define	EIC2_EIE2  	(IO_EIC2.bit.EIE2)
#define	EIC2_SL2  	(IO_EIC2.bit.SL2)
#define	EIC2_SL20  	(IO_EIC2.bitc.SL20)
#define	EIC2_SL21  	(IO_EIC2.bitc.SL21)
#define	EIC2_EIR2  	(IO_EIC2.bit.EIR2)

#ifdef __IO_DEFINE
#pragma segment IO=IO_SMC, locate=0x28
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	SOE:1;
			__BYTE	SCKE:1;
			__BYTE	RESV2:1;
			__BYTE	SMDE:1;
			__BYTE	MC:2;
			__BYTE	SBL:1;
			__BYTE	PEN:1;
	} bit;
	struct {
			__BYTE	SOE:1;
			__BYTE	SCKE:1;
			__BYTE	RESV2:1;
			__BYTE	SMDE:1;
			__BYTE	MC0:1;
			__BYTE	MC1:1;
			__BYTE	SBL:1;
			__BYTE	PEN:1;
	} bitc;
} SMCSTR;

__IO_EXTERN	  SMCSTR	IO_SMC;
#define	_smc		(IO_SMC)
#define	SMC		(IO_SMC.byte)
#define	SMC_SOE  	(IO_SMC.bit.SOE)
#define	SMC_SCKE  	(IO_SMC.bit.SCKE)
#define	SMC_SMDE  	(IO_SMC.bit.SMDE)
#define	SMC_MC  	(IO_SMC.bit.MC)
#define	SMC_MC0  	(IO_SMC.bitc.MC0)
#define	SMC_MC1  	(IO_SMC.bitc.MC1)
#define	SMC_SBL  	(IO_SMC.bit.SBL)
#define	SMC_PEN  	(IO_SMC.bit.PEN)

#ifdef __IO_DEFINE
#pragma segment IO=IO_SRC, locate=0x29
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	RC:3;
			__BYTE	CS:2;
			__BYTE	CR:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
	} bit;
	struct {
			__BYTE	RC0:1;
			__BYTE	RC1:1;
			__BYTE	RC2:1;
			__BYTE	CS0:1;
			__BYTE	CS1:1;
			__BYTE	CR:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} SRCSTR;

__IO_EXTERN	  SRCSTR	IO_SRC;
#define	_src		(IO_SRC)
#define	SRC		(IO_SRC.byte)
#define	SRC_RC  	(IO_SRC.bit.RC)
#define	SRC_RC0  	(IO_SRC.bitc.RC0)
#define	SRC_RC1  	(IO_SRC.bitc.RC1)
#define	SRC_RC2  	(IO_SRC.bitc.RC2)
#define	SRC_CS  	(IO_SRC.bit.CS)
#define	SRC_CS0  	(IO_SRC.bitc.CS0)
#define	SRC_CS1  	(IO_SRC.bitc.CS1)
#define	SRC_CR  	(IO_SRC.bit.CR)

#ifdef __IO_DEFINE
#pragma segment IO=IO_SSD, locate=0x2A
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	RD8_RP:1;
			__BYTE	TD8_TP:1;
			__BYTE	RESV2:1;
			__BYTE	RIE:1;
			__BYTE	TIE:1;
			__BYTE	TDRE:1;
			__BYTE	ORFE:1;
			__BYTE	RDRF:1;
	} bit;
	struct {
			__BYTE	RD8_RP:1;
			__BYTE	TD8_TP:1;
			__BYTE	RESV2:1;
			__BYTE	RIE:1;
			__BYTE	TIE:1;
			__BYTE	TDRE:1;
			__BYTE	ORFE:1;
			__BYTE	RDRF:1;
	} bitc;
} SSDSTR;

__IO_EXTERN	  SSDSTR	IO_SSD;
#define	_ssd		(IO_SSD)
#define	SSD		(IO_SSD.byte)
#define	SSD_RD8_RP  	(IO_SSD.bit.RD8_RP)
#define	SSD_TD8_TP  	(IO_SSD.bit.TD8_TP)
#define	SSD_RIE  	(IO_SSD.bit.RIE)
#define	SSD_TIE  	(IO_SSD.bit.TIE)
#define	SSD_TDRE  	(IO_SSD.bit.TDRE)
#define	SSD_ORFE  	(IO_SSD.bit.ORFE)
#define	SSD_RDRF  	(IO_SSD.bit.RDRF)

#ifdef __IO_DEFINE
#pragma segment IO=IO_SIDR, locate=0x2B
#endif

__IO_EXTERN	__BYTE	IO_SIDR;
#define	_sidr		(IO_SIDR)
#define	SIDR	(_sidr)

#ifdef __IO_DEFINE
#pragma segment IO=IO_UPC, locate=0x2C
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	PR:3;
			__BYTE	PREN:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
	} bit;
	struct {
			__BYTE	PR0:1;
			__BYTE	PR1:1;
			__BYTE	PR2:1;
			__BYTE	PREN:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} UPCSTR;

__IO_EXTERN	  UPCSTR	IO_UPC;
#define	_upc		(IO_UPC)
#define	UPC		(IO_UPC.byte)
#define	UPC_PR  	(IO_UPC.bit.PR)
#define	UPC_PR0  	(IO_UPC.bitc.PR0)
#define	UPC_PR1  	(IO_UPC.bitc.PR1)
#define	UPC_PR2  	(IO_UPC.bitc.PR2)
#define	UPC_PREN  	(IO_UPC.bit.PREN)

#ifdef __IO_DEFINE
#pragma segment IO=IO_ADC1, locate=0x30
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	AD:1;
			__BYTE	RESV1:1;
			__BYTE	ADMV:1;
			__BYTE	ADI:1;
			__BYTE	ANS:3;
			__BYTE	RESV5:1;
	} bit;
	struct {
			__BYTE	AD:1;
			__BYTE	RESV1:1;
			__BYTE	ADMV:1;
			__BYTE	ADI:1;
			__BYTE	ANS0:1;
			__BYTE	ANS1:1;
			__BYTE	ANS2:1;
			__BYTE	RESV7:1;
	} bitc;
} ADC1STR;

__IO_EXTERN	  ADC1STR	IO_ADC1;
#define	_adc1		(IO_ADC1)
#define	ADC1		(IO_ADC1.byte)
#define	ADC1_AD  	(IO_ADC1.bit.AD)
#define	ADC1_ADMV  	(IO_ADC1.bit.ADMV)
#define	ADC1_ADI  	(IO_ADC1.bit.ADI)
#define	ADC1_ANS  	(IO_ADC1.bit.ANS)
#define	ADC1_ANS0  	(IO_ADC1.bitc.ANS0)
#define	ADC1_ANS1  	(IO_ADC1.bitc.ANS1)
#define	ADC1_ANS2  	(IO_ADC1.bitc.ANS2)

#ifdef __IO_DEFINE
#pragma segment IO=IO_ADC2, locate=0x31
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	RESV0:1;
			__BYTE	EXT:1;
			__BYTE	RESV2:1;
			__BYTE	ADIE:1;
			__BYTE	ADCK:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	RESV0:1;
			__BYTE	EXT:1;
			__BYTE	RESV2:1;
			__BYTE	ADIE:1;
			__BYTE	ADCK:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} ADC2STR;

__IO_EXTERN	  ADC2STR	IO_ADC2;
#define	_adc2		(IO_ADC2)
#define	ADC2		(IO_ADC2.byte)
#define	ADC2_EXT  	(IO_ADC2.bit.EXT)
#define	ADC2_ADIE  	(IO_ADC2.bit.ADIE)
#define	ADC2_ADCK  	(IO_ADC2.bit.ADCK)

#ifdef __IO_DEFINE
#pragma segment IO=IO_ADD, locate=0x32
#endif

typedef union {
	__WORD	word;
	struct {
			__WORD	DATA10:10;
			__WORD	RESV1:1;
			__WORD	RESV2:1;
			__WORD	RESV3:1;
			__WORD	RESV4:1;
			__WORD	RESV5:1;
			__WORD	RESV6:1;
	} bit;
	struct {
			__WORD	DATA100:1;
			__WORD	DATA101:1;
			__WORD	DATA102:1;
			__WORD	DATA103:1;
			__WORD	DATA104:1;
			__WORD	DATA105:1;
			__WORD	DATA106:1;
			__WORD	DATA107:1;
			__WORD	DATA108:1;
			__WORD	DATA109:1;
			__WORD	RESV10:1;
			__WORD	RESV11:1;
			__WORD	RESV12:1;
			__WORD	RESV13:1;
			__WORD	RESV14:1;
			__WORD	RESV15:1;
	} bitc;
} ADDSTR;

__IO_EXTERN	  ADDSTR	IO_ADD;
#define	_add		(IO_ADD)
#define	ADD		(IO_ADD.word)
#define	ADD_DATA10  	(IO_ADD.bit.DATA10)
#define	ADD_DATA100  	(IO_ADD.bitc.DATA100)
#define	ADD_DATA101  	(IO_ADD.bitc.DATA101)
#define	ADD_DATA102  	(IO_ADD.bitc.DATA102)
#define	ADD_DATA103  	(IO_ADD.bitc.DATA103)
#define	ADD_DATA104  	(IO_ADD.bitc.DATA104)
#define	ADD_DATA105  	(IO_ADD.bitc.DATA105)
#define	ADD_DATA106  	(IO_ADD.bitc.DATA106)
#define	ADD_DATA107  	(IO_ADD.bitc.DATA107)
#define	ADD_DATA108  	(IO_ADD.bitc.DATA108)
#define	ADD_DATA109  	(IO_ADD.bitc.DATA109)

#ifdef __IO_DEFINE
#pragma segment IO=IO_ADEN, locate=0x34
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	ADE0:1;
			__BYTE	ADE1:1;
			__BYTE	ADE2:1;
			__BYTE	ADE3:1;
			__BYTE	ADE4:1;
			__BYTE	ADE5:1;
			__BYTE	ADE6:1;
			__BYTE	ADE7:1;
	} bit;
	struct {
			__BYTE	ADE0:1;
			__BYTE	ADE1:1;
			__BYTE	ADE2:1;
			__BYTE	ADE3:1;
			__BYTE	ADE4:1;
			__BYTE	ADE5:1;
			__BYTE	ADE6:1;
			__BYTE	ADE7:1;
	} bitc;
} ADENSTR;

__IO_EXTERN	  ADENSTR	IO_ADEN;
#define	_aden		(IO_ADEN)
#define	ADEN		(IO_ADEN.byte)
#define	ADEN_ADE0  	(IO_ADEN.bit.ADE0)
#define	ADEN_ADE1  	(IO_ADEN.bit.ADE1)
#define	ADEN_ADE2  	(IO_ADEN.bit.ADE2)
#define	ADEN_ADE3  	(IO_ADEN.bit.ADE3)
#define	ADEN_ADE4  	(IO_ADEN.bit.ADE4)
#define	ADEN_ADE5  	(IO_ADEN.bit.ADE5)
#define	ADEN_ADE6  	(IO_ADEN.bit.ADE6)
#define	ADEN_ADE7  	(IO_ADEN.bit.ADE7)

#ifdef __IO_DEFINE
#pragma segment IO=IO_EIE2, locate=0x36
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	IE20:1;
			__BYTE	IE21:1;
			__BYTE	IE22:1;
			__BYTE	IE23:1;
			__BYTE	IE24:1;
			__BYTE	IE25:1;
			__BYTE	IE26:1;
			__BYTE	IE27:1;
	} bit;
	struct {
			__BYTE	IE20:1;
			__BYTE	IE21:1;
			__BYTE	IE22:1;
			__BYTE	IE23:1;
			__BYTE	IE24:1;
			__BYTE	IE25:1;
			__BYTE	IE26:1;
			__BYTE	IE27:1;
	} bitc;
} EIE2STR;

__IO_EXTERN	  EIE2STR	IO_EIE2;
#define	_eie2		(IO_EIE2)
#define	EIE2_		(IO_EIE2.byte)
#define	EIE2_IE20  	(IO_EIE2.bit.IE20)
#define	EIE2_IE21  	(IO_EIE2.bit.IE21)
#define	EIE2_IE22  	(IO_EIE2.bit.IE22)
#define	EIE2_IE23  	(IO_EIE2.bit.IE23)
#define	EIE2_IE24  	(IO_EIE2.bit.IE24)
#define	EIE2_IE25  	(IO_EIE2.bit.IE25)
#define	EIE2_IE26  	(IO_EIE2.bit.IE26)
#define	EIE2_IE27  	(IO_EIE2.bit.IE27)

#ifdef __IO_DEFINE
#pragma segment IO=IO_EIF2, locate=0x37
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	IF20:1;
			__BYTE	RESV1:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	IF20:1;
			__BYTE	RESV1:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} EIF2STR;

__IO_EXTERN	  EIF2STR	IO_EIF2;
#define	_eif2		(IO_EIF2)
#define	EIF2		(IO_EIF2.byte)
#define	EIF2_IF20  	(IO_EIF2.bit.IF20)

#ifdef __IO_DEFINE
#pragma segment IO=IO_SMR, locate=0x39
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	SST:1;
			__BYTE	BDS:1;
			__BYTE	CKS:2;
			__BYTE	SOE:1;
			__BYTE	SCKE:1;
			__BYTE	SIOE:1;
			__BYTE	SIOF:1;
	} bit;
	struct {
			__BYTE	SST:1;
			__BYTE	BDS:1;
			__BYTE	CKS0:1;
			__BYTE	CKS1:1;
			__BYTE	SOE:1;
			__BYTE	SCKE:1;
			__BYTE	SIOE:1;
			__BYTE	SIOF:1;
	} bitc;
} SMRSTR;

__IO_EXTERN	  SMRSTR	IO_SMR;
#define	_smr		(IO_SMR)
#define	SMR		(IO_SMR.byte)
#define	SMR_SST  	(IO_SMR.bit.SST)
#define	SMR_BDS  	(IO_SMR.bit.BDS)
#define	SMR_CKS  	(IO_SMR.bit.CKS)
#define	SMR_CKS0  	(IO_SMR.bitc.CKS0)
#define	SMR_CKS1  	(IO_SMR.bitc.CKS1)
#define	SMR_SOE  	(IO_SMR.bit.SOE)
#define	SMR_SCKE  	(IO_SMR.bit.SCKE)
#define	SMR_SIOE  	(IO_SMR.bit.SIOE)
#define	SMR_SIOF  	(IO_SMR.bit.SIOF)

#ifdef __IO_DEFINE
#pragma segment IO=IO_SDR, locate=0x3A
#endif

__IO_EXTERN	__BYTE	IO_SDR;
#define	_sdr		(IO_SDR)
#define	SDR	(_sdr)

#ifdef __IO_DEFINE
#pragma segment IO=IO_SSEL, locate=0x3B
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	SSEL:1;
			__BYTE	RESV1:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	SSEL:1;
			__BYTE	RESV1:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} SSELSTR;

__IO_EXTERN	  SSELSTR	IO_SSEL;
#define	_ssel		(IO_SSEL)
#define	SSEL_		(IO_SSEL.byte)
#define	SSEL_SSEL  	(IO_SSEL.bit.SSEL)

#ifdef __IO_DEFINE
#pragma segment IO=IO_WRARH0, locate=0x40
#endif

__IO_EXTERN	__BYTE	IO_WRARH0;
#define	_wrarh0		(IO_WRARH0)
#define	WRARH0	(_wrarh0)

#ifdef __IO_DEFINE
#pragma segment IO=IO_WRARL0, locate=0x41
#endif

__IO_EXTERN	__BYTE	IO_WRARL0;
#define	_wrarl0		(IO_WRARL0)
#define	WRARL0	(_wrarl0)

#ifdef __IO_DEFINE
#pragma segment IO=IO_WRDR0, locate=0x42
#endif

__IO_EXTERN	__BYTE	IO_WRDR0;
#define	_wrdr0		(IO_WRDR0)
#define	WRDR0	(_wrdr0)

#ifdef __IO_DEFINE
#pragma segment IO=IO_WRARH1, locate=0x43
#endif

__IO_EXTERN	__BYTE	IO_WRARH1;
#define	_wrarh1		(IO_WRARH1)
#define	WRARH1	(_wrarh1)

#ifdef __IO_DEFINE
#pragma segment IO=IO_WRARL1, locate=0x44
#endif

__IO_EXTERN	__BYTE	IO_WRARL1;
#define	_wrarl1		(IO_WRARL1)
#define	WRARL1	(_wrarl1)

#ifdef __IO_DEFINE
#pragma segment IO=IO_WRDR1, locate=0x45
#endif

__IO_EXTERN	__BYTE	IO_WRDR1;
#define	_wrdr1		(IO_WRDR1)
#define	WRDR1	(_wrdr1)

#ifdef __IO_DEFINE
#pragma segment IO=IO_WREN, locate=0x46
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	EN00:1;
			__BYTE	EN01:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	EN00:1;
			__BYTE	EN01:1;
			__BYTE	RESV2:1;
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
#define	WREN_EN00  	(IO_WREN.bit.EN00)
#define	WREN_EN01  	(IO_WREN.bit.EN01)

#ifdef __IO_DEFINE
#pragma segment IO=IO_PUL0, locate=0x70
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	PUL00:1;
			__BYTE	PUL01:1;
			__BYTE	PUL02:1;
			__BYTE	PUL03:1;
			__BYTE	PUL04:1;
			__BYTE	PUL05:1;
			__BYTE	PUL06:1;
			__BYTE	PUL07:1;
	} bit;
	struct {
			__BYTE	PUL00:1;
			__BYTE	PUL01:1;
			__BYTE	PUL02:1;
			__BYTE	PUL03:1;
			__BYTE	PUL04:1;
			__BYTE	PUL05:1;
			__BYTE	PUL06:1;
			__BYTE	PUL07:1;
	} bitc;
} PUL0STR;

__IO_EXTERN	  PUL0STR	IO_PUL0;
#define	_pul0		(IO_PUL0)
#define	PUL0		(IO_PUL0.byte)
#define	PUL0_PUL00  	(IO_PUL0.bit.PUL00)
#define	PUL0_PUL01  	(IO_PUL0.bit.PUL01)
#define	PUL0_PUL02  	(IO_PUL0.bit.PUL02)
#define	PUL0_PUL03  	(IO_PUL0.bit.PUL03)
#define	PUL0_PUL04  	(IO_PUL0.bit.PUL04)
#define	PUL0_PUL05  	(IO_PUL0.bit.PUL05)
#define	PUL0_PUL06  	(IO_PUL0.bit.PUL06)
#define	PUL0_PUL07  	(IO_PUL0.bit.PUL07)

#ifdef __IO_DEFINE
#pragma segment IO=IO_PUL3, locate=0x71
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	PUL30:1;
			__BYTE	PUL31:1;
			__BYTE	PUL32:1;
			__BYTE	PUL33:1;
			__BYTE	PUL34:1;
			__BYTE	PUL35:1;
			__BYTE	PUL36:1;
			__BYTE	PUL37:1;
	} bit;
	struct {
			__BYTE	PUL30:1;
			__BYTE	PUL31:1;
			__BYTE	PUL32:1;
			__BYTE	PUL33:1;
			__BYTE	PUL34:1;
			__BYTE	PUL35:1;
			__BYTE	PUL36:1;
			__BYTE	PUL37:1;
	} bitc;
} PUL3STR;

__IO_EXTERN	  PUL3STR	IO_PUL3;
#define	_pul3		(IO_PUL3)
#define	PUL3		(IO_PUL3.byte)
#define	PUL3_PUL30  	(IO_PUL3.bit.PUL30)
#define	PUL3_PUL31  	(IO_PUL3.bit.PUL31)
#define	PUL3_PUL32  	(IO_PUL3.bit.PUL32)
#define	PUL3_PUL33  	(IO_PUL3.bit.PUL33)
#define	PUL3_PUL34  	(IO_PUL3.bit.PUL34)
#define	PUL3_PUL35  	(IO_PUL3.bit.PUL35)
#define	PUL3_PUL36  	(IO_PUL3.bit.PUL36)
#define	PUL3_PUL37  	(IO_PUL3.bit.PUL37)

#ifdef __IO_DEFINE
#pragma segment IO=IO_PUL5, locate=0x72
#endif

typedef union {
	__BYTE	byte;
	struct {
			__BYTE	PUL50:1;
			__BYTE	RESV1:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bit;
	struct {
			__BYTE	PUL50:1;
			__BYTE	RESV1:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
	} bitc;
} PUL5STR;

__IO_EXTERN	  PUL5STR	IO_PUL5;
#define	_pul5		(IO_PUL5)
#define	PUL5		(IO_PUL5.byte)
#define	PUL5_PUL50  	(IO_PUL5.bit.PUL50)

#ifdef __IO_DEFINE
#pragma segment IO=IO_ILR1, locate=0x7B
#endif

__IO_EXTERN	__BYTE	IO_ILR1;
#define	_ilr1		(IO_ILR1)
#define	ILR1	(_ilr1)

#ifdef __IO_DEFINE
#pragma segment IO=IO_ILR2, locate=0x7C
#endif

__IO_EXTERN	__BYTE	IO_ILR2;
#define	_ilr2		(IO_ILR2)
#define	ILR2	(_ilr2)

#ifdef __IO_DEFINE
#pragma segment IO=IO_ILR3, locate=0x7D
#endif

__IO_EXTERN	__BYTE	IO_ILR3;
#define	_ilr3		(IO_ILR3)
#define	ILR3	(_ilr3)

#ifdef __IO_DEFINE
#pragma segment IO=IO_ILR4, locate=0x7E
#endif

__IO_EXTERN	__BYTE	IO_ILR4;
#define	_ilr4		(IO_ILR4)
#define	ILR4	(_ilr4)
