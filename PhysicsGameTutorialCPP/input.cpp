// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
// ~ By Wilson - 'input.cpp'
//
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include "input.h"

#include <SDL2/SDL.h>
#include <iostream>

void Input::handleEvents(Screen window, std::vector<Circle> *circles, cpSpace space)
{
    SDL_Event e;
    while(SDL_PollEvent(&e))
    {
        switch (e.type) {
            case SDL_QUIT:
            {
                running = false;
                break;
            }
            case SDL_KEYDOWN:
            {
                switch (e.key.keysym.sym) {
                    case SDLK_c:
                        std::cout << "clear!" << std::endl;
                        std::cout << "could not clear, current clearing causes crash due to EXC_BAD_ACCESS." << std::endl;
                        break;
                    default:
                        break;
                }
            }
            case SDL_MOUSEBUTTONDOWN:
            {
                int x, y;
                SDL_GetMouseState(&x, &y);
                cpVect pos = cpv(x, y);
                Circle* newTempCircle = new Circle();
                newTempCircle->initCircle(window.renderer);
                cpShape newCircle = newTempCircle->createCircle(15.0f, &space, pos);
                circles->insert(circles->end(), *newTempCircle);
                break;
            }
            default:
            {
                break;
            }
                
        }
    }
}

bool Input::isRunning()
{
    return running;
}