#ifndef MELEE_HPP
#define MELEE_HPP
#include "Enemy.hpp"
#include "Entity.hpp"

using namespace std;

class Melee : public Enemy{
    public:
        void meleeAttack(Player*);

};
#endif


