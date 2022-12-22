#include "../headers/Orc.hpp"
#include "../headers/Game.hpp"
#include "../headers/TextureManager.hpp"

Orc::Orc(int health, int damage, double speed, int shield, int xPosition, int yPosition, const char* filePath){
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
