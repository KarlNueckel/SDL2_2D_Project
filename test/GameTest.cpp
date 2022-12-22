#include "gtest/gtest.h"
#include "SDL2/SDL.h"
#include "../headers/Game.hpp"


//Game.cpp tests
//test void functions
TEST(GameTest_PASS, handleEvents) {
    Game *test = new Game();

    EXPECT_NO_THROW(test->handleEvents());
}
TEST(GameTest_PASS, update) {
    Game *test = new Game();
    test->init("2D SDL Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);
    test->handleEvents();

    EXPECT_NO_THROW(test->update());
}
TEST(GameTest_PASS, render) {
    Game *test = new Game();
    test->init("2D SDL Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);
    test->handleEvents();
    test->update();

    EXPECT_NO_THROW(test->render());
}
TEST(GameTest_PASS, clean) {
    Game *test = new Game();
    test->init("2D SDL Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);
    test->handleEvents();
    test->update();
    test->render();

    EXPECT_NO_THROW(test->clean());
}
TEST(GameTest_PASS, checkCollisions) {
    Game *test = new Game();
    test->init("2D SDL Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);
    test->handleEvents();
    test->update();

    EXPECT_NO_THROW(test->checkCollisions());
}

//Paramaterized functions
TEST(GameTest_PASS, gameInit) {
    Game *test = new Game();

    EXPECT_NO_THROW(test->init("2D SDL Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false));
}
TEST(GameTest_PASS, addtoEnemyList){
    Game* test = new Game();
    Enemy *orc = new Enemy();

    EXPECT_NO_THROW(test->addToEnemyList(orc));
}

//functions that return a value
TEST(GameTest_PASS, isRunning_true) {
    Game *test = new Game();

    test->init("2D SDL Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);
    EXPECT_EQ(test->running(), true);
}

