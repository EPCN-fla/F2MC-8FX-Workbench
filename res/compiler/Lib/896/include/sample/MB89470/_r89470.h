/*
 MB89470 Series I/O register declaration file V30L08R01
 ALL RIGHTS RESERVED, COPYRIGHT (C) FUJITSU LIMITED 1998
 LICENSED MATERIAL - PROGRAM PROPERTY OF FUJITSU LIMITED
*/
#include "_f8ldef.h"


/*********************/
/* structure of PDR0 */
/*********************/
__UNION io_pdr0 __STRUCT_B
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
__STRUCT_E

/*********************/
/* structure of PDR1 */
/*********************/
__UNION io_pdr1 __STRUCT_B
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
__STRUCT_E

/*********************/
/* structure of PDR2 */
/*********************/
__UNION io_pdr2 __STRUCT_B
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
__STRUCT_E

/*********************/
/* structure of SYCC */
/*********************/
__UNION io_sycc __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT_NONAME(   2)
		__UCHARBIT(	SCS ,1)
		__UCHARBIT_NONAME(   4)
		__UCHARBIT(	SCM ,1)
	__STRUCT_TYPE_E(bit)
__STRUCT_E

/*********************/
/* structure of STBC */
/*********************/
__UNION io_stbc __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT_NONAME(   3)
		__UCHARBIT(	TMD ,1)
		__UCHARBIT(	RST ,1)
		__UCHARBIT(	SPL ,1)
		__UCHARBIT(	SLP ,1)
		__UCHARBIT(	STP ,1)
	__STRUCT_TYPE_E(bit)
__STRUCT_E

/*********************/
/* structure of TBTC */
/*********************/
__UNION io_tbtc __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	TBR ,1)
		__UCHARBIT_NONAME(   5)
		__UCHARBIT(	TBIE,1)
		__UCHARBIT(	TBOF,1)
	__STRUCT_TYPE_E(bit)
__STRUCT_E

/*********************/
/* structure of WPCR */
/*********************/
__UNION io_wpcr __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	WCLR,1)
		__UCHARBIT_NONAME(   5)
		__UCHARBIT(	WIE, 1)
		__UCHARBIT(	WIF, 1)
	__STRUCT_TYPE_E(bit)
__STRUCT_E

/*********************/
/* structure of PDR3 */
/*********************/
__UNION io_pdr3 __STRUCT_B
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
__STRUCT_E

/*********************/
/* structure of PDR4 */
/*********************/
__UNION io_pdr4 __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	P40 ,1)
		__UCHARBIT(	P41 ,1)
		__UCHARBIT(	P42 ,1)
		__UCHARBIT_NONAME(   5)
	__STRUCT_TYPE_E(bit)
__STRUCT_E

/*********************/
/* structure of RSFR */
/*********************/
__UNION io_rsfr __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT_NONAME(   4)
		__UCHARBIT(	SFTR,1)
		__UCHARBIT(	WDOG,1)
		__UCHARBIT(	ERST,1)
		__UCHARBIT(	PONR,1)
	__STRUCT_TYPE_E(bit)
__STRUCT_E

/*********************/
/* structure of BUZR */
/*********************/
__UNION io_buzr __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	BZ  ,3)
		__UCHARBIT_NONAME(   5)
	__STRUCT_TYPE_E(bit)
__STRUCT_E

/*********************/
/* structure of PDR5 */
/*********************/
__UNION io_pdr5 __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	P50 ,1)
		__UCHARBIT(	P51 ,1)
		__UCHARBIT(	P52 ,1)
		__UCHARBIT(	P53 ,1)
		__UCHARBIT(	P54 ,1)
		__UCHARBIT_NONAME(   3)
	__STRUCT_TYPE_E(bit)
__STRUCT_E

/*********************/
/* structure of T2CR */
/*********************/
__UNION io_t2cr __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	T2STR ,1)
		__UCHARBIT(	T2STP ,1)
		__UCHARBIT_NONAME(     4)
		__UCHARBIT(	T2IE  ,1)
		__UCHARBIT(	T2IF  ,1)
	__STRUCT_TYPE_E(bit)
__STRUCT_E

/*********************/
/* structure of T1CR */
/*********************/
__UNION io_t1cr __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	T1STR ,1)
		__UCHARBIT(	T1STP ,1)
		__UCHARBIT_NONAME(     4)
		__UCHARBIT(	T1IE  ,1)
		__UCHARBIT(	T1IF  ,1)
	__STRUCT_TYPE_E(bit)
__STRUCT_E

/********************/
/* structure of TDR */
/********************/
__UNION io_tdr __STRUCT_B
	__WORD_MEM
	__STRUCT_TYPE_B
		__UCHAR(	TDR2)
		__UCHAR(	TDR1)
	__STRUCT_TYPE_E(byte)
__STRUCT_E

/*********************/
/* structure of ADC1 */
/*********************/
__UNION io_adc1 __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	AD  ,1)
		__UCHARBIT_NONAME(   1)
		__UCHARBIT(	ADMV,1)
		__UCHARBIT(	ADI ,1)
		__UCHARBIT_NONAME(   4)
	__STRUCT_TYPE_E(bit)
__STRUCT_E

