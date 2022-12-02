#ifndef GAME_C___INPUTREADER_H
#define GAME_C___INPUTREADER_H

#include "Command.h"

class IInputMediator;

class InputReader {
public:
    virtual ~InputReader() = default;
    void addMediator(IInputMediator* mediator);
    virtual void process() = 0;

protected:
    void notify(Command command);
    IInputMediator* mediator = nullptr;
};

#endif //GAME_C___INPUTREADER_H
