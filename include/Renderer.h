#ifndef METATICTACTOE_RENDERER_H
#define METATICTACTOE_RENDERER_H

#include <string>
#include "Field.h"
#include "Cell.h"
#include "raylib.h"

class Renderer {
public:
    /// Draws the lines that make up the board
    static void DrawBoard();

    /// Loads the textures for the pictures
    static void LoadTextures();

    /// Unloads the textures for the pictures
    static void UnloadTextures();

    /// Fills the cell with a X or O depending on its state
    static void FillCell(const Cell* cell);

    /// Marks the field according to the winner
    static void FillField(Field &field);

private:
    static std::unordered_map<std::string, Texture2D> textureMap;
};

#endif
