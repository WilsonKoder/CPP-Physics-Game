// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
// ~ By Wilson - 'circle.h'
//
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#pragma once

#include <chipmunk/chipmunk.h>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

class Circle {
public:
    Circle();
    cpShape createCircle(float radius, cpSpace *space, cpVect pos);
    static SDL_Texture* initCircle(SDL_Renderer* renderer);
    static void drawCircle(cpVect pos, cpVect rot, SDL_Texture* ballTexture, SDL_Renderer* renderer);
    cpVect getCirclePos();
    cpShape* ballShape;
};
