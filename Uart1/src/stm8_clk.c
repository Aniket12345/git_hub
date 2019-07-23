/**
  *********************************************************************
  * @file    stm8_uart.h
  * @author  Aniket Fondekaar
  * @date    23 July 2019
  * @brief   This file contains functions defination for the CLK 
  *********************************************************************
**/

#include"stm8.h"
#include"stm8_clk.h"

void Initialise_System_Clock()
{
        CLK_ICKR = 0;			//  Reset the Internal clock register
        CLK_ICKR |= CLK_ICKR_HSIEN;	//  enable HSI(bit 0)
        CLK_ECKR = 0;      		//  Disable external clock
        
	while((CLK_ICKR &= CLK_ICKR_HSIRDY) == 0);     //  wait for HSI to be ready for use 
        
	CLK_CKDIVR = 0;    		//  Ensure the clocks are running at full speed.
        //CLK_CKDIVR |= 0x08; //  Set the HSI divider to 2

        CLK_PCKENR1 = 0xFF;		//  Enable all peripheral clock
        CLK_PCKENR2 = 0xFF;		//  Same 
        CLK_CCOR = 0;      		//  CLK output register off
        CLK_HSITRIMR = 0;  		//  Turn off any HSIU trimming 
        CLK_SWIMCCR = 0;   		//  set swim to run at clk/2
        CLK_SWR = 0xE1;    		//  Use HSI as clock source
        CLK_SWCR = 0;      		//  Reset the clk switch control register
        CLK_SWCR |= CLK_SWCR_SWEN;  	//  enable switching 
        
	while((CLK_SWCR &= CLK_SWCR_SWBSY) != 0);     //  pause while the clk is busy
}

