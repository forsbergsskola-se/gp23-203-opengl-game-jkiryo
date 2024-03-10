#pragma once
#include "unit.h"

using namespace std;

class Skeleton : virtual Unit
{
public:

    //when skeleton spawns it shows its health
    Skeleton() : Unit("Skeleton", 4) 
    {
        cout << "An Skeleton \033[1;32mSpawned\033[0m with \033[1;34m50 Health\033[0m.\n";
    }


    //Skeleton takes double damage and prints that attack is very effective
    virtual void takeDamage(int damage) override
    {
        cout << "The attack is very effective!\n";
        Unit::takeDamage(damage * 2);
    }
};
