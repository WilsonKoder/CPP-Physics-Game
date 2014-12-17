//
//  main.cpp
//  PhysicsGameTutorialCPP
//
//  Created by Wilson Koder on 17/12/14.
//  Copyright (c) 2014 WilsonKoder. All rights reserved.
//

#include <iostream>
#include <vector>

#include <chipmunk/chipmunk.h>

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

#include "circle.h"
#include "physics.h"
#include "screen.h"

std::vector<Circle> circles;

int main(int argc, const char * argv[]) {
    
    
    // insert code here...
    Screen window(800, 600);
    Physics physics;
    cpSpace space = physics.createPhysicsSpace();
    
    SDL_Surface *screen = SDL_GetWindowSurface(window.window);
    
    bool gameIsRunning = true;
    
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
    
    while (gameIsRunning)
    {
        SDL_RenderClear(window.renderer);

        SDL_Event e;
        while(SDL_PollEvent(&e))
        {
            switch (e.type) {
                case SDL_QUIT:
                {
                    gameIsRunning = false;
                    break;
                }
                case SDL_KEYDOWN:
                {
                    switch (e.key.keysym.sym) {
                        case SDLK_c:
                            std::cout << "clear!" << std::endl;
                            //for(auto &circle : circles)
                            //{
                            //    cpBodyFree(circle.ballShape->body);
                            //    cpShapeFree(circle.ballShape);
                            //}
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
                    circles.insert(circles.end(), *newTempCircle);
                    break;
                }
                default:
                {
                    break;
                }
                
            }
        }
        
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


