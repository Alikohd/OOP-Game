#ifndef GAME_C____CONSOLELOGGER_H_
#define GAME_C____CONSOLELOGGER_H_

#include "Logger.h"

class ConsoleLogger : public ILogger {
public:
    ILogger& operator<<(const std::string& string) override;
};

#endif //GAME_C____CONSOLELOGGER_H_