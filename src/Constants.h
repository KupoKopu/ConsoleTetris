#ifndef CONSOLETETRIS_CONSTANTS_H
#define CONSOLETETRIS_CONSTANTS_H
#include <utility>
#include <string>

constexpr short SCREEN_WIDTH = 80;
constexpr short SCREEN_HEIGHT = 30;
constexpr int FIELD_WIDTH = 12;
constexpr int FIELD_HEIGHT = 18;
constexpr std::pair<int,int> FIELD_OFFSET = {2, 2};

/* wchar_t *field that holds tetris board data represents differentiate elements with numbers
 * used by locked tetrominos- currently falling tetrominos use tetrominoIndex + 65 to get A-G characters
 * 0 = ' ' - free space
 * 1 = A - first TETROMINO piece
 * 2 = B - second TETROMINO piece
 * 3 = C - third TETROMINO piece
 * 4 = D - fourth TETROMINO piece
 * 5 = E - fifth TETROMINO piece
 * 6 = F - sixth TETROMINO piece
 * 7 = G - seventh TETROMINO piece
 * 8 = '=' - vertical line when animating line clear
 * 9 = # - field border
 */
constexpr wchar_t CHAR_ART[11] = L" ABCDEFG=#";
const std::wstring TETROMINO[7] = {L"..X...X...X...X.",
                                   L"..X..XX...X.....",
                                   L".....XX..XX.....",
                                   L"..X..XX..X......",
                                   L".X...XX...X.....",
                                   L".X...X...XX.....",
                                   L"..X...X..XX....."};

/* OK to run and continue loop in Frame derived classes
 * RETURN to exit tetris game and back to menu
 * START to exit menu and start tetris game
 * EXIT to leave application
 */
enum ExitCode {
    OK,
    RETURN,
    START,
    EXIT
};
#endif //CONSOLETETRIS_CONSTANTS_H
