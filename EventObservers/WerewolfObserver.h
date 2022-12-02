#ifndef GAME_C___WEREWOLFOBSERVER_H
#define GAME_C___WEREWOLFOBSERVER_H

#include "../Werewolf.h"

class WerewolfObserver : public IWerewolfObserver {
public:
    void werewolfReact(int damage) override;
};

#endif //GAME_C___WEREWOLFOBSERVER_H
