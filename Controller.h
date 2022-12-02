#pragma once

#include "Field.h"
#include "Player.h"
#include "IInputController.h"

class Controller:public IInputController {
public:
    explicit Controller(Player* player, Field* game_field = nullptr);
    void changeField(Field* new_game_field);
    void moveUp(int step_size = 1);
    void moveDown(int step_size = 1);
    void moveRight(int step_size = 1);
    void moveLeft(int step_size = 1);
    void process(Command command) override;
private:
    Field* _curr_field;
    Player* _player;
    Coords normalizePoint(Coords point);
};
