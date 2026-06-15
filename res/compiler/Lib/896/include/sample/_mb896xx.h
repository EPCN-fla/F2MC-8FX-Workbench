/*
 MB896xx Series I/O register declaration file V30L08
 ALL RIGHTS RESERVED, COPYRIGHT (C) FUJITSU LIMITED 1998
 LICENSED MATERIAL - PROGRAM PROPERTY OF FUJITSU LIMITED
*/
#include "_ffmc8ls.h"
#include "_f8ldef.h"

/****************************************************************/
/* Sample program for control registers of 10bit A/D converter. */
/****************************************************************/
/* structure of ADC1 */
#if defined(__CPU_MB89630_SERIES) || defined(__CPU_MB89670_SERIES) || \
    defined(__CPU_MB89690_SERIES)
__UNION io_adc1 __STRUCT_B
	__BYTE_MEM
#if defined(__CPU_MB89630_SERIES) || defined(__CPU_MB89670_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	AD  ,1)
		__UCHARBIT(	SIFM,1)
		__UCHARBIT(	ADMV,1)
		__UCHARBIT(	ADI ,1)
		__UCHARBIT(	ANS ,4)
	__STRUCT_TYPE_E(bit)
#elif defined(__CPU_MB89690_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	AD  ,1)
		__UCHARBIT_NONAME(   1)
		__UCHARBIT(	ADMV,1)
		__UCHARBIT(	ADI ,1)
		__UCHARBIT(	ANS ,4)
	__STRUCT_TYPE_E(bit)
#endif
__STRUCT_E
#endif

/* structure of ADC2 */
#if defined(__CPU_MB89630_SERIES) || defined(__CPU_MB89670_SERIES) || \
    defined(__CPU_MB89690_SERIES)
__UNION io_adc2 __STRUCT_B
	__BYTE_MEM
#if defined(__CPU_MB89630_SERIES) || defined(__CPU_MB89670_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT_NONAME(   1)
		__UCHARBIT(	EXT ,1)
		__UCHARBIT(	ADMD,1)
		__UCHARBIT(	ADIE,1)
		__UCHARBIT(	ADCK,1)
		__UCHARBIT_NONAME(   3)
	__STRUCT_TYPE_E(bit)
#elif defined(__CPU_MB89690_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT_NONAME(   3)
		__UCHARBIT(	ADIE,1)
		__UCHARBIT_NONAME(   4)
	__STRUCT_TYPE_E(bit)
#endif
__STRUCT_E
#endif

/* structure of ADD */
#if defined(__CPU_MB89630_SERIES) || defined(__CPU_MB89670_SERIES) || \
    defined(__CPU_MB89690_SERIES)
__UNION io_add __STRUCT_B
	__WORD_MEM
	__STRUCT_TYPE_B
		__USHORTBIT(	DATA10,10)
		__USHORTBIT_NONAME(     6)
	__STRUCT_TYPE_E(bit)
__STRUCT_E
#endif

/******************************************************/
/* Sample program for I/O variables of input capture. */
/******************************************************/
/* structure of ICCR */
#if defined(__CPU_MB89660_SERIES)
__UNION io_iccr __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	ES0 ,1)
		__UCHARBIT(	ES1 ,1)
		__UCHARBIT(	SFTE,1)
		__UCHARBIT_NONAME(   1)
		__UCHARBIT(	STG0,1)
		__UCHARBIT(	STG1,1)
		__UCHARBIT(	IS  ,1)
		__UCHARBIT_NONAME(   1)
	__STRUCT_TYPE_E(bit)
__STRUCT_E
#endif

/* structure of ICIC */
#if defined(__CPU_MB89660_SERIES)
__UNION io_icic __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	CIR0,1)
		__UCHARBIT(	CIR1,1)
		__UCHARBIT_NONAME(   1)
		__UCHARBIT(	OVF0,1)
		__UCHARBIT(	OVF1,1)
		__UCHARBIT(	CIE0,1)
		__UCHARBIT(	CIE1,1)
		__UCHARBIT_NONAME(   1)
	__STRUCT_TYPE_E(bit)
__STRUCT_E
#endif


/*****************************************************************/
/* Sample program for control registers of 16-bit timer/counter. */
/*****************************************************************/

/*****************************************************/
/* MB89610/610R, MB89620/620R, MB89630/630R, MB89640 */
/* MB89670/670A/670R/670AR Series                    */
/*****************************************************/
/* structure of TMCR */
#if defined(__CPU_MB89610_SERIES) || defined(__CPU_MB89620_SERIES) || \
    defined(__CPU_MB89630_SERIES) || defined(__CPU_MB89640_SERIES) || \
    defined(__CPU_MB89670_SERIES) || defined(__CPU_MB89690_SERIES)
__UNION io_tmcr __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	TCS  ,1)
		__UCHARBIT(	TCIE ,1)
		__UCHARBIT(	TCEF ,1)
		__UCHARBIT(	TCS01,2)
		__UCHARBIT(	TCR  ,1)
		__UCHARBIT_NONAME(    2)
	__STRUCT_TYPE_E(bit)
__STRUCT_E
#endif

/***********************/
/* MB89660/660R Series */
/***********************/
/* structure of TMCR */
#if defined(__CPU_MB89660_SERIES)
__UNION io_tmcr __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	TCS01,2)
		__UCHARBIT(	TMIR ,1)
		__UCHARBIT(	TMIE ,1)
		__UCHARBIT_NONAME(    2)
		__UCHARBIT(	STCR ,1)
		__UCHARBIT(	TMST ,1)
	__STRUCT_TYPE_E(bit)
__STRUCT_E
#endif


/*************************************************************************/
/* Sample program for control registers of serial I/O with 1byte buffer. */
/*************************************************************************/
/* structure of SMR */
#if defined(__CPU_MB89680_SERIES)
__UNION io_smr __STRUCT_B
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
__STRUCT_E
#endif

/* structure of SFR */
#if defined(__CPU_MB89680_SERIES)
__UNION io_sfr __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	SFLF,1)
		__UCHARBIT(	SEMF,1)
		__UCHARBIT(	SOVF,1)
		__UCHARBIT_NONAME(   5)
	__STRUCT_TYPE_E(bit)
__STRUCT_E
#endif


/***************************************************************/
/* Sample program for control registers of 2CH 8bit PWM timer. */
/***************************************************************/
/* structure of CNTR1 */
#if defined(__CPU_MB89630_SERIES) || defined(__CPU_MB89640_SERIES) || \
    defined(__CPU_MB89670_SERIES) || defined(__CPU_MB89690_SERIES)
__UNION io_cntr1 __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	SC2 ,2)
		__UCHARBIT(	SC1 ,2)
		__UCHARBIT(	P7M2,1)
		__UCHARBIT(	P7M1,1)
		__UCHARBIT(	PTX2,1)
		__UCHARBIT(	PTX1,1)
	__STRUCT_TYPE_E(bit)
__STRUCT_E
#endif

/* structure of CNTR2 */
#if defined(__CPU_MB89630_SERIES) || defined(__CPU_MB89640_SERIES) || \
    defined(__CPU_MB89670_SERIES) || defined(__CPU_MB89690_SERIES)
__UNION io_cntr2 __STRUCT_B
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
__STRUCT_E
#endif

/* structure of CNTR3 */
#if defined(__CPU_MB89630_SERIES) || defined(__CPU_MB89640_SERIES) || \
    defined(__CPU_MB89690_SERIES)
