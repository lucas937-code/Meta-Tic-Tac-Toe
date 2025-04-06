#pragma once

#include "raylib.h"

/// Provides global constants that are useful at various places in the project
namespace Constants {
    /**
     * @brief The size of the window in pixels.
     * This value is used to define the main window dimensions.
     */
    constexpr int WINDOW_SIZE = 1500;

    /**
     * @brief The size of the board, based on the window size.
     * This is calculated as the window size minus a fixed offset.
     */
    constexpr int BOARD_SIZE = WINDOW_SIZE - 150;

    /**
     * @brief The offset that centers the board inside the window.
     * This value is calculated as half of the difference between the window size and the board size.
     */
    constexpr int OFFSET = (WINDOW_SIZE - BOARD_SIZE) / 2;

    /**
     * @brief The number of fields on the board (3x3).
     * This value defines the grid layout of the game board.
     */
    constexpr int FIELD_AMOUNT = 3;

    /**
     * @brief The size of a single cell on the board.
     * This is calculated based on the board size and the number of fields.
     */
    constexpr int CELL_SIZE = BOARD_SIZE / (FIELD_AMOUNT * FIELD_AMOUNT);

    /**
     * @brief The size of a single field on the board.
     * This value represents the size of each 3x3 sub-board in the game.
     */
    constexpr int FIELD_SIZE = BOARD_SIZE / FIELD_AMOUNT;

    /// @brief The background color used in the game.
    constexpr Color CUSTOM_BG = {20, 20, 20};

    /// @brief The color red used for elements in the game.
    constexpr Color CUSTOM_RED = {181, 0, 0, 255};

    /// @brief The color blue used for elements in the game.
    constexpr Color CUSTOM_BLUE = {0, 93, 143, 255};
}