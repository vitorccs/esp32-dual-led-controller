#include <LedRelay.h>

void LedRelay::cycle()
{
  if (!state1 && !state2)
  {
    state1 = true;
    state2 = false;
  }
  else if (state1 && !state2)
  {
    state1 = false;
    state2 = true;
  }
  else if (!state1 && state2)
  {
    state1 = true;
    state2 = true;
  }
  else
  {
    state1 = false;
    state2 = false;
  }
}

void LedRelay::toggle(bool first)
{
  if (first)
  {
    state1 = !state1;
  }
  else
  {
    state2 = !state2;
  }
}

void LedRelay::turnOn(bool first)
{
  if (first)
  {
    state1 = true;
  }
  else
  {
    state2 = true;
  }
}

void LedRelay::turnOff(bool first)
{
  if (first)
  {
    state1 = false;
  }
  else
  {
    state2 = false;
  }
}

void LedRelay::turnOnAll()
{
  state1 = true;
  state2 = true;
}

void LedRelay::turnOffAll()
{
  state1 = false;
  state2 = false;
}
