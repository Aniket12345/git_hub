

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

/*********************************************************************************************************
** Function name:           mcp2515_setCANCTRL_Mode
** Descriptions:            set control mode
*********************************************************************************************************/

byte Mcp2515_SetCANCTRL_Mode(const byte newmode)
{
	// If the chip is asleep and we want to change mode then a manual wake needs to be done
	// This is done by setting the wake up interrupt flag
	// This undocumented trick was found at https://github.com/mkleemann/can/blob/master/can_sleep_mcp2515.c
	
	if((getMode()) == MODE_SLEEP && newmode != MODE_SLEEP)
	{
		// Make sure wake interrupt is enable
		byte wakeIntEnable = (Mcp2515_ReadRegister(MCP_CANINTE) & MCP_WAKIF);
		if(!wakeIntEnable)
			Mcp2515_ModifyRegister(MCP_CANINTE, MCP_WAKIF, MCP_WAKIF);

		//Set wake flag (this does the actual waking up)
		Mcp2515_ModifyRegister(MCP_CANINTE, MCP_WAKIF, MCP_WAKIF);
		
		// Wait for the chip to exit SLEEP and enter LISTENONLY mode.

		// If the chip is not connected to a CAN bus (or the bus has no other powered nodes) it will sometimes trigger the wake interrupt as soon
		// as it's put to sleep, but it will stay in SLEEP mode instead of automatically switching to LISTENONLY mode.
		// In this situation the mode needs to be manually set to LISTENONLY.

		if(Mcp2515_RequestNewMode(MODE_LESTENONLY) != MCP2515_OK)
			return MCP2515_FAIL;

		// Turn wake interrupt back off if it was originally off
		if(!wakeIntEnable)
			Mcp2515_ModifyRegister(MCP_CANINTE, MCP_WAKIF, 0);
	}

	// clear wake flag
	Mcp2515_ModifyRegister(MCP_CANINTE, MCP_WAKIF, 0);

	return Mcp2515_RequestNewMode(newmode);
}

/*********************************************************************************************************
** Function name:           mcp2515_requestNewMode
** Descriptions:            Set control mode
*********************************************************************************************************/

byte Mcp2515_RequestNewMode(const byte newmode)
{
	unsigned long startTime = millis();

	// Spam new mode request and wait for the operation to complete
	while(1)
	{
		// Request new mode
		// This is inside the loop as sometimes requesting the new mode once doesn't work (usually when attempting to sleep)
		Mcp2515_ModifyRegister(MCP_CANCTRL, MODE_MASK, newmode);
		
		byte statReg = Mcp2515_ReadRegister(MCP_CANSTAT);
		if((statReg & MODE_MASK) == newmode) // We're now in the new mode
			return MCP2515_OK;
		else if((millis() - startTime) > 200) // Wait no more than 200ms for the operation to complete
			return MCP2515_FAIL;
	}
}

/*********************************************************************************************************
** Function name:           mcp2515_configRate
** Descriptions:            set baudrate
*********************************************************************************************************/

