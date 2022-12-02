#ifndef GAME_C___FIREOBSERVER_H
#define GAME_C___FIREOBSERVER_H

#include "../Fire.h"

class FireObserver : public IFireObserver {
public:
    void fireReact() override;
};


#endif //GAME_C___FIREOBSERVER_H
