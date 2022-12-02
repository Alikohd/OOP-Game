#ifndef GAME_C___FLOGGER_H
#define GAME_C___FLOGGER_H

#include <string>
#include <fstream>
#include "Logger.h"

class FileLogger : public ILogger {
public:
    FileLogger();
    explicit FileLogger(const std::string& filename);
    ~FileLogger() override;

    ILogger& operator<<(const std::string& string) override;

private:
    std::string _file_name;
    std::ofstream _file;
};


#endif //GAME_C___FLOGGER_H
