;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.5.0 #9253 (Mar 24 2016) (Linux)
; This file was generated Sun Jul 21 01:39:08 2019
;--------------------------------------------------------
	.module Uart
	.optsdcc -mstm8
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _main
	.globl _uart_write
	.globl _delay
	.globl _strlen
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
;	src/Uart.c: 6: void delay(unsigned long count) {
;	-----------------------------------------
;	 function delay
;	-----------------------------------------
_delay:
	sub	sp, #8
;	src/Uart.c: 7: while (count--)
	ldw	y, (0x0b, sp)
	ldw	(0x01, sp), y
	ldw	x, (0x0d, sp)
00101$:
	exg	a, xl
	ld	(0x08, sp), a
	exg	a, xl
	ldw	y, (0x01, sp)
	ldw	(0x05, sp), y
	ld	a, xh
	subw	x, #0x0001
	push	a
	ld	a, (0x03, sp)
	sbc	a, #0x00
	ld	(0x03, sp), a
	ld	a, (0x02, sp)
	sbc	a, #0x00
	ld	(0x02, sp), a
	pop	a
	tnz	(0x08, sp)
	jrne	00115$
	tnz	a
	jrne	00115$
	ldw	y, (0x05, sp)
	jreq	00104$
00115$:
;	src/Uart.c: 8: nop();
	nop
	jra	00101$
00104$:
	addw	sp, #8
	ret
;	src/Uart.c: 11: int uart_write(const char *str) {
;	-----------------------------------------
;	 function uart_write
;	-----------------------------------------
_uart_write:
	sub	sp, #3
;	src/Uart.c: 13: for(i = 0; i < strlen(str); i++) {
	clr	(0x01, sp)
00106$:
	ldw	x, (0x06, sp)
	pushw	x
	call	_strlen
	addw	sp, #2
	ldw	(0x02, sp), x
	ld	a, (0x01, sp)
	ld	xl, a
	rlc	a
	clr	a
	sbc	a, #0x00
	ld	xh, a
	cpw	x, (0x02, sp)
	jrnc	00104$
;	src/Uart.c: 14: while(!(UART1_SR & UART_SR_TXE)); // !Transmit data register empty
00101$:
	ldw	x, #0x5230
	ld	a, (x)
	tnz	a
	jrpl	00101$
;	src/Uart.c: 15: UART1_DR = str[i];
	clrw	x
	ld	a, (0x01, sp)
	ld	xl, a
	addw	x, (0x06, sp)
	ld	a, (x)
	ldw	x, #0x5231
	ld	(x), a
;	src/Uart.c: 13: for(i = 0; i < strlen(str); i++) {
	inc	(0x01, sp)
	jra	00106$
00104$:
;	src/Uart.c: 17: return(i); // Bytes sent
	ld	a, (0x01, sp)
	ld	xl, a
	rlc	a
	clr	a
	sbc	a, #0x00
	ld	xh, a
	addw	sp, #3
	ret
;	src/Uart.c: 20: int main(void)
;	-----------------------------------------
;	 function main
;	-----------------------------------------
_main:
;	src/Uart.c: 23: CLK_CKDIVR = 0;
	mov	0x50c6+0, #0x00
;	src/Uart.c: 26: UART1_CR2 |= UART_CR2_TEN; // Transmitter enable
	ldw	x, #0x5235
	ld	a, (x)
	or	a, #0x08
	ld	(x), a
;	src/Uart.c: 28: UART1_CR3 &= ~(UART_CR3_STOP1 | UART_CR3_STOP2); // 1 stop bit
	ldw	x, #0x5236
	ld	a, (x)
	and	a, #0xcf
	ld	(x), a
;	src/Uart.c: 30: UART1_BRR2 = 0x03; UART1_BRR1 = 0x68; // 0x0683 coded funky way (see ref manual)
	mov	0x5233+0, #0x03
	mov	0x5232+0, #0x68
;	src/Uart.c: 32: while(1) {
00102$:
;	src/Uart.c: 33: uart_write("Hello World!\r\n");
	ldw	x, #___str_0+0
	pushw	x
	call	_uart_write
	popw	x
;	src/Uart.c: 34: delay(400000L);
	push	#0x80
	push	#0x1a
	push	#0x06
	push	#0x00
	call	_delay
	addw	sp, #4
	jra	00102$
	ret
	.area CODE
___str_0:
	.ascii "Hello World!"
	.db 0x0D
	.db 0x0A
	.db 0x00
	.area INITIALIZER
	.area CABS (ABS)
