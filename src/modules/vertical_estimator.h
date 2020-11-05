#ifndef vertical_estimator_h
#define vertical_estimator_h

#include "mbed.h"
#include "crazyflie.h"

// Vertical estimator class
class VerticalEstimator{
    public:
        // Class constructor
        VerticalEstimator ();

        // Initialize class
        void init ();

        // Predict vertical position and velocity from model
        void predict (float f_t);

        // Correct vertical position and velocity with measurement
        void correct (float phi, float theta);

        //Estimativa da posição e velocidade verticais em, respectivamente, m e m/s
        float z, w;

    private:
        // Range sensor object
        VL53L1X range;
};
#endif