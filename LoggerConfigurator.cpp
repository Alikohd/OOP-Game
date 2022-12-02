#include "LoggerConfigurator.h"

#include <iostream>

#include "ConcoleLogger.h"
#include "FLogger.h"
#include "Logger.h"

void LoggerConfigurator::accomplish() {
    std::cout << "Enter logging level:\n\t1. Action\n\t2. Info\n\t3. Error\n\t4. Nothing\n";
    char c = 0;
    std::cin >> c;

    Logger::Lvl level = Logger::Error;
    switch (c) {
        case '1':
            level = Logger::Action;
            break;
        case '2':
            level = Logger::Info;
            break;
        case '3':
            level = Logger::Error;
            break;
        case '4':
            level - Logger::Nothing;
            break;
        default:
            Logger::getInstance().setLvl(Logger::Error);
            Logger::getInstance().addLogger(new FileLogger());
            Logger::getInstance().addLogger(new ConsoleLogger());
            break;
    }

    Logger::getInstance().setLvl(level);

    if (c != '4') {
        std::cout << "Enable file logging? (y/n) (default: y):\n";
        std::cin >> c;

        if (c == 'y' || c == 'Y') {
            Logger::getInstance().addLogger(new FileLogger());
        }

        std::cout << "Enable console logging? (y/n) (default: y):\n";
        std::cin >> c;
        if (c == 'y' || c == 'Y') {

            Logger::getInstance().addLogger(new ConsoleLogger());
        }
    }
    system("cls");
}
