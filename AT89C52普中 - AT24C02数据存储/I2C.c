/*
I2C.c
*/
#include <REGX52.H>
#include "delay.h"//delay_ms()   unsigned char为u8,

sbit I2C_SCL=P2^1;
sbit I2C_SDA=P2^0;

/**
  * @brief I2C开始
  * @param 无
  * @retvalf 无
  */
void I2C_Start()
{
	I2C_SDA=1;
	I2C_SCL=1;
	I2C_SDA=0;//SDA 1->0跳变
	I2C_SCL=0;
}
/**
  * @brief I2C停止
  * @param 无
  * @retvalf 无
  */
void I2C_Stop()
{
	I2C_SDA=0;
	I2C_SCL=1;
	I2C_SDA=1;//SDA 0->1跳变
}
/**
  * @brief I2C发送一个字节
  * @param 无
  * @retvalf 无
  */
void I2C_SendByte(unsigned char Byte)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		I2C_SDA=Byte&(0x80>>i);
		I2C_SCL=1;
		I2C_SCL=0;
	}

}
/**
  * @brief I2C接收一个字节
  * @param 无
  * @retvalf 接收到一个字节数据
  */
unsigned char I2C_ReceiveByte()
{
	unsigned char i,Byte=0x00;
	I2C_SDA=1;
	for(i=0;i<8;i++){
		I2C_SCL=1;
		if(I2C_SDA){Byte|=(0x80>>i);}
		I2C_SCL=0;
	}
	
	return Byte;
}
/**
  * @brief I2C发送应答
  * @param AckBit 应答位，0为应答，1为非应答
  * @retvalf 无
  */
void I2C_SendAck(unsigned char AckBit)
{
	I2C_SDA=AckBit;
	I2C_SCL=1;
	I2C_SCL=0;
}
/**
  * @brief I2C接收应答位
  * @param 无
  * @retvalf 接收到的应答位，0为应答，1为非应答
  */
unsigned char I2C_ReceiveAck()
{
	unsigned char AckBit;
	I2C_SDA=1;//释放
	I2C_SCL=1;
	AckBit=I2C_SDA;
	I2C_SCL=0;
	return AckBit;
}
