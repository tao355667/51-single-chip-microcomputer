#include <REGX52.H>
#include <INTRINS.H>//Ҫ��_nop_();
#include "delay.h"

void delay_ms(unsigned long int ms)
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