__UNION io_cntr3 __STRUCT_B
	__BYTE_MEM
#if defined(__CPU_MB89630_SERIES) || defined(__CPU_MB89690_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT_NONAME(   4)
		__UCHARBIT(	CH12,1)
		__UCHARBIT(	OE3 ,1)
		__UCHARBIT(	OE2 ,1)
		__UCHARBIT_NONAME(   1)
	__STRUCT_TYPE_E(bit)
#elif defined(__CPU_MB89640_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT_NONAME(   4)
		__UCHARBIT(	CH12,1)
		__UCHARBIT(	OE3 ,1)
		__UCHARBIT(	OE2 ,1)
		__UCHARBIT(	OE1 ,1)
	__STRUCT_TYPE_E(bit)
#endif
__STRUCT_E
#endif

/* structure of CNTR3 */
#if defined(__CPU_MB89670_SERIES)
__UNION io_cntr3 __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	OE0 ,1)
		__UCHARBIT(	OE1 ,1)
		__UCHARBIT(	OE2 ,1)
		__UCHARBIT(	OE3 ,1)
		__UCHARBIT(	CH12,1)
		__UCHARBIT_NONAME(   3)
	__STRUCT_TYPE_E(bit)
__STRUCT_E
#endif


/********************************************************************/
/* Sample program for data and control registers of 8/16-bit updown */
/* counter timer.                                                   */
/********************************************************************/
/* structure of UDCR */
#if defined(__CPU_MB89670_SERIES)
__UNION io_udcr __STRUCT_B
	__WORD_MEM
	__STRUCT_TYPE_B
		__UCHAR(	UDCR1)
		__UCHAR(	UDCR2)
	__STRUCT_TYPE_E(byte)
__STRUCT_E
#endif

/* structure of CCRA1 */
#if defined(__CPU_MB89670_SERIES)
__UNION io_ccra1 __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	UDCC,1)
		__UCHARBIT(	CTUT,1)
		__UCHARBIT(	CES ,2)
		__UCHARBIT(	CMS ,2)
		__UCHARBIT(	CLKS,1)
		__UCHARBIT(	MOCH,1)
	__STRUCT_TYPE_E(bit)
__STRUCT_E
#endif

/* structure of CCRA2 */
#if defined(__CPU_MB89670_SERIES)
__UNION io_ccra2 __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	UDCC,1)
		__UCHARBIT(	CTUT,1)
		__UCHARBIT(	CES ,2)
		__UCHARBIT(	CMS ,2)
		__UCHARBIT(	CLKS,1)
		__UCHARBIT_NONAME(   1)
	__STRUCT_TYPE_E(bit)
__STRUCT_E
#endif

/* structure of CCRB */
#if defined(__CPU_MB89670_SERIES)
__UNION io_ccrb __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	CGE ,2)
		__UCHARBIT(	CGSC,1)
		__UCHARBIT(	CDCE,1)
		__UCHARBIT(	CMPE,1)
		__UCHARBIT(	UDFE,1)
		__UCHARBIT(	RLDE,1)
		__UCHARBIT_NONAME(   1)
	__STRUCT_TYPE_E(bit)
__STRUCT_E
#endif

/* structure of CSR */
#if defined(__CPU_MB89670_SERIES)
__UNION io_csr __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	UDF ,2)
		__UCHARBIT(	CDCF,1)
		__UCHARBIT(	CMPF,1)
		__UCHARBIT(	UDFF,1)
		__UCHARBIT(	OVFF,1)
		__UCHARBIT_NONAME(   1)
		__UCHARBIT(	CSTR,1)
	__STRUCT_TYPE_E(bit)
__STRUCT_E
#endif


/********************************************************************/
/* Sample program for data and control registers of 8/16-bit timer. */
/********************************************************************/
/* structure of T1CR */
#if defined(__CPU_MB89650_SERIES) || defined(__CPU_MB89660_SERIES) || \
    defined(__CPU_MB89670_SERIES) || defined(__CPU_MB89680_SERIES)
__UNION io_t1cr __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	T1STR,1)
		__UCHARBIT(	T1STP,1)
		__UCHARBIT(	T1CS ,2)
		__UCHARBIT(	T1OS ,2)
		__UCHARBIT(	T1IE ,1)
		__UCHARBIT(	T1IF ,1)
	__STRUCT_TYPE_E(bit)
__STRUCT_E
#endif

/* structure of T2CR */
#if defined(__CPU_MB89650_SERIES) || defined(__CPU_MB89660_SERIES) || \
    defined(__CPU_MB89670_SERIES) || defined(__CPU_MB89680_SERIES)
__UNION io_t2cr __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	T2STR,1)
		__UCHARBIT(	T2STP,1)
		__UCHARBIT(	T2CS ,2)
		__UCHARBIT(	T2OS ,2)
		__UCHARBIT(	T2IE ,1)
		__UCHARBIT(	T2IF ,1)
	__STRUCT_TYPE_E(bit)
__STRUCT_E
#endif

/* structure of T3CR */
#if defined(__CPU_MB89650_SERIES)
__UNION io_t3cr __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	T3STR,1)
		__UCHARBIT(	T3STP,1)
		__UCHARBIT(	T3CS ,2)
		__UCHARBIT(	T3OS ,2)
		__UCHARBIT(	T3IE ,1)
		__UCHARBIT(	T3IF ,1)
	__STRUCT_TYPE_E(bit)
__STRUCT_E
#endif

/* structure of T4CR */
#if defined(__CPU_MB89650_SERIES)
__UNION io_t4cr __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	T4STR,1)
		__UCHARBIT(	T4STP,1)
		__UCHARBIT(	T4CS ,2)
		__UCHARBIT(	T4OS ,2)
		__UCHARBIT(	T4IE ,1)
		__UCHARBIT(	T4IF ,1)
	__STRUCT_TYPE_E(bit)
__STRUCT_E
#endif

/* structure of T12DR */
#if defined(__CPU_MB89650_SERIES) || defined(__CPU_MB89660_SERIES) || \
    defined(__CPU_MB89670_SERIES) || defined(__CPU_MB89680_SERIES)
__UNION io_t12dr __STRUCT_B
	__WORD_MEM
	__STRUCT_TYPE_B
		__UCHAR(	T2DR)
		__UCHAR(	T1DR)
	__STRUCT_TYPE_E(byte)
__STRUCT_E
#endif

/* structure of T34DR */
#if defined(__CPU_MB89650_SERIES)
__UNION io_t34dr __STRUCT_B
	__WORD_MEM
	__STRUCT_TYPE_B
		__UCHAR(	T4DR)
		__UCHAR(	T3DR)
	__STRUCT_TYPE_E(byte)
__STRUCT_E
#endif


/***************************************************************/
/* Sample program for control registers of 8bit A/D converter. */
/***************************************************************/
/* structure of ADC1 */
#if defined(__CPU_MB89620_SERIES) || defined(__CPU_MB89640_SERIES) || \
    defined(__CPU_MB89650_SERIES) || defined(__CPU_MB89660_SERIES) || \
    defined(__CPU_MB89680_SERIES)
__UNION io_adc1 __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	AD  ,1)
		__UCHARBIT(	SIFM,1)
		__UCHARBIT(	ADMV,1)
		__UCHARBIT(	ADI ,1)
		__UCHARBIT(	ANS ,4)
	__STRUCT_TYPE_E(bit)
__STRUCT_E
#endif

