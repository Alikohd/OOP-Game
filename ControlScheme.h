

#ifndef GAME_C___CONTROLSCHEME_H
#define GAME_C___CONTROLSCHEME_H


#include <unordered_map>

#include "Command.h"

struct ControlScheme {
    inline Command operator()(char key) { return data[key]; }

    std::unordered_map<char, Command> data;
};


#endif //GAME_C___CONTROLSCHEME_H
