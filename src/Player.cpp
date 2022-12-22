#include "../headers/Player.hpp"
#include "../headers/TextureManager.hpp"
#include "../headers/Game.hpp"

Player::Player(int health, int damage, double speed, int shield, int xPosition, int yPosition, const char* filePath) {
    this->health = health;
    this->damage = damage;
    this->speed = speed;
    this->shield = shield;
    this->xPosition = xPosition;
    this->yPosition = yPosition;
    srcRect = new SDL_Rect();
    destRect = new SDL_Rect();

    this->texture = TextureManager::loadTexture(filePath);

    // Intializing velocity variables to zero
    setXVelocity(0);
    setYVelocity(0);

    // Setting w, h, x, y of srcRect.
    SDL_QueryTexture(this->texture, NULL, NULL, &srcRect->w, &srcRect->h);
    srcRect->x = 0;
    srcRect->y = 0;

    // Setting w, h, x, y of destRect.
    destRect->w = srcRect->w * 3;
    destRect->h = srcRect->h * 3;
    destRect->x = 0;
    destRect->y = 0;
}

void Player::rangedAttack(){
    
}

int Player::healUp(){
    if(killCount % 5 == 0){
        this->health += 50;
    }
    return health;
}
int Player::getShield(){
    if(killCount % 10 == 0){
        this->shield += 100;
    }
    return shield;
}

void Player::ultimate(){
    
}
void Player::levelUp(){
    
}
void Player::increaseExp(){

}
void Player::setKillCount(int count){
    killCount = count;
}
