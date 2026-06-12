/*
 MB898xx Series I/O register declaration file V30L08
 ALL RIGHTS RESERVED, COPYRIGHT (C) FUJITSU LIMITED 1998
 LICENSED MATERIAL - PROGRAM PROPERTY OF FUJITSU LIMITED
*/
#include "_ffmc8ls.h"
#include "_f8ldef.h"

/****************************************************************/
/* Sample program for control registers of 10bit A/D converter. */
/****************************************************************/
/* structure of ADC1 */
#if defined(__CPU_MB89850_SERIES) || defined(__CPU_MB89860_SERIES) || \
    defined(__CPU_MB89863_SERIES)
#macro io_adc1 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	AD  ,1)
		__UCHARBIT(	ADMV,1)
		__UCHARBIT(	ADI ,1)
		__UCHARBIT(	ADIE,1)
		__UCHARBIT(	ANS ,3)
		__UCHARBIT_NONAME(   1)
	__STRUCT_TYPE_E(bit)
#endm
#endif

#if defined(__CPU_MB89830_SERIES) || defined(__CPU_MB89870_SERIES) || \
    defined(__CPU_MB89880_SERIES)
#macro io_adc1 symbol
	__BYTE_MEM
#if defined(__CPU_MB89830_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	AD  ,1)
		__UCHARBIT(	SIFM,1)
		__UCHARBIT(	ADMV,1)
		__UCHARBIT(	ADI ,1)
		__UCHARBIT(	ANS ,3)
		__UCHARBIT_NONAME(   1)
	__STRUCT_TYPE_E(bit)
#else
	__STRUCT_TYPE_B
		__UCHARBIT(	AD  ,1)
		__UCHARBIT(	SIFM,1)
		__UCHARBIT(	ADMV,1)
		__UCHARBIT(	ADI ,1)
		__UCHARBIT(	ANS ,4)
	__STRUCT_TYPE_E(bit)
#endif
#endm
#endif

/* structure of ADC2 */
#if defined(__CPU_MB89850_SERIES) || defined(__CPU_MB89860_SERIES) || \
    defined(__CPU_MB89863_SERIES)
#macro io_adc2 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	ESL ,2)
		__UCHARBIT(	SELT,1)
		__UCHARBIT_NONAME(   5)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of ADC2 */
#if defined(__CPU_MB89830_SERIES) || defined(__CPU_MB89870_SERIES) || \
    defined(__CPU_MB89880_SERIES)
#macro io_adc2 symbol
	__BYTE_MEM
#if defined(__CPU_MB89870_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT_NONAME(   2)
		__UCHARBIT(	ADMD,1)
		__UCHARBIT(	ADIE,1)
		__UCHARBIT_NONAME(   4)
	__STRUCT_TYPE_E(bit)
#elif defined(__CPU_MB89880_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT_NONAME(   1)
		__UCHARBIT(	EXT ,1)
		__UCHARBIT(	ADMD,1)
		__UCHARBIT(	ADIE,1)
		__UCHARBIT(	ADCK,1)
		__UCHARBIT(	TIM ,2)
		__UCHARBIT_NONAME(   1)
	__STRUCT_TYPE_E(bit)
#else
	__STRUCT_TYPE_B
		__UCHARBIT_NONAME(   1)
		__UCHARBIT(	EXT ,1)
		__UCHARBIT(	ADMD,1)
		__UCHARBIT(	ADIE,1)
		__UCHARBIT(	ADCK,1)
		__UCHARBIT(	TIM ,2)
		__UCHARBIT(	SCMD,1)
	__STRUCT_TYPE_E(bit)
#endif
#endm
#endif

/* structure of ADC3 */
#if defined(__CPU_MB89830_SERIES)
#macro io_adc3 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	DSS0,1)
		__UCHARBIT(	DSS1,1)
		__UCHARBIT(	DSS2,1)
		__UCHARBIT(	DSS3,1)
		__UCHARBIT(	DSS4,1)
		__UCHARBIT(	DSS5,1)
		__UCHARBIT(	DSS6,1)
		__UCHARBIT(	DSS7,1)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of ADD */
#if defined(__CPU_MB89850_SERIES) || defined(__CPU_MB89860_SERIES) || \
    defined(__CPU_MB89863_SERIES) || defined(__CPU_MB89870_SERIES) || \
    defined(__CPU_MB89880_SERIES)
#macro io_add symbol
	__WORD_MEM
	__STRUCT_TYPE_B
		__USHORTBIT(	DATA10,10)
		__USHORTBIT_NONAME(     6)
	__STRUCT_TYPE_E(bit)
#endm
#endif


#if defined(__CPU_MB89830_SERIES)
#macro  io_add_bit0 symbol
	__USHORTBIT(	DATA10,10)
	__USHORTBIT_NONAME(     6)
#endm

#macro  io_add_bit1 symbol
	__USHORTBIT_NONAME(     6)
	__USHORTBIT(	DATA10,10)
#endm

#macro io_add symbol
	__WORD_MEM
	__TYPE_UNION
	__STRUCT_MEM(io_add_bit0,bit0)
	__TYPE_UNION
	__STRUCT_MEM(io_add_bit1,bit1)
#endm
#endif


/*****************************************************/
/* Sample program for I/O variable of input capture. */
/*****************************************************/
/* structure of ICSR */
#if defined(__CPU_MB89880_SERIES)
#macro io_icsr symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	ES0 ,1)
		__UCHARBIT(	ES1 ,1)
		__UCHARBIT(	ES2 ,1)
		__UCHARBIT(	IS  ,1)
		__UCHARBIT(	TMRC,1)
		__UCHARBIT(	STG0,1)
		__UCHARBIT(	STG1,1)
		__UCHARBIT(	STG2,1)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of ICIC */
#if defined(__CPU_MB89880_SERIES)
#macro io_icic symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	TMIE,1)
		__UCHARBIT(	CIE0,1)
		__UCHARBIT(	CIE1,1)
		__UCHARBIT(	CIE2,1)
		__UCHARBIT(	SFTE,1)
		__UCHARBIT_NONAME(   1)
		__UCHARBIT(	TES ,2)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of ICIS */
#if defined(__CPU_MB89880_SERIES)
#macro io_icis symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	TMIR,1)
		__UCHARBIT(	CIR0,1)
		__UCHARBIT(	CIR1,1)
		__UCHARBIT(	CIR2,1)
		__UCHARBIT(	OVF0,1)
		__UCHARBIT(	OVF1,1)
		__UCHARBIT(	OVF2,1)
		__UCHARBIT_NONAME(   1)
	__STRUCT_TYPE_E(bit)
#endm
#endif


/*****************************************************************/
/* Sample program for control registers of 16-bit timer/counter. */
/*****************************************************************/
/* structure of TMCR */
#if defined(__CPU_MB89810A_SERIES) || defined(__CPU_MB89830_SERIES) || \
    defined(__CPU_MB89880_SERIES)
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


/**********************************************************************/
/* Sample program for I/O variables of serial I/O with 1-byte buffer. */
/**********************************************************************/
/* structure of SBMR */
#if defined(__CPU_MB89890_SERIES)
#macro io_sbmr symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	BDS ,1)
		__UCHARBIT(	CKS ,2)
		__UCHARBIT(	SEN ,1)
		__UCHARBIT(	SOE ,1)
		__UCHARBIT(	SFLE,1)
		__UCHARBIT(	SEME,1)
		__UCHARBIT(	SOVE,1)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of SBFR */
