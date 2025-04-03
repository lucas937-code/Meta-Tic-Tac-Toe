#ifndef METATICTACTOE_FIELD_H
#define METATICTACTOE_FIELD_H

#include <vector>
#include "Cell.h"

/// Enum class that is used to declare the winner of \b one \b field
enum class Winner {
    NOT_SET,     ///< No winner yet
    TIE,         ///< Tie on the field
    X,           ///< player X has won this field
    O            ///< player O has one this field
};

/**
 * Represents one of the 9 fields of the whole board\n
 * contains 9 cells
 */
class Field {
public:
    /**
     * Initializes the cells of the field
     * @param x x coordinate of the field (pixels relative to top left corner of the window)
     * @param y y coordinate of the field (pixels relative to top left corner of the window)
     */
    Field(int x, int y);

    /**
     * Getter of field "cells"
     * @return reference to object "cells"
     */
    [[nodiscard]] std::vector<std::vector<Cell>> &GetCells();

    /// Draws cells of the field
    void Draw() const;

    /**
     * Getter of field "x"\n
     * x = x coordinate of the cell (pixels relative to top left corner of the window)
     * @return copy of "x"
     */
    [[nodiscard]] int GetX() const;

    /**
     * Getter of field "y"\n
     * y = y coordinate of the cell (pixels relative to top left corner of the window)
     * @return copy of "y"
     */
    [[nodiscard]] int GetY() const;

private:
    std::vector<std::vector<Cell>> cells;
    Winner winner;
    int x, y;
};

#endif
