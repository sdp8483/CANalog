#ifndef INC_STATE_MACHINE_H_
#define INC_STATE_MACHINE_H_

#include "Arduino.h"

typedef enum __states_t {
  NONE, /* none state */
  STARTUP,  /* state on power up */
  GET_SN_STARTUP,   /* get device sn from STM32 during power up */
  GET_BAUD_STARTUP,/* get can baud from STM32 during power up */
  GET_ID_STARTUP,/* get can ID from STM32 during power up */
  GET_START_STARTUP,/* get can start signal bit from STM32 during power up */
  GET_LEN_STARTUP,/* get can signal bit len from STM32 during power up */
  SETUP_WIFI,   /* start wifi access point */
  MAIN_LOOP,    /* handle wifi server */
} STATES_t;

class StateMachine {
    public:
        StateMachine(void);
        void changeState(STATES_t next_state);
        bool first_run(void);
        STATES_t state;
        STATES_t last_state;
    private:
        bool _ran_once;
};

#endif