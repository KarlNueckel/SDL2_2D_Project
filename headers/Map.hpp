#pragma once

#include "Game.hpp"

class Map
{
    public:
        Map();
        Map(int mapType);
        ~Map();

        void loadMap(int arr[20][25]);
        void drawMap();

    private:
        SDL_Rect src, dest;
        
        SDL_Texture* dungeon;
        SDL_Texture* grass;
        SDL_Texture* plains;

        int map[20][25];

};