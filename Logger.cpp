#include "Logger.h"

Logger& Logger::getInstance() {
    static Logger stat;
    return stat;
}

void Logger::setLvl(Logger::Lvl lvl) {
    _lvl = lvl;
}

Logger& Logger::operator<<(const LoggerMessage& message) {
    if (message.lvl < _lvl) {
        return *this;
    }
    for (auto logger : _loggers) {
        *logger << (lvlToString(message.lvl) + ": " + message.message);
    }
    return *this;
}

Logger::~Logger() {
    for (auto logger : _loggers) {
        delete logger;
    }
}

void Logger::addLogger(ILogger* logger) {
    _loggers.insert(logger);
}

void Logger::removeLogger(ILogger* logger) {
    _loggers.erase(logger);
}

std::string Logger::lvlToString(Logger::Lvl lvl) {
    switch (lvl) {
        case Action:
            return "ACTION";
        case Info:
            return "INFO";
        case Error:
            return "ERROR";
        case Nothing:
            break;
        default:
            return "UNKNOWN";
    }
}
