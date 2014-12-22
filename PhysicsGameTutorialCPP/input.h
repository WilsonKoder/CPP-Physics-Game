// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
// ~ By Wilson - 'input.h'
//
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


#pragma once

#include <vector>
#include "screen.h"
#include "circle.h"

class Input {
public:
    void handleEvents(Screen window, std::vector<Circle> *circles, cpSpace space, int radius);
    bool isRunning();
private:
    bool running = true;
    bool mouseHold = false;
    bool mouseDown = false;
};