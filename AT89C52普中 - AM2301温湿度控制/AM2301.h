#ifndef __AM2301_H
#define __AM2301_H

unsigned char AM2301_Start(void);
//void OneWire_SendBit(unsigned char Bit);
//void OneWire_SendByte(unsigned char Byte);
unsigned char AM2301_ReceiveBit(void);
unsigned char AM2301_ReceiveByte(void);


#endif
