#include <intrins.h>
#include <reg52.h>
unsigned int i, k;
unsigned int led = 0x01;
void main()
{
    TH0 = (65536 - 45872) / 256; //装初值，11.0592MHz晶振定时50ms，数为45872  ,前4位
    TL0 = (65536 - 45872) % 256; //后4位
    TMOD = 0X01;
    EA = 1;
    ET0 = 1; //开定时器0中断
    TR0 = 1; //启动定时器0
    while (1)
        P1 = led;
}

void time_1() interrupt 1
{
    TH0 = (65536 - 50000) / 256;
    TL0 = (65536 - 50000) % 256;
    k++;
    if (k == 4) //   定时4*50MS
    {
        k = 0;
        led = crol_(led, 1);
    }
}