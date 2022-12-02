#include "FieldBuilder.h"

#include "../Player.h"
#include "../Field.h"
#include "FieldScheme.h"
#include "../Escape.h"
#include "../EventObservers/EscapeObserver.h"
#include "../Werewolf.h"
#include "../EventObservers/WerewolfObserver.h"
#include "../Fire.h"
#include "../EventObservers/FireObserver.h"
#include "../EnchantmentTable.h"
#include "../MeteorRain.h"
#include "../EventObservers/MeteorRainObserver.h"
#include "../Portal.h"
#include "../Gear.h"
#include "../EventObservers/GearObserver.h"

std::pair<Field*, Player*> FieldBuilder::make(const FieldScheme& scheme) {
    std::vector<std::vector<Cell>> cells{};
    cells.resize(scheme.height);
    for (int i = 0; i < scheme.height; ++i) {
        cells[i].resize(scheme.width);
    }
    auto* field = new Field(scheme.width, scheme.height, std::move(cells));
    auto* player = new Player();

    for (int i = 0; i < scheme.height; ++i) {
        for (int j = 0; j < scheme.width; ++j) {
            Cell& cell = field->_matrix[i][j];
            switch (scheme.data[i][j])  {
                case CellType::Empty:
                default:
                    break;
                case CellType::Wall:
                    cell.changePassable(false);
                    break;
                case CellType::Player:
                    cell.playerStepped();
                    field->setPlayerPosition({i, j});
                    break;
                case CellType::Escape:
                    cell.changeEvent(new Escape(player, new EscapeObserver()));
                    break;
                case CellType::Werewolf:
                    cell.changeEvent(new Werewolf(player, new WerewolfObserver));
                    break;
                case CellType::Fire:
                    cell.changeEvent(new Fire(player, new FireObserver));
                    break;
                case CellType::EnchantmentTable:
                    // TODO: Enchantment table observer Observer
                    cell.changeEvent(new EnchantmentTable(player));
                    break;
                case CellType::MeteorRain:
                    cell.changeEvent(new MeteorRain(player, field, new MeteorRainObserver()));
                    break;
                case CellType::Portal:
                    // TODO: Portal observer
                    cell.changeEvent(new Portal(field));
                    break;
                case CellType::Gear:
                    cell.changeEvent(new Gear(player, new GearObserver()));
                    break;
            }
        }
    }

    std::pair<Field*, Player*> out{field, player};
    return out;
}
