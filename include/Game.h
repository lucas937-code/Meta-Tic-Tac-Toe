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

class Game {
public:
    Game();

    ~Game();

    bool IsRunning() const;

    void Run(); // main loop running the game
private:
    std::vector<std::vector<Field>> fields;
    bool isXTurn;
    bool isRunning;

    void HandleInput();

    void Update();

    void Draw();

    bool CheckWin();
};

#endif
