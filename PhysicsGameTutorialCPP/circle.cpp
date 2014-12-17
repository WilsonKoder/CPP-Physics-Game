// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
// ~ By Wilson - 'circle.cpp'
//
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include "circle.h"
#include <SDL2_image/SDL_image.h>

Circle::Circle()
{
    
}

cpShape Circle::createCircle(float radius, cpSpace *space, cpVect pos)
{
    cpFloat mass = 1;
    
    cpFloat moment = cpMomentForCircle(mass, 0, radius, cpvzero);
    
    cpBody* ballBody = cpSpaceAddBody(space, cpBodyNew(mass, moment));
    cpBodySetPos(ballBody, pos);
    
    ballShape = cpSpaceAddShape(space, cpCircleShapeNew(ballBody, radius, cpvzero));
    cpShapeSetFriction(ballShape, 0.8);
    cpShapeSetElasticity(ballShape, 0.8);

    return *ballShape;
}

SDL_Texture* Circle::initCircle(SDL_Renderer *renderer)
{
    SDL_Surface* rawImage = IMG_Load("/Users/WilsonKoder/Desktop/Game Development/C++/PhysicsGameTutorialCPP/PhysicsGameTutorialCPP/ball.png");
    SDL_Texture* imageTexture = SDL_CreateTextureFromSurface(renderer, rawImage);
    //SDL_FreeSurface(rawImage);
    return imageTexture;
    
}

void Circle::drawCircle(cpVect pos, cpVect rot, SDL_Texture* ballTexture, SDL_Renderer* renderer)
{
    SDL_Rect srcRect;
    SDL_Rect destRect;
    
    srcRect.x = srcRect.y = 0;
    srcRect.w = destRect.w = 30;
    srcRect.h = destRect.h = 30;
    
    destRect.x = pos.x;
    destRect.y = pos.y;
    
    
    SDL_RenderCopyEx(renderer, ballTexture, &srcRect, &destRect, int(rot.x), 0, SDL_FLIP_NONE);
    //SDL_RenderCopy(renderer, ballTexture, &srcRect, &destRect);
}

cpVect Circle::getCirclePos()
{
    cpVect pos = cpBodyGetPos(ballShape->body);
    return pos;
}