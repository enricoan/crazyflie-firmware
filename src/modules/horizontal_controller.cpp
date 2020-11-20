#include "horizontal_controller.h"

// Class constructor
HorizontalController::HorizontalController(){
    phi_r = 0;
    theta_r = 0;
}

// Control reference roll and pitch angles ( rad ) given reference positions (m) and current positions (m) and velocities (m/s)
void HorizontalController::control(float x_r, float y_r, float x, float y, float u, float v){
    theta_r = control_siso(x_r, x, u, kp_hor, kd_hor)/g;
    phi_r = -control_siso(y_r, y, v, kp_hor, kd_hor)/g;
}

// Control acceleration given reference position (m) and current position (m) and velocity (m/s) with given controller gains
float HorizontalController::control_siso(float pos_r, float pos, float vel, float kp, float kd){
    float d2tdt2 = kp * (pos_r - pos) + kd * (0 - vel);
    return d2tdt2;
}