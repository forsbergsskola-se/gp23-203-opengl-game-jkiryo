#pragma once
#include <algorithm>
#include <iostream>
#include <Windows.h>

using namespace std;

class Unit
{
public:

    explicit Unit(const char* name, const int health) : name_{ name }
    {
        health_ = clamp(health, 0, 100);

        cout << name << " \033[1;32mspawned\033[0m with \033[1;34m" << health << " Health\033[0m.\n";
    }

    // Virtual destructor
    virtual ~Unit()
    {
        cout << name_ << " \033[1;31mdied\033[0m.\n";
    }

    //Method for unit attack
    void attack(Unit& other)
    {
        cout << name_ << " \033[1;31mattacks\033[0m " << other.name_ << ".\n";

        other.takeDamage(1);

        //Shows the health of the Enemy/Player after every attack
        cout << other.name_ << " Health " << ": " << other.get_health() << endl;

    }

    //Take Damage method
    virtual void takeDamage(int damage)
    {
        health_ -= damage;
    }

    //Checking if the unit is dead
    bool is_dead() const { return health_ <= 0; }

    //Method to show unit health
    int get_health() const { return health_; }

    //this sets unit health
    void set_health(const int value)
    {
        health_ = clamp(value, 0, 100);

        cout << name_ << " now has \033[1;34m" << health_ << " Health\033[0m.\n";
    }

protected:
    //name of the unit
    const char* name_;

    //health of the unit
    int health_;
};



