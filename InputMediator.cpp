#include "InputMediator.h"

InputMediator::~InputMediator() {
    for (const auto& reader : _readers) {
        delete reader;
    }
}

void InputMediator::update() {
    for (const auto& reader : _readers) {
        reader->process(); // erase for много ридеров за раз???? это же глупо
    }
}

void InputMediator::process(Command command) {
    for (const auto& controller : _controllers) {
        controller->process(command);
    }
}

void InputMediator::addController(IInputController* controller) {
    _controllers.insert(controller);
}

void InputMediator::addReader(InputReader* reader) {
    reader->addMediator(this);
    _readers.insert(reader);
}