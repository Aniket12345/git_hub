

#include "mcp_can.h"
#include "stm8_spi.h"

/*********************************************************************************************************
** Function name:           txSidhToTxLoad
** Descriptions:            return tx load command according to tx buffer sidh register
*********************************************************************************************************/

byte txSidhToRTS(byte sidh) {
  switch (sidh) {
    case MCP_TXB0SIDH: 
	    return MCP_RTS_TX0;
    break;
    case MCP_TXB1SIDH: 
    	return MCP_RTS_TX1;
    break;
    case MCP_TXB2SIDH: 
    	return MCP_RTS_TX2;
    break;
  }
  return 0;
}

/*********************************************************************************************************
** Function name:           txCtrlReg
** Descriptions:            return tx ctrl reg according to tx buffer index.
**                          According to my tests this is faster and saves memory compared using vector
*********************************************************************************************************/

byte txCtrlReg(byte i) {
  switch (i) {
    case 0: 
	return MCP_TXB0CTRL;
    break;
    case 1: 
    	return MCP_TXB1CTRL;
    break;
    case 2: 
	return MCP_TXB2CTRL;
    break;
  }
  return MCP_TXB2CTRL;
}

/*********************************************************************************************************
** Function name:           txSidhToTxLoad
** Descriptions:            return tx load command according to tx buffer sidh register
*********************************************************************************************************/

byte txSidhToTxLoad(byte sidh) {
  switch (sidh) {
    case MCP_TXB0SIDH: 
	    return MCP_LOAD_TX0;
    break;
    case MCP_TXB1SIDH: 
    	return MCP_LOAD_TX1;
    break;
    case MCP_TXB2SIDH: 
    	return MCP_LOAD_TX2;
    break;
  }
  return 0;
}

/*********************************************************************************************************
** Function name:           txStatusPendingFlag
** Descriptions:            return buffer tx pending flag on status
*********************************************************************************************************/

byte txStatusPendingFlag(byte i) {
  switch (i) {
    case 0: return MCP_STAT_TX0_PENDING;
    break;
    case 1: return MCP_STAT_TX1_PENDING;
    break;
    case 2: return MCP_STAT_TX2_PENDING;
    break;
  }
  return 0xff;
}

/*********************************************************************************************************
** Function name:           txIfFlag
** Descriptions:            return tx interrupt flag
*********************************************************************************************************/

byte txIfFlag(byte i) {
  switch (i) {
    case 0: return MCP_TX0IF;
    break;
    case 1: return MCP_TX1IF;
    break;
    case 2: return MCP_TX2IF;
    break;
  }
  return 0;
}

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
** Function name:           begin
** Descriptions:            init can and set speed
*********************************************************************************************************/
byte Begin(byte speedset, const byte clockset)
{
    Spi_Init();
    byte res = Mcp2515_Init(speedset, clockset);
	
	return ((res == MCP2515_OK) ? CAN_OK : CAN_FAILINIT);
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
	
	if((GetMode()) == MODE_SLEEP && newmode != MODE_SLEEP)
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

		if(Mcp2515_RequestNewMode(MODE_LISTENONLY) != MCP2515_OK)
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
    Mcp2515_SetRegister(MCP_CNF1, cfg1);
    Mcp2515_SetRegister(MCP_CNF2, cfg2);
    Mcp2515_SetRegister(MCP_CNF3, cfg3);
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
//	Serial.print("Enter setting mode fail\r\n");
#else
	delay(10);
#endif
	return res;
    }
#if DEBUG_EN
//    Serial.print("Enter setting mode success \r\n");
#else
    delay(10);
#endif

    // set boadrate
    if (Mcp2515_ConfigRate(canSpeed, clock))
    {
#if DEBUG_EN
//	Serial.print("set rate fall!!\r\n");
#else
	delay(10);
#endif
	return res;
    }
#if DEBUG_EN
//    Serial.print("set rate success!!\r\n");
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
//        Serial.print("Enter Normal Mode Fail!!\r\n");
#else
        delay(10);
