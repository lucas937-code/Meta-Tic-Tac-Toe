#ifndef METATICTACTOE_GAME_H
#define METATICTACTOE_GAME_H

#include "Field.h"
#include "Cell.h"
#include "raylib.h"
#include <vector>
#include <map>

class Game : public Winnable {
public:
    /// Creates the window, loads the textures and initializes the fields
    Game();

    /// Cleans up the program after it finished
    ~Game();

    /**
     * Determines whether the game started successfully
     * @return copy of "isRunning"
     */
    [[nodiscard]] bool IsRunning() const;

    /**
     * Getter for the target field (field that must be played on next)
     */
    [[nodiscard]] static Field *GetTargetField();

    /// Negates "isXTurn" and updates the log message
    static void NextTurn();

    /// Starts the main loop of the game
    void Run();

private:
    static bool isXTurn;
    bool isRunning;
    static Field *targetField;

    Field *DetermineTargetField(Cell &cell);

    Field *HandleInput();

    void Draw();
};

#endif
