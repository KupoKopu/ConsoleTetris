#ifndef CONSOLETETRIS_FRAME_H
#define CONSOLETETRIS_FRAME_H

#include "constants.h"

// Abstract class to derive from to create frames to render on terminal
class Frame {
private:
    // virtuals function to implement
    virtual void tick() = 0;
    virtual void userInput() = 0;
    virtual void draw() = 0;
    virtual void emitExitCode(ExitCode code) = 0;

public:
    virtual void start() = 0;

protected:
    // screen variables
    wchar_t *screen;
    int screenWidth;
    int screenHeight;
    int screenArea;
};
#endif //CONSOLETETRIS_FRAME_H
