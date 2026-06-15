/*
 MB89051 Series I/O register declaration file V30L02
 ALL RIGHTS RESERVED, COPYRIGHT (C) FUJITSU LIMITED 2002
 LICENSED MATERIAL - PROGRAM PROPERTY OF FUJITSU LIMITED
*/
#include "_f8ldef.h"


/*********************/
/* structure of PDR0 */
/*********************/
#macro io_pdr0 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	P00 ,1)
		__UCHARBIT(	P01 ,1)
		__UCHARBIT(	P02 ,1)
		__UCHARBIT(	P03 ,1)
		__UCHARBIT(	P04 ,1)
		__UCHARBIT(	P05 ,1)
		__UCHARBIT(	P06 ,1)
		__UCHARBIT(	P07 ,1)
	__STRUCT_TYPE_E(bit)
#endm

/*********************/
/* structure of PDR1 */
/*********************/
#macro io_pdr1 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	P10 ,1)
		__UCHARBIT(	P11 ,1)
		__UCHARBIT(	P12 ,1)
		__UCHARBIT(	P13 ,1)
		__UCHARBIT(	P14 ,1)
		__UCHARBIT(	P15 ,1)
		__UCHARBIT(	P16 ,1)
		__UCHARBIT(	P17 ,1)
	__STRUCT_TYPE_E(bit)
#endm

/*********************/
/* structure of PDR2 */
/*********************/
#macro io_pdr2 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	P20 ,1)
		__UCHARBIT(	P21 ,1)
		__UCHARBIT(	P22 ,1)
		__UCHARBIT(	P23 ,1)
		__UCHARBIT(	P24 ,1)
		__UCHARBIT(	P25 ,1)
		__UCHARBIT(	P26 ,1)
		__UCHARBIT(	P27 ,1)
	__STRUCT_TYPE_E(bit)
#endm

/*********************/
/* structure of SYCC */
/*********************/
#macro io_sycc symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	CS  ,2)
		__UCHARBIT_NONAME(   1)
		__UCHARBIT(	WT  ,2)
		__UCHARBIT_NONAME(   3)
	__STRUCT_TYPE_E(bit)
#endm

/*********************/
/* structure of STBC */
/*********************/
#macro io_stbc symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT_NONAME(   4)
		__UCHARBIT(	RST ,1)
		__UCHARBIT(	SPL ,1)
		__UCHARBIT(	SLP ,1)
		__UCHARBIT(	STP ,1)
	__STRUCT_TYPE_E(bit)
#endm

/*********************/
/* structure of TBTC */
/*********************/
#macro io_tbtc symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	TBR ,1)
		__UCHARBIT(	TBC ,2)
		__UCHARBIT_NONAME(   3)
		__UCHARBIT(	TBIE,1)
		__UCHARBIT(	TBOF,1)
	__STRUCT_TYPE_E(bit)
#endm

/*********************/
/* structure of PDR3 */
/*********************/
#macro io_pdr3 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	P30 ,1)
		__UCHARBIT(	P31 ,1)
		__UCHARBIT(	P32 ,1)
		__UCHARBIT(	P33 ,1)
		__UCHARBIT(	P34 ,1)
		__UCHARBIT(	P35 ,1)
		__UCHARBIT(	P36 ,1)
		__UCHARBIT(	P37 ,1)
	__STRUCT_TYPE_E(bit)
#endm

/*********************/
/* structure of PDR4 */
/*********************/
#macro io_pdr4 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	P40 ,1)
		__UCHARBIT(	P41 ,1)
		__UCHARBIT(	P42 ,1)
		__UCHARBIT(	P43 ,1)
		__UCHARBIT(	P44 ,1)
		__UCHARBIT(	P45 ,1)
		__UCHARBIT(	P46 ,1)
		__UCHARBIT(	P47 ,1)
	__STRUCT_TYPE_E(bit)
#endm

/*********************/
/* structure of PDR5 */
/*********************/
#macro io_pdr5 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	P50 ,1)
		__UCHARBIT(	P51 ,1)
		__UCHARBIT(	P52 ,1)
		__UCHARBIT(	P53 ,1)
		__UCHARBIT(	P54 ,1)
		__UCHARBIT(	P55 ,1)
		__UCHARBIT(	P56 ,1)
		__UCHARBIT(	P57 ,1)
	__STRUCT_TYPE_E(bit)
#endm

/**********************/
/* structure of PURR0 */
/**********************/
#macro io_purr0 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	PUR00 ,1)
		__UCHARBIT(	PUR01 ,1)
		__UCHARBIT(	PUR02 ,1)
		__UCHARBIT(	PUR03 ,1)
		__UCHARBIT(	PUR04 ,1)
		__UCHARBIT(	PUR05 ,1)
		__UCHARBIT(	PUR06 ,1)
		__UCHARBIT(	PUR07 ,1)
	__STRUCT_TYPE_E(bit)
