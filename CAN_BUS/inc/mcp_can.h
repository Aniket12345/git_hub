/**
  *********************************************************************
  * @file    mcp_can.h
  * @author  Aniket Fondekaar
  * @date    23 July 2019
  * @brief   This file contains functions declaration for the mcp2515
  *********************************************************************
**/

#ifndef MCP2515_H
#define MCP2515_H

#include "mcp_can_dfs.h"
#include "stdbool.h"
#include "stm8.h"

	void delayMicroseconds(unsigned long count);	
	byte txSidhToRTS(byte sidh);

	byte txCtrlReg(byte i);
        
        byte Begin(byte speedset, byte clockset);     // init can

	byte Mcp2515_Init(const byte canSpeed, const byte clock);		//mcp2515init

	void Mcp2515_Reset(void);				//reset mcp2515

	byte Mcp2515_SetCANCTRL_Mode(const byte newmode);		//set mode

	byte GetMode();							// Get operational mode

	byte Mcp2515_ReadRegister(const byte address);		//read mcp2515's register 

	void Mcp2515_ModifyRegister(const byte address, const byte mask, const byte data);

	byte Mcp2515_RequestNewMode(const byte newmode);	

	byte Mcp2515_ConfigRate(const byte canspeed,const byte clock);		//set baudrate

	void Mcp2515_InitCANBuffers(void);

	void Mcp2515_SetRegiter(const byte address, const byte value);		//set mcp2515's register

        void Mcp2515_SetRegisters(const byte address, const byte values[], const byte n);

	byte Mcp2515_ReadStatus(void);		//read mcp2515's status
    
	byte SendMsgBuf(unsigned long id, byte ext,byte rtrBit, byte len, const byte *buf, bool wait_sent);               // send buf
    
	byte SendMsg(unsigned long id, byte ext, byte rtrBit, byte len, const byte *buf, bool wait_sent); // send message
        
        byte Mcp2515_GetNextFreeTXBuf(byte *txbuf_n);		//get next free txbuf

	void Mcp2515_Write_CANMsg(const byte buffer_sidh_addr, unsigned long id, byte ext, byte rtr, byte len, volatile const byte *buf);//write can msg

	void Mcp2515_Start_Transmit(const byte mcp_addr);	//start transmit
#endif

/***********************************************************************************************************
  END FILE
***********************************************************************************************************/




