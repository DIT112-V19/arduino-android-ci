#pragma once

#include "RotateableVehicle.h"
#include "gmock/gmock.h"

class MockRotateableVehicle : public RotateableVehicle
{
public:
    MOCK_METHOD0(enableCruiseControl, void());
    MOCK_METHOD1(setSpeed, void(float speed));
    MOCK_METHOD1(setAngle, void(int angle));
    MOCK_METHOD0(update, void());
    MOCK_METHOD0(getHeading, unsigned int());
    MOCK_METHOD0(getDistance, long());
};