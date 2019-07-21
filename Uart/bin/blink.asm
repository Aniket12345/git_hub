;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.5.0 #9253 (Mar 24 2016) (Linux)
; This file was generated Wed Jul 10 00:12:33 2019
;--------------------------------------------------------
	.module blink
	.optsdcc -mstm8
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _main
	.globl _delay
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
;	src/blink.c: 16: void delay(unsigned long count) {
;	-----------------------------------------
;	 function delay
;	-----------------------------------------
_delay:
	sub	sp, #8
;	src/blink.c: 17: while (count--)
	ldw	y, (0x0b, sp)
	ldw	(0x05, sp), y
	ldw	x, (0x0d, sp)
00101$:
	exg	a, xl
	ld	(0x04, sp), a
	exg	a, xl
	ldw	y, (0x05, sp)
	ldw	(0x01, sp), y
	ld	a, xh
	subw	x, #0x0001
	push	a
	ld	a, (0x07, sp)
	sbc	a, #0x00
	ld	(0x07, sp), a
	ld	a, (0x06, sp)
	sbc	a, #0x00
	ld	(0x06, sp), a
	pop	a
	tnz	(0x04, sp)
	jrne	00115$
	tnz	a
	jrne	00115$
	ldw	y, (0x01, sp)
	jreq	00104$
00115$:
;	src/blink.c: 18: nop();
	nop
	jra	00101$
00104$:
	addw	sp, #8
	ret
;	src/blink.c: 21: int main(void)
;	-----------------------------------------
;	 function main
;	-----------------------------------------
_main:
;	src/blink.c: 24: CLK_CKDIVR = 0;
	mov	0x50c6+0, #0x00
;	src/blink.c: 28: PORT(LED_PORT, DDR)  |= LED_PIN; // i.e. PB_DDR |= (1 << 5);
	ldw	x, #0x5007
	ld	a, (x)
	or	a, #0x20
	ld	(x), a
;	src/blink.c: 30: PORT(LED_PORT, CR1)  |= LED_PIN; // i.e. PB_CR1 |= (1 << 5);
	ldw	x, #0x5008
	ld	a, (x)
	or	a, #0x20
	ld	(x), a
;	src/blink.c: 32: while(1) {
00102$:
;	src/blink.c: 34: PORT(LED_PORT, ODR) |= LED_PIN; // PB_ODR |= (1 << 5);
	ldw	x, #0x5005
	ld	a, (x)
	or	a, #0x20
	ld	(x), a
;	src/blink.c: 35: delay(100000L);
	push	#0xa0
	push	#0x86
	push	#0x01
	push	#0x00
	call	_delay
	addw	sp, #4
;	src/blink.c: 37: PORT(LED_PORT, ODR) &= ~LED_PIN; // PB_ODR &= ~(1 << 5);
	ldw	x, #0x5005
	ld	a, (x)
	and	a, #0xdf
	ld	(x), a
;	src/blink.c: 38: delay(300000L);
	push	#0xe0
	push	#0x93
	push	#0x04
	push	#0x00
	call	_delay
	addw	sp, #4
	jra	00102$
	ret
	.area CODE
	.area INITIALIZER
	.area CABS (ABS)
