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
// ISR for tim4 overflow
void timer_isr(void) __interrupt(TIM4_OVR_UIF_IRQ)
{
    PB_ODR ^= (1 << 5);
    TIM4_SR &= ~(TIM_SR1_UIF);
}

void Init_Timer4(void);
void Setup_TIM4(void);

#endif
