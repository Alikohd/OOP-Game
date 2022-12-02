#include "GearObserver.h"
#include "Logger.h"

void GearObserver::gearReact() {
    Logger::getInstance() << LoggerMessage{"Gear!", Logger::Action};
}