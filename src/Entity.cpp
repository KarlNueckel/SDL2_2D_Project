#include "../headers/Entity.hpp"
#include "../headers/TextureManager.hpp"

Entity::Entity(){
    xPosition = 0;
    xVelocity = 0;

    yPosition = 0;
    yVelocity = 0;

    health = 100;
    shield = 50;
    damage = 5; 
    speed = 5;
}

Entity::~Entity() {
    delete srcRect;
    delete destRect;
}

void Entity::update() {
    if (xPosition < 0) {
        xPosition = 0;
    }
    else if (xPosition > 800 - destRect->w) {
        xPosition = 800 - destRect->w;
    }
    else {
        xPosition += xVelocity;
    }
    
    if (yPosition < 0) {
        yPosition = 0;
    }
    else if (yPosition > 640 - destRect->h) {
        yPosition = 640 - destRect->h;
    }
    else {
        yPosition += yVelocity;
    }

    destRect->x = xPosition;
    destRect->y = yPosition;
}

void Entity::render() {
    SDL_RenderCopy(Game::renderer, texture, srcRect, destRect);
}

void Entity::moveUp() {
    yVelocity = -speed;
}

void Entity::moveDown() {
    yVelocity = speed;
}

void Entity::moveLeft() {
    xVelocity = -speed;
}

void Entity::moveRight() {
    xVelocity = speed;
}

int Entity::getSpeed() const {
    return speed;
}

int Entity::getXPosition() const {
    return xPosition;
}

int Entity::getYPosition() const {
    return yPosition;
}

void Entity::setXVelocity(int velocity) {
    xVelocity = velocity;
}

void Entity::setYVelocity(int velocity) {
    yVelocity = velocity;
}

SDL_Rect* Entity::getSrcRect() const {
    return srcRect;
}

SDL_Rect* Entity::getDestRect() const {
    return destRect;
}

SDL_Texture* Entity::getTexture() const {
    return texture;
}
int Entity::getXVelocity(){
    return xVelocity;
}
int Entity::getYVelocity(){
    return yVelocity;
}