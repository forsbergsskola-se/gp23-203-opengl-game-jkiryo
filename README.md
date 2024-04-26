[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/UqIUAt8b)

Project Descripton:

This is a RPG Project that has a player fighting 2 different kinds of enemies with different rules coded to them. There is a Infected header that makes the infected enemy revive after its death. The other enemy is a skeleton that takes double damage from the player when attacked. You can play until the players health is at zero or if you want to quit there is always an output after each enemy killed that says "do you want to continue?" if you deciede to continue the game. continues with randomizing the next enemy (infected or skeleton) and if you want to quit the game ends and gives you an output that says "thanks for playing".

This is the Unit class i was using for this project this class.

This is what it is used for and what value it stores:
- When this class is created it initializes with a name and health using the clamp function that limits the health between 0 and 100.
- It also includes a Method for attacking other units
- Unit can also take damage and when it does it decreases.
- Method for a death check
- Method for get and set health

```
#pragma once
#include <algorithm>
#include <iostream>
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

This is the CPP file that uses headers from different kind of enemies and also unit headers to make the game work as required.
i used both cpp and header usage for the unit code to work properly so it can be included in the cpp and get called upon when required.

```
#include <algorithm>
#include <Windows.h>
#include <iostream>
#include "Skeleton.h"
#include "Infected.h"
#include "Unit.h"
using namespace std;

//Create a hero for the player
Unit* create_hero()
{
    return new Unit("\033[1;33mHero\033[0m", 100);
}

//Create a random enemy.
Unit* create_enemy()
{
    srand(time(nullptr));

    int enemyType = rand() % 2;

    if (enemyType == 0) 
    {

        return new Skeleton; // Spawns a Skeleton object
    }
    else 
    {
        return new Infected(); // Spawns an Infected object
    }
   
}

int main()
{
    // initialization
    Unit* hero = create_hero();
    Unit* enemy = create_enemy();
    int killed_monster_count{};
    char should_continue;

    // game loop
    do
    {
        // hero's turn
        Sleep(400);

        hero->attack(*enemy);
        
        Sleep(800);

        if (enemy->is_dead())
        {
            // spawn new enemy
            delete enemy;

            //Showed how many monsters the players have killed
            cout << "\033[1;36mYou killed a total of " << ++killed_monster_count << " Monsters!\033[0m\n";
            cout << "\n";
            enemy = create_enemy();
        }

        else // (if !enemy->is_dead
        {
            // enemy's turn

            cout << "\n";

            enemy->attack(*hero);
        }


        // choice to continue

        Sleep(800);

        cout << "\n";

        cout << "Do you want to continue? y/n\n";

        cin >> should_continue;

    } while (should_continue == 'y');

    // good game
    cout << "Thanks for playing!" << endl;
}




