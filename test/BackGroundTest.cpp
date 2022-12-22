#include "gtest/gtest.h" 
#include "../headers/Map.hpp"
#include "../headers/Game.hpp"

//Test basic functions of Map class
TEST(BackGroundTest_PASS, map0_NoThrow_DefaultConstructor) {//test class runs
    Map *test = new Map();//test default constructor
    EXPECT_NO_THROW(test->drawMap());
}
TEST(BackGroundTest_PASS, map0_NoThrow_PamConstructor) {//test class runs
    Map *test = new Map(1);//test param constructor
    EXPECT_NO_THROW(test->drawMap());
}

//Test map after initializing using the Game class
TEST(BackGroundTest_PASS, map1_Game_to_Map_Constructor) {//test Game can accurately use Map class to create background
    Game *test = new Game();
    test->setBackground(1);
    int testBackground = test->getBackground();

    Map* use = new Map(testBackground);
    EXPECT_NO_THROW(use->drawMap());
}