#if defined(__CPU_MB89890_SERIES)
#macro io_sbfr symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	SFLF,1)
		__UCHARBIT(	SEMF,1)
		__UCHARBIT(	SOVF,1)
		__UCHARBIT_NONAME(   5)
	__STRUCT_TYPE_E(bit)
#endm
#endif


/*********************************************************************/
/* Sample program for mode and data registers of 32-byte serial I/O. */
/*********************************************************************/
/* structure of SCR */
#if defined(__CPU_MB89830_SERIES)
#macro io_scr symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	ST  ,1)
		__UCHARBIT_NONAME(   2)
		__UCHARBIT(	DIR ,1)
		__UCHARBIT(	STBE,1)
		__UCHARBIT(	SOE ,1)
		__UCHARBIT(	SIE ,1)
		__UCHARBIT(	SIF ,1)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of SCMR */
#if defined(__CPU_MB89830_SERIES)
#macro io_scmr symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	SC  ,3)
		__UCHARBIT(	IC  ,2)
		__UCHARBIT_NONAME(   1)
		__UCHARBIT(	BDS ,1)
		__UCHARBIT_NONAME(   1)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of SCBR */
#if defined(__CPU_MB89830_SERIES)
#macro io_scbr symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	BC  ,5)
		__UCHARBIT_NONAME(   3)
	__STRUCT_TYPE_E(bit)
#endm
#endif


/********************************************************************/
/* Sample program for data and control registers of 8/16-bit timer. */
/********************************************************************/
/* structure of T1CR */
#if defined(__CPU_MB89870_SERIES) || defined(__CPU_MB89890_SERIES)
#macro io_t1cr symbol
        __BYTE_MEM
        __STRUCT_TYPE_B
                __UCHARBIT(   T1STR,1)
                __UCHARBIT(   T1STP,1)
                __UCHARBIT(   T1CS ,2)
                __UCHARBIT(   T1OS ,2)
                __UCHARBIT(   T1IE ,1)
                __UCHARBIT(   T1IF ,1)
        __STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of T2CR */
#if defined(__CPU_MB89870_SERIES) || defined(__CPU_MB89890_SERIES)
#macro io_t2cr symbol
        __BYTE_MEM
        __STRUCT_TYPE_B
                __UCHARBIT(   T2STR,1)
                __UCHARBIT(   T2STP,1)
                __UCHARBIT(   T2CS ,2)
                __UCHARBIT(   T2OS ,2)
                __UCHARBIT(   T2IE ,1)
                __UCHARBIT(   T2IF ,1)
        __STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of T12DR */
#if defined(__CPU_MB89870_SERIES) || defined(__CPU_MB89890_SERIES)
#macro io_t12dr symbol
        __WORD_MEM
        __STRUCT_TYPE_B
                __UCHAR(   T2DR)
                __UCHAR(   T1DR)
        __STRUCT_TYPE_E(byte)
#endm
#endif


/****************************************************************/
/* Sample program for control registers of 8-bit A/D converter. */
/****************************************************************/
/* structure of ADC1 */
#if defined(__CPU_MB89890_SERIES)
#macro io_adc1 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	AD  ,1)
		__UCHARBIT(	SIFM,1)
		__UCHARBIT(	ADMV,1)
		__UCHARBIT(	ADI ,1)
		__UCHARBIT(	ANS ,4)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of ADC2 */
#if defined(__CPU_MB89890_SERIES)
#macro io_adc2 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT_NONAME(   1)
		__UCHARBIT(	EXT ,1)
		__UCHARBIT(	ADMD,1)
		__UCHARBIT(	ADIE,1)
		__UCHARBIT_NONAME(   4)
	__STRUCT_TYPE_E(bit)
#endm
#endif


/***********************************************************/
/* Sample program for control registers of 8bit PWM timer. */
/***********************************************************/
/* structure of CNTR0 */
#if defined(__CPU_MB89880_SERIES)
#macro io_cntr0 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	TIE0,1)
		__UCHARBIT(	OE0 ,1)
		__UCHARBIT(	TIR0,1)
		__UCHARBIT(	TPE0,1)
		__UCHARBIT(	SC0 ,2)
		__UCHARBIT_NONAME(   1)
		__UCHARBIT(	PTX0,1)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of CNTR1 */
#if defined(__CPU_MB89810A_SERIES) || defined(__CPU_MB89880_SERIES)
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
#if defined(__CPU_MB89810A_SERIES) || defined(__CPU_MB89880_SERIES)
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
#if defined(__CPU_MB89810A_SERIES) || defined(__CPU_MB89880_SERIES)
#macro io_cntr3 symbol
	__BYTE_MEM
#if defined(__CPU_MB89810A_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT_NONAME(   4)
		__UCHARBIT(	CH12,1)
		__UCHARBIT(	OE3 ,1)
		__UCHARBIT(	OE2 ,1)
		__UCHARBIT_NONAME(   1)
	__STRUCT_TYPE_E(bit)
#else
	__STRUCT_TYPE_B
		__UCHARBIT_NONAME(   4)
		__UCHARBIT(	CH12,1)
		__UCHARBIT(	OE3 ,1)
		__UCHARBIT(	OE2 ,1)
		__UCHARBIT(	OE1 ,1)
	__STRUCT_TYPE_E(bit)
#endif
#endm
#endif

/* structure of CNTR */
#if defined(__CPU_MB89800_SERIES) || defined(__CPU_MB89820_SERIES) || \
    defined(__CPU_MB89830_SERIES) || defined(__CPU_MB89850_SERIES) || \
    defined(__CPU_MB89860_SERIES) || defined(__CPU_MB89863_SERIES) || \
    defined(__CPU_MB89870_SERIES) || defined(__CPU_MB89890_SERIES)
#macro io_cntr symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	TIE ,1)
		__UCHARBIT(	OE  ,1)
		__UCHARBIT(	TIR ,1)
		__UCHARBIT(	TPE ,1)
		__UCHARBIT(	P   ,2)
		__UCHARBIT_NONAME(   1)
		__UCHARBIT(	P_TX,1)
	__STRUCT_TYPE_E(bit)
#endm
#endif


/*************************************************************/
/* Sample program for control registers of 8-bit serial I/O. */
/*************************************************************/
/* structure of SMR */
#if defined(__CPU_MB89800_SERIES) || defined(__CPU_MB89810A_SERIES) || \
    defined(__CPU_MB89820_SERIES) || defined(__CPU_MB89830_SERIES)  || \
    defined(__CPU_MB89850_SERIES) || defined(__CPU_MB89860_SERIES)  || \
    defined(__CPU_MB89870_SERIES) || defined(__CPU_MB89880_SERIES)  || \
    defined(__CPU_MB89890_SERIES)
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


/*******************************************************/
/* Sample program for I/O variables of DTMF generater. */
/*******************************************************/
/* structure of DTMC */
#if defined(__CPU_MB89890_SERIES)
#macro io_dtmc symbol
        __BYTE_MEM
        __STRUCT_TYPE_B
                __UCHARBIT(   OUTE,1)
                __UCHARBIT(   RDIS,1)
                __UCHARBIT(   CDIS,1)
                __UCHARBIT(   CSEL,1)
                __UCHARBIT_NONAME( 4)
        __STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of DTMD */
