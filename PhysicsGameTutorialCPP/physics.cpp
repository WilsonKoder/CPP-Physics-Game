//
//  physics.cpp
//  PhysicsGameTutorialCPP
//
//  Created by Wilson Koder on 17/12/14.
//  Copyright (c) 2014 WilsonKoder. All rights reserved.
//

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