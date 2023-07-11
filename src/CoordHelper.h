#ifndef CONSOLETETRIS_COORDHELPER_H
#define CONSOLETETRIS_COORDHELPER_H
#include <utility>
#include "constants.h"
#include "tetromino.h"
int renderOnTo(wchar_t * source, int sourceWidth, const wchar_t * copy, std::pair<int,int> copySize, std::pair<int,int> offset);
int renderPiece(wchar_t * source, int sourceWidth, int tetrominoIndex, int rotation, std::pair<int,int> currentPos, std::pair<int,int> offset);
int rotate(int pixelX, int pixelY, int rotation);
#endif //CONSOLETETRIS_COORDHELPER_H
