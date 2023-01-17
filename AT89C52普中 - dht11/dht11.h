#ifndef DHT11_H
#define DHT11_H

sbit DATA = P1^3;

void  COM(void);
u8 DHT11_Start(void);


#endif
