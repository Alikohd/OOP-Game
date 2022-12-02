

#ifndef GAME_C___CONTROLSCHEMEFILEMANAGER_H
#define GAME_C___CONTROLSCHEMEFILEMANAGER_H


#include <string>

#include "ControlScheme.h"

class ControlSchemeFileManager {
public:
    explicit ControlSchemeFileManager(std::string filename = "controls.txt");

    ControlScheme scan();
    void save(const ControlScheme& control_scheme);

    ControlScheme defaultScheme();
    bool fixScheme(ControlScheme& scheme);

    std::string encodeCommand(Command command);
    Command decodeCommand(const std::string& str);

private:
    std::pair<char, Command> proceedLine(const std::string& line);

    std::string _filename;

    ControlScheme _default_scheme{{{'W', Command::MoveUp},
                                   {'A', Command::MoveLeft},
                                   {'S', Command::MoveDown},
                                   {'D', Command::MoveRight},
                                   {'E', Command::Exit}}};

    std::unordered_map<std::string, Command> _command_string_map{
            {"MoveUp", Command::MoveUp},
            {"MoveDown", Command::MoveDown},
            {"MoveRight", Command::MoveRight},
            {"MoveLeft", Command::MoveLeft},
            {"Exit", Command::Exit}};
};

#endif //GAME_C___CONTROLSCHEMEFILEMANAGER_H
