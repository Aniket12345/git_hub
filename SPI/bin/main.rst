                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 3.5.0 #9253 (Mar 24 2016) (Linux)
                                      4 ; This file was generated Sun Aug 11 22:41:03 2019
                                      5 ;--------------------------------------------------------
                                      6 	.module main
                                      7 	.optsdcc -mstm8
                                      8 	
                                      9 ;--------------------------------------------------------
                                     10 ; Public variables in this module
                                     11 ;--------------------------------------------------------
                                     12 	.globl _main
                                     13 	.globl _Chip_Deselect
                                     14 	.globl _Chip_Select
                                     15 	.globl _Spi_Write
                                     16 	.globl _Spi_Init
                                     17 	.globl _Initialise_System_Clock
                                     18 ;--------------------------------------------------------
                                     19 ; ram data
                                     20 ;--------------------------------------------------------
                                     21 	.area DATA
                                     22 ;--------------------------------------------------------
                                     23 ; ram data
                                     24 ;--------------------------------------------------------
                                     25 	.area INITIALIZED
                                     26 ;--------------------------------------------------------
                                     27 ; Stack segment in internal ram 
                                     28 ;--------------------------------------------------------
                                     29 	.area	SSEG
      008258                         30 __start__stack:
      008258                         31 	.ds	1
                                     32 
                                     33 ;--------------------------------------------------------
                                     34 ; absolute external ram data
                                     35 ;--------------------------------------------------------
                                     36 	.area DABS (ABS)
                                     37 ;--------------------------------------------------------
                                     38 ; interrupt vector 
                                     39 ;--------------------------------------------------------
                                     40 	.area HOME
      008000                         41 __interrupt_vect:
      008000 82 00 80 83             42 	int s_GSINIT ;reset
      008004 82 00 00 00             43 	int 0x0000 ;trap
      008008 82 00 00 00             44 	int 0x0000 ;int0
      00800C 82 00 00 00             45 	int 0x0000 ;int1
      008010 82 00 00 00             46 	int 0x0000 ;int2
      008014 82 00 00 00             47 	int 0x0000 ;int3
      008018 82 00 00 00             48 	int 0x0000 ;int4
      00801C 82 00 00 00             49 	int 0x0000 ;int5
      008020 82 00 00 00             50 	int 0x0000 ;int6
      008024 82 00 00 00             51 	int 0x0000 ;int7
      008028 82 00 00 00             52 	int 0x0000 ;int8
      00802C 82 00 00 00             53 	int 0x0000 ;int9
      008030 82 00 00 00             54 	int 0x0000 ;int10
      008034 82 00 00 00             55 	int 0x0000 ;int11
      008038 82 00 00 00             56 	int 0x0000 ;int12
      00803C 82 00 00 00             57 	int 0x0000 ;int13
      008040 82 00 00 00             58 	int 0x0000 ;int14
      008044 82 00 00 00             59 	int 0x0000 ;int15
      008048 82 00 00 00             60 	int 0x0000 ;int16
      00804C 82 00 00 00             61 	int 0x0000 ;int17
      008050 82 00 00 00             62 	int 0x0000 ;int18
      008054 82 00 00 00             63 	int 0x0000 ;int19
      008058 82 00 00 00             64 	int 0x0000 ;int20
      00805C 82 00 00 00             65 	int 0x0000 ;int21
      008060 82 00 00 00             66 	int 0x0000 ;int22
      008064 82 00 00 00             67 	int 0x0000 ;int23
      008068 82 00 00 00             68 	int 0x0000 ;int24
      00806C 82 00 00 00             69 	int 0x0000 ;int25
      008070 82 00 00 00             70 	int 0x0000 ;int26
      008074 82 00 00 00             71 	int 0x0000 ;int27
      008078 82 00 00 00             72 	int 0x0000 ;int28
      00807C 82 00 00 00             73 	int 0x0000 ;int29
                                     74 ;--------------------------------------------------------
                                     75 ; global & static initialisations
                                     76 ;--------------------------------------------------------
                                     77 	.area HOME
                                     78 	.area GSINIT
                                     79 	.area GSFINAL
                                     80 	.area GSINIT
      008083                         81 __sdcc_gs_init_startup:
      008083                         82 __sdcc_init_data:
                                     83 ; stm8_genXINIT() start
      008083 AE 00 00         [ 2]   84 	ldw x, #l_DATA
      008086 27 07            [ 1]   85 	jreq	00002$
      008088                         86 00001$:
      008088 72 4F 00 00      [ 1]   87 	clr (s_DATA - 1, x)
      00808C 5A               [ 2]   88 	decw x
      00808D 26 F9            [ 1]   89 	jrne	00001$
      00808F                         90 00002$:
      00808F AE 00 00         [ 2]   91 	ldw	x, #l_INITIALIZER
      008092 27 09            [ 1]   92 	jreq	00004$
      008094                         93 00003$:
      008094 D6 82 57         [ 1]   94 	ld	a, (s_INITIALIZER - 1, x)
      008097 D7 00 00         [ 1]   95 	ld	(s_INITIALIZED - 1, x), a
      00809A 5A               [ 2]   96 	decw	x
      00809B 26 F7            [ 1]   97 	jrne	00003$
      00809D                         98 00004$:
                                     99 ; stm8_genXINIT() end
                                    100 	.area GSFINAL
      00809D CC 80 80         [ 2]  101 	jp	__sdcc_program_startup
                                    102 ;--------------------------------------------------------
                                    103 ; Home
                                    104 ;--------------------------------------------------------
                                    105 	.area HOME
                                    106 	.area HOME
      008080                        107 __sdcc_program_startup:
      008080 CC 81 B5         [ 2]  108 	jp	_main
                                    109 ;	return from main will return to caller
                                    110 ;--------------------------------------------------------
                                    111 ; code
                                    112 ;--------------------------------------------------------
                                    113 	.area CODE
                                    114 ;	src/main.c: 8: void main()
                                    115 ;	-----------------------------------------
                                    116 ;	 function main
                                    117 ;	-----------------------------------------
      0081B5                        118 _main:
                                    119 ;	src/main.c: 10: disableInterrupts();
      0081B5 9B               [ 1]  120 	sim
                                    121 ;	src/main.c: 13: Initialise_System_Clock();
      0081B6 CD 80 A0         [ 4]  122 	call	_Initialise_System_Clock
                                    123 ;	src/main.c: 17: Spi_Init();
      0081B9 CD 81 51         [ 4]  124 	call	_Spi_Init
                                    125 ;	src/main.c: 19: enableInterrupts();
      0081BC 9A               [ 1]  126 	rim
                                    127 ;	src/main.c: 20: while(1) 
      0081BD                        128 00102$:
                                    129 ;	src/main.c: 22: Chip_Select();
      0081BD CD 81 9E         [ 4]  130 	call	_Chip_Select
                                    131 ;	src/main.c: 23: Spi_Write(0x10);
      0081C0 4B 10            [ 1]  132 	push	#0x10
      0081C2 CD 81 7D         [ 4]  133 	call	_Spi_Write
      0081C5 84               [ 1]  134 	pop	a
                                    135 ;	src/main.c: 24: Spi_Write(0x11);
      0081C6 4B 11            [ 1]  136 	push	#0x11
      0081C8 CD 81 7D         [ 4]  137 	call	_Spi_Write
      0081CB 84               [ 1]  138 	pop	a
                                    139 ;	src/main.c: 25: Spi_Write(0x12);
      0081CC 4B 12            [ 1]  140 	push	#0x12
      0081CE CD 81 7D         [ 4]  141 	call	_Spi_Write
      0081D1 84               [ 1]  142 	pop	a
                                    143 ;	src/main.c: 26: Spi_Write(0x13);
      0081D2 4B 13            [ 1]  144 	push	#0x13
      0081D4 CD 81 7D         [ 4]  145 	call	_Spi_Write
      0081D7 84               [ 1]  146 	pop	a
                                    147 ;	src/main.c: 27: Spi_Write(0x14);
      0081D8 4B 14            [ 1]  148 	push	#0x14
      0081DA CD 81 7D         [ 4]  149 	call	_Spi_Write
      0081DD 84               [ 1]  150 	pop	a
                                    151 ;	src/main.c: 28: Chip_Deselect();
      0081DE CD 81 A6         [ 4]  152 	call	_Chip_Deselect
      0081E1 20 DA            [ 2]  153 	jra	00102$
      0081E3 81               [ 4]  154 	ret
                                    155 	.area CODE
                                    156 	.area INITIALIZER
                                    157 	.area CABS (ABS)
