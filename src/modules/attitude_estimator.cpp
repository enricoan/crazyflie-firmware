#include "attitude_estimator.h"

//Construtor do estimador de atitude
AttitudeEstimator::AttitudeEstimator(): imu(IMU_SDA, IMU_SCL){
    phi = 0;
    theta = 0;
    psi = 0;
    p = 0;
    q = 0;
    r = 0;
}

//Inicializador da classe
void AttitudeEstimator::init(){
imu.init();
}

// Estimador dos ângulos de Euler (rad) e velocidades angulares (rad/s)
void AttitudeEstimator::estimate (){
    imu.read();
    float phi_a = atan2(-imu.ay, -imu.az);
    phi = (1-alpha)*phi + alpha*phi_a;
}
