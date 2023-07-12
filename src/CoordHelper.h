#ifndef CONSOLETETRIS_COORDHELPER_H
#define CONSOLETETRIS_COORDHELPER_H
#include <utility>
#include "constants.h"
int renderOnTo(wchar_t * source, int sourceWidth, const wchar_t * copy, std::pair<int,int> copySize, std::pair<int,int> offset);
int renderPiece(wchar_t * source, int sourceWidth, int tetrominoIndex, int rotation, std::pair<int,int> currentPos, std::pair<int,int> offset);
int rotate(int pixelX, int pixelY, int rotation);
bool doesPieceFit(int tetrominoIndex, int rotation, int positionX, int positionY, wchar_t *playArea);
int renderText(wchar_t * source, int sourceWidth, const wchar_t * copy, std::pair<int,int> copySize, std::pair<int,int> offset);
#endif //CONSOLETETRIS_COORDHELPER_H
