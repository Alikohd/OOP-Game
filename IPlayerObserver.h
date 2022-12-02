    #ifndef GAME_C___IPLAYEROBSERVER_H
#define GAME_C___IPLAYEROBSERVER_H


class Player;

class IPlayerObserver {
public:
    virtual void healthChanged(Player* player) = 0;
    virtual void gearScoreChanged(Player* player) = 0;
    virtual void damageChanged(Player* player) = 0;
    virtual void win_reached() = 0;
};


#endif //GAME_C___IPLAYEROBSERVER_H
