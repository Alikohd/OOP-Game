#include "Werewolf.h"

Werewolf::Werewolf(Player* player, IWerewolfObserver* observer)
        : PEvent(player), _health(50), _damage(10), _reward(5), _observer(observer) {}

void Werewolf::react() {
    if (_health <= 0)
        return;
    auto player = _player;
    int curr_dmg = _damage - _damage * player->getGearScore() / 1000; // -10% damage for each 100 gearScore
    while (player->getHealth() > 0 && _health > 0) {
        notifyObserver(_damage);
        player->changeHealth(-curr_dmg);
        _health -= player->getDamage();
    }

    if (_health <= 0 && player->getHealth() > 0) {
        player->changeGearScore(_reward);
    }
}

Event* Werewolf::clone() {
    auto event = new Werewolf(_player);
    event->_health = _health;
    event->_damage = _damage;
    event->_reward = _reward;
    return event;
}

void Werewolf::setObserver(IWerewolfObserver* observer) { _observer = observer; }

void Werewolf::notifyObserver(int damage) {
    if (_observer != nullptr) {
        _observer->werewolfReact(damage);
    }
}