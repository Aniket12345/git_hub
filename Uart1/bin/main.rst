                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 3.5.0 #9253 (Mar 24 2016) (Linux)
                                      4 ; This file was generated Tue Jul 23 23:56:19 2019
                                      5 ;--------------------------------------------------------
                                      6 	.module main
                                      7 	.optsdcc -mstm8
                                      8 	
                                      9 ;--------------------------------------------------------
                                     10 ; Public variables in this module
                                     11 ;--------------------------------------------------------
                                     12 	.globl _main
                                     13 	.globl _delay
                                     14 	.globl _Uart_Printf
                                     15 	.globl _Initialise_Uart
                                     16 	.globl _Initialise_System_Clock
                                     17 ;--------------------------------------------------------
                                     18 ; ram data
                                     19 ;--------------------------------------------------------
                                     20 	.area DATA
                                     21 ;--------------------------------------------------------
                                     22 ; ram data
                                     23 ;--------------------------------------------------------
                                     24 	.area INITIALIZED
                                     25 ;--------------------------------------------------------
                                     26 ; Stack segment in internal ram 
                                     27 ;--------------------------------------------------------
                                     28 	.area	SSEG
      0081DF                         29 __start__stack:
      0081DF                         30 	.ds	1
                                     31 
                                     32 ;--------------------------------------------------------
                                     33 ; absolute external ram data
                                     34 ;--------------------------------------------------------
                                     35 	.area DABS (ABS)
                                     36 ;--------------------------------------------------------
                                     37 ; interrupt vector 
                                     38 ;--------------------------------------------------------
                                     39 	.area HOME
      008000                         40 __interrupt_vect:
      008000 82 00 80 83             41 	int s_GSINIT ;reset
      008004 82 00 00 00             42 	int 0x0000 ;trap
      008008 82 00 00 00             43 	int 0x0000 ;int0
      00800C 82 00 00 00             44 	int 0x0000 ;int1
      008010 82 00 00 00             45 	int 0x0000 ;int2
      008014 82 00 00 00             46 	int 0x0000 ;int3
      008018 82 00 00 00             47 	int 0x0000 ;int4
      00801C 82 00 00 00             48 	int 0x0000 ;int5
      008020 82 00 00 00             49 	int 0x0000 ;int6
      008024 82 00 00 00             50 	int 0x0000 ;int7
      008028 82 00 00 00             51 	int 0x0000 ;int8
      00802C 82 00 00 00             52 	int 0x0000 ;int9
      008030 82 00 00 00             53 	int 0x0000 ;int10
      008034 82 00 00 00             54 	int 0x0000 ;int11
      008038 82 00 00 00             55 	int 0x0000 ;int12
      00803C 82 00 00 00             56 	int 0x0000 ;int13
      008040 82 00 00 00             57 	int 0x0000 ;int14
      008044 82 00 00 00             58 	int 0x0000 ;int15
      008048 82 00 00 00             59 	int 0x0000 ;int16
      00804C 82 00 00 00             60 	int 0x0000 ;int17
      008050 82 00 00 00             61 	int 0x0000 ;int18
      008054 82 00 00 00             62 	int 0x0000 ;int19
      008058 82 00 00 00             63 	int 0x0000 ;int20
      00805C 82 00 00 00             64 	int 0x0000 ;int21
      008060 82 00 00 00             65 	int 0x0000 ;int22
      008064 82 00 00 00             66 	int 0x0000 ;int23
      008068 82 00 00 00             67 	int 0x0000 ;int24
      00806C 82 00 00 00             68 	int 0x0000 ;int25
      008070 82 00 00 00             69 	int 0x0000 ;int26
      008074 82 00 00 00             70 	int 0x0000 ;int27
      008078 82 00 00 00             71 	int 0x0000 ;int28
      00807C 82 00 00 00             72 	int 0x0000 ;int29
                                     73 ;--------------------------------------------------------
                                     74 ; global & static initialisations
                                     75 ;--------------------------------------------------------
                                     76 	.area HOME
                                     77 	.area GSINIT
                                     78 	.area GSFINAL
                                     79 	.area GSINIT
      008083                         80 __sdcc_gs_init_startup:
      008083                         81 __sdcc_init_data:
                                     82 ; stm8_genXINIT() start
      008083 AE 00 00         [ 2]   83 	ldw x, #l_DATA
      008086 27 07            [ 1]   84 	jreq	00002$
      008088                         85 00001$:
      008088 72 4F 00 00      [ 1]   86 	clr (s_DATA - 1, x)
      00808C 5A               [ 2]   87 	decw x
      00808D 26 F9            [ 1]   88 	jrne	00001$
      00808F                         89 00002$:
      00808F AE 00 00         [ 2]   90 	ldw	x, #l_INITIALIZER
      008092 27 09            [ 1]   91 	jreq	00004$
      008094                         92 00003$:
      008094 D6 81 DE         [ 1]   93 	ld	a, (s_INITIALIZER - 1, x)
      008097 D7 00 00         [ 1]   94 	ld	(s_INITIALIZED - 1, x), a
      00809A 5A               [ 2]   95 	decw	x
      00809B 26 F7            [ 1]   96 	jrne	00003$
      00809D                         97 00004$:
                                     98 ; stm8_genXINIT() end
                                     99 	.area GSFINAL
      00809D CC 80 80         [ 2]  100 	jp	__sdcc_program_startup
                                    101 ;--------------------------------------------------------
                                    102 ; Home
                                    103 ;--------------------------------------------------------
                                    104 	.area HOME
                                    105 	.area HOME
      008080                        106 __sdcc_program_startup:
      008080 CC 81 84         [ 2]  107 	jp	_main
                                    108 ;	return from main will return to caller
                                    109 ;--------------------------------------------------------
                                    110 ; code
                                    111 ;--------------------------------------------------------
                                    112 	.area CODE
                                    113 ;	src/main.c: 17: void delay(unsigned long count) {
                                    114 ;	-----------------------------------------
                                    115 ;	 function delay
                                    116 ;	-----------------------------------------
      008151                        117 _delay:
      008151 52 08            [ 2]  118 	sub	sp, #8
                                    119 ;	src/main.c: 18: while (count--)
      008153 16 0B            [ 2]  120 	ldw	y, (0x0b, sp)
      008155 17 05            [ 2]  121 	ldw	(0x05, sp), y
      008157 1E 0D            [ 2]  122 	ldw	x, (0x0d, sp)
      008159                        123 00101$:
      008159 41               [ 1]  124 	exg	a, xl
      00815A 6B 04            [ 1]  125 	ld	(0x04, sp), a
      00815C 41               [ 1]  126 	exg	a, xl
      00815D 16 05            [ 2]  127 	ldw	y, (0x05, sp)
      00815F 17 01            [ 2]  128 	ldw	(0x01, sp), y
      008161 9E               [ 1]  129 	ld	a, xh
      008162 1D 00 01         [ 2]  130 	subw	x, #0x0001
      008165 88               [ 1]  131 	push	a
      008166 7B 07            [ 1]  132 	ld	a, (0x07, sp)
      008168 A2 00            [ 1]  133 	sbc	a, #0x00
      00816A 6B 07            [ 1]  134 	ld	(0x07, sp), a
      00816C 7B 06            [ 1]  135 	ld	a, (0x06, sp)
      00816E A2 00            [ 1]  136 	sbc	a, #0x00
      008170 6B 06            [ 1]  137 	ld	(0x06, sp), a
      008172 84               [ 1]  138 	pop	a
      008173 0D 04            [ 1]  139 	tnz	(0x04, sp)
      008175 26 07            [ 1]  140 	jrne	00115$
      008177 4D               [ 1]  141 	tnz	a
      008178 26 04            [ 1]  142 	jrne	00115$
      00817A 16 01            [ 2]  143 	ldw	y, (0x01, sp)
      00817C 27 03            [ 1]  144 	jreq	00104$
      00817E                        145 00115$:
                                    146 ;	src/main.c: 19: nop();
      00817E 9D               [ 1]  147 	nop
      00817F 20 D8            [ 2]  148 	jra	00101$
      008181                        149 00104$:
      008181 5B 08            [ 2]  150 	addw	sp, #8
      008183 81               [ 4]  151 	ret
                                    152 ;	src/main.c: 22: int main(void)
                                    153 ;	-----------------------------------------
                                    154 ;	 function main
                                    155 ;	-----------------------------------------
      008184                        156 _main:
                                    157 ;	src/main.c: 25: Initialise_System_Clock();
      008184 CD 80 A0         [ 4]  158 	call	_Initialise_System_Clock
                                    159 ;	src/main.c: 27: Initialise_Uart();
      008187 CD 80 E8         [ 4]  160 	call	_Initialise_Uart
                                    161 ;	src/main.c: 31: PORT(LED_PORT, DDR)  |= LED_PIN; // i.e. PB_DDR |= (1 << 5);
      00818A AE 50 07         [ 2]  162 	ldw	x, #0x5007
      00818D F6               [ 1]  163 	ld	a, (x)
      00818E AA 20            [ 1]  164 	or	a, #0x20
      008190 F7               [ 1]  165 	ld	(x), a
                                    166 ;	src/main.c: 33: PORT(LED_PORT, CR1)  |= LED_PIN; // i.e. PB_CR1 |= (1 << 5);
      008191 AE 50 08         [ 2]  167 	ldw	x, #0x5008
      008194 F6               [ 1]  168 	ld	a, (x)
      008195 AA 20            [ 1]  169 	or	a, #0x20
      008197 F7               [ 1]  170 	ld	(x), a
                                    171 ;	src/main.c: 35: while(1) 
      008198                        172 00102$:
                                    173 ;	src/main.c: 38: PORT(LED_PORT, ODR) |= LED_PIN; // PB_ODR |= (1 << 5);
      008198 AE 50 05         [ 2]  174 	ldw	x, #0x5005
      00819B F6               [ 1]  175 	ld	a, (x)
      00819C AA 20            [ 1]  176 	or	a, #0x20
      00819E F7               [ 1]  177 	ld	(x), a
                                    178 ;	src/main.c: 39: delay(100000L);
      00819F 4B A0            [ 1]  179 	push	#0xa0
      0081A1 4B 86            [ 1]  180 	push	#0x86
      0081A3 4B 01            [ 1]  181 	push	#0x01
      0081A5 4B 00            [ 1]  182 	push	#0x00
      0081A7 CD 81 51         [ 4]  183 	call	_delay
      0081AA 5B 04            [ 2]  184 	addw	sp, #4
                                    185 ;	src/main.c: 41: PORT(LED_PORT, ODR) &= ~LED_PIN; // PB_ODR &= ~(1 << 5);
      0081AC AE 50 05         [ 2]  186 	ldw	x, #0x5005
      0081AF F6               [ 1]  187 	ld	a, (x)
      0081B0 A4 DF            [ 1]  188 	and	a, #0xdf
      0081B2 F7               [ 1]  189 	ld	(x), a
                                    190 ;	src/main.c: 42: delay(300000L);
      0081B3 4B E0            [ 1]  191 	push	#0xe0
      0081B5 4B 93            [ 1]  192 	push	#0x93
      0081B7 4B 04            [ 1]  193 	push	#0x04
      0081B9 4B 00            [ 1]  194 	push	#0x00
      0081BB CD 81 51         [ 4]  195 	call	_delay
      0081BE 5B 04            [ 2]  196 	addw	sp, #4
                                    197 ;	src/main.c: 44: Uart_Printf("Hello world......\n\r");
      0081C0 AE 81 CB         [ 2]  198 	ldw	x, #___str_0+0
      0081C3 89               [ 2]  199 	pushw	x
      0081C4 CD 81 37         [ 4]  200 	call	_Uart_Printf
      0081C7 85               [ 2]  201 	popw	x
      0081C8 20 CE            [ 2]  202 	jra	00102$
      0081CA 81               [ 4]  203 	ret
                                    204 	.area CODE
      0081CB                        205 ___str_0:
      0081CB 48 65 6C 6C 6F 20 77   206 	.ascii "Hello world......"
             6F 72 6C 64 2E 2E 2E
             2E 2E 2E
      0081DC 0A                     207 	.db 0x0A
      0081DD 0D                     208 	.db 0x0D
      0081DE 00                     209 	.db 0x00
                                    210 	.area INITIALIZER
                                    211 	.area CABS (ABS)
