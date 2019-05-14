#pragma once

#include "RotateableVehicle.h"
#include <Smartcar.h>

class SmartCarRotateableVehicle : public RotateableVehicle
{
public:
    SmartCarRotateableVehicle(SmartCar& smartcar)
        : mSmartcar{smartcar}
    {
    }

    inline void enableCruiseControl() override
    {
        mSmartcar.enableCruiseControl();
    }

    inline void setSpeed(float speed) override
    {
        mSmartcar.setSpeed(speed);
    }

    inline void setAngle(int angle) override
    {
        mSmartcar.setAngle(angle);
    }

    inline void update() override
    {
        mSmartcar.update();
    }

    inline unsigned int getHeading() override
    {
        return mSmartcar.getHeading();
    }

    inline long getDistance() override
    {
        return mSmartcar.getDistance();
    }

private:
    SmartCar& mSmartcar;
};
