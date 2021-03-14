#ifndef INC_CAN_SIGNAL_H_
#define INC_CAN_SIGNAL_H_

#include <Arduino.h>

/* Signal Defines */
#define SIGNAL_LITTLE_ENDIAN    12
#define SIGNAL_BIG_ENDIAN      	21

#define ID_TYPE_11BIT			11
#define ID_TYPE_29BIT			29

#define SIGNAL_STRUCTS_ARE_EQUAL  0

/* CAN signal data struct 
 *  !this is the same exact struct on the STM32!
 *  For SPI bulk transmission of this struct to work these have to be the same (order and everything)
 *  If you update this be sure to update the STM32 struct as well */
typedef struct {
  uint32_t sn;                  /* stm32 SN used to set unique SSID per device */
  uint8_t  frame[8];            /* CAN frame data */
  uint16_t can_baud;            /* CAN baud rate in kbps */
  uint8_t  can_type;            /* ID type */
  uint32_t can_id;              /* CAN frame ID */
  uint8_t  start_bit;           /* signal start bit */
  uint8_t  bit_len;             /* signal bit length */
  uint8_t  endianness;          /* signal endianness */
  uint16_t max;                 /* signal max value */
  uint16_t min;                 /* signal min value */
  uint16_t value;               /* signal value extracted from frame */
  uint64_t mask;                /* bit mask to use when getting signal from frame */
  uint16_t dac_out;             /* dac output value */
} Signal_Handle_t;

/* function prototypes */
void printData(Signal_Handle_t *pData);
uint8_t signal_struct_cmp(Signal_Handle_t *pData1, Signal_Handle_t *pData2);

#endif