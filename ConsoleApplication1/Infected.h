#pragma once

#include "Unit.h"

using namespace std;

class Infected : public Unit //Inheriting from the unit class
{

public:
    Infected() : Unit("Infected", 2), revived(false) {}

    //overriding the takeDamage method
    virtual void takeDamage(int damage) override 
    {

        Unit::takeDamage(damage);

        //Checking if the infected enemy is dead or not
        if (is_dead() && !Risen) 
        {

            Risen(); //The infected rises from th dead
        }
    }

private:
    bool revived;

    void Risen() //Infected rises
{
        cout << "Infected has risen from the dead as Zombie with 1 Health.\n";

        name_ = "Zombie"; //changes infected to zombie

        health_ = 1; //Sets the zombies health to 1

        revived = true; // Marked as revived
    }
};



