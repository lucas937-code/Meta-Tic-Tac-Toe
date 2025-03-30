#ifndef METATICTACTOE_GAME_H
#define METATICTACTOE_GAME_H

#include "Board.h"
#include "raylib.h"

const int WINDOW_SIZE = 1500;

class Game {
public:
    Game();
    ~Game();
    bool IsRunning() const;

    void Run(); // main loop running the game
private:
    // Board mainBoard;
    bool isXTurn;
    bool isRunning;

    void HandleInput();

    void Update();

    void Draw();

    bool CheckWin();
};

#endif
