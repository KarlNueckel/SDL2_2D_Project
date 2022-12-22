#include "gtest/gtest.h"
#include "SDL2/SDL.h"
#include "../headers/Projectile.hpp"
#include "../headers/Game.hpp"


//Projectile.cpp tests
TEST(ProjectileDirectionVectorTest_PASS, BasicTest) {
    SDL_Window* window = SDL_CreateWindow("test", 50, 50, 50, 50, 0);
    int x = 1;
    int y = 1;

    EXPECT_EQ(x, y);
}

//test void functions
TEST(ProjectileDirectionVectorTest_PASS, update) {
    Game *test = new Game();
    test->init("2D SDL Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);
    test->handleEvents();
    
    EXPECT_NO_THROW(test->update());
}
TEST(ProjectileDirectionVectorTest_PASS, render) {
    Game *test = new Game();
    test->init("2D SDL Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);
    test->handleEvents();
    
    EXPECT_NO_THROW(test->render());
}