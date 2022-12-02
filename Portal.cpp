#include "Portal.h"

Portal::Portal(Field *field) : FEvent(field), _new_pos({0,0}) {}

void Portal::react() {
    _new_pos.x = std::rand() % (_field->getWidth()); // NOLINT(cert-msc30-c, cert-msc50-cpp)
    _new_pos.y = std::rand() % (_field->getHeight()); // NOLINT(cert-msc30-c, cert-msc50-cpp)
    _field->getCell(_field->getPlayerPosition()).playerLeft();
    _field -> setPlayerPosition (_new_pos);
    _field ->getCell(_new_pos).playerStepped();
}

Event *Portal::clone() {
    auto event = new Portal(_field);
    event ->_new_pos = _new_pos;
    return event;
}
