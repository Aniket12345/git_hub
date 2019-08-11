/**
  *********************************************************************
  * @file    stm8_spi.h
  * @author  Aniket Fondekaar
  * @date    06 Aug 2019
  * @brief   This file contains functions declaration for the SPI peripheral 
  *********************************************************************
**/
 
#ifndef STM8_SPI_H
#define STM8_SPI_H
#include<stdint.h>
void Spi_Init();
void Spi_Write(uint8_t data);
uint8_t Spi_Read();
void Chip_Select();
void Chip_Deselect();

#endif
