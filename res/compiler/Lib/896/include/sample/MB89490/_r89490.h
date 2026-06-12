/*
 MB89490 Series I/O register declaration file V30L08R03
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
		__UCHARBIT(	P37 ,1)
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
/* structure of PDR4 */
/*********************/
__UNION io_pdr4 __STRUCT_B
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
/* structure of PDR6 */
/*********************/
__UNION io_pdr6 __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	P60 ,1)
		__UCHARBIT(	P61 ,1)
		__UCHARBIT(	P62 ,1)
		__UCHARBIT(	P63 ,1)
		__UCHARBIT(	P64 ,1)
		__UCHARBIT(	P65 ,1)
		__UCHARBIT(	P66 ,1)
		__UCHARBIT(	P67 ,1)
	__STRUCT_TYPE_E(bit)
__STRUCT_E

/*********************/
/* structure of PDR7 */
/*********************/
__UNION io_pdr7 __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	P70 ,1)
		__UCHARBIT(	P71 ,1)
		__UCHARBIT(	P72 ,1)
		__UCHARBIT(	P73 ,1)
		__UCHARBIT(	P74 ,1)
		__UCHARBIT(	P75 ,1)
		__UCHARBIT(	P76 ,1)
		__UCHARBIT(	P77 ,1)
	__STRUCT_TYPE_E(bit)
__STRUCT_E

/*********************/
/* structure of PDR8 */
/*********************/
__UNION io_pdr8 __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	P80 ,1)
		__UCHARBIT(	P81 ,1)
		__UCHARBIT(	P82 ,1)
		__UCHARBIT(	P83 ,1)
		__UCHARBIT(	P84 ,1)
		__UCHARBIT_NONAME(   3)
	__STRUCT_TYPE_E(bit)
__STRUCT_E

/********************/
/* structure of EIC0*/
/********************/
__UNION io_eic0 __STRUCT_B
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

/********************/
/* structure of EIC1*/
/********************/
__UNION io_eic1 __STRUCT_B
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
/* structure of EIC2 */
/*********************/
__UNION io_eic2 __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	EIE4,1)
		__UCHARBIT_NONAME(   2)
		__UCHARBIT(	EIR4,1)
		__UCHARBIT(	EIE5,1)
		__UCHARBIT_NONAME(   2)
		__UCHARBIT(	EIR5,1)
	__STRUCT_TYPE_E(bit)
__STRUCT_E

/*********************/
/* structure of EIC3 */
/*********************/
__UNION io_eic3 __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	EIE6,1)
		__UCHARBIT_NONAME(   2)
		__UCHARBIT(	EIR6,1)
		__UCHARBIT(	EIE7,1)
		__UCHARBIT_NONAME(   2)
		__UCHARBIT(	EIR7,1)
	__STRUCT_TYPE_E(bit)
__STRUCT_E

/*********************/
/* structure of EIE1 */
/*********************/
__UNION io_eie1 __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	IE10,1)
		__UCHARBIT(	IE11,1)
		__UCHARBIT(	IE12,1)
		__UCHARBIT(	IE13,1)
		__UCHARBIT(	IE14,1)
		__UCHARBIT(	IE15,1)
		__UCHARBIT(	IE16,1)
		__UCHARBIT(	IE17,1)
	__STRUCT_TYPE_E(bit)
__STRUCT_E

/*********************/
/* structure of EIF1 */
/*********************/
__UNION io_eif1 __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	IF10,1)
		__UCHARBIT_NONAME(  7)
	__STRUCT_TYPE_E(bit)
__STRUCT_E

/*********************/
/* structure of SMR  */
/*********************/
__UNION io_smr __STRUCT_B
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
__STRUCT_E

/***********************/
/* structure of T01CR0 */
/***********************/
__UNION io_t01cr0 __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	T1STR ,1)
		__UCHARBIT(	T1STP ,1)
		__UCHARBIT_NONAME(     4)
		__UCHARBIT(	T1IE  ,1)
		__UCHARBIT(	T1IF  ,1)
	__STRUCT_TYPE_E(bit)
__STRUCT_E

/***********************/
/* structure of T01CR1 */
/***********************/
__UNION io_t01cr1 __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	T2STR ,1)
		__UCHARBIT(	T2STP ,1)
		__UCHARBIT_NONAME(     4)
		__UCHARBIT(	T2IE  ,1)
		__UCHARBIT(	T2IF  ,1)
	__STRUCT_TYPE_E(bit)
__STRUCT_E

/**********************/
/* structure of TDR01 */
/**********************/
__UNION io_tdr01 __STRUCT_B
	__WORD_MEM
	__STRUCT_TYPE_B
		__UCHAR(	TDR1)
		__UCHAR(	TDR0)
	__STRUCT_TYPE_E(byte)
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
/* structure of ADC0 */
/*********************/
__UNION io_adc0 __STRUCT_B
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
/* structure of ADC1 */
/*********************/
__UNION io_adc1 __STRUCT_B
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

/**********************/
/* structure of CNTR0 */
/**********************/
__UNION io_cntr0 __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	TIE0,1)
		__UCHARBIT(	OE0 ,1)
		__UCHARBIT(	TIR0,1)
		__UCHARBIT(	TPE0,1)
		__UCHARBIT_NONAME(   3)
		__UCHARBIT(	PTX0,1)
	__STRUCT_TYPE_E(bit)
__STRUCT_E

/*********************/
/* structure of SMC0 */
/*********************/
__UNION io_smc0 __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT_NONAME(   3)
		__UCHARBIT(	CL  ,1)
		__UCHARBIT(	SBL ,1)
		__UCHARBIT(	TDP ,1)
		__UCHARBIT(	PEN ,1)
		__UCHARBIT(	MD  ,1)
	__STRUCT_TYPE_E(bit)
