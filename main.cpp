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

    renderOnTo(screen, screenWidth, playArea->getArea(), {playArea->getWidth(), playArea->getHeight()}, playAreaOffset);

    int currentPiece = 0; // first piece
    int currentRotation = 0; // no rotations
    int currentX = fieldWidth / 2; // middle of field
    int currentY = 0; // top of field

    renderPiece(screen, screenWidth, currentPiece, currentRotation, {currentX, currentY}, playAreaOffset);

    terminal->render(screen);

    bool gameOver = false;
    while(!gameOver) {
        std::this_thread::sleep_for(5000ms); // Small Step = 1 Game Tick

        gameOver = true;
    }
}
