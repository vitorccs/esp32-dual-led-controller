#ifndef LED_RELAY_H
#define LED_RELAY_H
#include <Arduino.h>
#include "types.h"

class LedRelay
{
public:
    bool state1 = false;
    bool state2 = false;
    void cycle();
    void toggle(bool first);
    void turnOn(bool first);
    void turnOff(bool first);
    void turnOnAll();
    void turnOffAll();
    void wasPushed();
};

#endif