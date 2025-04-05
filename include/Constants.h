#pragma once

#include "raylib.h"

namespace Constants {
    constexpr int WINDOW_SIZE = 1500;
    constexpr int BOARD_SIZE = WINDOW_SIZE - 150;
    constexpr int OFFSET = (WINDOW_SIZE - BOARD_SIZE) / 2;
    constexpr int FIELD_AMOUNT = 3;
    constexpr int CELL_SIZE = BOARD_SIZE / (FIELD_AMOUNT * FIELD_AMOUNT);
    constexpr int FIELD_SIZE = BOARD_SIZE / FIELD_AMOUNT;

    constexpr Color CUSTOM_BG = {20, 20, 20};
    constexpr Color CUSTOM_RED = {181, 0, 0, 255};
    constexpr Color CUSTOM_BLUE = {0, 93, 143, 255};
}