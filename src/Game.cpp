#include "Game.h"

Game::Game() {
    initEngine();
}

Game::Game(HINSTANCE hInstance) {
  this->hInstance = hInstance;
    initEngine();
}

void Game::init() {

}

FAScene* Game::setInitialScene() {
    return new FAScene();
}

void Game::setWindowAttributes() {
    this->setWindowsSize(1240, 720);
    this->setSamples(4);
    this->setDecorated(false);
    // this->setWindowColor(glm::vec3(95.0/255.0,95.0/255.0,95.0/255.0));
}

Game::~Game() {

}
