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
    // constructor
    Tetris(int width, int height, int fieldWidth, int fieldHeight, ExitCode &outExitCode);

    // game loop logic
    void tick() override;
    void userInput() override;
    void draw() override;
    void emitExitCode(ExitCode code) override;
    void start() override;

    // methods
    void handleForceDown();
    void handleSpeedCounter();
    void resetField();

    // getters
    wchar_t *getScreen() const;
private:
    // console rendering
    Terminal *terminal;

    // code that controls state in main
    ExitCode &outExitCode;

    // tetris playing field
    int fieldWidth;
    int fieldHeight;
    int fieldArea;
    wchar_t *field; // tetris grid

    // current tetromino data
    int currentPiece; // first piece
    int currentRotation; // no rotations
    int currentX; // middle of field
    int currentY; // top of field

    // userInput variables
    bool keyPressed[4];
    bool rotateHold;

    // game logic
    std::vector<int> verticalLines; // y position of filled space
    int speed;
    int speedCounter;
    bool forceDown;
};
#endif //CONSOLETETRIS_TETRIS_H
