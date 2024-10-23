//
// Created by remzi isci on 23.10.2024.
//

#ifndef GAME_H
#define GAME_H

#include "SDL2/SDL.h"

class Game
{
private:

public:
    Game();
    ~Game();
    void Initialize();
    void Run();
    void ProcessInput();
    void Update();
    void Render();
    void Destroy();
    int windowWidth;
    int windowHeight;

private:
    SDL_Renderer* renderer;
    SDL_Window* window;
    bool isRunning;
};


#endif //GAME_H
