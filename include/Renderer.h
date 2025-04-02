#ifndef METATICTACTOE_RENDERER_H
#define METATICTACTOE_RENDERER_H

#include "Field.h"
#include "Cell.h"
#include "raylib.h"

class Renderer {
public:
    static void DrawBoard();

    static void LoadTextures();

    static void UnloadTextures();

    static void DrawCell(const Cell &cell);

private:
    static Texture2D xTexture;
    static Texture2D oTexture;
};

#endif
