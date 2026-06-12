/*
 MB895xx Series I/O register declaration file V30L08
 ALL RIGHTS RESERVED, COPYRIGHT (C) FUJITSU LIMITED 1998
 LICENSED MATERIAL - PROGRAM PROPERTY OF FUJITSU LIMITED
*/
#include "_ffmc8ls.h"
#include "_f8ldef.h"

/******************************************************/
/* Sample program for I/O variables of A/D converter. */
/******************************************************/
/* structure of ADC1 */
#if defined(__CPU_MB89530_SERIES) || defined(__CPU_MB89550_SERIES) || \
    defined(__CPU_MB89560_SERIES) || defined(__CPU_MB89570_SERIES)
#macro io_adc1 symbol
	__BYTE_MEM
#if defined(__CPU_MB89530_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	AD  ,1)
		__UCHARBIT(	SIFM,1)
		__UCHARBIT(	ADMV,1)
		__UCHARBIT(	ADI ,1)
		__UCHARBIT(	ANS ,3)
		__UCHARBIT_NONAME(   1)
	__STRUCT_TYPE_E(bit)
#elif defined(__CPU_MB89550_SERIES) || defined(__CPU_MB89570_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	AD  ,1)
		__UCHARBIT_NONAME(   1)
		__UCHARBIT(	ADMV,1)
		__UCHARBIT(	ADI ,1)
		__UCHARBIT(	ANS ,4)
	__STRUCT_TYPE_E(bit)
#else
	__STRUCT_TYPE_B
		__UCHARBIT(	AD  ,1)
		__UCHARBIT_NONAME(   1)
		__UCHARBIT(	ADMV,1)
		__UCHARBIT(	ADI ,1)
		__UCHARBIT(	ANS ,3)
		__UCHARBIT_NONAME(   1)
	__STRUCT_TYPE_E(bit)
#endif
#endm
#endif

/* structure of ADC2 */
#if defined(__CPU_MB89530_SERIES) || defined(__CPU_MB89550_SERIES) || \
    defined(__CPU_MB89560_SERIES) || defined(__CPU_MB89570_SERIES)
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
#endif

/* structure of ADEN */
#if defined(__CPU_MB89550_SERIES) || defined(__CPU_MB89560_SERIES)
#macro io_aden symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	ADE0 ,1)
		__UCHARBIT(	ADE1 ,1)
		__UCHARBIT(	ADE2 ,1)
		__UCHARBIT(	ADE3 ,1)
		__UCHARBIT(	ADE4 ,1)
		__UCHARBIT(	ADE5 ,1)
		__UCHARBIT(	ADE6 ,1)
		__UCHARBIT(	ADE7 ,1)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of ADEN1 */
#if defined(__CPU_MB89570_SERIES)
#macro io_aden1 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	ADE0 ,1)
		__UCHARBIT(	ADE1 ,1)
		__UCHARBIT(	ADE2 ,1)
		__UCHARBIT(	ADE3 ,1)
		__UCHARBIT_NONAME(    4)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of ADEN2 */
#if defined(__CPU_MB89570_SERIES)
#macro io_aden2 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	ADE4 ,1)
		__UCHARBIT(	ADE5 ,1)
		__UCHARBIT(	ADE6 ,1)
		__UCHARBIT(	ADE7 ,1)
		__UCHARBIT(	ADE8 ,1)
		__UCHARBIT(	ADE9 ,1)
		__UCHARBIT(	ADE10,1)
		__UCHARBIT(	ADE11,1)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of ADD */
#if defined(__CPU_MB89530_SERIES) || defined(__CPU_MB89550_SERIES) || \
    defined(__CPU_MB89560_SERIES)
#macro io_add symbol
	__UCHAR   (	ADDL)
	__UCHARBIT(	ADDH,2)
	__UCHARBIT_NONAME(   6)
#endm
#endif

/* structure of ADD */
#if defined(__CPU_MB89570_SERIES)
#macro io_add symbol
	__WORD_MEM
	__STRUCT_TYPE_B
		__USHORTBIT(	DATA10,10)
		__USHORTBIT_NONAME(     6)
	__STRUCT_TYPE_E(bit)
#endm
#endif


/****************************************************************/
/* Sample program for data and control registers of 12-bit PPG. */
/****************************************************************/
/* structure of PPGC1,2 */
#if defined(__CPU_MB89530_SERIES)
#macro io_ppgc symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	HSC ,6)
		__UCHARBIT(	RCK ,2)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of PRL21,11 */
#if defined(__CPU_MB89530_SERIES)
#macro io_prl1 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	HSC ,6)
		__UCHARBIT_NONAME(   2)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of PRL22,12 */
#if defined(__CPU_MB89530_SERIES)
#macro io_prl2 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	SCL ,6)
		__UCHARBIT_NONAME(   1)
		__UCHARBIT(	RCEN,1)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of PRL23,13 */
#if defined(__CPU_MB89530_SERIES)
#macro io_prl3 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	SCL ,6)
		__UCHARBIT_NONAME(   2)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of RCR21 */
#if defined(__CPU_MB89560_SERIES)
#macro io_rcr21 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	HSC ,6)
		__UCHARBIT(	RCK ,2)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of RCR22 */
#if defined(__CPU_MB89560_SERIES)
#macro io_rcr22 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	HSC ,6)
		__UCHARBIT_NONAME(   2)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of RCR23 */
#if defined(__CPU_MB89560_SERIES)
#macro io_rcr23 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	SCL ,6)
		__UCHARBIT_NONAME(   1)
		__UCHARBIT(	RCEN,1)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of RCR24 */
#if defined(__CPU_MB89560_SERIES)
#macro io_rcr24 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	SCL ,6)
		__UCHARBIT_NONAME(   2)
	__STRUCT_TYPE_E(bit)
#endm
#endif


/******************************************************************/
/* Sample program for data and control registers of 16-bit timer. */
/******************************************************************/
/* structure of TMCR */
#if defined(__CPU_MB89530_SERIES) || defined(__CPU_MB89550_SERIES) || \
    defined(__CPU_MB89570_SERIES)
#macro io_tmcr symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	TCS  ,1)
		__UCHARBIT(	TCIE ,1)
		__UCHARBIT(	TCEF ,1)
		__UCHARBIT(	TCS01,2)
		__UCHARBIT(	TCR  ,1)
		__UCHARBIT_NONAME(    2)
	__STRUCT_TYPE_E(bit)
#endm
#endif


/******************************************************/
/* Sample program for control registers of 6-bit PPG. */
/******************************************************/
/* structure of RCR1 */
#if defined(__CPU_MB89530_SERIES) || defined(__CPU_MB89550_SERIES) || \
    defined(__CPU_MB89560_SERIES)
#macro io_rcr1 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	HSC ,6)
		__UCHARBIT(	RCK ,2)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of RCR2 */
#if defined(__CPU_MB89530_SERIES) || defined(__CPU_MB89550_SERIES) || \
    defined(__CPU_MB89560_SERIES)
#macro io_rcr2 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	SCL ,6)
		__UCHARBIT_NONAME(   1)
		__UCHARBIT(	RCEN,1)
	__STRUCT_TYPE_E(bit)
#endm
#endif


