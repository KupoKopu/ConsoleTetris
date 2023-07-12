#include "CoordHelper.h"
// help render other frames onto wchar_t *screen defined in Frame class
void renderOnTo(wchar_t * source, int sourceWidth, const wchar_t * copy, std::pair<int,int> copySize, std::pair<int,int> offset) {
    // unpack std::pairs
    int copyWidth = copySize.first;
    int copyHeight = copySize.second;
    int offsetX = offset.first;
    int offsetY = offset.second;

    for (int x = 0; x < copyWidth; x++) {
        for (int y = 0; y < copyHeight; y++) {
            source[(y + offsetY)*sourceWidth + (x + offsetX)] = CHAR_ART[copy[y*copyWidth + x]];
        }
    }
}

// help render TETROMINO piece onto wchar_t *field in Tetris class
void renderPiece(wchar_t * source, int sourceWidth, int tetrominoIndex, int rotation, std::pair<int,int> currentPos, std::pair<int,int> offset) {
    const short GET_LETTER = 65; // shift value to char code specifc to each shape (0>=n>7 + 65) = "ABCDEFG"

    // unpack std::pairs
    int currentX = currentPos.first;
    int currentY = currentPos.second;
    int offsetX = offset.first;
    int offsetY = offset.second;

    for (int x = 0; x < 4; x++) {
        for (int y = 0; y < 4; y++) {
            if (TETROMINO[tetrominoIndex][rotate(x, y, rotation)] == L'X') {
                source[(y + currentY + offsetY)*sourceWidth + (x + currentX + offsetX)] = tetrominoIndex + GET_LETTER;
            }
        }
    }
}

// help render one line text onto wchar_t *screen defined in Frame class
void renderText(wchar_t * source, int sourceWidth, const wchar_t * copy, int copyWidth, std::pair<int,int> offset) {
    // unpack std::pairs
    int offsetX = offset.first;
    int offsetY = offset.second;

    for (int x = 0; x < copyWidth; x++) {
            source[(offsetY)*sourceWidth + (x + offsetX)] = copy[x];
    }
}

// rotates TETROMINO piece (0 =
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
    }
    return 0;
}

bool doesPieceFit(int tetrominoIndex, int rotation, int positionX, int positionY, wchar_t *playArea) {
    for (int x = 0; x < 4; ++x) {
        for (int y = 0; y < 4; ++y) {
            int  pieceIndex = rotate(x, y, rotation);

            int fieldIndex = (positionY + y) * FIELD_WIDTH + (positionX + x);

            // validating within bounds
            if (positionX + x >= 0 && positionX + x < FIELD_HEIGHT) {
                if (positionY + y >= 0 && positionY + y < FIELD_HEIGHT) {
                    if (TETROMINO[tetrominoIndex][pieceIndex] == L'X' && playArea[fieldIndex] != 0) { // checking if index is already occupied (0 is free space)
                        return false; // false if collision happened
                    }
                }
            }
        }
    }
    return true; // true if collision not happened
}
