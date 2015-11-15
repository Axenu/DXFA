#include <iostream>
#include <windows.h>
#include "Game.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {

     Game *game = new Game(hInstance);
     game->run();



    delete game;
    // int i = 0;
    // std::cin >> i;
    return 0;
}