/********************************************************************/
/* Sample program for data and control registers of 8/16-bit timer. */
/********************************************************************/
/* structure of T1CR */
#if defined(__CPU_MB89550_SERIES) || defined(__CPU_MB89560_SERIES) || \
    defined(__CPU_MB89570_SERIES)
#macro io_t1cr symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	T1STR,1)
		__UCHARBIT(	T1STP,1)
		__UCHARBIT(	T1CS ,2)
		__UCHARBIT(	T1OS ,2)
		__UCHARBIT(	T1IE ,1)
		__UCHARBIT(	T1IF ,1)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of T2CR */
#if defined(__CPU_MB89550_SERIES) || defined(__CPU_MB89560_SERIES) || \
    defined(__CPU_MB89570_SERIES)
#macro io_t2cr symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	T2STR,1)
		__UCHARBIT(	T2STP,1)
		__UCHARBIT(	T2CS ,2)
		__UCHARBIT(	T2OS ,2)
		__UCHARBIT(	T2IE ,1)
		__UCHARBIT(	T2IF ,1)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of T12DR */
#if defined(__CPU_MB89550_SERIES) || defined(__CPU_MB89570_SERIES)
#macro io_t12dr symbol
	__WORD_MEM
	__STRUCT_TYPE_B
		__UCHAR(	T2DR)
		__UCHAR(	T1DR)
	__STRUCT_TYPE_E(bit)
#endm
#endif


/********************************************************/
/* Sample program for I/O variables of 8-bit PWM timer. */
/********************************************************/
/* structure of CNTR1 */
#if defined(__CPU_MB89530_SERIES) || defined(__CPU_MB89550_SERIES) || \
    defined(__CPU_MB89560_SERIES) || defined(__CPU_MB89580_SERIES) || \
    defined(__CPU_MB89590_SERIES)
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
#endif

/* structure of CNTR2 */
#if defined(__CPU_MB89530_SERIES) || defined(__CPU_MB89550_SERIES) || \
    defined(__CPU_MB89560_SERIES) || defined(__CPU_MB89580_SERIES) || \
    defined(__CPU_MB89590_SERIES)
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
#endif

/* structure of CNTR3 */
#if defined(__CPU_MB89530_SERIES) || defined(__CPU_MB89550_SERIES) || \
    defined(__CPU_MB89560_SERIES) || defined(__CPU_MB89580_SERIES) || \
    defined(__CPU_MB89590_SERIES)
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
#endif


/*******************************************************************/
/* Sample program for mode and data registers of 8-bit serial I/O. */
/*******************************************************************/
/* structure of SMR */
#if defined(__CPU_MB89530_SERIES) || defined(__CPU_MB89550_SERIES) || \
    defined(__CPU_MB89560_SERIES)
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
#endif


/******************************************************/
/* Sample program for I/O variables of D/A converter. */
/******************************************************/
/* structure of DACR */
#if defined(__CPU_MB89550_SERIES) || defined(__CPU_MB89570_SERIES)
#macro io_dacr symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	DAE1,1)
		__UCHARBIT(	DAE2,1)
		__UCHARBIT_NONAME(   6)
	__STRUCT_TYPE_E(bit)
#endm
#endif


/*****************************************************/
/* Sample program for control registers of I/O port. */
/*****************************************************/
/* structure of PDR0 */
#if defined(__CPU_MB89530_SERIES) || defined(__CPU_MB89550_SERIES) || \
    defined(__CPU_MB89560_SERIES) || defined(__CPU_MB89570_SERIES) || \
    defined(__CPU_MB89580_SERIES) || defined(__CPU_MB89590_SERIES)
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
#endif

/* structure of PDR1 */
#if defined(__CPU_MB89530_SERIES) || defined(__CPU_MB89550_SERIES) || \
    defined(__CPU_MB89560_SERIES) || defined(__CPU_MB89570_SERIES) || \
    defined(__CPU_MB89580_SERIES) || defined(__CPU_MB89590_SERIES)
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
#endif

/* structure of PDR2 */
#if defined(__CPU_MB89530_SERIES) || defined(__CPU_MB89550_SERIES) || \
    defined(__CPU_MB89560_SERIES) || defined(__CPU_MB89570_SERIES) || \
    defined(__CPU_MB89580_SERIES) || defined(__CPU_MB89590_SERIES)
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
#endif

/* structure of PDR3 */
#if defined(__CPU_MB89530_SERIES) || defined(__CPU_MB89550_SERIES) || \
    defined(__CPU_MB89560_SERIES) || defined(__CPU_MB89570_SERIES) || \
    defined(__CPU_MB89580_SERIES) || defined(__CPU_MB89590_SERIES)
#macro io_pdr3 symbol
	__BYTE_MEM
#if defined(__CPU_MB89530_SERIES) || defined(__CPU_MB89580_SERIES) || \
    defined(__CPU_MB89590_SERIES)
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
#elif defined(__CPU_MB89570_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	P30 ,1)
		__UCHARBIT(	P31 ,1)
		__UCHARBIT(	P32 ,1)
		__UCHARBIT(	P33 ,1)
		__UCHARBIT(	P34 ,1)
		__UCHARBIT(	P35 ,1)
		__UCHARBIT_NONAME(   2)
	__STRUCT_TYPE_E(bit)
#else
	__STRUCT_TYPE_B
		__UCHARBIT(	P30 ,1)
		__UCHARBIT(	P31 ,1)
		__UCHARBIT_NONAME(   6)
	__STRUCT_TYPE_E(bit)
#endif
#endm
#endif

/* structure of PDR4 */
#if defined(__CPU_MB89530_SERIES) || defined(__CPU_MB89550_SERIES) || \
    defined(__CPU_MB89560_SERIES) || defined(__CPU_MB89570_SERIES) || \
    defined(__CPU_MB89580_SERIES) || defined(__CPU_MB89590_SERIES)
#macro io_pdr4 symbol
	__BYTE_MEM
#if defined(__CPU_MB89570_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	P40 ,1)
		__UCHARBIT(	P41 ,1)
		__UCHARBIT(	P42 ,1)
		__UCHARBIT(	P43 ,1)
		__UCHARBIT_NONAME(   4)
	__STRUCT_TYPE_E(bit)
#else
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
#endif
#endm
#endif

/* structure of PDR5 */
#if defined(__CPU_MB89530_SERIES) || defined(__CPU_MB89550_SERIES) || \
    defined(__CPU_MB89560_SERIES) || defined(__CPU_MB89570_SERIES) || \
    defined(__CPU_MB89580_SERIES) || defined(__CPU_MB89590_SERIES)
#macro io_pdr5 symbol
	__BYTE_MEM
#if defined(__CPU_MB89570_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	P50 ,1)
		__UCHARBIT(	P51 ,1)
		__UCHARBIT(	P52 ,1)
		__UCHARBIT(	P53 ,1)
		__UCHARBIT(	P54 ,1)
		__UCHARBIT(	P55 ,1)
		__UCHARBIT(	P56 ,1)
		__UCHARBIT_NONAME(   1)
	__STRUCT_TYPE_E(bit)
#elif defined(__CPU_MB89580_SERIES) || defined(__CPU_MB89590_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	P50 ,1)
		__UCHARBIT(	P51 ,1)
		__UCHARBIT(	P52 ,1)
		__UCHARBIT(	P53 ,1)
		__UCHARBIT(	P54 ,1)
		__UCHARBIT_NONAME(   3)
	__STRUCT_TYPE_E(bit)
