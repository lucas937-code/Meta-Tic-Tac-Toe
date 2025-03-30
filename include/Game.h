#ifndef METATICTACTOE_GAME_H
#define METATICTACTOE_GAME_H

#include "Board.h"
#include "raylib.h"

class Game {
public:
    Game();
    ~Game();
    bool IsRunning() const;
    const int WINDOW_WIDTH = 1500;
    const int WINDOW_HEIGHT = 1500;

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