#endm

/**********************/
/* structure of PURR1 */
/**********************/
#macro io_purr1 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	PUR10 ,1)
		__UCHARBIT(	PUR11 ,1)
		__UCHARBIT(	PUR12 ,1)
		__UCHARBIT(	PUR13 ,1)
		__UCHARBIT(	PUR14 ,1)
		__UCHARBIT(	PUR15 ,1)
		__UCHARBIT(	PUR16 ,1)
		__UCHARBIT(	PUR17 ,1)
	__STRUCT_TYPE_E(bit)
#endm

/**********************/
/* structure of PURR2 */
/**********************/
#macro io_purr2 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	PUR20 ,1)
		__UCHARBIT(	PUR21 ,1)
		__UCHARBIT(	PUR22 ,1)
		__UCHARBIT(	PUR23 ,1)
		__UCHARBIT(	PUR24 ,1)
		__UCHARBIT(	PUR25 ,1)
		__UCHARBIT(	PUR26 ,1)
		__UCHARBIT(	PUR27 ,1)
	__STRUCT_TYPE_E(bit)
#endm

/**********************/
/* structure of PURR3 */
/**********************/
#macro io_purr3 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT_NONAME(     1)
		__UCHARBIT(	PUR31 ,1)
		__UCHARBIT(	PUR32 ,1)
		__UCHARBIT(	PUR33 ,1)
		__UCHARBIT(	PUR34 ,1)
		__UCHARBIT(	PUR35 ,1)
		__UCHARBIT(	PUR36 ,1)
		__UCHARBIT(	PUR37 ,1)
	__STRUCT_TYPE_E(bit)
#endm

/**********************/
/* structure of PURR4 */
/**********************/
#macro io_purr4 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	PUR40 ,1)
		__UCHARBIT(	PUR41 ,1)
		__UCHARBIT(	PUR42 ,1)
		__UCHARBIT(	PUR43 ,1)
		__UCHARBIT(	PUR44 ,1)
		__UCHARBIT(	PUR45 ,1)
		__UCHARBIT_NONAME(     2)
	__STRUCT_TYPE_E(bit)
#endm

/**********************/
/* structure of CNTR1 */
/**********************/
#macro io_cntr1 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	SC2 ,2)
		__UCHARBIT(	SC1 ,2)
		__UCHARBIT(	P7M2,1)
		__UCHARBIT(	P7M1,1)
		__UCHARBIT(	PTX2,1)
		__UCHARBIT(	PTX1,1)
	__STRUCT_TYPE_E(bit)
#endm

/**********************/
/* structure of CNTR2 */
/**********************/
#macro io_cntr2 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	TIE2,1)
		__UCHARBIT(	TIE1,1)
		__UCHARBIT(	TIR2,1)
		__UCHARBIT(	TIR1,1)
		__UCHARBIT_NONAME(   1)
		__UCHARBIT(	CK12,1)
		__UCHARBIT(	TPE2,1)
		__UCHARBIT(	TPE1,1)
	__STRUCT_TYPE_E(bit)
#endm

/**********************/
/* structure of CNTR3 */
/**********************/
#macro io_cntr3 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT_NONAME(   4)
		__UCHARBIT(	CH12,1)
		__UCHARBIT(	OE3 ,1)
		__UCHARBIT(	OE2 ,1)
		__UCHARBIT_NONAME(   1)
	__STRUCT_TYPE_E(bit)
#endm

/*********************/
/* structure of CKR  */
/*********************/
#macro io_ckr  symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	CK1E,1)
		__UCHARBIT(	CK2E,1)
		__UCHARBIT_NONAME(   6)
	__STRUCT_TYPE_E(bit)
#endm

/********************/
/* structure of SCS */
/********************/
#macro io_scs symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	EXBRE,1)
		__UCHARBIT_NONAME(    7)
	__STRUCT_TYPE_E(bit)
#endm

/*********************/
/* structure of FMCS */
/*********************/
#macro io_fmcs symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT_NONAME(      4)
		__UCHARBIT(	RDY   , 1)
		__UCHARBIT(	WE    , 1)
		__UCHARBIT(	RDYINT, 1)
		__UCHARBIT(	INTE  , 1)
	__STRUCT_TYPE_E(bit)
#endm

/*********************/
/* structure of SMC1 */
/*********************/
#macro io_smc1 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	CS  ,3)
		__UCHARBIT(	CL  ,1)
		__UCHARBIT(	SBL ,1)
		__UCHARBIT(	TDP ,1)
		__UCHARBIT(	PEN ,1)
		__UCHARBIT(	MD  ,1)
	__STRUCT_TYPE_E(bit)
