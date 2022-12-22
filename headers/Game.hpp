#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include <vector>
#include <cstdlib>
#include <utility>
#include <ctime>

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "Player.hpp"
#include "Entity.hpp"
#include "Projectile.hpp"
#include "Orc.hpp"

enum GAME_STATUS {
    RUNNING,
    OVER,
};

class Game {
    public:
        Game();
        ~Game();

        void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

        void handleEvents();
        void update();
        void render();
        void clean();
        void checkCollisions();
        void addToProjectileList(Projectile* projectile);
        void addToEnemyList(Enemy* melee);
        pair<int,int> generateEnemyCoordinates();
        
        void setGameDifficulty(std::string difficulty);
        void setBackground(int image);
        int getGameDifficulty();
        int getBackground();
        GAME_STATUS getStatus() const;
        void setStatus(GAME_STATUS gameStatus);

        bool running();
        static SDL_Renderer* renderer;
    
    private:
        SDL_Window* window;
        SDL_Event event;
        bool isRunning;
        int gameDifficulty;
        Player* player;
        std::vector<Projectile*> projectileList;
        std::vector<Enemy*> enemyList;
        int background;
        GAME_STATUS gameStatus;
};

#endif