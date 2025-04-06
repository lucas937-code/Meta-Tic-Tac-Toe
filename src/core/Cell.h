#ifndef METATICTACTOE_CELL_H
#define METATICTACTOE_CELL_H

#include "BoardElement.h"
#include "Field.h"

/// @brief Represents one cell of a field and is the smallest unit of the board
class Cell : public BoardElement {
public:
    /// @brief Initializes a Cell with default values of the BoardElement default constructor and the owner to nullptr
    Cell();

    /**
     * @brief Initializes a Cell with given values
     * @param x x coordinate of the cell (pixels relative to top left corner of the window)
     * @param y y coordinate of the cell (pixels relative to top left corner of the window)
     */
    Cell(int x, int y, Field *owner);

    /**
     * @brief Getter for the owner field of the cell
     * @return pointer to the field that the cell belongs to
     */
    [[nodiscard]] Field *GetOwner();

    /**
     * @brief Uses the CELL_SIZE constant from the Constants namespace
     * @return size of the cell in pixels
     */
    [[nodiscard]] int GetSize() override;

private:
    Field *owner;
};

#endif
