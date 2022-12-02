#include "FireObserver.h"
#include "Logger.h"

void FireObserver::fireReact() {
    Logger::getInstance() << LoggerMessage{"Fire!", Logger::Action};
}