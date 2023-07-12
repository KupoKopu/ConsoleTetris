#include <iostream>
#include <thread>
#include <chrono>
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
        // game logic(?)
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

                // choose next piece
                currentX = fieldWidth / 2; // starting position maybe extract
                currentY = 0;
                currentRotation = 0;
                currentPiece = rand() % 7;
                // if piece does not fit

            }
        }

        // render
        renderOnTo(screen, screenWidth, playArea->getArea(), {playArea->getWidth(), playArea->getHeight()}, playAreaOffset);
        renderPiece(screen, screenWidth, currentPiece, currentRotation, {currentX, currentY}, playAreaOffset);
        terminal->render(screen);
    }
}
