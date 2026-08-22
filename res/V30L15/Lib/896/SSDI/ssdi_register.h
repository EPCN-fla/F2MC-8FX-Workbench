/*
    FFMC-8L SOFTUNE Workbench Simulator Debugger Interface
        Register Number
                            Copyright (c) 2003-2014 Spansion
*/
/*-- Class --*/
#define	RCLS_FIELD	0xE000
#define	RCLS_NON	0x0000
#define	RCLS_FLAGS	0x2000		/* Flags */
#define	RCLS_TWOREG	0x4000		/* IP,FP */
#define	RCLS_SP		0x6000		/* SP */

/*-- Feild --*/
#define	RFLD_FIELD	0x1F00
#define	RFLD_NON	0x0000		/* No Flags */

/*-- Field PS reg ---*/
#define	RFLD_CCR	0x0000		/* CCR */
#define	RFLD_C		0x0100		/*  C  */
#define	RFLD_V		0x0200		/*  V  */
#define	RFLD_Z		0x0300		/*  Z  */
#define	RFLD_N		0x0400		/*  N  */
#define	RFLD_I		0x0500		/*  I  */
#define	RFLD_H		0x0600		/*  H  */
#define	RFLD_RP		0x0700		/* RP  */
#define	RFLD_IL		0x0800		/* IL  */
#define	RFLD_IL0	0x0900		/* IL0 */
#define	RFLD_IL1	0x0a00		/* IL1 */
#define	RFLD_FLAG	0x0b00		/* FLAGS */

/* Feild of A register */
#define	RFLD_AL		0x0000		/* AL  */
#define	RFLD_AH		0x0100		/* AH  */
/* Feild of T register */
#define	RFLD_TL		0x0000		/* TL  */
#define	RFLD_TH		0x0100		/* TH  */

/*-- Register --*/
#define	REGF_FIELD	0x00FF
#define	REGF_A		0x0000		/* A   */
#define	REGF_T		0x0001		/* T   */
#define	REGF_IX		0x0002		/* IX  */
#define	REGF_SP		0x0003		/* PS  */
#define	REGF_EP		0x0004		/* EP  */
#define	REGF_PS		0x0005		/* PS  */
#define	REGF_PC		0x0006		/* PC  */
#define	REGF_R0		0x0010		/* R0  */
#define	REGF_R1		0x0011		/* R1  */
#define	REGF_R2		0x0012		/* R2  */
#define	REGF_R3		0x0013		/* R3  */
#define	REGF_R4		0x0014		/* R4  */
#define	REGF_R5		0x0015		/* R5  */
#define	REGF_R6		0x0016		/* R6  */
#define	REGF_R7		0x0017		/* R7  */

/*--- Register Number ---*/
#define	REG_A		(RCLS_NON    | RFLD_NON | REGF_A)
#define	REG_AL		(RCLS_FLAGS  | RFLD_AL  | REGF_A)
#define	REG_AH		(RCLS_FLAGS  | RFLD_AH  | REGF_A)
#define	REG_T		(RCLS_NON    | RFLD_NON | REGF_T)
#define	REG_TL		(RCLS_FLAGS  | RFLD_TL  | REGF_T)
#define	REG_TH		(RCLS_FLAGS  | RFLD_TH  | REGF_T)
#define	REG_IX		(RCLS_NON    | RFLD_NON | REGF_IX)
#define	REG_EP		(RCLS_NON    | RFLD_NON | REGF_EP)
#define	REG_PS		(RCLS_NON    | RFLD_NON | REGF_PS)
#define	REG_CCR		(RCLS_FLAGS  | RFLD_CCR | REGF_PS)
#define	REG_FLAG	(RCLS_FLAGS  | RFLD_FLAG| REGF_PS)
#define	REG_C		(RCLS_FLAGS  | RFLD_C   | REGF_PS)
#define	REG_V		(RCLS_FLAGS  | RFLD_V   | REGF_PS)
#define	REG_Z		(RCLS_FLAGS  | RFLD_Z   | REGF_PS)
#define	REG_N		(RCLS_FLAGS  | RFLD_N   | REGF_PS)
#define	REG_I		(RCLS_FLAGS  | RFLD_I   | REGF_PS)
#define	REG_H		(RCLS_FLAGS  | RFLD_H   | REGF_PS)
#define	REG_RP		(RCLS_FLAGS  | RFLD_RP  | REGF_PS)
#define	REG_IL		(RCLS_FLAGS  | RFLD_IL  | REGF_PS)
#define	REG_IL0		(RCLS_FLAGS  | RFLD_IL0 | REGF_PS)
#define	REG_IL1		(RCLS_FLAGS  | RFLD_IL1 | REGF_PS)
#define	REG_PC		(RCLS_NON    | RFLD_NON | REGF_PC)
#define	REG_R0		(RCLS_NON    | RFLD_NON | REGF_R0)
#define	REG_R1		(RCLS_NON    | RFLD_NON | REGF_R1)
#define	REG_R2		(RCLS_NON    | RFLD_NON | REGF_R2)
#define	REG_R3		(RCLS_NON    | RFLD_NON | REGF_R3)
#define	REG_R4		(RCLS_NON    | RFLD_NON | REGF_R4)
#define	REG_R5		(RCLS_NON    | RFLD_NON | REGF_R5)
#define	REG_R6		(RCLS_NON    | RFLD_NON | REGF_R6)
#define	REG_R7		(RCLS_NON    | RFLD_NON | REGF_R7)
#define	REG_IP		(RCLS_TWOREG | RFLD_NON | REGF_PC)
#define	REG_FP		(RCLS_TWOREG | RFLD_NON | REGF_IX)
#define	REG_SP		(RCLS_NON    | RFLD_NON | REGF_SP)
