#pragma once

#include "Unit.h"

using namespace std;

class Infected : public Unit {

public:
    Infected() : Unit("Infected", 2), revived(false) {} //parameter less constructors

    virtual void takeDamage(int damage) override 
    {

        Unit::takeDamage(damage);

        if (is_dead() && !Risen) 
        {

            Risen();
        }
    }

private:
    bool revived;

    void Risen() 
{
        cout << "Infected has risen from the dead as Zombie with 1 Health.\n";

        name_ = "Zombie";

        health_ = 1;

        revived = true;
    }
};



