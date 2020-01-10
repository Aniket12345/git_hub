

#include "mcp_can.h"

/*********************************************************************************************************
** Function name:           mcp2515_reset
** Descriptions:            reset the device
*********************************************************************************************************/
void MCP_CAN::Mcp2515_Reset(void)
{
	MCP2515_SELECT();
	Spi_Write(MCP_RESET);
	MCP2515_UNSELECT();
	
}

/*********************************************************************************************************
** Function name:           mcp2515_readRegister
** Descriptions:            read register
*********************************************************************************************************/

byte MCP_CAN::Mcp2515_ReadRegister(const byte address)
{
	byte ret;;
	MCP2515_SELECT();
	Spi_Write(MCP_READ);
	Spi_Write(address);
	ret = Spi_Read();
	MCP2515_UNSELECT();

	return ret;
}

/*********************************************************************************************************
** Function name:           mcp2515_readRegisterS
** Descriptions:            read registerS
*********************************************************************************************************/

void MCP_CAN::Mcp2515_ReadRegisters(const byte address, byte values[], const byte n)
{
	byte i;
	MCP2515_SELECT();
	Spi_Write(MCP_READ);
	Spi_Write(address);

	// mcp2515 has auto-increment of addres-pointer
	for(i=0;i<n && i<CAN_MAX_CHAR_IN_MESSAGE; i++)
	{	
		values[i] = Spi_Read();
	}

	MCP2515_SELECT();
}

/*********************************************************************************************************
** Function name:           mcp2515_setRegister
** Descriptions:            set register
*********************************************************************************************************/

void MCP_CAN::Mcp2515_SetRegister(const byte address, const byte value)
{

	MCP2515_SELECT();
