#ifndef CONSOLETETRIS_TERMINAL_H
#define CONSOLETETRIS_TERMINAL_H
#include <windows.h>

// Singleton class controlling display to console
class Terminal {
private:
    Terminal(short width, short height);

public:
    Terminal(Terminal &other) = delete;
    void operator=(const Terminal &) = delete;
    ~Terminal();

    static Terminal *getInstance(const short &width, const short &height);

    void initialiseTerminal();

    void render(wchar_t *screenToRender);
private:
    static Terminal *instance;

    HANDLE handleOut{};
    short bufferWidth{};
    short bufferHeight{};
    SMALL_RECT *bufferScreen{};
    DWORD dwBytesWritten{};
};
#endif //CONSOLETETRIS_TERMINAL_H