byte Mcp2515_ConfigRate(const byte canSpeed, const byte clock)
{
  byte set, cfg1, cfg2, cfg3;
  set = 1;
  switch (clock)
  {
    case (MCP_16MHz) :
      switch (canSpeed)
      {
        case (CAN_5KBPS):
          cfg1 = MCP_16MHz_5kBPS_CFG1;
          cfg2 = MCP_16MHz_5kBPS_CFG2;
          cfg3 = MCP_16MHz_5kBPS_CFG3;
          break;

        case (CAN_10KBPS):
          cfg1 = MCP_16MHz_10kBPS_CFG1;
          cfg2 = MCP_16MHz_10kBPS_CFG2;
          cfg3 = MCP_16MHz_10kBPS_CFG3;
          break;

        case (CAN_20KBPS):
          cfg1 = MCP_16MHz_20kBPS_CFG1;
          cfg2 = MCP_16MHz_20kBPS_CFG2;
          cfg3 = MCP_16MHz_20kBPS_CFG3;
          break;

        case (CAN_25KBPS):
          cfg1 = MCP_16MHz_25kBPS_CFG1;
          cfg2 = MCP_16MHz_25kBPS_CFG2;
          cfg3 = MCP_16MHz_25kBPS_CFG3;
          break;

        case (CAN_31K25BPS):
          cfg1 = MCP_16MHz_31k25BPS_CFG1;
          cfg2 = MCP_16MHz_31k25BPS_CFG2;
          cfg3 = MCP_16MHz_31k25BPS_CFG3;
          break;

        case (CAN_33KBPS):
          cfg1 = MCP_16MHz_33kBPS_CFG1;
          cfg2 = MCP_16MHz_33kBPS_CFG2;
          cfg3 = MCP_16MHz_33kBPS_CFG3;
          break;

        case (CAN_40KBPS):
          cfg1 = MCP_16MHz_40kBPS_CFG1;
          cfg2 = MCP_16MHz_40kBPS_CFG2;
          cfg3 = MCP_16MHz_40kBPS_CFG3;
          break;

        case (CAN_50KBPS):
          cfg1 = MCP_16MHz_50kBPS_CFG1;
          cfg2 = MCP_16MHz_50kBPS_CFG2;
          cfg3 = MCP_16MHz_50kBPS_CFG3;
          break;

        case (CAN_80KBPS):
          cfg1 = MCP_16MHz_80kBPS_CFG1;
          cfg2 = MCP_16MHz_80kBPS_CFG2;
          cfg3 = MCP_16MHz_80kBPS_CFG3;
          break;

        case (CAN_83K3BPS):
          cfg1 = MCP_16MHz_83k3BPS_CFG1;
          cfg2 = MCP_16MHz_83k3BPS_CFG2;
          cfg3 = MCP_16MHz_83k3BPS_CFG3;
          break;

        case (CAN_95KBPS):
          cfg1 = MCP_16MHz_95kBPS_CFG1;
          cfg2 = MCP_16MHz_95kBPS_CFG2;
          cfg3 = MCP_16MHz_95kBPS_CFG3;
          break;

        case (CAN_100KBPS):
          cfg1 = MCP_16MHz_100kBPS_CFG1;
          cfg2 = MCP_16MHz_100kBPS_CFG2;
          cfg3 = MCP_16MHz_100kBPS_CFG3;
          break;

        case (CAN_125KBPS):
          cfg1 = MCP_16MHz_125kBPS_CFG1;
          cfg2 = MCP_16MHz_125kBPS_CFG2;
          cfg3 = MCP_16MHz_125kBPS_CFG3;
          break;

        case (CAN_200KBPS):
          cfg1 = MCP_16MHz_200kBPS_CFG1;
          cfg2 = MCP_16MHz_200kBPS_CFG2;
          cfg3 = MCP_16MHz_200kBPS_CFG3;
          break;

        case (CAN_250KBPS):
          cfg1 = MCP_16MHz_250kBPS_CFG1;
          cfg2 = MCP_16MHz_250kBPS_CFG2;
          cfg3 = MCP_16MHz_250kBPS_CFG3;
          break;

        case (CAN_500KBPS):
          cfg1 = MCP_16MHz_500kBPS_CFG1;
          cfg2 = MCP_16MHz_500kBPS_CFG2;
          cfg3 = MCP_16MHz_500kBPS_CFG3;
          break;

        case (CAN_666KBPS):
          cfg1 = MCP_16MHz_666kBPS_CFG1;
          cfg2 = MCP_16MHz_666kBPS_CFG2;
          cfg3 = MCP_16MHz_666kBPS_CFG3;
          break;

        case (CAN_1000KBPS):
          cfg1 = MCP_16MHz_1000kBPS_CFG1;
          cfg2 = MCP_16MHz_1000kBPS_CFG2;
          cfg3 = MCP_16MHz_1000kBPS_CFG3;
          break;

        default:
          set = 0;
          break;
      }
      break;

    case (MCP_8MHz) :
      switch (canSpeed)
      {
        case (CAN_5KBPS) :
          cfg1 = MCP_8MHz_5kBPS_CFG1;
          cfg2 = MCP_8MHz_5kBPS_CFG2;
          cfg3 = MCP_8MHz_5kBPS_CFG3;
          break;

        case (CAN_10KBPS) :
          cfg1 = MCP_8MHz_10kBPS_CFG1;
          cfg2 = MCP_8MHz_10kBPS_CFG2;
          cfg3 = MCP_8MHz_10kBPS_CFG3;
          break;

        case (CAN_20KBPS) :
          cfg1 = MCP_8MHz_20kBPS_CFG1;
          cfg2 = MCP_8MHz_20kBPS_CFG2;
          cfg3 = MCP_8MHz_20kBPS_CFG3;
          break;

        case (CAN_31K25BPS) :
          cfg1 = MCP_8MHz_31k25BPS_CFG1;
          cfg2 = MCP_8MHz_31k25BPS_CFG2;
          cfg3 = MCP_8MHz_31k25BPS_CFG3;
          break;

        case (CAN_40KBPS) :
          cfg1 = MCP_8MHz_40kBPS_CFG1;
          cfg2 = MCP_8MHz_40kBPS_CFG2;
          cfg3 = MCP_8MHz_40kBPS_CFG3;
          break;

        case (CAN_50KBPS) :
          cfg1 = MCP_8MHz_50kBPS_CFG1;
          cfg2 = MCP_8MHz_50kBPS_CFG2;
          cfg3 = MCP_8MHz_50kBPS_CFG3;
          break;

        case (CAN_80KBPS) :
          cfg1 = MCP_8MHz_80kBPS_CFG1;
          cfg2 = MCP_8MHz_80kBPS_CFG2;
          cfg3 = MCP_8MHz_80kBPS_CFG3;
          break;

        case (CAN_100KBPS) :
          cfg1 = MCP_8MHz_100kBPS_CFG1;
          cfg2 = MCP_8MHz_100kBPS_CFG2;
          cfg3 = MCP_8MHz_100kBPS_CFG3;
          break;

        case (CAN_125KBPS) :
          cfg1 = MCP_8MHz_125kBPS_CFG1;
          cfg2 = MCP_8MHz_125kBPS_CFG2;
          cfg3 = MCP_8MHz_125kBPS_CFG3;
          break;

        case (CAN_200KBPS) :
          cfg1 = MCP_8MHz_200kBPS_CFG1;
          cfg2 = MCP_8MHz_200kBPS_CFG2;
          cfg3 = MCP_8MHz_200kBPS_CFG3;
          break;

        case (CAN_250KBPS) :
          cfg1 = MCP_8MHz_250kBPS_CFG1;
          cfg2 = MCP_8MHz_250kBPS_CFG2;
          cfg3 = MCP_8MHz_250kBPS_CFG3;
          break;

        case (CAN_500KBPS) :
          cfg1 = MCP_8MHz_500kBPS_CFG1;
          cfg2 = MCP_8MHz_500kBPS_CFG2;
          cfg3 = MCP_8MHz_500kBPS_CFG3;
          break;

        case (CAN_1000KBPS) :
          cfg1 = MCP_8MHz_1000kBPS_CFG1;
          cfg2 = MCP_8MHz_1000kBPS_CFG2;
          cfg3 = MCP_8MHz_1000kBPS_CFG3;
          break;

        default:
          set = 0;
          break;
      }
      break;

    default:
      set = 0;
      break;
  }

  if (set) {
    mcp2515_setRegister(MCP_CNF1, cfg1);
    mcp2515_setRegister(MCP_CNF2, cfg2);
    mcp2515_setRegister(MCP_CNF3, cfg3);
    return MCP2515_OK;
  }
  else {
    return MCP2515_FAIL;
  }
}

