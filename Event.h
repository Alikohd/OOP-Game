#pragma once

class Player;
class Field;


class Event {
public:
    virtual void react() = 0;
    virtual Event* clone() = 0;
    virtual ~Event() = default;
};

