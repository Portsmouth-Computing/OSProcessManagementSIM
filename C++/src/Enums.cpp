#include "Enums.h"

std::string stateToString(State state)
{
    switch (state) {
        case State::Processing:
            return "Processing";
            break;

        case State::Terminated:
            return "Terminated";
            break;

        case State::Waiting:
            return "Waiting";
            break;
    }
    return "ERROR";
}
