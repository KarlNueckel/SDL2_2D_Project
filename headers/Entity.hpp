#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "SDL2/SDL.h"

class Entity {
    protected:
        double health;
        double damage;
        double shield;
        int speed;
        int xPosition;
        int yPosition;
        int xVelocity;
        int yVelocity;
        SDL_Texture* texture;
        SDL_Rect* srcRect;
        SDL_Rect* destRect;

    public:
        Entity();
        ~Entity();
        
        void update();
        void render();

        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();

        int getSpeed() const;
        
        int getXPosition() const;
        int getYPosition() const;
        int getXVelocity();
        int getYVelocity();

        void setXVelocity(int velocity);
        void setYVelocity(int velocity);

        SDL_Rect* getSrcRect() const;
        SDL_Rect* getDestRect() const;
        
        SDL_Texture* getTexture() const;
};

#endif
