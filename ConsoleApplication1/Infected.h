#pragma once
#include "Unit.h"

using namespace std;

class Infected : virtual public Unit //Inheriting from the unit class
{
    bool revived = true;

public:
    Infected() : Unit("Infected", 2), revived(false) 
    {
       
    }
    

    //overriding the takeDamage method
    virtual void takeDamage(int damage) override 
    {

        Unit::takeDamage(damage);
        //Checking if the infected enemy is dead or not
        if (this->is_dead() && !revived) 
        {

            cout << "Infected has died and risen from the dead.\n";

            name_ = "Zombie"; //changes infected to zombie

            health_ = 1; //Sets the zombies health to 1

            revived = true; // Marked as revived
        }
    }

};



