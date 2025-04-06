#ifndef METATICTACTOE_GAME_H
#define METATICTACTOE_GAME_H

#include "Field.h"
#include "Cell.h"
#include "raylib.h"
#include <vector>
#include <map>

/// @brief Represents a Meta-Tic-Tac-Toe game
class Game : public Winnable {
public:
    /// @brief Creates the window, loads the textures and initializes the fields
    Game();

    /// @brief Frees the allocated space that was used for the fields & unloads the textures
    ~Game();

    /**
     * @brief Getter for the target field (field that must be played on next)
     * @return pointer to the field that must be clicked next or nullptr if the next player has free choice
     */
    [[nodiscard]] static Field *GetTargetField();

    /// @brief Negates "isXTurn" and updates the log message
    static void NextTurn();

    /**
     * @brief Contains the main loop of the game
     * @return winner of the game
     */
    State Run();

    /// @brief Draws all elements of the game into the window
    void Draw();

private:
    static bool isXTurn;
    static Field *targetField;

    Field *DetermineTargetField(Cell &cell);

    Field *HandleInput();
};

#endif
