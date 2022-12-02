#include "Controller.h"

Controller::Controller(Player* player, Field* game_field) : _player(player), _curr_field(game_field) {}

void Controller::changeField(Field* new_game_field) {
    _curr_field = new_game_field;
}

void Controller::moveUp(int step_size) {
    Coords now_position = _curr_field->getPlayerPosition();
    now_position.y -= step_size;
    now_position = normalizePoint(now_position);
    _curr_field->setPlayerPosition(now_position);

}

void Controller::moveDown(int step_size) {
    Coords now_position = _curr_field->getPlayerPosition();
    now_position.y += step_size;
    now_position = normalizePoint(now_position);
    _curr_field->setPlayerPosition(now_position);
}

void Controller::moveRight(int step_size) {
    Coords now_position = _curr_field->getPlayerPosition();
    now_position.x += step_size;
    now_position = normalizePoint(now_position);
    _curr_field->setPlayerPosition(now_position);

}

void Controller::moveLeft(int step_size) {
    Coords now_position = _curr_field->getPlayerPosition();
    now_position.x -= step_size;
    now_position = normalizePoint(now_position);
    _curr_field->setPlayerPosition(now_position);
}

Coords Controller::normalizePoint(Coords point) {
    if (point.x > _curr_field->getWidth()) {
        point.x %= _curr_field->getWidth();
    } else if (point.x < 0) {
        point.x = _curr_field->getWidth() - (-point.x % _curr_field->getWidth());
    }
    if (point.y > _curr_field->getHeight()) {
        point.y %= _curr_field->getHeight();
    } else if (point.y < 0) {
        point.y = _curr_field->getHeight() - (-point.y % _curr_field->getHeight());
    }
    return point;
}

void Controller::process(Command command) {
    switch (command) {
        case Command::MoveUp:
            moveUp();
            break;
        case Command::MoveDown:
            moveDown();
            break;
        case Command::MoveLeft:
            moveLeft();
            break;
        case Command::MoveRight:
            moveRight();
            break;
        default:
            break;
    }
}
