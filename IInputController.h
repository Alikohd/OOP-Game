#ifndef GAME_C___IINPUTCONTROLLER_H
#define GAME_C___IINPUTCONTROLLER_H
#include "Command.h"

class IInputController {
public:
    virtual ~IInputController() = default;
    virtual void process(Command command) = 0;
};
#endif //GAME_C___IINPUTCONTROLLER_H
