/**
  *********************************************************************
  * @file    stm8_millis.h
  * @author  Aniket Fondekaar
  * @date    13 Feb 2021
  * @brief   timer (millis) 
  *********************************************************************
**/
#ifndef STM8_TIM4_H
#define STM8_TIM4_H

#include "stm8.h"
#include <stdint.h>

void Init_Timer4(void);
void Setup_TIM4(void);

uint32_t Millis();
#endif
