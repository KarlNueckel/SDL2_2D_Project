#include "../headers/TextureManager.hpp"

SDL_Texture* TextureManager::loadTexture(const char* filePath) {
    
    SDL_Surface* tempSurface = IMG_Load(filePath);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
    SDL_FreeSurface(tempSurface);

    return texture;
}
void TextureManager::draw(SDL_Texture * tex, SDL_Rect src, SDL_Rect dest){
    SDL_RenderCopy(Game::renderer, tex, &src, &dest); 
}