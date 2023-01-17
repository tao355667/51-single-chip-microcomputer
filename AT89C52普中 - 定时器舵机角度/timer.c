#include <REGX52.H>
#include "51common.h"

sbit LED=P2^0;
sbit Motor=P1^0;

extern unsigned char Counter,Compare;

void Timer0_Init()
{
//	TMOD=0x01;//工作模式
	TMOD&=0xF0;//工作模式--保留高四位，低四位清零
	TMOD|=0x01;//工作模式--保留高四位，用新数据更新低四位，
	TF0=0;//溢出位，置0
	TR0=1;//开始工作
	//定时0.1ms初值
	TH0=0xFF;
	TL0=0xA4;
	//允许T0中断
	EA=1;ET0=1;
	//中断优先级
	PT0=0;
}


void Timer0_Rountine() interrupt 1
{
	//定时0.1ms初值
	TH0=0xFF;
	TL0=0xA4;
	Counter++;
	Counter%=200;
	if(Counter<Compare)
	{
		LED=0;
		Motor=1;
	}else{
		LED=1;
		Motor=0;
	}
	
	

}