#if defined(__CPU_MB89890_SERIES)
#macro io_dtmd symbol
        __BYTE_MEM
        __STRUCT_TYPE_B
                __UCHARBIT(   DDAT,4)
                __UCHARBIT_NONAME( 4)
        __STRUCT_TYPE_E(bit)
#endm
#endif


/*****************************************************/
/* Sample program for control registers of I/O port. */
/*****************************************************/
/* structure of PDR0 */
#if defined(__CPU_MB89800_SERIES) || defined(__CPU_MB89810A_SERIES) || \
    defined(__CPU_MB89820_SERIES) || defined(__CPU_MB89830_SERIES)  || \
    defined(__CPU_MB89850_SERIES) || defined(__CPU_MB89860_SERIES)  || \
    defined(__CPU_MB89863_SERIES) || defined(__CPU_MB89870_SERIES)  || \
    defined(__CPU_MB89880_SERIES) || defined(__CPU_MB89890_SERIES)
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
#if defined(__CPU_MB89800_SERIES) || defined(__CPU_MB89810A_SERIES) || \
    defined(__CPU_MB89820_SERIES) || defined(__CPU_MB89830_SERIES)  || \
    defined(__CPU_MB89850_SERIES) || defined(__CPU_MB89860_SERIES)  || \
    defined(__CPU_MB89870_SERIES) || defined(__CPU_MB89880_SERIES)  || \
    defined(__CPU_MB89890_SERIES)
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
#if defined(__CPU_MB89800_SERIES) || defined(__CPU_MB89810A_SERIES) || \
    defined(__CPU_MB89820_SERIES) || defined(__CPU_MB89830_SERIES)  || \
    defined(__CPU_MB89850_SERIES) || defined(__CPU_MB89860_SERIES)  || \
    defined(__CPU_MB89863_SERIES) || defined(__CPU_MB89870_SERIES)  || \
    defined(__CPU_MB89880_SERIES) || defined(__CPU_MB89890_SERIES)
#macro io_pdr2 symbol
	__BYTE_MEM
#if defined(__CPU_MB89880_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	P20 ,1)
		__UCHARBIT(	P21 ,1)
		__UCHARBIT(	P22 ,1)
		__UCHARBIT_NONAME(   5)
	__STRUCT_TYPE_E(bit)
#elif defined(__CPU_MB89870_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	P20 ,1)
		__UCHARBIT(	P21 ,1)
		__UCHARBIT(	P22 ,1)
		__UCHARBIT(	P23 ,1)
		__UCHARBIT(	P24 ,1)
		__UCHARBIT_NONAME(   3)
	__STRUCT_TYPE_E(bit)
#elif defined(__CPU_MB89800_SERIES) || defined(__CPU_MB89820_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	P20 ,1)
		__UCHARBIT(	P21 ,1)
		__UCHARBIT(	P22 ,1)
		__UCHARBIT(	P23 ,1)
		__UCHARBIT(	P24 ,1)
		__UCHARBIT(	P25 ,1)
		__UCHARBIT_NONAME(   2)
	__STRUCT_TYPE_E(bit)
#elif defined(__CPU_MB89863_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT_NONAME(   1)
		__UCHARBIT(	P21 ,1)
		__UCHARBIT(	P22 ,1)
		__UCHARBIT(	P23 ,1)
		__UCHARBIT(	P24 ,1)
		__UCHARBIT(	P25 ,1)
		__UCHARBIT(	P26 ,1)
		__UCHARBIT(	P27 ,1)
	__STRUCT_TYPE_E(bit)
#else
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
#endif
#endm
#endif

/* structure of PDR3 */
#if defined(__CPU_MB89800_SERIES) || defined(__CPU_MB89810A_SERIES) || \
    defined(__CPU_MB89820_SERIES) || defined(__CPU_MB89830_SERIES)  || \
    defined(__CPU_MB89850_SERIES) || defined(__CPU_MB89860_SERIES)  || \
    defined(__CPU_MB89863_SERIES) || defined(__CPU_MB89870_SERIES)  || \
    defined(__CPU_MB89880_SERIES) || defined(__CPU_MB89890_SERIES)
#macro io_pdr3 symbol
	__BYTE_MEM
#if defined(__CPU_MB89800_SERIES) || defined(__CPU_MB89820_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	P30 ,1)
		__UCHARBIT(	P31 ,1)
		__UCHARBIT(	P32 ,1)
		__UCHARBIT(	P33 ,1)
		__UCHARBIT_NONAME(   4)
	__STRUCT_TYPE_E(bit)
#elif defined(__CPU_MB89863_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	P30 ,1)
		__UCHARBIT(	P31 ,1)
		__UCHARBIT(	P32 ,1)
		__UCHARBIT_NONAME(   3)
		__UCHARBIT(	P36 ,1)
		__UCHARBIT(	P37 ,1)
	__STRUCT_TYPE_E(bit)
#else
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
#endif
#endm
#endif

/* structure of PDR4 */
#if defined(__CPU_MB89800_SERIES) || defined(__CPU_MB89810A_SERIES) || \
    defined(__CPU_MB89820_SERIES) || defined(__CPU_MB89830_SERIES)  || \
    defined(__CPU_MB89850_SERIES) || defined(__CPU_MB89860_SERIES)  || \
    defined(__CPU_MB89863_SERIES) || defined(__CPU_MB89870_SERIES)  || \
    defined(__CPU_MB89880_SERIES) || defined(__CPU_MB89890_SERIES)
#macro io_pdr4 symbol
	__BYTE_MEM
#if defined(__CPU_MB89890_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	P40 ,1)
		__UCHARBIT(	P41 ,1)
		__UCHARBIT(	P42 ,1)
		__UCHARBIT(	P43 ,1)
		__UCHARBIT(	P44 ,1)
		__UCHARBIT_NONAME(   3)
	__STRUCT_TYPE_E(bit)
#elif defined(__CPU_MB89800_SERIES) || defined(__CPU_MB89820_SERIES) || \
      defined(__CPU_MB89880_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	P40 ,1)
		__UCHARBIT(	P41 ,1)
		__UCHARBIT(	P42 ,1)
		__UCHARBIT(	P43 ,1)
		__UCHARBIT(	P44 ,1)
		__UCHARBIT(	P45 ,1)
		__UCHARBIT_NONAME(   2)
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
#if defined(__CPU_MB89810A_SERIES) || defined(__CPU_MB89830_SERIES) || \
    defined(__CPU_MB89850_SERIES)  || defined(__CPU_MB89860_SERIES) || \
    defined(__CPU_MB89863_SERIES)  || defined(__CPU_MB89870_SERIES) || \
    defined(__CPU_MB89880_SERIES)  || defined(__CPU_MB89890_SERIES)
#macro io_pdr5 symbol
	__BYTE_MEM
#if defined(__CPU_MB89810A_SERIES)
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
#if defined(__CPU_MB89810A_SERIES) || defined(__CPU_MB89830_SERIES) || \
    defined(__CPU_MB89850_SERIES)  || defined(__CPU_MB89860_SERIES) || \
    defined(__CPU_MB89863_SERIES)  || defined(__CPU_MB89880_SERIES) || \
    defined(__CPU_MB89890_SERIES)
