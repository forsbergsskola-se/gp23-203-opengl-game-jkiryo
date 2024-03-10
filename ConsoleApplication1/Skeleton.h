#pragma once
#include "unit.h"

using namespace std;

class Skeleton : public Unit
{
public:

    //when skeleton spawns it shows its health
    Skeleton() : Unit("Skeleton", 4) 
    {
        cout << "Skeleton spawned with " << get_health() << " Health." << endl;
    }


    //Skeleton takes double damage and prints that attack is very effective
    virtual void takeDamage(int damage) override
    {
        cout << "The attack is very effective!\n";
        Unit::takeDamage(damage * 2);
    }
};
