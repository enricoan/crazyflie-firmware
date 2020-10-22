#ifndef parameters_h
#define parameters_h

#include <cmath>

// Physical constants
const float pi = 3.1416;
const float g = 9.806;       // m/s^2

// Quadcopter dimensions
const float m = 30.0e-3;    // kg
const float I_xx = 16.0e-6; // kg.m^2
const float I_yy = 16.0e-6; // kg.m^2
const float I_zz = 29.0e-6; // kg.m^2
const float l = 33.0e-3;    // m

//Constantes curve fit lab 2
const float a1 = 4.488e-12;
const float a2 = 1.16e-7;

//Constante curve fit lab 3
const float kl = 1.726e-8;

//Constante curve fit lab 4
const float kd = 1.301e-10;

//Constantes lab 7 (para os filtros passa alta e passa baixa)
const float f_corte = 0.1;
const float dt = 0.002;
const float alpha = (f_corte*dt)/(1 + f_corte*dt);

//Constantes lab 8 (ganhos do controlador regulador de estados)
const float os = 0.1/100; //ultrapassagem percentual que desejamos que o controlador tenha em relação ao set point (porcentagem/100)
const float t_s = 0.3; //tempo de acomodação do sistema (em segundos)

const float zeta = abs(log(os)) / (pow((log(os)*log(os) + pi*pi), 0.5));
const float w_n = 4/(zeta*t_s);

#endif