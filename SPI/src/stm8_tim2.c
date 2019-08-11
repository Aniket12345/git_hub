/** 
  ********************************************************************* 
  * @file    stm8_tim2.h 
  * @author  Aniket Fondekaar 
  * @date    28 July 2019 
  * @brief   This file contains functions defination for the TIM2  
  ********************************************************************* 
**/ 
#include "stm8.h"
#include "stm8_tim2.h"
#include <stdint.h>

void Initialise_Timer2()
{
        TIM2_CR1 = 0;               // Turn everything TIM2 related off.
        TIM2_IER = 0;
        TIM2_SR2 = 0;
        TIM2_CCER1 = 0;
        TIM2_CCER2 = 0;
        TIM2_CCER1 = 0;
        TIM2_CCER2 = 0;
        TIM2_CCMR1 = 0;
        TIM2_CCMR2 = 0;
        TIM2_CCMR3 = 0;
        TIM2_CNTRH = 0;
        TIM2_CNTRL = 0;
        TIM2_PSCR = 0;
        TIM2_ARRH  = 0;
        TIM2_ARRL  = 0;
        TIM2_CCR1H = 0;
        TIM2_CCR1L = 0;
        TIM2_CCR2H = 0;
        TIM2_CCR2L = 0;
        TIM2_CCR3H = 0;
        TIM2_CCR3L = 0;
        TIM2_SR1 = 0;
}

void Setup_Timer2(uint8_t pre, uint8_t high, uint8_t low)
{
	TIM2_PSCR = pre;
	TIM2_ARRH = high;
	TIM2_ARRL = low;
	TIM2_IER |= TIM_IER_UIE;	// Enable the update interrupt
	TIM2_CR1 |= TIM_CR1_CEN;	// Finally enable the timer
}
