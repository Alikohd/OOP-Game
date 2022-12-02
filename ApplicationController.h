#ifndef GAME_C___APPLICATIONCONTROLLER_H
#define GAME_C___APPLICATIONCONTROLLER_H

#include "IInputController.h"

class Launcher;

class ApplicationController : public IInputController {
public:
    explicit ApplicationController(Launcher* application);
    void process(Command command) override;

private:
    Launcher* _app;
};

#endif //GAME_C___APPLICATIONCONTROLLER_H
