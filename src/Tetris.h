#ifndef CONSOLETETRIS_TETRIS_H
#define CONSOLETETRIS_TETRIS_H
#include <thread>
#include <vector>
#include "Frame.h"
#include "iostream"
#include "windows.h"
#include "CoordHelper.h"
#include "Terminal.h"

using namespace std::chrono_literals;

class Tetris : public Frame  {
public:
    virtual void tick();
    virtual void userInput();
    virtual void draw();
    virtual void emitExitCode(ExitCode code);

    Tetris(int width, int height, int fieldWidth, int fieldHeight, ExitCode &outExitCode);

    void handleForceDown();
    void handleSpeedCounter();
    void start();

    wchar_t *getScreen() const;
private:
    int screenArea;

    int fieldWidth = 12;
    int fieldHeight = 18;
    int fieldArea;
    wchar_t *field;

    int currentPiece; // first piece
    int currentRotation; // no rotations
    int currentX; // middle of field
    int currentY; // top of field
    bool keyPressed[4];
    bool rotateHold;

    std::vector<int> verticalLines;
    int speed = 20;
    int speedCounter = 0;
    bool forceDown = false;

    bool gameOver = false;

    ExitCode &outExitCode;

    Terminal *terminal;
};
#endif //CONSOLETETRIS_TETRIS_H
