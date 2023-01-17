#ifndef __ONEWIRE_H
#define __ONEWIRE_H

unsigned char OneWire_Init(void);
void OneWire_SendBit(unsigned char Bit);
void OneWire_SendByte(unsigned char Byte);
unsigned char OneWire_ReceiveBit(void);
unsigned char OneWire_ReceiveByte(void);
unsigned char OneWire_Receive2Byte(void);

#endif
