#include <vector>

#include "src/constants.h"
#include "src/Tetris.h"
#include "src/Menu.h"

int main() {
    // control state of application
    ExitCode exitCode = OK;

    Tetris *tetris = new Tetris(SCREEN_WIDTH, SCREEN_HEIGHT, FIELD_WIDTH, FIELD_HEIGHT, exitCode);
    Menu *menu = new Menu(SCREEN_WIDTH, SCREEN_HEIGHT, exitCode);
    Frame* activeFrame = menu;

    while (exitCode != EXIT) {
        if (OK == exitCode) {
            activeFrame->start();
            continue;
        }
        if (START == exitCode) {
            activeFrame = tetris;
            exitCode = OK;
            continue;
        }
        if (RETURN == exitCode) {
            activeFrame = menu;
            exitCode = OK;
            continue;
        }

    }
}
