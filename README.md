######
# Device Drivers for STM8
#
# Developer: Aniket Fondekar
#
# Date: 15 Jan 2020 
######

Bare metal programming: STM8 

STM8 is a cheap 8-bit microcontroller aimed towards low-cost mass-market devices. Initially I came across this part while searching for a simple microcontroller as a replacement for AVRs. Despite having various ARM Cortex-M0 devices available on the market for quite attractive prices, AVRs have one advantage - simplicity. Utilizing an ARM Cortex core to switch some lights on and off seems like an overkill. Some applications just don’t require that amount of flexibility and performance.

The main goal of this article is to demonstrate that ‘bare metal’ programming is not a difficult task and to give you an overview of STM8’s architecture and peripherals. Even though writing peripheral drivers from scratch might seem like reinventing the wheel, in many cases it is easier and faster to implement the functionality that you need for a specific task, instead of relying on vendor-supplied libraries that try to do everything at once (and fail).

for more details check out this :https://lujji.github.io/blog/bare-metal-programming-stm8/



Main motive was to develop CAN driver from scratch.

