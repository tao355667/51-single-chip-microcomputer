#include <REGX52.H>
#include <INTRINS.H>
#include "delay.h"

void Delay1ms()		//@11.0592MHz
{
	unsigned char i, j;

	_nop_();
	i = 2;
	j = 199;
	do
	{
		while (--j);
	} while (--i);
}

void delay_ms(unsigned long int ms)
{
	while(ms--){
		Delay1ms();
	}
}
