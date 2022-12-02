#include <iostream>
#include "Launcher.h"


int main() {
    Launcher launcher;
    launcher.start();
    launcher.quit();
    //Field field (5,5,{0,0});
    //std::cout << field.getPlayerPosition().x << field.getPlayerPosition().y <<'\n';
    //Gear gs(120);
    //field.getCell({1, 1}).changeEvent(&gs); // клетка (15,10) установлена непроходимой
    //Player player;
    //Controller player_controller(&player, &field);

    //player_controller.moveDown();
    //player_controller.moveRight();

    //std::cout << field.getPlayerPosition().x << field.getPlayerPosition().y<< '\n';
    //FieldPrinter printer(&field);
    //printer.printField(&field);

    //std::cout << player.getGearScore();

    //std::cout << player.changeGearScore(8);







    /*
    std::cout << field.getPlayerPosition().toString() << '\n'; // начальная позиция игрока

    player_controller.moveUp(2);
    std::cout << field.getPlayerPosition().toString() << '\n'; // перемещение на 2 вверх

    player_controller.moveRight(55);
    std::cout << field.getPlayerPosition().toString() << '\n'; // перемещение на 55 клеток вправо приводит нас к непроходимой (15,18),
                                                                // положение игрока не меняется
    player_controller.moveUp(); // еще шаг вверх переносит на (0,17)
    player_controller.moveRight(55); // с учетом нормализации конечное положение - (15,17)

    std::cout << field.getPlayerPosition().toString() << '\n'; */
    return 0;
}
