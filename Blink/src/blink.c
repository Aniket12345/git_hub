/**
  *********************************************************************
  * @file    main.c
  * @author  Aniket Fondekaar
  * @date    12 Aug 2019
  * @brief   Simple LED blinking program 
  *********************************************************************
**/
#include <stdint.h>
#include "stm8_millis.h"
#include "stm8.h"

/* Build in LED is in pin B5 (STM8S103 board) or D3 (STM8S003F3 board) */
#ifdef STM8S103
#define LED_PORT    PB
#define LED_PIN     PIN5
#else
#define LED_PORT    PD
#define LED_PIN     PIN3
#endif


unsigned long start_time;
unsigned long current_time;

int main(void)
{
    disableInterrupts();
    /* Set clock to full speed (16 Mhz) */
    CLK_CKDIVR = 0;

    /* GPIO setup */
    // Set pin data direction as output
    PORT(LED_PORT, DDR)  |= LED_PIN; // i.e. PB_DDR |= (1 << 5);
    // Set pin as "Push-pull"
    PORT(LED_PORT, CR1)  |= LED_PIN; // i.e. PB_CR1 |= (1 << 5);

    Init_Timer4();
    Setup_TIM4();
    enableInterrupts();
    
    start_time = Millis();

	while(1) 
    {
	current_time = Millis();
	if(current_time - start_time >= 1000u)
	{
	    PB_ODR ^= (1 << 5);
	    start_time = current_time;
	}
			
    }
}
