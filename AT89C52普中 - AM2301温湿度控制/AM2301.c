#include <REGX52.H>//标准头文件
#include "delay.h"//delay_ms()   unsigned char为u8,
#include <INTRINS.H>//要用_nop_();
//晶振11.0592MHz
//AM2301
sbit AM2301_DATA=P1^3;

/**
  * @brief 给AM2301发送开始信号并接收响应
  * @param 无
  * @retvalf 接收到响应则返回1，否则返回0
  */
unsigned char AM2301_Start(void)
{
	unsigned char i;
	unsigned char AckBit,AckBit1,AckBit2;
	AM2301_DATA=1;
	//MCU发送开始信号
	AM2301_DATA=0;
	delay_ms(1);
	AM2301_DATA=1;//释放
	i = 9;while (--i);//延时20us
	//传感器响应
	i = 18;while (--i);//延时40us
	AckBit1=AM2301_DATA;//读取从机的响应值（低电平）
	_nop_();i = 36;while (--i);//延时80us
	AckBit2=AM2301_DATA;//读取从机的响应值（高电平）
	i = 18;while (--i);//延时40us
	AM2301_DATA=1;
	AckBit=(!AckBit1)&AckBit2;//两次都接收到从机响应信号则为1，否则为0
	
	return AckBit;
}
/**
  * @brief 从AM2301接收一比特数据
  * @param 无
  * @retvalf 1比特数据
  */
unsigned char AM2301_ReceiveBit(void)
{
	unsigned char i;
	unsigned char Bit;
	
	while(AM2301_DATA);
	while(!AM2301_DATA);
	_nop_();i = 13;while (--i);//延时30us
	Bit=AM2301_DATA;
	
	return Bit;
}
/**
  * @brief 从AM2301接收一Byte数据
  * @param 无
  * @retvalf 1字节数据
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