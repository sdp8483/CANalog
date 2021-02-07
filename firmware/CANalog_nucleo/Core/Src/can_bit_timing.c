/*
 * can_bit_timing.c
 *
 *  Created on: Feb 6, 2021
 *      Author: sam
 */

#include "can_bit_timing.h"

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

/* set the can bit timing based on baud rate in signal handler */
void can_set_bit_timing(Signal_Handle_t *hsignal, CAN_HandleTypeDef *hcan) {
	switch(hsignal->can_baud) {
	case (BAUD_RATE_10kbps):
		hcan->Init.Prescaler 		= bitRate_10kbps.Prescaler;
		hcan->Init.SyncJumpWidth 	= bitRate_10kbps.SyncJumpWidth;
		hcan->Init.TimeSeg1 		= bitRate_10kbps.TimeSeg1;
		hcan->Init.TimeSeg2 		= bitRate_10kbps.TimeSeg2;
		break;
	case (BAUD_RATE_20kbps):
		hcan->Init.Prescaler 		= bitRate_20kbps.Prescaler;
		hcan->Init.SyncJumpWidth 	= bitRate_20kbps.SyncJumpWidth;
		hcan->Init.TimeSeg1 		= bitRate_20kbps.TimeSeg1;
		hcan->Init.TimeSeg2 		= bitRate_20kbps.TimeSeg2;
		break;
	case (BAUD_RATE_50kbps):
		hcan->Init.Prescaler 		= bitRate_50kbps.Prescaler;
		hcan->Init.SyncJumpWidth 	= bitRate_50kbps.SyncJumpWidth;
		hcan->Init.TimeSeg1 		= bitRate_50kbps.TimeSeg1;
		hcan->Init.TimeSeg2 		= bitRate_50kbps.TimeSeg2;
		break;
	case (BAUD_RATE_83kbps):
		hcan->Init.Prescaler 		= bitRate_83kbps.Prescaler;
		hcan->Init.SyncJumpWidth 	= bitRate_83kbps.SyncJumpWidth;
		hcan->Init.TimeSeg1 		= bitRate_83kbps.TimeSeg1;
		hcan->Init.TimeSeg2 		= bitRate_83kbps.TimeSeg2;
		break;
	case (BAUD_RATE_100kbps):
		hcan->Init.Prescaler 		= bitRate_100kbps.Prescaler;
		hcan->Init.SyncJumpWidth 	= bitRate_100kbps.SyncJumpWidth;
		hcan->Init.TimeSeg1 		= bitRate_100kbps.TimeSeg1;
		hcan->Init.TimeSeg2 		= bitRate_100kbps.TimeSeg2;
		break;
	case (BAUD_RATE_125kbps):
		hcan->Init.Prescaler 		= bitRate_125kbps.Prescaler;
		hcan->Init.SyncJumpWidth 	= bitRate_125kbps.SyncJumpWidth;
		hcan->Init.TimeSeg1 		= bitRate_125kbps.TimeSeg1;
		hcan->Init.TimeSeg2 		= bitRate_125kbps.TimeSeg2;
		break;
	case (BAUD_RATE_250kbps):
		hcan->Init.Prescaler 		= bitRate_250kbps.Prescaler;
		hcan->Init.SyncJumpWidth 	= bitRate_250kbps.SyncJumpWidth;
		hcan->Init.TimeSeg1 		= bitRate_250kbps.TimeSeg1;
		hcan->Init.TimeSeg2 		= bitRate_250kbps.TimeSeg2;
		break;
	case (BAUD_RATE_500kbps):
		hcan->Init.Prescaler 		= bitRate_500kbps.Prescaler;
		hcan->Init.SyncJumpWidth 	= bitRate_500kbps.SyncJumpWidth;
		hcan->Init.TimeSeg1 		= bitRate_500kbps.TimeSeg1;
		hcan->Init.TimeSeg2 		= bitRate_500kbps.TimeSeg2;
		break;
	case (BAUD_RATE_800kbps):
		hcan->Init.Prescaler 		= bitRate_800kbps.Prescaler;
		hcan->Init.SyncJumpWidth 	= bitRate_800kbps.SyncJumpWidth;
		hcan->Init.TimeSeg1 		= bitRate_800kbps.TimeSeg1;
		hcan->Init.TimeSeg2 		= bitRate_800kbps.TimeSeg2;
		break;
	case (BAUD_RATE_1000kbps):
		hcan->Init.Prescaler 		= bitRate_1000kbps.Prescaler;
		hcan->Init.SyncJumpWidth 	= bitRate_1000kbps.SyncJumpWidth;
		hcan->Init.TimeSeg1 		= bitRate_1000kbps.TimeSeg1;
		hcan->Init.TimeSeg2 		= bitRate_1000kbps.TimeSeg2;
		break;
	default:
		break;
	}


}
