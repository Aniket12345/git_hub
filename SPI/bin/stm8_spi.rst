                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 3.5.0 #9253 (Mar 24 2016) (Linux)
                                      4 ; This file was generated Sun Aug 11 22:41:03 2019
                                      5 ;--------------------------------------------------------
                                      6 	.module stm8_spi
                                      7 	.optsdcc -mstm8
                                      8 	
                                      9 ;--------------------------------------------------------
                                     10 ; Public variables in this module
                                     11 ;--------------------------------------------------------
                                     12 	.globl _Spi_Init
                                     13 	.globl _Spi_Write
                                     14 	.globl _Spi_Read
                                     15 	.globl _Chip_Select
                                     16 	.globl _Chip_Deselect
                                     17 ;--------------------------------------------------------
                                     18 ; ram data
                                     19 ;--------------------------------------------------------
                                     20 	.area DATA
                                     21 ;--------------------------------------------------------
                                     22 ; ram data
                                     23 ;--------------------------------------------------------
                                     24 	.area INITIALIZED
                                     25 ;--------------------------------------------------------
                                     26 ; absolute external ram data
                                     27 ;--------------------------------------------------------
                                     28 	.area DABS (ABS)
                                     29 ;--------------------------------------------------------
                                     30 ; global & static initialisations
                                     31 ;--------------------------------------------------------
                                     32 	.area HOME
                                     33 	.area GSINIT
                                     34 	.area GSFINAL
                                     35 	.area GSINIT
                                     36 ;--------------------------------------------------------
                                     37 ; Home
                                     38 ;--------------------------------------------------------
                                     39 	.area HOME
                                     40 	.area HOME
                                     41 ;--------------------------------------------------------
                                     42 ; code
                                     43 ;--------------------------------------------------------
                                     44 	.area CODE
                                     45 ;	src/stm8_spi.c: 17: void Spi_Init()
                                     46 ;	-----------------------------------------
                                     47 ;	 function Spi_Init
                                     48 ;	-----------------------------------------
      008151                         49 _Spi_Init:
                                     50 ;	src/stm8_spi.c: 20: PC_DDR |= (1 << CS_PIN);
      008151 AE 50 0C         [ 2]   51 	ldw	x, #0x500c
      008154 F6               [ 1]   52 	ld	a, (x)
      008155 AA 10            [ 1]   53 	or	a, #0x10
      008157 F7               [ 1]   54 	ld	(x), a
                                     55 ;	src/stm8_spi.c: 21: PC_CR1 |= (1 << CS_PIN);
      008158 AE 50 0D         [ 2]   56 	ldw	x, #0x500d
      00815B F6               [ 1]   57 	ld	a, (x)
      00815C AA 10            [ 1]   58 	or	a, #0x10
      00815E F7               [ 1]   59 	ld	(x), a
                                     60 ;	src/stm8_spi.c: 22: PC_ODR |= (1 << CS_PIN);
      00815F AE 50 0A         [ 2]   61 	ldw	x, #0x500a
      008162 F6               [ 1]   62 	ld	a, (x)
      008163 AA 10            [ 1]   63 	or	a, #0x10
      008165 F7               [ 1]   64 	ld	(x), a
                                     65 ;	src/stm8_spi.c: 25: SPI_CR1 = 0;
      008166 35 00 52 00      [ 1]   66 	mov	0x5200+0, #0x00
                                     67 ;	src/stm8_spi.c: 26: SPI_CR2 = 0;
      00816A 35 00 52 01      [ 1]   68 	mov	0x5201+0, #0x00
                                     69 ;	src/stm8_spi.c: 29: SPI_CR2 |= (SPI_CR2_SSI) | (SPI_CR2_SSM); 	//  Master mode & software SS
      00816E AE 52 01         [ 2]   70 	ldw	x, #0x5201
      008171 F6               [ 1]   71 	ld	a, (x)
      008172 AA 03            [ 1]   72 	or	a, #0x03
      008174 F7               [ 1]   73 	ld	(x), a
                                     74 ;	src/stm8_spi.c: 30: SPI_CR1 |= (SPI_CR1_MSTR) | (SPI_CR1_SPE) | (SPI_CR1_BR(4)) ;
      008175 AE 52 00         [ 2]   75 	ldw	x, #0x5200
      008178 F6               [ 1]   76 	ld	a, (x)
      008179 AA 64            [ 1]   77 	or	a, #0x64
      00817B F7               [ 1]   78 	ld	(x), a
      00817C 81               [ 4]   79 	ret
                                     80 ;	src/stm8_spi.c: 33: void Spi_Write(uint8_t data)
                                     81 ;	-----------------------------------------
                                     82 ;	 function Spi_Write
                                     83 ;	-----------------------------------------
      00817D                         84 _Spi_Write:
                                     85 ;	src/stm8_spi.c: 35: SPI_DR = data;
      00817D AE 52 04         [ 2]   86 	ldw	x, #0x5204
      008180 7B 03            [ 1]   87 	ld	a, (0x03, sp)
      008182 F7               [ 1]   88 	ld	(x), a
                                     89 ;	src/stm8_spi.c: 36: while( !(SPI_SR & SPI_SR_TXE));		//  Wait till tx buffer is not empty
      008183                         90 00101$:
      008183 AE 52 03         [ 2]   91 	ldw	x, #0x5203
      008186 F6               [ 1]   92 	ld	a, (x)
      008187 A5 02            [ 1]   93 	bcp	a, #0x02
      008189 27 F8            [ 1]   94 	jreq	00101$
      00818B 81               [ 4]   95 	ret
                                     96 ;	src/stm8_spi.c: 39: uint8_t Spi_Read()
                                     97 ;	-----------------------------------------
                                     98 ;	 function Spi_Read
                                     99 ;	-----------------------------------------
      00818C                        100 _Spi_Read:
                                    101 ;	src/stm8_spi.c: 41: Spi_Write(0xFF);	//  To read write dummy value
      00818C 4B FF            [ 1]  102 	push	#0xff
      00818E CD 81 7D         [ 4]  103 	call	_Spi_Write
      008191 84               [ 1]  104 	pop	a
                                    105 ;	src/stm8_spi.c: 42: while(!(SPI_SR & SPI_SR_RXNE));		//  wait till rx buffer is full
      008192                        106 00101$:
      008192 AE 52 03         [ 2]  107 	ldw	x, #0x5203
      008195 F6               [ 1]  108 	ld	a, (x)
      008196 44               [ 1]  109 	srl	a
      008197 24 F9            [ 1]  110 	jrnc	00101$
                                    111 ;	src/stm8_spi.c: 43: return SPI_DR;
      008199 AE 52 04         [ 2]  112 	ldw	x, #0x5204
      00819C F6               [ 1]  113 	ld	a, (x)
      00819D 81               [ 4]  114 	ret
                                    115 ;	src/stm8_spi.c: 46: void Chip_Select()
                                    116 ;	-----------------------------------------
                                    117 ;	 function Chip_Select
                                    118 ;	-----------------------------------------
      00819E                        119 _Chip_Select:
                                    120 ;	src/stm8_spi.c: 48: PC_ODR &= ~(1 << CS_PIN);
      00819E AE 50 0A         [ 2]  121 	ldw	x, #0x500a
      0081A1 F6               [ 1]  122 	ld	a, (x)
      0081A2 A4 EF            [ 1]  123 	and	a, #0xef
      0081A4 F7               [ 1]  124 	ld	(x), a
      0081A5 81               [ 4]  125 	ret
                                    126 ;	src/stm8_spi.c: 51: void Chip_Deselect()
                                    127 ;	-----------------------------------------
                                    128 ;	 function Chip_Deselect
                                    129 ;	-----------------------------------------
      0081A6                        130 _Chip_Deselect:
                                    131 ;	src/stm8_spi.c: 53: while((SPI_SR & (SPI_SR_BSY)));
      0081A6                        132 00101$:
      0081A6 AE 52 03         [ 2]  133 	ldw	x, #0x5203
      0081A9 F6               [ 1]  134 	ld	a, (x)
      0081AA 4D               [ 1]  135 	tnz	a
      0081AB 2B F9            [ 1]  136 	jrmi	00101$
                                    137 ;	src/stm8_spi.c: 54: PC_ODR |= (1 << CS_PIN);
      0081AD AE 50 0A         [ 2]  138 	ldw	x, #0x500a
      0081B0 F6               [ 1]  139 	ld	a, (x)
      0081B1 AA 10            [ 1]  140 	or	a, #0x10
      0081B3 F7               [ 1]  141 	ld	(x), a
      0081B4 81               [ 4]  142 	ret
                                    143 	.area CODE
                                    144 	.area INITIALIZER
                                    145 	.area CABS (ABS)
