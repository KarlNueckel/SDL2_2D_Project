#ifndef TEXTUREMANAGER_HPP
#define TEXTUREMANAGER_HPP

#include "Game.hpp"

class TextureManager {
    public:
        static SDL_Texture* loadTexture(const char* filePath);
        static void draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);
};

#endif
