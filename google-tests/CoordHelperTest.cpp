#include "gtest/gtest.h"
#include "../src/CoordHelper.h"

TEST(CoordHelper_Suite, render_middle){

    auto *sourceActual = new wchar_t[16+1]{L"...."
                                              "...."
                                              "...."
                                              "...."};
    auto *sourceExpect = new wchar_t[16+1]{L"...."
                                           ".AA."
                                           ".AA."
                                           "...."};
    int sourceWidth = 4;
    auto *copy = new wchar_t [4+1]{L"\x01\x01"
                                      "\x01\x01"};
    std::pair<int,int> copySize = {2,2};
    std::pair<int,int> offset = {1,1};

    renderOnTo(sourceActual, sourceWidth, copy, copySize, offset);

    ASSERT_STREQ(sourceActual, sourceExpect);
}

TEST(CoordHelper_Suite, render_top_half){

    auto *sourceActual = new wchar_t[16+1]{L"...."
                                           "...."
                                           "...."
                                           "...."};
    auto *sourceExpect = new wchar_t[16+1]{L"...."
                                           ".AA."
                                           "...."
                                           "...."};
    int sourceWidth = 4;
    auto *copy = new wchar_t [4+1]{L"\x01\x01"
                                   "\x01\x01"};
    std::pair<int,int> copySize = {2,1};
    std::pair<int,int> offset = {1,1};

    renderOnTo(sourceActual, sourceWidth, copy, copySize, offset);

    ASSERT_STREQ(sourceActual, sourceExpect);
}

TEST(CoordHelper_Suite, render_left_side){

    auto *sourceActual = new wchar_t[16+1]{L"...."
                                           "...."
                                           "...."
                                           "...."};
    auto *sourceExpect = new wchar_t[16+1]{L"...."
                                           ".A.."
                                           ".A.."
                                           "...."};
    int sourceWidth = 4;
    auto *copy = new wchar_t [4+1]{L"\x01\x01"
                                   "\x01\x01"};
    std::pair<int,int> copySize = {1,2};
    std::pair<int,int> offset = {1,1};

    renderOnTo(sourceActual, sourceWidth, copy, copySize, offset);

    ASSERT_STREQ(sourceActual, sourceExpect);
}