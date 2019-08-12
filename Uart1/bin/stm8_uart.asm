;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.5.0 #9253 (Mar 24 2016) (Linux)
; This file was generated Mon Aug 12 22:43:56 2019
;--------------------------------------------------------
	.module stm8_uart
	.optsdcc -mstm8
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _Initialise_Uart
	.globl _Uart_Printf
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
;	src/stm8_uart.c: 13: void Initialise_Uart ()
;	-----------------------------------------
;	 function Initialise_Uart
;	-----------------------------------------
_Initialise_Uart:
;	src/stm8_uart.c: 16: UART_CR1 = 0;
	mov	0x5234+0, #0x00
;	src/stm8_uart.c: 17: UART_CR2 = 0;
	mov	0x5235+0, #0x00
;	src/stm8_uart.c: 18: UART_CR4 = 0;
	mov	0x5237+0, #0x00
;	src/stm8_uart.c: 19: UART_CR3 = 0;
	mov	0x5236+0, #0x00
;	src/stm8_uart.c: 20: UART_CR5 = 0;
	mov	0x5238+0, #0x00
;	src/stm8_uart.c: 21: UART_GTR = 0;
	mov	0x5239+0, #0x00
;	src/stm8_uart.c: 22: UART_PSCR = 0;
	mov	0x523a+0, #0x00
;	src/stm8_uart.c: 25: UART_CR1 &= 0xEB;                         //clear M bit(8data bits) and PCEN (disable parity)
	ldw	x, #0x5234
	ld	a, (x)
	and	a, #0xeb
	ld	(x), a
;	src/stm8_uart.c: 26: UART_CR3 &= 0xCF;                         // 1 stop bit (bit5 and bit4)=0
	ldw	x, #0x5236
	ld	a, (x)
	and	a, #0xcf
	ld	(x), a
;	src/stm8_uart.c: 27: UART_BRR2 = 0x0A;                         //baudrate =115200 f=16Mhz
	mov	0x5233+0, #0x0a
;	src/stm8_uart.c: 28: UART_BRR1 = 0x08;
	mov	0x5232+0, #0x08
;	src/stm8_uart.c: 31: UART_CR2 &= 0xF3;                         // disable tx and rx
	ldw	x, #0x5235
	ld	a, (x)
	and	a, #0xf3
	ld	(x), a
;	src/stm8_uart.c: 34: UART_CR3 |= 0x07;                         //set CPOL CPHA LBCL
	ldw	x, #0x5236
	ld	a, (x)
	or	a, #0x07
	ld	(x), a
;	src/stm8_uart.c: 37: UART_CR2 |= 0x0C;
	ldw	x, #0x5235
	ld	a, (x)
	or	a, #0x0c
	ld	(x), a
;	src/stm8_uart.c: 38: UART_CR3 |= 0x08;                         //CLKEN =1
	ldw	x, #0x5236
	ld	a, (x)
	or	a, #0x08
	ld	(x), a
	ret
;	src/stm8_uart.c: 41: void Uart_Printf(char *message)
;	-----------------------------------------
;	 function Uart_Printf
;	-----------------------------------------
_Uart_Printf:
;	src/stm8_uart.c: 43: char *ch = message;
	ldw	y, (0x03, sp)
;	src/stm8_uart.c: 44: while(*ch != '\0')
00104$:
	ld	a, (y)
	tnz	a
	jreq	00107$
;	src/stm8_uart.c: 46: UART_DR = (unsigned char) *ch;	//  put the next char into the buffer
	ldw	x, #0x5231
	ld	(x), a
;	src/stm8_uart.c: 47: while((UART_SR &= UART_SR_TXE) == 0);	//  wait for TX to complete
00101$:
	ldw	x, #0x5230
	ld	a, (x)
	and	a, #0x80
	ld	(x), a
	tnz	a
	jreq	00101$
;	src/stm8_uart.c: 48: ch++;
	incw	y
	jra	00104$
00107$:
	ret
	.area CODE
	.area INITIALIZER
	.area CABS (ABS)
