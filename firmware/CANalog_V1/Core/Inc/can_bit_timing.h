/*
 * can_bit_timing.h
 *
 *  Created on: Feb 6, 2021
 *      Author: sam
 *
 *      Timing values from: http://www.bittiming.can-wiki.info/
 *      	ST Microelectronigs bxCAN
 *      	Clock Rate: 32Mhz
 *
 *      All timings are preferred values, ie 16 time quanta
 */

#ifndef INC_CAN_BIT_TIMING_H_
#define INC_CAN_BIT_TIMING_H_

#include "can.h"
#include "can_signal.h"

#include <stdint.h>

/* CAN baud rates */
#define BAUD_RATE_10kbps	10
#define BAUD_RATE_20kbps	20
#define BAUD_RATE_50kbps	50
#define BAUD_RATE_83kbps	83
#define BAUD_RATE_100kbps	100
#define BAUD_RATE_125kbps	125
#define BAUD_RATE_250kbps	250
#define BAUD_RATE_500kbps	500
#define BAUD_RATE_800kbps	800
#define BAUD_RATE_1000kbps	1000

/* CAN_BTR register value for specific bit timing */
#define CAN_BTR_1000kbps 	0x001c0001
#define CAN_BTR_800kbps		0x00070003
#define CAN_BTR_500kbps		0x001c0003
#define CAN_BTR_250kbps		0x001c0007
#define CAN_BTR_125kbps		0x001c000f
#define CAN_BTR_100kbps		0x001c0013
#define CAN_BTR_83kbps		0x001c0017
#define CAN_BTR_50kbps		0x001c0027
#define CAN_BTR_20kbps		0x001c0063
#define CAN_BTR_10kbps		0x001c00c7

typedef struct {
	  uint32_t Prescaler;
	  uint32_t SyncJumpWidth;
	  uint32_t TimeSeg1;
	  uint32_t TimeSeg2;
} BitTiming_Handle_t;

extern const BitTiming_Handle_t bitRate_10kbps;
extern const BitTiming_Handle_t bitRate_20kbps;
extern const BitTiming_Handle_t bitRate_50kbps;
extern const BitTiming_Handle_t bitRate_83kbps;
extern const BitTiming_Handle_t bitRate_100kbps;
extern const BitTiming_Handle_t bitRate_125kbps;
extern const BitTiming_Handle_t bitRate_250kbps;
extern const BitTiming_Handle_t bitRate_500kbps;
extern const BitTiming_Handle_t bitRate_800kbps;
extern const BitTiming_Handle_t bitRate_1000kbps;

/* function prototypes */
void can_set_bit_timing(Signal_Handle_t *hsignal, CAN_HandleTypeDef *hcan);

#endif /* INC_CAN_BIT_TIMING_H_ */
