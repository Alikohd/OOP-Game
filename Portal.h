#ifndef GAME_C___PORTAL_H
#define GAME_C___PORTAL_H
#include "FEvent.h"
#include "Coords.h"
#include "Field.h"

class Portal:public FEvent {
public:
    explicit Portal(Field *field);
    void react() override;
    Event * clone() override;
private:
    Coords _new_pos;
    //Event *effect;
};


#endif //GAME_C___PORTAL_H
