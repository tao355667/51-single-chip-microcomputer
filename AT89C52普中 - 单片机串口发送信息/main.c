/*
串口向电脑发送数据
UART(Universal Asynchronous Receiver Transmitter)
TXD(transmit exchange data)
RXD(receive exchange data)
串口常用电平标准
TTL电平：+5V表示1，0V表示0
RS232电平：-3~-15V表示1，+3~+15V表示0
RS485电平：两线压差+2~+6V表示1，-2V~-6V表示0

*/
#include <REGX52.H>
#include <delay.h>
#include <key.h>

unsigned char sec;

void Uart_Init(void)		//9600bps@11.0592MHz
{
	
	SCON=0x40;
	PCON|=0x00;
	TMOD &= 0x0F;		//清除定时器1模式位
	TMOD |= 0x20;		//设定定时器1为8位自动重装方式
	TL1 = 0xFD;		//设定定时初值
	TH1 = 0xFD;		//设定定时器重装值
	ET1 = 0;		//禁止定时器1中断
	TR1 = 1;		//启动定时器1
	
}
void UART_SendByte(unsigned char Byte)
{
	SBUF=Byte;
	while(TI==0);
	TI=0;
	
}

void main()
{
	Uart_Init();
	
	while(1)
	{
		UART_SendByte(sec++);
		P2=0xf0;delay_ms(500);
		P2=0x0f;delay_ms(500);
	}
}

