#include "ApplicationController.h"

#include "Launcher.h"

ApplicationController::ApplicationController(Launcher* application)
        : _app(application) {}

void ApplicationController::process(Command command) {
    switch (command) {
        case Command::Exit:
            _app->quit();
            break;
        default:
            break;
    }
}
