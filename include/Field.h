#ifndef METATICTACTOE_FIELD_H
#define METATICTACTOE_FIELD_H

#include "BoardElement.h"
#include "Winnable.h"

/**
 * Represents one of the 9 fields of the whole board\n
 * Contains 9 cells\n
 * Inherits from BoardElement and Winnable
 */
class Field : public BoardElement, public Winnable {
public:
    /**
     * Initializes the cells of the field
     * @param x x coordinate of the field (pixels relative to top left corner of the window)
     * @param y y coordinate of the field (pixels relative to top left corner of the window)
     */
    Field(int x, int y);

    /// Draws cells of the field
    void Draw() const;
};

#endif
