#include "gtest/gtest.h" 
#include "../headers/Boss.hpp"


//Test basic functions of Boss class
TEST(BossTest_PASS, constructorTest) {//test class works
    Boss *test = new Boss(100, 10, 5, 50, rand() % (800 - 600 + 1) + 600, rand() % (640 + 1), "sprites/characters/Enemy/Orc Crew/orctest.png");
    
    EXPECT_NO_THROW(test->meleeAttack());
}
TEST(BossTest_PASS, healTest) {//test class works
    Boss *test = new Boss(100, 10, 5, 50, rand() % (800 - 600 + 1) + 600, rand() % (640 + 1), "sprites/characters/Enemy/Orc Crew/orctest.png");
    
    EXPECT_EQ(test->healUp(), 200);//health is 100 and 100+100 = 200
}
TEST(BossTest_PASS, sheildTest) {//test class works
    Boss *test = new Boss(100, 10, 5, 50, rand() % (800 - 600 + 1) + 600, rand() % (640 + 1), "sprites/characters/Enemy/Orc Crew/orctest.png");
    
    EXPECT_EQ(test->getShield(), 150);//sheild is 50 and 50+100 = 150
}