#macro io_pdr6 symbol
	__BYTE_MEM
#if defined(__CPU_MB89863_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	P60 ,1)
		__UCHARBIT_NONAME(   3)
		__UCHARBIT(	P64 ,1)
		__UCHARBIT_NONAME(   3)
	__STRUCT_TYPE_E(bit)
#elif defined(__CPU_MB89850_SERIES) || defined(__CPU_MB89860_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	P60 ,1)
		__UCHARBIT(	P61 ,1)
		__UCHARBIT(	P62 ,1)
		__UCHARBIT(	P63 ,1)
		__UCHARBIT(	P64 ,1)
		__UCHARBIT_NONAME(   3)
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
#if defined(__CPU_MB89860_SERIES) || defined(__CPU_MB89890_SERIES)
#macro io_pdr7 symbol
	__BYTE_MEM
#if defined(__CPU_MB89860_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	P70 ,1)
		__UCHARBIT(	P71 ,1)
		__UCHARBIT(	P72 ,1)
		__UCHARBIT(	P73 ,1)
		__UCHARBIT(	P74 ,1)
		__UCHARBIT(	P75 ,1)
		__UCHARBIT(	P76 ,1)
		__UCHARBIT_NONAME(   1)
	__STRUCT_TYPE_E(bit)
#else
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
#endif
#endm
#endif

/* structure of PDR8 */
#if defined(__CPU_MB89860_SERIES) || defined(__CPU_MB89890_SERIES)
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
#if defined(__CPU_MB89890_SERIES)
#macro io_pdr9 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	P90 ,1)
		__UCHARBIT(	P91 ,1)
		__UCHARBIT(	P92 ,1)
		__UCHARBIT(	P93 ,1)
		__UCHARBIT(	P94 ,1)
		__UCHARBIT(	P95 ,1)
		__UCHARBIT(	P96 ,1)
		__UCHARBIT(	P97 ,1)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of PDRA */
#if defined(__CPU_MB89890_SERIES)
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

/* structure of PIVE */
#if defined(__CPU_MB89810A_SERIES)
#macro io_pive symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	EN  ,1)
		__UCHARBIT_NONAME(   7)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of CHG5 */
#if defined(__CPU_MB89870_SERIES)
#macro io_chg5 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT_NONAME(   3)
		__UCHARBIT(	CHG0,1)
		__UCHARBIT_NONAME(   3)
		__UCHARBIT(	CHG1,1)
	__STRUCT_TYPE_E(bit)
#endm
#endif


/*****************************************************************/
/* Sample program for control registers of LCD controler/driver. */
/*****************************************************************/
/* structure of LCR */
#if defined(__CPU_MB89800_SERIES) || defined(__CPU_MB89820_SERIES) || \
    defined(__CPU_MB89870_SERIES)
#macro io_lcr symbol
	__BYTE_MEM
#if defined(__CPU_MB89800_SERIES) || defined(__CPU_MB89820_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	FP  ,2)
		__UCHARBIT(	MS  ,2)
		__UCHARBIT(	BK  ,1)
		__UCHARBIT(	VSEL,1)
		__UCHARBIT_NONAME(   2)
	__STRUCT_TYPE_E(bit)
#else
	__STRUCT_TYPE_B
		__UCHARBIT(	FP  ,2)
		__UCHARBIT(	MS  ,2)
		__UCHARBIT(	BK  ,1)
		__UCHARBIT(	VSEL,1)
		__UCHARBIT(	LCEN,1)
		__UCHARBIT(	CSS ,1)
	__STRUCT_TYPE_E(bit)
#endif
#endm
#endif

/* structure of LCR2 */
#if defined(__CPU_MB89870_SERIES)
#macro io_lcr2 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT_NONAME(   1)
		__UCHARBIT(	SEG1,1)
		__UCHARBIT(	SEG2,1)
		__UCHARBIT(	SEG3,1)
		__UCHARBIT(	SEG4,1)
		__UCHARBIT(	SEG5,1)
		__UCHARBIT(	COM2,1)
		__UCHARBIT(	COM3,1)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of SEGR */
#if defined(__CPU_MB89800_SERIES) || defined(__CPU_MB89820_SERIES)
#macro io_segr symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	SEG00,1)
		__UCHARBIT(	SEG10,1)
		__UCHARBIT(	SEG11,1)
		__UCHARBIT(	SEG12,1)
		__UCHARBIT(	SEG13,1)
		__UCHARBIT_NONAME(    3)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of VRAM */
#if defined(__CPU_MB89800_SERIES) || defined(__CPU_MB89820_SERIES) || \
    defined(__CPU_MB89870_SERIES)
#macro io_vram  symbol
#if defined(__CPU_MB89800_SERIES)
	__WORD_MEM_A(17)
	__BYTE_MEM_A(35)
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
		__UCHARBIT_COM01( SEG32,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG33,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG34,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG35,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG36,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG37,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG38,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG39,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG40,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG41,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG42,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG43,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG44,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG45,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG46,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG47,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG48,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG49,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG50,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG51,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG52,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG53,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG54,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG55,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG56,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG57,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG58,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG59,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG60,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG61,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG62,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG63,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG64,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG65,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG66,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG67,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG68,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG69,2)
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
		__UCHARBIT_COM012(SEG32,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG33,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG34,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG35,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG36,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG37,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG38,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG39,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG40,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG41,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG42,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG43,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG44,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG45,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG46,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG47,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG48,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG49,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG50,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG51,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG52,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG53,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG54,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG55,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG56,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG57,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG58,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG59,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG60,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG61,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG62,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG63,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG64,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG65,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG66,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG67,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG68,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG69,3)
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
		__UCHARBIT_COM0123(SEG32,4)
		__UCHARBIT_COM0123(SEG33,4)
		__UCHARBIT_COM0123(SEG34,4)
		__UCHARBIT_COM0123(SEG35,4)
		__UCHARBIT_COM0123(SEG36,4)
		__UCHARBIT_COM0123(SEG37,4)
		__UCHARBIT_COM0123(SEG38,4)
		__UCHARBIT_COM0123(SEG39,4)
		__UCHARBIT_COM0123(SEG40,4)
		__UCHARBIT_COM0123(SEG41,4)
		__UCHARBIT_COM0123(SEG42,4)
		__UCHARBIT_COM0123(SEG43,4)
		__UCHARBIT_COM0123(SEG44,4)
		__UCHARBIT_COM0123(SEG45,4)
		__UCHARBIT_COM0123(SEG46,4)
		__UCHARBIT_COM0123(SEG47,4)
		__UCHARBIT_COM0123(SEG48,4)
		__UCHARBIT_COM0123(SEG49,4)
		__UCHARBIT_COM0123(SEG50,4)
		__UCHARBIT_COM0123(SEG51,4)
		__UCHARBIT_COM0123(SEG52,4)
		__UCHARBIT_COM0123(SEG53,4)
		__UCHARBIT_COM0123(SEG54,4)
		__UCHARBIT_COM0123(SEG55,4)
		__UCHARBIT_COM0123(SEG56,4)
		__UCHARBIT_COM0123(SEG57,4)
		__UCHARBIT_COM0123(SEG58,4)
		__UCHARBIT_COM0123(SEG59,4)
		__UCHARBIT_COM0123(SEG60,4)
		__UCHARBIT_COM0123(SEG61,4)
		__UCHARBIT_COM0123(SEG62,4)
		__UCHARBIT_COM0123(SEG63,4)
		__UCHARBIT_COM0123(SEG64,4)
		__UCHARBIT_COM0123(SEG65,4)
		__UCHARBIT_COM0123(SEG66,4)
		__UCHARBIT_COM0123(SEG67,4)
		__UCHARBIT_COM0123(SEG68,4)
		__UCHARBIT_COM0123(SEG69,4)
	__STRUCT_TYPE_E(COM0123)
