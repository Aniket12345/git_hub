                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 3.5.0 #9253 (Mar 24 2016) (Linux)
                                      4 ; This file was generated Tue Jul 23 23:56:18 2019
                                      5 ;--------------------------------------------------------
                                      6 	.module stm8_uart
                                      7 	.optsdcc -mstm8
                                      8 	
                                      9 ;--------------------------------------------------------
                                     10 ; Public variables in this module
                                     11 ;--------------------------------------------------------
                                     12 	.globl _Initialise_Uart
                                     13 	.globl _Uart_Printf
                                     14 ;--------------------------------------------------------
                                     15 ; ram data
                                     16 ;--------------------------------------------------------
                                     17 	.area DATA
                                     18 ;--------------------------------------------------------
                                     19 ; ram data
                                     20 ;--------------------------------------------------------
                                     21 	.area INITIALIZED
                                     22 ;--------------------------------------------------------
                                     23 ; absolute external ram data
                                     24 ;--------------------------------------------------------
                                     25 	.area DABS (ABS)
                                     26 ;--------------------------------------------------------
                                     27 ; global & static initialisations
                                     28 ;--------------------------------------------------------
                                     29 	.area HOME
                                     30 	.area GSINIT
                                     31 	.area GSFINAL
                                     32 	.area GSINIT
                                     33 ;--------------------------------------------------------
                                     34 ; Home
                                     35 ;--------------------------------------------------------
                                     36 	.area HOME
                                     37 	.area HOME
                                     38 ;--------------------------------------------------------
                                     39 ; code
                                     40 ;--------------------------------------------------------
                                     41 	.area CODE
                                     42 ;	src/stm8_uart.c: 13: void Initialise_Uart ()
                                     43 ;	-----------------------------------------
                                     44 ;	 function Initialise_Uart
                                     45 ;	-----------------------------------------
      0080E8                         46 _Initialise_Uart:
                                     47 ;	src/stm8_uart.c: 16: UART_CR1 = 0;
      0080E8 35 00 52 34      [ 1]   48 	mov	0x5234+0, #0x00
                                     49 ;	src/stm8_uart.c: 17: UART_CR2 = 0;
      0080EC 35 00 52 35      [ 1]   50 	mov	0x5235+0, #0x00
                                     51 ;	src/stm8_uart.c: 18: UART_CR4 = 0;
      0080F0 35 00 52 37      [ 1]   52 	mov	0x5237+0, #0x00
                                     53 ;	src/stm8_uart.c: 19: UART_CR3 = 0;
      0080F4 35 00 52 36      [ 1]   54 	mov	0x5236+0, #0x00
                                     55 ;	src/stm8_uart.c: 20: UART_CR5 = 0;
      0080F8 35 00 52 38      [ 1]   56 	mov	0x5238+0, #0x00
                                     57 ;	src/stm8_uart.c: 21: UART_GTR = 0;
      0080FC 35 00 52 39      [ 1]   58 	mov	0x5239+0, #0x00
                                     59 ;	src/stm8_uart.c: 22: UART_PSCR = 0;
      008100 35 00 52 3A      [ 1]   60 	mov	0x523a+0, #0x00
                                     61 ;	src/stm8_uart.c: 25: UART_CR1 &= 0xEB;                         //clear M bit(8data bits) and PCEN (disable parity)
      008104 AE 52 34         [ 2]   62 	ldw	x, #0x5234
      008107 F6               [ 1]   63 	ld	a, (x)
      008108 A4 EB            [ 1]   64 	and	a, #0xeb
      00810A F7               [ 1]   65 	ld	(x), a
                                     66 ;	src/stm8_uart.c: 26: UART_CR3 &= 0xCF;                         // 1 stop bit (bit5 and bit4)=0
      00810B AE 52 36         [ 2]   67 	ldw	x, #0x5236
      00810E F6               [ 1]   68 	ld	a, (x)
      00810F A4 CF            [ 1]   69 	and	a, #0xcf
      008111 F7               [ 1]   70 	ld	(x), a
                                     71 ;	src/stm8_uart.c: 27: UART_BRR2 = 0x0A;                         //baudrate =115200 f=16Mhz
      008112 35 0A 52 33      [ 1]   72 	mov	0x5233+0, #0x0a
                                     73 ;	src/stm8_uart.c: 28: UART_BRR1 = 0x08;
      008116 35 08 52 32      [ 1]   74 	mov	0x5232+0, #0x08
                                     75 ;	src/stm8_uart.c: 31: UART_CR2 &= 0xF3;                         // disable tx and rx
      00811A AE 52 35         [ 2]   76 	ldw	x, #0x5235
      00811D F6               [ 1]   77 	ld	a, (x)
      00811E A4 F3            [ 1]   78 	and	a, #0xf3
      008120 F7               [ 1]   79 	ld	(x), a
                                     80 ;	src/stm8_uart.c: 34: UART_CR3 |= 0x07;                         //set CPOL CPHA LBCL
      008121 AE 52 36         [ 2]   81 	ldw	x, #0x5236
      008124 F6               [ 1]   82 	ld	a, (x)
      008125 AA 07            [ 1]   83 	or	a, #0x07
      008127 F7               [ 1]   84 	ld	(x), a
                                     85 ;	src/stm8_uart.c: 37: UART_CR2 |= 0x0C;
      008128 AE 52 35         [ 2]   86 	ldw	x, #0x5235
      00812B F6               [ 1]   87 	ld	a, (x)
      00812C AA 0C            [ 1]   88 	or	a, #0x0c
      00812E F7               [ 1]   89 	ld	(x), a
                                     90 ;	src/stm8_uart.c: 38: UART_CR3 |= 0x08;                         //CLKEN =1
      00812F AE 52 36         [ 2]   91 	ldw	x, #0x5236
      008132 F6               [ 1]   92 	ld	a, (x)
      008133 AA 08            [ 1]   93 	or	a, #0x08
      008135 F7               [ 1]   94 	ld	(x), a
      008136 81               [ 4]   95 	ret
                                     96 ;	src/stm8_uart.c: 41: void Uart_Printf(char *message)
                                     97 ;	-----------------------------------------
                                     98 ;	 function Uart_Printf
                                     99 ;	-----------------------------------------
      008137                        100 _Uart_Printf:
                                    101 ;	src/stm8_uart.c: 43: char *ch = message;
      008137 16 03            [ 2]  102 	ldw	y, (0x03, sp)
                                    103 ;	src/stm8_uart.c: 44: while(*ch != '\0')
      008139                        104 00104$:
      008139 90 F6            [ 1]  105 	ld	a, (y)
      00813B 4D               [ 1]  106 	tnz	a
      00813C 27 12            [ 1]  107 	jreq	00107$
                                    108 ;	src/stm8_uart.c: 46: UART_DR = (unsigned char) *ch;	//  put the next char into the buffer
      00813E AE 52 31         [ 2]  109 	ldw	x, #0x5231
      008141 F7               [ 1]  110 	ld	(x), a
                                    111 ;	src/stm8_uart.c: 47: while((UART_SR &= UART_SR_TXE) == 0);	//  wait for TX to complete
      008142                        112 00101$:
      008142 AE 52 30         [ 2]  113 	ldw	x, #0x5230
      008145 F6               [ 1]  114 	ld	a, (x)
      008146 A4 80            [ 1]  115 	and	a, #0x80
      008148 F7               [ 1]  116 	ld	(x), a
      008149 4D               [ 1]  117 	tnz	a
      00814A 27 F6            [ 1]  118 	jreq	00101$
                                    119 ;	src/stm8_uart.c: 48: ch++;
      00814C 90 5C            [ 2]  120 	incw	y
      00814E 20 E9            [ 2]  121 	jra	00104$
      008150                        122 00107$:
      008150 81               [ 4]  123 	ret
                                    124 	.area CODE
                                    125 	.area INITIALIZER
                                    126 	.area CABS (ABS)
