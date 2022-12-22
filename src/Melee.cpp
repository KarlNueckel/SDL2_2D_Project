#include "../headers/Melee.hpp"
#include "../headers/Game.hpp"
#include "../headers/TextureManager.hpp"

void Melee::meleeAttack(Player* p){

    int playerX = getPlayerPos(p).first;
    int playerY = getPlayerPos(p).second;
    int proximity = 50;
    this->damage = 20;
    int pace = 1; // Speed of Enemy. Default is 1: Any higher and enemy collides with player.

    if((this->xPosition != playerX) && (this->xPosition != playerX-proximity) && (this->xPosition != playerX+proximity)){
      
         (this->xPosition<playerX) ? this->xPosition+=pace : this->xPosition-=pace;
    }


    if((this->yPosition != playerY) && (this->yPosition != (playerY-proximity)) && (this->yPosition != (playerY+proximity))){

         (this->yPosition<playerY) ? this->yPosition+=pace : this->yPosition-=pace;
    }

}