/*
 * can_signal.h
 *
 *  Created on: Feb 6, 2021
 *      Author: sam
 *
 *      functions to extract a signal from received CAN frame
 *      signal is limited to 16bit value, DAC is only 12bits so loss of resolution on larger values
 *      also have not seen CAN signal larger then 16bits
 */

#ifndef INC_CAN_SIGNAL_H_
#define INC_CAN_SIGNAL_H_

#include <stdint.h>
#include "device_sn.h"

#define SIGNAL_LITTLE_ENDIAN   	12
#define SIGNAL_BIG_ENDIAN      	21

#define ID_TYPE_11BIT			11
#define ID_TYPE_29BIT			29

#define TERMINATION_ON   		1
#define TERMINATION_OFF  		0

/* SPI Master Commands
 *   SPI communication between ESP8266 and STM32
 *     	- ESP8266 is master, STM32 is slave
 * 		- STM32 responds to ss pin low using EXTI, responding code is in HAL_GPIO_EXTI_Callback
 * 		- the below commands determine if STM32 is sending signal or updating signal
 */
#define SPI_SIGNAL_SEND			'?'
#define SPI_SIGNAL_RECEIVE		'='
#define SPI_SEND_SN				'N'
#define SPI_SEND_FW_VERSION		'F'
#define SPI_SEND_HW_VERSION		'H'
#define SPI_SEND_CAN_SIGNAL		'S'
#define SPI_SEND_DAC_VALUE		'D'
#define SPI_SEND_CAN_FRAME		'C'

/* signal status flag values */
#define SIGNAL_NO_CHANGE		0
#define SIGNAL_UPDATE			1

/* default values used in init */
#define CAN_BAUD				250 					/* CAN baud rate*/
#define CAN_ID	 				0x18EFB400 				/* CAN ID, supports 11-bit (standard) and 29-bit (extended) */
#define CAN_ID_TYPE 			ID_TYPE_29BIT			/* CAN ID bit len */
#define CAN_SIGNAL_ENDIAN		SIGNAL_LITTLE_ENDIAN	/* signal endianness */
#define CAN_SIGNAL_START_BIT	0 						/* bit that signal to convert to analog starts */
#define CAN_SIGNAL_BIT_LEN 		16 						/* bit length of signal to convert to analog */
#define CAN_SIGNAL_MAX			40000					/* max signal value, not necessarily max signal bit len */
#define CAN_SIGNAL_MIN			0						/* min signal value */

/* Big Endian shift lookup table by bit position
 * for example if bit position is 56, find index 56 in array and shift that amount*/
extern const uint8_t be_shift[64];

/* CAN signal data struct
 *  !this is the same exact struct on the ESP8266!
 *  For SPI bulk transmission of this struct to work these have to be the same (order and everything)
 *  If you update this be sure to update the ESP8266 struct as well */
typedef struct {
//	uint32_t sn;				/* stm32 SN used to set unique SSID per device */
	uint8_t  frame[8];			/* CAN frame data */
	uint16_t can_baud;			/* CAN baud rate in kbps */
	uint8_t  can_type;			/* ID type */
	uint32_t can_id;			/* CAN frame ID */
	uint8_t  start_bit;			/* signal start bit */
	uint8_t  bit_len;			/* signal bit length */
	uint8_t  endianness;		/* signal endianness */
	uint16_t max;				/* signal max value */
	uint16_t min;				/* signal min value */
	uint8_t term;				/* state of 120ohm terminator */
	uint16_t value;				/* signal value extracted from frame */
	uint64_t mask;				/* bit mask to use when getting signal from frame */
	uint16_t dac_out;			/* dac output value */
} Signal_Handle_t;

/* function prototypes */
void signal_init(Signal_Handle_t *hsignal);		/* initialize to default values */
void signal_update(Signal_Handle_t *hsignal);	/* new parameters, update calculated values */
void signal_calc(Signal_Handle_t *hsignal);		/* get signal from frame */

uint32_t map(uint32_t x, uint32_t in_min, uint32_t in_max, uint32_t out_min, uint32_t out_max);
void nibble_swap(uint64_t *val);

#endif /* INC_CAN_SIGNAL_H_ */
