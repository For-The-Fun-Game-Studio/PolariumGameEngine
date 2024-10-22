//
// Created by remzi isci on 23.10.2024.
//

#include "Game.h"

#include <iostream>

Game::Game() {
std::cout<<"Game Constructor Called"<<std::endl;
}

Game::~Game() {
    std::cout<<"Game Destructor Called"<<std::endl;
}

void Game::Initialize() {

}
void Game::Run() {
    while (true) {
        ProcessInput();
        Update();
        Render();
    }
}

void Game::Update() {}
void Game::ProcessInput() {

}

void Game::Render() {}
void Game::Destroy() {

}

