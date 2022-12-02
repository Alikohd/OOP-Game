#include "Launcher.h"
#include <iostream>
#include <unistd.h>
#include "LoggerConfigurator.h"
#include "Werewolf.h"
#include "Controller.h"
#include "Player.h"
#include "Fire.h"
#include "EnchantmentTable.h"
#include "Escape.h"
#include "MeteorRain.h"
#include "Portal.h"
#include "Logger.h"
#include "FLogger.h"
#include "ConcoleLogger.h"
#include "FieldPrinter.h"
#include "ControlSchemeFileManager.h"
#include "KeyboardReader.h"

Launcher::Launcher()
: _game_proceed(false), _app_controller(this), _controller(Controller{&_player, &_field}),
 _player_observer(PlayerObserver{this}), _field_observer({}), _printer(&_field) {

    LoggerConfigurator::accomplish();
    _input_mediator.addController(&_controller);

    ControlSchemeFileManager control_scheme_manager;
    auto scheme = control_scheme_manager.scan();
    auto* keyboard_reader = new KeyboardReader();
    keyboard_reader->setScheme(scheme);
    _input_mediator.addReader(keyboard_reader);
    _input_mediator.addController(&_controller);



    _player.setObserver(&_player_observer);
    _field.setObserver(&_field_observer);


    _player_observer << _player;
    _field_observer << _field;

    auto werewolf = new Werewolf(&_player);
    werewolf->setObserver(&_werewolf_observer);
    _field.changeCellEvent({0, 1}, werewolf);
    auto exit = new Escape(&_player);
    exit->setObserver(&_escape_observer);

//    _field.changeCellPassable({1,0},false);
    _field.changeCellEvent({2, 2}, exit);

}

void Launcher::start() {
    _game_proceed = true;
    Logger::getInstance() << LoggerMessage{"Application started", Logger::Info};
    while (_game_proceed) {
        // Game loop
        _input_mediator.update();

        usleep(100000*0.75);
    }

    system("pause");

}

void Launcher::quit() {
    _game_proceed = false;
    Logger::getInstance() << LoggerMessage{"Application is closing", Logger::Info};
}

// итого: - балл за разбиение по папкам, - балл за то что ломается файл, - балл for в ридерах.