#ifndef BOSS_HPP
#define BOSS_HPP
#include "Enemy.hpp"

using namespace std;

class Boss : public Enemy{
    public:
        Boss(int health, int damage, double speed, int shield, int xPos, int yPos, const char* filePath);
        void meleeAttack();
        void rangedAttack();
        int healUp();
        int getShield();
        void specialAttack();
    private:
        int contactCounter;
        
};
#endif