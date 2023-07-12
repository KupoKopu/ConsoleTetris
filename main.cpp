#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include "src/Terminal.h"
#include "src/constants.h"
#include "src/Tetris.h"

using namespace std::chrono_literals;

int main() {
    ExitCode exitCode = OK;

    Terminal *terminal = Terminal::getInstance(SCREEN_WIDTH, SCREEN_HEIGHT);
    HANDLE stdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    Tetris *tetris = new Tetris(SCREEN_WIDTH, SCREEN_HEIGHT, FIELD_WIDTH, FIELD_HEIGHT, exitCode);
    Frame* activeFrame = tetris;


    activeFrame->start();

    if (exitCode == RETURN) {
        SetConsoleActiveScreenBuffer(stdOut);
    }

    while (exitCode == RETURN) {
        std::cout << exitCode;
        std::this_thread::sleep_for(5000ms);
        exitCode = EXIT;
    }
}
