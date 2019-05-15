#pragma once

#include "RotateableVehicle.h"

class AutomatedMover
{
public:
    AutomatedMover(RotateableVehicle& rotateableVehicle);

    /**
       Rotate the car at the specified degrees with the certain speed
       @param degrees   The degrees to turn. Positive values for clockwise
                        negative for counter-clockwise.
       @param speed     The speed to turn
    */
    void rotate(int degrees, float speed);

    /**
       Makes the car travel at the specified distance with a certain speed
       @param centimeters   How far to travel in centimeters, positive for
                            forward and negative values for backward
       @param speed         The speed to travel
    */
    void go(long centimeters, float speed);

private:
    RotateableVehicle& mRotateableVehicle;
};
