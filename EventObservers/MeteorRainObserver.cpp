#include "MeteorRainObserver.h"
#include "../Logger.h"

void MeteorRainObserver::meteorRainReact() {
    Logger::getInstance() << LoggerMessage{"Cold is coming...", Logger::Action};
}