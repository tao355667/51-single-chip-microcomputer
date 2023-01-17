/*
此程序用延时的方法制作了一个电子钟，并可以手动调节时间
外设：LCD1602，三个独立按键（下拉）

使用方法：启动时为模式0，从0时刻开始记时间
		  长按设置键（1秒），可进入设置模式1，在设置模式1中可通过加减按键调节秒的数值
		  再按设置键，可进入设置模式1，在设置模式1中可通过加减按键调节“秒”的数值
		  再按设置键，可进入设置模式2，在设置模式2中可通过加减按键调节“分”的数值
		  再按设置键，可进入设置模式3，在设置模式3中可通过加减按键调节“时”的数值
		  再按设置键，回到模式0（时钟模式）

*/

#include <REGX52.H>//标准头文件
#include "typedef.h"//定义unsigned char为u8
#include "delay.h"//延时头文件，可调用delay_ms()
#include "key.h"//独立按键头文件
#include "LCD1602.h"//LCD1602头文件

#define keyMode P3_1	//模式按键
#define keyPlus P3_0    //加键
#define keyReduce P3_2  //减键

void showTime(void);//时间+1s，显示时间
void set_second(void);//设置秒
void set_minute(void);//设置分钟
void set_hour(void);//设置小时
void key_scan(void);//扫描设置键

//初始时间--全局变量
u8 second=0;//秒
u8 minute=0;//分
u8 hour=0;//时
u8 mode=0;//初始模式

void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"TIME:");//LCD屏幕上显示TIME：
	LCD_ShowChar(2,3,':');//显示时间中间的冒号
	LCD_ShowChar(2,6,':');//显示时间中间的冒号
	
	while(1)
	{
		key_scan();//检测设置按键是否按下
		if(mode==0)showTime();//显示时间
		if(mode==1)set_second();//设置秒
		if(mode==2)set_minute();//设置分
		if(mode==3)set_hour();//设置小时
		LCD_ShowString(1,6,"           ");//擦除文字痕迹
	}
}



void key_scan(void)
{
	if(!keyMode){
		delay_ms(10);
		while(!keyMode);
		mode=(mode+1)%4;
	}
	
}

void showTime(void)
{
	//对时间溢出的处理
	if(second>59){
		second=0;minute++;
	}
	if(minute>59){
		minute=0;hour++;
	}
	if(hour>23){
		hour=0;
	}
	LCD_ShowNum(2,1,hour,2);//显示时
	LCD_ShowNum(2,4,minute,2);//显示分
	LCD_ShowNum(2,7,second++,2);//显示秒
	delay_ms(980);//延时函数，计1秒，考虑其他程序执行时间，可适当缩小
}

void set_second(void)
{
	LCD_ShowString(1,6,"Set:Second ");//显示调节模式示意文字
    do{
		if(!keyPlus){//按键检测，长按短按都有效，易于调节
			second=(second+1)%60;//按键生效一次，秒数+1，为防止溢出使用了取余数算法
			delay_ms(200);//延时以减缓时间调节速度
		}
		if(!keyReduce){
			(second==0)?(second=59):(second--);//问号表达式，按键生效一次，秒数-1，用重新赋值防止溢出
			delay_ms(200);//延时以减缓时间调节速度
		}
		LCD_ShowNum(2,7,second,2);//展示调节后的秒数
	}while(keyMode);//模式按键没按下，就一直循环。模式按键按下时就跳出此模式
}

void set_minute(void)
{
	LCD_ShowString(1,6,"Set:Minute  ");//显示调节模式示意文字
	do{
		if(!keyPlus){
			 minute=(minute+1)%60;
			delay_ms(200);//延时以减缓时间调节速度
		}
		if(!keyReduce){
			(minute==0)?(minute=59):(minute--);
			delay_ms(200);//延时以减缓时间调节速度
		}
		LCD_ShowNum(2,4,minute,2);
	}while(keyMode);
}

void set_hour(void)
{
	LCD_ShowString(1,6,"Set:Hour   ");//显示调节模式示意文字
	do{
		if(!keyPlus){
			hour=(hour+1)%24;
			delay_ms(200);//延时以减缓时间调节速度
		}
		if(!keyReduce){
			(hour==0)?(hour=23):(hour--);
			delay_ms(200);//延时以减缓时间调节速度
		}
		LCD_ShowNum(2,1,hour,2);
	}while(keyMode);
}
