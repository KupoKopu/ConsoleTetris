#include "CoordHelper.h"
int renderOnTo(wchar_t * source, int sourceWidth, int sourceHeight, const wchar_t * copy, int copyWidth, int copyHeight, std::pair<int,int> offset) {
    for (int x = 0; x < copyWidth; x++) {
        for (int y = 0; y < copyHeight; y++) {
            source[(y + offset.second)*sourceWidth + (x + offset.first)] = L" ABCDEFG=#"[copy[y*copyWidth + x]];
        }
    }
    return 0;
}