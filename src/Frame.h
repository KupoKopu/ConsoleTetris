#ifndef CONSOLETETRIS_FRAME_H
#define CONSOLETETRIS_FRAME_H

#include "constants.h"

class Frame {
private:
    virtual void tick() = 0;
    virtual void userInput() = 0;
    virtual void draw() = 0;
    virtual ExitCode emitExitCode(ExitCode code) = 0;

public:
    virtual void start() = 0;

protected:
    wchar_t *screen;
    int screenWidth;
    int screenHeight;
};
#endif //CONSOLETETRIS_FRAME_H
