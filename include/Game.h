#ifndef METATICTACTOE_GAME_H
#define METATICTACTOE_GAME_H

#include "Field.h"
#include "raylib.h"
#include <vector>
#include <map>

const int WINDOW_SIZE = 1500;
const int BOARD_SIZE = WINDOW_SIZE - 150;
const int OFFSET = (WINDOW_SIZE - BOARD_SIZE) / 2;
const int FIELD_AMOUNT = 3;
const int CELL_SIZE = BOARD_SIZE / (FIELD_AMOUNT * FIELD_AMOUNT);
const int FIELD_SIZE = BOARD_SIZE / FIELD_AMOUNT;

const Color CUSTOM_BG = {20, 20, 20};
const Color CUSTOM_RED = {181, 0, 0, 255};
const Color CUSTOM_BLUE = {0, 93, 143, 255};

class Game {
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

    /// Negates "isXTurn"
    static void NextTurn();

    /// Starts the main loop of the game
    void Run();

private:
    std::vector<std::vector<Field>> fields;
    // must use a map instead of an unordered_map here because there is no hash function for pair :(
    std::map<std::pair<int, int>, Field *> fieldMap;
    static bool isXTurn;
    bool isRunning;
    static Field *targetField;

    void SetTargetField(Cell &cell);

    Field *HandleInput();

    void Draw();

    //bool CheckWin();
};

#endif
