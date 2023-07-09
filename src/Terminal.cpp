#include "Terminal.h"

Terminal::Terminal(short width, short height): bufferWidth(width), bufferHeight(height) {
    hStdOut = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, nullptr, CONSOLE_TEXTMODE_BUFFER, nullptr);
    bufferScreen = new SMALL_RECT {0,0,1,1};
    dwBytesWritten = 0;

    initialiseTerminal();
}

DWORD Terminal::getDwMode() const {
    return dwMode;
}

void Terminal::setDwMode(DWORD dwMode) {
    Terminal::dwMode |= dwMode;
}

void Terminal::initialiseTerminal() {
    SetConsoleWindowInfo(hStdOut, true, bufferScreen);

    COORD buffer_size = {bufferWidth, bufferHeight};
    SetConsoleScreenBufferSize(hStdOut, buffer_size);

    bufferScreen->Right = bufferWidth-1;
    bufferScreen->Bottom = bufferHeight-1;
    SetConsoleWindowInfo(hStdOut, true, bufferScreen);

    SetConsoleActiveScreenBuffer(hStdOut);
}

short Terminal::getBufferWidth() const {
    return bufferWidth;
}

short Terminal::getBufferHeight() const {
    return bufferHeight;
}

void Terminal::render(wchar_t *screenToRender) {
    WriteConsoleOutputCharacterW(hStdOut, screenToRender, bufferWidth * bufferHeight, {0,0}, &dwBytesWritten);
}
