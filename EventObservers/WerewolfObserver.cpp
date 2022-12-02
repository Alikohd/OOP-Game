#include "WerewolfObserver.h"
#include "../Logger.h"

void WerewolfObserver::werewolfReact(int damage) {
    Logger::getInstance() << LoggerMessage{"Terrible werewolf with damage " +
                                           std::to_string(damage) +
                                           " just appeared.",
                                           Logger::Action};
}
