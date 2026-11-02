// week09_1
// Maker UNO: turn ON the onboard BUZZER slide switch.
// Board selection: Arduino Uno / ATmega328P / 16 MHz.
// This sketch uses the local modified PCM.cpp, NOT the original D11 library.
#include "PCM.h"
#include "sounddata.h"

void setup() {
  startPlayback(sounddata_data, sounddata_length);
}

void loop() {
  // One-shot sample plays for 1 second. Press RESET to play again.
}
