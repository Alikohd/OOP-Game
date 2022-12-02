#ifndef GAME_C___FIELDSCHEME_H
#define GAME_C___FIELDSCHEME_H


#include <vector>

enum class CellType {
    Empty, Wall, Player, Escape, Werewolf, EnchantmentTable, Fire, Gear, MeteorRain, Portal
};

struct FieldScheme {
    std::vector<std::vector<CellType>> data;
    int width;
    int height;
};


#endif //GAME_C___FIELDSCHEME_H