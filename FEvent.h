#ifndef GAME_C___FEVENT_H
#define GAME_C___FEVENT_H

#include "Event.h"
#include "Field.h"

class FEvent: public virtual Event {
public:
    explicit FEvent(Field* game_field);
    void react() override = 0;
    Event* clone() override = 0;
protected:
    Field *_field;
};


#endif //GAME_C___FEVENT_H