/* structure of ADC2 */
#if defined(__CPU_MB89620_SERIES) || defined(__CPU_MB89640_SERIES) || \
    defined(__CPU_MB89650_SERIES) || defined(__CPU_MB89660_SERIES) || \
    defined(__CPU_MB89680_SERIES)
__UNION io_adc2 __STRUCT_B
	__BYTE_MEM
#if defined(__CPU_MB89620_SERIES) || defined(__CPU_MB89640_SERIES) || \
    defined(__CPU_MB89660_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT_NONAME(   1)
		__UCHARBIT(	EXT ,1)
		__UCHARBIT(	ADMD,1)
		__UCHARBIT(	ADIE,1)
		__UCHARBIT(	ADCK,1)
		__UCHARBIT_NONAME(   3)
	__STRUCT_TYPE_E(bit)
#elif defined(__CPU_MB89650_SERIES) || defined(__CPU_MB89680_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT_NONAME(   1)
		__UCHARBIT(	EXT ,1)
		__UCHARBIT(	ADMD,1)
		__UCHARBIT(	ADIE,1)
		__UCHARBIT_NONAME(   4)
	__STRUCT_TYPE_E(bit)
#endif
__STRUCT_E
#endif


/***********************************************************/
/* Sample program for control registers of 8bit PWM timer. */
/***********************************************************/

/*********************************************************************/
/* MB89601, MB89610/610R, MB89620/620R, MB89660/660R, MB89680 Series */
/*********************************************************************/
/* structure of CNTR */
#if defined(__CPU_MB89601_SERIES) || defined(__CPU_MB89610_SERIES) || \
    defined(__CPU_MB89620_SERIES) || defined(__CPU_MB89660_SERIES) || \
    defined(__CPU_MB89680_SERIES)
__UNION io_cntr __STRUCT_B
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
__STRUCT_E
#endif

/*************************/
/* MB89650A/650AR Series */
/*************************/
/* structure of CNTR */
#if defined(__CPU_MB89650_SERIES)
__UNION io_cntr __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	TIE ,1)
		__UCHARBIT(	OE1 ,1)
		__UCHARBIT(	TIR ,1)
		__UCHARBIT(	TPE ,1)
		__UCHARBIT(	P   ,2)
		__UCHARBIT(	OE2 ,1)
		__UCHARBIT(	P_TX,1)
	__STRUCT_TYPE_E(bit)
__STRUCT_E
#endif

/**********************************/
/* MB89670/670A/670R/670AR Series */
/**********************************/
/* structure of CNTR_3 */
#if defined(__CPU_MB89670_SERIES)
__UNION io_cntr_3 __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	TIE ,1)
		__UCHARBIT(	OE1 ,1)
		__UCHARBIT(	TIR ,1)
		__UCHARBIT(	TPE ,1)
		__UCHARBIT(	P   ,2)
		__UCHARBIT(	OE2 ,1)
		__UCHARBIT(	P_TX,1)
	__STRUCT_TYPE_E(bit)
__STRUCT_E
#endif

/* structure of CNTR_4-6 */
#if defined(__CPU_MB89670A_SERIES)
__UNION io_cntr_n __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	TIE ,1)
		__UCHARBIT(	OE1 ,1)
		__UCHARBIT(	TIR ,1)
		__UCHARBIT(	TPE ,1)
		__UCHARBIT(	P   ,2)
		__UCHARBIT_NONAME(   1)
		__UCHARBIT(	P_TX,1)
	__STRUCT_TYPE_E(bit)
__STRUCT_E
#endif


/*************************************************************/
/* Sample program for control registers of 8-bit serial I/O. */
/*************************************************************/
/* structure of SMR */
#if defined(__CPU_MB89601_SERIES) || defined(__CPU_MB89610_SERIES) || \
    defined(__CPU_MB89620_SERIES) || defined(__CPU_MB89630_SERIES) || \
    defined(__CPU_MB89640_SERIES) || defined(__CPU_MB89650_SERIES) || \
    defined(__CPU_MB89660_SERIES) || defined(__CPU_MB89670_SERIES) || \
    defined(__CPU_MB89690_SERIES)
__UNION io_smr __STRUCT_B
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
__STRUCT_E
#endif


/**********************************************************/
/* Sample program for control registers of D/A converter. */
/**********************************************************/
/* structure of DACR */
#if defined(__CPU_MB89640_SERIES)
__UNION io_dacr __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT_NONAME(   4)
		__UCHARBIT(	STP2,1)
		__UCHARBIT(	STP1,1)
		__UCHARBIT(	E2  ,1)
		__UCHARBIT(	E1  ,1)
	__STRUCT_TYPE_E(bit)
__STRUCT_E
#endif


/*****************************************************/
/* Sample program for control registers of I/O port. */
/*****************************************************/
/* structure of PDR0 */
#if defined(__CPU_MB89601_SERIES) || defined(__CPU_MB89610_SERIES) || \
    defined(__CPU_MB89620_SERIES) || defined(__CPU_MB89630_SERIES) || \
    defined(__CPU_MB89640_SERIES) || defined(__CPU_MB89650_SERIES) || \
    defined(__CPU_MB89660_SERIES) || defined(__CPU_MB89670_SERIES) || \
    defined(__CPU_MB89680_SERIES) || defined(__CPU_MB89690_SERIES)
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
#endif

/* structure of PDR1 */
#if defined(__CPU_MB89601_SERIES) || defined(__CPU_MB89610_SERIES) || \
    defined(__CPU_MB89620_SERIES) || defined(__CPU_MB89630_SERIES) || \
    defined(__CPU_MB89640_SERIES) || defined(__CPU_MB89650_SERIES) || \
    defined(__CPU_MB89660_SERIES) || defined(__CPU_MB89670_SERIES) || \
    defined(__CPU_MB89680_SERIES) || defined(__CPU_MB89690_SERIES)
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
#endif

/* structure of PDR2 */
#if defined(__CPU_MB89610_SERIES) || defined(__CPU_MB89620_SERIES) || \
    defined(__CPU_MB89630_SERIES) || defined(__CPU_MB89640_SERIES) || \
    defined(__CPU_MB89650_SERIES) || defined(__CPU_MB89660_SERIES) || \
    defined(__CPU_MB89670_SERIES) || defined(__CPU_MB89680_SERIES) || \
    defined(__CPU_MB89690_SERIES)
__UNION io_pdr2 __STRUCT_B
	__BYTE_MEM
#if defined(__CPU_MB89610_SERIES) || defined(__CPU_MB89620_SERIES) || \
    defined(__CPU_MB89630_SERIES) || defined(__CPU_MB89640_SERIES) || \
    defined(__CPU_MB89660_SERIES) || defined(__CPU_MB89670_SERIES) || \
    defined(__CPU_MB89680_SERIES) || defined(__CPU_MB89690_SERIES)
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
#elif defined(__CPU_MB89650_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	P20 ,1)
		__UCHARBIT(	P21 ,1)
		__UCHARBIT(	P22 ,1)
		__UCHARBIT_NONAME(   1)
		__UCHARBIT(	P24 ,1)
		__UCHARBIT(	P25 ,1)
		__UCHARBIT(	P26 ,1)
		__UCHARBIT_NONAME(   1)
	__STRUCT_TYPE_E(bit)
#endif
__STRUCT_E
#endif

