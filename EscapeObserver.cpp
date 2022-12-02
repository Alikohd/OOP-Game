#include "EscapeObserver.h"

#include "Logger.h"

void EscapeObserver::EscapeReacted() {
    Logger::getInstance() << LoggerMessage{"Escape!", Logger::Action};
}