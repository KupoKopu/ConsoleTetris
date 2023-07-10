//
// Created by LMLK-404 on 08/07/2023.
//

#ifndef CONSOLETETRIS_TERMINAL_H
#define CONSOLETETRIS_TERMINAL_H
#include <windows.h>

class Terminal {
private:
    Terminal(short width, short height);

public:
    Terminal(Terminal &other) = delete;
    void operator=(const Terminal &) = delete;
    ~Terminal();

    static Terminal *getInstance(const short &width, const short &height);

    void initialiseTerminal();

    DWORD getDwMode() const;

    void setDwMode(DWORD dwMode);

    short getBufferWidth() const;

    void setBufferWidth(short bufferWidth);

    short getBufferHeight() const;

    void setBufferHeight(short bufferHeight);

    void render(wchar_t *screenToRender);
private:
    static Terminal *instance;

    HANDLE hStdOut{};
    DWORD dwMode{};
    short bufferWidth{};
    short bufferHeight{};
    SMALL_RECT *bufferScreen{};
    DWORD dwBytesWritten{};
};
#endif //CONSOLETETRIS_TERMINAL_H
