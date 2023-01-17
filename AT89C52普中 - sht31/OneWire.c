#include <REGX52.H>//��׼ͷ�ļ�
#include "delay.h"//delay_ms()   unsigned charΪu8,
#include "LCD1602.h"//LCD1602ͷ�ļ�
#include <INTRINS.H>//Ҫ��_nop_();
//����11.0592MHz
//AM2301
sbit OneWire_DATA=P1^3;

unsigned char OneWire_Init(void)
{
	unsigned char i,j;
	unsigned char AckBit,AckBit1,AckBit2;
//	OneWire_DATA=1;
	//MCU���Ϳ�ʼ�ź�
	OneWire_DATA=0;
	delay_ms(1);
	OneWire_DATA=1;//�ͷ�
	i = 9;while (--i);//��ʱ20us
	//��������Ӧ
	i = 18;while (--i);//��ʱ40us
	AckBit1=OneWire_DATA;//��ȡ�ӻ�����Ӧֵ���͵�ƽ��
	_nop_();i = 36;while (--i);//��ʱ80us
	AckBit2=OneWire_DATA;//��ȡ�ӻ�����Ӧֵ���ߵ�ƽ��
	i = 18;while (--i);//��ʱ40us
	OneWire_DATA=1;
	AckBit=(!AckBit1)&AckBit2;//���ζ����յ��ӻ���Ӧ�ź���Ϊ1������Ϊ0
	
	return AckBit;
}

unsigned char OneWire_ReceiveBit(void)
{
	unsigned char i;
	unsigned char Bit;
	OneWire_DATA=1;
	while(OneWire_DATA);
	_nop_();i = 22;while (--i);//��ʱ50us
	_nop_();i = 22;while (--i);//��ʱ50us
	Bit=OneWire_DATA;
	
	
	OneWire_DATA=1;
	OneWire_DATA=0;
	i = 2;while (--i);//��ʱ5us
	OneWire_DATA=1;
	i = 2;while (--i);//��ʱ5us
	Bit=OneWire_DATA;
	_nop_();i = 22;while (--i);//��ʱ50us
	
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