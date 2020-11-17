#include "horizontal_estimator.h"

//Class constructor
HorizontalEstimator::HorizontalEstimator():flow(PA_7, PA_6, PA_5, PB_4){
    x = 0;
    y = 0;
    u = 0;
    v = 0;
}

// Initialize class
void HorizontalEstimator::init(){
    flow.init();
}

// Predict horizontal positions and velocities from model
void HorizontalEstimator::predict(float phi, float theta){
 u += g * theta * dt;
 v += g * phi * dt;
 x += u * dt;
 v += v * dt;
}

// Correct horizontal velocities with measurements
void HorizontalEstimator::correct(float phi, float theta, float p, float q, float z){
    float den = cos(phi)*cos(theta);
    if(den > 0.5){
            float d = z/den;
            flow.read();
            float u_m = (sigma * flow.px + q) * d;
            float v_m = (sigma * flow.py - q) * d;
            u += l_hor * dt * (u_m - u);
            v += l_hor * dt * (v_m - v);
        }
}