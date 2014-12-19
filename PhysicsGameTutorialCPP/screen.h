// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
// ~ By Wilson - 'screen.h'
//
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#pragma once

#include <SDL2/SDL.h>
#include <string>

class Screen {
public:
    Screen(int resX, int resY, std::string title);
    SDL_Window* window;
    SDL_Renderer* renderer;
};