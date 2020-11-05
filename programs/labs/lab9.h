#include "mbed.h"
#include "crazyflie.h"
#include "USBSerial.h"

// USB serial object
USBSerial serial;

// Crazyflie controller objects
AttitudeEstimator att_est;
VerticalEstimator ver_est;

// Define ticker
Ticker tic;
Ticker tic_range;

// Define interrupt flags
bool flag;
bool flag_range = false;

// Define callback functions
void callback() {flag = true;}
void callback_range() {flag_range = true;}

// Main program
int main (){
    // Initialize estimator objects
    att_est.init();
    ver_est.init();
    // Initialize interrupts
    tic.attach(& callback, dt);
    tic_range.attach(& callback_range, dt_range);
    while(true){
        if(flag){
            flag = false;
            att_est.estimate();
            ver_est.predict(0.0);
            if (flag_range){
                flag_range = false;
                ver_est.correct(att_est.phi, att_est.theta);
                serial.printf("z[m]:%6.2f|w[m/s]:%6.2f\n", ver_est.z, ver_est.w);
            }
        }
    }
}