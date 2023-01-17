#include <REGX52.H>
#include <INTRINS.H>

void Delay1ms()		//@11.088MHz
{
	unsigned char i, j;

	i = 2;
	j = 201;
	do
	{
		while (--j);
	} while (--i);
}
void delay(unsigned long int ms)
{
	while(ms--){
		Delay1ms();
	}
}





void main()
{
	
	while(1)
	{
		P2=0xaa;//1010 1010
		delay(2000);
		P2=0x55;//0101 0101
		delay(2000);
	}
}

