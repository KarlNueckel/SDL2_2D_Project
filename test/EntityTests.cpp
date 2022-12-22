#include "gtest/gtest.h" 
#include "../headers/Entity.hpp"
#include "../headers/TextureManager.hpp"
#include "../headers/Player.hpp"
#include "../headers/Game.hpp"

//Test basic functions of Entity class
TEST(EntityTest_PASS, getSpeed) {//test class Entity can get speed from class Player
    int speed = 5; //showing where speed is inserted
    Entity *test = new Player(100, 5, speed, 50, 0, 0, "sprites/characters/Player/stillplayer1.png"); //using entity pointer to run getSpeed() function later
    
    EXPECT_EQ(test->getSpeed(),speed);
}
TEST(EntityTest_PASS, getXposition) {//test class Entity can get xPosition from class Player
    int xPosition = 5;
    Entity *test = new Player(100, 5, 5, 50, xPosition, 0, "sprites/characters/Player/stillplayer1.png"); //using entity pointer to run getXPosition() function later
    
    EXPECT_EQ(test->getXPosition(), xPosition);
}
TEST(EntityTest_PASS, getYposition) {//test class Entity can get YPosition from class Player
    int yPosition = 7;
    Entity *test = new Player(100, 5, 5, 50, 0, yPosition, "sprites/characters/Player/stillplayer1.png"); //using entity pointer to run getYPosition() function later
    
    EXPECT_EQ(test->getYPosition(), yPosition);
}

//x and y velocity tests
TEST(EntityTest_PASS, getXVelocity){
    Entity *test = new Entity();

    test->setXVelocity(5);
    EXPECT_EQ(test->getXVelocity(), 5);
}
TEST(EntityTest_PASS, getYVelocity){
    Entity *test = new Entity();

    test->setYVelocity(6);
    EXPECT_EQ(test->getYVelocity(), 6);
}

//void functions
TEST(EntityTest_PASS, moveUp){
    Entity *test = new Entity();

    EXPECT_NO_THROW(test->moveUp());
}
TEST(EntityTest_PASS, moveDown){
    Entity *test = new Entity();

    EXPECT_NO_THROW(test->moveDown());
}
TEST(EntityTest_PASS, moveLeft){
    Entity *test = new Entity();

    EXPECT_NO_THROW(test->moveUp());
}
TEST(EntityTest_PASS, moveRight){
    Entity *test = new Entity();

    EXPECT_NO_THROW(test->moveDown());
}