#else
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
#endif
#endm
#endif

/* structure of PDR6 */
#if defined(__CPU_MB89530_SERIES) || defined(__CPU_MB89550_SERIES) || \
    defined(__CPU_MB89560_SERIES) || defined(__CPU_MB89570_SERIES) || \
    defined(__CPU_MB89580_SERIES)
#macro io_pdr6 symbol
	__BYTE_MEM
#if defined(__CPU_MB89530_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	P60 ,1)
		__UCHARBIT(	P61 ,1)
		__UCHARBIT(	P62 ,1)
		__UCHARBIT(	P63 ,1)
		__UCHARBIT(	P64 ,1)
		__UCHARBIT_NONAME(   3)
	__STRUCT_TYPE_E(bit)
#elif defined(__CPU_MB89570_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	P60 ,1)
		__UCHARBIT(	P61 ,1)
		__UCHARBIT(	P62 ,1)
		__UCHARBIT(	P63 ,1)
		__UCHARBIT(	P64 ,1)
		__UCHARBIT(	P65 ,1)
		__UCHARBIT_NONAME(   2)
	__STRUCT_TYPE_E(bit)
#else
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
#endif
#endm
#endif

/* structure of PDR7 */
#if defined(__CPU_MB89550_SERIES) || defined(__CPU_MB89570_SERIES)
#macro io_pdr7 symbol
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
#endm
#endif

/* structure of PDR8 */
#if defined(__CPU_MB89550_SERIES) || defined(__CPU_MB89570_SERIES)
#macro io_pdr8 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	P80 ,1)
		__UCHARBIT(	P81 ,1)
		__UCHARBIT(	P82 ,1)
		__UCHARBIT(	P83 ,1)
		__UCHARBIT(	P84 ,1)
		__UCHARBIT(	P85 ,1)
		__UCHARBIT(	P86 ,1)
		__UCHARBIT(	P87 ,1)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of PDR9 */
#if defined(__CPU_MB89570_SERIES)
#macro io_pdr9 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	P90 ,1)
		__UCHARBIT(	P91 ,1)
		__UCHARBIT(	P92 ,1)
		__UCHARBIT_NONAME(   5)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of PDRA */
#if defined(__CPU_MB89570_SERIES)
#macro io_pdra symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	PA0 ,1)
		__UCHARBIT(	PA1 ,1)
		__UCHARBIT(	PA2 ,1)
		__UCHARBIT(	PA3 ,1)
		__UCHARBIT(	PA4 ,1)
		__UCHARBIT(	PA5 ,1)
		__UCHARBIT(	PA6 ,1)
		__UCHARBIT(	PA7 ,1)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of PDRB */
#if defined(__CPU_MB89570_SERIES)
#macro io_pdrb symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	PB0 ,1)
		__UCHARBIT(	PB1 ,1)
		__UCHARBIT(	PB2 ,1)
		__UCHARBIT(	PB3 ,1)
		__UCHARBIT(	PB4 ,1)
		__UCHARBIT(	PB5 ,1)
		__UCHARBIT(	PB6 ,1)
		__UCHARBIT(	PB7 ,1)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of DDR4 */
#if defined(__CPU_MB89530_SERIES) || defined(__CPU_MB89550_SERIES) || \
    defined(__CPU_MB89560_SERIES) || defined(__CPU_MB89580_SERIES) || \
    defined(__CPU_MB89590_SERIES)
#macro io_ddr4 symbol
	__BYTE_MEM
#if defined(__CPU_MB89530_SERIES) || defined(__CPU_MB89580_SERIES) || \
    defined(__CPU_MB89590_SERIES)
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
#else
	__STRUCT_TYPE_B
		__UCHARBIT(	P40 ,1)
		__UCHARBIT(	P41 ,1)
		__UCHARBIT(	P42 ,1)
		__UCHARBIT(	P43 ,1)
		__UCHARBIT(	P44 ,1)
		__UCHARBIT(	P45 ,1)
		__UCHARBIT_NONAME(   2)
	__STRUCT_TYPE_E(bit)
#endif
#endm
#endif

/* structure of DDR5 */
#if defined(__CPU_MB89570_SERIES) || defined(__CPU_MB89580_SERIES) || \
    defined(__CPU_MB89590_SERIES)
#macro io_ddr5 symbol
	__BYTE_MEM
#if defined(__CPU_MB89570_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	P50 ,1)
		__UCHARBIT(	P51 ,1)
		__UCHARBIT(	P52 ,1)
		__UCHARBIT(	P53 ,1)
		__UCHARBIT(	P54 ,1)
		__UCHARBIT(	P55 ,1)
		__UCHARBIT(	P56 ,1)
		__UCHARBIT_NONAME(   1)
	__STRUCT_TYPE_E(bit)
#else
	__STRUCT_TYPE_B
		__UCHARBIT(	P50 ,1)
		__UCHARBIT(	P51 ,1)
		__UCHARBIT_NONAME(   6)
	__STRUCT_TYPE_E(bit)
#endif
#endm
#endif

/* structure of DDR7 */
#if defined(__CPU_MB89570_SERIES)
#macro io_ddr7 symbol
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
#endm
#endif

/* structure of DDR8 */
#if defined(__CPU_MB89570_SERIES)
#macro io_ddr8 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	P80 ,1)
		__UCHARBIT(	P81 ,1)
		__UCHARBIT(	P82 ,1)
		__UCHARBIT(	P83 ,1)
		__UCHARBIT_NONAME(   1)
		__UCHARBIT(	P85 ,1)
		__UCHARBIT(	P86 ,1)
		__UCHARBIT(	P87 ,1)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of DDR9 */
#if defined(__CPU_MB89570_SERIES)
#macro io_ddr9 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	P90 ,1)
		__UCHARBIT(	P91 ,1)
		__UCHARBIT(	P92 ,1)
		__UCHARBIT_NONAME(   5)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of DDCR */
#if defined(__CPU_MB89530_SERIES)
#macro io_ddcr symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	DDC ,1)
		__UCHARBIT_NONAME(   7)
	__STRUCT_TYPE_E(bit)
#endm
#endif


/****************************************************************/
/* Sample program for I/O variables of inter IIC bus interface. */
/****************************************************************/
/* structure of IACR */
#if defined(__CPU_MB89530_SERIES)
#macro io_iacr symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	A0,1)
		__UCHARBIT(	A1,1)
		__UCHARBIT(	A2,1)
		__UCHARBIT_NONAME( 5)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of IBSR */
#if defined(__CPU_MB89530_SERIES) || defined(__CPU_MB89560_SERIES) || \
    defined(__CPU_MB89570_SERIES)
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
#endif

/* structure of IBCR */
#if defined(__CPU_MB89530_SERIES) || defined(__CPU_MB89560_SERIES) || \
    defined(__CPU_MB89570_SERIES)
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
#endif

/* structure of ICCR */
#if defined(__CPU_MB89530_SERIES) || defined(__CPU_MB89560_SERIES) || \
    defined(__CPU_MB89570_SERIES)
#macro io_iccr symbol
	__BYTE_MEM
