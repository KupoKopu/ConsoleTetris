//
// Created by LMLK-404 on 08/07/2023.
//





#include "Terminal.h"

Terminal::Terminal() {
    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

    GetConsoleMode(hStdOut, &dwMode);

    initialiseTerminal();
}

DWORD Terminal::getDwMode() const {
    return dwMode;
}

void Terminal::setDwMode(DWORD dwMode) {
    Terminal::dwMode |= dwMode;
}

void Terminal::initialiseTerminal() {
    setDwMode(ENABLE_VIRTUAL_TERMINAL_PROCESSING);

    SetConsoleMode(hStdOut, dwMode);
}
