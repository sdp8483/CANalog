#ifndef INC_SPI_MASTER_H_
#define INC_SPI_MASTER_H_

#include <Arduino.h>
#include <SPI.h>

#define SPI_COMMAND_READ    '?'         /* send as first byte in SPI transmission to signal STM32 to return 'signal' data */
#define SPI_COMMAND_WRITE   '='         /* send as first byte in SPI transmission to signal STM32 that incoming data is new 'signal' data */

#define SPI_DELAY_us        10          /* delay for uS before each SPI.transmit to allow STM32 time to catch up, STM32 needs a few uS between bytes */
#define SPI_BAUD            500000UL    /* SPI clock baud rate in Mbits/sec */

class ESPMaster {
  private:
    uint8_t _ss_pin;

  public:
    ESPMaster(uint8_t ss_pin);
    void begin();
    void write(uint8_t *pData, uint16_t len);
    void read(uint8_t *pData, uint16_t len);
};

#endif