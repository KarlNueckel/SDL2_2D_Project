#include "../headers/Boss.hpp"
#include "../headers/TextureManager.hpp"
#include "../headers/Game.hpp"

Boss::Boss(int health, int damage, double speed, int shield, int xPosition, int yPosition, const char* filePath) {
    this->health = health;
    this->damage = damage;
    this->speed = speed;
    this->shield = shield;
    this->xPosition = xPosition;
    this->yPosition = yPosition;

    this->texture = TextureManager::loadTexture(filePath);
    
}


void Boss::meleeAttack(){
    
}

int Boss::healUp(){
    //based on times boss hits player or based on game running time?
    this->health += 100;
    return health;
}
int Boss::getShield(){
    //based on times boss hits player or based on game running time?
    this->shield += 100;
    return shield;
}

void Boss::specialAttack(){
    
}
