/*
 * can_signal.c
 *
 *  Created on: Feb 6, 2021
 *      Author: sam
 */

#include "can_signal.h"

/* initialize signal handle with default values at startup */
void signal_init(Signal_Handle_t *hsignal) {

	hsignal->sn = calc_sn();
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

	hsignal->sn = calc_sn();	/* esp could send wrong sn so get it again */

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

        temp = temp >> (64 - (hsignal->start_bit + hsignal->bit_len));
	}

	temp &= hsignal->mask;

	hsignal->value = (uint16_t) temp;

	hsignal->dac_out = (uint16_t) map(hsignal->value, hsignal->min, hsignal->max, 0, 4095);
}
