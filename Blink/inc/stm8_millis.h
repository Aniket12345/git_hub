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
static volatile uint32_t millis_count;
void timer_isr(void) __interrupt(TIM4_OVR_UIF_IRQ)
{
    millis_count++;
    TIM4_SR &= ~(TIM_SR1_UIF);
}

uint32_t Millis()
{
    return millis_count;
}
void Init_Timer4(void);
void Setup_TIM4(void);

#endif
