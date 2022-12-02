#include "Cell.h"


Cell::Cell(Event* event, bool can_be_passed, bool is_player_on)
    : _event(event), _canBePassed(can_be_passed), _isPlayerHere(is_player_on) {}

Cell::Cell() : Cell(nullptr, true, false) {}

void Cell::playerStepped() {
    _isPlayerHere = true;
    if (_event != nullptr)
        _event ->react();
}

bool Cell::isPassable() const {
    return _canBePassed;
}

bool Cell::isPlayerHere() const {
    return _isPlayerHere;
}

void Cell::changeEvent(Event* new_event) {
    _event = new_event;
}

void Cell::playerLeft() {
    _isPlayerHere = false;
}

void Cell::changePassable(bool value) {
    _canBePassed = value;
}

Event *Cell::getEvent() const {
    return _event;
}

Cell::~Cell() {
    delete _event;
}

Cell::Cell(const Cell &other):
    _event(other._event->clone()), _isPlayerHere(other._isPlayerHere), _canBePassed(other._canBePassed) {}

Cell& Cell::operator=(const Cell& other) {
    if (this != &other) {
        delete _event;
        _event = other._event->clone();
        _isPlayerHere = other._isPlayerHere;
        _canBePassed = other._canBePassed;
    }
    return *this;
}

Cell::Cell(Cell&& other) noexcept
        : _event(other._event), _canBePassed(other._canBePassed), _isPlayerHere(other.isPlayerHere()) {
    other._event = nullptr;
    other._isPlayerHere = false;
}

Cell& Cell::operator=(Cell&& other) noexcept {
    if (this != &other) {
        delete _event;
        _event = other._event->clone();
        _isPlayerHere = other._isPlayerHere;
        _canBePassed= other._canBePassed;
        other._event = nullptr;
        other._isPlayerHere = false;
    }
    return *this;
}