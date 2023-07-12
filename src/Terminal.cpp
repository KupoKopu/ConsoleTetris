#include "Terminal.h"

// initialize at run time;
Terminal *Terminal::instance = nullptr;

// constructor
Terminal::Terminal(short width, short height): bufferWidth(width), bufferHeight(height) {
    handleOut = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, nullptr, CONSOLE_TEXTMODE_BUFFER, nullptr);
    bufferScreen = new SMALL_RECT {0,0,1,1};
    dwBytesWritten = 0;

    initialiseTerminal();
}

Terminal::~Terminal() {
    delete bufferScreen;
    delete instance;
}

// resizes terminal to fit dimensions for the game
void Terminal::initialiseTerminal() {
    // minimize to tiniest window
    SetConsoleWindowInfo(handleOut, true, bufferScreen);

    // adjust to desired size
    COORD buffer_size = {bufferWidth, bufferHeight};
    SetConsoleScreenBufferSize(handleOut, buffer_size);

    bufferScreen->Right = bufferWidth-1;
    bufferScreen->Bottom = bufferHeight-1;
    SetConsoleWindowInfo(handleOut, true, bufferScreen);

    // set to created new window from handleOut
    SetConsoleActiveScreenBuffer(handleOut);
}

// renders wchar_t* screen from Frame class to window
void Terminal::render(wchar_t *screenToRender) {
    WriteConsoleOutputCharacterW(handleOut, screenToRender, bufferWidth * bufferHeight, {0, 0}, &dwBytesWritten);
}

// create or give instance to class object
Terminal *Terminal::getInstance(const short &width, const short &height) {
    if (nullptr == instance) {
        instance = new Terminal(width, height);
    }
    return instance;
}
