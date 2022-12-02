#ifndef GAME_C___METEORRAINOBSERVER_H
#define GAME_C___METEORRAINOBSERVER_H

#include "MeteorRain.h"

class MeteorRainObserver : public IMeteorRainObserver {
public:
    void meteorRainReact() override;
};


#endif //GAME_C___METEORRAINOBSERVER_H
