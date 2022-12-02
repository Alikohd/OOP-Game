#ifndef GAME_C_GENERATOR_CELLCHANGER_H_
#define GAME_C_GENERATOR_CELLCHANGER_H_

#include "FieldScheme.h"

template<CellType Type>
class CellChanger {
  public:
  void apply(CellType& cell) {
    if (cell != CellType::Empty) {
      return;
    }
    cell = Type;
  }
};

#endif
