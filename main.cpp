#include <iostream>

#include <string>
#include "enemy.h"

using std::cout;

int main() {


    // This enemy is not supposed to be defeated
    const Enemy BOSS("Goblin God", 150, 200, true);

    Enemy redGoblin("Goblin Vermelho", 12, 3);
    Enemy blueGoblin("Globin Azul", 15, 5);
    Enemy superGoblin("Super Goblin", 100, 100, true);

    redGoblin.say("Carne!");
    blueGoblin.say("Carne humana!");
    superGoblin.say("Atacar!");

    superGoblin.tauntPlayer();
    std::cout << "Todos eles atacam! Mas o líder morre!\n";

    superGoblin.decreaseHP(100);
    superGoblin.printStatus();
    superGoblin.~Enemy();   // Só um placeholder

    // Blue goblin se definiu como lider!
    blueGoblin.defineLeader(blueGoblin);
    std::cout << "O Goblin azul se define como lider! Mas morre!\n";
    // Blue goblin is defeated
    blueGoblin.decreaseHP(15);
    blueGoblin.printStatus();
    blueGoblin.~Enemy();

    Enemy::defineLeader(redGoblin);
    redGoblin.tauntPlayer();

    redGoblin.decreaseHP(12);
    redGoblin.printStatus();
    
    redGoblin.~Enemy();
    std::cout << "Todos eles morreram, mas porque a luta continua?\n";
    std::cout << "O contador diz que tem " << Enemy::getNumEnemiesInArea() << " inimigos na area.\n";

    BOSS.printStatus();

    std::cout << "Ele é constante! Não pode ser derrotado.\n";

    return 0;
}