#include "gtest/gtest.h" 
#include "../headers/Game.hpp"


//Testing GameDifficulty setter and getter operations
TEST(InputValidatonTest_PASS, getDifficulty0_NoThrow) {//test function runs
    Game *test = new Game;
    test->setGameDifficulty("Easy");
    EXPECT_NO_THROW(test->getGameDifficulty());
}
TEST(InputValidatonTest_PASS, getDifficulty1_goodInputs) {//test function works with correct inputs
    Game *test = new Game;
    test->setGameDifficulty("Easy");
    EXPECT_EQ(test->getGameDifficulty(), 0);//make sure that the easy game difficulty is being proccessed correctly
}
TEST(InputValidatonTest_PASS, getDifficulty2_badInputs) {//test function works with bad inputs
    Game *test = new Game;
    test->setGameDifficulty("bad input");
    EXPECT_EQ(test->getGameDifficulty(), 0);//should catch default case
}
TEST(InputValidatonTest_FAIL, getDifficulty3_falseOutputs) {
    Game *test = new Game;
    test->setGameDifficulty("Medium");
    EXPECT_NE(test->getGameDifficulty(), 0);//should return false
}


//Testing GameBackground setter and getter operations
TEST(InputValidatonTest_PASS, getBackGround0_NoThrow) {//test function runs
    Game *test = new Game;
    test->setBackground(1);
    EXPECT_NO_THROW(test->getBackground());
}
TEST(InputValidatonTest_PASS, getBackGround1_goodInput) {//test function works with good inputs
    Game *test = new Game;
    test->setBackground(2);
    EXPECT_EQ(test->getBackground(), 2);
}
TEST(InputValidatonTest_PASS, getBackGround2_badInput) {//test function works with bad inputs
    Game *test = new Game;
    test->setBackground(-97);
    EXPECT_EQ(test->getBackground(), 1);//should catch default case
}
TEST(InputValidatonTest_FAIL, getBackGround3_falseOutput) {
    Game *test = new Game;
    test->setBackground(2);
    EXPECT_NE(test->getBackground(), 1);//should return false
}
