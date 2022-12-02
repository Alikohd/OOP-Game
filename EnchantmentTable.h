#ifndef GAME_C___ENCHANTMENTTABLE_H
#define GAME_C___ENCHANTMENTTABLE_H

#include "PEvent.h"

class IEnchantmentTableObserver {
public:
    virtual ~IEnchantmentTableObserver() = default;
    virtual void enchantmentTableReact() = 0;
};

class EnchantmentTable : public PEvent {
private:
    int _gearScore, _health;
    bool _isActive;
    IEnchantmentTableObserver* _observer;

public:
    explicit EnchantmentTable(Player* player, IEnchantmentTableObserver* observer = nullptr);
    void react() override;
    Event* clone() override;
};


#endif //GAME_C___ENCHANTMENTTABLE_H
