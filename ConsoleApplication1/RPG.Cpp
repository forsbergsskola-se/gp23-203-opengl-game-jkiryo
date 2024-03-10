
#include <algorithm>
#include <Windows.h>
#include <iostream>
#include "Skeleton.h"
#include "Infected.h"
#include "Unit.h"


using namespace std;

Unit* create_hero()
{
    return new Unit("\033[1;33mHero\033[0m", 100);
}

Unit* create_enemy()
{
    srand(time(nullptr));

    int enemyType = rand() % 2;

    if (enemyType == 0) 
    {

        return new Skeleton; // Return a Skeleton object
    }
    else 
    {
        return new Infected(); // Return an Infected object
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

        cout << "The attack was very effective!" << endl; // Message when you fight a skeleton.

        Sleep(800);

        if (enemy->is_dead())
        {
            // spawn new enemy
            delete enemy;
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
