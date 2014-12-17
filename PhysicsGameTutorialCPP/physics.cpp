// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
// ~ By Wilson - 'physics.cpp'
//
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


#include "physics.h"

cpSpace Physics::createPhysicsSpace()
{
    cpSpace *space = cpSpaceNew();
    cpVect grav = cpv(0, 900);
    cpSpaceSetGravity(space, grav);
    
    cpShape *ground = cpSegmentShapeNew(space->staticBody, cpv(0, 500), cpv(800, 500), 0);
    cpShapeSetFriction(ground, 1);
    cpShapeSetElasticity(ground, 0.4);
    cpSpaceAddShape(space, ground);
    
    return *space;
}
