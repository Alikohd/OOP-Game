#include <iostream>
#include "ConcoleLogger.h"

ILogger& ConsoleLogger::operator<<(const std::string& string) {
    std::cout << string << '\n';
    return *this;
}
