#include <iostream>

#include <string>
#include "enemy.h"

using std::cout;

int main() {

    Enemy goblin("Goblin");
    string *weapons = goblin.getWeapons();

    for (int i = 0; i < 5; i++)
        std::cout << weapons[i] << "\n";
    return 0;
}
