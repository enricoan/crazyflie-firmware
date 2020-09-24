#include "mbed.h"
#include "crazyflie.h"

PwmOut motor_1(MOTOR1), motor_2(MOTOR2), motor_3(MOTOR3), motor_4(MOTOR4);
float omega_1, omega_2, omega_3, omega_4;

float control_motor(double omega_r){
    float PWM = a2*pow(omega_r,2) + a1*omega_r;
    return PWM;}

void mixer (float f_t, float tau_phi, float tau_theta, float tau_psi){
    omega_1 = f_t * 1/(4*kl) + tau_phi * -1/(4*kl*l) + tau_theta * -1/(4*kl*l) + tau_psi * -1/(4*kd);
    omega_2 = f_t * 1/(4*kl) + tau_phi * -1/(4*kl*l) + tau_theta *  1/(4*kl*l) + tau_psi *  1/(4*kd);
    omega_3 = f_t * 1/(4*kl) + tau_phi *  1/(4*kl*l) + tau_theta *  1/(4*kl*l) + tau_psi * -1/(4*kd);
    omega_4 = f_t * 1/(4*kl) + tau_phi *  1/(4*kl*l) + tau_theta * -1/(4*kl*l) + tau_psi *  1/(4*kd);

    if(omega_1 < 0){omega_1 = 0;}
    else{omega_1 = sqrt(omega_1);}

    if(omega_2 < 0){omega_2 = 0;}
    else{omega_2 = sqrt(omega_2);}

    if(omega_3 < 0){omega_3 = 0;}
    else{omega_3 = sqrt(omega_3);}

    if(omega_4 < 0){omega_4 = 0;}
    else{omega_4 = sqrt(omega_4);}
    }

void actuate (float f_t, float tau_phi, float tau_theta, float tau_psi){
    mixer (f_t, tau_phi, tau_theta, tau_psi);
    motor_1 = control_motor (omega_1);
    motor_2 = control_motor (omega_2);
    motor_3 = control_motor (omega_3);
    motor_4 = control_motor (omega_4);
}

int main(){
    actuate(1.5*m*g, 0, 0, 0);
    wait(5);
    actuate(0, 0, 0, 0);
    while(true){}
}