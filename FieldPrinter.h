#pragma once

#include "Field.h"


class FieldPrinter {
public:
   void printField ();
   explicit FieldPrinter (Field* field);
private:
    Field* _field;
};
