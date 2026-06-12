/*
 MB891xx Series I/O register declaration file V30L08
 ALL RIGHTS RESERVED, COPYRIGHT (C) FUJITSU LIMITED 1998
 LICENSED MATERIAL - PROGRAM PROPERTY OF FUJITSU LIMITED
*/
#include "_ffmc8ls.h"
#include "_f8ldef.h"

/******************************************************/
/* Sample program for I/O variables of A/D converter. */
/******************************************************/
/* structure of ADC1 */
#if defined(__CPU_MB89130_SERIES)  || defined(__CPU_MB89140_SERIES) || \
    defined(__CPU_MB89143A_SERIES) || defined(__CPU_MB89160_SERIES) || \
    defined(__CPU_MB89190_SERIES)
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
#if defined(__CPU_MB89130_SERIES)  || defined(__CPU_MB89140_SERIES) || \
    defined(__CPU_MB89143A_SERIES) || defined(__CPU_MB89160_SERIES) || \
    defined(__CPU_MB89190_SERIES)
#macro io_adc2 symbol
	__BYTE_MEM
#if defined(__CPU_MB89140_SERIES)
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
		__UCHARBIT_NONAME(   3)
	__STRUCT_TYPE_E(bit)
#endif
#endm
#endif

/* structure of ADDH/ADDL*/
#if defined(__CPU_MB89140_SERIES) || defined(__CPU_MB89143A_SERIES)
#macro io_add symbol
	__WORD_MEM
#if defined(__CPU_MB89143A_SERIES)
	__STRUCT_TYPE_B
		__USHORTBIT_NONAME(   2)
		__USHORTBIT(	DATA8,8)
		__USHORTBIT_NONAME(   6)
	__STRUCT_TYPE_E(bit)
#else
	__STRUCT_TYPE_B
		__USHORTBIT(	DATA10,10)
		__USHORTBIT_NONAME(     6)
	__STRUCT_TYPE_E(bit)
#endif
#endm
#endif


/********************************************************************/
/* Sample program for data and control registers of 8/16-bit timer. */
/********************************************************************/
/* structure of T1CR */
#if defined(__CPU_MB89120_SERIES) || defined(__CPU_MB89130_SERIES)  || \
    defined(__CPU_MB89140_SERIES) || defined(__CPU_MB89143A_SERIES) || \
    defined(__CPU_MB89150_SERIES) || defined(__CPU_MB89160_SERIES)  || \
    defined(__CPU_MB89170_SERIES) || defined(__CPU_MB89180_SERIES)  || \
    defined(__CPU_MB89190_SERIES)
#macro io_t1cr symbol
	__BYTE_MEM
#if defined(__CPU_MB89140_SERIES) || defined(__CPU_MB89143A_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	T1STR,1)
		__UCHARBIT(	T1STP,1)
		__UCHARBIT(	T1CS ,2)
		__UCHARBIT_NONAME(    2)
		__UCHARBIT(	T1IE ,1)
		__UCHARBIT(	T1IF ,1)
	__STRUCT_TYPE_E(bit)
#else
	__STRUCT_TYPE_B
		__UCHARBIT(	T1STR,1)
		__UCHARBIT(	T1STP,1)
		__UCHARBIT(	T1CS ,2)
		__UCHARBIT(	T1OS ,2)
		__UCHARBIT(	T1IE ,1)
		__UCHARBIT(	T1IF ,1)
	__STRUCT_TYPE_E(bit)
#endif
#endm
#endif

/* structure of T2CR */
#if defined(__CPU_MB89120_SERIES) || defined(__CPU_MB89130_SERIES)  || \
    defined(__CPU_MB89140_SERIES) || defined(__CPU_MB89143A_SERIES) || \
    defined(__CPU_MB89150_SERIES) || defined(__CPU_MB89160_SERIES)  || \
    defined(__CPU_MB89170_SERIES) || defined(__CPU_MB89180_SERIES)  || \
    defined(__CPU_MB89190_SERIES)
#macro io_t2cr symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	T2STR,1)
		__UCHARBIT(	T2STP,1)
		__UCHARBIT(	T2CS ,2)
		__UCHARBIT_NONAME(    2)
		__UCHARBIT(	T2IE ,1)
		__UCHARBIT(	T2IF ,1)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of T12DR */
