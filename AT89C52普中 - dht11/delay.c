#include <REGX52.H>
#include <INTRINS.H>//ÒªÓÃ_nop_();
#include "delay.h"

void delay_ms(unsigned long int ms)	//@12MHz
{
	unsigned char i, j;
    while(ms--){
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
	}
	
}


void Delay_10us()		//@12MHz
{
	unsigned char i;

	_nop_();
	i = 2;
	while (--i);
}
