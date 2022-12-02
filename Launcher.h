#ifndef GAME_C___LAUNCHER_H
#define GAME_C___LAUNCHER_H
#include "ApplicationController.h"
//#include "EnchantmentTableObserver.h"
#include "EscapeObserver.h"
#include "FireObserver.h"
#include "GearObserver.h"
#include "MeteorRainObserver.h"
//#include "PortalObserver.h"
#include "WerewolfObserver.h"

#include "Field.h"
#include "Player.h"
#include "Controller.h"
#include "PlayerObserver.h"
#include "FieldObserver.h"
#include "FieldPrinter.h"
#include "InputMediator.h"

class Launcher {
public:
    Launcher();
    void start();
    void quit();
private:
    bool _game_proceed;
    Field _field;
    Player _player;
    Controller _controller;
    PlayerObserver _player_observer;
    FieldObserver _field_observer;
    FieldPrinter _printer;
    InputMediator _input_mediator;
    ApplicationController _app_controller;

    //EnchantmentTableObserver _enchantment_table_observer;
    EscapeObserver _escape_observer;
    FireObserver _fire_observer;
    GearObserver _gear_observer;
    MeteorRainObserver _meteor_rain_observer;
    //PortalObserver _portal_observer;
    WerewolfObserver _werewolf_observer;
};


#endif //GAME_C___LAUNCHER_H
