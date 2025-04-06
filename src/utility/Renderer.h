#ifndef METATICTACTOE_RENDERER_H
#define METATICTACTOE_RENDERER_H

#include <string>
#include "../core/Cell.h"
#include "raylib.h"

/**
 * Class with all static functions that draw the content in the window
 */
class Renderer {
public:
    /**
     * Setter for the log message (message on the bottom left corner of the window)
     * @param msg new message
     */
    static void SetLogMessage(std::string msg);

    /// Draws the lines that make up the board
    static void DrawBoard();

    /// Shows the current log message
    static void ShowLogMessage();

    /// Loads the textures for the pictures
    static void LoadTextures();

    /// Unloads the textures for the pictures
    static void UnloadTextures();

    /**
     * Marks the cell with an X or O depending on its state
     * @param cell cell to fill
     */
    static void MarkCell(const Cell *cell);

    /**
     * Marks the field according to the winner
     * @param field field to mark
     */
    static void MarkFieldWinner(const Field *field);

    /**
     * Draws a red rectangle around the target field
     * @param isXTurn whose turn it is
     */
    static void MarkTargetField(bool isXTurn);

    /**
     * Draws the end screen (semi-transparent background, show winner, "press R to restart")
     * @param winner winner of the game
     */
    static void DrawEndScreen(State winner);

private:
    static std::unordered_map<std::string, Texture2D> textureMap;
    static std::string logMessage;
};

#endif