#endif
        return res;
      }


#if DEBUG_EN
//      Serial.print("Enter Normal Mode Success!!\r\n");
#else
      delay(10);
#endif

    }
    return res;

}

/*********************************************************************************************************
** Function name:           mcp2515_id_to_buf
** Descriptions:            configure tbufdata[4] from id and ext
*********************************************************************************************************/

void Mcp2515_Id_To_Buf(const byte ext, const unsigned long id, byte *tbufdata)
{
    uint16_t canid;
    canid = (uint16_t)(id & 0x0FFFF);

    if ( ext == 1)
    {
	    tbufdata[MCP_EID0] = (byte) (canid & 0xFF);
	    tbufdata[MCP_EID8] = (byte) (canid >> 8);
	    canid = (uint16_t)(id >> 16);
	    tbufdata[MCP_SIDL] = (byte) (canid & 0x03);
	    tbufdata[MCP_SIDL] += (byte) ((canid & 0x1C) << 3);
	    tbufdata[MCP_SIDL] |= MCP_TXB_EXIDE_M;
	    tbufdata[MCP_SIDH] = (byte) (canid >> 5 );
    }
    else
    {
	    tbufdata[MCP_SIDH] = (byte) (canid >> 3 );
	    tbufdata[MCP_SIDL] = (byte) ((canid & 0x07 ) << 5);
	    tbufdata[MCP_EID0] = 0;
	    tbufdata[MCP_EID8] = 0;
    }
}

/*********************************************************************************************************
** Function name:           mcp2515_write_id
** Descriptions:            write can id
*********************************************************************************************************/
void Mcp2515_Write_Id(const byte mcp_addr, const byte ext, const unsigned long id)
{
    byte tbufdata[4];

    Mcp2515_Id_To_Buf(ext,id,tbufdata);
    Mcp2515_SetRegisterS(mcp_addr, tbufdata, 4);
}

/*********************************************************************************************************
** Function name:           mcp2515_read_id
** Descriptions:            read can id
*********************************************************************************************************/

void Mcp2515_Read_Id(const byte mcp_addr, byte* ext, unsigned long* id)
{
    byte tbufdata[4];

    *ext    = 0;
    *id     = 0;

    Mcp2515_ReadRegisterS(mcp_addr, tbufdata, 4);

    *id = (tbufdata[MCP_SIDH] << 3) + (tbufdata[MCP_SIDL] >> 5);

    if ( (tbufdata[MCP_SIDL] & MCP_TXB_EXIDE_M) ==  MCP_TXB_EXIDE_M )
    {
      // extended id
      *id = (*id << 2) + (tbufdata[MCP_SIDL] & 0x03);
      *id = (*id << 8) + tbufdata[MCP_EID8];
      *id = (*id << 8) + tbufdata[MCP_EID0];
      *ext = 1;
    }
}

/*********************************************************************************************************
** Function name:           mcp2515_write_canMsg
** Descriptions:            write msg
**                          Note! There is no check for right address!
*********************************************************************************************************/
void Mcp2515_Write_CANMsg(const byte buffer_sidh_addr, unsigned long id, byte ext, byte rtrBit, byte len, volatile const byte *buf)
{
  byte load_addr=txSidhToTxLoad(buffer_sidh_addr);

  byte tbufdata[4];
  byte dlc = len | ( rtrBit ? MCP_RTR_MASK : 0 ) ;
  byte i;

  Mcp2515_Id_To_Buf(ext,id,tbufdata);

  MCP2515_SELECT();
//  Spi_Read(load_addr);

  for (i = 0; i < 4; i++) 
	  Spi_Write(tbufdata[i]);
  
  Spi_Write(dlc);

  for (i = 0; i < len && i<CAN_MAX_CHAR_IN_MESSAGE; i++) 
	  Spi_Write(buf[i]);

  MCP2515_UNSELECT();

  Mcp2515_Start_Transmit( buffer_sidh_addr );

}

