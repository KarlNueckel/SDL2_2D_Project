#include "../headers/Projectile.hpp"
#include "../headers/TextureManager.hpp"

Projectile::Projectile(Point2D positionCoordinates, Point2D mouseCoordinates, int velocity, const char* filePath) {
    this->positionCoordinates = positionCoordinates;
    this->velocity = velocity;
    this->directionVector = Vector2D(positionCoordinates, mouseCoordinates).velocityNormalize(velocity);

    srcRect = new SDL_Rect();
    destRect = new SDL_Rect();
    texture = TextureManager::loadTexture(filePath);

    // Setting w, h, x, y of srcRect.
    SDL_QueryTexture(texture, NULL, NULL, &srcRect->w, &srcRect->h);
    srcRect->x = 0;
    srcRect->y = 0;

    // Setting w, h, x, y of destRect.
    destRect->w = srcRect->w;
    destRect->h = srcRect->h;
    destRect->x = srcRect->x;
    destRect->y = srcRect->y;
}

Projectile::~Projectile() {
    delete srcRect;
    delete destRect;
}

void Projectile::update() {
    positionCoordinates.x += directionVector.xComponent;
    positionCoordinates.y += directionVector.yComponent;

    destRect->x = positionCoordinates.x;
    destRect->y = positionCoordinates.y;
}

void Projectile::render() const {
    SDL_RenderCopy(Game::renderer, texture, srcRect, destRect);
}

SDL_Rect* Projectile::getDestRect() const {
    return destRect;
}