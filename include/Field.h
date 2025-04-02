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

    [[nodiscard]] std::vector<std::vector<Cell>> &GetCells();

    void Draw() const;

    [[nodiscard]] int GetX() const;

    [[nodiscard]] int GetY() const;

private:
    std::vector<std::vector<Cell>> cells;
    Winner winner;
    int x, y;
};

#endif
