#include "gtest/gtest.h" 
#include "../headers/Player.hpp"

//Testing player health at different points
TEST(Healthtest_PASS, health0_NoThrow) {//test class runs
    Player *test = new Player(100, 5, 5, 50, 0, 0, "sprites/characters/Player/stillplayer1.png");
    EXPECT_NO_THROW(test->rangedAttack());
}
TEST(Healthtest_PASS, health1_sufficientKills) {
    int health = 100;
    Player *test = new Player(health, 5, 5, 50, 0, 0, "sprites/characters/Player/stillplayer1.png");//initialize player
    test->setKillCount(5);//testing that if the player has at least 5 kills they can heal
    EXPECT_EQ(test->healUp(),150);
}
TEST(Healthtest_PASS, health2_insufficientKills) {//test class runs
    int health = 100;
    Player *test = new Player(health, 5, 5, 50, 0, 0, "sprites/characters/Player/stillplayer1.png");//initialize player
    test->setKillCount(3);//testing that if the player has at least 5 kills they can heal
    EXPECT_EQ(test->healUp(),100);
}

//Testing player shield at different points
TEST(Healthtest_PASS, shield1_sufficientKills) {//test class runs
    int shield = 0; //showing where the shield variable goes
    Player *test = new Player(100, 5, 5, shield, 0, 0, "sprites/characters/Player/stillplayer1.png");
    test->setKillCount(10);
    EXPECT_EQ(test->getShield(), 100);//shield should increment by 100 from sufficient number of kills
}
TEST(Healthtest_PASS, shield2_insufficientKills) {//test class runs
    int shield = 0; //showing where the shield variable goes
    Player *test = new Player(100, 5, 5, shield, 0, 0, "sprites/characters/Player/stillplayer1.png");
    test->setKillCount(7);
    EXPECT_EQ(test->getShield(), 0);//shield shouldnt increment by 100 from insufficient kills
}
TEST(Healthtest_PASS, shield3_overKills) {//test class runs
    int shield = 0; //showing where the shield variable goes
    Player *test = new Player(100, 5, 5, shield, 0, 0, "sprites/characters/Player/stillplayer1.png");
    test->setKillCount(11);
    EXPECT_EQ(test->getShield(), 0);//shield shouldnt increment by only 100 from killCount < 20
}