#if defined(__CPU_MB89120_SERIES) || defined(__CPU_MB89130_SERIES)  || \
    defined(__CPU_MB89140_SERIES) || defined(__CPU_MB89143A_SERIES) || \
    defined(__CPU_MB89150_SERIES) || defined(__CPU_MB89160_SERIES)  || \
    defined(__CPU_MB89170_SERIES) || defined(__CPU_MB89180_SERIES)  || \
    defined(__CPU_MB89190_SERIES)
#macro io_t12dr symbol
	__WORD_MEM
	__STRUCT_TYPE_B
		__UCHAR(	T2DR)
		__UCHAR(	T1DR)
	__STRUCT_TYPE_E(byte)
#endm
#endif


/********************************************************/
/* Sample program for I/O variables of 8-bit PWM timer. */
/********************************************************/
/* structure of CNTR */
#if defined(__CPU_MB89140_SERIES) || defined(__CPU_MB89160_SERIES)
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


/*******************************************************************/
/* Sample program for mode and data registers of 8-bit serial I/O. */
/*******************************************************************/
/* structure of SMR */
#if defined(__CPU_MB89120_SERIES) || defined(__CPU_MB89130_SERIES)  || \
    defined(__CPU_MB89140_SERIES) || defined(__CPU_MB89143A_SERIES) || \
    defined(__CPU_MB89150_SERIES) || defined(__CPU_MB89160_SERIES)  || \
    defined(__CPU_MB89170_SERIES) || defined(__CPU_MB89180_SERIES)  || \
    defined(__CPU_MB89190_SERIES)
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
#if defined(__CPU_MB89170_SERIES)
#macro io_dtmc symbol
	__BYTE_MEM
#if defined(__CPU_MB89170A__)  || defined(__CPU_MB89174A__)  || \
    defined(__CPU_MB89P175A__) || defined(__CPU_MB89PV170A__)
	__STRUCT_TYPE_B
		__UCHARBIT(	OUTE,1)
		__UCHARBIT(	RDIS,1)
		__UCHARBIT(	CDIS,1)
		__UCHARBIT(	CSEL,1)
		__UCHARBIT_NONAME(   4)
	__STRUCT_TYPE_E(bit)
#else
	__STRUCT_TYPE_B
		__UCHARBIT(	OUTE,1)
		__UCHARBIT(	RDIS,1)
		__UCHARBIT(	CDIS,1)
		__UCHARBIT_NONAME(   5)
	__STRUCT_TYPE_E(bit)
#endif
#endm
#endif

/* structure of DTMD */
#if defined(__CPU_MB89170_SERIES)
#macro io_dtmd symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	DDAT,4)
		__UCHARBIT_NONAME(   4)
	__STRUCT_TYPE_E(bit)
#endm
#endif


/*****************************************************/
/* Sample program for control registers of I/O port. */
/*****************************************************/
/* structure of PDR0 */
#if defined(__CPU_MB89120_SERIES) || defined(__CPU_MB89130_SERIES)  || \
    defined(__CPU_MB89140_SERIES) || defined(__CPU_MB89143A_SERIES) || \
    defined(__CPU_MB89150_SERIES) || defined(__CPU_MB89160_SERIES)  || \
    defined(__CPU_MB89170_SERIES) || defined(__CPU_MB89180_SERIES)  || \
    defined(__CPU_MB89190_SERIES)
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
#if defined(__CPU_MB89120_SERIES) || defined(__CPU_MB89130_SERIES)  || \
    defined(__CPU_MB89140_SERIES) || defined(__CPU_MB89143A_SERIES) || \
    defined(__CPU_MB89150_SERIES) || defined(__CPU_MB89160_SERIES)  || \
    defined(__CPU_MB89170_SERIES) || defined(__CPU_MB89180_SERIES)
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
#if defined(__CPU_MB89120_SERIES) || defined(__CPU_MB89130_SERIES)  || \
    defined(__CPU_MB89140_SERIES) || defined(__CPU_MB89143A_SERIES) || \
    defined(__CPU_MB89150_SERIES) || defined(__CPU_MB89160_SERIES)  || \
    defined(__CPU_MB89170_SERIES) || defined(__CPU_MB89180_SERIES)
#macro io_pdr2 symbol
	__BYTE_MEM
