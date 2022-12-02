#ifndef GAME_C_GENERATOR_BORDERPLACER_H_
#define GAME_C_GENERATOR_BORDERPLACER_H_

#include "FieldScheme.h"

template <int XOffset, int YOffset, int Width, typename CellChanger>
class BorderPlacer {
 public:
  void apply(FieldScheme& scheme) {
    for (int i = YOffset; i < YOffset + Width; ++i) {
      for (int j = XOffset; j < scheme.width - XOffset - 1; ++j) {
        _changer.apply(scheme.data[i][j]);
      }
    }
    // ...
  }

 private:
  CellChanger _changer;
};

#endif
