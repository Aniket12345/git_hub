


#ifndef MCP2515_H
#define MCP2515_H

#include "mcp_can_dfs.h"

	
	byte ext_flg;		//identifier xxxID

	unsigned long can_id;		//can id
	byte rtr;		//rtr
//	byte SPICS;
	byte   mcpMode;                         // Current controller mode
	

	void Mcp2515_Reset(void);				//reset mcp2515

	byte Mcp2515_ReadRegister(const byte address);		//read mcp2515's register 

	void mcp2515_ReadRegisterS(const byte address, byte values[], const byte n);

	void Mcp2515_SetRegiter(const byte address, const byte value);		//set mcp2515's register

	void Mcp2515_SetRegisters(const byte address, const byte values[], const byte n);

	void Mcp2515_InitCANBuffers(void);

	void Mcp2515_modifyRegister(const byte address, const byte mask, const byte data);

	byte Mcp2515_ReadStatus(void);		//read mcp2515's status

	byte Mcp2515_SetCANCTRL_Mode(const byte newmode);		//set mode
	
	void SetSleepWakeup(byte enable);                               // Enable or disable the wake up interrupt (If disabled the MCP2515 will not be woken up by CAN bus activity, making it send only)
	
	byte Sleep();	// Put the MCP2515 in sleep mode

	byte Wake();	// Wake MCP2515 manually from sleep
	byte SetMode(byte opMode);                                      // Set operational mode
	byte GetMode();
/*				                                    // Get operational mode
	byte sendMsgBuf(unsigned long id, byte ext, byte rtrBit, byte len, const byte *buf, bool wait_sent=true);  // send buf

	byte Mcp2515_RequestNewMode(const byte newmode);	

	byte Mcp2515_ConfigRate(const byte canspeed,const byte clock);		//set baudrate

	byte Mcp2515_Init(const byte canspeed, const byte clock);		//mcp2515init

	void Mcp2515_Writeid(const byte mcp_addr, const byte ext, const unsigned long id);		//write can id

	void Mcp2515_ReadId(const byte mcp_addr, byte *ext, unsigned long *id);			//read can id

	void Mcp2515_WriteCANMsg(const byte buffer_sidh_addr, unsigned long id, byte ext, byte rtr, byte len, volatile const byte *buf);//write can msg

	void Mcp2515_ReadCANMsg(const byte buffer_load_addr, volatile unsigned long *id, volatile byte *ext, volatile byte *rtr,volatile byte *len, volatile byte *buf);	//read can msg

	void Mcp2515_StartTransmit(const byte mcp_addr);	//start transmit

	byte Mcp2515_GetNextFreeTXBuf(byte *txbuf_n);		//get next free txbuf

	byte Mcp2515_TXBufFree(byte *txbuf_n, byte iBuf);	//is buffer by index free

	//can operator function 
	
	byte SendMsg(unsigned long id,byte ext, byte rtrBit, byte len, const byte *buf, bool wait_sent = true);	//send message 

	MCP_CAN(byte _CS = 0);
	void Init_CS(byte _CS);		//define CS after construction before begin()
	void EnableTXInterrupt(bool enable = true);		//enable tx interrupt

	void ReserveTXBuffer(byte nTXBuf = 0) { nReservedTx = (nTXBuf < MCP_n_TXBUFFERS?nTXBuf:MCP_N_TXBUFFERS-1); }

	byte getLastTxBuffer() { return MCP_N_TXBUFFERS-1; } // read index of last tx buffer

	byte begin(byte speedset, const byte clockset = MCP_16MHz);     // init can
	byte init_Mask(byte num, byte ext, unsigned long ulData);       // init Masks
	byte init_Filt(byte num, byte ext, unsigned long ulData);       // init filters
	byte sendMsgBuf(unsigned long id, byte ext, byte len, const byte *buf, bool wait_sent=true);               // send buf
	byte readMsgBuf(byte *len, byte *buf);                          // read buf
	byte readMsgBufID(unsigned long *ID, byte *len, byte *buf);     // read buf with object ID
	byte checkReceive(void);                                        // if something received
	byte checkError(void);                                          // if something error
	unsigned long getCanId(void);                                   // get can id when receive
	byte isRemoteRequest(void);                                     // get RR flag when receive
	byte isExtendedFrame(void);                                     // did we recieve 29bit frame?

	byte readMsgBufID(byte status, volatile unsigned long *id, volatile byte *ext, volatile byte *rtr, volatile byte *len, volatile byte *buf); // read buf with object ID
	byte trySendMsgBuf(unsigned long id, byte ext, byte rtrBit, byte len, const byte *buf, byte iTxBuf=0xff);  // as sendMsgBuf, but does not have any wait for free buffer
	byte sendMsgBuf(byte status, unsigned long id, byte ext, byte rtrBit, byte len, volatile const byte *buf); // send message buf by using parsed buffer status
	inline byte trySendExtMsgBuf(unsigned long id, byte len, const byte *buf, byte iTxBuf=0xff) {  // as trySendMsgBuf, but set ext=1 and rtr=0
		return trySendMsgBuf(id,1,0,len,buf,iTxBuf);
	}
	inline byte sendExtMsgBuf(byte status, unsigned long id, byte len, volatile const byte *buf) { // as sendMsgBuf, but set ext=1 and rtr=0
		return sendMsgBuf(status,id,1,0,len,buf);
	}
	void clearBufferTransmitIfFlags(byte flags=0);                  // Clear transmit flags according to status
	byte readRxTxStatus(void);                                      // read has something send or received
	byte checkClearRxStatus(byte *status);                          // read and clear and return first found rx status bit
	byte checkClearTxStatus(byte *status, byte iTxBuf=0xff);        // read and clear and return first found or buffer specified tx status bit

	bool mcpPinMode(const byte pin, const byte mode);                  // switch supported pins between HiZ, interrupt, output or input
	bool mcpDigitalWrite(const byte pin, const byte mode);             // write HIGH or LOW to RX0BF/RX1BF
	byte mcpDigitalRead(const byte pin);                               // read HIGH or LOW from supported 
*/
#endif

/***********************************************************************************************************
  END FILE
***********************************************************************************************************/




