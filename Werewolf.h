#ifndef GAME_C___WEREWOLF_H
#define GAME_C___WEREWOLF_H
#include "PEvent.h"
#include "Player.h"

class IWerewolfObserver {
public:
    virtual ~IWerewolfObserver() = default;
    virtual void werewolfReact(int damage) = 0;
};

class Werewolf: public PEvent {
private:
    int _health, _damage, _reward;
    IWerewolfObserver* _observer = nullptr;
    void notifyObserver(int damage);

public:
    void react() override;
    explicit Werewolf(Player *player);
    Event* clone() override;
    void setObserver(IWerewolfObserver* observer);
};


#endif //GAME_C___WEREWOLF_H
