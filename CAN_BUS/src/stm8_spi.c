/**
  *********************************************************************
  * @file    stm8_spi.c
  * @author  Aniket Fondekaar
  * @date    5 Aug 2019
  * @brief   This file contains functions defination for the SPI
  *********************************************************************
**/
#include<stdint.h>
#include"stm8.h"
#include"stm8_spi.h"

/******************
 SPI pinout
** SCK -> PC5
** MOSI -> PC6
** MISO -> PC7
** CS -> PC4
******************/

#define CS_PIN		4

void Spi_Init()
{
	/*  Initialize CS pin*/
	PC_DDR |= (1 << CS_PIN);
	PC_CR1 |= (1 << CS_PIN);
	PC_ODR |= (1 << CS_PIN);

	/*Initialisation of SPI*/
	SPI_CR1 = 0;
	SPI_CR2 = 0;
	
	/*  Initialize SPI master at 500kH */
	SPI_CR2 |= (SPI_CR2_SSI) | (SPI_CR2_SSM); 	//  Master mode & software SS
	SPI_CR1 |= (SPI_CR1_MSTR) | (SPI_CR1_SPE) | (SPI_CR1_BR(4)) ;
}

void Spi_Write(uint8_t data)
{
	SPI_DR = data;
	while( !(SPI_SR & SPI_SR_TXE));		//  Wait till tx buffer is not empty
}

uint8_t Spi_Read()
{
	uint8_t Data =0x00;

	Spi_Write(0xFF);	//  To read write dummy value
	while(!(SPI_SR & SPI_SR_RXNE));		//  wait till rx buffer is full
	Data = SPI_DR;

	// Reading twice as initialy it will return (FF) value	
	while(!(SPI_SR & SPI_SR_RXNE));		//  wait till rx buffer is full
	Data = SPI_DR;
	return ((uint8_t)Data);
}

void Chip_Select()
{
	PC_ODR &= ~(1 << CS_PIN);
}

void Chip_Deselect()
{
	while((SPI_SR & (SPI_SR_BSY)));
	PC_ODR |= (1 << CS_PIN);
}	
