#ifndef GAME_C___FIELDGENERATOR_H
#define GAME_C___FIELDGENERATOR_H


#include "../Field.h"
#include "FieldScheme.h"
#include "FieldBuilder.h"

struct FieldGeneratorOutput {
    Field* field;
    Player* player;
};

template<int Width, int Height, typename... Rules>
class FieldGenerator {
public:
    FieldGeneratorOutput make() {
        std::vector<std::vector<CellType>> cells{};
        cells.resize(Height);
        for (int i = 0; i < Width; ++i) {
            cells[i].resize(Width);
        }
        FieldScheme scheme{cells, Width, Height};

        (apply<Rules>(scheme), ...);

        FieldBuilder builder;
        auto out = builder.make(scheme);
        FieldGeneratorOutput generator_out{out.first, out.second};
        return generator_out;
    };

private:
    template<typename Rule>
    void apply(FieldScheme& scheme) {
        Rule rule;
        rule.apply(scheme);
    }
};


#endif //GAME_C___FIELDGENERATOR_H
