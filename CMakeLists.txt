cmake_minimum_required(VERSION 3.25)
project(ConsoleTetris)

set(CMAKE_CXX_STANDARD 17)

add_executable(ConsoleTetris main.cpp src/Terminal.cpp src/Terminal.h src/PlayArea.h src/PlayArea.cpp src/CoordHelper.cpp src/CoordHelper.h src/constants.h)

add_subdirectory(google-tests)
