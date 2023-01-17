#include <REGX52.H>
#include "51common.h"

void Timer0_Init()
{
//	TMOD=0x01;//工作模式
	TMOD&=0xF0;//工作模式
	TMOD|=0x01;//工作模式
	TF0=0;//溢出位，置0
	TR0=1;//开始工作
	//定时1ms初值
	TH0=64535/256;
	TL0=64535%256;
	//允许T0中断
	EA=1;ET0=1;
	//中断优先级
	PT0=0;
}

u16 T0count;
void Timer0_Rountine() interrupt 1
{
	//定时1ms初值
	TH0=64535/256;
	TL0=64535%256;
	T0count++;
	if(T0count>=1000)
	{
		T0count=0;
		P2=~P2;
	}
	

}
