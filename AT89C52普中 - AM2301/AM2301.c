#include <REGX52.H>//��׼ͷ�ļ�
#include "delay.h"//delay_ms()   unsigned charΪu8,
#include <INTRINS.H>//Ҫ��_nop_();
//����11.0592MHz
//AM2301
sbit AM2301_DATA=P1^3;

/**
  * @brief ��AM2301���Ϳ�ʼ�źŲ�������Ӧ
  * @param ��
  * @retvalf ���յ���Ӧ�򷵻�1�����򷵻�0
  */
unsigned char AM2301_Start(void)
{
	unsigned char i;
	unsigned char AckBit,AckBit1,AckBit2;
	AM2301_DATA=1;
	//MCU���Ϳ�ʼ�ź�
	AM2301_DATA=0;
	delay_ms(1);
	AM2301_DATA=1;//�ͷ�
	i = 9;while (--i);//��ʱ20us
	//��������Ӧ
	i = 18;while (--i);//��ʱ40us
	AckBit1=AM2301_DATA;//��ȡ�ӻ�����Ӧֵ���͵�ƽ��
	_nop_();i = 36;while (--i);//��ʱ80us
	AckBit2=AM2301_DATA;//��ȡ�ӻ�����Ӧֵ���ߵ�ƽ��
	i = 18;while (--i);//��ʱ40us
	AM2301_DATA=1;
	AckBit=(!AckBit1)&AckBit2;//���ζ����յ��ӻ���Ӧ�ź���Ϊ1������Ϊ0
	
	return AckBit;
}
/**
  * @brief ��AM2301����һ��������
  * @param ��
  * @retvalf 1��������
  */
unsigned char AM2301_ReceiveBit(void)
{
	unsigned char i;
	unsigned char Bit;
	
	while(AM2301_DATA);
	while(!AM2301_DATA);
	_nop_();i = 13;while (--i);//��ʱ30us
	Bit=AM2301_DATA;
	
	return Bit;
}
/**
  * @brief ��AM2301����һByte����
  * @param ��
  * @retvalf 1�ֽ�����
  */
unsigned char AM2301_ReceiveByte(void)
{
	unsigned char i;
	unsigned char Byte=0x00;
	for(i=0;i<8;i++){
		if(AM2301_ReceiveBit()){Byte|=(0x80>>i);}
	}
	return Byte;
}