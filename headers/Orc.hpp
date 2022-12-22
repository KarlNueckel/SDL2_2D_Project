#ifndef ORC_HPP
#define ORC_HPP
#include "Melee.hpp"
#include "Entity.hpp"

using namespace std;

class Orc : public Melee{
    public:
        Orc(int health, int damage, double speed, int shield, int xPos, int yPos, const char* filePath);
};
#endif