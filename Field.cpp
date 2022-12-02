#include "Field.h"
#include <iostream>
Field::Field(int width, int height, Coords start_pos) : _width(width), _height(height), _player_pos(start_pos) {
    if (width*height > 0) {
        _matrix.resize(height);
        for (int i = 0; i < height; i++) {
            _matrix[i].resize(width);
        }
        this->getCell(start_pos).playerStepped();
    }
    }

Field::Field() : Field(20, 20, {0,0}) {
    this -> getCell({0,0}).playerStepped();
}

Field::Field(const Field& other) : _width(other._width), _height(other._height), _matrix(other._matrix), _player_pos(other._player_pos) {}

Field::Field(Field&& other) noexcept
    : _width(other._width), _height(other._height), _matrix(std::move(other._matrix)), _player_pos(other._player_pos) {
    other._height = 0;
    other._width = 0;
    other._matrix = {};
    other._player_pos = {};
}

Field& Field::operator=(const Field& other) {
    if (this != &other) {
        _width = other._width;
        _height = other._height;
        _matrix = other._matrix;
        _player_pos = other._player_pos;
        return *this;
    }
    return *this;
}

Field& Field::operator=(Field&& other) noexcept {
    if (this != &other) {
        _width = other._width;
        _height = other._height;
        _matrix = std::move(other._matrix);
        _player_pos = other._player_pos;
        other._height = 0;
        other._width = 0;
        other._matrix = {};
        other._player_pos = {};
        return *this;
    }
    return *this;
}

Cell& Field::getCell(Coords coordinate) {
    return _matrix[coordinate.y][coordinate.x];
}

[[maybe_unused]] int Field::getWidth() const {
    return _width;
}

int Field::getHeight() const {
    return _height;
}

Coords Field::getPlayerPosition() {
    return _player_pos;
}

void Field::setPlayerPosition(Coords new_pos) {
    auto& cell = _matrix[new_pos.y][new_pos.x];
    if (!cell.isPassable()) {
        _observer->playerPosChanged(new_pos);
        return;
    }
    auto& prev_cell = _matrix[_player_pos.y][_player_pos.x];
    prev_cell.playerLeft();
    cell.playerStepped();
    _player_pos = new_pos;
    _observer->playerPosChanged(new_pos);
}

void Field::changeCellEvent(const Coords& position, Event* event) {
    _matrix[position.y][position.x].changeEvent(event);
    _observer->cellEventChanged(position);
}

void Field::changeCellPassable(const Coords& position, bool value) {
    _matrix[position.y][position.x].changePassable(value);
    _observer->cellPassableChanged(position, value);
}

void Field::setObserver(IFieldObserver* observer) {
    _observer = observer;
}
