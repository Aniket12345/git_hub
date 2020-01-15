#include<stdio.h>
//#include"led.h"
//#include"relay.h"
extern void led_on();
extern void led_off();
extern void relay_on();
extern void relay_off();
int main()
{
    printf("make file\n");
    led_on();
    led_off();
    relay_on();
    relay_off();
    return 0;
}