#if defined(__CPU_MB89530_SERIES) || defined(__CPU_MB89570_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	CS012,3)
		__UCHARBIT(	CS34 ,2)
		__UCHARBIT(	EN   ,1)
		__UCHARBIT_NONAME(    1)
		__UCHARBIT(	DMBP ,1)
	__STRUCT_TYPE_E(bit)
#else 
	__STRUCT_TYPE_B
		__UCHARBIT(	CS012,3)
		__UCHARBIT(	CS34 ,2)
		__UCHARBIT(	EN   ,1)
		__UCHARBIT(	IBS  ,1)
		__UCHARBIT(	DMBP ,1)
	__STRUCT_TYPE_E(bit)
#endif
#endm
#endif

/* structure of IADR */
#if defined(__CPU_MB89530_SERIES) || defined(__CPU_MB89560_SERIES) || \
    defined(__CPU_MB89570_SERIES)
#macro io_iadr symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	A   ,7)
		__UCHARBIT_NONAME(   1)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of ITCR */
#if defined(__CPU_MB89570_SERIES)
#macro io_itcr symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	TS  ,3)
		__UCHARBIT(	EXT ,1)
		__UCHARBIT(	TOE ,1)
		__UCHARBIT_NONAME(   1)
		__UCHARBIT(	AAC ,1)
		__UCHARBIT_NONAME(   1)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of ITSR */
#if defined(__CPU_MB89570_SERIES)
#macro io_itsr symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	MTR ,1)
		__UCHARBIT(	STR ,1)
		__UCHARBIT(	TCR ,1)
		__UCHARBIT(	TDR ,1)
		__UCHARBIT_NONAME(   4)
	__STRUCT_TYPE_E(bit)
#endm
#endif


/*****************************************************************/
/* Sample program for control registers of LCD controler/driver. */
/*****************************************************************/
/* structure of LCR1 */
#if defined(__CPU_MB89550_SERIES) || defined(__CPU_MB89560_SERIES) || \
    defined(__CPU_MB89570_SERIES)
#macro io_lcr1 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	FP  ,2)
		__UCHARBIT(	MS  ,2)
		__UCHARBIT(	BK  ,1)
		__UCHARBIT(	VSEL,1)
		__UCHARBIT(	LCEN,1)
		__UCHARBIT(	CSS ,1)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of LCR2 */
#if defined(__CPU_MB89550_SERIES) || defined(__CPU_MB89560_SERIES) || \
    defined(__CPU_MB89570_SERIES)
#macro io_lcr2 symbol
	__BYTE_MEM
#if defined(__CPU_MB89570_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT_NONAME(    1)
		__UCHARBIT(	SEG8 ,1)
		__UCHARBIT(	SEG9 ,1)
		__UCHARBIT(	SEG10,1)
		__UCHARBIT(	SEG11,1)
		__UCHARBIT(	SEG12,1)
		__UCHARBIT(	SEG13,1)
		__UCHARBIT_NONAME(    1)
	__STRUCT_TYPE_E(bit)
#else
	__STRUCT_TYPE_B
		__UCHARBIT(	FP  ,2)
		__UCHARBIT(	LCS ,4)
		__UCHARBIT(	LCEN,1)
		__UCHARBIT(	CSS ,1)
	__STRUCT_TYPE_E(bit)
#endif
#endm
#endif

/* structure of LCR3 */
#if defined(__CPU_MB89550_SERIES) || defined(__CPU_MB89560_SERIES) || \
    defined(__CPU_MB89570_SERIES)
#macro io_lcr3 symbol
	__BYTE_MEM
#if defined(__CPU_MB89550_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	LCD ,5)
		__UCHARBIT_NONAME(   3)
	__STRUCT_TYPE_E(bit)
#elif defined(__CPU_MB89560_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	LCD ,5)
		__UCHARBIT(	LCS ,1)
		__UCHARBIT_NONAME(   2)
	__STRUCT_TYPE_E(bit)
#else
	__STRUCT_TYPE_B
		__UCHARBIT(	SEG0,1)
		__UCHARBIT(	SEG1,1)
		__UCHARBIT(	SEG2,1)
		__UCHARBIT(	SEG3,1)
		__UCHARBIT(	SEG4,1)
		__UCHARBIT(	SEG5,1)
		__UCHARBIT(	SEG6,1)
		__UCHARBIT(	SEG7,1)
	__STRUCT_TYPE_E(bit)
#endif
#endm
#endif

/* structure of LCR4 */
#if defined(__CPU_MB89570_SERIES)
#macro io_lcr4 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT_NONAME(   4)
		__UCHARBIT(	COM0,1)
		__UCHARBIT(	COM1,1)
		__UCHARBIT(	COM2,1)
		__UCHARBIT(	COM3,1)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of VRAM  */
#if defined(__CPU_MB89550_SERIES) || defined(__CPU_MB89560_SERIES) || \
    defined(__CPU_MB89570_SERIES)
#macro io_vram symbol
#if defined(__CPU_MB89550_SERIES)
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
#elif defined(__CPU_MB89560_SERIES)
	__WORD_MEM_A(6)
	__BYTE_MEM_A(12)
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
	__STRUCT_TYPE_E(COM0123)
#else
	__WORD_MEM_A(4)
	__BYTE_MEM_A(8)
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
	__STRUCT_TYPE_E(COM0123)
#endif
#endm
#endif


/*********************************************/
/* Sample program for I/O variables of UART. */
/*********************************************/
/* structure of SMC11 */
#if defined(__CPU_MB89530_SERIES) || defined(__CPU_MB89550_SERIES) || \
    defined(__CPU_MB89560_SERIES)
#macro io_smc11 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	SOE ,1)
		__UCHARBIT(	SCKE,1)
		__UCHARBIT(	SMDE,1)
		__UCHARBIT(	MC  ,3)
		__UCHARBIT(	SBL ,1)
		__UCHARBIT(	PEN ,1)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of SRC1 */
#if defined(__CPU_MB89530_SERIES) || defined(__CPU_MB89550_SERIES) || \
    defined(__CPU_MB89560_SERIES)
#macro io_src1 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	RC  ,3)
		__UCHARBIT(	SCS ,2)
		__UCHARBIT(	CR  ,1)
		__UCHARBIT_NONAME(   2)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of SSD1 */
#if defined(__CPU_MB89530_SERIES) || defined(__CPU_MB89550_SERIES) || \
    defined(__CPU_MB89560_SERIES)
#macro io_ssd1 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	RD8_RP,1)
		__UCHARBIT(	TD8_TP,1)
		__UCHARBIT_NONAME(     1)
		__UCHARBIT(	RIE   ,1)
		__UCHARBIT(	TIE   ,1)
		__UCHARBIT(	TDRE  ,1)
		__UCHARBIT(	ORFE  ,1)
		__UCHARBIT(	RDRF  ,1)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of SMC12 */
#if defined(__CPU_MB89530_SERIES) || defined(__CPU_MB89550_SERIES) || \
    defined(__CPU_MB89560_SERIES)
#macro io_smc12 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	PDS ,3)
		__UCHARBIT(	PDCK,1)
		__UCHARBIT(	LSEL,1)
		__UCHARBIT(	PSEN,1)
		__UCHARBIT_NONAME(   2)
	__STRUCT_TYPE_E(bit)
#endm
#endif


