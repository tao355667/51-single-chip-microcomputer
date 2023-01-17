/*
AT24C02.c
*/

#include <REGX52.H>
#include "delay.h"//delay_ms()   unsigned charΪu8,
#include "I2C.h"//I2C(iic)通信协议
#include "LCD1602.h"//LCD1602头文件

#define AT24C02_ADDRESS 0xA0	//1010 000 0

/**
  * @brief AT24C02写字节
  * @param 片内地址，要存储的数据
  * @retvalf 无
  */
void AT24C02_WriteByte(unsigned char WordAddress,Data)
{
	unsigned char a1=5,a2=5,a3=5;
	I2C_Start();
	I2C_SendByte(AT24C02_ADDRESS);
	a1=I2C_ReceiveAck();
	
	I2C_SendByte(WordAddress);
	a2=I2C_ReceiveAck();
	
	I2C_SendByte(Data);
	a3=I2C_ReceiveAck();
	
	I2C_Stop();
	
	//LCD_ShowNum(1,8,a1,1);
	//LCD_ShowNum(1,9,a2,1);
	//LCD_ShowNum(1,10,a3,1);
}
/**
  * @brief AT24C02读取字节
  * @param 片内地址
  * @retvalf 一字节数据
  */
unsigned char AT24C02_ReadByte(unsigned char WordAddress)
{
	unsigned char Data;
	I2C_Start();
	I2C_SendByte(AT24C02_ADDRESS);
	I2C_ReceiveAck();
	I2C_SendByte(WordAddress);
	I2C_ReceiveAck();
	
	I2C_Start();
	I2C_SendByte(AT24C02_ADDRESS|0x01);
	I2C_ReceiveAck();
	Data=I2C_ReceiveByte();
	I2C_SendAck(1);
	I2C_Stop();
	return Data;
}
