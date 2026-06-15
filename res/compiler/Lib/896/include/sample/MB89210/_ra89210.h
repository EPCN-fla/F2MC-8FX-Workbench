/*
 MB89210 Series I/O register declaration file V30L08R02
 ALL RIGHTS RESERVED, COPYRIGHT (C) FUJITSU LIMITED 1998
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
		__UCHARBIT_NONAME(   5)
		__UCHARBIT(	TBIE,1)
		__UCHARBIT(	TBOF,1)
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
/* structure of RSFR */
/*********************/
#macro io_rsfr symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT_NONAME(   4)
		__UCHARBIT(	SFTR,1)
		__UCHARBIT(	WDOG,1)
		__UCHARBIT(	ERST,1)
		__UCHARBIT(	PONR,1)
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
		__UCHARBIT_NONAME(   4)
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
		__UCHARBIT_NONAME(   6)
	__STRUCT_TYPE_E(bit)
#endm

/*********************/
/* structure of DDR3 */
/*********************/
#macro io_ddr3 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	P30 ,1)
		__UCHARBIT_NONAME(   7)
	__STRUCT_TYPE_E(bit)
#endm

/**********************/
/* structure of RCR21 */
/**********************/
#macro io_rcr21 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	HSC ,6)
		__UCHARBIT(	RCK ,2)
	__STRUCT_TYPE_E(bit)
#endm

/**********************/
/* structure of RCR22 */
/**********************/
#macro io_rcr22 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	HSC ,6)
		__UCHARBIT_NONAME(   2)
	__STRUCT_TYPE_E(bit)
#endm

/**********************/
/* structure of RCR23 */
/**********************/
#macro io_rcr23 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	SCL ,6)
		__UCHARBIT_NONAME(   1)
		__UCHARBIT(	RCEN,1)
	__STRUCT_TYPE_E(bit)
#endm

/**********************/
/* structure of RCR24 */
/**********************/
#macro io_rcr24 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	SCL ,6)
		__UCHARBIT_NONAME(   2)
	__STRUCT_TYPE_E(bit)
#endm

/*********************/
/* structure of TCCR */
/*********************/
#macro io_tccr symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT_NONAME(     3)
		__UCHARBIT(	TCMSK ,1)
		__UCHARBIT(	CCMSK ,1)
		__UCHARBIT(	CPIEN ,1)
		__UCHARBIT(	CFCLR ,1)
		__UCHARBIT(	CPIF  ,1)
	__STRUCT_TYPE_E(bit)
#endm

/***********************/
/* structure of T0CR01 */
/***********************/
#macro io_t0cr01 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	TSTR0 ,1)
		__UCHARBIT_NONAME(     3)
		__UCHARBIT(	CINV  ,1)
		__UCHARBIT(	T0IEN ,1)
		__UCHARBIT(	TFCR0 ,1)
		__UCHARBIT(	TIF0  ,1)
	__STRUCT_TYPE_E(bit)
#endm

/***********************/
/* structure of T1CR01 */
/***********************/
#macro io_t1cr01 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	TSTR1 ,1)
		__UCHARBIT_NONAME(     4)
		__UCHARBIT(	T1IEN ,1)
		__UCHARBIT(	TFCR1 ,1)
		__UCHARBIT(	TIF1  ,1)
	__STRUCT_TYPE_E(bit)
#endm

/**********************/
/* structure of T01DR */
/**********************/
#macro io_t01dr symbol
	__WORD_MEM
	__STRUCT_TYPE_B
		__UCHAR(	T1DR)
		__UCHAR(	T0DR)
	__STRUCT_TYPE_E(byte)
#endm

/*********************/
/* structure of TCP0 */
/*********************/
#macro io_tcp0 symbol
	__WORD_MEM
	__STRUCT_TYPE_B
		__UCHAR(	TCPH0)
		__UCHAR(	TCPL0)
	__STRUCT_TYPE_E(byte)
#endm

/*********************/
/* structure of TCR2 */
/*********************/
#macro io_tcr2 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	TSEL,1)
		__UCHARBIT(	PEN ,1)
		__UCHARBIT_NONAME(   6)
	__STRUCT_TYPE_E(bit)
#endm

