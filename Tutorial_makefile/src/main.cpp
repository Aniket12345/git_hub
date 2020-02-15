#include<iostream>
#include"led.h"
#include"relay.hpp"

int main()
{
    std::cout <<"Make file Tutorail\n";
    Led_on();
    Led_off();
    Relay_on();
    Relay_off();
    return 0;
}

