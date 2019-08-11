#include <stdint.h>
#include "stm8.h"
#include "stm8_clk.h"
#include "stm8_uart.h"
#include "stm8_tim2.h"
#include "stm8_spi.h"

void main()
{
	disableInterrupts();

	/* Set clock to full speed (16 Mhz) */
	Initialise_System_Clock();

//	Initialise_Uart();
	
	Spi_Init();

	enableInterrupts();
	while(1) 
	{	
		Chip_Select();
		Spi_Write(0x10);
		Spi_Write(0x11);
		Spi_Write(0x12);
		Spi_Write(0x13);
		Spi_Write(0x14);
		Chip_Deselect();
	}
}
