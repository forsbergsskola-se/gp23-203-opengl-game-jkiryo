#pragma once
#include <algorithm>
#include <iostream>
#include <Windows.h>

class Unit
{
public:

    explicit Unit(const char* name, const int health) : name_{ name }
    {
        health_ = clamp(health, 0, 100);

        cout << name << " \033[1;32mspawned\033[0m with \033[1;34m" << health << " Health\033[0m.\n";
    }

    // Virtual destr
    virtual ~Unit()
    {
        cout << name_ << " \033[1;31mdied\033[0m.\n";
    }

    void attack(Unit& other)
    {
        cout << name_ << " \033[1;31mattacks\033[0m " << other.name_ << ".\n";
        other.takeDamage(1);
    }

    bool is_dead() const { return health_ <= 0; }

    int get_health() const { return health_; }

    void set_health(const int value)
    {
        health_ = clamp(value, 0, 100);

        cout << name_ << " now has \033[1;34m" << health_ << " Health\033[0m.\n";
    }

    virtual void takeDamage(int damage)
    {
        health_ -= damage;
    }

protected:
    const char* name_;
    int health_;
};



