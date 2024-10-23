//
// Created by remzi isci on 23.10.2024.
//

#include "Game.h"

#include <iostream>
#include <SDL_events.h>


Game::Game()
{
    std::cout << "Game Constructor Called" << std::endl;
}

Game::~Game()
{
    std::cout << "Game Destructor Called" << std::endl;
}

void Game::Initialize()
{
    //Construct SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return;
    }
    SDL_DisplayMode* displayMode = new SDL_DisplayMode();
    SDL_GetCurrentDisplayMode(0, displayMode);
    windowWidth = displayMode->w;
    windowHeight = displayMode->h;
    free(displayMode);
    displayMode = nullptr;
    //Setup window
    window = SDL_CreateWindow(
        "Polarium Game",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        windowWidth,
        windowHeight,
        SDL_WINDOW_OPENGL | SDL_WINDOW_BORDERLESS);
    if (!window)
    {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        return;
    }

    //Setup renderer
    renderer = SDL_CreateRenderer(window,
                                  -1,
                                  SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer)
    {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
    }
    SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
    isRunning = true;
}

void Game::Run()
{
    while (isRunning)
    {
        ProcessInput();
        Update();
        Render();
    }
}

void Game::Update()
{
}

void Game::ProcessInput()
{
    SDL_Event sdlEvent;

    while (SDL_PollEvent(&sdlEvent) > 0)
    {
        switch (sdlEvent.type)
        {
        case SDL_QUIT:
            isRunning = false;
            break;
        case SDL_KEYDOWN:
            if (sdlEvent.key.keysym.sym == SDLK_ESCAPE)
            {
                isRunning = false;
            }
            break;;
        }
    }
}

void Game::Render()
{
    SDL_SetRenderDrawColor(renderer, 200, 100, 50, 100);
    SDL_RenderClear(renderer);

    //TODO: Render all game objects
    SDL_RenderPresent(renderer);
}

void Game::Destroy()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

