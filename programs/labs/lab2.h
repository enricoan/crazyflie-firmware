# include "mbed.h"
# include "crazyflie.h"

// Define motor 1 as PWM output object
PwmOut motor_1(MOTOR1);
PwmOut motor_2(MOTOR2);
PwmOut motor_3(MOTOR3);
PwmOut motor_4(MOTOR4);
 
// Converts desired angular velocity (rad/s) to PWM signal (%)
float control_motor(double omega_r){
    float PWM = a2*pow(omega_r,2) + a1*omega_r;
    return PWM;}

// Main program
int main ()
{
    // Set PWM frequency to 500 Hz
    //motor_3.period(1.0/500.0);

    while(true){
    motor_1 = control_motor(500.0);
    wait (0.5);
    motor_1 = control_motor(0.0);
    wait(0.5);

    motor_2 = control_motor(1000.0);
    wait (0.5);
    motor_2 = control_motor(0.0);
    wait(0.5);

    motor_3 = control_motor(1500.0);
    wait (0.5);
    motor_3 = control_motor(0.0);
    wait(0.5);

    motor_4 = control_motor(2000.0);
    wait (0.5);
    motor_4 = control_motor(0.0);
    wait(0.5);
                }
}