#include <REGX52.H>
#include <INTRINS.H>

typedef unsigned char u8;

void delay_ms(unsigned long int ms);		//@12.000MHz


void main()
{
	u8 LEDNum=0xff;
	while(1)
	{
		if(P3_1==0){
			delay_ms(10);
			while(P3_1==0);
			delay_ms(10);
			
			LEDNum++;
			if(LEDNum>=8)LEDNum=0;
			P2=~(0x01<<LEDNum);
			
		}
		if(P3_0==0){
			delay_ms(10);
			while(P3_1==0);
			delay_ms(10);
			
			if(LEDNum==0) LEDNum=7;
			else LEDNum--;
			
			P2=~(0x01<<LEDNum);
			
		}
		
		
	}
}


void delay_ms(unsigned long int ms)		//@12.000MHz
{
	unsigned char i, j;
    while(ms--)
	{
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
    }
}
