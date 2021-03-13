/**
  *********************************************************************
  * @file    stm8_millis.c
  * @author  Aniket Fondekaar
  * @date    13 Feb 2021
  * @brief   timer (millis) 
  *********************************************************************
**/
#include "stm8.h"
#include <stdint.h>

extern volatile uint32_t millis_count;
void Init_Timer4()
{
   TIM4_CR1 = 0x00;
   TIM4_IER = 0x00;
   TIM4_EGR = 0x00;
   TIM4_CNTR = 0x00;
   TIM4_PSCR = 0x00;
   TIM4_ARR = 0x00;
}

void Setup_TIM4()
{
   TIM4_PSCR = 0b00000110;
   TIM4_ARR = 0xFA;
   TIM4_IER = TIM_IER_UIE;
   TIM4_CR1 = TIM_CR1_CEN;
}
uint32_t Millis()
{
   return millis_count;
}
