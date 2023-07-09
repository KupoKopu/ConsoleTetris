//
// Created by LMLK-404 on 08/07/2023.
//

#ifndef CONSOLETETRIS_TERMINAL_H
#define CONSOLETETRIS_TERMINAL_H
#include <windows.h>

class Terminal {
public:
    Terminal(short width, short height);

    void initialiseTerminal();

    DWORD getDwMode() const;

    void setDwMode(DWORD dwMode);

    short getBufferWidth() const;

    void setBufferWidth(short bufferWidth);

    short getBufferHeight() const;

    void setBufferHeight(short bufferHeight);
private:
    HANDLE hStdOut{};
    DWORD dwMode{};
    short bufferWidth{};
    short bufferHeight{};
    SMALL_RECT *bufferScreen{};
};
#endif //CONSOLETETRIS_TERMINAL_H