/*************************************************/
/* Sample program for I/O variables of UART/SIO. */
/*************************************************/
/* structure of SMC21 */
#if defined(__CPU_MB89530_SERIES) || defined(__CPU_MB89550_SERIES) || \
    defined(__CPU_MB89560_SERIES) || defined(__CPU_MB89570_SERIES) || \
    defined(__CPU_MB89580_SERIES) || defined(__CPU_MB89590_SERIES)
#macro io_smc21 symbol
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
#endif

/* structure of SMC22 */
#if defined(__CPU_MB89530_SERIES) || defined(__CPU_MB89550_SERIES) || \
    defined(__CPU_MB89560_SERIES) || defined(__CPU_MB89570_SERIES) || \
    defined(__CPU_MB89580_SERIES) || defined(__CPU_MB89590_SERIES)
#macro io_smc22 symbol
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
#endif

/* structure of SSD2 */
#if defined(__CPU_MB89530_SERIES) || defined(__CPU_MB89550_SERIES) || \
    defined(__CPU_MB89560_SERIES) || defined(__CPU_MB89570_SERIES) || \
    defined(__CPU_MB89580_SERIES) || defined(__CPU_MB89590_SERIES)
#macro io_ssd2 symbol
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
#endif

/* structure of SCS */
#if defined(__CPU_MB89580_SERIES) || defined(__CPU_MB89590_SERIES)
#macro io_scs symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	EXBRE,1)
		__UCHARBIT_NONAME(    7)
	__STRUCT_TYPE_E(bit)
#endm
#endif


/****************************************************/
/* Sample program for control registers of USB Hub. */
/****************************************************/
/* structure of HMDR */
#if defined(__CPU_MB89590_SERIES)
#macro io_hmdr symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	PWC ,1)
		__UCHARBIT_NONAME(   5)
		__UCHARBIT(	POWE,1)
		__UCHARBIT(	HRST,1)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of HDSR */
#if defined(__CPU_MB89590_SERIES)
#macro io_hdsr symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	PCM ,2)
		__UCHARBIT(	OVM ,2)
		__UCHARBIT(	PPM1,1)
		__UCHARBIT(	PPM2,1)
		__UCHARBIT(	PPM3,1)
		__UCHARBIT(	PPM4,1)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of HSTR */
#if defined(__CPU_MB89590_SERIES)
#macro io_hstr symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	P1SUS,1)
		__UCHARBIT(	P2SUS,1)
		__UCHARBIT(	P3SUS,1)
		__UCHARBIT(	P4SUS,1)
		__UCHARBIT(	MWKUP,1)
		__UCHARBIT(	WKUP ,1)
		__UCHARBIT(	RTSM ,1)
		__UCHARBIT(	RTSUS,1)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of OCCR */
#if defined(__CPU_MB89590_SERIES)
#macro io_occr symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	OC1 ,1)
		__UCHARBIT(	OC2 ,1)
		__UCHARBIT(	OC3 ,1)
		__UCHARBIT(	OC4 ,1)
		__UCHARBIT_NONAME(   3)
		__UCHARBIT(	HBSR,1)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of SDSR */
#if defined(__CPU_MB89590_SERIES)
#macro io_sdsr symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	SSEL,3)
		__UCHARBIT_NONAME(   5)
	__STRUCT_TYPE_E(bit)
#endm
#endif


/*********************************************************/
/* Sample program for control registers of USB Function. */
/*********************************************************/
/* structure of UMDR */
#if defined(__CPU_MB89580_SERIES) || defined(__CPU_MB89590_SERIES)
#macro io_umdr symbol
	__BYTE_MEM
#if defined(__CPU_MB89580_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	BFS  ,1)
		__UCHARBIT_NONAME(    3)
		__UCHARBIT(	SP   ,1)
		__UCHARBIT(	HCON ,1)
		__UCHARBIT(	RESUM,1)
		__UCHARBIT(	RST  ,1)
	__STRUCT_TYPE_E(bit)
#else
	__STRUCT_TYPE_B
		__UCHARBIT(	BFS  ,1)
		__UCHARBIT(	RFBM ,1)
		__UCHARBIT_NONAME(    2)
		__UCHARBIT(	SP   ,1)
		__UCHARBIT(	HCON ,1)
		__UCHARBIT(	RESUM,1)
		__UCHARBIT(	RST  ,1)
	__STRUCT_TYPE_E(bit)
#endif
#endm
#endif

/* structure of DBAR */
#if defined(__CPU_MB89580_SERIES) || defined(__CPU_MB89590_SERIES)
#macro io_dbar symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	AD ,6)
		__UCHARBIT_NONAME(  2)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of UCTR */
#if defined(__CPU_MB89580_SERIES) || defined(__CPU_MB89590_SERIES)
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
#endif

/* structure of USTR1 */
#if defined(__CPU_MB89580_SERIES) || defined(__CPU_MB89590_SERIES)
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
#endif

/* structure of USTR2 */
#if defined(__CPU_MB89580_SERIES) || defined(__CPU_MB89590_SERIES)
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
#endif

/* structure of UMSKR */
#if defined(__CPU_MB89580_SERIES) || defined(__CPU_MB89590_SERIES)
#macro io_umskr symbol
	__BYTE_MEM
#if defined(__CPU_MB89580_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT_NONAME(     1)
		__UCHARBIT(	MSUSP ,1)
		__UCHARBIT(	MWKUP ,1)
		__UCHARBIT(	MBUSR ,1)
		__UCHARBIT(	MSETIF,1)
		__UCHARBIT(	MSOF  ,1)
		__UCHARBIT(	MSETUP,1)
		__UCHARBIT(	MPKEND,1)
	__STRUCT_TYPE_E(bit)
#else
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
#endif
#endm
#endif

/* structure of EPER */
#if defined(__CPU_MB89580_SERIES) || defined(__CPU_MB89590_SERIES)
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
#endif

/* structure of EPBR0 */
#if defined(__CPU_MB89580_SERIES) || defined(__CPU_MB89590_SERIES)
#macro io_epbr0 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	MP ,7)
		__UCHARBIT_NONAME(  1)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of EPBRm */
#if defined(__CPU_MB89580_SERIES)
#macro io_epbrm symbol
	__WORD_MEM
	__STRUCT_TYPE_B
		__USHORTBIT(	MP ,10)
		__USHORTBIT(	DIR,2)
		__USHORTBIT(	TYP,2)
		__USHORTBIT_NONAME( 1)
		__USHORTBIT(	EPM,1)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of EPBRn */
#if defined(__CPU_MB89580_SERIES) || defined(__CPU_MB89590_SERIES)
#macro io_epbrn symbol
	__WORD_MEM
	__STRUCT_TYPE_B
		__USHORTBIT(	MP ,7)
		__USHORTBIT_NONAME( 3)
		__USHORTBIT(	DIR,2)
		__USHORTBIT(	TYP,2)
		__USHORTBIT_NONAME( 2)
	__STRUCT_TYPE_E(bit)
#endm
#endif


/*********************************************************/
/* Sample program for control registers of clock output. */
/*********************************************************/
/* structure of CKR  */
#if defined(__CPU_MB89530_SERIES) || defined(__CPU_MB89550_SERIES) || \
    defined(__CPU_MB89560_SERIES) || defined(__CPU_MB89580_SERIES) || \
    defined(__CPU_MB89590_SERIES)
