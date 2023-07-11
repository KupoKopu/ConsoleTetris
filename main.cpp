#include <iostream>
#include <thread>
#include <chrono>
#include "src/Terminal.h"
#include "src/PlayArea.h"

short screenWidth = 80;
short screenHeight = 30;
using namespace std::chrono_literals;

int fieldWidth = 12;
int fieldHeight = 18;
unsigned char *playField = nullptr;

int renderOnTo(wchar_t * source, int sourceWidth, int sourceHeight, wchar_t * copy, int copyWidth, int copyHeight) {
    for (int x = 0; x < copyWidth; x++)
    {
        for (int y = 0; y < copyHeight; y++)
        {
            source[(y + 2)*sourceWidth + (x + 77)] = L" ABCDEFG=#"[copy[y*copyWidth + x]];
        }
    }
    return 0;
}

int main() {
    Terminal *terminal = Terminal::getInstance(screenWidth, screenHeight);
    PlayArea *playArea = new PlayArea(12, 18);


    wchar_t *screen = new wchar_t[screenWidth * screenHeight];
    for (int i = 0; i < screenWidth * screenHeight; i++) screen[i] = L' ';

    for (int x = 0; x < fieldWidth; x++)
    {
        for (int y = 0; y < fieldHeight; y++)
        {
            screen[(y + 2)*screenWidth + (x + 77)] = L" ABCDEFG=#"[playArea->getArea()[y*fieldWidth + x]];
        }
    }

    terminal->render(screen);

    bool gameOver = false;
    while(!gameOver) {
        std::this_thread::sleep_for(5000ms); // Small Step = 1 Game Tick

        gameOver = true;
    }
}
