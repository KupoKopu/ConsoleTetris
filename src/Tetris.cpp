#include "Tetris.h"

Tetris::Tetris(int width, int height, int fieldWidth, int fieldHeight, ExitCode &outExitCode) : outExitCode(outExitCode) {
    screenWidth = width;
    screenHeight = height;
    screenArea = screenWidth* screenHeight;
    screen = new wchar_t [screenArea];
    for (int i = 0; i < screenWidth * screenHeight; i++) screen[i] = L' ';

    this->fieldWidth = fieldWidth;
    this->fieldHeight = fieldHeight;
    fieldArea = fieldWidth * fieldHeight;
    field = new wchar_t[fieldArea];
    resetField();


    currentPiece = 0;
    currentRotation = 0;
    currentX = fieldWidth / 2;
    currentY = 0;
//    keyPressed[4];
    rotateHold = false;

    speed = 20;
    speedCounter = 0;
    forceDown = false;

    terminal = Terminal::getInstance(80, 30);
}

void Tetris::tick() {
    std::this_thread::sleep_for(50ms);
}

void Tetris::handleSpeedCounter() {
    speedCounter++;
    forceDown = (speedCounter == speed);
}

void Tetris::userInput() {
    // input
    for (int k = 0; k < 4; ++k) {
        keyPressed[k] = (GetAsyncKeyState((unsigned char)("\x27\x25\x28Z"[k]))) != 0;
    }
    // game logic(?)
    // left
    if (keyPressed[1])
    {
        if (doesPieceFit(currentPiece, currentRotation, currentX - 1, currentY, field))
        {
            currentX = currentX - 1;
        }
    }

    // right
    if (keyPressed[0])
    {
        if (doesPieceFit(currentPiece, currentRotation, currentX + 1, currentY, field))
        {
            currentX = currentX + 1;
        }
    }

    // down
    if (keyPressed[2])
    {
        if (doesPieceFit(currentPiece, currentRotation, currentX, currentY + 1, field))
        {
            currentY = currentY + 1;
        }
    }

    // z(rotate clockwise) key
    if (keyPressed[3])
    {
        if (!rotateHold && doesPieceFit(currentPiece, currentRotation + 1, currentX, currentY, field))
        {
            currentRotation = currentRotation + 1;
        }
        rotateHold = true;
    } else {
        rotateHold = false;
    }
}

void Tetris::handleForceDown() {
    if (forceDown) {
        // reset counter
        speedCounter = 0;
        if (doesPieceFit(currentPiece, currentRotation, currentX, currentY + 1, field)) {
            currentY = currentY + 1;
        } else {
            // lock piece to playArea
            for (int x = 0; x < 4; x++) {
                for (int y = 0; y < 4; ++y) {
                    if (tetromino[currentPiece][rotate(x, y, currentRotation)] == L'X') {
                        field[(currentY + y) * fieldWidth + (currentX + x)] = currentPiece + 1;
                    }
                }
            }
            // horizontal match
            for (int y = 0; y < 4; ++y) {
                if (currentY + y < fieldHeight - 1) { // boundary check
                    bool bottomLine = true;
                    for (int x = 1; x < fieldWidth - 1; ++x) {
                        // check if line has empty space
                        bottomLine &= (field[(currentY + y) * fieldWidth + x]) != 0;
                    }

                    if (bottomLine) {
                        for (int x = 1; x < fieldWidth - 1 ; ++x) {
                            // create line
                            field[(currentY + y) * fieldWidth + x] = 8;
                        }
                        verticalLines.push_back(currentY + y);
                    }
                }
            }

            // choose next piece
            currentX = fieldWidth / 2; // starting position maybe extract
            currentY = 0;
            currentRotation = 0;
            currentPiece = rand() % 7;

            // if piece does not fit
            if(!doesPieceFit(currentPiece, currentRotation, currentX, currentY, field)) {
                emitExitCode(RETURN);
                resetField();
            }
        }
    }
}

void Tetris::draw() {
    renderOnTo(screen, screenWidth, field, {fieldWidth, fieldHeight}, playAreaOffset);
    renderPiece(screen, screenWidth, currentPiece, currentRotation, {currentX, currentY}, playAreaOffset);

    if (!verticalLines.empty()) {
        terminal->render(screen);
        std::this_thread::sleep_for(400ms);

        for (auto &v: verticalLines)
            for (int x = 1; x < fieldWidth - 1; x++) {
                for (int py = v; py > 0; py--)
                    field[py * fieldWidth + x] = field[
                            (py - 1) * fieldWidth + x];
                field[x] = 0;
            }

        verticalLines.clear();
    }
}

void Tetris::emitExitCode(ExitCode code) {
    outExitCode = code;
}

wchar_t *Tetris::getScreen() const {
    return screen;
}

void Tetris::start() {
    while(OK == outExitCode) {
        tick();

        handleSpeedCounter();

        userInput();

        handleForceDown();

        draw();

        terminal->render(getScreen());
    }
}

void Tetris::resetField() {
    for (int x = 0; x < fieldWidth; x++)
    {
        for (int y = 0; y < fieldHeight; y++)
        {
            field[y*fieldWidth + x] =  ( x == 0 || x == fieldWidth - 1 || y == fieldHeight - 1) ? 9 : 0;
        }
    }
}
