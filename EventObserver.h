#ifndef GAME_C___EVENTOBSERVER_H
#define GAME_C___EVENTOBSERVER_H

#include "Werewolf.h"
#include "MeteorRain.h"
#include "Gear.h"
#include "Fire.h"
#include "Escape.h"

class EventObserver : public IWerewolfObserver,
                      public IFireObserver,
                      public IGearObserver,
                      public IMeteorRainObserver,
                      public IEscapeObserver {
public:
    void werewolfReact(int damage) override;
    void fireReact() override;
    void gearReact() override;
    void meteorRainReact() override;
    void EscapeReacted() override;
};

#endif //GAME_C___EVENTOBSERVER_H
