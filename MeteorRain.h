#include "PEvent.h"
#include "FEvent.h"
#ifndef GAME_C___METEORRAIN_H
#define GAME_C___METEORRAIN_H

class IMeteorRainObserver {
public:
    virtual ~IMeteorRainObserver() = default;
    virtual void meteorRainReact() = 0;
};

class MeteorRain: public PEvent, public FEvent  {
private:
    int _gear;
    IMeteorRainObserver* _observer = nullptr;
public:
    MeteorRain(Player *player, Field *field);
    void react() override;
    Event * clone() override;
    void setObserver(IMeteorRainObserver* observer);
};


#endif //GAME_C___METEORRAIN_H
