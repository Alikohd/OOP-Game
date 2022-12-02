#include "PlayerObserver.h"
#include "Launcher.h"
#include "Logger.h"
#include <iostream>

PlayerObserver::PlayerObserver(Launcher* launcher) : _launcher(launcher) {}

void PlayerObserver::healthChanged(Player* player) {
    Logger::getInstance() << LoggerMessage{"Health changed to " + std::to_string(player->getHealth()), Logger::Action};
    if (player->getHealth() <= 0) {
        Logger::getInstance() << LoggerMessage{"You died!", Logger::Action};
        _launcher->quit();
    }
}

void PlayerObserver::win_reached() {
    Logger::getInstance() << LoggerMessage{"You win!", Logger::Action};
    _launcher->quit();
}

void PlayerObserver::gearScoreChanged(Player* player) {
    Logger::getInstance() << LoggerMessage{"Score changed to " + std::to_string(player->getGearScore()), Logger::Action};
}

void PlayerObserver::damageChanged(Player *player)  {
    Logger::getInstance() << LoggerMessage{"Damage changed to " + std::to_string(player->getDamage()), Logger::Action};
}

PlayerObserver& PlayerObserver::operator<<(const Player& player) {
    Logger::getInstance() << LoggerMessage{
            "Player: score = " + std::to_string(player.getGearScore()) + ", health = " + std::to_string(player.getHealth())
            + ", damage = " + std::to_string(player.getDamage()), Logger::Info};
    return *this;
}