#if defined(__CPU_MB89140_SERIES) || defined(__CPU_MB89143A_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	P20 ,1)
		__UCHARBIT(	P21 ,1)
		__UCHARBIT(	P22 ,1)
		__UCHARBIT(	P23 ,1)
		__UCHARBIT_NONAME(   4)
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
#if defined(__CPU_MB89120_SERIES) || defined(__CPU_MB89130_SERIES)  || \
    defined(__CPU_MB89140_SERIES) || defined(__CPU_MB89143A_SERIES) || \
    defined(__CPU_MB89150_SERIES) || defined(__CPU_MB89160_SERIES)  || \
    defined(__CPU_MB89170_SERIES) || defined(__CPU_MB89180_SERIES)  || \
    defined(__CPU_MB89190_SERIES)
#macro io_pdr3 symbol
	__BYTE_MEM
#if defined(__CPU_MB89150_SERIES) || defined(__CPU_MB89180_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	P30 ,1)
		__UCHARBIT(	P31 ,1)
		__UCHARBIT(	P32 ,1)
		__UCHARBIT_NONAME(   5)
	__STRUCT_TYPE_E(bit)
#elif defined(__CPU_MB89160_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	P30 ,1)
		__UCHARBIT(	P31 ,1)
		__UCHARBIT(	P32 ,1)
		__UCHARBIT(	P33 ,1)
		__UCHARBIT_NONAME(   4)
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
#if defined(__CPU_MB89120_SERIES) || defined(__CPU_MB89130_SERIES)  || \
    defined(__CPU_MB89140_SERIES) || defined(__CPU_MB89143A_SERIES) || \
    defined(__CPU_MB89150_SERIES) || defined(__CPU_MB89160_SERIES)  || \
    defined(__CPU_MB89170_SERIES) || defined(__CPU_MB89180_SERIES)  || \
    defined(__CPU_MB89190_SERIES)
#macro io_pdr4 symbol
	__BYTE_MEM
#if defined(__CPU_MB89120_SERIES) || defined(__CPU_MB89130_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	P40 ,1)
		__UCHARBIT(	P41 ,1)
		__UCHARBIT(	P42 ,1)
		__UCHARBIT(	P43 ,1)
		__UCHARBIT_NONAME(   4)
	__STRUCT_TYPE_E(bit)
#elif defined(__CPU_MB89170_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	P40 ,1)
		__UCHARBIT(	P41 ,1)
		__UCHARBIT(	P42 ,1)
		__UCHARBIT(	P43 ,1)
		__UCHARBIT(	P44 ,1)
		__UCHARBIT_NONAME(   3)
	__STRUCT_TYPE_E(bit)
#elif defined(__CPU_MB89190_SERIES)
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
#if defined(__CPU_MB89140_SERIES) || defined(__CPU_MB89143A_SERIES) || \
    defined(__CPU_MB89150_SERIES) || defined(__CPU_MB89160_SERIES)  || \
    defined(__CPU_MB89180_SERIES)
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
#endif

/* structure of PDR6 */
#if defined(__CPU_MB89140_SERIES) || defined(__CPU_MB89143A_SERIES) || \
    defined(__CPU_MB89160_SERIES)
#macro io_pdr6 symbol
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
#endm
#endif

/* structure of PDR7 */
#if defined(__CPU_MB89140_SERIES) || defined(__CPU_MB89143A_SERIES) || \
    defined(__CPU_MB89160_SERIES)
#macro io_pdr7 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	P70 ,1)
		__UCHARBIT(	P71 ,1)
		__UCHARBIT_NONAME(   6)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of ENI0 */
#if defined(__CPU_MB89190_SERIES)
#macro io_eni0 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	P00 ,1)
		__UCHARBIT(	P01 ,1)
		__UCHARBIT(	P02 ,1)
		__UCHARBIT(	P03 ,1)
		__UCHARBIT_NONAME(   4)
	__STRUCT_TYPE_E(bit)
#endm
#endif


/*****************************************************************/
/* Sample program for control registers of LCD controler/driver. */
/*****************************************************************/
/* structure of LCR */
#if defined(__CPU_MB89150_SERIES) || defined(__CPU_MB89160_SERIES) || \
    defined(__CPU_MB89180_SERIES)
#macro io_lcr symbol
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

