#ifndef attitude_estimator_h
#define attitude_estimator_h

#include "mbed.h"
#include "crazyflie.h"

//classe do estimador de atitude
class AttitudeEstimator{
    public:
        //construtor da classe
            AttitudeEstimator();

        //Iinicialização da classe
            void init();

        //estimar ângulos de euler
            void estimate();

        //Ângulos de Euler (rad)
            float phi, theta, psi;

        //Velocidades angulares (rad/s)
            float p, q, r;

    private:
        //IMU sensor object
            BMI088 imu;

        //Variavel para o LED indicador de calibração
            DigitalOut led;
            
        //Obtenção dos valores de erro sistemático
            float p_bias, q_bias, r_bias;
};

#endif