#elif defined(__CPU_MB89820_SERIES)
	__WORD_MEM_A(12)
	__BYTE_MEM_A(25)
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
		__UCHARBIT_COM01( SEG32,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG33,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG34,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG35,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG36,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG37,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG38,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG39,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG40,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG41,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG42,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG43,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG44,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG45,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG46,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG47,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG48,2)
		__UCHARBIT_NONAME(      2)
		__UCHARBIT_COM01( SEG49,2)
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
		__UCHARBIT_COM012(SEG32,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG33,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG34,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG35,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG36,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG37,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG38,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG39,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG40,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG41,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG42,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG43,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG44,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG45,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG46,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG47,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG48,3)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT_COM012(SEG49,3)
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
		__UCHARBIT_COM0123(SEG32,4)
		__UCHARBIT_COM0123(SEG33,4)
		__UCHARBIT_COM0123(SEG34,4)
		__UCHARBIT_COM0123(SEG35,4)
		__UCHARBIT_COM0123(SEG36,4)
		__UCHARBIT_COM0123(SEG37,4)
		__UCHARBIT_COM0123(SEG38,4)
		__UCHARBIT_COM0123(SEG39,4)
		__UCHARBIT_COM0123(SEG40,4)
		__UCHARBIT_COM0123(SEG41,4)
		__UCHARBIT_COM0123(SEG42,4)
		__UCHARBIT_COM0123(SEG43,4)
		__UCHARBIT_COM0123(SEG44,4)
		__UCHARBIT_COM0123(SEG45,4)
		__UCHARBIT_COM0123(SEG46,4)
		__UCHARBIT_COM0123(SEG47,4)
		__UCHARBIT_COM0123(SEG48,4)
		__UCHARBIT_COM0123(SEG49,4)
	__STRUCT_TYPE_E(COM0123)
#elif defined(__CPU_MB89870_SERIES)
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
#endif
#endm
#endif


/*****************************************************/
/* Sample program for I/O variables of OP amplifier. */
/*****************************************************/
/* structure of OPC */
#if defined(__CPU_MB89870_SERIES)
#macro io_opc symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT_NONAME(   4)
		__UCHARBIT(	PD4 ,1)
		__UCHARBIT(	PD5 ,1)
		__UCHARBIT(	PD6 ,1)
		__UCHARBIT(	PD7 ,1)
	__STRUCT_TYPE_E(bit)
#endm
#endif


/*********************************************/
/* Sample program for I/O variables of UART. */
/*********************************************/
/* structure of SMC */
#if defined(__CPU_MB89800_SERIES) || defined(__CPU_MB89810A_SERIES) || \
    defined(__CPU_MB89820_SERIES) || defined(__CPU_MB89850_SERIES)  || \
    defined(__CPU_MB89860_SERIES) || defined(__CPU_MB89863_SERIES)
#macro io_smc symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	SOE ,1)
		__UCHARBIT(	SCKE,1)
		__UCHARBIT_NONAME(   1)
		__UCHARBIT(	SMDE,1)
		__UCHARBIT(	MC  ,2)
		__UCHARBIT(	SBL ,1)
		__UCHARBIT(	PEN ,1)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of SRC */
#if defined(__CPU_MB89800_SERIES) || defined(__CPU_MB89810A_SERIES) || \
    defined(__CPU_MB89820_SERIES) || defined(__CPU_MB89850_SERIES)  || \
    defined(__CPU_MB89860_SERIES) || defined(__CPU_MB89863_SERIES)
#macro io_src symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	RC  ,3)
		__UCHARBIT(	CS  ,2)
		__UCHARBIT(	CR  ,1)
		__UCHARBIT_NONAME(   2)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of SSD */
#if defined(__CPU_MB89800_SERIES) || defined(__CPU_MB89810A_SERIES) || \
    defined(__CPU_MB89820_SERIES) || defined(__CPU_MB89850_SERIES)  || \
    defined(__CPU_MB89860_SERIES) || defined(__CPU_MB89863_SERIES)
#macro io_ssd symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	RD8_RP ,1)
		__UCHARBIT(	TD8_TP ,1)
		__UCHARBIT_NONAME(      1)
		__UCHARBIT(	RIE    ,1)
		__UCHARBIT(	TIE    ,1)
		__UCHARBIT(	TDRE   ,1)
		__UCHARBIT(	ORFE   ,1)
		__UCHARBIT(	RDRF   ,1)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of SMC2 */
#if defined(__CPU_MB89800_SERIES) || defined(__CPU_MB89810A_SERIES) || \
    defined(__CPU_MB89820_SERIES)
#macro io_smc2 symbol
	__BYTE_MEM
#if defined(__CPU_MB89800_SERIES) || defined(__CPU_MB89820_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	PDS ,2)
		__UCHARBIT_NONAME(   1)
		__UCHARBIT(	RSEL,1)
		__UCHARBIT_NONAME(   1)
		__UCHARBIT(	PSEN,1)
		__UCHARBIT_NONAME(   2)
	__STRUCT_TYPE_E(bit)
#else
	__STRUCT_TYPE_B
		__UCHARBIT(	PDS ,2)
		__UCHARBIT(	PDCK,1)
		__UCHARBIT(	PSEL,1)
		__UCHARBIT(	LSEL,1)
		__UCHARBIT(	PSEN,1)
		__UCHARBIT_NONAME(   2)
	__STRUCT_TYPE_E(bit)
#endif
#endm
#endif

/* structure of USMR */
#if defined(__CPU_MB89880_SERIES)
#macro io_usmr symbol
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
#endif

/* structure of USCR */
#if defined(__CPU_MB89880_SERIES)
#macro io_uscr symbol
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

/* structure of USTR */
#if defined(__CPU_MB89880_SERIES)
#macro io_ustr symbol
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


/*********************************************************/
/* Sample program for control registers of system clock. */
/*********************************************************/
/* structure of SYCC */
#if defined(__CPU_MB89800_SERIES) || defined(__CPU_MB89810A_SERIES) || \
    defined(__CPU_MB89870_SERIES) || defined(__CPU_MB89890_SERIES)
#macro io_sycc symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	CS  ,2)
		__UCHARBIT(	SCS ,1)
		__UCHARBIT(	WT  ,2)
		__UCHARBIT_NONAME(   2)
		__UCHARBIT(	SCM ,1)
	__STRUCT_TYPE_E(bit)
#endm
#endif


