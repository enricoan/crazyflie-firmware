#include "mbed.h"
#include "crazyflie.h"
#include "USBSerial.h"

// Define serial object
USBSerial serial;

// Main program
int main()
{
    // Print "Hello World" every 1s
    while(1) 
    {
        serial.printf("Hello world!\n");
        wait(1);
    }
}