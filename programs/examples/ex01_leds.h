#include "mbed.h"
#include "crazyflie.h"

// Define red LED (right) as digital output object
DigitalOut led1(LED_RED_R,!false);
DigitalOut led2(LED_RED_L,!false);

// Main program
int main()
{
    // Blink LED every second
    while(true) 
    {
        led1 = !led1;
        wait(0.5);

        led2 = !led2;
        wait(0.2);
    }
}
