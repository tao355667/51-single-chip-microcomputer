#include <REGX52.H>
#include "51common.h"
#include <INTRINS.H>//ÒªÓÃ_nop_();

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




