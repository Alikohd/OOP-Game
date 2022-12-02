#include "Field.h"
#include "Fire.h"
#include "MeteorRain.h"
MeteorRain::MeteorRain(Player *player, Field *field) : PEvent(player), FEvent(field), _gear(5) {}

void MeteorRain::react() {
    auto field = _field;
    auto player = _player;
    if (_player->getGearScore() >= 0) {
        player->changeGearScore(-_gear);
    }
    int field_square = field -> getHeight()* field-> getWidth();
    int meteors_amount = std::rand() % (field_square/5); // NOLINT(cert-msc30-c, cert-msc50-cpp)
    int max_iter = 2 * meteors_amount;
    int iter_count = 0;
    while (meteors_amount > 0 && iter_count < max_iter)
    {
        iter_count++;
        int x = std::rand() % field -> getWidth(); // NOLINT(cert-msc30-c, cert-msc50-cpp)
        int y = std::rand() % field -> getHeight(); // NOLINT(cert-msc30-c, cert-msc50-cpp)
        auto cell = field ->getCell({x,y});
        if (cell.getEvent() != nullptr)
        {
            continue;
        }
        cell.changeEvent((new Fire(_player)));
        meteors_amount--;
    }
}

Event* MeteorRain::clone() {
    auto event = new MeteorRain(_player, _field);
    return event;
}

void MeteorRain::setObserver(IMeteorRainObserver* observer) {
    _observer = observer;
}