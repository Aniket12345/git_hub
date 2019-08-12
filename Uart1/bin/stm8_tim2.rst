                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 3.5.0 #9253 (Mar 24 2016) (Linux)
                                      4 ; This file was generated Mon Aug 12 22:43:56 2019
                                      5 ;--------------------------------------------------------
                                      6 	.module stm8_tim2
                                      7 	.optsdcc -mstm8
                                      8 	
                                      9 ;--------------------------------------------------------
                                     10 ; Public variables in this module
                                     11 ;--------------------------------------------------------
                                     12 	.globl _Initialise_Timer2
                                     13 	.globl _Setup_Timer2
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
                                     42 ;	src/stm8_tim2.c: 13: void Initialise_Timer2()
                                     43 ;	-----------------------------------------
                                     44 ;	 function Initialise_Timer2
                                     45 ;	-----------------------------------------
      008200                         46 _Initialise_Timer2:
                                     47 ;	src/stm8_tim2.c: 15: TIM2_CR1 = 0;               // Turn everything TIM2 related off.
      008200 35 00 53 00      [ 1]   48 	mov	0x5300+0, #0x00
                                     49 ;	src/stm8_tim2.c: 16: TIM2_IER = 0;
      008204 35 00 53 03      [ 1]   50 	mov	0x5303+0, #0x00
                                     51 ;	src/stm8_tim2.c: 17: TIM2_SR2 = 0;
      008208 35 00 53 05      [ 1]   52 	mov	0x5305+0, #0x00
                                     53 ;	src/stm8_tim2.c: 18: TIM2_CCER1 = 0;
      00820C 35 00 53 0A      [ 1]   54 	mov	0x530a+0, #0x00
                                     55 ;	src/stm8_tim2.c: 19: TIM2_CCER2 = 0;
      008210 35 00 53 0B      [ 1]   56 	mov	0x530b+0, #0x00
                                     57 ;	src/stm8_tim2.c: 20: TIM2_CCER1 = 0;
      008214 35 00 53 0A      [ 1]   58 	mov	0x530a+0, #0x00
                                     59 ;	src/stm8_tim2.c: 21: TIM2_CCER2 = 0;
      008218 35 00 53 0B      [ 1]   60 	mov	0x530b+0, #0x00
                                     61 ;	src/stm8_tim2.c: 22: TIM2_CCMR1 = 0;
      00821C 35 00 53 07      [ 1]   62 	mov	0x5307+0, #0x00
                                     63 ;	src/stm8_tim2.c: 23: TIM2_CCMR2 = 0;
      008220 35 00 53 08      [ 1]   64 	mov	0x5308+0, #0x00
                                     65 ;	src/stm8_tim2.c: 24: TIM2_CCMR3 = 0;
      008224 35 00 53 09      [ 1]   66 	mov	0x5309+0, #0x00
                                     67 ;	src/stm8_tim2.c: 25: TIM2_CNTRH = 0;
      008228 35 00 53 0C      [ 1]   68 	mov	0x530c+0, #0x00
                                     69 ;	src/stm8_tim2.c: 26: TIM2_CNTRL = 0;
      00822C 35 00 53 0D      [ 1]   70 	mov	0x530d+0, #0x00
                                     71 ;	src/stm8_tim2.c: 27: TIM2_PSCR = 0;
      008230 35 00 53 0E      [ 1]   72 	mov	0x530e+0, #0x00
                                     73 ;	src/stm8_tim2.c: 28: TIM2_ARRH  = 0;
      008234 35 00 53 0F      [ 1]   74 	mov	0x530f+0, #0x00
                                     75 ;	src/stm8_tim2.c: 29: TIM2_ARRL  = 0;
      008238 35 00 53 10      [ 1]   76 	mov	0x5310+0, #0x00
                                     77 ;	src/stm8_tim2.c: 30: TIM2_CCR1H = 0;
      00823C 35 00 53 11      [ 1]   78 	mov	0x5311+0, #0x00
                                     79 ;	src/stm8_tim2.c: 31: TIM2_CCR1L = 0;
      008240 35 00 53 12      [ 1]   80 	mov	0x5312+0, #0x00
                                     81 ;	src/stm8_tim2.c: 32: TIM2_CCR2H = 0;
      008244 35 00 53 13      [ 1]   82 	mov	0x5313+0, #0x00
                                     83 ;	src/stm8_tim2.c: 33: TIM2_CCR2L = 0;
      008248 35 00 53 14      [ 1]   84 	mov	0x5314+0, #0x00
                                     85 ;	src/stm8_tim2.c: 34: TIM2_CCR3H = 0;
      00824C 35 00 53 15      [ 1]   86 	mov	0x5315+0, #0x00
                                     87 ;	src/stm8_tim2.c: 35: TIM2_CCR3L = 0;
      008250 35 00 53 16      [ 1]   88 	mov	0x5316+0, #0x00
                                     89 ;	src/stm8_tim2.c: 36: TIM2_SR1 = 0;
      008254 35 00 53 04      [ 1]   90 	mov	0x5304+0, #0x00
      008258 81               [ 4]   91 	ret
                                     92 ;	src/stm8_tim2.c: 39: void Setup_Timer2(uint8_t pre, uint8_t high, uint8_t low)
                                     93 ;	-----------------------------------------
                                     94 ;	 function Setup_Timer2
                                     95 ;	-----------------------------------------
      008259                         96 _Setup_Timer2:
                                     97 ;	src/stm8_tim2.c: 41: TIM2_PSCR = pre;
      008259 AE 53 0E         [ 2]   98 	ldw	x, #0x530e
      00825C 7B 03            [ 1]   99 	ld	a, (0x03, sp)
      00825E F7               [ 1]  100 	ld	(x), a
                                    101 ;	src/stm8_tim2.c: 42: TIM2_ARRH = high;
      00825F AE 53 0F         [ 2]  102 	ldw	x, #0x530f
      008262 7B 04            [ 1]  103 	ld	a, (0x04, sp)
      008264 F7               [ 1]  104 	ld	(x), a
                                    105 ;	src/stm8_tim2.c: 43: TIM2_ARRL = low;
      008265 AE 53 10         [ 2]  106 	ldw	x, #0x5310
      008268 7B 05            [ 1]  107 	ld	a, (0x05, sp)
      00826A F7               [ 1]  108 	ld	(x), a
                                    109 ;	src/stm8_tim2.c: 44: TIM2_IER |= TIM_IER_UIE;	// Enable the update interrupt
      00826B 72 10 53 03      [ 1]  110 	bset	0x5303, #0
                                    111 ;	src/stm8_tim2.c: 45: TIM2_CR1 |= TIM_CR1_CEN;	// Finally enable the timer
      00826F 72 10 53 00      [ 1]  112 	bset	0x5300, #0
      008273 81               [ 4]  113 	ret
                                    114 	.area CODE
                                    115 	.area INITIALIZER
                                    116 	.area CABS (ABS)
