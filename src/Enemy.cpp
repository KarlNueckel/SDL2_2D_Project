#include "../headers/Enemy.hpp"

std::pair<int, int> Enemy::getPlayerPos(Player* player) const {

    std::pair<int, int> coordinate;
    coordinate.first = player->getXPosition();
    coordinate.second = player->getYPosition();

    return coordinate;
};

void Enemy::followPlayer(Player* player) {
    std::pair<int, int> playerCoordinates = getPlayerPos(player);
    int playerX = playerCoordinates.first;
    int playerY = playerCoordinates.second;
    int proximity = 1;
    
    int pace = 1; // Speed of Enemy. Default is 1: Any higher and enemy collides with player.

    if((this->xPosition != playerX) && (this->xPosition != playerX-proximity) && (this->xPosition != playerX+proximity)){
      
         (this->xPosition<playerX) ? this->xPosition+=pace : this->xPosition-=pace;
    }

    if((this->yPosition != playerY) && (this->yPosition != (playerY-proximity)) && (this->yPosition != (playerY+proximity))){

         (this->yPosition<playerY) ? this->yPosition+=pace : this->yPosition-=pace;
    }
}