/*********************************************************************************************************
** Function name:           mcp2515_initCANBuffers
** Descriptions:            init canbuffers
*********************************************************************************************************/

void Mcp2515_InitCANBuffers(void)
{
    byte i, a1, a2, a3;

    a1 = MCP_TXB0CTRL;
    a2 = MCP_TXB1CTRL;
    a3 = MCP_TXB2CTRL;
    for (i = 0; i < 14; i++)                         // in-buffer loop
    {
      Mcp2515_SetRegister(a1, 0);
      Mcp2515_SetRegister(a2, 0);
      Mcp2515_SetRegister(a3, 0);
      a1++;
      a2++;
      a3++;
    }
    Mcp2515_SetRegister(MCP_RXB0CTRL, 0);
    Mcp2515_SetRegister(MCP_RXB1CTRL, 0);
}

/*********************************************************************************************************
** Function name:           mcp2515_init
** Descriptions:            init the device
*********************************************************************************************************/

byte Mcp2515_Init(const byte canSpeed, const byte clock)
{

    byte res;

    Mcp2515_Reset();

    res = Mcp2515_SetCANCTRL_Mode(MODE_CONFIG);
    if (res > 0)
    {
#if DEBUG_EN
	Serial.print("Enter setting mode fail\r\n");
#else
	delay(10);
#endif
	return res;
    }
#if DEBUG_EN
    Serial.print("Enter setting mode success \r\n");
#else
    delay(10);
#endif

    // set boadrate
    if (Mcp2515_ConfigRate(canSpeed, clock))
    {
#if DEBUG_EN
	Serial.print("set rate fall!!\r\n");
#else
	delay(10);
#endif
	return res;
    }
#if DEBUG_EN
    Serial.print("set rate success!!\r\n");
#else
    delay(10);
#endif
    
    if ( res == MCP2515_OK ) {

      // init canbuffers
      Mcp2515_InitCANBuffers();

      // interrupt mode
      Mcp2515_SetRegister(MCP_CANINTE, MCP_RX0IF | MCP_RX1IF);

#if (DEBUG_RXANY==1)
      // enable both receive-buffers to receive any message and enable rollover
      Mcp2515_ModifyRegister(MCP_RXB0CTRL,
                             MCP_RXB_RX_MASK | MCP_RXB_BUKT_MASK,
                             MCP_RXB_RX_ANY | MCP_RXB_BUKT_MASK);
      Mcp2515_ModifyRegister(MCP_RXB1CTRL, MCP_RXB_RX_MASK,
                             MCP_RXB_RX_ANY);
#else
      // enable both receive-buffers to receive messages with std. and ext. identifiers and enable rollover
      Mcp2515_ModifyRegister(MCP_RXB0CTRL,
                             MCP_RXB_RX_MASK | MCP_RXB_BUKT_MASK,
                             MCP_RXB_RX_STDEXT | MCP_RXB_BUKT_MASK);
      Mcp2515_ModifyRegister(MCP_RXB1CTRL, MCP_RXB_RX_MASK,
                             MCP_RXB_RX_STDEXT);
#endif
      // enter normal mode
      res = SetMode(MODE_NORMAL);
      if (res)
      {
#if DEBUG_EN
        Serial.print("Enter Normal Mode Fail!!\r\n");
#else
        delay(10);
#endif
        return res;
      }


#if DEBUG_EN
      Serial.print("Enter Normal Mode Success!!\r\n");
#else
      delay(10);
#endif

    }
    return res;

}









