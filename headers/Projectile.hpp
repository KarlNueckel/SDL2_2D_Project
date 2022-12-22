#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

#include "SDL2/SDL.h"
#include "Vector2D.hpp"

class Projectile {
    private:
        Vector2D directionVector;
        Point2D positionCoordinates;
        int velocity;

        SDL_Texture* texture;
        SDL_Rect* srcRect;
        SDL_Rect* destRect;
    
    public:
        Projectile(Point2D positionCoordinates, Point2D mouseCoordinates, int velocity, const char* filePath);
        ~Projectile();

        void update();
        void render() const;

        SDL_Rect* getDestRect() const;
};

#endif