#macro io_ckr  symbol
	__BYTE_MEM
#if defined(__CPU_MB89580_SERIES) || defined(__CPU_MB89590_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	LCKE,1)
		__UCHARBIT_NONAME(   7)
	__STRUCT_TYPE_E(bit)
#else
	__STRUCT_TYPE_B
		__UCHARBIT(	LCKE,1)
		__UCHARBIT(	MCOE,1)
		__UCHARBIT_NONAME(   6)
	__STRUCT_TYPE_E(bit)
#endif
#endm
#endif


/***************************************************/
/* Sample program for I/O variables of comparater. */
/***************************************************/
/* structure of COCR1 */
#if defined(__CPU_MB89570_SERIES)
#macro io_cocr1 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	SPM ,3)
		__UCHARBIT(	BOF1,1)
		__UCHARBIT(	BOF2,1)
		__UCHARBIT(	BOF3,1)
		__UCHARBIT_NONAME(   2)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of COCR2 */
#if defined(__CPU_MB89570_SERIES)
#macro io_cocr2 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	DC1 ,1)
		__UCHARBIT(	DC2 ,1)
		__UCHARBIT(	B1  ,1)
		__UCHARBIT(	B2  ,1)
		__UCHARBIT(	B3  ,1)
		__UCHARBIT_NONAME(   3)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of COSR1 */
#if defined(__CPU_MB89570_SERIES)
#macro io_cosr1 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	COR1,1)
		__UCHARBIT(	COR2,1)
		__UCHARBIT(	COR3,1)
		__UCHARBIT(	COR4,1)
		__UCHARBIT(	COR5,1)
		__UCHARBIT(	COR6,1)
		__UCHARBIT(	COR7,1)
		__UCHARBIT(	COR8,1)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of CICR1 */
#if defined(__CPU_MB89570_SERIES)
#macro io_cicr1 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	CEN1,1)
		__UCHARBIT(	CEN2,1)
		__UCHARBIT(	CEN3,1)
		__UCHARBIT(	CEN4,1)
		__UCHARBIT(	CEN5,1)
		__UCHARBIT(	CEN6,1)
		__UCHARBIT(	CEN7,1)
		__UCHARBIT(	CEN8,1)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of COSR2 */
#if defined(__CPU_MB89570_SERIES)
#macro io_cosr2 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	VAR1,1)
		__UCHARBIT(	VAR2,1)
		__UCHARBIT(	VAR3,1)
		__UCHARBIT(	SWR1,1)
		__UCHARBIT(	SWR2,1)
		__UCHARBIT(	SWR3,1)
		__UCHARBIT_NONAME(   2)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of CICR2 */
#if defined(__CPU_MB89570_SERIES)
#macro io_cicr2 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	VEN1,1)
		__UCHARBIT(	VEN2,1)
		__UCHARBIT(	VEN3,1)
		__UCHARBIT(	SEN1,1)
		__UCHARBIT(	SEN2,1)
		__UCHARBIT(	SEN3,1)
		__UCHARBIT_NONAME(   2)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of COSR3 */
#if defined(__CPU_MB89570_SERIES)
#macro io_cosr3 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	VAL1,1)
		__UCHARBIT(	VAL2,1)
		__UCHARBIT(	VAL3,1)
		__UCHARBIT(	SWS1,1)
		__UCHARBIT(	SWS2,1)
		__UCHARBIT(	SWS3,1)
		__UCHARBIT_NONAME(   2)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of COSR4 */
#if defined(__CPU_MB89570_SERIES)
#macro io_cosr4 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	COS1,1)
		__UCHARBIT(	COS2,1)
		__UCHARBIT(	COS3,1)
		__UCHARBIT(	COS4,1)
		__UCHARBIT(	COS5,1)
		__UCHARBIT(	COS6,1)
		__UCHARBIT(	COS7,1)
		__UCHARBIT(	COS8,1)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of CIER */
#if defined(__CPU_MB89570_SERIES)
#macro io_cier symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	DIE1,1)
		__UCHARBIT(	DIE2,1)
		__UCHARBIT(	BIE1,1)
		__UCHARBIT(	BIE2,1)
		__UCHARBIT(	BIE3,1)
		__UCHARBIT_NONAME(   3)
	__STRUCT_TYPE_E(bit)
#endm
#endif


/************************************************************/
/* Sample program for I/O variables of clock control block. */
/************************************************************/
/* structure of SYCC */
#if defined(__CPU_MB89530_SERIES) || defined(__CPU_MB89550_SERIES) || \
    defined(__CPU_MB89560_SERIES) || defined(__CPU_MB89570_SERIES) || \
    defined(__CPU_MB89580_SERIES) || defined(__CPU_MB89590_SERIES)
#macro io_sycc symbol
	__BYTE_MEM
#if defined(__CPU_MB89580_SERIES) || defined(__CPU_MB89590_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	CS  ,2)
		__UCHARBIT_NONAME(   1)
		__UCHARBIT(	WT  ,2)
		__UCHARBIT_NONAME(   3)
	__STRUCT_TYPE_E(bit)
#else
	__STRUCT_TYPE_B
		__UCHARBIT(	CS  ,2)
		__UCHARBIT(	SCS ,1)
		__UCHARBIT(	WT  ,2)
		__UCHARBIT_NONAME(   2)
		__UCHARBIT(	SCM ,1)
	__STRUCT_TYPE_E(bit)
#endif
#endm
#endif


/*************************************************************/
/* Sample program for I/O variables of low power controller. */
/*************************************************************/
/* structure of STBC */
#if defined(__CPU_MB89530_SERIES) || defined(__CPU_MB89550_SERIES) || \
    defined(__CPU_MB89560_SERIES) || defined(__CPU_MB89570_SERIES) || \
    defined(__CPU_MB89580_SERIES) || defined(__CPU_MB89590_SERIES)
#macro io_stbc symbol
	__BYTE_MEM
#if defined(__CPU_MB89580_SERIES) || defined(__CPU_MB89590_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT_NONAME(   4)
		__UCHARBIT(	RST ,1)
		__UCHARBIT(	SPL ,1)
		__UCHARBIT(	SLP ,1)
		__UCHARBIT(	STP ,1)
	__STRUCT_TYPE_E(bit)
#else
	__STRUCT_TYPE_B
		__UCHARBIT_NONAME(   3)
		__UCHARBIT(	TMD ,1)
		__UCHARBIT(	RST ,1)
		__UCHARBIT(	SPL ,1)
		__UCHARBIT(	SLP ,1)
		__UCHARBIT(	STP ,1)
	__STRUCT_TYPE_E(bit)
#endif
#endm
#endif


/***********************************************************/
/* Sample program for control register of time-base timer. */
/***********************************************************/
/* structure of TBTC */
#if defined(__CPU_MB89530_SERIES) || defined(__CPU_MB89550_SERIES) || \
    defined(__CPU_MB89560_SERIES) || defined(__CPU_MB89570_SERIES) || \
    defined(__CPU_MB89580_SERIES) || defined(__CPU_MB89590_SERIES)
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
#endif


