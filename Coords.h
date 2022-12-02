#pragma once

#include <string>

struct Coords {
    int x;
    int y;

    explicit operator std::string() const {
        return '(' + std::to_string(x) + ", " + std::to_string(y) + ')';
    }
};