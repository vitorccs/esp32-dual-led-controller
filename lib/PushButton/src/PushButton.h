#ifndef PUSH_BUTTON_H
#define PUSH_BUTTON_H
#include <Arduino.h>
#include "types.h"

class PushButton
{
public:
    void init(LedCycleFn toggleFn, uint8_t pin);
    void wasPushed();

private:
    LedCycleFn ledCycleFn;
    uint8_t buttonPin;
    bool lastButtonState = LOW;
};

#endif