#endm

/*********************/
/* structure of SMC2 */
/*********************/
#macro io_smc2 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	TIE ,1)
		__UCHARBIT(	RIE ,1)
		__UCHARBIT(	SCKE,1)
		__UCHARBIT(	TXOE,1)
		__UCHARBIT(	BRGE,1)
		__UCHARBIT(	TXE ,1)
		__UCHARBIT(	RXE ,1)
		__UCHARBIT(	RERC,1)
	__STRUCT_TYPE_E(bit)
#endm

/********************/
/* structure of SSD */
/********************/
#macro io_ssd symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT_NONAME(   3)
		__UCHARBIT(	TDRE,1)
		__UCHARBIT(	RDRF,1)
		__UCHARBIT(	FER ,1)
		__UCHARBIT(	OVE ,1)
		__UCHARBIT(	PER ,1)
	__STRUCT_TYPE_E(bit)
#endm

/*********************/
/* structure of IBSR */
/*********************/
#macro io_ibsr symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	FBT ,1)
		__UCHARBIT(	GCA ,1)
		__UCHARBIT(	AAS ,1)
		__UCHARBIT(	TRX ,1)
		__UCHARBIT(	LRB ,1)
		__UCHARBIT(	AL  ,1)
		__UCHARBIT(	RSC ,1)
		__UCHARBIT(	BB  ,1)
	__STRUCT_TYPE_E(bit)
#endm

/*********************/
/* structure of IBCR */
/*********************/
#macro io_ibcr symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	INT ,1)
		__UCHARBIT(	INTE,1)
		__UCHARBIT(	GCAA,1)
		__UCHARBIT(	ACK ,1)
		__UCHARBIT(	MSS ,1)
		__UCHARBIT(	SCC ,1)
		__UCHARBIT(	BEIE,1)
		__UCHARBIT(	BER ,1)
	__STRUCT_TYPE_E(bit)
#endm

/*********************/
/* structure of ICCR */
/*********************/
#macro io_iccr symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	CS012,3)
		__UCHARBIT(	CS34 ,2)
		__UCHARBIT(	EN   ,1)
		__UCHARBIT_NONAME(    1)
		__UCHARBIT(	DMBP ,1)
	__STRUCT_TYPE_E(bit)
#endm

/*********************/
/* structure of IADR */
/*********************/
#macro io_iadr symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	A   ,7)
		__UCHARBIT_NONAME(   1)
	__STRUCT_TYPE_E(bit)
#endm

/********************/
/* structure of SMR */
/********************/
#macro io_smr symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	SST ,1)
		__UCHARBIT(	BDS ,1)
		__UCHARBIT(	CKS ,2)
		__UCHARBIT(	SOE ,1)
		__UCHARBIT(	SCKE,1)
		__UCHARBIT(	SIOE,1)
		__UCHARBIT(	SIOF,1)
	__STRUCT_TYPE_E(bit)
#endm

/********************/
/* structure of EIE */
/********************/
#macro io_eie symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT_NONAME(  1)
		__UCHARBIT(	IE1,1)
		__UCHARBIT(	IE2,1)
		__UCHARBIT(	IE3,1)
		__UCHARBIT(	IE4,1)
		__UCHARBIT(	IE5,1)
		__UCHARBIT(	IE6,1)
		__UCHARBIT(	IE7,1)
	__STRUCT_TYPE_E(bit)
#endm

/********************/
/* structure of EIF */
/********************/
#macro io_eif symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	IF0,1)
		__UCHARBIT_NONAME(  7)
	__STRUCT_TYPE_E(bit)
#endm

/*********************/
/* structure of HMDR */
/*********************/
#macro io_hmdr symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	PWC ,1)
		__UCHARBIT_NONAME(   5)
		__UCHARBIT(	POWE,1)
		__UCHARBIT(	HRST,1)
	__STRUCT_TYPE_E(bit)
#endm

/**********************/
/* structure of HDSR1 */
/**********************/
#macro io_hdsr1 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT_NONAME(   2)
		__UCHARBIT(	OVM ,2)
		__UCHARBIT_NONAME(   4)
	__STRUCT_TYPE_E(bit)
#endm

/*********************/
/* structure of HSTR */
/*********************/
#macro io_hstr symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	P5SUS,1)
		__UCHARBIT(	P2SUS,1)
		__UCHARBIT(	P3SUS,1)
		__UCHARBIT(	P4SUS,1)
		__UCHARBIT(	MWKUP,1)
		__UCHARBIT(	WKUP ,1)
		__UCHARBIT(	RTSM ,1)
		__UCHARBIT(	RTSUS,1)
	__STRUCT_TYPE_E(bit)
