#pragma once
#include "unit.h"

class Skeleton : public Unit
{
public:
    Skeleton() : Unit("Skeleton", 4) {}

    virtual void takeDamage(int damage) override
    {
        cout << "The attack is very effective!\n";
        Unit::takeDamage(damage * 2);
    }
};
