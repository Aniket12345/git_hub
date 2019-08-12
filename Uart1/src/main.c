/**
  *********************************************************************
  * @file    main.c
  * @author  Aniket Fondekaar
  * @date    12 Aug 2019
  * @brief   Uart and Timer2 interrupt implementation
  *********************************************************************
**/

#include <stdint.h>
#include "stm8.h"
#include "stm8_clk.h"
#include "stm8_uart.h"
#include "stm8_tim2.h"

/* Build in LED is in pin B5 (STM8S103 board) or D3 (STM8S003F3 board) */
#ifdef STM8S103
#define LED_PORT    PB
#define LED_PIN     PIN5
#else
#define LED_PORT    PD
#define LED_PIN     PIN3
#endif


#define PSCR		0x03	//  Prescaler = 8
#define ARRH		0xC3	//  High byte of 50,000
#define ARRL		0x50	//  Low byte of 50,000



void timer_isr(void) __interrupt(TIM2_OVR_UIF_IRQ)
{
	PORT(LED_PORT, ODR) ^= LED_PIN;
	//  Clear timer 2 status register
	
	TIM2_SR1 &= ~TIM_SR1_UIF;
}
 		
/* Simple busy loop delay */
void delay(unsigned long count) {
    while (count--)
        nop();
}

int main(void)
{
	disableInterrupts();

	/* Set clock to full speed (16 Mhz) */
	Initialise_System_Clock();

	Initialise_Timer2();

	Setup_Timer2(PSCR, ARRH, ARRL);

	Initialise_Uart();

	/* GPIO setup */
	// Set pin data direction as output
	PORT(LED_PORT, DDR)  |= LED_PIN; // i.e. PB_DDR |= (1 << 5);
	// Set pin as "Push-pull"
	PORT(LED_PORT, CR1)  |= LED_PIN; // i.e. PB_CR1 |= (1 << 5);
	
	enableInterrupts();
	while(1) 
	{
	/*	// LED on
		PORT(LED_PORT, ODR) |= LED_PIN; // PB_ODR |= (1 << 5);
		delay(100000L);
		// LED off
		PORT(LED_PORT, ODR) &= ~LED_PIN; // PB_ODR &= ~(1 << 5);
		delay(300000L);*/
	wfi();
		Uart_Printf("Bare metal Programming for STM8 for firmware follow on github\n\r");
	}
}
