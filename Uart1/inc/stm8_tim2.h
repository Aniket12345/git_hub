/**
  *********************************************************************
  * @file    stm8_tim2.h
  * @author  Aniket Fondekaar
  * @date    28 July 2019
  * @brief   This file contains functions declaration for the TIM2 
  *********************************************************************
**/
#include <stdint.h>

#ifndef STM8_TIM2_H
#define STM8_TIM2_H

void Initialise_Timer2();
void Setup_Timer2(uint8_t pre, uint8_t high, uint8_t low);
#endif
 
