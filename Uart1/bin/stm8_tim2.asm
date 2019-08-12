;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.5.0 #9253 (Mar 24 2016) (Linux)
; This file was generated Mon Aug 12 22:43:56 2019
;--------------------------------------------------------
	.module stm8_tim2
	.optsdcc -mstm8
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _Initialise_Timer2
	.globl _Setup_Timer2
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
;	src/stm8_tim2.c: 13: void Initialise_Timer2()
;	-----------------------------------------
;	 function Initialise_Timer2
;	-----------------------------------------
_Initialise_Timer2:
;	src/stm8_tim2.c: 15: TIM2_CR1 = 0;               // Turn everything TIM2 related off.
	mov	0x5300+0, #0x00
;	src/stm8_tim2.c: 16: TIM2_IER = 0;
	mov	0x5303+0, #0x00
;	src/stm8_tim2.c: 17: TIM2_SR2 = 0;
	mov	0x5305+0, #0x00
;	src/stm8_tim2.c: 18: TIM2_CCER1 = 0;
	mov	0x530a+0, #0x00
;	src/stm8_tim2.c: 19: TIM2_CCER2 = 0;
	mov	0x530b+0, #0x00
;	src/stm8_tim2.c: 20: TIM2_CCER1 = 0;
	mov	0x530a+0, #0x00
;	src/stm8_tim2.c: 21: TIM2_CCER2 = 0;
	mov	0x530b+0, #0x00
;	src/stm8_tim2.c: 22: TIM2_CCMR1 = 0;
	mov	0x5307+0, #0x00
;	src/stm8_tim2.c: 23: TIM2_CCMR2 = 0;
	mov	0x5308+0, #0x00
;	src/stm8_tim2.c: 24: TIM2_CCMR3 = 0;
	mov	0x5309+0, #0x00
;	src/stm8_tim2.c: 25: TIM2_CNTRH = 0;
	mov	0x530c+0, #0x00
;	src/stm8_tim2.c: 26: TIM2_CNTRL = 0;
	mov	0x530d+0, #0x00
;	src/stm8_tim2.c: 27: TIM2_PSCR = 0;
	mov	0x530e+0, #0x00
;	src/stm8_tim2.c: 28: TIM2_ARRH  = 0;
	mov	0x530f+0, #0x00
;	src/stm8_tim2.c: 29: TIM2_ARRL  = 0;
	mov	0x5310+0, #0x00
;	src/stm8_tim2.c: 30: TIM2_CCR1H = 0;
	mov	0x5311+0, #0x00
;	src/stm8_tim2.c: 31: TIM2_CCR1L = 0;
	mov	0x5312+0, #0x00
;	src/stm8_tim2.c: 32: TIM2_CCR2H = 0;
	mov	0x5313+0, #0x00
;	src/stm8_tim2.c: 33: TIM2_CCR2L = 0;
	mov	0x5314+0, #0x00
;	src/stm8_tim2.c: 34: TIM2_CCR3H = 0;
	mov	0x5315+0, #0x00
;	src/stm8_tim2.c: 35: TIM2_CCR3L = 0;
	mov	0x5316+0, #0x00
;	src/stm8_tim2.c: 36: TIM2_SR1 = 0;
	mov	0x5304+0, #0x00
	ret
;	src/stm8_tim2.c: 39: void Setup_Timer2(uint8_t pre, uint8_t high, uint8_t low)
;	-----------------------------------------
;	 function Setup_Timer2
;	-----------------------------------------
_Setup_Timer2:
;	src/stm8_tim2.c: 41: TIM2_PSCR = pre;
	ldw	x, #0x530e
	ld	a, (0x03, sp)
	ld	(x), a
;	src/stm8_tim2.c: 42: TIM2_ARRH = high;
	ldw	x, #0x530f
	ld	a, (0x04, sp)
	ld	(x), a
;	src/stm8_tim2.c: 43: TIM2_ARRL = low;
	ldw	x, #0x5310
	ld	a, (0x05, sp)
	ld	(x), a
;	src/stm8_tim2.c: 44: TIM2_IER |= TIM_IER_UIE;	// Enable the update interrupt
	bset	0x5303, #0
;	src/stm8_tim2.c: 45: TIM2_CR1 |= TIM_CR1_CEN;	// Finally enable the timer
	bset	0x5300, #0
	ret
	.area CODE
	.area INITIALIZER
	.area CABS (ABS)
