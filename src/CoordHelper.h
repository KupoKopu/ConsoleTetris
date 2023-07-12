#ifndef CONSOLETETRIS_COORDHELPER_H
#define CONSOLETETRIS_COORDHELPER_H
#include <utility>
#include "Constants.h"
void renderOnTo(wchar_t * source, int sourceWidth, const wchar_t * copy, std::pair<int,int> copySize, std::pair<int,int> offset);
void renderPiece(wchar_t * source, int sourceWidth, int tetrominoIndex, int rotation, std::pair<int,int> currentPos, std::pair<int,int> offset);
void renderText(wchar_t * source, int sourceWidth, const wchar_t * copy, int copyWidth, std::pair<int,int> offset);
bool doesPieceFit(int tetrominoIndex, int rotation, int positionX, int positionY, wchar_t *playArea);
int rotate(int pixelX, int pixelY, int rotation);
#endif //CONSOLETETRIS_COORDHELPER_H
