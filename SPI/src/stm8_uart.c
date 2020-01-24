/**
  *********************************************************************
  * @file    stm8_uart.h
  * @author  Aniket Fondekaar
  * @date    23 July 2019
  * @brief   This file contains functions defination for the UART peripheral 
  *********************************************************************
**/

#include "stm8.h"
#include "stm8_uart.h"

void Initialise_Uart ()
{
        // reset all uart1 register 
        UART_CR1 = 0;
        UART_CR2 = 0;
        UART_CR4 = 0;
        UART_CR3 = 0;
        UART_CR5 = 0;
        UART_GTR = 0;
        UART_PSCR = 0;

        //setup port to 115200,n,8,1stop bit
        UART_CR1 &= 0xEB;                         //clear M bit(8data bits) and PCEN (disable parity)
        UART_CR3 &= 0xCF;                         // 1 stop bit (bit5 and bit4)=0
        UART_BRR2 = 0x0A;                         //baudrate =115200 f=16Mhz
        UART_BRR1 = 0x08;

        //DISABLE TX AND RX
        UART_CR2 &= 0xF3;                         // disable tx and rx

        //set clock polarity
        UART_CR3 |= 0x07;                         //set CPOL CPHA LBCL

        //turn on uart tx rc and uart clk
        UART_CR2 |= 0x0C;
        UART_CR3 |= 0x08;                         //CLKEN =1
}

void Uart_Printf(char *message)
{
	char *ch = message;
	while(*ch != '\0')
	{
		UART_DR = (unsigned char) *ch;	//  put the next char into the buffer
		while((UART_SR &= UART_SR_TXE) == 0);	//  wait for TX to complete
		ch++;
	}
}