/*******************************************************************/
/* Sample program for I/O variables of serial port change circuit. */
/*******************************************************************/
/* structure of SSEL */
#if defined(__CPU_MB89890_SERIES)
#macro io_ssel symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	SPSL,1)
		__UCHARBIT(	SSOE,1)
		__UCHARBIT(	SSKE,1)
		__UCHARBIT(	BPSL,1)
		__UCHARBIT(	BSOE,1)
		__UCHARBIT(	BSKE,1)
		__UCHARBIT_NONAME(   2)
	__STRUCT_TYPE_E(bit)
#endm
#endif


/*********************************************************/
/* Sample program for control registers of standby mode. */
/*********************************************************/
/* structure of STBC */
#if defined(__CPU_MB89800_SERIES) || defined(__CPU_MB89810A_SERIES) || \
    defined(__CPU_MB89820_SERIES) || defined(__CPU_MB89830_SERIES)  || \
    defined(__CPU_MB89850_SERIES) || defined(__CPU_MB89860_SERIES)  || \
    defined(__CPU_MB89863_SERIES) || defined(__CPU_MB89870_SERIES)  || \
    defined(__CPU_MB89880_SERIES) || defined(__CPU_MB89890_SERIES)
#macro io_stbc symbol
	__BYTE_MEM
