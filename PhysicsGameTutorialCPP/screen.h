// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
// ~ By Wilson - 'screen.h'
//
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#pragma once

#include <SDL2/SDL.h>

class Screen {
public:
    Screen(int resX, int resY);
    SDL_Window* window;
    SDL_Renderer* renderer;
};