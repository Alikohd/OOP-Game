#ifndef GAME_C___PEVENT_H
#define GAME_C___PEVENT_H


#include "Event.h"
#include "Player.h"

class PEvent: virtual public Event {
public:
    explicit PEvent(Player* player);
    void react() override = 0;
    Event* clone() override = 0;
protected:
    Player *_player;
};


#endif //GAME_C___PEVENT_H
