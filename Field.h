#pragma once

#include <vector>
#include "Cell.h"
#include "Coords.h"
#include "Player.h"
#include "IFieldObserver.h"

class Field {
    friend class FieldBuilder;
public:
    Field();
    Field(int width, int height, Coords player_pos);
    Field(int width, int height, std::vector<std::vector<Cell>>&& cells);
    Field(const Field& other);
    Field(Field&& other) noexcept;
    Field& operator=(const Field& other);
    Field& operator=(Field&& other) noexcept;
    [[nodiscard]] const Cell& getCell(Coords coordinate) const;

    void changeCellEvent(const Coords& position, Event* event);
    void changeCellPassable(const Coords& position, bool value);

    [[nodiscard]] int getWidth() const;
    [[nodiscard]] int getHeight() const;
    Coords getPlayerPosition();
    void setPlayerPosition(Coords new_position, bool previous = true);
    void setObserver(IFieldObserver* observer);

private:
    int _width, _height;
    std::vector<std::vector<Cell>> _matrix;
    Coords _player_pos;
    IFieldObserver* _observer = nullptr;
    //Player& _player;
};
