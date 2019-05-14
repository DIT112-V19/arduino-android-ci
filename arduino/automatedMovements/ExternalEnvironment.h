#pragma once

class ExternalEnvironment
{
public:
    virtual ~ExternalEnvironment() = default;

    virtual void delay(unsigned long milliseconds)                  = 0;
    virtual void pinMode(unsigned int pin, unsigned int mode)       = 0;
    virtual void digitalWrite(unsigned int pin, unsigned int state) = 0;
};