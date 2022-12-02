#include "FieldObserver.h"
#include "Logger.h"
#include "Field.h"

void FieldObserver::cellEventChanged(const Coords& position) {
    Logger::getInstance()
            << LoggerMessage{"Event changed in cell on " + static_cast<std::string>(position), Logger::Action};
}

void FieldObserver::cellPassableChanged(const Coords& position, bool value) {
    Logger::getInstance() << LoggerMessage{
            "Passable changed in cell on " + static_cast<std::string>(position) + " to " + (value ? "true" : "false"),
            Logger::Action};
}

void FieldObserver::playerPosChanged(const Coords& position) {
    Logger::getInstance()
            << LoggerMessage{"Player position changed to " + static_cast<std::string>(position), Logger::Action};
}

FieldObserver& FieldObserver::operator<<(const Field& game_field) {
    if (game_field.getWidth()*game_field.getHeight()<=0){
        Logger::getInstance() << LoggerMessage{
                "Incorrect field sizes initialized",
                Logger::Error};
        exit(0);
    }
    Logger::getInstance() << LoggerMessage{
            "Field: width = " + std::to_string(game_field.getWidth()) +
            ", height = " + std::to_string(game_field.getHeight()),
            Logger::Info};
    return *this;
}
