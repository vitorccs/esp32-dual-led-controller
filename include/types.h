#include <Arduino.h>

#ifndef TYPES_H
#define TYPES_H
struct RelayStates {
    bool relay1;
    bool relay2;
};
#endif // TYPES_H

typedef std::function<RelayStates()> LedStateFn;
typedef std::function<void()> LedCycleFn;
typedef std::function<void(bool)> LedToggleFn;
typedef std::function<void(bool)> LedOnFn;
typedef std::function<void(bool)> LedOffFn;