/**********************/
/* structure of CNTR  */
/**********************/
#macro io_cntr symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	TIE ,1)
		__UCHARBIT(	OE  ,1)
		__UCHARBIT(	TIR ,1)
		__UCHARBIT(	TPE ,1)
		__UCHARBIT_NONAME(   3)
		__UCHARBIT(	PTX ,1)
	__STRUCT_TYPE_E(bit)
#endm

/********************/
/* structure of EIC1*/
/********************/
#macro io_eic1 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	EIE0,1)
		__UCHARBIT_NONAME(   2)
		__UCHARBIT(	EIR0,1)
		__UCHARBIT(	EIE1,1)
		__UCHARBIT_NONAME(   2)
		__UCHARBIT(	EIR1,1)
	__STRUCT_TYPE_E(bit)
#endm

/*********************/
/* structure of EIC2 */
/*********************/
#macro io_eic2 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	EIE2,1)
		__UCHARBIT_NONAME(   2)
		__UCHARBIT(	EIR2,1)
		__UCHARBIT_NONAME(   4)
	__STRUCT_TYPE_E(bit)
#endm

/*********************/
/* structure of SCR  */
/*********************/
#macro io_scr symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	TXE ,1)
		__UCHARBIT(	RXE ,1)
		__UCHARBIT(	CRE ,1)
		__UCHARBIT(	AD  ,1)
		__UCHARBIT(	CL  ,1)
		__UCHARBIT(	SBL ,1)
		__UCHARBIT(	P   ,1)
		__UCHARBIT(	PEN ,1)
	__STRUCT_TYPE_E(bit)
#endm

/*********************/
/* structure of USMR */
/*********************/
#macro io_usmr symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	USOE ,1)
		__UCHARBIT(	USCKE,1)
		__UCHARBIT(	UPCL ,1)
		__UCHARBIT(	REST ,1)
		__UCHARBIT(	EXT  ,1)
		__UCHARBIT(	OTO  ,1)
		__UCHARBIT_NONAME(   2)
	__STRUCT_TYPE_E(bit)
#endm

/*********************/
/* structure of SSR  */
/*********************/
#macro io_ssr symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	TIE  ,1)
		__UCHARBIT(	RIE  ,1)
		__UCHARBIT(	BDS  ,1)
		__UCHARBIT(	TDRE ,1)
		__UCHARBIT(	RDRF ,1)
		__UCHARBIT(	FRE  ,1)
		__UCHARBIT(	ORE  ,1)
		__UCHARBIT(	PE   ,1)
	__STRUCT_TYPE_E(bit)
#endm

/*********************/
/* structure of ESCR */
/*********************/
#macro io_escr symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	SCES ,1)
		__UCHARBIT(	CCO  ,1)
		__UCHARBIT(	SIOP ,1)
		__UCHARBIT(	SOPE ,1)
		__UCHARBIT_NONAME(    2)
		__UCHARBIT(	LBD  ,1)
		__UCHARBIT(	LBIE ,1)
	__STRUCT_TYPE_E(bit)
#endm

/*********************/
/* structure of ECCR */
/*********************/
#macro io_eccr symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	TBI  ,1)
		__UCHARBIT(	RBI  ,1)
		__UCHARBIT_NONAME(    1)
		__UCHARBIT(	SSM  ,1)
		__UCHARBIT(	SCDE ,1)
		__UCHARBIT(	MS   ,1)
		__UCHARBIT_NONAME(    1)
		__UCHARBIT(	INV  ,1)
	__STRUCT_TYPE_E(bit)
#endm

/*********************/
/* structure of BGR  */
/*********************/
#macro io_bgr symbol
	__WORD_MEM
	__STRUCT_TYPE_B
		__UCHAR(	BGRH)
		__UCHAR(	BGRL)
	__STRUCT_TYPE_E(byte)
#endm

/*********************/
/* structure of ADC1 */
/*********************/
#macro io_adc1 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	AD  ,1)
		__UCHARBIT_NONAME(   1)
		__UCHARBIT(	ADMV,1)
		__UCHARBIT(	ADI ,1)
		__UCHARBIT_NONAME(   4)
	__STRUCT_TYPE_E(bit)
#endm

/*********************/
/* structure of ADC2 */
/*********************/
#macro io_adc2 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT_NONAME(   1)
		__UCHARBIT(	EXT ,1)
		__UCHARBIT_NONAME(   1)
		__UCHARBIT(	ADIE,1)
		__UCHARBIT(	ADCK,1)
		__UCHARBIT_NONAME(   3)
	__STRUCT_TYPE_E(bit)
