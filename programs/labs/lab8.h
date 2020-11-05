#include "mbed.h"
#include "crazyflie.h"

// Crazyflie controller objects
Mixer mixer;
AttitudeEstimator att_est;
AttitudeController att_cont;

// Ticker objects
Ticker tic;

// Interrupt flag and counter variables
bool flag;

// Callback functions
void callback(){flag = true;}

//Programa principal
int main (){
    //Inidicação de que queremos que o drone fique sempre na posição paralela ao chao (definição dos setpoints do controlador)
    float f_t = 0.83*m*g;
    float phi_r = 0.0f;
    float theta_r = 0.0f;
    float psi_r = 0.0f;

    //Inicialização dos objetos do estimador 
    att_est.init();

    // Initialize interrupts
    tic.attach(& callback, dt);

    //Armar motores
    mixer.arm();

    //Rodar o controlador enquanto a inclinação de roll e pitch do drone não superarem 45 graus e as velocidade angulares não superarem 12.5 rad/s
    while(abs(att_est.phi) <= pi/4.0 && abs(att_est.theta) <= pi/4.0 && abs(att_est.p) <= 4.0*pi && abs(att_est.q) <= 4.0*pi && abs(att_est.r) <= 4.0*pi){
        if (flag){
            flag = false;
            att_est.estimate();
            att_cont.control(phi_r, theta_r, psi_r, att_est.phi, att_est.theta, att_est.psi, att_est.p, att_est.q, att_est.r);
            mixer.actuate(f_t, att_cont.tau_phi, att_cont.tau_theta, att_cont.tau_psi);
        }
    }
    // Disarm motors and end program
    mixer.disarm();
    while(1);
}
