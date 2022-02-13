#include "spi_master.h"

ESPMaster::ESPMaster(uint8_t ss_pin, uint8_t rdy_pin) {
  _ss_pin = ss_pin;
  _rdy_pin = rdy_pin;
}

void ESPMaster::begin() {
  digitalWrite(_ss_pin, HIGH);
  pinMode(_ss_pin, OUTPUT);

  pinMode(_rdy_pin, INPUT);

  SPI.begin();
}

void ESPMaster::write(uint8_t *pData, uint16_t len) {
  SPI.beginTransaction(SPISettings(SPI_BAUD, MSBFIRST, SPI_MODE0));
  digitalWrite(_ss_pin, LOW);

  /* wait for STM32 to pull ready pin low */
  uint32_t polling_start = millis();
  while (digitalRead(_rdy_pin) == HIGH) {
    if ((millis() - polling_start) >= TIMEOUT_ms) {
      Serial.println(F("SPI timeout while waiting for ready signal from STM32"));
      digitalWrite(_ss_pin, HIGH);
      return;
    }
  }
  
  delayMicroseconds(SPI_DELAY_us);
  SPI.transfer(SPI_SIGNAL_WRITE); /* signal esp8266 wants to write data */

  for(uint16_t i=0; i<len; i++) {
    delayMicroseconds(SPI_DELAY_us);
    SPI.transfer(*pData);
    pData++;
  }
  
  digitalWrite(_ss_pin, HIGH);
  SPI.endTransaction();
}

void ESPMaster::write(uint8_t cmd_char, uint8_t *pData, uint16_t len) {
  SPI.beginTransaction(SPISettings(SPI_BAUD, MSBFIRST, SPI_MODE0));
  digitalWrite(_ss_pin, LOW);

  /* wait for STM32 to pull ready pin low */
  uint32_t polling_start = millis();
  while (digitalRead(_rdy_pin) == HIGH) {
    if ((millis() - polling_start) >= TIMEOUT_ms) {
      Serial.println(F("SPI timeout while waiting for ready signal from STM32"));
      digitalWrite(_ss_pin, HIGH);
      return;
    }
  }

  delayMicroseconds(SPI_DELAY_us);
  SPI.transfer(cmd_char);               /* signal what data esp8266 wants to write */

  for(uint16_t i=0; i<len; i++) {
    delayMicroseconds(SPI_DELAY_us);
    SPI.transfer(*pData);
    pData++;
  }
  
  digitalWrite(_ss_pin, HIGH);
  SPI.endTransaction();
}

void ESPMaster::read(uint8_t *pData, uint16_t len) {
  SPI.beginTransaction(SPISettings(SPI_BAUD, MSBFIRST, SPI_MODE0));
  digitalWrite(_ss_pin, LOW);

  /* wait for STM32 to pull ready pin low */
  uint32_t polling_start = millis();
  while (digitalRead(_rdy_pin) == HIGH) {
    if ((millis() - polling_start) >= TIMEOUT_ms) {
      Serial.println(F("SPI timeout while waiting for ready signal from STM32"));
      digitalWrite(_ss_pin, HIGH);
      return;
    }
  }
  
  delayMicroseconds(SPI_DELAY_us);
  SPI.transfer(SPI_SIGNAL_READ); /* signal esp8266 wants to read data */

  for(uint16_t i=0; i<len; i++) {
    delayMicroseconds(SPI_DELAY_us);
    *pData = SPI.transfer(0);
    pData++;
  }
  
  digitalWrite(_ss_pin, HIGH);
  SPI.endTransaction();
}

void ESPMaster::read(uint8_t cmd_char, uint8_t *pData, uint16_t len) {
  SPI.beginTransaction(SPISettings(SPI_BAUD, MSBFIRST, SPI_MODE0));
  digitalWrite(_ss_pin, LOW);

  /* wait for STM32 to pull ready pin low */
  uint32_t polling_start = millis();
  while (digitalRead(_rdy_pin) == HIGH) {
    if ((millis() - polling_start) >= TIMEOUT_ms) {
      Serial.println(F("SPI timeout while waiting for ready signal from STM32"));
      digitalWrite(_ss_pin, HIGH);
      return;
    }
  }
  
  delayMicroseconds(SPI_DELAY_us);
  SPI.transfer(cmd_char); /* signal esp8266 wants to read data */

  for(uint16_t i=0; i<len; i++) {
    delayMicroseconds(SPI_DELAY_us);
    *pData = SPI.transfer(0);
    pData++;
  }
  
  digitalWrite(_ss_pin, HIGH);
  SPI.endTransaction();
}