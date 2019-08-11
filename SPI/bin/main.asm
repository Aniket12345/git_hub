;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.5.0 #9253 (Mar 24 2016) (Linux)
; This file was generated Sun Aug 11 22:41:03 2019
;--------------------------------------------------------
	.module main
	.optsdcc -mstm8
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _main
	.globl _Chip_Deselect
	.globl _Chip_Select
	.globl _Spi_Write
	.globl _Spi_Init
	.globl _Initialise_System_Clock
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area DATA
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area INITIALIZED
;--------------------------------------------------------
; Stack segment in internal ram 
;--------------------------------------------------------
	.area	SSEG
__start__stack:
	.ds	1

;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area DABS (ABS)
;--------------------------------------------------------
; interrupt vector 
;--------------------------------------------------------
	.area HOME
__interrupt_vect:
	int s_GSINIT ;reset
	int 0x0000 ;trap
	int 0x0000 ;int0
	int 0x0000 ;int1
	int 0x0000 ;int2
	int 0x0000 ;int3
	int 0x0000 ;int4
	int 0x0000 ;int5
	int 0x0000 ;int6
	int 0x0000 ;int7
	int 0x0000 ;int8
	int 0x0000 ;int9
	int 0x0000 ;int10
	int 0x0000 ;int11
	int 0x0000 ;int12
	int 0x0000 ;int13
	int 0x0000 ;int14
	int 0x0000 ;int15
	int 0x0000 ;int16
	int 0x0000 ;int17
	int 0x0000 ;int18
	int 0x0000 ;int19
	int 0x0000 ;int20
	int 0x0000 ;int21
	int 0x0000 ;int22
	int 0x0000 ;int23
	int 0x0000 ;int24
	int 0x0000 ;int25
	int 0x0000 ;int26
	int 0x0000 ;int27
	int 0x0000 ;int28
	int 0x0000 ;int29
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area HOME
	.area GSINIT
	.area GSFINAL
	.area GSINIT
__sdcc_gs_init_startup:
__sdcc_init_data:
; stm8_genXINIT() start
	ldw x, #l_DATA
	jreq	00002$
00001$:
	clr (s_DATA - 1, x)
	decw x
	jrne	00001$
00002$:
	ldw	x, #l_INITIALIZER
	jreq	00004$
00003$:
	ld	a, (s_INITIALIZER - 1, x)
	ld	(s_INITIALIZED - 1, x), a
	decw	x
	jrne	00003$
00004$:
; stm8_genXINIT() end
	.area GSFINAL
	jp	__sdcc_program_startup
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area HOME
	.area HOME
__sdcc_program_startup:
	jp	_main
;	return from main will return to caller
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area CODE
;	src/main.c: 8: void main()
;	-----------------------------------------
;	 function main
;	-----------------------------------------
_main:
;	src/main.c: 10: disableInterrupts();
	sim
;	src/main.c: 13: Initialise_System_Clock();
	call	_Initialise_System_Clock
;	src/main.c: 17: Spi_Init();
	call	_Spi_Init
;	src/main.c: 19: enableInterrupts();
	rim
;	src/main.c: 20: while(1) 
00102$:
;	src/main.c: 22: Chip_Select();
	call	_Chip_Select
;	src/main.c: 23: Spi_Write(0x10);
	push	#0x10
	call	_Spi_Write
	pop	a
;	src/main.c: 24: Spi_Write(0x11);
	push	#0x11
	call	_Spi_Write
	pop	a
;	src/main.c: 25: Spi_Write(0x12);
	push	#0x12
	call	_Spi_Write
	pop	a
;	src/main.c: 26: Spi_Write(0x13);
	push	#0x13
	call	_Spi_Write
	pop	a
;	src/main.c: 27: Spi_Write(0x14);
	push	#0x14
	call	_Spi_Write
	pop	a
;	src/main.c: 28: Chip_Deselect();
	call	_Chip_Deselect
	jra	00102$
	ret
	.area CODE
	.area INITIALIZER
	.area CABS (ABS)
