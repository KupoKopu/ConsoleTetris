#include <iostream>
#include <thread>
#include <chrono>
#include "src/Terminal.h"
short screenWidth = 80;
short screenHeight = 30;
using namespace std::chrono_literals;

int main() {
    Terminal *terminal = new Terminal(screenWidth, screenHeight);

    bool gameOver = false;
    while(!gameOver) {
        std::this_thread::sleep_for(5000ms); // Small Step = 1 Game Tick

        gameOver = true;
    }
}