/*****************************************************/
/* Sample program for I/O variable of parallel port. */
/*****************************************************/
/* structure of PDCR */
#if defined(__CPU_MB89580_SERIES)
#macro io_pdcr symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	PDIE,1)
		__UCHARBIT(	OBFE,1)
		__UCHARBIT(	IBFE,1)
		__UCHARBIT(	IROE,1)
		__UCHARBIT(	IRIE,1)
		__UCHARBIT_NONAME(   3)
	__STRUCT_TYPE_E(bit)
#endm
#endif


/****************************************************************/
/* Sample program for I/O variables of pulse-width count timer. */
/****************************************************************/
/* structure of PCR1 */
#if defined(__CPU_MB89530_SERIES) || defined(__CPU_MB89550_SERIES) || \
    defined(__CPU_MB89560_SERIES)
#macro io_pcr1 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	BF  ,1)
		__UCHARBIT(	IR  ,1)
		__UCHARBIT(	UF  ,1)
		__UCHARBIT_NONAME(   2)
		__UCHARBIT(	IE  ,1)
		__UCHARBIT(	TOE ,1)
		__UCHARBIT(	EN  ,1)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of PCR2 */
#if defined(__CPU_MB89530_SERIES) || defined(__CPU_MB89550_SERIES) || \
    defined(__CPU_MB89560_SERIES)
#macro io_pcr2 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	W   ,3)
		__UCHARBIT(	C   ,2)
		__UCHARBIT(	TO  ,1)
		__UCHARBIT(	RM  ,1)
		__UCHARBIT(	FC  ,1)
	__STRUCT_TYPE_E(bit)
#endm
#endif


/*****************************************************************/
/* Sample program for I/O variables of bridge circuit registers. */
/*****************************************************************/
/* structure of BRSR1 */
#if defined(__CPU_MB89570_SERIES)
#macro io_brsr1 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	BL2 ,1)
		__UCHARBIT(	BL3 ,1)
		__UCHARBIT(	BL4 ,1)
		__UCHARBIT_NONAME(   5)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of BRSR2 */
#if defined(__CPU_MB89570_SERIES)
#macro io_brsr2 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	BMI2 ,2)
		__UCHARBIT(	BMI3 ,2)
		__UCHARBIT(	BMI4 ,2)
		__UCHARBIT_NONAME(    2)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of BRSR3 */
#if defined(__CPU_MB89570_SERIES)
#macro io_brsr3 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	BU1 ,1)
		__UCHARBIT(	BU2 ,1)
		__UCHARBIT(	BU3 ,1)
		__UCHARBIT_NONAME(   5)
	__STRUCT_TYPE_E(bit)
#endm
#endif


/*******************************************************************/
/* Sample program for I/O variables of pull-up resistor registers. */
/*******************************************************************/
/* structure of PURR0 */
#if defined(__CPU_MB89530_SERIES) || defined(__CPU_MB89550_SERIES) || \
    defined(__CPU_MB89560_SERIES) || defined(__CPU_MB89580_SERIES) || \
    defined(__CPU_MB89590_SERIES)
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
#endif

/* structure of PURR1 */
#if defined(__CPU_MB89530_SERIES) || defined(__CPU_MB89550_SERIES) || \
    defined(__CPU_MB89560_SERIES) || defined(__CPU_MB89580_SERIES) || \
    defined(__CPU_MB89590_SERIES)
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
#endif

/* structure of PURR2 */
#if defined(__CPU_MB89530_SERIES) || defined(__CPU_MB89550_SERIES) || \
    defined(__CPU_MB89560_SERIES) || defined(__CPU_MB89580_SERIES) || \
    defined(__CPU_MB89590_SERIES)
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
#endif

/* structure of PURR3 */
#if defined(__CPU_MB89530_SERIES) || defined(__CPU_MB89580_SERIES) || \
    defined(__CPU_MB89590_SERIES)
#macro io_purr3 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	PUR30 ,1)
		__UCHARBIT(	PUR31 ,1)
		__UCHARBIT(	PUR32 ,1)
		__UCHARBIT(	PUR33 ,1)
		__UCHARBIT(	PUR34 ,1)
		__UCHARBIT(	PUR35 ,1)
		__UCHARBIT(	PUR36 ,1)
		__UCHARBIT(	PUR37 ,1)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of PURR4 */
#if defined(__CPU_MB89530_SERIES) || defined(__CPU_MB89550_SERIES) || \
    defined(__CPU_MB89560_SERIES) || defined(__CPU_MB89580_SERIES) || \
    defined(__CPU_MB89590_SERIES)
#macro io_purr4 symbol
	__BYTE_MEM
#if defined(__CPU_MB89530_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	PUR40 ,1)
		__UCHARBIT(	PUR41 ,1)
		__UCHARBIT_NONAME(     2)
		__UCHARBIT(	PUR44 ,1)
		__UCHARBIT(	PUR45 ,1)
		__UCHARBIT(	PUR46 ,1)
		__UCHARBIT(	PUR47 ,1)
	__STRUCT_TYPE_E(bit)
#elif defined(__CPU_MB89580_SERIES) || defined(__CPU_MB89590_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	PUR40 ,1)
		__UCHARBIT(	PUR41 ,1)
		__UCHARBIT(	PUR42 ,1)
		__UCHARBIT(	PUR43 ,1)
		__UCHARBIT(	PUR44 ,1)
		__UCHARBIT(	PUR45 ,1)
		__UCHARBIT(	PUR46 ,1)
		__UCHARBIT(	PUR47 ,1)
	__STRUCT_TYPE_E(bit)
#else
	__STRUCT_TYPE_B
		__UCHARBIT(	PUR40 ,1)
		__UCHARBIT(	PUR41 ,1)
		__UCHARBIT(	PUR42 ,1)
		__UCHARBIT(	PUR43 ,1)
		__UCHARBIT(	PUR44 ,1)
		__UCHARBIT(	PUR45 ,1)
		__UCHARBIT_NONAME(     2)
	__STRUCT_TYPE_E(bit)
#endif
#endm
#endif

/* structure of PURR5 */
#if defined(__CPU_MB89580_SERIES) || defined(__CPU_MB89590_SERIES)
#macro io_purr5 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	PUR50 ,1)
		__UCHARBIT(	PUR51 ,1)
		__UCHARBIT(	PUR52 ,1)
		__UCHARBIT(	PUR53 ,1)
		__UCHARBIT(	PUR54 ,1)
		__UCHARBIT_NONAME(     3)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of PURR6 */
#if defined(__CPU_MB89530_SERIES)
#macro io_purr6 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	PUR60 ,1)
		__UCHARBIT(	PUR61 ,1)
		__UCHARBIT(	PUR62 ,1)
		__UCHARBIT(	PUR63 ,1)
		__UCHARBIT(	PUR64 ,1)
		__UCHARBIT_NONAME(     3)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of PURR8 */
#if defined(__CPU_MB89550_SERIES)
#macro io_purr8 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	PUR80 ,1)
		__UCHARBIT(	PUR81 ,1)
		__UCHARBIT(	PUR82 ,1)
		__UCHARBIT(	PUR83 ,1)
		__UCHARBIT(	PUR84 ,1)
		__UCHARBIT(	PUR85 ,1)
		__UCHARBIT(	PUR86 ,1)
		__UCHARBIT(	PUR87 ,1)
	__STRUCT_TYPE_E(bit)
