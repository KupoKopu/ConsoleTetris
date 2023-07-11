#ifndef CONSOLETETRIS_COORDHELPER_H
#define CONSOLETETRIS_COORDHELPER_H
#include <utility>
int renderOnTo(wchar_t * source, int sourceWidth, int sourceHeight, const wchar_t * copy, int copyWidth, int copyHeight, std::pair<int, int> offset);
int rotate(int pixelX, int pixelY, int rotation);
#endif //CONSOLETETRIS_COORDHELPER_H
