                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 3.5.0 #9253 (Mar 24 2016) (Linux)
                                      4 ; This file was generated Mon Aug 12 22:43:56 2019
                                      5 ;--------------------------------------------------------
                                      6 	.module main
                                      7 	.optsdcc -mstm8
                                      8 	
                                      9 ;--------------------------------------------------------
                                     10 ; Public variables in this module
                                     11 ;--------------------------------------------------------
                                     12 	.globl _main
                                     13 	.globl _delay
                                     14 	.globl _timer_isr
                                     15 	.globl _Setup_Timer2
                                     16 	.globl _Initialise_Timer2
                                     17 	.globl _Uart_Printf
                                     18 	.globl _Initialise_Uart
                                     19 	.globl _Initialise_System_Clock
                                     20 ;--------------------------------------------------------
                                     21 ; ram data
                                     22 ;--------------------------------------------------------
                                     23 	.area DATA
                                     24 ;--------------------------------------------------------
                                     25 ; ram data
                                     26 ;--------------------------------------------------------
                                     27 	.area INITIALIZED
                                     28 ;--------------------------------------------------------
                                     29 ; Stack segment in internal ram 
                                     30 ;--------------------------------------------------------
                                     31 	.area	SSEG
      008274                         32 __start__stack:
      008274                         33 	.ds	1
                                     34 
                                     35 ;--------------------------------------------------------
                                     36 ; absolute external ram data
                                     37 ;--------------------------------------------------------
                                     38 	.area DABS (ABS)
                                     39 ;--------------------------------------------------------
                                     40 ; interrupt vector 
                                     41 ;--------------------------------------------------------
                                     42 	.area HOME
      008000                         43 __interrupt_vect:
      008000 82 00 80 83             44 	int s_GSINIT ;reset
      008004 82 00 00 00             45 	int 0x0000 ;trap
      008008 82 00 00 00             46 	int 0x0000 ;int0
      00800C 82 00 00 00             47 	int 0x0000 ;int1
      008010 82 00 00 00             48 	int 0x0000 ;int2
      008014 82 00 00 00             49 	int 0x0000 ;int3
      008018 82 00 00 00             50 	int 0x0000 ;int4
      00801C 82 00 00 00             51 	int 0x0000 ;int5
      008020 82 00 00 00             52 	int 0x0000 ;int6
      008024 82 00 00 00             53 	int 0x0000 ;int7
      008028 82 00 00 00             54 	int 0x0000 ;int8
      00802C 82 00 00 00             55 	int 0x0000 ;int9
      008030 82 00 00 00             56 	int 0x0000 ;int10
      008034 82 00 00 00             57 	int 0x0000 ;int11
      008038 82 00 00 00             58 	int 0x0000 ;int12
      00803C 82 00 81 51             59 	int _timer_isr ;int13
      008040 82 00 00 00             60 	int 0x0000 ;int14
      008044 82 00 00 00             61 	int 0x0000 ;int15
      008048 82 00 00 00             62 	int 0x0000 ;int16
      00804C 82 00 00 00             63 	int 0x0000 ;int17
      008050 82 00 00 00             64 	int 0x0000 ;int18
      008054 82 00 00 00             65 	int 0x0000 ;int19
      008058 82 00 00 00             66 	int 0x0000 ;int20
      00805C 82 00 00 00             67 	int 0x0000 ;int21
      008060 82 00 00 00             68 	int 0x0000 ;int22
      008064 82 00 00 00             69 	int 0x0000 ;int23
      008068 82 00 00 00             70 	int 0x0000 ;int24
      00806C 82 00 00 00             71 	int 0x0000 ;int25
      008070 82 00 00 00             72 	int 0x0000 ;int26
      008074 82 00 00 00             73 	int 0x0000 ;int27
      008078 82 00 00 00             74 	int 0x0000 ;int28
      00807C 82 00 00 00             75 	int 0x0000 ;int29
                                     76 ;--------------------------------------------------------
                                     77 ; global & static initialisations
                                     78 ;--------------------------------------------------------
                                     79 	.area HOME
                                     80 	.area GSINIT
                                     81 	.area GSFINAL
                                     82 	.area GSINIT
      008083                         83 __sdcc_gs_init_startup:
      008083                         84 __sdcc_init_data:
                                     85 ; stm8_genXINIT() start
      008083 AE 00 00         [ 2]   86 	ldw x, #l_DATA
      008086 27 07            [ 1]   87 	jreq	00002$
      008088                         88 00001$:
      008088 72 4F 00 00      [ 1]   89 	clr (s_DATA - 1, x)
      00808C 5A               [ 2]   90 	decw x
      00808D 26 F9            [ 1]   91 	jrne	00001$
      00808F                         92 00002$:
      00808F AE 00 00         [ 2]   93 	ldw	x, #l_INITIALIZER
      008092 27 09            [ 1]   94 	jreq	00004$
      008094                         95 00003$:
      008094 D6 82 73         [ 1]   96 	ld	a, (s_INITIALIZER - 1, x)
      008097 D7 00 00         [ 1]   97 	ld	(s_INITIALIZED - 1, x), a
      00809A 5A               [ 2]   98 	decw	x
      00809B 26 F7            [ 1]   99 	jrne	00003$
      00809D                        100 00004$:
                                    101 ; stm8_genXINIT() end
                                    102 	.area GSFINAL
      00809D CC 80 80         [ 2]  103 	jp	__sdcc_program_startup
                                    104 ;--------------------------------------------------------
                                    105 ; Home
                                    106 ;--------------------------------------------------------
                                    107 	.area HOME
                                    108 	.area HOME
      008080                        109 __sdcc_program_startup:
      008080 CC 81 90         [ 2]  110 	jp	_main
                                    111 ;	return from main will return to caller
                                    112 ;--------------------------------------------------------
                                    113 ; code
                                    114 ;--------------------------------------------------------
                                    115 	.area CODE
                                    116 ;	src/main.c: 32: void timer_isr(void) __interrupt(TIM2_OVR_UIF_IRQ)
                                    117 ;	-----------------------------------------
                                    118 ;	 function timer_isr
                                    119 ;	-----------------------------------------
      008151                        120 _timer_isr:
                                    121 ;	src/main.c: 34: PORT(LED_PORT, ODR) ^= LED_PIN;
      008151 AE 50 05         [ 2]  122 	ldw	x, #0x5005
      008154 F6               [ 1]  123 	ld	a, (x)
      008155 A8 20            [ 1]  124 	xor	a, #0x20
      008157 F7               [ 1]  125 	ld	(x), a
                                    126 ;	src/main.c: 37: TIM2_SR1 &= ~TIM_SR1_UIF;
      008158 72 11 53 04      [ 1]  127 	bres	0x5304, #0
      00815C 80               [11]  128 	iret
                                    129 ;	src/main.c: 41: void delay(unsigned long count) {
                                    130 ;	-----------------------------------------
                                    131 ;	 function delay
                                    132 ;	-----------------------------------------
      00815D                        133 _delay:
      00815D 52 08            [ 2]  134 	sub	sp, #8
                                    135 ;	src/main.c: 42: while (count--)
      00815F 16 0B            [ 2]  136 	ldw	y, (0x0b, sp)
      008161 17 01            [ 2]  137 	ldw	(0x01, sp), y
      008163 1E 0D            [ 2]  138 	ldw	x, (0x0d, sp)
      008165                        139 00101$:
      008165 41               [ 1]  140 	exg	a, xl
      008166 6B 08            [ 1]  141 	ld	(0x08, sp), a
      008168 41               [ 1]  142 	exg	a, xl
      008169 16 01            [ 2]  143 	ldw	y, (0x01, sp)
      00816B 17 05            [ 2]  144 	ldw	(0x05, sp), y
      00816D 9E               [ 1]  145 	ld	a, xh
      00816E 1D 00 01         [ 2]  146 	subw	x, #0x0001
      008171 88               [ 1]  147 	push	a
      008172 7B 03            [ 1]  148 	ld	a, (0x03, sp)
      008174 A2 00            [ 1]  149 	sbc	a, #0x00
      008176 6B 03            [ 1]  150 	ld	(0x03, sp), a
      008178 7B 02            [ 1]  151 	ld	a, (0x02, sp)
      00817A A2 00            [ 1]  152 	sbc	a, #0x00
      00817C 6B 02            [ 1]  153 	ld	(0x02, sp), a
      00817E 84               [ 1]  154 	pop	a
      00817F 0D 08            [ 1]  155 	tnz	(0x08, sp)
      008181 26 07            [ 1]  156 	jrne	00115$
      008183 4D               [ 1]  157 	tnz	a
      008184 26 04            [ 1]  158 	jrne	00115$
      008186 16 05            [ 2]  159 	ldw	y, (0x05, sp)
      008188 27 03            [ 1]  160 	jreq	00104$
      00818A                        161 00115$:
                                    162 ;	src/main.c: 43: nop();
      00818A 9D               [ 1]  163 	nop
      00818B 20 D8            [ 2]  164 	jra	00101$
      00818D                        165 00104$:
      00818D 5B 08            [ 2]  166 	addw	sp, #8
      00818F 81               [ 4]  167 	ret
                                    168 ;	src/main.c: 46: int main(void)
                                    169 ;	-----------------------------------------
                                    170 ;	 function main
                                    171 ;	-----------------------------------------
      008190                        172 _main:
                                    173 ;	src/main.c: 48: disableInterrupts();
      008190 9B               [ 1]  174 	sim
                                    175 ;	src/main.c: 51: Initialise_System_Clock();
      008191 CD 80 A0         [ 4]  176 	call	_Initialise_System_Clock
                                    177 ;	src/main.c: 53: Initialise_Timer2();
      008194 CD 82 00         [ 4]  178 	call	_Initialise_Timer2
                                    179 ;	src/main.c: 55: Setup_Timer2(PSCR, ARRH, ARRL);
      008197 4B 50            [ 1]  180 	push	#0x50
      008199 4B C3            [ 1]  181 	push	#0xc3
      00819B 4B 03            [ 1]  182 	push	#0x03
      00819D CD 82 59         [ 4]  183 	call	_Setup_Timer2
      0081A0 5B 03            [ 2]  184 	addw	sp, #3
                                    185 ;	src/main.c: 57: Initialise_Uart();
      0081A2 CD 80 E8         [ 4]  186 	call	_Initialise_Uart
                                    187 ;	src/main.c: 61: PORT(LED_PORT, DDR)  |= LED_PIN; // i.e. PB_DDR |= (1 << 5);
      0081A5 AE 50 07         [ 2]  188 	ldw	x, #0x5007
      0081A8 F6               [ 1]  189 	ld	a, (x)
      0081A9 AA 20            [ 1]  190 	or	a, #0x20
      0081AB F7               [ 1]  191 	ld	(x), a
                                    192 ;	src/main.c: 63: PORT(LED_PORT, CR1)  |= LED_PIN; // i.e. PB_CR1 |= (1 << 5);
      0081AC AE 50 08         [ 2]  193 	ldw	x, #0x5008
      0081AF F6               [ 1]  194 	ld	a, (x)
      0081B0 AA 20            [ 1]  195 	or	a, #0x20
      0081B2 F7               [ 1]  196 	ld	(x), a
                                    197 ;	src/main.c: 65: enableInterrupts();
      0081B3 9A               [ 1]  198 	rim
                                    199 ;	src/main.c: 66: while(1) 
      0081B4                        200 00102$:
                                    201 ;	src/main.c: 74: wfi();
      0081B4 8F               [10]  202 	wfi
                                    203 ;	src/main.c: 75: Uart_Printf("Bare metal Programming for STM8 for firmware follow on github\n\r");
      0081B5 AE 81 C0         [ 2]  204 	ldw	x, #___str_0+0
      0081B8 89               [ 2]  205 	pushw	x
      0081B9 CD 81 37         [ 4]  206 	call	_Uart_Printf
      0081BC 85               [ 2]  207 	popw	x
      0081BD 20 F5            [ 2]  208 	jra	00102$
      0081BF 81               [ 4]  209 	ret
                                    210 	.area CODE
      0081C0                        211 ___str_0:
      0081C0 42 61 72 65 20 6D 65   212 	.ascii "Bare metal Programming for STM8 for firmware follow on githu"
             74 61 6C 20 50 72 6F
             67 72 61 6D 6D 69 6E
             67 20 66 6F 72 20 53
             54 4D 38 20 66 6F 72
             20 66 69 72 6D 77 61
             72 65 20 66 6F 6C 6C
             6F 77 20 6F 6E 20 67
             69 74 68 75
      0081FC 62                     213 	.ascii "b"
      0081FD 0A                     214 	.db 0x0A
      0081FE 0D                     215 	.db 0x0D
      0081FF 00                     216 	.db 0x00
                                    217 	.area INITIALIZER
                                    218 	.area CABS (ABS)
