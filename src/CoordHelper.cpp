#include "CoordHelper.h"
int renderOnTo(wchar_t * source, int sourceWidth, int sourceHeight, const wchar_t * copy, int copyWidth, int copyHeight, std::pair<int,int> offset) {
    for (int x = 0; x < copyWidth; x++) {
        for (int y = 0; y < copyHeight; y++) {
            source[(y + offset.second)*sourceWidth + (x + offset.first)] = L" ABCDEFG=#"[copy[y*copyWidth + x]];
        }
    }
    return 0;
}

int rotate(int pixelX, int pixelY, int rotation) {
    switch (rotation % 4) {
        case 0: {
            return pixelY * 4 + pixelX;
        }
        case 1: {
            return 12 + pixelY - (pixelX * 4);
        }
        case 2: {
            return 15 - (pixelY * 4) - pixelX;
        }
        case 3: {
            return 3 - pixelY + (pixelX * 4);
        }
        return 0;
    }
}
