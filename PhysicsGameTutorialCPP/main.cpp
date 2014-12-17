// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
// ~ By Wilson - 'main.cpp'
//
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// STL

#include <iostream>
#include <vector>

// CUSTOM FILES

#include "circle.h"
#include "physics.h"
#include "screen.h"
#include "input.h"

// No global variables! Good C++.


int main(int argc, const char * argv[]) {
    
    Screen window(800, 600);
    Physics physics;
    Input input;
    
    cpSpace space = physics.createPhysicsSpace();
    std::vector<Circle> circles;

    SDL_Surface *screen = SDL_GetWindowSurface(window.window);
    
    SDL_SetRenderDrawColor(window.renderer, 255, 255, 255, 255);
    SDL_Texture* ballTexture = Circle::initCircle(window.renderer);
    
    SDL_Surface* floorSurface = IMG_Load("/Users/WilsonKoder/Desktop/Game Development/C++/PhysicsGameTutorialCPP/PhysicsGameTutorialCPP/floor.png");
    SDL_Texture* floorTexture = SDL_CreateTextureFromSurface(window.renderer, floorSurface);
    SDL_FreeSurface(floorSurface);
    
    SDL_Rect floorSrcRect;
    SDL_Rect floorDestRect;
    
    floorSrcRect.x = floorSrcRect.y = 0;
    floorSrcRect.w = floorDestRect.w = 800;
    floorSrcRect.h = floorDestRect.h = 64;
    floorDestRect.y = 515;
    floorDestRect.x = 0;
    
    while (input.isRunning())
    {
        SDL_RenderClear(window.renderer);

        input.handleEvents(window, &circles, space);
        
        for(auto &circle : circles)
        {
            cpShape* shape = circle.ballShape;
            Circle::drawCircle(circle.getCirclePos(), shape->body->rot, ballTexture, window.renderer);
        }
        
        SDL_RenderCopy(window.renderer, floorTexture, &floorSrcRect, &floorDestRect);
        
        cpSpaceStep(&space, (1.0/60.0));
        
        SDL_RenderPresent(window.renderer);

    }
    
    return 0;
}

