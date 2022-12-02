#include "KeyboardReader.h"

#include <utility>

#ifdef _WIN32
#include <windows.h>
#endif

void KeyboardReader::process() {
#ifdef _WIN32
    static constexpr int kKeyPressed = 0x8000;
    for (const auto& pair : _control_scheme.data) {
        if ((GetAsyncKeyState(pair.first) & kKeyPressed) != 0) {
            notify(pair.second);
        }
    }
#endif
}

void KeyboardReader::setScheme(ControlScheme control_scheme) {
    _control_scheme = std::move(control_scheme);
}