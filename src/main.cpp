#include <iostream>
#include <windows.h>
#include "Game.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {

     Game *game = new Game(hInstance);

    while (game->shouldTerminate()) {
        game->update();
        game->render();
    }

    delete game;
    int i = 0;
    std::cin >> i;
    return 0;
}
