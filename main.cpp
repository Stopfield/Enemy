#include <iostream>

#include <string>
#include "enemy.h"
#include <cstdlib>
#include <time.h>

using std::cout;

int main() {

    Enemy *bully;
    Enemy goblin("Goblin");
    Enemy ghost("Ghost", 5, 3, 1);
    Enemy robot("Robot", 15, 10, 5, true);

    // Dando diversas armas para o goblin
    goblin.catchWeapon("Espada");
    goblin.catchWeapon("Arco");
    goblin.catchWeapon("Machado");
    goblin.catchWeapon("Bombas");
    goblin.catchWeapon("Foice");

    // Aqui ele encheu os bolsos
    goblin.catchWeapon("Bastão");

    bully = &robot;
    bully->fightWith(goblin);

    ghost.say("HAHAHA");
    
    return 0;
}
