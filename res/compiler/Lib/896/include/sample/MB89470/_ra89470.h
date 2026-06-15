/*
 MB89470 Series I/O register declaration file V30L08R01
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
		__UCHARBIT_NONAME(   2)
		__UCHARBIT(	SCS ,1)
		__UCHARBIT_NONAME(   4)
		__UCHARBIT(	SCM ,1)
	__STRUCT_TYPE_E(bit)
#endm

/*********************/
/* structure of STBC */
/*********************/
#macro io_stbc symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT_NONAME(   3)
		__UCHARBIT(	TMD ,1)
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
/* structure of WPCR */
/*********************/
#macro io_wpcr symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	WCLR,1)
		__UCHARBIT_NONAME(   5)
		__UCHARBIT(	WIE, 1)
		__UCHARBIT(	WIF, 1)
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
		__UCHARBIT_NONAME(   1)
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
		__UCHARBIT_NONAME(   5)
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
/* structure of BUZR */
/*********************/
#macro io_buzr symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	BZ  ,3)
		__UCHARBIT_NONAME(   5)
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
		__UCHARBIT_NONAME(   3)
	__STRUCT_TYPE_E(bit)
#endm

/*********************/
/* structure of T2CR */
/*********************/
#macro io_t2cr symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	T2STR ,1)
		__UCHARBIT(	T2STP ,1)
		__UCHARBIT_NONAME(     4)
		__UCHARBIT(	T2IE  ,1)
		__UCHARBIT(	T2IF  ,1)
	__STRUCT_TYPE_E(bit)
#endm

/*********************/
/* structure of T1CR */
/*********************/
#macro io_t1cr symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	T1STR ,1)
		__UCHARBIT(	T1STP ,1)
		__UCHARBIT_NONAME(     4)
		__UCHARBIT(	T1IE  ,1)
		__UCHARBIT(	T1IF  ,1)
	__STRUCT_TYPE_E(bit)
#endm

/********************/
/* structure of TDR */
/********************/
#macro io_tdr symbol
	__WORD_MEM
	__STRUCT_TYPE_B
		__UCHAR(	TDR2)
		__UCHAR(	TDR1)
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
		__UCHARBIT(	ADMD,1)
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
/* structure of ADER */
/*********************/
#macro io_ader symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	ADER0,1)
		__UCHARBIT(	ADER1,1)
		__UCHARBIT(	ADER2,1)
		__UCHARBIT(	ADER3,1)
		__UCHARBIT(	ADER4,1)
		__UCHARBIT(	ADER5,1)
		__UCHARBIT(	ADER6,1)
		__UCHARBIT(	ADER7,1)
	__STRUCT_TYPE_E(bit)
#endm

/*********************/
/* structure of SMC1 */
/*********************/
#macro io_smc1 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	CLK ,3)
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
		__UCHARBIT(	EIE3,1)
		__UCHARBIT_NONAME(   2)
		__UCHARBIT(	EIR3,1)
	__STRUCT_TYPE_E(bit)
#endm

/*********************/
/* structure of EIE2 */
/*********************/
#macro io_eie2 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	IE20,1)
		__UCHARBIT(	IE21,1)
		__UCHARBIT(	IE22,1)
		__UCHARBIT(	IE23,1)
		__UCHARBIT(	IE24,1)
		__UCHARBIT_NONAME(   3)
	__STRUCT_TYPE_E(bit)
#endm

/*********************/
/* structure of EIF2 */
/*********************/
#macro io_eif2 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	IF20,1)
		__UCHARBIT_NONAME(   7)
	__STRUCT_TYPE_E(bit)
#endm

/*********************/
/* structure of PCR1 */
/*********************/
#macro io_pcr1 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	BF ,1)
		__UCHARBIT(	IR ,1)
		__UCHARBIT(	UF ,1)
		__UCHARBIT_NONAME(  2)
		__UCHARBIT(	IE ,1)
		__UCHARBIT_NONAME(  1)
		__UCHARBIT(	EN ,1)
	__STRUCT_TYPE_E(bit)
#endm

/*********************/
/* structure of PCR2 */
/*********************/
#macro io_pcr2 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	W  ,3)
		__UCHARBIT(	C  ,2)
		__UCHARBIT(	TO ,1)
		__UCHARBIT(	RM ,1)
		__UCHARBIT(	FC ,1)
	__STRUCT_TYPE_E(bit)
#endm

/*********************/
/* structure of CNTR */
/*********************/
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

/**********************/
/* structure of PURC0 */
/**********************/
#macro io_purc0 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	PUR00,1)
		__UCHARBIT(	PUR01,1)
		__UCHARBIT(	PUR02,1)
		__UCHARBIT(	PUR03,1)
		__UCHARBIT(	PUR04,1)
		__UCHARBIT(	PUR05,1)
		__UCHARBIT(	PUR06,1)
		__UCHARBIT(	PUR07,1)
	__STRUCT_TYPE_E(bit)
#endm

/**********************/
/* structure of PURC1 */
/**********************/
#macro io_purc1 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	PUR10,1)
		__UCHARBIT(	PUR11,1)
		__UCHARBIT(	PUR12,1)
		__UCHARBIT(	PUR13,1)
		__UCHARBIT(	PUR14,1)
		__UCHARBIT(	PUR15,1)
		__UCHARBIT(	PUR16,1)
		__UCHARBIT(	PUR17,1)
	__STRUCT_TYPE_E(bit)
#endm

/**********************/
/* structure of PURC2 */
/**********************/
#macro io_purc2 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	PUR20,1)
		__UCHARBIT(	PUR21,1)
		__UCHARBIT(	PUR22,1)
		__UCHARBIT(	PUR23,1)
		__UCHARBIT(	PUR24,1)
		__UCHARBIT(	PUR25,1)
		__UCHARBIT(	PUR26,1)
		__UCHARBIT(	PUR27,1)
	__STRUCT_TYPE_E(bit)
#endm

/**********************/
/* structure of PURC3 */
/**********************/
#macro io_purc3 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	PUR30,1)
		__UCHARBIT(	PUR31,1)
		__UCHARBIT(	PUR32,1)
		__UCHARBIT(	PUR33,1)
		__UCHARBIT(	PUR34,1)
		__UCHARBIT(	PUR35,1)
		__UCHARBIT(	PUR36,1)
		__UCHARBIT_NONAME(    1)
	__STRUCT_TYPE_E(bit)
#endm

/**********************/
/* structure of PURC5 */
/**********************/
#macro io_purc5 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	PUR50,1)
		__UCHARBIT(	PUR51,1)
		__UCHARBIT(	PUR52,1)
		__UCHARBIT(	PUR53,1)
		__UCHARBIT(	PUR54,1)
		__UCHARBIT_NONAME(    3)
	__STRUCT_TYPE_E(bit)
#endm
