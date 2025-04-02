#ifndef METATICTACTOE_GAME_H
#define METATICTACTOE_GAME_H

#include "Field.h"
#include "raylib.h"
#include <vector>

const int WINDOW_SIZE = 1500;
const int BOARD_SIZE = WINDOW_SIZE - 150;
const int OFFSET = (WINDOW_SIZE - BOARD_SIZE) / 2;
const int FIELD_AMOUNT = 3;
const int CELL_SIZE = BOARD_SIZE / (FIELD_AMOUNT * FIELD_AMOUNT);

const Color CUSTOM_BG = {20, 20, 20};
const Color CUSTOM_RED = {181, 0, 0};
const Color CUSTOM_BLUE = {0, 51, 103};

class Game {
public:
    Game();

    ~Game();

    bool IsRunning() const;

    static void NextTurn();

    void Run(); // main loop running the game
private:
    std::vector<std::vector<Field>> fields;
    static bool isXTurn;
    bool isRunning;

    void HandleInput();

    void Update();

    void Draw();

    bool CheckWin();
};

#endif