/* structure of PDR3 */
#if defined(__CPU_MB89601_SERIES) || defined(__CPU_MB89610_SERIES) || \
    defined(__CPU_MB89620_SERIES) || defined(__CPU_MB89630_SERIES) || \
    defined(__CPU_MB89640_SERIES) || defined(__CPU_MB89650_SERIES) || \
    defined(__CPU_MB89660_SERIES) || defined(__CPU_MB89670_SERIES) || \
    defined(__CPU_MB89680_SERIES) || defined(__CPU_MB89690_SERIES)
__UNION io_pdr3 __STRUCT_B
	__BYTE_MEM
#if defined(__CPU_MB89601_SERIES) || defined(__CPU_MB89610_SERIES) || \
    defined(__CPU_MB89620_SERIES) || defined(__CPU_MB89630_SERIES) || \
    defined(__CPU_MB89640_SERIES) || defined(__CPU_MB89650_SERIES) || \
    defined(__CPU_MB89660_SERIES) || defined(__CPU_MB89670_SERIES) || \
    defined(__CPU_MB89680_SERIES)
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
#elif defined(__CPU_MB89690_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	P30 ,1)
		__UCHARBIT(	P31 ,1)
		__UCHARBIT(	P32 ,1)
		__UCHARBIT(	P33 ,1)
		__UCHARBIT(	P34 ,1)
		__UCHARBIT(	P35 ,1)
		__UCHARBIT_NONAME(   1)
		__UCHARBIT(	P37 ,1)
	__STRUCT_TYPE_E(bit)
#endif
__STRUCT_E
#endif

/* structure of PDR4 */
#if defined(__CPU_MB89601_SERIES) || defined(__CPU_MB89610_SERIES) || \
    defined(__CPU_MB89620_SERIES) || defined(__CPU_MB89630_SERIES) || \
    defined(__CPU_MB89640_SERIES) || defined(__CPU_MB89650_SERIES) || \
    defined(__CPU_MB89660_SERIES) || defined(__CPU_MB89670_SERIES) || \
    defined(__CPU_MB89680_SERIES) || defined(__CPU_MB89690_SERIES)
__UNION io_pdr4 __STRUCT_B
	__BYTE_MEM
#if defined(__CPU_MB89601_SERIES) || defined(__CPU_MB89610_SERIES) || \
    defined(__CPU_MB89620_SERIES) || defined(__CPU_MB89640_SERIES) || \
    defined(__CPU_MB89650_SERIES) || defined(__CPU_MB89660_SERIES) || \
    defined(__CPU_MB89670_SERIES) || defined(__CPU_MB89690_SERIES)
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
#elif defined(__CPU_MB89630_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	P40 ,1)
		__UCHARBIT(	P41 ,1)
		__UCHARBIT(	P42 ,1)
		__UCHARBIT(	P43 ,1)
		__UCHARBIT_NONAME(   4)
	__STRUCT_TYPE_E(bit)
#elif defined(__CPU_MB89680_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	P40 ,1)
		__UCHARBIT(	P41 ,1)
		__UCHARBIT(	P42 ,1)
		__UCHARBIT(	P43 ,1)
		__UCHARBIT(	P44 ,1)
		__UCHARBIT_NONAME(   3)
	__STRUCT_TYPE_E(bit)
#endif
__STRUCT_E
#endif

/* structure of PDR5 */
#if defined(__CPU_MB89610_SERIES) || defined(__CPU_MB89620_SERIES) || \
    defined(__CPU_MB89630_SERIES) || defined(__CPU_MB89640_SERIES) || \
    defined(__CPU_MB89650_SERIES) || defined(__CPU_MB89660_SERIES) || \
    defined(__CPU_MB89670_SERIES) || defined(__CPU_MB89680_SERIES) || \
    defined(__CPU_MB89690_SERIES)
__UNION io_pdr5 __STRUCT_B
	__BYTE_MEM
#if defined(__CPU_MB89610_SERIES) || defined(__CPU_MB89620_SERIES) || \
    defined(__CPU_MB89640_SERIES) || defined(__CPU_MB89650_SERIES) || \
    defined(__CPU_MB89660_SERIES) || defined(__CPU_MB89670_SERIES) || \
    defined(__CPU_MB89680_SERIES) || defined(__CPU_MB89690_SERIES)
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
#elif defined(__CPU_MB89630_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	P50 ,1)
		__UCHARBIT(	P51 ,1)
		__UCHARBIT(	P52 ,1)
		__UCHARBIT(	P53 ,1)
		__UCHARBIT_NONAME(   4)
	__STRUCT_TYPE_E(bit)
#endif
__STRUCT_E
#endif

/* structure of PDR6 */
#if defined(__CPU_MB89601_SERIES) || defined(__CPU_MB89610_SERIES) || \
    defined(__CPU_MB89620_SERIES) || defined(__CPU_MB89630_SERIES) || \
    defined(__CPU_MB89640_SERIES) || defined(__CPU_MB89650_SERIES) || \
    defined(__CPU_MB89660_SERIES) || defined(__CPU_MB89670_SERIES) || \
    defined(__CPU_MB89680_SERIES) || defined(__CPU_MB89690_SERIES)
__UNION io_pdr6 __STRUCT_B
	__BYTE_MEM
#if defined(__CPU_MB89601_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	P60 ,1)
		__UCHARBIT_NONAME(   7)
	__STRUCT_TYPE_E(bit)
#elif defined(__CPU_MB89610_SERIES)  || defined(__CPU_MB89620_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	P60 ,1)
		__UCHARBIT(	P61 ,1)
		__UCHARBIT(	P62 ,1)
		__UCHARBIT(	P63 ,1)
		__UCHARBIT(	P64 ,1)
		__UCHARBIT_NONAME(   3)
	__STRUCT_TYPE_E(bit)
#elif defined(__CPU_MB89630_SERIES) || defined(__CPU_MB89640_SERIES) || \
      defined(__CPU_MB89650_SERIES) || defined(__CPU_MB89670_SERIES) || \
      defined(__CPU_MB89680_SERIES)
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
#elif defined(__CPU_MB89660_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	P60 ,1)
		__UCHARBIT(	P61 ,1)
		__UCHARBIT(	P62 ,1)
		__UCHARBIT(	P63 ,1)
		__UCHARBIT_NONAME(   4)
	__STRUCT_TYPE_E(bit)
#elif defined(__CPU_MB89690_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	P60 ,1)
		__UCHARBIT(	P61 ,1)
		__UCHARBIT(	P62 ,1)
		__UCHARBIT_NONAME(   5)
	__STRUCT_TYPE_E(bit)
#endif
__STRUCT_E
#endif

/* structure of PDR7 */
#if defined(__CPU_MB89630_SERIES) || defined(__CPU_MB89640_SERIES) || \
    defined(__CPU_MB89650_SERIES) || defined(__CPU_MB89670_SERIES) || \
    defined(__CPU_MB89680_SERIES)
__UNION io_pdr7 __STRUCT_B
	__BYTE_MEM
#if defined(__CPU_MB89630_SERIES) || defined(__CPU_MB89640_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	P70 ,1)
		__UCHARBIT(	P71 ,1)
		__UCHARBIT(	P72 ,1)
		__UCHARBIT(	P73 ,1)
		__UCHARBIT(	P74 ,1)
		__UCHARBIT_NONAME(   3)
	__STRUCT_TYPE_E(bit)
#elif defined(__CPU_MB89650_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	P70 ,1)
		__UCHARBIT(	P71 ,1)
		__UCHARBIT(	P72 ,1)
		__UCHARBIT(	P73 ,1)
		__UCHARBIT(	P74 ,1)
		__UCHARBIT(	P75 ,1)
		__UCHARBIT_NONAME(   2)
	__STRUCT_TYPE_E(bit)
