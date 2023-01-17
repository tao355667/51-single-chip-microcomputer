#include <REGX52.H>
#include <INTRINS.H>//ÒªÓÃ_nop_();
#include "delay.h"

void  delay_ms(unsigned long int nms)
{
#if MAIN_Fosc == 12000000L
    unsigned char i, j;
    do
    {
        i = 2;
        j = 239;
        do
        {
            while (--j);
        }
        while (--i);
    }
    while(--nms);
#elif MAIN_Fosc == 11059200L
    unsigned char i, j;
    do
    {
        _nop_();
        i = 2;
        j = 199;
        do
        {
            while (--j);
        }
        while (--i);
    }
    while(--nms);

#endif
}

