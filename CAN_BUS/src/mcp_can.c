

#include "mcp_can.h"
#include "stm8_spi.h"

/*********************************************************************************************************
** Function name:           mcp2515_reset
** Descriptions:            reset the device
*********************************************************************************************************/
void  Mcp2515_Reset(void)
{
	MCP2515_SELECT();
	Spi_Write(MCP_RESET);
	MCP2515_UNSELECT();
	
}

/*********************************************************************************************************
** Function name:           mcp2515_readRegister
** Descriptions:            read register
*********************************************************************************************************/

byte  Mcp2515_ReadRegister(const byte address)
{
	byte ret;
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

void  Mcp2515_ReadRegisters(const byte address, byte values[], const byte n)
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

void  Mcp2515_SetRegister(const byte address, const byte value)
{

	MCP2515_SELECT();
	Spi_Write(MCP_WRITE);
	Spi_Write(address);
	Spi_Write(value);
	MCP2515_UNSELECT();
}

/*********************************************************************************************************
** Function name:           mcp2515_setRegisterS
** Descriptions:            set registerS
*********************************************************************************************************/

void  Mcp2515_SetRegisterS(const byte address, const byte values[], const byte n)
{
	byte i;
	MCP2515_SELECT();
	Spi_Write(MCP_WRITE);
	Spi_Write(address);

	for(i=0; i<n; i++)
	{
		Spi_Write(values[i]);
	}
	MCP2515_UNSELECT();
}

/*********************************************************************************************************
** Function name:           mcp2515_modifyRegister
** Descriptions:            set bit of one register
*********************************************************************************************************/

void  Mcp2515_ModifyRegister(const byte address, const byte mask, const byte data)
{
	 
	MCP2515_SELECT();
	Spi_Write(MCP_BITMOD);
	Spi_Write(address);
	Spi_Write(mask);
	Spi_Write(data);
	MCP2515_UNSELECT();
}

/*********************************************************************************************************
** Function name:           mcp2515_readStatus
** Descriptions:            read mcp2515's Status
*********************************************************************************************************/

byte  Mcp2515_ReadStatus(void)
{
	byte i;
	MCP2515_SELECT();
	Spi_Write(MCP_READ_STATUS);
	i = Spi_Read();
	MCP2515_UNSELECT();

	return i;
}

/*********************************************************************************************************
** Function name:           setSleepWakeup
** Descriptions:            Enable or disable the wake up interrupt (If disabled the MCP2515 will not be woken up by CAN bus activity)
*********************************************************************************************************/

void SetSleepWakeup(const byte enable)
{
	Mcp2515_ModifyRegister(MCP_CANINTE, MCP_WAKIF, enable ? MCP_WAKIF : 0);
}

/*********************************************************************************************************
** Function name:           sleep
** Descriptions:            Put mcp2515 in sleep mode to save power
*********************************************************************************************************/

byte Sleep()
{
	if(GetMode() != MODE_SLEEP)
		return Mcp2515_SetCANCTRL_Mode(MODE_SLEEP);
	else
		return CAN_OK;
}

/*********************************************************************************************************
** Function name:           wake
** Descriptions:            wake MCP2515 manually from sleep. It will come back in the mode it was before sleeping.
*********************************************************************************************************/

byte Wake()
{
	byte currMode = GetMode();
	if(currMode != mcpMode)
		return Mcp2515_SetCANCTRL_Mode(mcpMode);
	else 
		return CAN_OK;
}

/*********************************************************************************************************
** Function name:           setMode
** Descriptions:            Sets control mode
*********************************************************************************************************/

byte SetMode(const byte opMode)
{
	if(opMode != MODE_SLEEP)  // if going to sleep, the value stored in opMode is not changed so that we can return to it later
		mcpMode = opMode;
	return Mcp2515_SetCANCTRL_Mode(opMode);
}

/*********************************************************************************************************
** Function name:           getMode
** Descriptions:            Returns current control mode
*********************************************************************************************************/

byte GetMode()
{
	return Mcp2515_ReadRegister(MCP_CANSTAT) & MODE_MASK;
}


