#include "EnchantmentTable.h"
#include "Player.h"

EnchantmentTable::EnchantmentTable(Player* player, IEnchantmentTableObserver* observer)
        : PEvent(player), _gearScore(50), _health(10), _isActive(true), _observer(observer) {}

void EnchantmentTable::react() {
    if (!_isActive)
        return;
    _isActive = false;
    auto* player = _player;
    player->changeGearScore(_gearScore);
    player->changeHealth(_health);
}

Event* EnchantmentTable::clone() {
    auto event = new EnchantmentTable(_player);
    event->_isActive = _isActive;
    event->_gearScore = _gearScore;
    event->_health = _health;
    return event;
}