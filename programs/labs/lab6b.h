#include "mbed.h"
#include "crazyflie.h"

Mixer mixer; //definicao de uma objeto chamado mixer, pertencente à classe Mixer

int main(){
    mixer.arm();
    mixer.actuate(0.9*m*g, 0, 0, 0);
    wait(0.5);
    mixer.disarm(); //NAO ESTA FUNCIONANDO
    while(true){}
}