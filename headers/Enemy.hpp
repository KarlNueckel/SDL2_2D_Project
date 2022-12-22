#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <utility>
#include <iostream>
#include "Player.hpp"
#include "Entity.hpp"

class Enemy : public Entity{
    public:
        std::pair<int, int> getPlayerPos(Player*) const ;
        void followPlayer(Player* player);
};
#endif