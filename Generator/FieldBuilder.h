#ifndef GAME_C___FIELDBUILDER_H
#define GAME_C___FIELDBUILDER_H


#include <utility>

class Field;
class Player;
struct FieldScheme;

class FieldBuilder {
public:
    std::pair<Field*, Player*> make(const FieldScheme& scheme);
};


#endif //GAME_C___FIELDBUILDER_H