/* structure of VRAM */
#if defined(__CPU_MB89150_SERIES) || defined(__CPU_MB89160_SERIES) || \
    defined(__CPU_MB89180_SERIES)
#macro io_vram symbol
#if   defined(__CPU_MB89150_SERIES)
	__WORD_MEM_A(9)
	__BYTE_MEM_A(18)
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
	__STRUCT_TYPE_E(COM0123)
#elif defined(__CPU_MB89160_SERIES)
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
#elif defined(__CPU_MB89180_SERIES)
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
#endif
#endm
#endif


/************************************************************/
/* Sample program for I/O variables of clock control block. */
/************************************************************/
/* structure of SYCC */
#if defined(__CPU_MB89120_SERIES) || defined(__CPU_MB89130_SERIES)  || \
    defined(__CPU_MB89140_SERIES) || defined(__CPU_MB89143A_SERIES) || \
    defined(__CPU_MB89150_SERIES) || defined(__CPU_MB89160_SERIES)  || \
    defined(__CPU_MB89170_SERIES) || defined(__CPU_MB89180_SERIES)
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


/*************************************************************/
/* Sample program for I/O variables of low power controller. */
/*************************************************************/
/* structure of STBC */
#if defined(__CPU_MB89120_SERIES) || defined(__CPU_MB89130_SERIES)  || \
    defined(__CPU_MB89140_SERIES) || defined(__CPU_MB89143A_SERIES) || \
    defined(__CPU_MB89150_SERIES) || defined(__CPU_MB89160_SERIES)  || \
    defined(__CPU_MB89170_SERIES) || defined(__CPU_MB89180_SERIES)  || \
    defined(__CPU_MB89190_SERIES)
#macro io_stbc symbol
	__BYTE_MEM
#if defined(__CPU_MB89190_SERIES)
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
#if defined(__CPU_MB89120_SERIES) || defined(__CPU_MB89130_SERIES)  || \
    defined(__CPU_MB89140_SERIES) || defined(__CPU_MB89143A_SERIES) || \
    defined(__CPU_MB89150_SERIES) || defined(__CPU_MB89160_SERIES)  || \
    defined(__CPU_MB89170_SERIES) || defined(__CPU_MB89180_SERIES)  || \
    defined(__CPU_MB89190_SERIES)
#macro io_tbtc symbol
	__BYTE_MEM
#if defined(__CPU_MB89190_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	TBC ,2)
		__UCHARBIT(	TBR ,1)
		__UCHARBIT(	TBOF,1)
		__UCHARBIT(	TBIE,1)
		__UCHARBIT_NONAME(   3)
	__STRUCT_TYPE_E(bit)
#else
	__STRUCT_TYPE_B
		__UCHARBIT(	TBR ,1)
		__UCHARBIT(	TBC ,2)
		__UCHARBIT_NONAME(   3)
		__UCHARBIT(	TBIE,1)
		__UCHARBIT(	TBOF,1)
	__STRUCT_TYPE_E(bit)
#endif
#endm
#endif


/****************************************************************/
/* Sample program for buzzer register of buzzer output circuit. */
/****************************************************************/
/* structure of BZCR */
#if defined(__CPU_MB89120_SERIES) || defined(__CPU_MB89130_SERIES)  || \
    defined(__CPU_MB89140_SERIES) || defined(__CPU_MB89143A_SERIES) || \
    defined(__CPU_MB89150_SERIES) || defined(__CPU_MB89160_SERIES)  || \
    defined(__CPU_MB89170_SERIES) || defined(__CPU_MB89180_SERIES)  || \
    defined(__CPU_MB89190_SERIES)
#macro io_bzcr symbol
	__BYTE_MEM
#if defined(__CPU_MB89140_SERIES) || defined(__CPU_MB89143A_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	BZ  ,2)
		__UCHARBIT_NONAME(   6)
	__STRUCT_TYPE_E(bit)
#else
	__STRUCT_TYPE_B
		__UCHARBIT(	BZ  ,3)
		__UCHARBIT_NONAME(   5)
	__STRUCT_TYPE_E(bit)
#endif
#endm
#endif


/**************************************************************/
/* Sample program for I/O variables of multi pulse generater. */
/**************************************************************/
/* structure of MCNT */
#if defined(__CPU_MB89140_SERIES)
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
#if defined(__CPU_MB89140_SERIES)
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


