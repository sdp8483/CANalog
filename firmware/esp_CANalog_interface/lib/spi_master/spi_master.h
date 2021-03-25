#ifndef INC_SPI_MASTER_H_
#define INC_SPI_MASTER_H_

#include <Arduino.h>
#include <SPI.h>

#define SPI_SIGNAL_READ     '?'         /* send as first byte in SPI transmission to signal STM32 to return 'signal' data */
#define SPI_SIGNAL_WRITE    '='         /* send as first byte in SPI transmission to signal STM32 that incoming data is new 'signal' data */
#define SPI_GET_FW_VERSION	'F'         /* send as first byte in SPI transmission to signal STM32 to return firmware version string */
#define SPI_GET_HW_VERSION	'H'         /* send as first byte in SPI transmission to signal STM32 to return firmware version string */
#define SPI_GET_CAN_SIGNAL  'S'         /* send as first byte in SPI transmission to signal STM32 to return CAN signal value */
#define SPI_GET_DAC_VALUE   'D'

#define SPI_DELAY_us        10          /* delay for uS before each SPI.transmit to allow STM32 time to catch up, STM32 needs a few uS between bytes */
#define SPI_BAUD            500000UL    /* SPI clock baud rate in Mbits/sec */

#define TIMEOUT_ms          10          /* if rdy pins is not pulled low after timout period error out */

class ESPMaster {
  private:
    uint8_t _ss_pin;                    /* chip select pin, signal STM32 want to talk */
    uint8_t _rdy_pin;                   /* ready input, STM32 will pull low when ready to respond */

  public:
    ESPMaster(uint8_t ss_pin, uint8_t rdy_pin);
    void begin();
    void write(uint8_t *pData, uint16_t len);
    void read(uint8_t *pData, uint16_t len);
    void read(uint8_t cmd_char, uint8_t *pData, uint16_t len);
};

#endif