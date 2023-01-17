#include <REGX52.H>//标准头文件
#include "delay.h"//delay_ms()   unsigned char为u8,
#include "LCD1602.h"//LCD1602头文件
#include <INTRINS.H>//要用_nop_();
//晶振11.0592MHz
//AM2301
sbit OneWire_DATA=P1^3;

unsigned char OneWire_Init(void)
{
	unsigned char i,j;
	unsigned char AckBit,AckBit1,AckBit2;
//	OneWire_DATA=1;
	//MCU发送开始信号
	OneWire_DATA=0;
	delay_ms(1);
	OneWire_DATA=1;//释放
	i = 9;while (--i);//延时20us
	//传感器响应
	i = 18;while (--i);//延时40us
	AckBit1=OneWire_DATA;//读取从机的响应值（低电平）
	_nop_();i = 36;while (--i);//延时80us
	AckBit2=OneWire_DATA;//读取从机的响应值（高电平）
	i = 18;while (--i);//延时40us
	OneWire_DATA=1;
	AckBit=(!AckBit1)&AckBit2;//两次都接收到从机响应信号则为1，否则为0
	
	return AckBit;
}

unsigned char OneWire_ReceiveBit(void)
{
	unsigned char i;
	unsigned char Bit;
	OneWire_DATA=1;
	while(OneWire_DATA);
	_nop_();i = 22;while (--i);//延时50us
	_nop_();i = 22;while (--i);//延时50us
	Bit=OneWire_DATA;
	
	
	OneWire_DATA=1;
	OneWire_DATA=0;
	i = 2;while (--i);//延时5us
	OneWire_DATA=1;
	i = 2;while (--i);//延时5us
	Bit=OneWire_DATA;
	_nop_();i = 22;while (--i);//延时50us
	
	return Bit;
}



unsigned char OneWire_ReceiveByte(void)
{
	unsigned char i;
	unsigned char Byte=0x00;
	
	for(i=0;i<8;i++){
		if(OneWire_ReceiveBit()){Byte|=(0x80>>i);}
	}
	return Byte;
}