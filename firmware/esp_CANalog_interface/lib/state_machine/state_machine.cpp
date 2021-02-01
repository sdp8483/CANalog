#include "state_machine.h"

StateMachine::StateMachine(void) {
    state = STARTUP;
    last_state = NONE;
}

void StateMachine::changeState(STATES_t next_state) {
    last_state = state;
    state = next_state;

    _ran_once = false;
}

bool StateMachine::first_run(void) {
    if (_ran_once == false) {
        _ran_once = true;
        return true;
    } else {
        return false;
    }
}