#include "delay.h"
//==============================================================================
void delay::us(unsigned int us)
{
    // Convert microseconds us into how many clock ticks it will take
    us *= Frequency / 1000000 / 2; // Core Timer updates every 2 ticks

    _CP0_SET_COUNT(0); // Set Core Timer count to 0

    while (us > _CP0_GET_COUNT()); // Wait until Core Timer count reaches the number we calculated earlier
}
void delay::ms(unsigned int ms)
{
    us(ms * 1000);
}
void delay::s(unsigned int s)
{
    ms(s * 1000);
}
