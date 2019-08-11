;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.5.0 #9253 (Mar 24 2016) (Linux)
; This file was generated Sun Aug 11 22:41:03 2019
;--------------------------------------------------------
	.module stm8_spi
	.optsdcc -mstm8
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _Spi_Init
	.globl _Spi_Write
	.globl _Spi_Read
	.globl _Chip_Select
	.globl _Chip_Deselect
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
;	src/stm8_spi.c: 17: void Spi_Init()
;	-----------------------------------------
;	 function Spi_Init
;	-----------------------------------------
_Spi_Init:
;	src/stm8_spi.c: 20: PC_DDR |= (1 << CS_PIN);
	ldw	x, #0x500c
	ld	a, (x)
	or	a, #0x10
	ld	(x), a
;	src/stm8_spi.c: 21: PC_CR1 |= (1 << CS_PIN);
	ldw	x, #0x500d
	ld	a, (x)
	or	a, #0x10
	ld	(x), a
;	src/stm8_spi.c: 22: PC_ODR |= (1 << CS_PIN);
	ldw	x, #0x500a
	ld	a, (x)
	or	a, #0x10
	ld	(x), a
;	src/stm8_spi.c: 25: SPI_CR1 = 0;
	mov	0x5200+0, #0x00
;	src/stm8_spi.c: 26: SPI_CR2 = 0;
	mov	0x5201+0, #0x00
;	src/stm8_spi.c: 29: SPI_CR2 |= (SPI_CR2_SSI) | (SPI_CR2_SSM); 	//  Master mode & software SS
	ldw	x, #0x5201
	ld	a, (x)
	or	a, #0x03
	ld	(x), a
;	src/stm8_spi.c: 30: SPI_CR1 |= (SPI_CR1_MSTR) | (SPI_CR1_SPE) | (SPI_CR1_BR(4)) ;
	ldw	x, #0x5200
	ld	a, (x)
	or	a, #0x64
	ld	(x), a
	ret
;	src/stm8_spi.c: 33: void Spi_Write(uint8_t data)
;	-----------------------------------------
;	 function Spi_Write
;	-----------------------------------------
_Spi_Write:
;	src/stm8_spi.c: 35: SPI_DR = data;
	ldw	x, #0x5204
	ld	a, (0x03, sp)
	ld	(x), a
;	src/stm8_spi.c: 36: while( !(SPI_SR & SPI_SR_TXE));		//  Wait till tx buffer is not empty
00101$:
	ldw	x, #0x5203
	ld	a, (x)
	bcp	a, #0x02
	jreq	00101$
	ret
;	src/stm8_spi.c: 39: uint8_t Spi_Read()
;	-----------------------------------------
;	 function Spi_Read
;	-----------------------------------------
_Spi_Read:
;	src/stm8_spi.c: 41: Spi_Write(0xFF);	//  To read write dummy value
	push	#0xff
	call	_Spi_Write
	pop	a
;	src/stm8_spi.c: 42: while(!(SPI_SR & SPI_SR_RXNE));		//  wait till rx buffer is full
00101$:
	ldw	x, #0x5203
	ld	a, (x)
	srl	a
	jrnc	00101$
;	src/stm8_spi.c: 43: return SPI_DR;
	ldw	x, #0x5204
	ld	a, (x)
	ret
;	src/stm8_spi.c: 46: void Chip_Select()
;	-----------------------------------------
;	 function Chip_Select
;	-----------------------------------------
_Chip_Select:
;	src/stm8_spi.c: 48: PC_ODR &= ~(1 << CS_PIN);
	ldw	x, #0x500a
	ld	a, (x)
	and	a, #0xef
	ld	(x), a
	ret
;	src/stm8_spi.c: 51: void Chip_Deselect()
;	-----------------------------------------
;	 function Chip_Deselect
;	-----------------------------------------
_Chip_Deselect:
;	src/stm8_spi.c: 53: while((SPI_SR & (SPI_SR_BSY)));
00101$:
	ldw	x, #0x5203
	ld	a, (x)
	tnz	a
	jrmi	00101$
;	src/stm8_spi.c: 54: PC_ODR |= (1 << CS_PIN);
	ldw	x, #0x500a
	ld	a, (x)
	or	a, #0x10
	ld	(x), a
	ret
	.area CODE
	.area INITIALIZER
	.area CABS (ABS)
