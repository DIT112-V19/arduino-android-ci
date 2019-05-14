#pragma once

#include "ExternalEnvironment.h"
#include <Arduino.h>

class ArduinoExternalEnvironment : public ExternalEnvironment
{
public:
    inline void delay(unsigned long milliseconds) override
    {
        delay(milliseconds);
    }

    inline void pinMode(unsigned int pin, unsigned int mode) override
    {
        pinMode(pin, mode);
    }

    inline void digitalWrite(unsigned int pin, unsigned int state) override
    {
        digitalWrite(pin, state);
    }
};