#endm

/*********************/
/* structure of ADD  */
/*********************/
#macro io_add symbol
	__WORD_MEM
	__STRUCT_TYPE_B
		__USHORTBIT(	DATA10,10)
		__USHORTBIT_NONAME(     6)
	__STRUCT_TYPE_E(bit)
#endm

/*********************/
/* structure of ADEN */
/*********************/
#macro io_aden symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	ADE0,1)
		__UCHARBIT(	ADE1,1)
		__UCHARBIT(	ADE2,1)
		__UCHARBIT(	ADE3,1)
		__UCHARBIT(	ADE4,1)
		__UCHARBIT(	ADE5,1)
		__UCHARBIT(	ADE6,1)
		__UCHARBIT(	ADE7,1)
	__STRUCT_TYPE_E(bit)
#endm

/*********************/
/* structure of SMR  */
/*********************/
#macro io_smr symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	SST ,1)
		__UCHARBIT(	BDS ,1)
		__UCHARBIT_NONAME(   2)
		__UCHARBIT(	SOE ,1)
		__UCHARBIT(	SCKE,1)
		__UCHARBIT(	SIOE,1)
		__UCHARBIT(	SIOF,1)
	__STRUCT_TYPE_E(bit)
#endm

/*********************/
/* structure of TCP1 */
/*********************/
#macro io_tcp1 symbol
	__WORD_MEM
	__STRUCT_TYPE_B
		__UCHAR(	TCPH1)
		__UCHAR(	TCPL1)
	__STRUCT_TYPE_E(byte)
#endm

/*********************/
/* structure of TCSL */
/*********************/
#macro io_tcsl symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	TCSEL,1)
		__UCHARBIT_NONAME(    7)
	__STRUCT_TYPE_E(bit)
#endm

/*********************/
/* structure of XCRS */
/*********************/
#macro io_xcrs symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	XTAL ,1)
		__UCHARBIT(	XCRST,1)
		__UCHARBIT(	KLCR ,1)
		__UCHARBIT(	XCRIE,1)
		__UCHARBIT(	XCRI ,1)
		__UCHARBIT_NONAME(    3)
	__STRUCT_TYPE_E(bit)
#endm

/**********************/
/* structure of PUL0  */
/**********************/
#macro io_pul0 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	PUL00,1)
		__UCHARBIT(	PUL01,1)
		__UCHARBIT(	PUL02,1)
		__UCHARBIT(	PUL03,1)
		__UCHARBIT(	PUL04,1)
		__UCHARBIT(	PUL05,1)
		__UCHARBIT(	PUL06,1)
		__UCHARBIT(	PUL07,1)
	__STRUCT_TYPE_E(bit)
#endm

/**********************/
/* structure of PUL1  */
/**********************/
#macro io_pul1 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	PUL10,1)
		__UCHARBIT(	PUL11,1)
		__UCHARBIT(	PUL12,1)
		__UCHARBIT(	PUL13,1)
		__UCHARBIT(	PUL14,1)
		__UCHARBIT(	PUL15,1)
		__UCHARBIT(	PUL16,1)
		__UCHARBIT(	PUL17,1)
	__STRUCT_TYPE_E(bit)
#endm

/**********************/
/* structure of PUL2  */
/**********************/
#macro io_pul2 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	PUL20,1)
		__UCHARBIT(	PUL21,1)
		__UCHARBIT(	PUL22,1)
		__UCHARBIT(	PUL23,1)
		__UCHARBIT_NONAME(    4)
	__STRUCT_TYPE_E(bit)
#endm

/**********************/
/* structure of PUL3  */
/**********************/
#macro io_pul3 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	PUL30,1)
		__UCHARBIT_NONAME(    7)
	__STRUCT_TYPE_E(bit)
#endm

/**********************/
/* structure of FMCS  */
/**********************/
#macro io_fmcs __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT_NONAME(      4)
		__UCHARBIT(	RDY   , 1)
		__UCHARBIT(	WE    , 1)
		__UCHARBIT(	RDYINT, 1)
		__UCHARBIT(	INTE  , 1)
	__STRUCT_TYPE_E(bit)
#endm
