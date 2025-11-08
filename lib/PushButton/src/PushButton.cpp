#include <PushButton.h>

void PushButton::init(LedCycleFn cycleFn, uint8_t btnPin)
{
  ledCycleFn = cycleFn;
  buttonPin = btnPin;

  pinMode(buttonPin, INPUT_PULLUP);
}

void PushButton::wasPushed()
{
  int reading = digitalRead(buttonPin);
  bool btnPressed = reading == LOW;
  bool stateChanged = lastButtonState == HIGH;

  if (btnPressed && stateChanged)
  {
    ledCycleFn();
  }

  lastButtonState = reading;
}