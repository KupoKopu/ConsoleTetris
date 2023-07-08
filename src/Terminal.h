//
// Created by LMLK-404 on 08/07/2023.
//

#ifndef CONSOLETETRIS_TERMINAL_H
#define CONSOLETETRIS_TERMINAL_H
#include <windows.h>

class Terminal {
public:
    Terminal();

    void initialiseTerminal();


private:
    HANDLE hStdOut{};
    DWORD dwMode{};
public:
    DWORD getDwMode() const;

    void setDwMode(DWORD dwMode);

};
#endif //CONSOLETETRIS_TERMINAL_H
