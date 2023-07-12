cmake_minimum_required(VERSION 3.25)
project(Console-Tetris)

set(CMAKE_CXX_STANDARD 17)

add_executable(ConsoleTetris main.cpp src/Terminal.cpp src/Terminal.h src/CoordHelper.cpp src/CoordHelper.h src/Constants.h src/Frame.h src/Tetris.cpp src/Tetris.h src/Menu.cpp src/Menu.h)

include_directories(src)
add_subdirectory(src)

add_subdirectory(google-tests)
