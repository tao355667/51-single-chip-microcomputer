#include <REGX52.H>
#include "typedef.h"
#include "delay.h"

void Nixie(u8 location,Number,Point);

void main()
{
	while(1)
	{
		u8 i;
		for(i=0;;i++){
			Nixie(1,i,1);
			delay_ms(500);
			if(i==9) i=0;
		}
		
	}
}

void Nixie(u8 Location,Number,Point)
{
	//坐标（1~8，从右到左），数字（0~9），有无点（1为有，0为无）
	switch(Location)
	{
		case 1:P2_4=0;P2_3=0;P2_2=0;break;
		case 2:P2_4=0;P2_3=0;P2_2=1;break;
		case 3:P2_4=0;P2_3=1;P2_2=0;break;
		case 4:P2_4=0;P2_3=1;P2_2=1;break;
		case 5:P2_4=1;P2_3=0;P2_2=0;break;
		case 6:P2_4=1;P2_3=0;P2_2=1;break;
		case 7:P2_4=1;P2_3=1;P2_2=0;break;
		case 8:P2_4=1;P2_3=1;P2_2=1;break;
	}
	switch(Number)
	{
		case 0:P0=0x3F;break;
		case 1:P0=0x06;break;
		case 2:P0=0x5b;break;
		case 3:P0=0x4f;break;
		case 4:P0=0x66;break;
		case 5:P0=0x6D;break;
		case 6:P0=0x7D;break;
		case 7:P0=0x07;break;
		case 8:P0=0x7F;break;
		case 9:P0=0x6F;break;
	}
	switch(Point)
	{
		case 0:P0_7=0;break;
		case 1:P0_7=1;break;
	}
	
	
	
}