#elif defined(__CPU_MB89670_SERIES)
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
#elif defined(__CPU_MB89680_SERIES)
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
__STRUCT_E
#endif

/* structure of PDR8 */
#if defined(__CPU_MB89640_SERIES) || defined(__CPU_MB89650_SERIES) || \
    defined(__CPU_MB89670_SERIES) || defined(__CPU_MB89680_SERIES)
__UNION io_pdr8 __STRUCT_B
	__BYTE_MEM
#if defined(__CPU_MB89640_SERIES) || defined(__CPU_MB89650_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	P80 ,1)
		__UCHARBIT(	P81 ,1)
		__UCHARBIT(	P82 ,1)
		__UCHARBIT(	P83 ,1)
		__UCHARBIT_NONAME(   4)
	__STRUCT_TYPE_E(bit)
#elif defined(__CPU_MB89670_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	P80 ,1)
		__UCHARBIT(	P81 ,1)
		__UCHARBIT(	P82 ,1)
		__UCHARBIT(	P83 ,1)
		__UCHARBIT(	P84 ,1)
		__UCHARBIT(	P85 ,1)
		__UCHARBIT_NONAME(   2)
	__STRUCT_TYPE_E(bit)
#elif defined(__CPU_MB89680_SERIES)
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
#endif
__STRUCT_E
#endif

/* structure of PDR9 */
#if defined(__CPU_MB89680_SERIES)
__UNION io_pdr9 __STRUCT_B
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
__STRUCT_E
#endif

/* structure of PDRA */
#if defined(__CPU_MB89680_SERIES)
__UNION io_pdra __STRUCT_B
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
__STRUCT_E
#endif

/* structure of DDR3 */
#if defined(__CPU_MB89680_SERIES) || defined(__CPU_MB89690_SERIES)
__UNION io_ddr3 __STRUCT_B
	__BYTE_MEM
#if defined(__CPU_MB89680_SERIES)
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
#elif defined(__CPU_MB89690_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	P30 ,1)
		__UCHARBIT(	P31 ,1)
		__UCHARBIT(	P32 ,1)
		__UCHARBIT(	P33 ,1)
		__UCHARBIT(	P34 ,1)
		__UCHARBIT(	P35 ,1)
		__UCHARBIT_NONAME(   1)
		__UCHARBIT(	P37 ,1)
	__STRUCT_TYPE_E(bit)
#endif
__STRUCT_E
#endif

/* structure of DDR4 */
#if defined(__CPU_MB89690_SERIES)
__UNION io_ddr4 __STRUCT_B
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
#endif

/* structure of DDR6 */
#if defined(__CPU_MB89680_SERIES) || defined(__CPU_MB89690_SERIES)
__UNION io_ddr6 __STRUCT_B
	__BYTE_MEM
#if defined(__CPU_MB89680_SERIES)
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
#elif defined(__CPU_MB89690_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	P60 ,1)
		__UCHARBIT(	P61 ,1)
		__UCHARBIT(	P62 ,1)
		__UCHARBIT_NONAME(   5)
	__STRUCT_TYPE_E(bit)
#endif
__STRUCT_E
#endif

/* structure of DDR9 */
#if defined(__CPU_MB89680_SERIES)
__UNION io_ddr9 __STRUCT_B
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
__STRUCT_E
#endif

/* structure of DDRA */
#if defined(__CPU_MB89680_SERIES)
__UNION io_ddra __STRUCT_B
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
__STRUCT_E
#endif

/* structure of SPCR */
#if defined(__CPU_MB89601_SERIES)
__UNION io_spcr __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	P30P,1)
		__UCHARBIT(	P31P,1)
		__UCHARBIT(	P32P,1)
		__UCHARBIT(	P33P,1)
		__UCHARBIT(	P347,1)
		__UCHARBIT_NONAME(   3)
	__STRUCT_TYPE_E(bit)
__STRUCT_E
#endif

/* structure of CHG3 */
#if defined(__CPU_MB89630_SERIES)
__UNION io_chg3 __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT_NONAME(   3)
		__UCHARBIT(	CG33,1)
		__UCHARBIT(	CG34,1)
		__UCHARBIT(	CG35,1)
		__UCHARBIT_NONAME(   2)
	__STRUCT_TYPE_E(bit)
__STRUCT_E
#endif

/* structure of CHG2 */
#if defined(__CPU_MB89650_SERIES)
__UNION io_chg2 __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT_NONAME(    3)
		__UCHARBIT(	LCKE ,1)
		__UCHARBIT(	HCKE ,1)
		__UCHARBIT(	CHG2 ,1)
		__UCHARBIT_NONAME(    2)
	__STRUCT_TYPE_E(bit)
__STRUCT_E
#endif

/* structure of PPCR */
#if defined(__CPU_MB89670_SERIES)
__UNION io_ppcr __STRUCT_B
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
#endif


/**********************************************************************/
/* Sample program for control registers of LAN communication circuit. */
/**********************************************************************/
/* structure of CTLREG1 */
#if defined(__CPU_MB89690_SERIES)
__UNION io_ctlreg1 __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT_NONAME(   1)
		__UCHARBIT(	OE  ,1)
		__UCHARBIT(	S1EN,1)
		__UCHARBIT(	RIRQ,1)
		__UCHARBIT(	RIEN,1)
		__UCHARBIT(	TIRQ,1)
		__UCHARBIT(	TIEN,1)
		__UCHARBIT(	EN  ,1)
	__STRUCT_TYPE_E(bit)
__STRUCT_E
#endif

/* structure of CTLREG2 */
#if defined(__CPU_MB89690_SERIES)
__UNION io_ctlreg2 __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	OVTIMS,1)
		__UCHARBIT(	MLER  ,1)
		__UCHARBIT(	RSPEN ,1)
		__UCHARBIT(	CRCON ,1)
		__UCHARBIT(	SKIP  ,1)
		__UCHARBIT_NONAME(     3)
	__STRUCT_TYPE_E(bit)
__STRUCT_E
#endif

/* structure of MLREG */
#if defined(__CPU_MB89690_SERIES)
__UNION io_mlreg __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	MSLEN,4)
		__UCHARBIT_NONAME(    4)
	__STRUCT_TYPE_E(bit)
__STRUCT_E
#endif

/* structure of STATREG1 */
#if defined(__CPU_MB89690_SERIES)
__UNION io_statreg1 __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT_NONAME(    3)
		__UCHARBIT(	TDEC ,1)
		__UCHARBIT(	LABR ,1)
		__UCHARBIT(	RSPER,1)
		__UCHARBIT(	UNRUN,1)
		__UCHARBIT(	SOFER,1)
	__STRUCT_TYPE_E(bit)
__STRUCT_E
#endif

/* structure of STATREG2 */
#if defined(__CPU_MB89690_SERIES)
__UNION io_statreg2 __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT_NONAME(    1)
		__UCHARBIT(	RXEND,1)
		__UCHARBIT(	OVRUN,1)
		__UCHARBIT(	MKER ,1)
		__UCHARBIT(	CRCER,1)
		__UCHARBIT(	STFER,1)
		__UCHARBIT(	FMER ,1)
		__UCHARBIT(	LENER,1)
	__STRUCT_TYPE_E(bit)
__STRUCT_E
#endif


