#include <REGX52.H>
#include <INTRINS.H>

typedef unsigned char u8;

void delay_ms(unsigned long int ms);		//@12.000MHz


void main()
{
	u8 LEDNum=0;//存储要显示的二进制数
	while(1)
	{
		if(P3_1==0){
			delay_ms(20);
			while(P3_1==0);

			delay_ms(20);
			//P2复位值1111 1111
			P2=~++LEDNum;//将存储的二进制数转换为P2口要求的格式

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
