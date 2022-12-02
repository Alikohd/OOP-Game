#ifndef GAME_C___ENCHANTMENTTABLE_H
#define GAME_C___ENCHANTMENTTABLE_H
#include "PEvent.h"

class EnchantmentTable: public PEvent {
private:
    int _gearScore, _health;
    bool _isActive;
public:
    explicit EnchantmentTable(Player *player);
    void react() override;
    Event* clone() override;
};


#endif //GAME_C___ENCHANTMENTTABLE_H
