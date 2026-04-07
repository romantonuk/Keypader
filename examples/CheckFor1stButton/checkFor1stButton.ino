#include "keypader.h"
uint8_t keypadColumnsPins[4] = {2, 3, 4, 5};
uint8_t keypadRowsPins[4] = {6, 7, 8, 9};
uint8_t keypadSize[] = {4, 4};
using namespace keypader;
using namespace DefaultSoftDrivers_keypad;
DefaultSoftDrivers_keypad::DirectPinsSoft_keypad n = DefaultSoftDrivers_keypad::DirectPinsSoft_keypad(keypadColumnsPins, keypadRowsPins, keypadSize);

void setup() {
  Serial.begin(9600);
  n.setupPinsPullup();
}

void loop() {
  Serial.println(keypader::isPressed(n, 0, 0), BIN);
}