__STRUCT_E

/*********************/
/* structure of SMC1 */
/*********************/
__UNION io_smc1 __STRUCT_B
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

/**********************/
/* structure of CNTR1 */
/**********************/
__UNION io_cntr1 __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	TIE1,1)
		__UCHARBIT(	OE1 ,1)
		__UCHARBIT(	TIR1,1)
		__UCHARBIT(	TPE1,1)
		__UCHARBIT_NONAME(   3)
		__UCHARBIT(	PTX1,1)
	__STRUCT_TYPE_E(bit)
__STRUCT_E

/*********************/
/* structure of IBSR */
/*********************/
__UNION io_ibsr __STRUCT_B
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
__STRUCT_E

/*********************/
/* structure of IBCR */
/*********************/
__UNION io_ibcr __STRUCT_B
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
__STRUCT_E

/*********************/
/* structure of ICCR */
/*********************/
__UNION io_iccr __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT_NONAME(    5)
		__UCHARBIT(	EN   ,1)
		__UCHARBIT_NONAME(    1)
		__UCHARBIT(	DMBP ,1)
	__STRUCT_TYPE_E(bit)
__STRUCT_E

/*********************/
/* structure of IADR */
/*********************/
__UNION io_iadr __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	A   ,7)
		__UCHARBIT_NONAME(   1)
	__STRUCT_TYPE_E(bit)
__STRUCT_E

/**********************/
/* structure of PLLCR */
/**********************/
__UNION io_pllcr __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT_NONAME(    2)
		__UCHARBIT(	SBCS ,1)
		__UCHARBIT_NONAME(    5)
	__STRUCT_TYPE_E(bit)
__STRUCT_E

/*********************/
/* structure of RMC  */
/*********************/
__UNION io_rmc __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT_NONAME(     4)
		__UCHARBIT(	RMPOL ,1)
		__UCHARBIT(	RMISEL,1)
		__UCHARBIT(	EDGSEL,1)
		__UCHARBIT(	RMCLR ,1)
	__STRUCT_TYPE_E(bit)
__STRUCT_E

/*********************/
/* structure of RMS  */
/*********************/
__UNION io_rms __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	RMEMP ,1)
		__UCHARBIT(	RMFUL ,1)
		__UCHARBIT(	RMOE  ,1)
		__UCHARBIT(	FCDV  ,1)
		__UCHARBIT(	NCDL  ,1)
		__UCHARBIT(	NCDH  ,1)
		__UCHARBIT(	RMSIG ,1)
		__UCHARBIT(	COF   ,1)
	__STRUCT_TYPE_E(bit)
__STRUCT_E

/*********************/
/* structure of RMD  */
/*********************/
__UNION io_rmd __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	CF   ,3)
		__UCHARBIT(	RMDS ,1)
		__UCHARBIT_NONAME(    4)
	__STRUCT_TYPE_E(bit)
__STRUCT_E

/*********************/
/* structure of RMCI */
/*********************/
__UNION io_rmci __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	RIF     ,1)
		__UCHARBIT(	RIE     ,1)
		__UCHARBIT(	RMIST   ,1)
		__UCHARBIT_NONAME(       5)
	__STRUCT_TYPE_E(bit)
__STRUCT_E

/*********************/
/* structure of LCD  */
/*********************/
__UNION io_lcd __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT_NONAME(       4)
		__UCHARBIT(	BK      ,1)
		__UCHARBIT(	VSEL    ,1)
		__UCHARBIT(	LCEN    ,1)
		__UCHARBIT(	CSS     ,1)
	__STRUCT_TYPE_E(bit)
__STRUCT_E

/*********************/
/* structure of VRAM */
/*********************/
__UNION io_vram __STRUCT_B
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
		__UCHARBIT(	PUR37,1)
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

/**********************/
/* structure of PURC6 */
/**********************/
__UNION io_purc6 __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	PUR60,1)
		__UCHARBIT(	PUR61,1)
		__UCHARBIT(	PUR62,1)
		__UCHARBIT(	PUR63,1)
		__UCHARBIT(	PUR64,1)
		__UCHARBIT(	PUR65,1)
		__UCHARBIT(	PUR66,1)
		__UCHARBIT(	PUR67,1)
	__STRUCT_TYPE_E(bit)
__STRUCT_E

/**********************/
/* structure of PURC7 */
/**********************/
__UNION io_purc7 __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	PUR70,1)
		__UCHARBIT(	PUR71,1)
		__UCHARBIT(	PUR72,1)
		__UCHARBIT(	PUR73,1)
		__UCHARBIT(	PUR74,1)
		__UCHARBIT(	PUR75,1)
		__UCHARBIT(	PUR76,1)
		__UCHARBIT(	PUR77,1)
	__STRUCT_TYPE_E(bit)
__STRUCT_E

/**********************/
/* structure of PURC8 */
/**********************/
__UNION io_purc8 __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	PUR80,1)
		__UCHARBIT(	PUR81,1)
		__UCHARBIT(	PUR82,1)
		__UCHARBIT_NONAME(    5)
	__STRUCT_TYPE_E(bit)
__STRUCT_E

/**********************/
/* structure of FMCS  */
/**********************/
__UNION io_fmcs __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT_NONAME(      4)
		__UCHARBIT(	RDY   , 1)
		__UCHARBIT(	WE    , 1)
		__UCHARBIT(	RDYINT, 1)
		__UCHARBIT(	INTE  , 1)
	__STRUCT_TYPE_E(bit)
__STRUCT_E
