// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
// ~ By Wilson - 'screen.cpp'
//
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


#include "screen.h"
#include <iostream>

Screen::Screen(int resX, int resY, std::string title)
{
    if(SDL_Init(SDL_INIT_EVERYTHING) >= 0)
    {
        std::cout << "successfully init sdl" << std::endl;
        
        window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, resX, resY, SDL_WINDOW_INPUT_FOCUS);
        
        if (window != 0)
        {
            std::cout << "successfully created window!" << std::endl;
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
            if (renderer != 0)
            {
                std::cout << "successfully created window!"  << std::endl;
            }
        }
        else
        {
            std::cout << "couldn't create my window!" << std::endl;
        }
    }
    
}