#ifndef CONSOLETETRIS_CONSTANTS_H
#define CONSOLETETRIS_CONSTANTS_H
#include <utility>
constexpr short SCREEN_WIDTH = 80;
constexpr short SCREEN_HEIGHT = 30;
constexpr int FIELD_WIDTH = 12;
constexpr int FIELD_HEIGHT = 18;
constexpr std::pair<int,int> playAreaOffset = {2,2};
enum ExitCode {
 OK,
 RETURN,
 EXIT
};
#endif //CONSOLETETRIS_CONSTANTS_H
