#include <stdint.h>
#include <stdio.h>
#include "stm8.h"
#include "stm8_clk.h"
#include "stm8_uart.h"
#include "stm8_millis.h"
//#include "stm8_tim2.h"
#include "stm8_spi.h"
#include "mcp_can.h"

/******************
 SPI pinout
** SCK -> PC5
** MOSI -> PC6
** MISO -> PC7
** CS -> PC4

Uart Tx D5
******************/

uint8_t ret = 0x00;
uint8_t q =0;
unsigned char stmp[8] = {0x01,0x02,0x03,0x00,0x05,0x06,0x07};
uint8_t check = 0;
// ISR for tim4 overflow
   volatile uint32_t millis_count = 0;
   void timer_isr(void) __interrupt(TIM4_OVR_UIF_IRQ)
   {
	millis_count++;
	TIM4_SR &= ~(TIM_SR1_UIF);
   }  

   
void main(void)
{

   disableInterrupts();

   Initialise_System_Clock();

   Initialise_Uart();
   
   Init_Timer4();

   Setup_TIM4();

   Spi_Init();
   enableInterrupts();

   printf("CAN Initializtion about to happen\n\r");
   while(CAN_OK != Begin(CAN_500KBPS,MCP_16MHz))
   {
	   printf("CAN init Fail, retry.....\n\r");
	   delayMicroseconds(1000);
   }
   printf("CAN init OK\n");
   delayMicroseconds(100000);
    
	
   delayMicroseconds(500000);
   check = SendMsgBuf(0x08,0,0,8,stmp,true);	
   printf("check = %d\r\n",check);
   delayMicroseconds(500000);
   while(1) 
   {

   }


}
