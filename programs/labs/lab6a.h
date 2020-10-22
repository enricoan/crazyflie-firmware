#include "mbed.h"
#include "crazyflie.h"

Mixer mixer; //definicao de uma objeto chamado mixer, pertencente à classe Mixer

int main(){
    mixer.actuate(0.3*m*g, 0, 0, 0);
    wait(2);
    mixer.actuate(0, 0, 0, 0);
    while(true){}
}