/*********************/
/* structure of ADC2 */
/*********************/
__UNION io_adc2 __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT_NONAME(   1)
		__UCHARBIT(	EXT ,1)
		__UCHARBIT(	ADMD,1)
		__UCHARBIT(	ADIE,1)
		__UCHARBIT(	ADCK,1)
		__UCHARBIT_NONAME(   3)
	__STRUCT_TYPE_E(bit)
__STRUCT_E

/*********************/
/* structure of ADD  */
/*********************/
__UNION io_add __STRUCT_B
	__WORD_MEM
	__STRUCT_TYPE_B
		__USHORTBIT(	DATA10,10)
		__USHORTBIT_NONAME(     6)
	__STRUCT_TYPE_E(bit)
__STRUCT_E

/*********************/
/* structure of ADER */
/*********************/
__UNION io_ader __STRUCT_B
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
__STRUCT_E

/*********************/
/* structure of SMC1 */
/*********************/
__UNION io_smc1 __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	CLK ,3)
		__UCHARBIT(	CL  ,1)
		__UCHARBIT(	SBL ,1)
		__UCHARBIT(	TDP ,1)
		__UCHARBIT(	PEN ,1)
		__UCHARBIT(	MD  ,1)
	__STRUCT_TYPE_E(bit)
__STRUCT_E

/*********************/
/* structure of SMC2 */
/*********************/
__UNION io_smc2 __STRUCT_B
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
__STRUCT_E

/********************/
/* structure of SSD */
/********************/
__UNION io_ssd __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT_NONAME(   3)
		__UCHARBIT(	TDRE,1)
		__UCHARBIT(	RDRF,1)
		__UCHARBIT(	FER ,1)
		__UCHARBIT(	OVE ,1)
		__UCHARBIT(	PER ,1)
	__STRUCT_TYPE_E(bit)
__STRUCT_E

/********************/
/* structure of EIC1*/
/********************/
__UNION io_eic1 __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	EIE0,1)
		__UCHARBIT_NONAME(   2)
		__UCHARBIT(	EIR0,1)
		__UCHARBIT(	EIE1,1)
		__UCHARBIT_NONAME(   2)
		__UCHARBIT(	EIR1,1)
	__STRUCT_TYPE_E(bit)
__STRUCT_E

/*********************/
/* structure of EIC2 */
/*********************/
__UNION io_eic2 __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	EIE2,1)
		__UCHARBIT_NONAME(   2)
		__UCHARBIT(	EIR2,1)
		__UCHARBIT(	EIE3,1)
		__UCHARBIT_NONAME(   2)
		__UCHARBIT(	EIR3,1)
	__STRUCT_TYPE_E(bit)
__STRUCT_E

/*********************/
/* structure of EIE2 */
/*********************/
__UNION io_eie2 __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	IE20,1)
		__UCHARBIT(	IE21,1)
		__UCHARBIT(	IE22,1)
		__UCHARBIT(	IE23,1)
		__UCHARBIT(	IE24,1)
		__UCHARBIT_NONAME(   3)
	__STRUCT_TYPE_E(bit)
__STRUCT_E

/*********************/
/* structure of EIF2 */
/*********************/
__UNION io_eif2 __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	IF20,1)
		__UCHARBIT_NONAME(   7)
	__STRUCT_TYPE_E(bit)
__STRUCT_E

/*********************/
/* structure of PCR1 */
/*********************/
__UNION io_pcr1 __STRUCT_B
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
__STRUCT_E

/*********************/
/* structure of PCR2 */
/*********************/
__UNION io_pcr2 __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	W  ,3)
		__UCHARBIT(	C  ,2)
		__UCHARBIT(	TO ,1)
		__UCHARBIT(	RM ,1)
		__UCHARBIT(	FC ,1)
	__STRUCT_TYPE_E(bit)
__STRUCT_E

/*********************/
/* structure of CNTR */
/*********************/
__UNION io_cntr __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	TIE ,1)
		__UCHARBIT(	OE  ,1)
		__UCHARBIT(	TIR ,1)
		__UCHARBIT(	TPE ,1)
		__UCHARBIT_NONAME(   3)
		__UCHARBIT(	PTX ,1)
	__STRUCT_TYPE_E(bit)
__STRUCT_E

/**********************/
/* structure of PURC0 */
/**********************/
__UNION io_purc0 __STRUCT_B
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
__STRUCT_E

/**********************/
/* structure of PURC1 */
/**********************/
__UNION io_purc1 __STRUCT_B
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
__STRUCT_E

/**********************/
/* structure of PURC2 */
/**********************/
__UNION io_purc2 __STRUCT_B
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
__STRUCT_E

/**********************/
/* structure of PURC3 */
/**********************/
__UNION io_purc3 __STRUCT_B
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
__STRUCT_E

/**********************/
/* structure of PURC5 */
/**********************/
__UNION io_purc5 __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	PUR50,1)
		__UCHARBIT(	PUR51,1)
		__UCHARBIT(	PUR52,1)
		__UCHARBIT(	PUR53,1)
		__UCHARBIT(	PUR54,1)
		__UCHARBIT_NONAME(    3)
	__STRUCT_TYPE_E(bit)
__STRUCT_E
