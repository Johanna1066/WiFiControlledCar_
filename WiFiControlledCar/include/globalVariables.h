#ifndef _WCC_GLOBALVARIABLES_H
#define _WCC_GLOBALVARIABLES_H
#include <vector>

#include "Motors/engine.h"
#include "Motors/steeringServo.h"
#include "Sensors/usSensor.h"

namespace globalVariables
{
    std::vector<Engine> engines;
    Engine rightEngine(A1, D6, D5);
    Engine leftEngine(A2, D4, D3);
    SteeringServo servo(9);
    const int safeServoDistance{20};


    SemaphoreHandle_t engineHandle;
    SemaphoreHandle_t servoHandle;

    USsensor sensor(D8, D7);
    bool hinderForwardMovement = false;

    int reading{};
    int dataRecieved{};

}

#endif //_WCC_GLOBALVARIABLES_H
