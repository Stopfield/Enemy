#include <iostream>

#include <string>
#include "enemy.h"
#include <cstdlib>
#include <time.h>

using std::cout;

int main() {
    
    const int numEnemies = 3;
    const string newName = "Goblin ";
    string *name;

    // Alocação de memória de um array
    Enemy *inimigos = new Enemy[numEnemies];

    // Altera e imprime os nomes dos inimigos no array
    for (int i = 0; i < numEnemies; i++) {
        inimigos[i].setName(newName + std::to_string(i));
        std::cout << inimigos[i].getName() << "\n";
    }

    name = new std::string(inimigos[1].getName());

    std::cout << "*name = "<< *name << "\n";

    delete name;
    delete [] inimigos;
    name = 0;
    inimigos = 0;
    
    return 0;
}
