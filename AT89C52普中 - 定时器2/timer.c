#include <REGX52.H>
#include "key.h"


sbit Motor=P1^0;

unsigned char Counter_Motor=0,Compare_Motor=50;
unsigned char i;

void Timer2_Init(void)		//50毫秒@11.0592MHz
{
	T2MOD = 0x00;		//初始化模式寄存器
	T2CON = 0x04;		//初始化控制寄存器，16位自动重装载
	TL2 = 0x00;		//设置定时初值
	TH2 = 0x4C;		//设置定时初值
	RCAP2L = 0x00;		//设置定时重载值
	RCAP2H = 0x4C;		//设置定时重载值
	
	EA=1;ET2=1;//使能中断
	
	TR2 = 1;		//定时器2开始计时
	
}


void Timer2_Rountine() interrupt 5
{
//	P2=0x00;
//	//	P2=0x00;
//	
//	for(i=0;i<255;i++){
//		P2++;
//		delay_ms(100);
//	}
//	
	Counter_Motor++;
	Counter_Motor%=100;
	
	if(Counter_Motor>Compare_Motor)
	{
		Motor=1;
		P2=0x0F;
	}else{
		Motor=0;
		P2=0xF0;
	}

}
