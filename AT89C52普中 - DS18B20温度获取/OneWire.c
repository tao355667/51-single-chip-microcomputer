#include <REGX52.H>//标准头文件
#include "delay.h"//delay_ms()   unsigned char为u8,
#include "LCD1602.h"//LCD1602头文件
#include <INTRINS.H>//要用_nop_();
//晶振11.0592MHz
sbit OneWire_DQ=P3^7;

unsigned char OneWire_Init(void)
{
	unsigned char i;
	unsigned char AckBit;
	OneWire_DQ=1;
	OneWire_DQ=0;
	
	_nop_();i = 247;while (--i);//延时500us
	OneWire_DQ=1;//释放
	_nop_();i = 29;while (--i);//延时70us
	AckBit=OneWire_DQ;//读取从机的响应值（低电平）
	_nop_();i = 247;while (--i);//延时500us
	
	return AckBit;
}

void OneWire_SendBit(unsigned char Bit)
{
	unsigned char i;
	OneWire_DQ=0;
	i = 4;while (--i);//延时10us
	OneWire_DQ=Bit;
	_nop_();i = 22;while (--i);//延时50us
	OneWire_DQ=1;
	
}

unsigned char OneWire_ReceiveBit(void)
{
	unsigned char i;
	unsigned char Bit;
	OneWire_DQ=1;
	OneWire_DQ=0;
	i = 2;while (--i);//延时5us
	OneWire_DQ=1;
	i = 2;while (--i);//延时5us
	Bit=OneWire_DQ;
	_nop_();i = 22;while (--i);//延时50us
	
	return Bit;
}

void OneWire_SendByte(unsigned char Byte)
{
	unsigned char i;
	
	for(i=0;i<8;i++){
		OneWire_SendBit(Byte&0x01<<i);
	}
	
}

unsigned char OneWire_ReceiveByte(void)
{
	unsigned char i;
	unsigned char Byte=0x00;
	for(i=0;i<8;i++){
		if(OneWire_ReceiveBit()){Byte|=(0x01<<i);}
	}
	return Byte;
}