/*********************************************************************************************************
** Function name:           mcp2515_read_canMsg
** Descriptions:            read message
*********************************************************************************************************/

void Mcp2515_ReadCANMsg( const byte buffer_load_addr, volatile unsigned long *id, volatile byte *ext, volatile byte *rtrBit, volatile byte *len, volatile byte *buf)        /* read can msg                 */
{
  buffer_load_addr;
  byte tbufdata[4];
  byte i;

  MCP2515_SELECT();
//  Spi_Read(buffer_load_addr);

  // mcp2515 has auto-increment of address-pointer
  for (i = 0; i < 4; i++) 
	  tbufdata[i] = Spi_Read();

  *id = (tbufdata[MCP_SIDH] << 3) + (tbufdata[MCP_SIDL] >> 5);
  *ext = 0;
  if ( (tbufdata[MCP_SIDL] & MCP_TXB_EXIDE_M) ==  MCP_TXB_EXIDE_M )
  {
    /* extended id                  */
    *id = (*id << 2) + (tbufdata[MCP_SIDL] & 0x03);
    *id = (*id << 8) + tbufdata[MCP_EID8];
    *id = (*id << 8) + tbufdata[MCP_EID0];
    *ext = 1;
  }

  byte pMsgSize = Spi_Read();
  *len = pMsgSize & MCP_DLC_MASK;
  *rtrBit = (pMsgSize & MCP_RTR_MASK) ? 1 : 0;
  
  for (i = 0; i < *len && i<CAN_MAX_CHAR_IN_MESSAGE; i++) 
  {
      buf[i] = Spi_Read();
  }

  MCP2515_UNSELECT();
}

/*********************************************************************************************************
** Function name:           mcp2515_start_transmit
** Descriptions:            Start message transmit on mcp2515
*********************************************************************************************************/
void Mcp2515_Start_Transmit(const byte mcp_addr)              // start transmit
{
  mcp_addr;
  MCP2515_SELECT();
//  Spi_Read(txSidhToRTS(mcp_addr));
  MCP2515_UNSELECT();
}

/*********************************************************************************************************
** Function name:           mcp2515_isTXBufFree
** Descriptions:            Test is tx buffer free for transmitting
*********************************************************************************************************/

byte Mcp2515_IsTXBufFree(byte *txbuf_n, byte iBuf)           /* get Next free txbuf          */
{
  *txbuf_n = 0x00;

  if ( iBuf>=MCP_N_TXBUFFERS || (Mcp2515_ReadStatus() & txStatusPendingFlag(iBuf))!=0 ) 
	return MCP_ALLTXBUSY;

  *txbuf_n = txCtrlReg(iBuf) + 1;                                /* return SIDH-address of Buffer */
  Mcp2515_ModifyRegister(MCP_CANINTF, txIfFlag(iBuf), 0);

  return MCP2515_OK;
}

/*********************************************************************************************************
** Function name:           mcp2515_getNextFreeTXBuf
** Descriptions:            finds next free tx buffer for sending. Return MCP_ALLTXBUSY, if there is none.
*********************************************************************************************************/

byte Mcp2515_GetNextFreeTXBuf(byte *txbuf_n)                 // get Next free txbuf
{
    byte status=Mcp2515_ReadStatus() & MCP_STAT_TX_PENDING_MASK;
    byte i;

    *txbuf_n = 0x00;

    if ( status==MCP_STAT_TX_PENDING_MASK ) 
	    return MCP_ALLTXBUSY; // All buffers are pending

    // check all 3 TX-Buffers except reserved
    for (i = 0; i < MCP_N_TXBUFFERS-nReservedTx; i++)
    {
      if ( (status & txStatusPendingFlag(i) ) == 0 ) {
        *txbuf_n = txCtrlReg(i) + 1;                                   // return SIDH-address of Buffer
        Mcp2515_ModifyRegister(MCP_CANINTF, txIfFlag(i), 0);
        return MCP2515_OK;                                                 // ! function exit
      }
    }

    return MCP_ALLTXBUSY;
}




