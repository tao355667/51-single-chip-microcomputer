#include <REGX52.H>//标准头文件
#include "delay.h"//delay_ms()   unsigned char为u8,
#include "LCD1602.h"//LCD1602头文件
#include "OneWire.h"//单总线1-wire协议

#define DS18B20_SKIP_ROM	0xCC
#define DS18B20_CONVERT_T	0x44
#define DS18B20_READ_SCRATCHPAD	0xBE

void DS18B20_ConvertT(void)//转换温度
{
	OneWire_Init();
	OneWire_SendByte(DS18B20_SKIP_ROM);
	OneWire_SendByte(DS18B20_CONVERT_T);
}

float DS18B20_ReadT(void)//读取温度
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
