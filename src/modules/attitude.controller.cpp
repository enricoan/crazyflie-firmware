#include "mbed.h"
#include "attitude_controller.h"

// Class constructor
AttitudeController::AttitudeController(){
    tau_phi = 0;
    tau_theta = 0;
    tau_psi = 0;
    kp = w_n * w_n;
    kd = 2 * zeta * w_n;
    kd_yaw = 2 * zeta * w_n_yaw;
}

// Control torques (N.m) given reference angles (rad) and current angles ( rad ) and angular velocities ( rad /s)
void AttitudeController::control(float phi_r, float theta_r, float psi_r, float phi, float theta, float psi, float p, float q, float r){
    
    tau_phi   = I_xx * control_siso(float (phi_r), float (phi), float (p), float (kp), float (kd));
    tau_theta = I_yy * control_siso(float (theta_r), float (theta), float (q), float (kp), float (kd));
    tau_psi   = I_zz * control_siso(float (psi_r), float (psi), float (r), float (kp), float (kd_yaw));
}

// Controle do torque (N.m) que deve ser enviado aos motores dados um ângulo de referência (rad), um ângulo atual (rad), uma velocidade angular (rad/s) e os ganhos do controlador
float AttitudeController::control_siso(float angle_r, float angle, float rate, float kp, float kd){
    float d2tdt2 = kp * (angle_r - angle) + kd * ((angle_r - angle_r_antigo)/dt - (angle - angle_antigo)/dt);
    float angle_antigo = angle;
    float angle_r_antigo = angle_r;
    return d2tdt2;
}