#if defined(__CPU_MB89800_SERIES) || defined(__CPU_MB89810A_SERIES) || \
    defined(__CPU_MB89870_SERIES) || defined(__CPU_MB89890_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT_NONAME(   3)
		__UCHARBIT(	TMD ,1)
		__UCHARBIT(	RST ,1)
		__UCHARBIT(	SPL ,1)
		__UCHARBIT(	SLP ,1)
		__UCHARBIT(	STP ,1)
	__STRUCT_TYPE_E(bit)
#elif defined(__CPU_MB89820_SERIES) || defined(__CPU_MB89830_SERIES) || \
      defined(__CPU_MB89880_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT_NONAME(   4)
		__UCHARBIT(	RST ,1)
		__UCHARBIT(	SPL ,1)
		__UCHARBIT(	SLP ,1)
		__UCHARBIT(	STP ,1)
	__STRUCT_TYPE_E(bit)
#elif defined(__CPU_MB89850_SERIES) || defined(__CPU_MB89860_SERIES) || \
      defined(__CPU_MB89863_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT_NONAME(   2)
		__UCHARBIT(	OSCS,1)
		__UCHARBIT_NONAME(   1)
		__UCHARBIT(	RST ,1)
		__UCHARBIT(	SPL ,1)
		__UCHARBIT(	SLP ,1)
		__UCHARBIT(	STP ,1)
	__STRUCT_TYPE_E(bit)
#endif
#endm
#endif


/***************************************************************/
/* Sample program for control register of many function timer. */
/***************************************************************/
/* structure of TCSR */
#if defined(__CPU_MB89850_SERIES) || defined(__CPU_MB89860_SERIES) || \
    defined(__CPU_MB89863_SERIES)
#macro io_tcsr symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	TMIR,1)
		__UCHARBIT(	TMIE,1)
		__UCHARBIT(	TZIR,1)
		__UCHARBIT(	TZIE,1)
		__UCHARBIT(	TCIR,1)
		__UCHARBIT(	TCIE,1)
		__UCHARBIT_NONAME(   1)
		__UCHARBIT(	STCR,1)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of CICR */
#if defined(__CPU_MB89850_SERIES) || defined(__CPU_MB89860_SERIES) || \
    defined(__CPU_MB89863_SERIES)
#macro io_cicr symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	CIR0,1)
		__UCHARBIT(	CIR1,1)
		__UCHARBIT(	CIR2,1)
		__UCHARBIT(	CIR3,1)
		__UCHARBIT(	CIE0,1)
		__UCHARBIT(	CIE1,1)
		__UCHARBIT(	CIE2,1)
		__UCHARBIT(	CIE3,1)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of COER */
#if defined(__CPU_MB89850_SERIES) || defined(__CPU_MB89860_SERIES) || \
    defined(__CPU_MB89863_SERIES)
#macro io_coer symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	RTO0,1)
		__UCHARBIT(	RTO1,1)
		__UCHARBIT(	RTO2,1)
		__UCHARBIT(	RTO3,1)
		__UCHARBIT_NONAME(   4)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of TMCR */
#if defined(__CPU_MB89850_SERIES) || defined(__CPU_MB89860_SERIES) || \
    defined(__CPU_MB89863_SERIES)
#macro io_tmcr symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	TCS ,2)
		__UCHARBIT(	CES ,2)
		__UCHARBIT_NONAME(   2)
		__UCHARBIT(	MODE,1)
		__UCHARBIT(	TMST,1)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of CMCR */
#if defined(__CPU_MB89850_SERIES) || defined(__CPU_MB89860_SERIES) || \
    defined(__CPU_MB89863_SERIES)
#macro io_cmcr symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	BFS0,1)
		__UCHARBIT(	BFS1,1)
		__UCHARBIT(	TREN,1)
		__UCHARBIT_NONAME(   5)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of DTCR */
#if defined(__CPU_MB89850_SERIES) || defined(__CPU_MB89860_SERIES) || \
    defined(__CPU_MB89863_SERIES)
#macro io_dtcr symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	DT0 ,1)
		__UCHARBIT_NONAME(   1)
		__UCHARBIT(	DTIF,1)
		__UCHARBIT(	DTIE,1)
		__UCHARBIT_NONAME(   4)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of OCTBR */
#if defined(__CPU_MB89850_SERIES) || defined(__CPU_MB89860_SERIES) || \
    defined(__CPU_MB89863_SERIES)
#macro io_octbr symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	RO0 ,2)
		__UCHARBIT(	RO1 ,2)
		__UCHARBIT(	RO2 ,2)
		__UCHARBIT(	RO3 ,2)
	__STRUCT_TYPE_E(bit)
#endm
#endif


/************************************************************/
/* Sample program for control registers of time base timer. */
/************************************************************/
/* structure of TBTC */
#if defined(__CPU_MB89800_SERIES) || defined(__CPU_MB89810A_SERIES) || \
    defined(__CPU_MB89870_SERIES) || defined(__CPU_MB89890_SERIES)
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

/* structure of TBTC */
#if defined(__CPU_MB89820_SERIES) || defined(__CPU_MB89830_SERIES) || \
    defined(__CPU_MB89850_SERIES) || defined(__CPU_MB89860_SERIES) || \
    defined(__CPU_MB89863_SERIES) || defined(__CPU_MB89880_SERIES)
#macro io_tbtc symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	TBC ,2)
		__UCHARBIT(	TBR ,1)
		__UCHARBIT(	TBOF,1)
		__UCHARBIT(	TBIE,1)
		__UCHARBIT_NONAME(   3)
	__STRUCT_TYPE_E(bit)
#endm
#endif


/******************************************************/
/* Sample program for control registers of PWC timer. */
/******************************************************/
/* structure of PWCR */
#if defined(__CPU_MB89810A_SERIES)
#macro io_pwcr symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	OE  ,1)
		__UCHARBIT(	EN  ,1)
		__UCHARBIT(	SL  ,1)
		__UCHARBIT_NONAME(   5)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of PCR1 */
#if defined(__CPU_MB89800_SERIES) || defined(__CPU_MB89820_SERIES)
#macro io_pcr1 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	BF  ,1)
		__UCHARBIT(	IR  ,1)
		__UCHARBIT(	UF  ,1)
		__UCHARBIT_NONAME(   2)
		__UCHARBIT(	IE  ,1)
		__UCHARBIT_NONAME(   1)
		__UCHARBIT(	EN  ,1)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of PCR2 */
#if defined(__CPU_MB89800_SERIES) || defined(__CPU_MB89820_SERIES)
#macro io_pcr2 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	W   ,2)
		__UCHARBIT(	C   ,2)
		__UCHARBIT_NONAME(   1)
		__UCHARBIT(	TO  ,1)
		__UCHARBIT(	RM  ,1)
		__UCHARBIT(	FC  ,1)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of NCCR */
#if defined(__CPU_MB89800_SERIES) || defined(__CPU_MB89820_SERIES)
#macro io_nccr symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	NCS ,2)
		__UCHARBIT_NONAME(   6)
	__STRUCT_TYPE_E(bit)
#endm
#endif


/****************************************************************/
/* Sample program for buzzer register of buzzer output circuit. */
/****************************************************************/
/* structure of BZCR */
#if defined(__CPU_MB89830_SERIES)
#macro io_bzcr symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	BST ,1)
		__UCHARBIT(	BSEL,1)
		__UCHARBIT(	BOE ,1)
		__UCHARBIT_NONAME(   5)
	__STRUCT_TYPE_E(bit)
#endm
#endif

#if defined(__CPU_MB89890_SERIES)
#macro io_bzcr symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	BZ  ,3)
		__UCHARBIT_NONAME(   5)
	__STRUCT_TYPE_E(bit)
#endm
#endif


/**************************************************************/
/* Sample program for I/O variables of multi pulse generater. */
/**************************************************************/
/* structure of MCNT */
#if defined(__CPU_MB89830_SERIES)
#macro io_mcnt symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	PCN ,2)
		__UCHARBIT(	STRG,1)
		__UCHARBIT(	SPOL,1)
		__UCHARBIT(	CKS ,2)
		__UCHARBIT(	TSL ,2)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of INTSTR */
#if defined(__CPU_MB89830_SERIES)
#macro io_intstr symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	DTIR,1)
		__UCHARBIT(	DTIE,1)
		__UCHARBIT(	CMIR,1)
		__UCHARBIT(	CMIE,1)
		__UCHARBIT(	CLIR,1)
		__UCHARBIT(	CLIE,1)
		__UCHARBIT(	ESL ,2)
	__STRUCT_TYPE_E(bit)
#endm
#endif


/****************************************************/
/* Sample program for I/O variables of modem timer. */
/****************************************************/
/* structure of MDC1 */
#if defined(__CPU_MB89890_SERIES)
#macro io_mdc1 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	MDIF,1)
		__UCHARBIT(	ESL ,2)
		__UCHARBIT(	LOF ,1)
		__UCHARBIT(	HOF ,1)
		__UCHARBIT(	MOIE,1)
		__UCHARBIT(	MSIG,1)
		__UCHARBIT_NONAME(   1)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of MDC2 */
#if defined(__CPU_MB89890_SERIES)
#macro io_mdc2 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	NCS ,2)
		__UCHARBIT(	MCS ,2)
		__UCHARBIT_NONAME(   4)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of MLD */
#if defined(__CPU_MB89890_SERIES)
#macro io_mld symbol
	__WORD_MEM
	__STRUCT_TYPE_B
		__UCHAR(	MLDH)
		__UCHAR(	MLDL)
	__STRUCT_TYPE_E(byte)
#endm
#endif


/********************************************************************/
/* Sample program for I/O variables of modem signal output circuit. */
/********************************************************************/
/* structure of MODC */
#if defined(__CPU_MB89890_SERIES)
#macro io_modc symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	STAT,1)
		__UCHARBIT(	CSL ,2)
		__UCHARBIT_NONAME(   1)
		__UCHARBIT(	MOEN,1)
		__UCHARBIT(	SIOE,1)
		__UCHARBIT(	DEIE,1)
		__UCHARBIT(	HIZE,1)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of MODA */
#if defined(__CPU_MB89890_SERIES)
#macro io_moda symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	MDA0,1)
		__UCHARBIT(	MDA1,1)
		__UCHARBIT_NONAME(   5)
		__UCHARBIT(	DEMP,1)
	__STRUCT_TYPE_E(bit)
#endm
#endif


/**********************************************************************/
/* Sample program for control registers of external interrupt1(eddge) */
/**********************************************************************/
/* structure of EIC1 */
#if defined(__CPU_MB89800_SERIES) || defined(__CPU_MB89810A_SERIES) || \
    defined(__CPU_MB89820_SERIES) || defined(__CPU_MB89830_SERIES)  || \
    defined(__CPU_MB89850_SERIES) || defined(__CPU_MB89860_SERIES)  || \
    defined(__CPU_MB89863_SERIES) || defined(__CPU_MB89880_SERIES)
#macro io_eic1 symbol
	__BYTE_MEM
#if defined(__CPU_MB89863_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	EIE0,1)
		__UCHARBIT(	SL0 ,1)
		__UCHARBIT_NONAME(   1)
		__UCHARBIT(	EIR0,1)
		__UCHARBIT_NONAME(   4)
	__STRUCT_TYPE_E(bit)
#elif defined(__CPU_MB89850_SERIES) || defined(__CPU_MB89860_SERIES) || \
      defined(__CPU_MB89880_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	EIE0,1)
		__UCHARBIT(	SL0 ,1)
		__UCHARBIT_NONAME(   1)
		__UCHARBIT(	EIR0,1)
		__UCHARBIT(	EIE1,1)
		__UCHARBIT(	SL1 ,1)
		__UCHARBIT_NONAME(   1)
		__UCHARBIT(	EIR1,1)
	__STRUCT_TYPE_E(bit)
#else
	__STRUCT_TYPE_B
		__UCHARBIT(	EIE0,1)
		__UCHARBIT(	SL0 ,2)
		__UCHARBIT(	EIR0,1)
		__UCHARBIT(	EIE1,1)
		__UCHARBIT(	SL1 ,2)
		__UCHARBIT(	EIR1,1)
	__STRUCT_TYPE_E(bit)
#endif
#endm
#endif

/* structure of EIC2 */
#if defined(__CPU_MB89810A_SERIES) || defined(__CPU_MB89850_SERIES) || \
    defined(__CPU_MB89860_SERIES)
#macro io_eic2 symbol
	__BYTE_MEM
#if defined(__CPU_MB89850_SERIES) || defined(__CPU_MB89860_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	EIE2,1)
		__UCHARBIT(	SL2 ,1)
		__UCHARBIT_NONAME(   1)
		__UCHARBIT(	EIR2,1)
		__UCHARBIT(	EIE3,1)
		__UCHARBIT(	SL3 ,1)
		__UCHARBIT_NONAME(   1)
		__UCHARBIT(	EIR3,1)
	__STRUCT_TYPE_E(bit)
#else
	__STRUCT_TYPE_B
		__UCHARBIT(	EIE2,1)
		__UCHARBIT(	SL2 ,2)
		__UCHARBIT(	EIR2,1)
		__UCHARBIT(	EIE3,1)
		__UCHARBIT(	SL3 ,2)
		__UCHARBIT(	EIR3,1)
	__STRUCT_TYPE_E(bit)
#endif
#endm
#endif

/* structure of EIE1 */
#if defined(__CPU_MB89870_SERIES)
#macro io_eie1 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	EI4 ,2)
		__UCHARBIT(	EI5 ,2)
		__UCHARBIT(	EI6 ,2)
		__UCHARBIT(	EI7 ,2)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of EIE2 */
#if defined(__CPU_MB89870_SERIES)
#macro io_eie2 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	IE0 ,1)
		__UCHARBIT(	IE1 ,1)
		__UCHARBIT(	IE2 ,1)
		__UCHARBIT(	IE3 ,1)
		__UCHARBIT_NONAME(   2)
		__UCHARBIT(	IF3 ,1)
		__UCHARBIT(	EI3 ,1)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of EIF1 */
#if defined(__CPU_MB89870_SERIES)
#macro io_eif1 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	IE4 ,1)
		__UCHARBIT(	IE5 ,1)
		__UCHARBIT(	IE6 ,1)
		__UCHARBIT(	IE7 ,1)
		__UCHARBIT(	IF4 ,1)
		__UCHARBIT(	IF5 ,1)
		__UCHARBIT(	IF6 ,1)
		__UCHARBIT(	IF7 ,1)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of EIE1 */
#if  defined(__CPU_MB89890_SERIES)
#macro io_eie1 symbol
	__BYTE_MEM
	__STRUCT_TYPE_UNION
		__UCHARBIT(	IE10,1)
		__UCHARBIT(	IE11,1)
		__UCHARBIT(	IE12,1)
		__UCHARBIT(	IE13,1)
		__UCHARBIT(	SIV0,1)
		__UCHARBIT(	SIV1,1)
		__UCHARBIT(	SIV2,1)
		__UCHARBIT(	SIV3,1)
	__STRUCT_TYPE_E(bit)
	__STRUCT_TYPE_UNION
		__UCHARBIT(	IE1 ,4)
		__UCHARBIT(	SIV ,4)
	__STRUCT_TYPE_E(bitc)
#endm
#endif

/* structure of EIF1 */
#if  defined(__CPU_MB89890_SERIES)
#macro io_eif1 symbol
	__BYTE_MEM
	__STRUCT_TYPE_UNION
		__UCHARBIT(	IF10,1)
		__UCHARBIT(	IF11,1)
		__UCHARBIT(	IF12,1)
		__UCHARBIT(	IF13,1)
		__UCHARBIT_NONAME(   4)
	__STRUCT_TYPE_E(bit)
	__STRUCT_TYPE_UNION
		__UCHARBIT(	IF1 ,4)
		__UCHARBIT_NONAME(   4)
	__STRUCT_TYPE_E(bitc)
#endm
#endif


/**********************************************************************/
/* Sample program for control registers of external interrupt2(level) */
/**********************************************************************/
/* structure of EI2E */
#if defined(__CPU_MB89810A_SERIES)
#macro io_ei2e symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	IE4 ,1)
		__UCHARBIT(	IS4 ,1)
		__UCHARBIT(	IE5 ,1)
		__UCHARBIT(	IS5 ,1)
		__UCHARBIT(	IE6 ,1)
		__UCHARBIT(	IS6 ,1)
		__UCHARBIT(	IE7 ,1)
		__UCHARBIT(	IS7 ,1)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of EI2F */
#if defined(__CPU_MB89810A_SERIES)
#macro io_ei2f symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	EIR4,1)
		__UCHARBIT(	EIR5,1)
		__UCHARBIT(	EIR6,1)
		__UCHARBIT(	EIR7,1)
		__UCHARBIT_NONAME(   4)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of EIE2 */
#if  defined(__CPU_MB89890_SERIES)
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
#endif

/* structure of EIF2 */
#if  defined(__CPU_MB89890_SERIES)
#macro io_eif2 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	IF20,1)
		__UCHARBIT(	IE28,1)
		__UCHARBIT_NONAME(   6)
	__STRUCT_TYPE_E(bit)
#endm
#endif


/**************************************************************/
/* Sample program for I/O variable of bus controler(SmallLC). */
/**************************************************************/
/* structure of STR1 */
#if defined(__CPU_MB89880_SERIES)
#macro io_str1 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	TXRDY,1)
		__UCHARBIT(	RXRDY,1)
		__UCHARBIT(	BRC  ,1)
		__UCHARBIT(	ERR  ,1)
		__UCHARBIT(	TX   ,1)
		__UCHARBIT(	CD   ,1)
		__UCHARBIT(	RSMI ,1)
		__UCHARBIT(	INTR ,1)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of STR2 */
#if defined(__CPU_MB89880_SERIES)
#macro io_str2 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	DRE ,1)
		__UCHARBIT(	WSEM,1)
		__UCHARBIT(	AKE ,1)
		__UCHARBIT(	PE  ,1)
		__UCHARBIT(	FE  ,1)
		__UCHARBIT(	RLD ,1)
		__UCHARBIT(	WLD ,1)
		__UCHARBIT(	RDE ,1)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of MDR */
#if defined(__CPU_MB89880_SERIES)
#macro io_mdr symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	MDR ,4)
		__UCHARBIT(	TCS ,1)
		__UCHARBIT(	SIE ,1)
		__UCHARBIT(	SSF ,1)
		__UCHARBIT(	SDF ,1)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of CCR */
#if defined(__CPU_MB89880_SERIES)
#macro io_ccr symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	TIM ,1)
		__UCHARBIT(	RIM ,1)
		__UCHARBIT(	RES ,1)
		__UCHARBIT(	SMI ,1)
		__UCHARBIT(	RTC ,1)
		__UCHARBIT_NONAME(   3)
	__STRUCT_TYPE_E(bit)
#endm
#endif


/*******************************************************/
/* Sample program for I/O variable of watch prescaler. */
/*******************************************************/
/* structure of WPCR */
#if defined(__CPU_MB89810A_SERIES) || defined(__CPU_MB89870_SERIES) || \
    defined(__CPU_MB89890_SERIES)
#macro io_wpcr symbol
	__BYTE_MEM
#if defined(__CPU_MB89810A_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	WCLR,1)
		__UCHARBIT(	WS  ,2)
		__UCHARBIT(	PRSL,1)
		__UCHARBIT_NONAME(   2)
		__UCHARBIT(	WIE ,1)
		__UCHARBIT(	WIF ,1)
	__STRUCT_TYPE_E(bit)
#elif defined(__CPU_MB89890_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	WCLR,1)
		__UCHARBIT(	WS  ,2)
		__UCHARBIT_NONAME(   3)
		__UCHARBIT(	WIE ,1)
		__UCHARBIT(	WIF ,1)
	__STRUCT_TYPE_E(bit)
#else
	__STRUCT_TYPE_B
		__UCHARBIT(	WCLR,1)
		__UCHARBIT(	WS  ,2)
		__UCHARBIT_NONAME(   1)
		__UCHARBIT(	WC  ,2)
		__UCHARBIT(	WIE ,1)
		__UCHARBIT(	WIF ,1)
	__STRUCT_TYPE_E(bit)
#endif
#endm
#endif
