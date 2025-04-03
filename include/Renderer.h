#ifndef METATICTACTOE_RENDERER_H
#define METATICTACTOE_RENDERER_H

#include <string>
#include "Field.h"
#include "Cell.h"
#include "raylib.h"

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

    /// Fills the cell with a X or O depending on its state
    static void FillCell(const Cell* cell);

    /// Marks the field according to the winner
    static void FillField(Field &field);

    /// Draws a red rectangle around the target field
    static void MarkTargetField(bool isXTurn);

private:
    static std::unordered_map<std::string, Texture2D> textureMap;
    static std::string logMessage;
};

#endif
