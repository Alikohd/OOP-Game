#include "FieldPrinter.h"
#include <iostream>
void FieldPrinter::printField() {
std::cout << "Printer Work..." << '\n';
    for (int i = 0; i < _field -> getHeight(); i++ ){
        for (int j = 0; j < _field -> getWidth(); j++){
            if (_field -> getCell({j, i}).isPlayerHere())
                std::cout << "P";
            else if (_field -> getCell({j, i}).getEvent())
                std::cout << 'E';
            else if (_field -> getCell({j, i}).isPassable())
                std::cout << 'o';
            else std::cout << '#';


        }

    std::cout << '\n';
    }
}



FieldPrinter::FieldPrinter(Field *field): _field(field) {}
