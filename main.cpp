#include <iostream>

#include "enemy.h"


int main() {

    Enemy hogoblin("Hogoblin", 15, 20);
    hogoblin.printStatus();
    hogoblin.decreaseHP(5);
    hogoblin.printStatus();

    return 0;
}