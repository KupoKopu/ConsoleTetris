//
// Created by LMLK-404 on 12/07/2023.
//

#include "Menu.h"

Menu::Menu(int width, int height, ExitCode &outExitCode) : outExitCode(outExitCode) {
    screenWidth = width;
    screenHeight = height;
    screenArea = screenWidth* screenHeight;
    screen = new wchar_t [screenArea];
    for (int i = 0; i < screenWidth * screenHeight; i++) screen[i] = L' ';

    currentSelection = 0;
    menuOptions[0] = {L"Play", {4,4}};
    menuOptions[1] = {L"Exit", {4,6}};

    terminal = Terminal::getInstance(80, 30);
}

void Menu::tick() {
    std::this_thread::sleep_for(50ms);
}

void Menu::draw() {
    int count = 0;
    for (auto string : menuOptions) {
        const wchar_t *text = menuOptions[count].first.c_str();
        int size = menuOptions[count].first.size();
        std::pair<int, int> offset = menuOptions[count].second;
        renderText(screen, screenWidth, text, {size, 1}, offset);
        count++;

    }
}

void Menu::start() {
    while(outExitCode == OK) {
        tick();

        userInput();

        draw();

        terminal->render(getScreen());
    }
}

wchar_t *Menu::getScreen() const {
    return screen;
}

void Menu::userInput() {
// input
    for (int k = 0; k < 2; ++k) {
        keyPressed[k] = (GetAsyncKeyState((unsigned char)("QP"[k]))) != 0;
    }
    // game logic(?)
    // Q key
//    if (keyPressed[0])
//    {
//        emitExitCode(EXIT);
//    }

    // P
    if (keyPressed[1])
    {
        emitExitCode(START);
    }
}

void Menu::emitExitCode(ExitCode code) {
    outExitCode = code;
}
