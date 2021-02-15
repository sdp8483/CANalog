#include "spi_master.h"

ESPMaster::ESPMaster(uint8_t ss_pin) {
  _ss_pin = ss_pin;
}

void ESPMaster::begin() {
  digitalWrite(_ss_pin, HIGH);
  pinMode(_ss_pin, OUTPUT);

  SPI.begin();
}

void ESPMaster::write(uint8_t *pData, uint16_t len) {
  SPI.beginTransaction(SPISettings(SPI_BAUD, MSBFIRST, SPI_MODE0));
  digitalWrite(_ss_pin, LOW);
  
  delayMicroseconds(SPI_DELAY_us);
  SPI.transfer(SPI_COMMAND_WRITE); /* signal esp8266 wants to read data */

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
  
  delayMicroseconds(SPI_DELAY_us);
  SPI.transfer(SPI_COMMAND_READ); /* signal esp8266 wants to read data */

  for(uint16_t i=0; i<len; i++) {
    delayMicroseconds(SPI_DELAY_us);
    *pData = SPI.transfer(0);
    pData++;
  }
  
  digitalWrite(_ss_pin, HIGH);
  SPI.endTransaction();
}