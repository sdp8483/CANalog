#ifndef INC_SPI_MASTER_H_
#define INC_SPI_MASTER_H_

#include <Arduino.h>
#include <SPI.h>

/* characters sent as first byte in SPI transmission to signal STM32 what to do */
#define SPI_SIGNAL_READ     '?'         /* read 'signal' data from stm32 */
#define SPI_SIGNAL_WRITE    '='         /* write 'signal' data to stm32 */
#define SPI_GET_SN          'N'         /* read SN from STM32 */
#define SPI_GET_FW_VERSION	'F'         /* read firmware version string */
#define SPI_GET_HW_VERSION	'H'         /* read firmware version string */
#define SPI_GET_CAN_SIGNAL  'S'         /* read CAN signal value */
#define SPI_GET_DAC_VALUE   'D'         /* read dac value */
#define SPI_GET_CAN_FRAME   'C'         /* read CAN frame data */

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