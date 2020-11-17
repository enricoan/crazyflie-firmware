#ifndef mixer_h
#define mixer_h

#include "mbed.h"
#include "crazyflie.h"

class Mixer{
    public: //declaração das funções que vão poder ser chamadas no programa principal
        Mixer(); //construtor da classe

        //função que mudará o estado da variável armed para true
        void arm(); 

        //função que mudará o estado da variável armed para false e desligará os motores
        void disarm(); 

        //acionamento dos motores dependendo das forças e torques solicitados
        void actuate(float f_t, float tau_phi, float tau_theta, float tau_psi);

    private: //declaração das variáveis e funções de uso interno da classe
        //declaração da variável booleana que guardará o estado de "armado" e "desarmado" do drone
        bool armed; 

        //declaração dos motores como objetos de PWM de saída 
        PwmOut  motor_1, motor_2, motor_3, motor_4;

        //velocidades angulares solicitadas usadas internamente
        float omega_1, omega_2, omega_3, omega_4;

        //conversão do empuxo e dos torques em velocidades angulares
        void mixer(float f_t, float tau_phi, float tau_theta, float tau_psi);
        
        //função que, dada uma velocidade solicitada, controla o valor de PWM que deve ser fornecido aos motores do drone
        float control_motor(float omega_r);

        //Variavel LED que indica estado de funcionamento atual
        DigitalOut led_funcionamento;
};

#endif