#include "Portal.h"

Portal::Portal(Field* field, IPortalObserver* observer)
        : FEvent(field), _new_pos({0, 0}), _observer(observer) {}

void Portal::react() {
    _new_pos.x = std::rand() % (_field->getWidth()); // NOLINT(cert-msc30-c, cert-msc50-cpp)
    _new_pos.y = std::rand() % (_field->getHeight()); // NOLINT(cert-msc30-c, cert-msc50-cpp)
    _field->setPlayerPosition(_new_pos);
    if (_observer) {
        _observer->portalReact();
    }
}

Event* Portal::clone() {
    auto event = new Portal(_field);
    event->_new_pos = _new_pos;
    return event;
}