#endm

/*********************/
/* structure of OCCR */
/*********************/
#macro io_occr symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	OC5 ,1)
		__UCHARBIT(	OC2 ,1)
		__UCHARBIT(	OC3 ,1)
		__UCHARBIT(	OC4 ,1)
		__UCHARBIT_NONAME(   3)
		__UCHARBIT(	HBSR,1)
	__STRUCT_TYPE_E(bit)
#endm

/**********************/
/* structure of HDSR4 */
/**********************/
#macro io_hdsr4 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	PTNM, 3)
		__UCHARBIT(	DRV2, 1)
		__UCHARBIT(	DRV3, 1)
		__UCHARBIT(	DRV4, 1)
		__UCHARBIT(	DRV5, 1)
		__UCHARBIT(	CDS,  1)
	__STRUCT_TYPE_E(bit)
#endm

/*********************/
/* structure of UMDR */
/*********************/
#macro io_umdr symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	BFS  ,1)
		__UCHARBIT(	RFBM ,1)
		__UCHARBIT_NONAME(    2)
		__UCHARBIT(	SP   ,1)
		__UCHARBIT(	HCON ,1)
		__UCHARBIT(	RESUM,1)
		__UCHARBIT(	RST  ,1)
	__STRUCT_TYPE_E(bit)
#endm

/*********************/
/* structure of DBAR */
/*********************/
#macro io_dbar symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	AD ,6)
		__UCHARBIT_NONAME(  2)
	__STRUCT_TYPE_E(bit)
#endm

/*********************/
/* structure of UCTR */
/*********************/
#macro io_uctr symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	STALL0,1)
		__UCHARBIT(	STALL1,1)
		__UCHARBIT(	STALL2,1)
		__UCHARBIT(	STALL3,1)
		__UCHARBIT(	BFOK0 ,1)
		__UCHARBIT(	BFOK1 ,1)
		__UCHARBIT(	BFOK2 ,1)
		__UCHARBIT(	BFOK3 ,1)
	__STRUCT_TYPE_E(bit)
#endm

/**********************/
/* structure of USTR1 */
/**********************/
#macro io_ustr1 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	NACK ,1)
		__UCHARBIT(	SUSP ,1)
		__UCHARBIT(	WKUP ,1)
		__UCHARBIT(	BUSR ,1)
		__UCHARBIT(	SETIF,1)
		__UCHARBIT(	SOF  ,1)
		__UCHARBIT(	SETUP,1)
		__UCHARBIT(	PKEND,1)
	__STRUCT_TYPE_E(bit)
#endm

/**********************/
/* structure of USTR2 */
/**********************/
#macro io_ustr2 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	EPC ,2)
		__UCHARBIT(	DIR ,1)
		__UCHARBIT(	SPK ,1)
		__UCHARBIT(	I1AL,2)
		__UCHARBIT(	I0AL,2)
	__STRUCT_TYPE_E(bit)
#endm

/**********************/
/* structure of UMSKR */
/**********************/
#macro io_umskr symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	BUSRF ,1)
		__UCHARBIT(	MSUSP ,1)
		__UCHARBIT(	MWKUP ,1)
		__UCHARBIT(	MBUSR ,1)
		__UCHARBIT(	MSETIF,1)
		__UCHARBIT(	MSOF  ,1)
		__UCHARBIT(	MSETUP,1)
		__UCHARBIT(	MPKEND,1)
	__STRUCT_TYPE_E(bit)
#endm

/**********************/
/* structure of EPER */
/**********************/
#macro io_eper symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	EPEN0,1)
		__UCHARBIT(	EPEN1,1)
		__UCHARBIT(	EPEN2,1)
		__UCHARBIT(	EPEN3,1)
		__UCHARBIT_NONAME(    4)
	__STRUCT_TYPE_E(bit)
#endm

/**********************/
/* structure of EPBR0 */
/**********************/
#macro io_epbr0 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	MP ,7)
		__UCHARBIT_NONAME(  1)
	__STRUCT_TYPE_E(bit)
#endm

/**********************/
/* structure of EPBRn */
/**********************/
#macro io_epbrn symbol
	__WORD_MEM
	__STRUCT_TYPE_B
		__USHORTBIT_NONAME( 2)
		__USHORTBIT(	DIR,2)
		__USHORTBIT(	TYP,2)
		__USHORTBIT_NONAME( 2)
		__USHORTBIT(	MP ,7)
		__USHORTBIT_NONAME( 1)
	__STRUCT_TYPE_E(bit)
#endm
