#include <iostream>
#include <ctime>

#include "../headers/Game.hpp"
#include "../headers/TextureManager.hpp"
#include "../headers/Map.hpp"


SDL_Renderer* Game::renderer = nullptr;
Map * map;
static int numEnemiesToBeSpawned = 1;

Game::Game() {

}

Game::~Game() {
    delete player;
    
    for (int i = 0; i < enemyList.size(); ++i) {
        delete enemyList[i];
    }

    for (int i = 0; i < projectileList.size(); ++i) {
        delete projectileList[i];
    }
}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
    int fullscreenFlag = 0;

    if (fullscreen) {
        fullscreenFlag = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "Subsystems initialized..." << std::endl;

        window = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreenFlag); 
       
        if (window) {
            std::cout << "Window created!" << std::endl;
        }

        Game::renderer = SDL_CreateRenderer(window, -1, 0);

        if (renderer) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

            std::cout << "Renderer created!" << std::endl;
        }

        isRunning = true;
        gameStatus = GAME_STATUS::RUNNING;
        srand(time(0));
    } 
    else {
        isRunning = false;
    }

    // Create player
    player = new Player(100, 5, 5, 50, (800/2), (640/2), "sprites/characters/Player/stillplayer1.png");
    
    setBackground(2);
    map = new Map(background);

    pair<int,int> enemyCoordinates = generateEnemyCoordinates();   
    addToEnemyList(new Orc(100, 5, 5, 50, enemyCoordinates.first, enemyCoordinates.second, "sprites/characters/Enemy/Orc Crew/orctest.png"));
}

void Game::handleEvents() {
    SDL_PollEvent(&event);

    if (event.type == SDL_QUIT) {
        isRunning = false;
    }

    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
            case SDLK_w:
                player->moveUp();
                break;
            case SDLK_a:
                player->moveLeft();
                break;
            case SDLK_s:
                player->moveDown();
                break;
            case SDLK_d:
                player->moveRight();
                break;
            default:
                break;
        }
    }

    if (event.type == SDL_KEYUP) {
        switch (event.key.keysym.sym) {
            case SDLK_w:
                player->setYVelocity(0);
                break;
            case SDLK_a:
                player->setXVelocity(0);
                break;
            case SDLK_s:
                player->setYVelocity(0);
                break;
            case SDLK_d:
                player->setXVelocity(0);
                break;
            default:
                break;
        }
    }

    if (event.type == SDL_MOUSEBUTTONDOWN) {
        if (event.button.button == SDL_BUTTON_LEFT) {
            int mouseX = 0;
            int mouseY = 0;

            SDL_GetMouseState(&mouseX, &mouseY);
            
            addToProjectileList(new Projectile(Point2D(player->getXPosition() + 10, player->getYPosition() + 20), Point2D(mouseX, mouseY), 10, "sprites/bullets/blue_dot.png"));
        }
    }
}

void Game::addToProjectileList(Projectile* projectile) {
    projectileList.push_back(projectile);
}

void Game::addToEnemyList(Enemy* enemy) {
    enemyList.push_back(enemy);
}

void Game::update() {
    if (getStatus() == GAME_STATUS::OVER) {
        std::cout << "Restarting game" << std::endl;

        for (int i = 0; i < enemyList.size(); ++i) {
            delete enemyList[i];
        }
        enemyList.clear();

        for (int i = 0; i < projectileList.size(); ++i) {
            delete projectileList[i];
        }
        projectileList.clear();

        numEnemiesToBeSpawned = 1;

        delete player;
        player = new Player(100, 5, 5, 50, (800/2), (640/2), "sprites/characters/Player/stillplayer1.png");
        
        setStatus(GAME_STATUS::RUNNING);
    }

    // Spawn enemy loop.
    if (enemyList.size() == 0) {
        for (int i = 0; i < numEnemiesToBeSpawned; ++i) {

            pair<int,int> enemyCoordinates = generateEnemyCoordinates();   
            addToEnemyList(new Orc(100, 10, 5, 50, enemyCoordinates.first, enemyCoordinates.second, "sprites/characters/Enemy/Orc Crew/orctest.png"));
        }

        numEnemiesToBeSpawned += 1;
    }

    player->update();

    for (Projectile* projectile : projectileList) {
        projectile->update();
    }

    for (Enemy* enemy : enemyList) {
        enemy->followPlayer(player);
        enemy->update();
    }

    checkCollisions();
}

void Game::render() {
    SDL_RenderClear(renderer);
    map->drawMap(); //load map
    // Renders player.png to window
    player->render();

    for (Projectile* projectile : projectileList) {
        projectile->render();
    }

    for (Enemy* enemy : enemyList) {
        enemy->render();
    }
    // testEnemy->render(); //TEST: Enemy follows player

    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    
    delete map;

    std::cout << "Window and renderer destroyed. Quitting." << std::endl;
}

bool Game::running() {
    return isRunning;
}
void Game::setBackground(int image){
    if (image > 0 && image < 4){
        background = image;
    }
    else{//default background
        background = 1;
    }
}

void Game::setGameDifficulty(std::string difficulty){
    if(difficulty == "Medium" || difficulty == "medium"){
        gameDifficulty = 1; //1 for medium
    }
    else if(difficulty == "Hard" || difficulty == "hard"){
        gameDifficulty = 2; //2 for hard
    }
    else{//Easy case
        gameDifficulty = 0; //0 for easy 
    }
}
int Game::getGameDifficulty(){
    return gameDifficulty;
}
        
int Game::getBackground(){
    return background;
}

void Game::checkCollisions() {
    // Check bullet to enemy collision
    int projectileIndex = 0;
    for (Projectile* projectile : projectileList) {
        int enemyIndex = 0;
        for (Enemy* enemy : enemyList) {
            if (SDL_HasIntersection(projectile->getDestRect(), enemy->getDestRect())) {
                delete projectileList[projectileIndex];
                projectileList.erase(projectileList.begin() + projectileIndex);
                delete enemyList[enemyIndex];
                enemyList.erase(enemyList.begin() + enemyIndex);
                return;
            }
            enemyIndex++;
        }
        projectileIndex++;
    }

    // Check player and enemy collision.
    for (Enemy* enemy : enemyList) {
        if (SDL_HasIntersection(enemy->getDestRect(), player->getDestRect())) {
            // Clear enemies and player from screen and have game over with play again button.
            std::cout << "Game over." << std::endl;
            setStatus(GAME_STATUS::OVER);
            return;
        }
    }
}

GAME_STATUS Game::getStatus() const {
    return gameStatus;
}

void Game::setStatus(GAME_STATUS gameStatus) {
    this->gameStatus = gameStatus;
}

pair<int,int> Game::generateEnemyCoordinates(){

    pair<int,int> enemyCoordinates;   
    int randomPerimeter = rand()%2;
    int xPerimeter[] = {0,800}; 
    int yPerimeter[] = {0,600};
            
    int determineCoordinates = rand()%2;
    if(determineCoordinates==0){
         enemyCoordinates.first = xPerimeter[randomPerimeter];
         enemyCoordinates.second = (rand() % 600);
    }
     else{
         enemyCoordinates.first = (rand() % 800);
         enemyCoordinates.second = yPerimeter[randomPerimeter];
    }

    return enemyCoordinates;
}