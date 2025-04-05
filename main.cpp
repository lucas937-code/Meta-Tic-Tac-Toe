#include <iostream>
#include "include/Game.h"

int main() {
    Game game;

    if (!game.IsRunning()) {
        std::cerr << "Error occurred while starting the game" << std::endl;
        return 1;
    }

    game.Run();
    return 0;
}
