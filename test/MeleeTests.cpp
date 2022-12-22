#include "gtest/gtest.h"
#include "SDL2/SDL.h"
#include "../headers/Melee.hpp"


//Melee.cpp tests
//test void functions
TEST(MeleeTest_PASS, meleeAttack) {
    Melee *test = new Melee();
    Player *user = new Player(100, 5, 5, 50, 0, 0, "sprites/characters/Player/stillplayer1.png");

    EXPECT_NO_THROW(test->meleeAttack(user));
}