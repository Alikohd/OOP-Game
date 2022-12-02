#ifndef GAME_C___GEAR_H
#define GAME_C___GEAR_H
#include "PEvent.h"

class IGearObserver {
public:
    virtual ~IGearObserver() = default;
    virtual void gearReact() = 0;
};

class Gear: public PEvent {
public:
    explicit Gear(Player *player);
    void react() override;
    Event * clone() override;
    void setObserver(IGearObserver* observer);
private:
    int _score;
    int _isActive;
    IGearObserver* _observer = nullptr;
};


#endif //GAME_C___GEAR_H