/*****************************************************************/
/* Sample program for control registers of LCD controler/driver. */
/*****************************************************************/
/* structure of LCR1 */
#if defined(__CPU_MB89650_SERIES)
__UNION io_lcr1 __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	FP  ,2)
		__UCHARBIT(	MS  ,2)
		__UCHARBIT(	BK  ,1)
		__UCHARBIT(	VSEL,1)
		__UCHARBIT(	LCEN,1)
		__UCHARBIT(	CSS ,1)
	__STRUCT_TYPE_E(bit)
__STRUCT_E
#endif

/* structure of LCR2 */
#if defined(__CPU_MB89650_SERIES)
__UNION io_lcr2 __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	SEG01,2)
		__UCHARBIT(	SEG2 ,1)
		__UCHARBIT(	SEG3 ,1)
		__UCHARBIT(	SEG4 ,1)
		__UCHARBIT(	SEG5 ,1)
		__UCHARBIT(	COM0 ,1)
		__UCHARBIT(	COM1 ,1)
	__STRUCT_TYPE_E(bit)
__STRUCT_E
#endif

/* structure of VRAM */
#if defined(__CPU_MB89650_SERIES)
__UNION io_vram  __STRUCT_B
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
#endif


/*********************************************/
/* Sample program for I/O variables of UART. */
/*********************************************/

/**********************************************/
/* MB89630/630R, MB89660/660R, MB89680,       */
/* MB89690A Series                            */
/**********************************************/
/* structure of SMC */
#if defined(__CPU_MB89630_SERIES) || defined(__CPU_MB89660_SERIES) || \
    defined(__CPU_MB89680_SERIES) || defined(__CPU_MB89690_SERIES)
__UNION io_smc __STRUCT_B
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
__STRUCT_E
#endif

/* structure of SRC */
#if defined(__CPU_MB89630_SERIES)  || defined(__CPU_MB89660_SERIES) || \
    defined(__CPU_MB89680_SERIES)  || defined(__CPU_MB89690_SERIES)
__UNION io_src __STRUCT_B
	__BYTE_MEM
#if defined(__CPU_MB89630_SERIES)  || defined(__CPU_MB89660_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	RC  ,3)
		__UCHARBIT(	CS  ,2)
		__UCHARBIT(	CR  ,1)
		__UCHARBIT_NONAME(   2)
	__STRUCT_TYPE_E(bit)
#elif defined(__CPU_MB89680_SERIES) || defined(__CPU_MB89690_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	RC  ,3)
		__UCHARBIT(	CS  ,2)
		__UCHARBIT(	CR  ,1)
		__UCHARBIT(	CK  ,2)
	__STRUCT_TYPE_E(bit)
#endif
__STRUCT_E
#endif

/* structure of SSD */
#if defined(__CPU_MB89630_SERIES) || defined(__CPU_MB89660_SERIES) || \
    defined(__CPU_MB89680_SERIES) || defined(__CPU_MB89690_SERIES)
__UNION io_ssd __STRUCT_B
	__BYTE_MEM
#if defined(__CPU_MB89630_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	RD8_RP,1)
		__UCHARBIT(	TD8_TP,1)
		__UCHARBIT(	PSEL  ,1)
		__UCHARBIT(	RIE   ,1)
		__UCHARBIT(	TIE   ,1)
		__UCHARBIT(	TDRE  ,1)
		__UCHARBIT(	ORFE  ,1)
		__UCHARBIT(	RDRF  ,1)
	__STRUCT_TYPE_E(bit)
#elif defined(__CPU_MB89660_SERIES) || defined(__CPU_MB89680_SERIES) || \
      defined(__CPU_MB89690_SERIES)
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
#endif
__STRUCT_E
#endif

/**********************************/
/* MB89670/670A/670R/670AR Series */
/**********************************/
/* structure of USMR */
#if defined(__CPU_MB89670_SERIES)
__UNION io_usmr __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	CS  ,3)
		__UCHARBIT(	CL  ,1)
		__UCHARBIT(	SBL ,1)
		__UCHARBIT(	TDP ,1)
		__UCHARBIT(	PEN ,1)
		__UCHARBIT(	MD  ,1)
	__STRUCT_TYPE_E(bit)
__STRUCT_E
#endif

/* structure of USCR */
#if defined(__CPU_MB89670_SERIES)
__UNION io_uscr __STRUCT_B
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
#endif

/* structure of USTR */
#if defined(__CPU_MB89670_SERIES)
__UNION io_ustr __STRUCT_B
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
#endif


/*******************************************************/
/* Sample program for I/O variables of output compare. */
/*******************************************************/
/* structure of OPCR */
#if defined(__CPU_MB89660_SERIES)
__UNION io_opcr __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	RTO0,1)
		__UCHARBIT(	OUT0,1)
		__UCHARBIT(	CIE0,1)
		__UCHARBIT(	CIR0,1)
		__UCHARBIT(	RTO1,1)
		__UCHARBIT(	OUT1,1)
		__UCHARBIT(	CIE1,1)
		__UCHARBIT(	CIR1,1)
	__STRUCT_TYPE_E(bit)
__STRUCT_E
#endif


/**********************************************************/
/* Sample program for control registers of clock monitor. */
/**********************************************************/
/* structure of CLKE */
#if defined(__CPU_MB89620_SERIES)
__UNION io_clke __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	CLKEN,1)
		__UCHARBIT_NONAME(    7)
	__STRUCT_TYPE_E(bit)
__STRUCT_E
#endif


/*********************************************************/
/* Sample program for control registers of system clock. */
/*********************************************************/
/* structure of SYCC */
#if defined(__CPU_MB89630_SERIES) || defined(__CPU_MB89640_SERIES) || \
    defined(__CPU_MB89650_SERIES) || defined(__CPU_MB89670_SERIES) || \
    defined(__CPU_MB89680_SERIES) || defined(__CPU_MB89690_SERIES)
__UNION io_sycc __STRUCT_B
	__BYTE_MEM
#if defined(__CPU_MB89630_SERIES) || defined(__CPU_MB89640_SERIES) || \
    defined(__CPU_MB89650_SERIES) || defined(__CPU_MB89680_SERIES) || \
    defined(__CPU_MB89690_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	CS  ,2)
		__UCHARBIT(	SCS ,1)
		__UCHARBIT(	WT  ,2)
		__UCHARBIT_NONAME(   2)
		__UCHARBIT(	SCM ,1)
	__STRUCT_TYPE_E(bit)
#elif defined(__CPU_MB89670_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	CS  ,2)
		__UCHARBIT_NONAME(   1)
		__UCHARBIT(	WT  ,2)
		__UCHARBIT_NONAME(   3)
	__STRUCT_TYPE_E(bit)
#endif
__STRUCT_E
#endif


/*******************************************************************/
/* Sample program for control registers of serial I/O port change. */
/*******************************************************************/
/* structure of SSEL */
#if defined(__CPU_MB89680_SERIES)
__UNION io_ssel __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	UPSL,1)
		__UCHARBIT(	USOE,1)
		__UCHARBIT(	USKE,1)
		__UCHARBIT(	BPSL,1)
		__UCHARBIT(	BSOE,1)
		__UCHARBIT(	BSKE,1)
		__UCHARBIT_NONAME(   2)
	__STRUCT_TYPE_E(bit)
__STRUCT_E
#endif


