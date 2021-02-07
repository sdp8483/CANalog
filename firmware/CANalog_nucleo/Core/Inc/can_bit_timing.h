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

#include <stdint.h>

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

const BitTiming_Handle_t bitRate_10kbps = {
		.Prescaler = 200,
		.SyncJumpWidth = CAN_SJW_1TQ,
		.TimeSeg1 = CAN_BS1_13TQ,
		.TimeSeg2 = CAN_BS2_2TQ
};

const BitTiming_Handle_t bitRate_20kbps = {
		.Prescaler = 100,
		.SyncJumpWidth = CAN_SJW_1TQ,
		.TimeSeg1 = CAN_BS1_13TQ,
		.TimeSeg2 = CAN_BS2_2TQ
};

const BitTiming_Handle_t bitRate_50kbps = {
		.Prescaler = 40,
		.SyncJumpWidth = CAN_SJW_1TQ,
		.TimeSeg1 = CAN_BS1_13TQ,
		.TimeSeg2 = CAN_BS2_2TQ
};

const BitTiming_Handle_t bitRate_83kbps = {
		.Prescaler = 24,
		.SyncJumpWidth = CAN_SJW_1TQ,
		.TimeSeg1 = CAN_BS1_13TQ,
		.TimeSeg2 = CAN_BS2_2TQ
};

const BitTiming_Handle_t bitRate_100kbps = {
		.Prescaler = 20,
		.SyncJumpWidth = CAN_SJW_1TQ,
		.TimeSeg1 = CAN_BS1_13TQ,
		.TimeSeg2 = CAN_BS2_2TQ
};

const BitTiming_Handle_t bitRate_125kbps = {
		.Prescaler = 16,
		.SyncJumpWidth = CAN_SJW_1TQ,
		.TimeSeg1 = CAN_BS1_13TQ,
		.TimeSeg2 = CAN_BS2_2TQ
};

const BitTiming_Handle_t bitRate_250kbps = {
		.Prescaler = 8,
		.SyncJumpWidth = CAN_SJW_1TQ,
		.TimeSeg1 = CAN_BS1_13TQ,
		.TimeSeg2 = CAN_BS2_2TQ
};

const BitTiming_Handle_t bitRate_500kbps = {
		.Prescaler = 4,
		.SyncJumpWidth = CAN_SJW_1TQ,
		.TimeSeg1 = CAN_BS1_13TQ,
		.TimeSeg2 = CAN_BS2_2TQ
};

const BitTiming_Handle_t bitRate_800kbps = {
		.Prescaler = 4,
		.SyncJumpWidth = CAN_SJW_1TQ,
		.TimeSeg1 = CAN_BS1_8TQ,
		.TimeSeg2 = CAN_BS2_1TQ
};

const BitTiming_Handle_t bitRate_1000kbps = {
		.Prescaler = 2,
		.SyncJumpWidth = CAN_SJW_1TQ,
		.TimeSeg1 = CAN_BS1_13TQ,
		.TimeSeg2 = CAN_BS2_2TQ
};

#endif /* INC_CAN_BIT_TIMING_H_ */
