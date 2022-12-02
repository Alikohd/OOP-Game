#ifndef GAME_C___INPUTMEDIATOR_H
#define GAME_C___INPUTMEDIATOR_H
#include <memory>
#include <unordered_set>

#include "IInputController.h"
#include "IInputMediator.h"
#include "InputReader.h"

class InputMediator : public IInputMediator {
public:
    ~InputMediator() override;

    void update();
    void process(Command command) override;

    void addController(IInputController* controller);
    void addReader(InputReader* reader);

private:
    std::unordered_set<IInputController*> _controllers;
    std::unordered_set<InputReader*> _readers;
};


#endif //GAME_C___INPUTMEDIATOR_H
