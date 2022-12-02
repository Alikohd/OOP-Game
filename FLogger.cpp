#include "FLogger.h"

ILogger& FileLogger::operator<<(const std::string& string) {
    _file << string << '\n';
    return *this;
}

FileLogger::FileLogger() : FileLogger("logFile.log") {}

FileLogger::FileLogger(const std::string& filename) : _file(filename) {}

FileLogger::~FileLogger() {
    _file.close();
}
