#include <iostream>
#include "Player.h"

Player::Player(int health, int damage, int gearScore, int mana)
    : _health(health), _damage(damage), _gearScore(gearScore), _mana(mana){}

Player::Player() : Player(100, 10, 10, 100){}

void Player::changeHealth(int value) {
_health += value;
if (_observer != nullptr)
    _observer->healthChanged(this);
}

void Player::changeGearScore(int value) {
    _gearScore += value;
    if (_observer != nullptr)
        _observer->gearScoreChanged(this);
}

int Player::getGearScore() const {
    return _gearScore;
}

int Player::getHealth() const {
    return _health;
}


void Player::win() {
    if (_observer != nullptr)
        _observer->win_reached();
}


void Player::setObserver(PlayerObserver *observer) {
    _observer = observer;
}

int Player::getDamage() const {
    return _damage;
}




