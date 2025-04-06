#ifndef METATICTACTOE_FIELD_H
#define METATICTACTOE_FIELD_H

#include "BoardElement.h"
#include "Winnable.h"

/**
 * @brief Represents one of the 9 fields of the whole board that Contains 9 cells.
 * It inherits from both BoardElement and Winnable
 */
class Field : public BoardElement, public Winnable {
public:
    /**
     * @brief Initializes the cells of the field
     * @param x x coordinate of the field (pixels relative to top left corner of the window)
     * @param y y coordinate of the field (pixels relative to top left corner of the window)
     */
    Field(int x, int y);

    /// @brief Deletes all the cells the field contains
    ~Field() override;

    /// @brief Draws cells of the field
    void Draw();

    /**
     * @brief Uses the FIELD_SIZE constant from the Constants namespace
     * @return size of the field in pixels
     */
    [[nodiscard]] int GetSize() override;
};

#endif
