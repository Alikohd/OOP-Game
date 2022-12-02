#include "Gear.h"
#include "Player.h"

Gear::Gear(Player* player, IGearObserver* observer)
        : PEvent(player), _score(50), _isActive(true), _observer(observer) {}

void Gear::react() {
    if (!_isActive)
        return;
    auto* player = _player;
    player->changeGearScore(_score);
}

Event* Gear::clone() {
    auto event = new Gear(_player);
    event->_isActive = _isActive;
    event->_score = _score;
    return event;
}

void Gear::setObserver(IGearObserver* observer) {
    _observer = observer;
}