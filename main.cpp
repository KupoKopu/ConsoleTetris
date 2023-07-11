#include <iostream>
#include <thread>
#include <chrono>
#include "src/Terminal.h"
#include "src/PlayArea.h"
#include "src/CoordHelper.h"

short screenWidth = 80;
short screenHeight = 30;
using namespace std::chrono_literals;

int fieldWidth = 12;
int fieldHeight = 18;
unsigned char *playField = nullptr;

int main() {
    Terminal *terminal = Terminal::getInstance(screenWidth, screenHeight);
    PlayArea *playArea = new PlayArea(12, 18);

    wchar_t *screen = new wchar_t[screenWidth * screenHeight];
    for (int i = 0; i < screenWidth * screenHeight; i++) screen[i] = L' ';

    renderOnTo(screen, screenWidth, screenHeight, playArea->getArea(), playArea->getWidth(), playArea->getHeight(), {2,2});

    terminal->render(screen);

    bool gameOver = false;
    while(!gameOver) {
        std::this_thread::sleep_for(5000ms); // Small Step = 1 Game Tick

        gameOver = true;
    }
}
