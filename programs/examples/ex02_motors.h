#include "mbed.h"
#include "crazyflie.h"

// Define motor 1 as PWM output object
PwmOut motor1(MOTOR1);
PwmOut motor2(MOTOR2);
PwmOut motor3(MOTOR3);
PwmOut motor4(MOTOR4);
float power = 0.4;

// Main program
int main()
{
    // Turn motor on (20% power) and off every second
    while(true) 
    {
      motor1 = power;
      wait(0.6);
      motor1 = 0.0;
      wait(0.5);

      motor2 = power;
      wait(0.6);
      motor2 = 0.0;
      wait(0.5);

      motor3 = power;
      wait(0.6);
      motor3 = 0.0;
      wait(0.5);

      motor4 = power;
      wait(0.6);
      motor4 = 0.0;
      wait(0.5);

    }
}
