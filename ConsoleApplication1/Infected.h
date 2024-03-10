#pragma once
#include "Unit.h"

using namespace std;

class Infected : virtual public Unit //Inheriting from the unit class
{
    bool revived = true;

public:
    Infected() : Unit("Infected", 2), revived(false) 
    {
        cout << "A Infected \033[1;32mSpawned\033[0m with \033[1;34m50 Health\033[0m.\n";
    }

    //overriding the takeDamage method
    virtual void takeDamage(int damage) override 
    {

        Unit::takeDamage(damage);
        //Checking if the infected enemy is dead or not
        if (this->is_dead() && !revived) 
        {

            cout << "Infected has risen from the dead as Zombie with 1 Health.\n";

            name_ = "Zombie"; //changes infected to zombie

            health_ = 1; //Sets the zombies health to 1

            revived = true; // Marked as revived
        }
    }

};



