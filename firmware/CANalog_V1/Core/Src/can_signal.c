/*
 * can_signal.c
 *
 *  Created on: Feb 6, 2021
 *      Author: sam
 */

#include "can_signal.h"

/* Big Endian shift lookup table by bit position */
const uint8_t be_shift[64] = {56, 57, 58, 59, 60, 61, 62, 63,
					          48, 49, 50, 51, 52, 53, 54, 55,
							  40, 41, 42, 43, 44, 45, 46, 47,
							  32, 33, 34, 35, 36, 37, 38, 39,
							  24, 25, 26, 27, 28, 29, 30, 31,
							  16, 17, 18, 19, 20, 21, 22, 23,
							   8,  9, 10, 11, 12, 13, 14, 15,
							   0,  1,  2,  3,  4,  5,  6,  7};

/* initialize signal handle with default values at startup */
void signal_init(Signal_Handle_t *hsignal) {

//	hsignal->sn = calc_sn();
	hsignal->can_baud = CAN_BAUD;
	hsignal->can_id = CAN_ID;
	hsignal->can_type = CAN_ID_TYPE;
	hsignal->endianness = CAN_SIGNAL_ENDIAN;
	hsignal->start_bit = CAN_SIGNAL_START_BIT;
	hsignal->bit_len = CAN_SIGNAL_BIT_LEN;
	hsignal->max = CAN_SIGNAL_MAX;
	hsignal->min = CAN_SIGNAL_MIN;
	hsignal->dac_out = 0;
	hsignal->term = TERMINATION_OFF;

	HAL_GPIO_WritePin(CAN_TERM_GPIO_Port, CAN_TERM_Pin, GPIO_PIN_RESET);

	hsignal->mask = 0;
	for (uint8_t i=0; i<hsignal->bit_len; i++) {
		hsignal->mask += 1ULL << i;
	}
}

/* new parameters were received, update calculated values */
void signal_update(Signal_Handle_t *hsignal) {

//	hsignal->sn = calc_sn();	/* esp could send wrong sn so get it again */

	if (hsignal->term == TERMINATION_ON) {
		HAL_GPIO_WritePin(CAN_TERM_GPIO_Port, CAN_TERM_Pin, GPIO_PIN_SET);
	} else {
		HAL_GPIO_WritePin(CAN_TERM_GPIO_Port, CAN_TERM_Pin, GPIO_PIN_RESET);
	}

	hsignal->mask = 0;
	for (uint8_t i=0; i<hsignal->bit_len; i++) {
		hsignal->mask += 1ULL << i;
	}
}

uint32_t map(uint32_t x, uint32_t in_min, uint32_t in_max, uint32_t out_min, uint32_t out_max) {
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;;
}

void nibble_swap(uint64_t *val) {
	uint64_t high_nibbles = (*val >> 4) & 0x0F0F0F0F0F0F0F0F;
	uint64_t low_nibbles  = (*val)      & 0x0F0F0F0F0F0F0F0F;

	*val = (low_nibbles << 4) | high_nibbles;
}

/* get signal from frame and set DAC output */
void signal_calc(Signal_Handle_t *hsignal) {
	uint64_t temp = 0;

	if (hsignal->endianness == SIGNAL_LITTLE_ENDIAN) {
		for (uint8_t i=0; i<sizeof(hsignal->frame); i++) {
			temp += ((uint64_t) hsignal->frame[i] << (i * 8));
		}

		temp = temp >> hsignal->start_bit;
	} else {
        for(uint8_t i=0; i<sizeof(hsignal->frame); i++) {
        	temp += ((uint64_t)hsignal->frame[i] << (56 - (i * 8)));
        }

        /* swap nibbles for signals that are not 8 bit aligned */
        nibble_swap(&temp);

        /* shift to signal data */
        temp = temp >> be_shift[hsignal->start_bit];

        /* return nibbles to original position */
        nibble_swap(&temp);
	}

	temp &= hsignal->mask;

	hsignal->value = (uint16_t) temp;

	hsignal->dac_out = (uint16_t) map(hsignal->value, hsignal->min, hsignal->max, 0, 4095);
}
