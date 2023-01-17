#include <REGX52.H>
#include "key.h"

sbit LED=P2^0;
sbit Motor=P1^0;
sbit Servo=P0^0;


extern unsigned char Counter_Motor,Counter_Servo,Compare_Servo,Compare_Motor;
extern unsigned char key;

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
	PT0=1;
}

void Timer1_Init()
{
//	TMOD=0x01;//工作模式
	TMOD&=0x0F;//工作模式--保留高四位，低四位清零
	TMOD|=0x10;//工作模式--保留高四位，用新数据更新低四位，
	TF1=0;//溢出位，置0
	TR1=1;//开始工作
	//定时0.1ms初值
	TH1=0xFF;
	TL1=0xA4;
	//允许T0中断
	EA=1;ET1=1;
	//中断优先级
	PT1=0;
}

void Timer2Init(void)		//10微秒@11.0592MHz
{
	T2MOD = 0;		//初始化模式寄存器
	T2CON = 0;		//初始化控制寄存器
	TL2 = 0xF7;		//设置定时初值
	TH2 = 0xFF;		//设置定时初值
	RCAP2L = 0xF7;		//设置定时重载值
	RCAP2H = 0xFF;		//设置定时重载值
	TR2 = 1;		//定时器2开始计时
}


void Timer0_Rountine() interrupt 1
{
	//定时0.1ms初值
	TH0=0xFF;
	TL0=0xA4;
	Counter_Servo++;
	Counter_Servo%=200;
	if(Counter_Servo<Compare_Servo)
	{
		LED=0;
		Servo=1;
	}else{
		LED=1;
		Servo=0;
	}
	
}

void Timer1_Rountine() interrupt 3
{
	
	//定时0.1ms初值
	TH1=0xFF;
	TL1=0xA4;
	Counter_Motor++;
	Counter_Motor%=100;
	if(Counter_Motor<Compare_Motor)
	{
		Motor=1;
	}else{
		Motor=0;
	}
	
}

void Timer2_Rountine() interrupt 5
{
	TL2 = 0xF7;		//设置定时初值
	TH2 = 0xFF;		//设置定时初值
	key=KEY_Scan(1);
}
