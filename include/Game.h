#ifndef METATICTACTOE_GAME_H
#define METATICTACTOE_GAME_H

#include "Board.h"

class Game {
public:
    Game();

    void Run(); // main loop running the game
private:
    Board mainBoard;
    bool isXTurn;

    void HandleInput();

    void Update();

    void Draw();

    bool CheckWin();
};

#endif
