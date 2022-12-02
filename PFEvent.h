#ifndef GAME_C___PFEVENT_H
#define GAME_C___PFEVENT_H


#include "Event.h"
#include "Player.h"

class PFEvent: public Event {
protected:
    Player *_player;
    Field *_field;
    PFEvent(Player *player, Field *field);
};


#endif //GAME_C___PFEVENT_H
