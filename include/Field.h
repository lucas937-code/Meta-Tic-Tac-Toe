#ifndef METATICTACTOE_FIELD_H
#define METATICTACTOE_FIELD_H

#include <vector>
#include "Cell.h"

enum class Winner {
    NOT_SET, TIE, X, O
};

class Field {
public:
    Field(int x, int y);

    int x, y;

    [[nodiscard]] std::vector<std::vector<Cell>> GetCells() const;

    void Draw() const;

private:
    std::vector<std::vector<Cell>> cells;
    Winner winner;
};

#endif
