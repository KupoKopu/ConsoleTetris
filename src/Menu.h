#ifndef CONSOLETETRIS_MENU_H
#define CONSOLETETRIS_MENU_H
#include <thread>
#include <string>
#include "Frame.h"
#include "CoordHelper.h"
#include "Terminal.h"

using namespace std::chrono_literals;

class Menu : public Frame {
public:
    void tick() override;
    void userInput() override;
    void draw() override;
    void emitExitCode(ExitCode code) override;

    Menu(int width, int height, ExitCode &outExitCode);

    void start() override;
    [[nodiscard]] wchar_t *getScreen() const;
private:
    int screenArea;

    int currentSelection;
    std::pair<std::wstring, std::pair<int,int>> menuOptions[2];

    bool keyPressed[2];
    ExitCode &outExitCode;

    Terminal *terminal;
};
#endif //CONSOLETETRIS_MENU_H
