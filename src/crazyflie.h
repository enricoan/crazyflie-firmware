#ifndef crazyflie_h
#define crazyflie_h

// Crazyflie utility variables
#include "utils/pin_names.h"
#include "utils/parameters.h"

// Crazyflie 2.1 hardware abstraction layer
#include "drivers/bmi088.h"     // IMU sensor
#include "drivers/vl53l1x.h"    // Range sensor
#include "drivers/pmw3901.h"    // Optical flow sensor

//classes de estimadores e controladores
#include "modules/mixer.h"

#include "modules/attitude_estimator.h"
#include "modules/attitude_controller.h"

#include "modules/vertical_estimator.h"
#include "modules/vertical_controller.h"

#include "modules/horizontal_estimator.h"
#include "modules/horizontal_controller.h"

#endif
