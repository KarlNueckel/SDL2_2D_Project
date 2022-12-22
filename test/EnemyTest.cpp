#include "gtest/gtest.h" 
#include "../headers/Enemy.hpp"


//Test basic functions of Enemy class
TEST(EnemyTest_PASS, followPlayer) {//test followPlayer function works
    Enemy *test = new Enemy;

    Player *playerPos = new Player(100, 5, 5, 50, 0, 0, "sprites/characters/Player/stillplayer1.png");
    EXPECT_NO_THROW(test->followPlayer(playerPos));
}
TEST(EnemyTest_PASS, getPlayerPos) {//test getPlayerPos function works
    Enemy *test = new Enemy;

    Player *playerPos = new Player(100, 5, 5, 50, 0, 0, "sprites/characters/Player/stillplayer1.png");
    EXPECT_NO_THROW(test->getPlayerPos(playerPos));
}
