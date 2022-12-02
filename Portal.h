#ifndef GAME_C___PORTAL_H
#define GAME_C___PORTAL_H
#include "FEvent.h"
#include "Coords.h"
#include "Field.h"

class IPortalObserver {
public:
    virtual ~IPortalObserver() = default;
    virtual void portalReact() = 0;
};

class Portal:public FEvent {
public:
    explicit Portal(Field *field, IPortalObserver* observer = nullptr);
    void react() override;
    Event * clone() override;

private:
    Coords _new_pos;
    IPortalObserver* _observer;
    //Event *effect;
};


#endif //GAME_C___PORTAL_H
