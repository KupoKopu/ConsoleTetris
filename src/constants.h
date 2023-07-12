#ifndef CONSOLETETRIS_CONSTANTS_H
#define CONSOLETETRIS_CONSTANTS_H
#include <utility>
#include <string>

constexpr short SCREEN_WIDTH = 80;
constexpr short SCREEN_HEIGHT = 30;
constexpr int FIELD_WIDTH = 12;
constexpr int FIELD_HEIGHT = 18;
constexpr std::pair<int,int> FIELD_OFFSET = {2, 2};

const std::wstring TETROMINO[7] = {L"..X...X...X...X.",
                                   L"..X..XX...X.....",
                                   L".....XX..XX.....",
                                   L"..X..XX..X......",
                                   L".X...XX...X.....",
                                   L".X...X...XX.....",
                                   L"..X...X..XX....."};

enum ExitCode {
    OK,
    RETURN,
    START,
    EXIT
};
#endif //CONSOLETETRIS_CONSTANTS_H
