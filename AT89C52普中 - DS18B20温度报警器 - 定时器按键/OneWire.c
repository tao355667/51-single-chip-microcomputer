#include <REGX52.H>//��׼ͷ�ļ�
#include "delay.h"//delay_ms()   unsigned charΪu8,
#include "LCD1602.h"//LCD1602ͷ�ļ�
#include <INTRINS.H>//Ҫ��_nop_();
//����11.0592MHz
sbit OneWire_DQ=P3^7;

unsigned char OneWire_Init(void)
{
	unsigned char i;
	unsigned char AckBit;
	OneWire_DQ=1;
	OneWire_DQ=0;
	
	_nop_();i = 247;while (--i);//��ʱ500us
	OneWire_DQ=1;//�ͷ�
	_nop_();i = 29;while (--i);//��ʱ70us
	AckBit=OneWire_DQ;//��ȡ�ӻ�����Ӧֵ���͵�ƽ��
	_nop_();i = 247;while (--i);//��ʱ500us
	
	return AckBit;
}

void OneWire_SendBit(unsigned char Bit)
{
	unsigned char i;
	OneWire_DQ=0;
	i = 4;while (--i);//��ʱ10us
	OneWire_DQ=Bit;
	_nop_();i = 22;while (--i);//��ʱ50us
	OneWire_DQ=1;
	
}

unsigned char OneWire_ReceiveBit(void)
{
	unsigned char i;
	unsigned char Bit;
	OneWire_DQ=1;
	OneWire_DQ=0;
	i = 2;while (--i);//��ʱ5us
	OneWire_DQ=1;
	i = 2;while (--i);//��ʱ5us
	Bit=OneWire_DQ;
	_nop_();i = 22;while (--i);//��ʱ50us
	
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