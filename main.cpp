#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include "src/Terminal.h"
#include "src/PlayArea.h"
#include "src/CoordHelper.h"
#include "src/constants.h"

using namespace std::chrono_literals;
unsigned char *playField = nullptr;

int main() {
    Terminal *terminal = Terminal::getInstance(screenWidth, screenHeight);
    PlayArea *playArea = new PlayArea(fieldWidth, fieldHeight);

    wchar_t *screen = new wchar_t[screenWidth * screenHeight];
    for (int i = 0; i < screenWidth * screenHeight; i++) screen[i] = L' ';


    int currentPiece = 0; // first piece
    int currentRotation = 0; // no rotations
    int currentX = fieldWidth / 2; // middle of field
    int currentY = 0; // top of field
    bool keyPressed[4];
    bool rotateHold = false;

    std::vector<int> verticalLines;
    int speed = 20;
    int speedCounter = 0;
    bool forceDown = false;

    bool gameOver = false;
    while(!gameOver) {
        // game tick
        std::this_thread::sleep_for(50ms); // Small Step = 1 Game Tick
        speedCounter++;
        forceDown = (speedCounter == speed);

        // input
        for (int k = 0; k < 4; ++k) {
            keyPressed[k] = (GetAsyncKeyState((unsigned char)("\x27\x25\x28Z"[k]))) != 0;
        }
        // game logic(?)
        // left
        if (keyPressed[1])
        {
            if (doesPieceFit(currentPiece, currentRotation, currentX - 1, currentY, playArea->getArea()))
            {
                currentX = currentX - 1;
            }
        }

        // right
        if (keyPressed[0])
        {
            if (doesPieceFit(currentPiece, currentRotation, currentX + 1, currentY, playArea->getArea()))
            {
                currentX = currentX + 1;
            }
        }

        // down
        if (keyPressed[2])
        {
            if (doesPieceFit(currentPiece, currentRotation, currentX, currentY + 1, playArea->getArea()))
            {
                currentY = currentY + 1;
            }
        }

        // z(rotate clockwise) key
        if (keyPressed[3])
        {
            if (!rotateHold && doesPieceFit(currentPiece, currentRotation + 1, currentX, currentY, playArea->getArea()))
            {
                currentRotation = currentRotation + 1;
            }
            rotateHold = true;
        } else {
            rotateHold = false;
        }

        if (forceDown) {
            // reset counter
            speedCounter = 0;
            if (doesPieceFit(currentPiece, currentRotation, currentX, currentY + 1, playArea->getArea())) {
                currentY = currentY + 1;
            } else {
                // lock piece to playArea
                for (int x = 0; x < 4; x++) {
                    for (int y = 0; y < 4; ++y) {
                        if (tetromino[currentPiece][rotate(x, y, currentRotation)] == L'X') {
                            playArea->getArea()[(currentY + y) * playArea->getWidth() + (currentX + x)] = currentPiece + 1;
                        }
                    }
                }
                // horizontal match
                for (int y = 0; y < 4; ++y) {
                    if (currentY + y < fieldHeight - 1) { // boundary check
                        bool bottomLine = true;
                        for (int x = 1; x < fieldWidth; ++x) {
                            // check if line has empty space
                            bottomLine &= (playArea->getArea()[(currentY + y) * fieldWidth + x]) != 0;
                        }

                        if (bottomLine) {
                            for (int x = 1; x < fieldWidth - 1 ; ++x) {
                                // create line
                                playArea->getArea()[(currentY + y) * fieldWidth + x] = 8;
                            }
                            verticalLines.push_back(currentY + y);
                        }
                    }
                }

                // choose next piece
                currentX = fieldWidth / 2; // starting position maybe extract
                currentY = 0;
                currentRotation = 0;
                currentPiece = rand() % 7;
                // if piece does not fit

            }
        }

        // draw
        renderOnTo(screen, screenWidth, playArea->getArea(), {playArea->getWidth(), playArea->getHeight()}, playAreaOffset);
        renderPiece(screen, screenWidth, currentPiece, currentRotation, {currentX, currentY}, playAreaOffset);

        if (!verticalLines.empty()) {
            terminal->render(screen);
            std::this_thread::sleep_for(400ms);

            for (auto &v : verticalLines)
                for (int x = 1; x < fieldWidth - 1; x++)
                {
                    for (int py = v; py > 0; py--)
                        playArea->getArea()[py * fieldWidth + x] = playArea->getArea()[(py - 1) * fieldWidth + x];
                    playArea->getArea()[x] = 0;
                }

            verticalLines.clear();
        }

        // render
        terminal->render(screen);
    }
}
