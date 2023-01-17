/*
定时器舵机
SG90舵机一个周期20ms
高电平时间对应角度
0.5ms	0°
1ms		45°
1.5ms	90°
2ms		135°
2.5ms	180°
*/
#include <REGX52.H>//标准头文件
#include "51common.h"//定义unsigned char为u8,延时函数delay_ms()
#include "key.h"//独立按键头文件
#include "LCD1602.h"//LCD1602头文件
#include "timer.h"//定时器

unsigned char Counter,Compare;
unsigned char key,speed;

void main()
{
	Timer0_Init();
	while(1)
	{
		key=KEY_Scan(0);
		if(key==1){
			speed++;
			speed%=5;
			if(speed==0){Compare=5;}
			if(speed==1){Compare=10;}
			if(speed==2){Compare=15;}
			if(speed==3){Compare=20;}
			if(speed==4){Compare=25;}
		}
	}
	
}

