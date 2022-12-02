#pragma once
#include "PlayerObserver.h"

class Player {
public:
    Player();
    Player(int health, int damage, int gearScore, int mana);
    [[nodiscard]] int getHealth() const;
    [[nodiscard]] int getGearScore() const;
    [[nodiscard]] int getDamage() const;
    void changeHealth(int value);
    void changeGearScore(int value);
    void win();
    void setObserver(PlayerObserver* observer);
private:
    PlayerObserver* _observer;
    int _health;
    int _damage;
    int _gearScore;
    int _mana;
};
