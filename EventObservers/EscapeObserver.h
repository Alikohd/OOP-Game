#ifndef GAME_C___ESCAPEOBSERVER_H
#define GAME_C___ESCAPEOBSERVER_H


#include "../Escape.h"

class EscapeObserver : public IEscapeObserver {
public:
    void EscapeReacted() override;
};


#endif //GAME_C___ESCAPEOBSERVER_H
