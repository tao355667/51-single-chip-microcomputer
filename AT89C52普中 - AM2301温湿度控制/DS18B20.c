#include <REGX52.H>//��׼ͷ�ļ�
#include "delay.h"//delay_ms()   unsigned charΪu8,
#include "LCD1602.h"//LCD1602ͷ�ļ�
#include "OneWire.h"//������1-wireЭ��

#define DS18B20_SKIP_ROM	0xCC
#define DS18B20_CONVERT_T	0x44
#define DS18B20_READ_SCRATCHPAD	0xBE

void DS18B20_ConvertT(void)//ת���¶�
{
	OneWire_Init();
	OneWire_SendByte(DS18B20_SKIP_ROM);
	OneWire_SendByte(DS18B20_CONVERT_T);
}

float DS18B20_ReadT(void)//��ȡ�¶�
{
	unsigned char TLSB,TMSB;
	int Temp;
	float T;
	OneWire_Init();
	OneWire_SendByte(DS18B20_SKIP_ROM);
	OneWire_SendByte(DS18B20_READ_SCRATCHPAD);
	TLSB=OneWire_ReceiveByte();
	TMSB=OneWire_ReceiveByte();
	Temp=(TMSB<<8)|TLSB;
	T=Temp/16.0;
	return T;
}
