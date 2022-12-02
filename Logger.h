#ifndef GAME_C___LOGGER_H
#define GAME_C___LOGGER_H


#include <string>
#include <set>

struct LoggerMessage;

class ILogger {
public:
    virtual ILogger& operator<<(const std::string&) = 0;
    virtual ~ILogger() = default;
};


class Logger {
public:
    enum Lvl {
        Action, Info, Error, Nothing
    };

    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    static Logger& getInstance();

    Logger& operator<<(const LoggerMessage& message);

    void setLvl(Lvl lvl);
    void addLogger(ILogger* logger);
    void removeLogger(ILogger* logger);

    ~Logger();

    static std::string lvlToString(Lvl lvl);

private:
    Logger() = default;

    std::set<ILogger*> _loggers;
    Lvl _lvl = Info;
};

struct LoggerMessage {
    std::string message;
    Logger::Lvl lvl;
};

#endif //GAME_C___LOGGER_H
