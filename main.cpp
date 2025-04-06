#include <iostream>
#include "src/core/Game.h"
#include "src/utility/WindowManager.h"

#include <memory>
#include <raylib.h>

int main() {
    if (!WindowManager::InitializeWindow()) {
        std::cerr << "Error occurred while starting the game" << std::endl;
        return 1;
    }
    while (!WindowShouldClose()) {
        auto game = std::make_unique<Game>();
        while (WindowManager::ShowEndScreen(game.operator*(), game->Run())) {
        }
    }
    return 0;
}
