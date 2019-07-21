                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 3.5.0 #9253 (Mar 24 2016) (Linux)
                                      4 ; This file was generated Wed Jul 17 22:47:21 2019
                                      5 ;--------------------------------------------------------
                                      6 	.module Uart
                                      7 	.optsdcc -mstm8
                                      8 	
                                      9 ;--------------------------------------------------------
                                     10 ; Public variables in this module
                                     11 ;--------------------------------------------------------
                                     12 	.globl _main
                                     13 	.globl _uart_write
                                     14 	.globl _delay
                                     15 	.globl _strlen
                                     16 ;--------------------------------------------------------
                                     17 ; ram data
                                     18 ;--------------------------------------------------------
                                     19 	.area DATA
                                     20 ;--------------------------------------------------------
                                     21 ; ram data
                                     22 ;--------------------------------------------------------
                                     23 	.area INITIALIZED
                                     24 ;--------------------------------------------------------
                                     25 ; Stack segment in internal ram 
                                     26 ;--------------------------------------------------------
                                     27 	.area	SSEG
      000001                         28 __start__stack:
      000001                         29 	.ds	1
                                     30 
                                     31 ;--------------------------------------------------------
                                     32 ; absolute external ram data
                                     33 ;--------------------------------------------------------
                                     34 	.area DABS (ABS)
                                     35 ;--------------------------------------------------------
                                     36 ; interrupt vector 
                                     37 ;--------------------------------------------------------
                                     38 	.area HOME
      008000                         39 __interrupt_vect:
      008000 82 00 80 83             40 	int s_GSINIT ;reset
      008004 82 00 00 00             41 	int 0x0000 ;trap
      008008 82 00 00 00             42 	int 0x0000 ;int0
      00800C 82 00 00 00             43 	int 0x0000 ;int1
      008010 82 00 00 00             44 	int 0x0000 ;int2
      008014 82 00 00 00             45 	int 0x0000 ;int3
      008018 82 00 00 00             46 	int 0x0000 ;int4
      00801C 82 00 00 00             47 	int 0x0000 ;int5
      008020 82 00 00 00             48 	int 0x0000 ;int6
      008024 82 00 00 00             49 	int 0x0000 ;int7
      008028 82 00 00 00             50 	int 0x0000 ;int8
      00802C 82 00 00 00             51 	int 0x0000 ;int9
      008030 82 00 00 00             52 	int 0x0000 ;int10
      008034 82 00 00 00             53 	int 0x0000 ;int11
      008038 82 00 00 00             54 	int 0x0000 ;int12
      00803C 82 00 00 00             55 	int 0x0000 ;int13
      008040 82 00 00 00             56 	int 0x0000 ;int14
      008044 82 00 00 00             57 	int 0x0000 ;int15
      008048 82 00 00 00             58 	int 0x0000 ;int16
      00804C 82 00 00 00             59 	int 0x0000 ;int17
      008050 82 00 00 00             60 	int 0x0000 ;int18
      008054 82 00 00 00             61 	int 0x0000 ;int19
      008058 82 00 00 00             62 	int 0x0000 ;int20
      00805C 82 00 00 00             63 	int 0x0000 ;int21
      008060 82 00 00 00             64 	int 0x0000 ;int22
      008064 82 00 00 00             65 	int 0x0000 ;int23
      008068 82 00 00 00             66 	int 0x0000 ;int24
      00806C 82 00 00 00             67 	int 0x0000 ;int25
      008070 82 00 00 00             68 	int 0x0000 ;int26
      008074 82 00 00 00             69 	int 0x0000 ;int27
      008078 82 00 00 00             70 	int 0x0000 ;int28
      00807C 82 00 00 00             71 	int 0x0000 ;int29
                                     72 ;--------------------------------------------------------
                                     73 ; global & static initialisations
                                     74 ;--------------------------------------------------------
                                     75 	.area HOME
                                     76 	.area GSINIT
                                     77 	.area GSFINAL
                                     78 	.area GSINIT
      008083                         79 __sdcc_gs_init_startup:
      008083                         80 __sdcc_init_data:
                                     81 ; stm8_genXINIT() start
      008083 AE 00 00         [ 2]   82 	ldw x, #l_DATA
      008086 27 07            [ 1]   83 	jreq	00002$
      008088                         84 00001$:
      008088 72 4F 00 00      [ 1]   85 	clr (s_DATA - 1, x)
      00808C 5A               [ 2]   86 	decw x
      00808D 26 F9            [ 1]   87 	jrne	00001$
      00808F                         88 00002$:
      00808F AE 00 00         [ 2]   89 	ldw	x, #l_INITIALIZER
      008092 27 09            [ 1]   90 	jreq	00004$
      008094                         91 00003$:
      008094 D6 81 5E         [ 1]   92 	ld	a, (s_INITIALIZER - 1, x)
      008097 D7 00 00         [ 1]   93 	ld	(s_INITIALIZED - 1, x), a
      00809A 5A               [ 2]   94 	decw	x
      00809B 26 F7            [ 1]   95 	jrne	00003$
      00809D                         96 00004$:
                                     97 ; stm8_genXINIT() end
                                     98 	.area GSFINAL
      00809D CC 80 80         [ 2]   99 	jp	__sdcc_program_startup
                                    100 ;--------------------------------------------------------
                                    101 ; Home
                                    102 ;--------------------------------------------------------
                                    103 	.area HOME
                                    104 	.area HOME
      008080                        105 __sdcc_program_startup:
      008080 CC 81 0F         [ 2]  106 	jp	_main
                                    107 ;	return from main will return to caller
                                    108 ;--------------------------------------------------------
                                    109 ; code
                                    110 ;--------------------------------------------------------
                                    111 	.area CODE
                                    112 ;	src/Uart.c: 6: void delay(unsigned long count) {
                                    113 ;	-----------------------------------------
                                    114 ;	 function delay
                                    115 ;	-----------------------------------------
      0080A0                        116 _delay:
      0080A0 52 08            [ 2]  117 	sub	sp, #8
                                    118 ;	src/Uart.c: 7: while (count--)
      0080A2 16 0B            [ 2]  119 	ldw	y, (0x0b, sp)
      0080A4 17 01            [ 2]  120 	ldw	(0x01, sp), y
      0080A6 1E 0D            [ 2]  121 	ldw	x, (0x0d, sp)
      0080A8                        122 00101$:
      0080A8 41               [ 1]  123 	exg	a, xl
      0080A9 6B 08            [ 1]  124 	ld	(0x08, sp), a
      0080AB 41               [ 1]  125 	exg	a, xl
      0080AC 16 01            [ 2]  126 	ldw	y, (0x01, sp)
      0080AE 17 05            [ 2]  127 	ldw	(0x05, sp), y
      0080B0 9E               [ 1]  128 	ld	a, xh
      0080B1 1D 00 01         [ 2]  129 	subw	x, #0x0001
      0080B4 88               [ 1]  130 	push	a
      0080B5 7B 03            [ 1]  131 	ld	a, (0x03, sp)
      0080B7 A2 00            [ 1]  132 	sbc	a, #0x00
      0080B9 6B 03            [ 1]  133 	ld	(0x03, sp), a
      0080BB 7B 02            [ 1]  134 	ld	a, (0x02, sp)
      0080BD A2 00            [ 1]  135 	sbc	a, #0x00
      0080BF 6B 02            [ 1]  136 	ld	(0x02, sp), a
      0080C1 84               [ 1]  137 	pop	a
      0080C2 0D 08            [ 1]  138 	tnz	(0x08, sp)
      0080C4 26 07            [ 1]  139 	jrne	00115$
      0080C6 4D               [ 1]  140 	tnz	a
      0080C7 26 04            [ 1]  141 	jrne	00115$
      0080C9 16 05            [ 2]  142 	ldw	y, (0x05, sp)
      0080CB 27 03            [ 1]  143 	jreq	00104$
      0080CD                        144 00115$:
                                    145 ;	src/Uart.c: 8: nop();
      0080CD 9D               [ 1]  146 	nop
      0080CE 20 D8            [ 2]  147 	jra	00101$
      0080D0                        148 00104$:
      0080D0 5B 08            [ 2]  149 	addw	sp, #8
      0080D2 81               [ 4]  150 	ret
                                    151 ;	src/Uart.c: 11: int uart_write(const char *str) {
                                    152 ;	-----------------------------------------
                                    153 ;	 function uart_write
                                    154 ;	-----------------------------------------
      0080D3                        155 _uart_write:
      0080D3 52 03            [ 2]  156 	sub	sp, #3
                                    157 ;	src/Uart.c: 13: for(i = 0; i < strlen(str); i++) {
      0080D5 0F 01            [ 1]  158 	clr	(0x01, sp)
      0080D7                        159 00106$:
      0080D7 1E 06            [ 2]  160 	ldw	x, (0x06, sp)
      0080D9 89               [ 2]  161 	pushw	x
      0080DA CD 81 51         [ 4]  162 	call	_strlen
      0080DD 5B 02            [ 2]  163 	addw	sp, #2
      0080DF 1F 02            [ 2]  164 	ldw	(0x02, sp), x
      0080E1 7B 01            [ 1]  165 	ld	a, (0x01, sp)
      0080E3 97               [ 1]  166 	ld	xl, a
      0080E4 49               [ 1]  167 	rlc	a
      0080E5 4F               [ 1]  168 	clr	a
      0080E6 A2 00            [ 1]  169 	sbc	a, #0x00
      0080E8 95               [ 1]  170 	ld	xh, a
      0080E9 13 02            [ 2]  171 	cpw	x, (0x02, sp)
      0080EB 24 17            [ 1]  172 	jrnc	00104$
                                    173 ;	src/Uart.c: 14: while(!(UART1_SR & UART_SR_TXE)); // !Transmit data register empty
      0080ED                        174 00101$:
      0080ED AE 52 30         [ 2]  175 	ldw	x, #0x5230
      0080F0 F6               [ 1]  176 	ld	a, (x)
      0080F1 4D               [ 1]  177 	tnz	a
      0080F2 2A F9            [ 1]  178 	jrpl	00101$
                                    179 ;	src/Uart.c: 15: UART1_DR = str[i];
      0080F4 5F               [ 1]  180 	clrw	x
      0080F5 7B 01            [ 1]  181 	ld	a, (0x01, sp)
      0080F7 97               [ 1]  182 	ld	xl, a
      0080F8 72 FB 06         [ 2]  183 	addw	x, (0x06, sp)
      0080FB F6               [ 1]  184 	ld	a, (x)
      0080FC AE 52 31         [ 2]  185 	ldw	x, #0x5231
      0080FF F7               [ 1]  186 	ld	(x), a
                                    187 ;	src/Uart.c: 13: for(i = 0; i < strlen(str); i++) {
      008100 0C 01            [ 1]  188 	inc	(0x01, sp)
      008102 20 D3            [ 2]  189 	jra	00106$
      008104                        190 00104$:
                                    191 ;	src/Uart.c: 17: return(i); // Bytes sent
      008104 7B 01            [ 1]  192 	ld	a, (0x01, sp)
      008106 97               [ 1]  193 	ld	xl, a
      008107 49               [ 1]  194 	rlc	a
      008108 4F               [ 1]  195 	clr	a
      008109 A2 00            [ 1]  196 	sbc	a, #0x00
      00810B 95               [ 1]  197 	ld	xh, a
      00810C 5B 03            [ 2]  198 	addw	sp, #3
      00810E 81               [ 4]  199 	ret
                                    200 ;	src/Uart.c: 20: int main(void)
                                    201 ;	-----------------------------------------
                                    202 ;	 function main
                                    203 ;	-----------------------------------------
      00810F                        204 _main:
                                    205 ;	src/Uart.c: 23: CLK_CKDIVR = 0;
      00810F 35 00 50 C6      [ 1]  206 	mov	0x50c6+0, #0x00
                                    207 ;	src/Uart.c: 26: UART1_CR2 |= UART_CR2_TEN; // Transmitter enable
      008113 AE 52 35         [ 2]  208 	ldw	x, #0x5235
      008116 F6               [ 1]  209 	ld	a, (x)
      008117 AA 08            [ 1]  210 	or	a, #0x08
      008119 F7               [ 1]  211 	ld	(x), a
                                    212 ;	src/Uart.c: 28: UART1_CR3 &= ~(UART_CR3_STOP1 | UART_CR3_STOP2); // 1 stop bit
      00811A AE 52 36         [ 2]  213 	ldw	x, #0x5236
      00811D F6               [ 1]  214 	ld	a, (x)
      00811E A4 CF            [ 1]  215 	and	a, #0xcf
      008120 F7               [ 1]  216 	ld	(x), a
                                    217 ;	src/Uart.c: 30: UART1_BRR2 = 0x03; UART1_BRR1 = 0x68; // 0x0683 coded funky way (see ref manual)
      008121 35 03 52 33      [ 1]  218 	mov	0x5233+0, #0x03
      008125 35 68 52 32      [ 1]  219 	mov	0x5232+0, #0x68
                                    220 ;	src/Uart.c: 32: while(1) {
      008129                        221 00102$:
                                    222 ;	src/Uart.c: 33: uart_write("Hello World!\r\n");
      008129 AE 81 42         [ 2]  223 	ldw	x, #___str_0+0
      00812C 89               [ 2]  224 	pushw	x
      00812D CD 80 D3         [ 4]  225 	call	_uart_write
      008130 5B 02            [ 2]  226 	addw	sp, #2
                                    227 ;	src/Uart.c: 34: delay(400000L);
      008132 4B 80            [ 1]  228 	push	#0x80
      008134 4B 1A            [ 1]  229 	push	#0x1a
      008136 4B 06            [ 1]  230 	push	#0x06
      008138 4B 00            [ 1]  231 	push	#0x00
      00813A CD 80 A0         [ 4]  232 	call	_delay
      00813D 5B 04            [ 2]  233 	addw	sp, #4
      00813F 20 E8            [ 2]  234 	jra	00102$
      008141 81               [ 4]  235 	ret
                                    236 	.area CODE
      008142                        237 ___str_0:
      008142 48 65 6C 6C 6F 20 57   238 	.ascii "Hello World!"
             6F 72 6C 64 21
      00814E 0D                     239 	.db 0x0D
      00814F 0A                     240 	.db 0x0A
      008150 00                     241 	.db 0x00
                                    242 	.area INITIALIZER
                                    243 	.area CABS (ABS)
