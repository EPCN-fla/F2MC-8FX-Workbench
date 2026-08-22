;==========================================================================
; F2MC-8FX Family SOFTUNE C Compiler sample startup routine,
; (c) Copyright Spansion LLC, All Rights Reserved 1986 - 2014
;==========================================================================
;  Sample program for initialization
;--------------------------------------------------------------------------
		.PROGRAM	start
		.TITLE		start

;--------------------------------------------------------------------------
; external declaration of symbols
;--------------------------------------------------------------------------
		.EXPORT		__start
		.IMPORT		_main
		.IMPORT		LMEMTOMEM
		.IMPORT		LMEMCLEAR
		.IMPORT		_RAM_INIT
		.IMPORT		_ROM_INIT
		.IMPORT		_RAM_DIRINIT
		.IMPORT		_ROM_DIRINIT

;--------------------------------------------------------------------------
; definition to stack area
;--------------------------------------------------------------------------
     		.SECTION	STACK,    STACK,    ALIGN=1
		.RES.B		62
STACK_TOP:
		.RES.B		2
		
;--------------------------------------------------------------------------
; definition to start address of data, const and code section
;--------------------------------------------------------------------------
		.SECTION	DIRDATA,  DIR,      ALIGN=1
		.SECTION	DIRINIT,  DIR,      ALIGN=1
		.SECTION	DATA,     DATA,     ALIGN=1
		.SECTION	INIT,     DATA,     ALIGN=1

;--------------------------------------------------------------------------
; code area
;--------------------------------------------------------------------------
    		.SECTION	CODE,     CODE,     ALIGN=1
__start:
;--------------------------------------------------------------------------
; set stack pointer
;--------------------------------------------------------------------------
		MOVW	A, #STACK_TOP
		MOVW	SP, A

;--------------------------------------------------------------------------
; set register bank is 0
;--------------------------------------------------------------------------
		MOVW	A, PS
		MOVW	A, #0x07FF
		ANDW	A
		MOVW	PS, A

;--------------------------------------------------------------------------
; set ILM to the lowest level(3)
;--------------------------------------------------------------------------
		MOVW	A, PS
		MOVW	A, #0x0030
		ORW	A
		MOVW	PS, A

;--------------------------------------------------------------------------
; copy initial value *CONST(ROM) section to *INIT(RAM) section
;--------------------------------------------------------------------------
#macro		ICOPY	src_addr, dest_addr, src_section
		MOVW	EP, #\src_addr
		MOVW	A,  #\dest_addr
		MOVW	A,  #SIZEOF (\src_section)
		CALL	LMEMTOMEM
#endm

		ICOPY	_ROM_INIT,	_RAM_INIT,	INIT
		ICOPY	_ROM_DIRINIT,	_RAM_DIRINIT,	DIRINIT

;--------------------------------------------------------------------------
; zero clear of *VAR section
;--------------------------------------------------------------------------
#macro		FILL0	src_section
		MOVW	A, #\src_section
		MOVW	A, #SIZEOF (\src_section)
		CALL	LMEMCLEAR
#endm

		FILL0	DIRDATA
		FILL0	DATA

;--------------------------------------------------------------------------
; call main routine
;--------------------------------------------------------------------------
		CALL	_main
end:		JMP	end

		.END	__start