/*************************************************************/
/* Sample program for control registers of remote controler. */
/*************************************************************/
/* structure of RCR1 */
#if defined(__CPU_MB89120_SERIES) || defined(__CPU_MB89130_SERIES) || \
    defined(__CPU_MB89150_SERIES) || defined(__CPU_MB89160_SERIES) || \
    defined(__CPU_MB89180_SERIES) || defined(__CPU_MB89190_SERIES)
#macro io_rcr1 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	HSC ,6)
		__UCHARBIT(	RCK ,2)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of RCR2 */
#if defined(__CPU_MB89120_SERIES) || defined(__CPU_MB89130_SERIES) || \
    defined(__CPU_MB89150_SERIES) || defined(__CPU_MB89160_SERIES) || \
    defined(__CPU_MB89180_SERIES) || defined(__CPU_MB89190_SERIES)
#macro io_rcr2 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	SCL ,6)
		__UCHARBIT_NONAME(   1)
		__UCHARBIT(	RCEN,1)
	__STRUCT_TYPE_E(bit)
#endm
#endif


/**********************************************************************/
/* Sample program for control registers of external interrupt1(eddge) */
/**********************************************************************/
/* structure of EIC,EIC1 */
#if defined(__CPU_MB89120_SERIES) || defined(__CPU_MB89130_SERIES)  || \
    defined(__CPU_MB89140_SERIES) || defined(__CPU_MB89143A_SERIES) || \
    defined(__CPU_MB89170_SERIES) || defined(__CPU_MB89190_SERIES)
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
#if defined(__CPU_MB89120_SERIES) || defined(__CPU_MB89130_SERIES) || \
    defined(__CPU_MB89170_SERIES) || defined(__CPU_MB89190_SERIES)
#macro io_eic2 symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	EIE2,1)
		__UCHARBIT(	SL2 ,2)
		__UCHARBIT(	EIR2,1)
		__UCHARBIT_NONAME(   4)
	__STRUCT_TYPE_E(bit)
#endm
#endif

/* structure of EIE1 */
#if defined(__CPU_MB89150_SERIES) || defined(__CPU_MB89160_SERIES) || \
    defined(__CPU_MB89180_SERIES)
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
#if defined(__CPU_MB89150_SERIES) || defined(__CPU_MB89160_SERIES) || \
    defined(__CPU_MB89180_SERIES)
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
/* structure of EIE2 */
#if defined(__CPU_MB89120_SERIES) || defined(__CPU_MB89130_SERIES) || \
    defined(__CPU_MB89150_SERIES) || defined(__CPU_MB89160_SERIES) || \
    defined(__CPU_MB89170_SERIES) || defined(__CPU_MB89180_SERIES) || \
    defined(__CPU_MB89190_SERIES)
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
#if defined(__CPU_MB89120_SERIES) || defined(__CPU_MB89130_SERIES) || \
    defined(__CPU_MB89150_SERIES) || defined(__CPU_MB89160_SERIES) || \
    defined(__CPU_MB89170_SERIES) || defined(__CPU_MB89180_SERIES) || \
    defined(__CPU_MB89190_SERIES)
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
#if defined(__CPU_MB89120_SERIES) || defined(__CPU_MB89130_SERIES)  || \
    defined(__CPU_MB89140_SERIES) || defined(__CPU_MB89143A_SERIES) || \
    defined(__CPU_MB89150_SERIES) || defined(__CPU_MB89160_SERIES)  || \
    defined(__CPU_MB89170_SERIES) || defined(__CPU_MB89180_SERIES)
#macro io_wpcr symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	WCLR,1)
		__UCHARBIT(	WS  ,2)
		__UCHARBIT_NONAME(   3)
		__UCHARBIT(	WIE ,1)
		__UCHARBIT(	WIF ,1)
	__STRUCT_TYPE_E(bit)
#endm
#endif


/************************************************/
/* Sample program for control register of SCGC. */
/************************************************/
/* structure of SCGC */
#if defined(__CPU_MB89120_SERIES) || defined(__CPU_MB89130_SERIES)
#macro io_scgc symbol
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	SCG ,2)
		__UCHARBIT_NONAME(   6)
	__STRUCT_TYPE_E(bit)
#endm
#endif
