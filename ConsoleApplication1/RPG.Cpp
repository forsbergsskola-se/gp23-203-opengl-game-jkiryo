#include "Unit.h"
#include <algorithm>
#include <Windows.h>
#include <iostream>
#include "ConsoleApplication1.cpp"
#include "Skeleton.h"


using namespace std;

unit* create_hero()
{
    return new unit("\033[1;33mHero\033[0m", 100);
}

unit* create_enemy()
{
    return new unit("Enemy", 3);
}

int main()
{
    // initialization
    unit* hero = create_hero();

    unit* enemy = create_enemy();

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

    return 0;
}
