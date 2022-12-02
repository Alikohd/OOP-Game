#include "Escape.h"
#include "Player.h"

Escape::Escape(Player *player): PEvent(player), _lock(false), _gear_plank(1000){}

void Escape::react() {
    auto player = _player;
    if (!_lock || player->getGearScore() >= _gear_plank)
        player->win();
}

Event* Escape::clone() {
    auto event = new Escape(_player);
    event -> _lock = _lock;
    event ->_gear_plank = _gear_plank;
    return event;
}

void Escape::setObserver(IEscapeObserver* observer) {
    _observer = observer;
}
