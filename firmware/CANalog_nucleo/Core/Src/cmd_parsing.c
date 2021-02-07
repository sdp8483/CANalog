/*
 * cmd_parsing.c
 *
 *  Created on: Jan 30, 2021
 *      Author: sam
 */

#include "cmd_parsing.h"

/* parse commands when handle has is_ready flag set */
int8_t cmd_parse(CMD_Handle_t *hcmd, Signal_Handle_t *hsignal) {
	int8_t rVal = CMD_NONE;							/* return value */

	if(hcmd->is_overflow == 1) {					/* handle overflow condition */
		hcmd->is_overflow = 0;
		cmd_clear_buffer(hcmd);
		cmd_tx_string((uint8_t *)CMD_IS_LONG);
		rVal = CMD_ERROR;
		return rVal;
	}

	if(hcmd->is_ready == 1) {				/* handle when a command is ready */
		hcmd->is_ready = 0;

		if(hcmd->buffer[0] != CMD_START_CHAR) {		/* start character is wrong */
			cmd_tx_string((uint8_t *)CMD_IS_BAD);
			rVal = CMD_ERROR;
		} else {
			switch(hcmd->buffer[2]) {
			case CMD_SET_CHAR:						/* set parameter value */
				cmd_is_set(hcmd, hsignal);
				rVal = CMD_RECEIVED_VALUE;
				break;
			case CMD_GET_CHAR:						/* respond with parameter value */
				cmd_is_get(hcmd, hsignal);
				rVal = CMD_SENT_VALUE;
				break;
			default:								/* unsupported command type */
				cmd_tx_string((uint8_t *)CMD_IS_BAD);
				rVal = CMD_ERROR;
				break;
			}
		}

		cmd_clear_buffer(hcmd);
	}

	return rVal;
}

/* clear the command receive buffer */
void cmd_clear_buffer(CMD_Handle_t *hcmd) {
	hcmd->index = 0;		/* reset index */

	for (uint8_t i=0; i<CMD_BUFFER_LEN; i++) {
		hcmd->buffer[i] = 0;
	}
}

/* transmit to attached micro/user string */
void cmd_tx_string(uint8_t *str) {
	uint16_t len = strlen((char *)str);

	while(HAL_UART_Transmit_IT(&huart1, str, len) == HAL_BUSY) {
		HAL_Delay(1);
	}
}

/* convert valid input to unsigned long with base
 * 	https://stackoverflow.com/questions/26080829/detecting-strtol-failure/26083517 */
void cmd_to_ul(CMD_Handle_t *hcmd, uint8_t base, uint32_t *ptrParameter) {
	const char *nptr = (char *)&hcmd->buffer[3];			/* string to read */
	char *endptr = NULL;									/* pointer to additional chars */
	unsigned long number = 0;								/* variable holding return */

	errno = 0;												/* reset errno to 0 before call */

	number = strtoul(nptr, &endptr, base);

    if (nptr == endptr) {									/* invalid, no digits found */
    	cmd_tx_string((uint8_t *)CMD_IS_BAD);
    } else if (errno == ERANGE && number == 0) {			/* invalid, underflow occurred */
    	cmd_tx_string((uint8_t *)CMD_IS_BAD);
    } else if (errno == ERANGE && number == ULONG_MAX) {	/* invalid, overflow occurred */
    	cmd_tx_string((uint8_t *)CMD_IS_BAD);
    } else if (errno == EINVAL) {  							/* invalid, base contains unsupported value */
    	cmd_tx_string((uint8_t *)CMD_IS_BAD);
    } else if (errno != 0 && number == 0) {					/* invalid, unspecified error occurred */
    	cmd_tx_string((uint8_t *)CMD_IS_BAD);
    } else if (errno == 0 && nptr && !*endptr) {			/* valid and represents all characters read */
    	*ptrParameter = number;
    	cmd_tx_string((uint8_t *)CMD_IS_GOOD);
    } else if (errno == 0 && nptr && *endptr != 0) {		/* valid  (but additional characters remain */
    	*ptrParameter = number;
    	cmd_tx_string((uint8_t *)CMD_IS_GOOD);
    }
}

