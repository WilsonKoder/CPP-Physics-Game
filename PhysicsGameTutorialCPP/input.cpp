// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
// ~ By Wilson - 'input.cpp'
//
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include "input.h"

#include <SDL2/SDL.h>
#include <iostream>

void Input::handleEvents(Screen window, std::vector<Circle> *circles, cpSpace space, int *radius, int *gravity, int *wind)
{
    SDL_Event e;
    while(SDL_PollEvent(&e))
    {
        switch (e.type) {
            case SDL_QUIT:
                running = false;
                break;
            
            case SDL_KEYDOWN:
                if(e.key.keysym.sym == SDLK_c)
                {
                    std::cout << "clear!" << std::endl;
                    std::cout << "could not clear, current clearing causes crash due to EXC_BAD_ACCESS." << std::endl;
                }
                else if(e.key.keysym.sym == SDLK_w)
                {
                    gravity -= 100;
                    cpSpaceSetGravity(&space, cpv(*wind, *gravity));
                }
                else if(e.key.keysym.sym == SDLK_s)
                {
                    gravity += 100;
                    cpSpaceSetGravity(&space, cpv(*wind, *gravity));
                }
                break;
                
            case SDL_MOUSEBUTTONDOWN:
            {
                int x, y;
                SDL_GetMouseState(&x, &y);
                cpVect pos = cpv(x, y);
                Circle* newTempCircle = new Circle();
                newTempCircle->initCircle(window.renderer);
                cpShape newCircle = newTempCircle->createCircle(*radius, &space, pos);
                circles->insert(circles->end(), *newTempCircle);
                break;
            }
            default:
                break;
            
                
        }
    }
}

bool Input::isRunning()
{
    return running;
}