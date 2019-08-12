;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.5.0 #9253 (Mar 24 2016) (Linux)
; This file was generated Mon Aug 12 23:11:22 2019
;--------------------------------------------------------
	.module stm8_clk
	.optsdcc -mstm8
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
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
; absolute external ram data
;--------------------------------------------------------
	.area DABS (ABS)
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area HOME
	.area GSINIT
	.area GSFINAL
	.area GSINIT
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area HOME
	.area HOME
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area CODE
;	src/stm8_clk.c: 13: void Initialise_System_Clock()
;	-----------------------------------------
;	 function Initialise_System_Clock
;	-----------------------------------------
_Initialise_System_Clock:
;	src/stm8_clk.c: 15: CLK_ICKR = 0;			//  Reset the Internal clock register
	mov	0x50c0+0, #0x00
;	src/stm8_clk.c: 16: CLK_ICKR |= CLK_ICKR_HSIEN;	//  enable HSI(bit 0)
	bset	0x50c0, #0
;	src/stm8_clk.c: 17: CLK_ECKR = 0;      		//  Disable external clock
	mov	0x50c1+0, #0x00
;	src/stm8_clk.c: 19: while((CLK_ICKR &= CLK_ICKR_HSIRDY) == 0);     //  wait for HSI to be ready for use 
00101$:
	ldw	x, #0x50c0
	ld	a, (x)
	and	a, #0x02
	ld	(x), a
	tnz	a
	jreq	00101$
;	src/stm8_clk.c: 21: CLK_CKDIVR = 0;    		//  Ensure the clocks are running at full speed.
	mov	0x50c6+0, #0x00
;	src/stm8_clk.c: 24: CLK_PCKENR1 = 0xFF;		//  Enable all peripheral clock
	mov	0x50c7+0, #0xff
;	src/stm8_clk.c: 25: CLK_PCKENR2 = 0xFF;		//  Same 
	mov	0x50ca+0, #0xff
;	src/stm8_clk.c: 26: CLK_CCOR = 0;      		//  CLK output register off
	mov	0x50c9+0, #0x00
;	src/stm8_clk.c: 27: CLK_HSITRIMR = 0;  		//  Turn off any HSIU trimming 
	mov	0x50cc+0, #0x00
;	src/stm8_clk.c: 28: CLK_SWIMCCR = 0;   		//  set swim to run at clk/2
	mov	0x50cd+0, #0x00
;	src/stm8_clk.c: 29: CLK_SWR = 0xE1;    		//  Use HSI as clock source
	mov	0x50c4+0, #0xe1
;	src/stm8_clk.c: 30: CLK_SWCR = 0;      		//  Reset the clk switch control register
	mov	0x50c5+0, #0x00
;	src/stm8_clk.c: 31: CLK_SWCR |= CLK_SWCR_SWEN;  	//  enable switching 
	ldw	x, #0x50c5
	ld	a, (x)
	or	a, #0x02
	ld	(x), a
;	src/stm8_clk.c: 33: while((CLK_SWCR &= CLK_SWCR_SWBSY) != 0);     //  pause while the clk is busy
00104$:
	ldw	x, #0x50c5
	ld	a, (x)
	and	a, #0x01
	ld	(x), a
	tnz	a
	jrne	00104$
	ret
	.area CODE
	.area INITIALIZER
	.area CABS (ABS)
