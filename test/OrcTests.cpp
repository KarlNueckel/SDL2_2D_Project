#include "gtest/gtest.h"
#include "SDL2/SDL.h"
#include "../headers/Orc.hpp"


//Orc.cpp tests
//test constructor function
TEST(OrcTest_PASS, defaultConstructor) {
    Orc *test = new Orc(100, 10, 5, 50, rand() % (800 - 600 + 1) + 600, rand() % (640 + 1), "sprites/characters/Enemy/Orc Crew/orctest.png");

    EXPECT_EQ(1,1);//if the test got to this part the constructor works correctly
}