#endm
#endif


/*****************************************************************************/
/* Sample program for I/O variables of inter Multi addres IIC bus interface. */
/*****************************************************************************/
/* structure of MBSR */
#if defined(__CPU_MB89570_SERIES)
#macro io_mbsr symbol
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
#endif

/* structure of MBCR */
#if defined(__CPU_MB89570_SERIES)
#macro io_mbcr symbol
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
#endif

/* structure of MCCR */
#if defined(__CPU_MB89570_SERIES)
#macro io_mccr symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	CS012,3)
		__UCHARBIT(	CS34 ,2)
		__UCHARBIT(	EN   ,1)
		__UCHARBIT_NONAME(    1)
		__UCHARBIT(	DMBP ,1)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of MADR */
#if defined(__CPU_MB89570_SERIES)
#macro io_madr symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	A   ,7)
		__UCHARBIT_NONAME(   1)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of MTCR */
#if defined(__CPU_MB89570_SERIES)
#macro io_mtcr symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	TS  ,3)
		__UCHARBIT(	EXT ,1)
		__UCHARBIT(	TOE ,1)
		__UCHARBIT_NONAME(   1)
		__UCHARBIT(	AAC ,1)
		__UCHARBIT_NONAME(   1)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of MTSR */
#if defined(__CPU_MB89570_SERIES)
#macro io_mtsr symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	MTR ,1)
		__UCHARBIT(	STR ,1)
		__UCHARBIT(	TCR ,1)
		__UCHARBIT(	TDR ,1)
		__UCHARBIT_NONAME(   4)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of MALR */
#if defined(__CPU_MB89570_SERIES)
#macro io_malr symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	AEN ,1)
		__UCHARBIT(	ARF ,1)
		__UCHARBIT(	ARO ,1)
		__UCHARBIT(	ARAE,1)
		__UCHARBIT_NONAME(   4)
	__STRUCT_TYPE_E(bit)
#endm
#endif


/*************************************************************/
/* Sample program for I/O variables of reset flag registers. */
/*************************************************************/
/* structure of RSFR */
#if defined(__CPU_MB89570_SERIES)
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
#endif


/*******************************************************/
/* Sample program for I/O variables of Wild registers. */
/*******************************************************/
/* structure of WREN  */
#if defined(__CPU_MB89530_SERIES) || defined(__CPU_MB89550_SERIES) || \
    defined(__CPU_MB89560_SERIES) || defined(__CPU_MB89570_SERIES)
#macro io_wren  symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	EN    ,6)
		__UCHARBIT_NONAME(     2)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of WROR  */
#if defined(__CPU_MB89530_SERIES) || defined(__CPU_MB89560_SERIES)
#macro io_wror  symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	DRR   ,6)
		__UCHARBIT_NONAME(     2)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of WILDR */
#if defined(__CPU_MB89530_SERIES) || defined(__CPU_MB89550_SERIES) || \
    defined(__CPU_MB89560_SERIES) || defined(__CPU_MB89570_SERIES)
#macro io_wildreg symbol
		__UCHAR(	WRARH)
		__UCHAR(	WRARL)
		__UCHAR(	WRDR )
#endm
#endif


/**********************************************************************/
/* Sample program for control registers of external interrupt1(eddge) */
/**********************************************************************/
/* structure of EIC1 */
#if defined(__CPU_MB89530_SERIES) || defined(__CPU_MB89550_SERIES) || \
    defined(__CPU_MB89560_SERIES) || defined(__CPU_MB89570_SERIES)
#macro io_eic1 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	EIE0,1)
		__UCHARBIT(	SL0 ,2)
		__UCHARBIT(	EIR0,1)
		__UCHARBIT(	EIE1,1)
		__UCHARBIT(	SL1 ,2)
		__UCHARBIT(	EIR1,1)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of EIC2 */
#if defined(__CPU_MB89530_SERIES) || defined(__CPU_MB89550_SERIES) || \
    defined(__CPU_MB89560_SERIES) || defined(__CPU_MB89570_SERIES)
#macro io_eic2 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	EIE2,1)
		__UCHARBIT(	SL2 ,2)
		__UCHARBIT(	EIR2,1)
		__UCHARBIT(	EIE3,1)
		__UCHARBIT(	SL3 ,2)
		__UCHARBIT(	EIR3,1)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of EIC3 */
#if defined(__CPU_MB89550_SERIES) || defined(__CPU_MB89560_SERIES)
#macro io_eic3 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	EIE4,1)
		__UCHARBIT(	SL4 ,2)
		__UCHARBIT(	EIR4,1)
		__UCHARBIT(	EIE5,1)
		__UCHARBIT(	SL5 ,2)
		__UCHARBIT(	EIR5,1)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of EIC4 */
#if defined(__CPU_MB89550_SERIES) || defined(__CPU_MB89560_SERIES)
#macro io_eic4 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	EIE6,1)
		__UCHARBIT(	SL6 ,2)
		__UCHARBIT(	EIR6,1)
		__UCHARBIT(	EIE7,1)
		__UCHARBIT(	SL7 ,2)
		__UCHARBIT(	EIR7,1)
	__STRUCT_TYPE_E(bit)
#endm
#endif


/**********************************************************************/
/* Sample program for control registers of external interrupt2(level) */
/**********************************************************************/
/* structure of EIE2 */
#if defined(__CPU_MB89530_SERIES) || defined(__CPU_MB89550_SERIES) || \
    defined(__CPU_MB89560_SERIES) || defined(__CPU_MB89580_SERIES) || \
    defined(__CPU_MB89590_SERIES)
#macro io_eie2 symbol
	__BYTE_MEM
#if defined(__CPU_MB89530_SERIES) || defined(__CPU_MB89550_SERIES) || \
    defined(__CPU_MB89580_SERIES) || defined(__CPU_MB89590_SERIES)
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
#else
	__STRUCT_TYPE_B
		__UCHARBIT(	IE20,1)
		__UCHARBIT(	IE21,1)
		__UCHARBIT(	IE22,1)
		__UCHARBIT(	IE23,1)
		__UCHARBIT_NONAME(   4)
	__STRUCT_TYPE_E(bit)
#endif
#endm
#endif

/* structure of EIF2 */
#if defined(__CPU_MB89530_SERIES) || defined(__CPU_MB89550_SERIES) || \
    defined(__CPU_MB89560_SERIES) || defined(__CPU_MB89580_SERIES) || \
    defined(__CPU_MB89590_SERIES)
#macro io_eif2 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	IF20,1)
		__UCHARBIT_NONAME(   7)
	__STRUCT_TYPE_E(bit)
#endm
#endif


/*******************************************************/
/* Sample program for I/O variable of watch prescaler. */
/*******************************************************/
/* structure of WPCR */
#if defined(__CPU_MB89530_SERIES) || defined(__CPU_MB89550_SERIES) || \
    defined(__CPU_MB89560_SERIES) || defined(__CPU_MB89570_SERIES)
#macro io_wpcr symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	WCLR,1)
		__UCHARBIT(	WS  ,3)
		__UCHARBIT_NONAME(   2)
		__UCHARBIT(	WIE ,1)
		__UCHARBIT(	WIF ,1)
	__STRUCT_TYPE_E(bit)
#endm
#endif
