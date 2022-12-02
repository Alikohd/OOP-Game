#ifndef GAME_C___GEAROBSERVER_H
#define GAME_C___GEAROBSERVER_H


#include "Gear.h"

class GearObserver : public IGearObserver {
public:
    void gearReact() override;
};



#endif //GAME_C___GEAROBSERVER_H