/*********************************************************/
/* Sample program for control registers of standby mode. */
/*********************************************************/
/* structure of STBC */
#if defined(__CPU_MB89601_SERIES) || defined(__CPU_MB89610_SERIES) || \
    defined(__CPU_MB89620_SERIES) || defined(__CPU_MB89630_SERIES) || \
    defined(__CPU_MB89640_SERIES) || defined(__CPU_MB89650_SERIES) || \
    defined(__CPU_MB89660_SERIES) || defined(__CPU_MB89670_SERIES) || \
    defined(__CPU_MB89680_SERIES) || defined(__CPU_MB89690_SERIES)
__UNION io_stbc __STRUCT_B
	__BYTE_MEM
#if defined(__CPU_MB89601_SERIES) || defined(__CPU_MB89610_SERIES) || \
    defined(__CPU_MB89620_SERIES) || defined(__CPU_MB89660_SERIES) || \
    defined(__CPU_MB89670_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT_NONAME(   4)
		__UCHARBIT(	RST ,1)
		__UCHARBIT(	SPL ,1)
		__UCHARBIT(	SLP ,1)
		__UCHARBIT(	STP ,1)
	__STRUCT_TYPE_E(bit)
#elif defined(__CPU_MB89630_SERIES) || defined(__CPU_MB89640_SERIES) || \
      defined(__CPU_MB89650_SERIES) || defined(__CPU_MB89680_SERIES) || \
      defined(__CPU_MB89690_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT_NONAME(   3)
		__UCHARBIT(	TMD ,1)
		__UCHARBIT(	RST ,1)
		__UCHARBIT(	SPL ,1)
		__UCHARBIT(	SLP ,1)
		__UCHARBIT(	STP ,1)
	__STRUCT_TYPE_E(bit)
#endif
__STRUCT_E
#endif


/************************************************************/
/* Sample program for control registers of time base timer. */
/************************************************************/

/************************************************************/
/* MB89601, MB89610/610R, MB89620/620R, MB89660/660R Series */
/************************************************************/
/* structure of TBTC */
#if defined(__CPU_MB89601_SERIES) || defined(__CPU_MB89610_SERIES) || \
    defined(__CPU_MB89620_SERIES) || defined(__CPU_MB89660_SERIES)
__UNION io_tbtc __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	TBC ,2)
		__UCHARBIT(	TBR ,1)
		__UCHARBIT(	TBOF,1)
		__UCHARBIT(	TBIE,1)
		__UCHARBIT_NONAME(   3)
	__STRUCT_TYPE_E(bit)
__STRUCT_E
#endif

/*******************************************/
/* MB89630/630R, MB89640, MB89650A/650AR,  */
/* MB89670/670A/670R/670AR, MB89680 Series */
/*******************************************/
/* structure of TBTC */
#if defined(__CPU_MB89630_SERIES) || defined(__CPU_MB89640_SERIES) || \
    defined(__CPU_MB89650_SERIES) || defined(__CPU_MB89670_SERIES) || \
    defined(__CPU_MB89680_SERIES) || defined(__CPU_MB89690_SERIES)
__UNION io_tbtc __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	TBR ,1)
		__UCHARBIT(	TBC ,2)
		__UCHARBIT_NONAME(   3)
		__UCHARBIT(	TBIE,1)
		__UCHARBIT(	TBOF,1)
	__STRUCT_TYPE_E(bit)
__STRUCT_E
#endif


/******************************************************/
/* Sample program for control registers of PWC timer. */
/******************************************************/
/* structure of PCR1 */
#if defined(__CPU_MB89610_SERIES) || defined(__CPU_MB89620_SERIES) || \
    defined(__CPU_MB89630_SERIES) || defined(__CPU_MB89640_SERIES)
__UNION io_pcr1 __STRUCT_B
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
__STRUCT_E
#endif

/* structure of PCR2 */
#if defined(__CPU_MB89610_SERIES) || defined(__CPU_MB89620_SERIES) || \
    defined(__CPU_MB89630_SERIES) || defined(__CPU_MB89640_SERIES)
__UNION io_pcr2 __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	W   ,2)
		__UCHARBIT(	C   ,2)
		__UCHARBIT_NONAME(   1)
		__UCHARBIT(	TO  ,1)
		__UCHARBIT(	RM  ,1)
		__UCHARBIT(	FC  ,1)
	__STRUCT_TYPE_E(bit)
__STRUCT_E
#endif


/*********************************************************/
/* Sample program for control registers of buzer output. */
/*********************************************************/
/* structure of BZCR */
#if defined(__CPU_MB89610_SERIES) || defined(__CPU_MB89620_SERIES) || \
    defined(__CPU_MB89630_SERIES) || defined(__CPU_MB89640_SERIES) || \
    defined(__CPU_MB89670_SERIES) || defined(__CPU_MB89680_SERIES)
__UNION io_bzcr __STRUCT_B
	__BYTE_MEM
#if defined(__CPU_MB89610_SERIES) || defined(__CPU_MB89620_SERIES) || \
    defined(__CPU_MB89630_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	BZ  ,2)
		__UCHARBIT_NONAME(   6)
	__STRUCT_TYPE_E(bit)
#elif defined(__CPU_MB89640_SERIES) || defined(__CPU_MB89670_SERIES) || \
      defined(__CPU_MB89680_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	BZ  ,3)
		__UCHARBIT_NONAME(   5)
	__STRUCT_TYPE_E(bit)
#endif
__STRUCT_E
#endif


/*************************************************************/
/* Sample program for control registers of Pull-up resistor. */
/*************************************************************/
/* structure of P0UP */
#if defined(__CPU_MB89690_SERIES)
__UNION io_p0up __STRUCT_B
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
#endif

/* structure of P1UP */
#if defined(__CPU_MB89690_SERIES)
__UNION io_p1up __STRUCT_B
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
#endif

/* structure of P3UP */
#if defined(__CPU_MB89690_SERIES)
__UNION io_p3up __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	PUR30,1)
		__UCHARBIT(	PUR31,1)
		__UCHARBIT(	PUR32,1)
		__UCHARBIT(	PUR33,1)
		__UCHARBIT(	PUR34,1)
		__UCHARBIT(	PUR35,1)
		__UCHARBIT_NONAME(    1)
		__UCHARBIT(	PUR37,1)
	__STRUCT_TYPE_E(bit)
__STRUCT_E
#endif

/* structure of P4UP */
#if defined(__CPU_MB89690_SERIES)
__UNION io_p4up __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	PUR40,1)
		__UCHARBIT(	PUR41,1)
		__UCHARBIT(	PUR42,1)
		__UCHARBIT(	PUR43,1)
		__UCHARBIT(	PUR44,1)
		__UCHARBIT(	PUR45,1)
		__UCHARBIT(	PUR46,1)
		__UCHARBIT(	PUR47,1)
	__STRUCT_TYPE_E(bit)
__STRUCT_E
#endif

/* structure of P6UP */
#if defined(__CPU_MB89690_SERIES)
__UNION io_p6up __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	PUR60,1)
		__UCHARBIT(	PUR61,1)
		__UCHARBIT(	PUR62,1)
		__UCHARBIT_NONAME(    5)
	__STRUCT_TYPE_E(bit)
__STRUCT_E
#endif


/****************************************************************/
/* Sample program for control registers of modem signal output. */
/****************************************************************/
/* structure of MODC */
#if defined(__CPU_MB89680_SERIES)
__UNION io_modc __STRUCT_B
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
__STRUCT_E
#endif

