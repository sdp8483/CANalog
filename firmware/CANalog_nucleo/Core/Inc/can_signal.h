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

#define SIGNAL_LITTLE_ENDIAN   12
#define SIGNAL_BIG_ENDIAN      21

#define ID_TYPE_11BIT	0
#define ID_TYPE_29BIT	1

/* default values used in init */
#define CAN_BAUD				250 					/* CAN baud rate*/
#define CAN_ID	 				0x18EFB300 				/* CAN ID, supports 11-bit (standard) and 29-bit (extended) */
#define CAN_ID_TYPE 			ID_TYPE_29BIT			/* CAN ID bit len */
#define CAN_SIGNAL_ENDIAN		SIGNAL_LITTLE_ENDIAN	/* signal endianness */
#define CAN_SIGNAL_START_BIT	0 						/* bit that signal to convert to analog starts */
#define CAN_SIGNAL_BIT_LEN 		16 						/* bit length of signal to convert to analog */
#define CAN_SIGNAL_MAX			40000					/* max signal value, not necessarily max signal bit len */
#define CAN_SIGNAL_MIN			0						/* min signal value */

/* CAN Signal handle typedef */
typedef struct {
	uint8_t frame[8];			/* CAN frame data */
	uint16_t can_baud;			/* CAN baud rate in kbps */
	uint32_t can_id;			/* CAN frame ID */
	uint8_t can_type;			/* ID type */
	uint8_t endianness;			/* signal endianness */
	uint8_t start_bit;			/* signal start bit */
	uint8_t bit_len;			/* signal bit length */
	uint16_t value;				/* signal value extracted from frame */
	uint16_t max;				/* signal max value */
	uint16_t min;				/* signal min value */
	uint64_t mask;				/* bit mask to use when getting signal from frame */
	uint16_t dac_out;			/* dac output value */
} Signal_Handle_t;

/* function prototypes */
void signal_init(Signal_Handle_t *hsignal);		/* initialize to default values */
void signal_reInit(Signal_Handle_t *hsignal);	/* new parameters, update calculated values */
uint32_t map(uint32_t x, uint32_t in_min, uint32_t in_max, uint32_t out_min, uint32_t out_max);
void signal_calc(Signal_Handle_t *hsignal);		/* get signal from frame */


#endif /* INC_CAN_SIGNAL_H_ */
