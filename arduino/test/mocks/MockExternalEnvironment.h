#pragma once

#include "ExternalEnvironment.h"
#include "gmock/gmock.h"

class MockExternalEnvironment : public ExternalEnvironment
{
public:
    MOCK_METHOD1(delay, void(unsigned long milliseconds));
    MOCK_METHOD2(pinMode, void(unsigned int pin, unsigned int mode));
    MOCK_METHOD2(digitalWrite, void(unsigned int pin, unsigned int state));
};