/* structure of MODA */
#if defined(__CPU_MB89680_SERIES)
__UNION io_moda __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	MDA0,1)
		__UCHARBIT(	MDA1,1)
		__UCHARBIT_NONAME(   5)
		__UCHARBIT(	DEMP,1)
	__STRUCT_TYPE_E(bit)
__STRUCT_E
#endif


/********************************************************/
/* Sample program for control registers of modem timer. */
/********************************************************/
/* structure of MDC1 */
#if defined(__CPU_MB89680_SERIES)
__UNION io_mdc1 __STRUCT_B
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
__STRUCT_E
#endif

/* structure of MDC2 */
#if defined(__CPU_MB89680_SERIES)
__UNION io_mdc2 __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	NCS ,2)
		__UCHARBIT(	MCS ,2)
		__UCHARBIT_NONAME(   4)
	__STRUCT_TYPE_E(bit)
__STRUCT_E
#endif

/* structure of MLD */
#if defined(__CPU_MB89680_SERIES)
__UNION io_mld __STRUCT_B
	__WORD_MEM
	__STRUCT_TYPE_B
		__UCHAR(	MLDH)
		__UCHAR(	MLDL)
	__STRUCT_TYPE_E(byte)
__STRUCT_E
#endif


/*************************************************************/
/* Sample program for I/O variables of reset flag registers. */
/*************************************************************/
/* structure of RSFR */
#if defined(__CPU_MB89690_SERIES)
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
#endif


/**********************************************************************/
/* Sample program for control registers of external interrupt0 pin    */
/**********************************************************************/
/* structure of EISR */
#if defined(__CPU_MB89690_SERIES)
__UNION io_eisr __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	EIS ,1)
		__UCHARBIT_NONAME(   7)
	__STRUCT_TYPE_E(bit)
__STRUCT_E
#endif


/**********************************************************************/
/* Sample program for control registers of external interrupt1(eddge) */
/**********************************************************************/
/* structure of EIC */
#if defined(__CPU_MB89601_SERIES) || defined(__CPU_MB89610_SERIES) || \
    defined(__CPU_MB89620_SERIES) || defined(__CPU_MB89630_SERIES) || \
    defined(__CPU_MB89640_SERIES) || defined(__CPU_MB89660_SERIES) || \
    defined(__CPU_MB89670_SERIES) || defined(__CPU_MB89690_SERIES)
__UNION io_eic1 __STRUCT_B
	__BYTE_MEM
#if defined(__CPU_MB89601_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	EIE0,1)
		__UCHARBIT(	SL0 ,1)
		__UCHARBIT_NONAME(   1)
		__UCHARBIT(	EIR0,1)
		__UCHARBIT_NONAME(   4)
	__STRUCT_TYPE_E(bit)
#elif defined(__CPU_MB89610_SERIES) || defined(__CPU_MB89620_SERIES) || \
      defined(__CPU_MB89630_SERIES) || defined(__CPU_MB89640_SERIES)
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
__STRUCT_E
#endif

/* structure of EIC2 */
#if defined(__CPU_MB89610_SERIES) || defined(__CPU_MB89620_SERIES) || \
    defined(__CPU_MB89630_SERIES) || defined(__CPU_MB89640_SERIES) || \
    defined(__CPU_MB89660_SERIES) || defined(__CPU_MB89670_SERIES) || \
    defined(__CPU_MB89690_SERIES)
__UNION io_eic2 __STRUCT_B
	__BYTE_MEM
#if defined(__CPU_MB89610_SERIES) || defined(__CPU_MB89620_SERIES) || \
    defined(__CPU_MB89630_SERIES) || defined(__CPU_MB89640_SERIES)
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
__STRUCT_E
#endif

/* structure of EIE1 */
#if defined(__CPU_MB89650_SERIES) || defined(__CPU_MB89680_SERIES)
__UNION io_eie1 __STRUCT_B
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
__STRUCT_E
#endif

/* structure of EIF1 */
#if defined(__CPU_MB89650_SERIES) || defined(__CPU_MB89680_SERIES)
__UNION io_eif1 __STRUCT_B
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
__STRUCT_E
#endif


/**********************************************************************/
/* Sample program for control registers of external interrupt1(level) */
/**********************************************************************/
/* structure of EIE2 */
#if defined(__CPU_MB89640_SERIES) || defined(__CPU_MB89650_SERIES) || \
    defined(__CPU_MB89680_SERIES)
__UNION io_eie2 __STRUCT_B
	__BYTE_MEM
#if defined(__CPU_MB89640_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	IE20,1)
		__UCHARBIT(	IE21,1)
		__UCHARBIT(	IE22,1)
		__UCHARBIT(	IE23,1)
		__UCHARBIT(	IE24,1)
		__UCHARBIT_NONAME(   3)
	__STRUCT_TYPE_E(bit)
#else
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
#endif
__STRUCT_E
#endif

/* structure of EIE2 */
#if defined(__CPU_MB89670_SERIES)
__UNION io_eie2 __STRUCT_B
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
__STRUCT_E
#endif

/* structure of EIF2 */
#if defined(__CPU_MB89640_SERIES) || defined(__CPU_MB89650_SERIES) || \
    defined(__CPU_MB89680_SERIES)
__UNION io_eif2 __STRUCT_B
	__BYTE_MEM
#if defined(__CPU_MB89640_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	IF20,1)
		__UCHARBIT_NONAME(   7)
	__STRUCT_TYPE_E(bit)
#else
	__STRUCT_TYPE_B
		__UCHARBIT(	IF20,1)
		__UCHARBIT(	IE28,1)
		__UCHARBIT_NONAME(   6)
	__STRUCT_TYPE_E(bit)
#endif
__STRUCT_E
#endif

/* structure of EIF2 */
#if defined(__CPU_MB89670_SERIES)
__UNION io_eif2 __STRUCT_B
	__BYTE_MEM
	__STRUCT_TYPE_B
		__UCHARBIT(	EIR4,1)
		__UCHARBIT(	EIR5,1)
		__UCHARBIT(	EIR6,1)
		__UCHARBIT(	EIR7,1)
		__UCHARBIT_NONAME(   4)
	__STRUCT_TYPE_E(bit)
__STRUCT_E
#endif


/*******************************************************/
/* Sample program for I/O variable of watch prescaler. */
/*******************************************************/
/* structure of WPCR */
#if defined(__CPU_MB89630_SERIES) || defined(__CPU_MB89640_SERIES) || \
    defined(__CPU_MB89650_SERIES) || defined(__CPU_MB89680_SERIES) || \
    defined(__CPU_MB89690_SERIES)
__UNION io_wpcr __STRUCT_B
	__BYTE_MEM
#if defined(__CPU_MB89630_SERIES) || defined(__CPU_MB89640_SERIES) || \
    defined(__CPU_MB89680_SERIES) || defined(__CPU_MB89690_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	WCLR,1)
		__UCHARBIT(	WS  ,2)
		__UCHARBIT_NONAME(   3)
		__UCHARBIT(	WIE ,1)
		__UCHARBIT(	WIF ,1)
	__STRUCT_TYPE_E(bit)
#elif defined(__CPU_MB89650_SERIES)
	__STRUCT_TYPE_B
		__UCHARBIT(	WCLR,1)
		__UCHARBIT(	WS  ,2)
		__UCHARBIT_NONAME(   1)
		__UCHARBIT(	WC  ,2)
		__UCHARBIT(	WIE ,1)
		__UCHARBIT(	WIF ,1)
	__STRUCT_TYPE_E(bit)
#endif
__STRUCT_E
#endif
