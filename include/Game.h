#ifndef METATICTACTOE_GAME_H
#define METATICTACTOE_GAME_H

#include "Field.h"
#include "Cell.h"
#include "raylib.h"
#include <vector>
#include <map>

/**
 * Represents a Meta-Tic-Tac-Toe game
 */
class Game : public Winnable {
public:
    /// Creates the window, loads the textures and initializes the fields
    Game();

    /// Cleans up the game after it's finished
    ~Game();

    /**
     * Getter for the target field (field that must be played on next)
     */
    [[nodiscard]] static Field *GetTargetField();

    /// Negates "isXTurn" and updates the log message
    static void NextTurn();

    /**
     * Contains the main loop of the game
     * @return winner of the game
     */
    State Run();

    /// Draws all elements of the game into the window
    void Draw();

private:
    static bool isXTurn;
    static Field *targetField;

    Field *DetermineTargetField(Cell &cell);

    Field *HandleInput();
};

#endif
