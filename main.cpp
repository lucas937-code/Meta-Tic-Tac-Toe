#include "raylib.h"

int main() {
    InitWindow(1500, 1500, "Raylib mit CLion");

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Raylib funktioniert!", 300, 280, 20, DARKBLUE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
