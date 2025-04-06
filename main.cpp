#include <iostream>
#include "include/Game.h"
#include "include/WindowManager.h"

#include <memory>

int main() {
    if (!WindowManager::InitializeWindow()) {
        std::cerr << "Error occurred while starting the game" << std::endl;
        return 1;
    }

    while (!WindowShouldClose()) {
        std::unique_ptr<Game> game = std::make_unique<Game>();

        WindowManager::ShowEndScreen(game.operator*(), game->Run());
    }

    return 0;
}
