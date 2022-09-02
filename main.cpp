#include <iostream>

#include "enemy.h"


int main() {

    Enemy hogoblin("Hogoblin", 15, 20);
    Enemy bokoblin("Bokoblin", 30, 15);

    hogoblin.printStatus();
    hogoblin.decreaseHP(5);
    hogoblin.printStatus();

    bokoblin.printStatus();
    bokoblin.decreaseHP(10);
    bokoblin.printStatus();

    return 0;
}