/* attached micro/user is trying to set a parameter */
void cmd_is_set(CMD_Handle_t *hcmd, Signal_Handle_t *hsignal) {
	switch(hcmd->buffer[1]) {
	case CMD_CAN_BAUD:								/* set the can baud rate */
		cmd_to_ul(hcmd, 10, (uint32_t *) &hsignal->can_baud);
		hcmd->cmd_char = CMD_CAN_BAUD;
		break;
	case CMD_CAN_ID_TYPE:
		cmd_to_ul(hcmd, 10, (uint32_t *) &hsignal->can_type);	/* set can ID to 11bit/29bit */
		hcmd->cmd_char = CMD_CAN_ID_TYPE;
		break;
	case CMD_CAN_ID:								/* set the can ID */
		cmd_to_ul(hcmd, 10, &hsignal->can_id);
		hcmd->cmd_char = CMD_CAN_ID;
		break;
	case CMD_CAN_SIGNAL_START_BIT:					/* set the signal start bit */
		cmd_to_ul(hcmd, 10, (uint32_t *) &hsignal->start_bit);
		hcmd->cmd_char = CMD_CAN_SIGNAL_START_BIT;
		break;
	case CMD_CAN_SIGNAL_BIT_LEN:					/* set the signal length */
		cmd_to_ul(hcmd, 10, (uint32_t *) &hsignal->bit_len);
		hcmd->cmd_char = CMD_CAN_SIGNAL_BIT_LEN;
		break;
	case CMD_CAN_ENDIANNESS:						/* set endianness of signal */
		cmd_to_ul(hcmd, 10, (uint32_t *) &hsignal->endianness);
		hcmd->cmd_char = CMD_CAN_ENDIANNESS;
		break;
	case CMD_CAN_SIGNAL_MAX:
		cmd_to_ul(hcmd, 10, (uint32_t *) &hsignal->max);
		hcmd->cmd_char = CMD_CAN_SIGNAL_MAX;
		break;
	case CMD_CAN_SIGNAL_MIN:
		cmd_to_ul(hcmd, 10, (uint32_t *) &hsignal->min);
		hcmd->cmd_char = CMD_CAN_SIGNAL_MIN;
	default:										/* unsupported parameter */
		cmd_tx_string((uint8_t *)CMD_IS_BAD);
		hcmd->cmd_char = CMD_BAD;
		break;
	}
}

/* attached micro/user is asking for a parameter value */
void cmd_is_get(CMD_Handle_t *hcmd, Signal_Handle_t *hsignal) {
	switch(hcmd->buffer[1]) {
	case CMD_SN:									/* send serial number, no set command */
		cmd_send_response(hcmd, CMD_SN, (uint32_t) device_sn);
		break;
	case CMD_CAN_BAUD:								/* send the can baud rate */
		cmd_send_response(hcmd, CMD_CAN_BAUD, (uint32_t) hsignal->can_baud);
		break;
	case CMD_CAN_ID:								/* send the can ID */
		cmd_send_response(hcmd, CMD_CAN_ID, hsignal->can_id);
		break;
	case CMD_CAN_SIGNAL_START_BIT:					/* send the signal start bit */
		cmd_send_response(hcmd, CMD_CAN_SIGNAL_START_BIT, hsignal->start_bit);
		break;
	case CMD_CAN_SIGNAL_BIT_LEN:					/* send the signal length */
		cmd_send_response(hcmd, CMD_CAN_SIGNAL_BIT_LEN, hsignal->bit_len);
		break;
	default:										/* unsupported parameter */
		cmd_tx_string((uint8_t *)CMD_IS_BAD);
		break;
	}
}

void cmd_send_response(CMD_Handle_t *hcmd, uint8_t parameter_char, uint32_t value) {

//	if ((parameter_char == CMD_CAN_ID) || (parameter_char == CMD_SN)) {
//		sprintf((char *)hcmd->txBuffer, "%c%c%c%lX%s", CMD_START_CHAR, parameter_char, CMD_RESPOND_CHAR, value, CMD_EOL);
//	} else {
	sprintf((char *)hcmd->txBuffer, "%c%c%c%lu%s", CMD_START_CHAR, parameter_char, CMD_RESPOND_CHAR, value, CMD_EOL);
//	}
	cmd_tx_string(hcmd->txBuffer);
}
