#ifndef GAME_C___PLAYEROBSERVER_H
#define GAME_C___PLAYEROBSERVER_H
#include "IPlayerObserver.h"

class Player;
class Launcher;

class PlayerObserver: public IPlayerObserver {
public:
    explicit PlayerObserver(Launcher* launcher);

    void healthChanged(Player* player) override;
    void gearScoreChanged(Player* player) override;
    //void manaChanged(Player* player);
    void damageChanged(Player* player) override;
    void win_reached() override;
    PlayerObserver& operator<<(const Player& player);
private:
    Launcher* _launcher;
};

#endif //GAME_C___PLAYEROBSERVER_H
