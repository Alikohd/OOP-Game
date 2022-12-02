#include "InputReader.h"

#include "IInputMediator.h"

void InputReader::addMediator(IInputMediator* mediator) {
    this->mediator = mediator;
}

void InputReader::notify(Command command) { mediator->process(command); }