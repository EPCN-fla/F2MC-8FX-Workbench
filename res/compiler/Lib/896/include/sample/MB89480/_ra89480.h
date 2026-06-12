/*
 MB89480 Series I/O register declaration file V30L08R03
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
		__UCHARBIT_NONAME(   6)
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
		__UCHARBIT(	IE25,1)
		__UCHARBIT(	IE26,1)
		__UCHARBIT(	IE27,1)
	__STRUCT_TYPE_E(bit)
#endm

/*********************/
/* structure of EIF2 */
/*********************/
#macro io_eif2 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	IF20,1)
		__UCHARBIT_NONAME(  7)
	__STRUCT_TYPE_E(bit)
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
		__UCHARBIT_NONAME(    4)
		__UCHARBIT(	ADER4,1)
		__UCHARBIT(	ADER5,1)
		__UCHARBIT(	ADER6,1)
		__UCHARBIT(	ADER7,1)
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

/***********************/
/* structure of T12CR1 */
/***********************/
#macro io_t12cr1 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	T1STR ,1)
		__UCHARBIT(	T1STP ,1)
		__UCHARBIT_NONAME(     4)
		__UCHARBIT(	T1IE  ,1)
		__UCHARBIT(	T1IF  ,1)
	__STRUCT_TYPE_E(bit)
#endm

/***********************/
/* structure of T12CR2 */
/***********************/
#macro io_t12cr2 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	T2STR ,1)
		__UCHARBIT(	T2STP ,1)
		__UCHARBIT_NONAME(     4)
		__UCHARBIT(	T2IE  ,1)
		__UCHARBIT(	T2IF  ,1)
	__STRUCT_TYPE_E(bit)
#endm

/**********************/
/* structure of TDR12 */
/**********************/
#macro io_tdr12 symbol
	__WORD_MEM
	__STRUCT_TYPE_B
		__UCHAR(	TDR2)
		__UCHAR(	TDR1)
	__STRUCT_TYPE_E(byte)
#endm

/**********************/
/* structure of PPGC1 */
/**********************/
#macro io_ppgc1 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	HSC ,6)
		__UCHARBIT(	RCK ,2)
	__STRUCT_TYPE_E(bit)
#endm

/**********************/
/* structure of PPGC2 */
/**********************/
#macro io_ppgc2 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	SCL ,6)
		__UCHARBIT_NONAME(   1)
		__UCHARBIT(	RCEN,1)
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
/* structure of LCR1 */
/*********************/
#macro io_lcr1 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT_NONAME(   4)
		__UCHARBIT(	BK  ,1)
		__UCHARBIT(	VSEL,1)
		__UCHARBIT(	LCEN,1)
		__UCHARBIT(	CSS ,1)
	__STRUCT_TYPE_E(bit)
#endm

/*********************/
/* structure of LCR2 */
/*********************/
#macro io_lcr2 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	SEG00,1)
		__UCHARBIT(	SEG10,1)
		__UCHARBIT(	SEG11,1)
		__UCHARBIT(	SEG12,1)
		__UCHARBIT(	SEG13,1)
		__UCHARBIT(	SEG14,1)
		__UCHARBIT(	PSEL ,1)
		__UCHARBIT_NONAME(    1)
	__STRUCT_TYPE_E(bit)
#endm

/*********************/
/* structure of VRAM */
/*********************/
#macro io_vram symbol
	__WORD_MEM_A(8)
	__BYTE_MEM_A(16)
	__STRUCT_TYPE_UNION
		__UCHARBIT_COM01( SEG0 ,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG1 ,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG2 ,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG3 ,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG4 ,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG5 ,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG6 ,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG7 ,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG8 ,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG9 ,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG10,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG11,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG12,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG13,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG14,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG15,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG16,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG17,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG18,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG19,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG20,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG21,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG22,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG23,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG24,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG25,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG26,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG27,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG28,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG29,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG30,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG31,2)
		__UCHARBIT_NONAME(      2)
	__STRUCT_TYPE_E(COM01)
	__STRUCT_TYPE_UNION
		__UCHARBIT_COM012(SEG0 ,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG1 ,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG2 ,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG3 ,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG4 ,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG5 ,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG6 ,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG7 ,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG8 ,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG9 ,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG10,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG11,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG12,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG13,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG14,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG15,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG16,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG17,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG18,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG19,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG20,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG21,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG22,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG23,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG24,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG25,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG26,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG27,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG28,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG29,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG30,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG31,3)
		__UCHARBIT_NONAME(      1)
	__STRUCT_TYPE_E(COM012)
	__STRUCT_TYPE_UNION
		__UCHARBIT_COM0123(SEG0 ,4)
		__UCHARBIT_COM0123(SEG1 ,4)
		__UCHARBIT_COM0123(SEG2 ,4)
		__UCHARBIT_COM0123(SEG3 ,4)
		__UCHARBIT_COM0123(SEG4 ,4)
		__UCHARBIT_COM0123(SEG5 ,4)
		__UCHARBIT_COM0123(SEG6 ,4)
		__UCHARBIT_COM0123(SEG7 ,4)
		__UCHARBIT_COM0123(SEG8 ,4)
		__UCHARBIT_COM0123(SEG9 ,4)
		__UCHARBIT_COM0123(SEG10,4)
		__UCHARBIT_COM0123(SEG11,4)
		__UCHARBIT_COM0123(SEG12,4)
		__UCHARBIT_COM0123(SEG13,4)
		__UCHARBIT_COM0123(SEG14,4)
		__UCHARBIT_COM0123(SEG15,4)
		__UCHARBIT_COM0123(SEG16,4)
		__UCHARBIT_COM0123(SEG17,4)
		__UCHARBIT_COM0123(SEG18,4)
		__UCHARBIT_COM0123(SEG19,4)
		__UCHARBIT_COM0123(SEG20,4)
		__UCHARBIT_COM0123(SEG21,4)
		__UCHARBIT_COM0123(SEG22,4)
		__UCHARBIT_COM0123(SEG23,4)
		__UCHARBIT_COM0123(SEG24,4)
		__UCHARBIT_COM0123(SEG25,4)
		__UCHARBIT_COM0123(SEG26,4)
		__UCHARBIT_COM0123(SEG27,4)
		__UCHARBIT_COM0123(SEG28,4)
		__UCHARBIT_COM0123(SEG29,4)
		__UCHARBIT_COM0123(SEG30,4)
		__UCHARBIT_COM0123(SEG31,4)
	__STRUCT_TYPE_E(COM0123)
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
/* structure of PURC2 */
/**********************/
#macro io_purc2 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	PUR20,1)
		__UCHARBIT(	PUR21,1)
		__UCHARBIT(	PUR22,1)
		__UCHARBIT(	PUR23,1)
		__UCHARBIT_NONAME(    4)
	__STRUCT_TYPE_E(bit)
#endm
