#pragma once

class RotateableVehicle
{
public:
    virtual ~RotateableVehicle() = default;

    virtual void enableCruiseControl() = 0;
    virtual void setSpeed(float speed) = 0;
    virtual void setAngle(int angle)   = 0;
    virtual void update()              = 0;
    virtual unsigned int getHeading()  = 0;
    virtual long getDistance()         = 0;
};