#include <iostream>
#include <thread>
#include <chrono>
#include "src/Terminal.h"
short screenWidth = 80;
short screenHeight = 30;
using namespace std::chrono_literals;

int fieldWidth = screenWidth;
int fieldHeight = screenHeight;
unsigned char *playField = nullptr;

int main() {
    Terminal *terminal = Terminal::getInstance(screenWidth, screenHeight);

    playField = new unsigned char[fieldWidth * fieldHeight]; // Create play field buffer
    for (int x = 0; x < fieldWidth; x++) // Board Boundary
        for (int y = 0; y < fieldHeight; y++)
            playField[y * fieldWidth + x] = (x == 0 || x == fieldWidth - 1 || y == fieldHeight - 1) ? 9 : 0;

    wchar_t *screen = new wchar_t[screenWidth*screenHeight];
    for (int i = 0; i < screenWidth*screenHeight; i++) screen[i] = L'#';

    terminal->render(screen);

    bool gameOver = false;
    while(!gameOver) {
        std::this_thread::sleep_for(5000ms); // Small Step = 1 Game Tick

        gameOver = true;
    }
}
