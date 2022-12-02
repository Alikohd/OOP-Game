#ifndef GAME_C___FIELDOBSERVER_H
#define GAME_C___FIELDOBSERVER_H


#include "IFieldObserver.h"

class Field;

class FieldObserver : public IFieldObserver {
public:
    void cellEventChanged(const Coords& position) override;
    void cellPassableChanged(const Coords& position, bool value) override;
    void playerPosChanged(const Coords& position) override;
    FieldObserver& operator<<(const Field& game_field);
};


#endif //GAME_C___FIELDOBSERVER_H
