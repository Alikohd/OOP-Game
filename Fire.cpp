#include "Fire.h"

Fire::Fire(Player* player, IFireObserver* observer)
        : PEvent(player), _damage(5), _gear_Decrease(3), _observer(observer) {}

void Fire::react() {
    auto* player = _player;
    if (player->getGearScore() >= 1000)
        return;
    else if (player->getGearScore() > 0) {
        player->changeGearScore(-_gear_Decrease);
        player->changeHealth(-_damage);
    } else {
        player->changeHealth(-2 * _damage);
    }
}

Event* Fire::clone() {
    auto event = new Fire(_player);
    event->_damage = _damage;
    event->_gear_Decrease = _gear_Decrease;
    return event;
}

void Fire::setObserver(IFireObserver* observer) { _observer = observer; }
