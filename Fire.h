#include "Player.h"
#include "PEvent.h"

#ifndef GAME_C___FIRE_H
#define GAME_C___FIRE_H

class IFireObserver {
public:
    virtual ~IFireObserver() = default;
    virtual void fireReact() = 0;
};

class Fire : public PEvent {
private:
    int _damage;
    int _gear_Decrease;
    IFireObserver* _observer = nullptr;
public:
    explicit Fire(Player* player, IFireObserver* observer = nullptr);
    void react() override;
    Event* clone() override;
    void setObserver(IFireObserver* observer);
};


#endif //GAME_C___FIRE_H
