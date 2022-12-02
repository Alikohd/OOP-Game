#ifndef GAME_C___IFIELDOBSERVER_H
#define GAME_C___IFIELDOBSERVER_H


#include "Coords.h"

class IFieldObserver {
public:
    virtual void cellEventChanged(const Coords& position) = 0;
    virtual void cellPassableChanged(const Coords& position, bool value) = 0;
    virtual void playerPosChanged(const Coords& position) = 0;
};

#endif //GAME_C___IFIELDOBSERVER_H
