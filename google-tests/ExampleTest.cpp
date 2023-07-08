//
// Created by LMLK-404 on 08/07/2023.
//

#include "gtest/gtest.h"

TEST(Example_Suite, Testing_success){
    int thisIsOne = 1;
    int thisIsTwo = 2;

    EXPECT_NE(thisIsOne, thisIsTwo);
}

TEST(Example_Suite, Testing_failure){
    int thisIsOne = 1;
    int thisIsTwo = 2;

    EXPECT_EQ(thisIsOne, thisIsTwo);
}