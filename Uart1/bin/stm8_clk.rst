                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 3.5.0 #9253 (Mar 24 2016) (Linux)
                                      4 ; This file was generated Mon Aug  5 22:17:27 2019
                                      5 ;--------------------------------------------------------
                                      6 	.module stm8_clk
                                      7 	.optsdcc -mstm8
                                      8 	
                                      9 ;--------------------------------------------------------
                                     10 ; Public variables in this module
                                     11 ;--------------------------------------------------------
                                     12 	.globl _Initialise_System_Clock
                                     13 ;--------------------------------------------------------
                                     14 ; ram data
                                     15 ;--------------------------------------------------------
                                     16 	.area DATA
                                     17 ;--------------------------------------------------------
                                     18 ; ram data
                                     19 ;--------------------------------------------------------
                                     20 	.area INITIALIZED
                                     21 ;--------------------------------------------------------
                                     22 ; absolute external ram data
                                     23 ;--------------------------------------------------------
                                     24 	.area DABS (ABS)
                                     25 ;--------------------------------------------------------
                                     26 ; global & static initialisations
                                     27 ;--------------------------------------------------------
                                     28 	.area HOME
                                     29 	.area GSINIT
                                     30 	.area GSFINAL
                                     31 	.area GSINIT
                                     32 ;--------------------------------------------------------
                                     33 ; Home
                                     34 ;--------------------------------------------------------
                                     35 	.area HOME
                                     36 	.area HOME
                                     37 ;--------------------------------------------------------
                                     38 ; code
                                     39 ;--------------------------------------------------------
                                     40 	.area CODE
                                     41 ;	src/stm8_clk.c: 13: void Initialise_System_Clock()
                                     42 ;	-----------------------------------------
                                     43 ;	 function Initialise_System_Clock
                                     44 ;	-----------------------------------------
      0080A0                         45 _Initialise_System_Clock:
                                     46 ;	src/stm8_clk.c: 15: CLK_ICKR = 0;			//  Reset the Internal clock register
      0080A0 35 00 50 C0      [ 1]   47 	mov	0x50c0+0, #0x00
                                     48 ;	src/stm8_clk.c: 16: CLK_ICKR |= CLK_ICKR_HSIEN;	//  enable HSI(bit 0)
      0080A4 72 10 50 C0      [ 1]   49 	bset	0x50c0, #0
                                     50 ;	src/stm8_clk.c: 17: CLK_ECKR = 0;      		//  Disable external clock
      0080A8 35 00 50 C1      [ 1]   51 	mov	0x50c1+0, #0x00
                                     52 ;	src/stm8_clk.c: 19: while((CLK_ICKR &= CLK_ICKR_HSIRDY) == 0);     //  wait for HSI to be ready for use 
      0080AC                         53 00101$:
      0080AC AE 50 C0         [ 2]   54 	ldw	x, #0x50c0
      0080AF F6               [ 1]   55 	ld	a, (x)
      0080B0 A4 02            [ 1]   56 	and	a, #0x02
      0080B2 F7               [ 1]   57 	ld	(x), a
      0080B3 4D               [ 1]   58 	tnz	a
      0080B4 27 F6            [ 1]   59 	jreq	00101$
                                     60 ;	src/stm8_clk.c: 21: CLK_CKDIVR = 0;    		//  Ensure the clocks are running at full speed.
      0080B6 35 00 50 C6      [ 1]   61 	mov	0x50c6+0, #0x00
                                     62 ;	src/stm8_clk.c: 24: CLK_PCKENR1 = 0xFF;		//  Enable all peripheral clock
      0080BA 35 FF 50 C7      [ 1]   63 	mov	0x50c7+0, #0xff
                                     64 ;	src/stm8_clk.c: 25: CLK_PCKENR2 = 0xFF;		//  Same 
      0080BE 35 FF 50 CA      [ 1]   65 	mov	0x50ca+0, #0xff
                                     66 ;	src/stm8_clk.c: 26: CLK_CCOR = 0;      		//  CLK output register off
      0080C2 35 00 50 C9      [ 1]   67 	mov	0x50c9+0, #0x00
                                     68 ;	src/stm8_clk.c: 27: CLK_HSITRIMR = 0;  		//  Turn off any HSIU trimming 
      0080C6 35 00 50 CC      [ 1]   69 	mov	0x50cc+0, #0x00
                                     70 ;	src/stm8_clk.c: 28: CLK_SWIMCCR = 0;   		//  set swim to run at clk/2
      0080CA 35 00 50 CD      [ 1]   71 	mov	0x50cd+0, #0x00
                                     72 ;	src/stm8_clk.c: 29: CLK_SWR = 0xE1;    		//  Use HSI as clock source
      0080CE 35 E1 50 C4      [ 1]   73 	mov	0x50c4+0, #0xe1
                                     74 ;	src/stm8_clk.c: 30: CLK_SWCR = 0;      		//  Reset the clk switch control register
      0080D2 35 00 50 C5      [ 1]   75 	mov	0x50c5+0, #0x00
                                     76 ;	src/stm8_clk.c: 31: CLK_SWCR |= CLK_SWCR_SWEN;  	//  enable switching 
      0080D6 AE 50 C5         [ 2]   77 	ldw	x, #0x50c5
      0080D9 F6               [ 1]   78 	ld	a, (x)
      0080DA AA 02            [ 1]   79 	or	a, #0x02
      0080DC F7               [ 1]   80 	ld	(x), a
                                     81 ;	src/stm8_clk.c: 33: while((CLK_SWCR &= CLK_SWCR_SWBSY) != 0);     //  pause while the clk is busy
      0080DD                         82 00104$:
      0080DD AE 50 C5         [ 2]   83 	ldw	x, #0x50c5
      0080E0 F6               [ 1]   84 	ld	a, (x)
      0080E1 A4 01            [ 1]   85 	and	a, #0x01
      0080E3 F7               [ 1]   86 	ld	(x), a
      0080E4 4D               [ 1]   87 	tnz	a
      0080E5 26 F6            [ 1]   88 	jrne	00104$
      0080E7 81               [ 4]   89 	ret
                                     90 	.area CODE
                                     91 	.area INITIALIZER
                                     92 	.area CABS (ABS)
