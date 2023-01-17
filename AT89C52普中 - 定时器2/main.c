/*
定时器舵机
SG90舵机一个周期20ms
高电平时间对应角度
0.5ms	0°
1ms		45°
1.5ms	90°
2ms		135°
2.5ms	180°
//具体数据应以试验为主，此次试验如下：
			if(speed==0){Compare_Servo=4;}
			if(speed==1){Compare_Servo=8;}
			if(speed==2){Compare_Servo=13;}
			if(speed==3){Compare_Servo=18;}
			if(speed==4){Compare_Servo=25;}
*/
#include <REGX52.H>//标准头文件
#include "51common.h"//定义unsigned char为u8,延时函数delay_ms()
#include "key.h"//独立按键头文件
#include "LCD1602.h"//LCD1602头文件
#include "timer.h"//定时器
#include "delay.h"//延时函数



void main()
{

	
//	
//	
//	P2=0x00;
//	for(i=0;i<255;i++){
//		P2++;
//		delay_ms(100);
//	}
//	
	Timer2_Init();
	
	while(1)
	{
		
	}
	
}

