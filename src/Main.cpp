#include <iostream>
#include <SDL.h>

int main() {
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* _window = SDL_CreateWindow("Tests", 100, 100, 512, 512, SDL_WINDOW_SHOWN);
    if(!_window)
    {
        std::cout << "Failed to create window\n";
        return -1;
    }

    SDL_Surface* _surface = SDL_GetWindowSurface(_window);
    if(!_surface){
        std::cout << "Failed to get the surface from the window\n";
        return -1;
    }

    bool keep_window_open = true;
    while(keep_window_open)
    {
        SDL_Event e;
        while(SDL_PollEvent(&e) > 0)
        {
            switch(e.type)
            {
                case SDL_QUIT:
                    keep_window_open = false;
                break;
            }

            SDL_UpdateWindowSurface(_window);
        }
    }
}
