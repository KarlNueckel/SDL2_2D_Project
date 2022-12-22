#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Entity.hpp"

using namespace std;

class Player : public Entity {
    private:
        int exp;
        int killCount;
    public:
        Player(int health, int damage, double speed, int shield, int xPos, int yPos, const char* filePath);
        
        void rangedAttack();
        int healUp();
        int getShield();
        void setKillCount(int count);
        void ultimate();
        void levelUp();
        void increaseExp();
};

#endif
