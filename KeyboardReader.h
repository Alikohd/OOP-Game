#ifndef GAME_C___KEYBOARDREADER_H
#define GAME_C___KEYBOARDREADER_H


#include "ControlScheme.h"
#include "InputReader.h"

class KeyboardReader : public InputReader {
public:
    void process() override;
    void setScheme(ControlScheme control_scheme);

private:
    ControlScheme _control_scheme;
};


#endif //GAME_C___KEYBOARDREADER_H
