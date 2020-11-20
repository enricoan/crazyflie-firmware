#include "vertical_estimator.h"

// Class constructor
VerticalEstimator::VerticalEstimator():range(E_SDA, E_SCL){
    z = 0.0;
    w = 0.0;
}

// Initialize class
void VerticalEstimator::init(){
    range.init();
}

//Predição da posição e velodidade verticais através da planta, que leva em consideração a frça de empuxo total aplicada pelas asas
void VerticalEstimator::predict(float f_t){
    z += w * dt;    
    w += (f_t/m)*dt;
}

// Corretor da posição e da velocidade verticais através das medidas dos ângulos
void VerticalEstimator::correct(float phi, float theta){
    range.read();
    if(range.d < 4.0){
        float z_m = range.d * cos(phi) * cos(theta);
        z += alpha_ver_2 * (z_m - z);
        w += alpha_ver_1 * (z_m - z);
    }
}