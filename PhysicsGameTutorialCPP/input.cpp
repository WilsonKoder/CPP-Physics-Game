// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
// ~ By Wilson - 'input.cpp'
//
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include "input.h"

#include <SDL2/SDL.h>
#include <iostream>

void Input::handleEvents(Screen window, std::vector<Circle> *circles, cpSpace space, int radius)
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
                else if (e.key.keysym.sym == SDLK_r)
                {
                    if (mouseHold)
                    {
                        mouseHold = false;
                    }
                    else
                    {
                        mouseHold = true;
                    }
                }
                break;
                
            case SDL_MOUSEBUTTONDOWN:
            {
                if (!mouseHold)
                {
                    int x, y;
                    SDL_GetMouseState(&x, &y);
                    x -= 15;
                    y -= 15;
                    cpVect pos = cpv(x, y);
                    Circle* newTempCircle = new Circle();
                    newTempCircle->initCircle(window.renderer);
                    newTempCircle->createCircle(radius, &space, pos);
                    circles->insert(circles->end(), *newTempCircle);
                }
                else
                {
                    mouseDown = true;
                }
                break;
            }
            case SDL_MOUSEBUTTONUP:
                mouseDown = false;
            default:
                break;
            
                
        }
    }
    
    if(mouseDown)
    {
        int x, y;
        SDL_GetMouseState(&x, &y);
        cpVect pos = cpv(x, y);
        Circle* newTempCircle = new Circle();
        newTempCircle->initCircle(window.renderer);
        newTempCircle->createCircle(radius, &space, pos);
        circles->insert(circles->end(), *newTempCircle);
    }
}

bool Input::isRunning()
{
    return running;
}