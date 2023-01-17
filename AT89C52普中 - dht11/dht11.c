#include <REGX52.H>
#include "delay.h"
#include "typedef.h"
#include "dht11.h"

u8  U8FLAG,k;
u8  U8count,U8temp;
u8  U8T_data_H,U8T_data_L,U8RH_data_H,U8RH_data_L,U8checkdata;
u8  U8T_data_H_temp,U8T_data_L_temp,U8RH_data_H_temp,U8RH_data_L_temp,U8checkdata_temp;
u8  U8comdata;
u8  count, count_r=0;

void  COM(void)
{
    unsigned char i;
    for(i=0;i<8;i++)	   
    {
  	    U8FLAG=2;
	   	while((!DATA)&&U8FLAG++);
		Delay_10us();
		Delay_10us();
		Delay_10us();
  		U8temp=0;
        if(DATA)U8temp=1;
		    U8FLAG=2;
		while((DATA)&&U8FLAG++);
	   	//超时则跳出for循环		  
	   	if(U8FLAG==1)break;
	   	//判断数据位是0还是1	 
	   	   
		// 如果高电平高过预定0高电平值则数据位为 1 
	   	 
		U8comdata<<=1;
	   	U8comdata|=U8temp;     
    }//rof
}

//--------------------------------
//-----温湿度读取子程序 ------------
//--------------------------------
//----以下变量均为全局变量--------
//----温度高8位== U8T_data_H------
//----温度低8位== U8T_data_L------
//----湿度高8位== U8RH_data_H-----
//----湿度低8位== U8RH_data_L-----
//----校验 8位 == U8checkdata-----
//----调用相关子程序如下----------
//---- Delay();, Delay_10us();COM(); 
//--------------------------------
u8 DHT11_Start(void)
{
	//主机拉低18ms 
    DATA=0;
	delay_ms(18);  //延时18毫秒
	DATA=1;
	//总线由上拉电阻拉高 主机延时40us
	Delay_10us();
	Delay_10us();
	Delay_10us();
	Delay_10us();
	//主机设为输入 判断从机响应信号 
	DATA=1;
	//判断从机是否有低电平响应信号 如不响应则跳出，响应则向下运行	  
	if(!DATA)		 //T !	  
	{
	    U8FLAG=2;
	    //判断从机是否发出 80us 的低电平响应信号是否结束	 
	    while((!DATA)&&U8FLAG++);
	    U8FLAG=2;
	    //判断从机是否发出 80us 的高电平，如发出则进入数据接收状态
	    while((DATA)&&U8FLAG++);
	    //数据接收状态		 
	    COM();
	    U8RH_data_H_temp=U8comdata;
	    COM();
	    U8RH_data_L_temp=U8comdata;
	    COM();
	    U8T_data_H_temp=U8comdata;
	    COM();
	    U8T_data_L_temp=U8comdata;
	    COM();
	    U8checkdata_temp=U8comdata;
	    DATA=1;
	    //数据校验 
	    U8temp=(U8T_data_H_temp+U8T_data_L_temp+U8RH_data_H_temp+U8RH_data_L_temp);
	    if(U8temp==U8checkdata_temp)
	    {
	   	   U8RH_data_H=U8RH_data_H_temp;//湿度整数数
	   	   U8RH_data_L=U8RH_data_L_temp;//湿度小数
	   	   U8T_data_H=U8T_data_H_temp;//温度整数
	   	   U8T_data_L=U8T_data_L_temp;//温度小数
	   	   U8checkdata=U8checkdata_temp;//校验
	    }//fi
		return 1;
	}//fi
	else   //传感器不响应
	{
	   return 0;
	}
	
}


