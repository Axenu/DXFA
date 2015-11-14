#include <iostream>
#include "Game.h"

int main()
{

     Game *game = new Game();

    while (game->shouldTerminate()) {
        game->update();
        game->render();
    }

    delete game;
    int i = 0;
    std::cin >> i;
    return 0;
}
