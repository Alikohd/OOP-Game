#pragma once

#include "Event.h"

class Cell {
public:
    Cell();
    Cell(Event* event, bool can_be_passed, bool is_player_on);
    ~Cell();

    void playerStepped();
    void playerLeft();

    Cell(const Cell& other);
    Cell& operator=(const Cell& other);

    Cell(Cell&& other) noexcept;
    Cell& operator=(Cell&& other) noexcept;

    [[nodiscard]] Event *getEvent() const;
    void changeEvent(Event* new_event);
    void changePassable(bool value);
    [[nodiscard]] bool isPassable() const;
    [[nodiscard]] bool isPlayerHere() const;

private:
    Event* _event;
    bool _canBePassed;
    bool _isPlayerHere;
};
