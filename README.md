[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/UqIUAt8b)

Project Descripton:
This is a RPG Project that has a player fighting 2 different kinds of enemies with different rules coded to them. There is a Infected header that makes the infected enemy revive after its death. The other enemy is a skeleton that takes double damage from the player when attacked. You can play until the players health is at zero or if you want to quit there is always an output after each enemy killed that says "do you want to continue?" if you deciede to continue the game. continues with randomizing the next enemy (infected or skeleton) and if you want to quit the game ends and gives you an output that says "thanks for playing".

This is the Unit class i was using for this project this class i used both cpp and header usage for the unit code to work properly.

# pragma once
# include <algorithm>
# include <iostream>
# using namespace std;
# class Unit
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




