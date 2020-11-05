#include "attitude_estimator.h"
#include <cmath>
//Variável para indicar calibração do giroscópio (eliminiação de erro sistemático de leitura)    
bool led_cal = LED_RED_L; 

//Construtor do estimador de atitude
AttitudeEstimator::AttitudeEstimator(): imu(IMU_SDA, IMU_SCL){
    phi = 0;
    theta = 0;
    psi = 0;
    p = 0;
    p_bias = 0;
    q = 0;
    q_bias = 0;
    r = 0;
    r_bias = 0;
}

//Inicializador da classe
void AttitudeEstimator::init(){
    imu.init();   
    for(int i = 0; i<1500; i++){
        imu.read();
        p_bias = p_bias + imu.gx/1500;
        q_bias = q_bias + imu.gy/1500;
        r_bias = r_bias + imu.gz/1500;

        led_cal = !led_cal;
        wait(dt);
    }
}

// Estimador dos ângulos de Euler (rad) e velocidades angulares (rad/s)
void AttitudeEstimator::estimate(){
    imu.read();
    /*
//  Controle linear de ângulos
    p = imu.gx - p_bias; 
    float phi_g = phi + p * dt;
    float phi_a = atan2(-imu.ay, -imu.az);
    phi = (1-alpha) * phi_g + alpha * phi_a;

    q = imu.gy - q_bias;
    float theta_g = theta + q * dt;
    float theta_a = atan2(imu.ax, -imu.az);
    theta = (1-alpha) * theta_g + alpha * theta_a;

    r = imu.gz - r_bias; 
    psi = psi + r * dt;
    */
//  Controle não linear de ângulos
    p = imu.gx - p_bias; 
    float phi_g = phi + (p + sin(phi)*tan(theta)*q + cos(phi)*tan(theta)*r) * dt;
    float phi_a = atan2(-imu.ay, -imu.az);
    phi = (1-alpha) * phi_g + alpha * phi_a;

    q = imu.gy - q_bias;
    float theta_g = theta + (cos(phi)*q - sin(phi)*r) * dt;
    float theta_a = atan2(imu.ax, -(((imu.az>0)-(imu.az<0))*pow((imu.ax*imu.ax + imu.az*imu.az), 0.5)));
    theta = (1-alpha) * theta_g + alpha * theta_a;

    r = imu.gz - r_bias; 
    psi = psi + (sin(phi)*(1/cos(theta))*q + cos(phi)*(1/cos(theta))*r) * dt;
}
