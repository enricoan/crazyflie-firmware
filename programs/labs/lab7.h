# include "mbed.h"
# include "crazyflie.h"
# include "USBSerial.h"

// Define serial object
USBSerial serial;

//Definição do comando que pode ser enviado para o programa através da serial
char command;

// Define attitude estimator object
AttitudeEstimator att_est;

// Define Ticker objects
Ticker tic;

//Define Interrupt flag and counter variables
bool flag;

//Define Callback functions
void callback(){flag = true;}

int main (){
    //Função de inicialização do objeto "att_est", pertencente à classe AttitudeEstimator
    att_est.init();
    // Initialize interrupt
    tic.attach(& callback,dt);
    while (true){
        //estimar atitude
        if (flag){
            flag = false;
            att_est.estimate();
            }
        //imprimir atitude na serial
        if (serial.readable()){
            command = serial.getc();
            if (command == 'p'){
                serial.printf("%f,%f,%f\n", att_est.phi, att_est.theta, att_est.psi);
                }
            }
        }
    }