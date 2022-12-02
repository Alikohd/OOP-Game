#ifndef GAME_C___ESCAPE_H
#define GAME_C___ESCAPE_H
#include "Event.h"
#include "PEvent.h"

class IEscapeObserver {
public:
    virtual ~IEscapeObserver() = default;
    virtual void EscapeReacted() = 0;
};

class Escape: public PEvent {
private:
    bool _lock;
    int _gear_plank;
    IEscapeObserver* _observer = nullptr;
public:
    explicit Escape(Player *player);
    void react() override;
    Event * clone() override;
    void setObserver(IEscapeObserver* observer);
};


#endif //GAME_C___ESCAPE_H
