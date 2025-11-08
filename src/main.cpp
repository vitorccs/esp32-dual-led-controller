#include <Arduino.h>
#include <NoDelay.h>
#include <HttpServer.h>
#include <WifiHandler.h>
#include <LedRelay.h>
#include <PushButton.h>
#include "types.h"

#define RELAY_PIN_1 1
#define RELAY_PIN_2 0
#define LED_PIN_1 3
#define LED_PIN_2 4
#define BUTTON_PIN 10
#define WIFI_SSID "MY_SSID"
#define WIFI_PWD "MY_PASSWORD"

HttpServer httpServer;
WifiHandler wifiHandler;
PushButton pushButton;
LedRelay ledRelay;
noDelay wifiTimer;
noDelay btnBounceTimer;

void updateRelayPins()
{
  digitalWrite(RELAY_PIN_1, ledRelay.state1);
  digitalWrite(LED_PIN_1, ledRelay.state1);

  digitalWrite(RELAY_PIN_2, ledRelay.state2);
  digitalWrite(LED_PIN_2, ledRelay.state2);

  Serial.print("Relay ");
  Serial.print(ledRelay.state1 ? "ON" : "OFF");
  Serial.print("|");
  Serial.println(ledRelay.state2 ? "ON" : "OFF");
}

void setup()
{
  Serial.begin(115200);

  pinMode(RELAY_PIN_1, OUTPUT);
  pinMode(RELAY_PIN_2, OUTPUT);
  pinMode(LED_PIN_1, OUTPUT);
  pinMode(LED_PIN_2, OUTPUT);

  LedStateFn relayState = [&]
  {
    return RelayStates{ledRelay.state1, ledRelay.state2};
  };

  LedCycleFn cycleLed = [&]
  {
    ledRelay.cycle();
    updateRelayPins();
  };

  LedToggleFn toggleLed = [&](bool first)
  {
    ledRelay.toggle(first);
    updateRelayPins();
  };

  LedOnFn ledTurnOn = [&](bool first)
  {
    ledRelay.turnOn(first);
    updateRelayPins();
  };

  LedOffFn ledTurnOff = [&](bool first)
  {
    ledRelay.turnOff(first);
    updateRelayPins();
  };

  updateRelayPins();

  pushButton.init(cycleLed, BUTTON_PIN);

  wifiHandler.connect(WIFI_SSID, WIFI_PWD);

  httpServer.init(ledTurnOn, ledTurnOff, toggleLed, cycleLed, relayState);

  wifiTimer.setdelay(5000);
  btnBounceTimer.setdelay(100);
}

void loop()
{
  if (btnBounceTimer.update())
  {
    pushButton.wasPushed();
  }

  if (wifiTimer.update())
  {
    wifiHandler.reconnect();
  }
}
