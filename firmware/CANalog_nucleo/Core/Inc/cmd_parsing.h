/*
 * cmd_parsing.h
 *
 * UART Command Parsing
 *  All commands start with a $ character and end with a \n character.
 * 	An attached micro/user will set parameters using $X= where X is a parameter character defied below
 *	An attached micro/user will get parameters using $X? where X is a parameter character defied below
 *  The STM32 will respond to a get command with $X: where X is the parameter character requested
 *  The STM32 will respond with a OK if the command is valid, a NOK if the command is invalid,
 *   or a OVF if the command was not terminated with a \n
 *
 *  Created on: Jan 29, 2021
 *      Author: sam
 */

#ifndef INC_CMD_PARSING_H_
#define INC_CMD_PARSING_H_

#include "main.h"
#include "usart.h"

#include "stdio.h"
#include "stdint.h"
#include "string.h"
#include "stdlib.h"
#include "errno.h"
#include "limits.h"

#include "can_signal.h"

#define CMD_BUFFER_LEN				32			/* how long the rx command buffer is */

/* common characters and strings for command parser */
#define CMD_START_CHAR				'$'			/* all commands start with this character */
#define CMD_GET_CHAR				'?'			/* used by rx line to get value */
#define CMD_SET_CHAR				'='			/* used by rx line to set value */
#define CMD_RESPOND_CHAR			':'			/* use to respond with value */
#define CMD_END_CHAR				'\n'		/* all valid commands end with this character */
#define CMD_EOL						"\r\n"		/* used to terminate command */
#define CMD_IS_GOOD					"OK\r\n"	/* response when command is accepted */
#define CMD_IS_BAD					"NOK\r\n"	/* response when command is not accepted */
#define CMD_IS_LONG					"OVF\r\n"	/* response when command is too long */

/* parameters to set or get with command parser, case is important */
#define CMD_BAD						'!'			/* command received was bad, only used to signal main loop on cmd_parse return */
#define CMD_SN						's'			/* 32bit unique device serial number */
#define CMD_CAN_BAUD				'B'			/* CAN baud rate */
#define CMD_CAN_ID_TYPE				'T'			/* CAN ID is 11bit or 29bit */
#define CMD_CAN_ID					'I'			/* CAN ID in hex */
#define CMD_CAN_SIGNAL_START_BIT 	'S'			/* CAN Signal Start Bit */
#define CMD_CAN_SIGNAL_BIT_LEN		'L'			/* CAN Signal Bit Length */
#define CMD_CAN_ENDIANNESS			'E'			/* CAN Signal endianness */
#define CMD_CAN_SIGNAL_MAX			'M'			/* CAN signal max value */
#define CMD_CAN_SIGNAL_MIN			'm'			/* CAN signal min value */

/* command parsing return codes, used to signal main loop */
#define CMD_NONE					0			/* no action needed by main loop */
#define CMD_RECEIVED_VALUE			1			/* there is a new parameter value, react by saving to backup and more */
#define CMD_SENT_VALUE				2			/* sent parameter to requesting device, no need to react (I think) */
#define CMD_ERROR					-1			/* something is wrong */

/* command handle type define */
typedef struct __CMD_Handle_t {
	uint8_t rxBuffer[1];
	uint8_t txBuffer[CMD_BUFFER_LEN];
	uint8_t buffer[CMD_BUFFER_LEN];				/* the received commands to parse */
	volatile uint8_t is_ready; 					/* signal to super loop that a serial command is ready */
	volatile uint8_t is_overflow;				/* signal to super loop that the serial data received was too long */
	volatile uint8_t index; 					/* where to place next incoming byte in the buffer */
	uint8_t cmd_char;							/* store cmd character that was received, signal to main loop what parameter was updated */
} CMD_Handle_t;

/* external variables to parameters set/get by the command parser */
extern uint32_t device_sn;						/* unique 32bit serial number (maybe) */

/* function prototypes */
int8_t cmd_parse(CMD_Handle_t *hcmd, Signal_Handle_t *hsignal);
												/* parse the incoming command and determine if set/get
 	 	 	 	 	 	 	 	 	 	 	 	 *  this is only function that should be called by main
 	 	 	 	 	 	 	 	 	 	 	 	 *  incoming commands are stored/retrieved from signal handle */
void cmd_clear_buffer(CMD_Handle_t *hcmd); 		/* clear the command buffer */
void cmd_tx_string(uint8_t *str);				/* send string over UART */
void cmd_to_ul(CMD_Handle_t *hcmd, uint8_t base, uint32_t *ptrParameter);
												/* set parameter using pointer, unsigned long number of specified base
												 * doesn't set parameter if parsing error in strtoul and tx error message */
void cmd_is_set(CMD_Handle_t *hcmd, Signal_Handle_t *hsignal);			/* attached micro/user is setting a parameter */
void cmd_is_get(CMD_Handle_t *hcmd, Signal_Handle_t *hsignal);			/* attached micro/user is requesting parameter value */
void cmd_send_response(CMD_Handle_t *hcmd, uint8_t parameter_char, uint32_t value);
												/* send response to requested parameter */


#endif /* INC_CMD_PARSING_H_ */
