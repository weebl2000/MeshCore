#pragma once

#include <Arduino.h>
#include <helpers/ESP32Board.h>

// LILYGO T-LoRa / T3 LoRa32 board with SX1276
class LilyGoTLoraBoard : public ESP32Board {
public:
  const char* getManufacturerName() const override {
#ifdef BOARD_MANUFACTURER_NAME
    return BOARD_MANUFACTURER_NAME;
#else
    return "LILYGO T-LoRa V2.1-1.6";
#endif
  }

  uint16_t getBattMilliVolts() override {
    analogReadResolution(12);

    uint32_t raw = 0;
    for (int i = 0; i < 8; i++) {
      raw += analogReadMilliVolts(PIN_VBAT_READ);
    }
    raw = raw / 8;

    return (2 * raw);
  }
};