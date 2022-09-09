#ifndef ENEMY_H
#define ENEMY_H

#include <string>

using std::string;

class Enemy {
    public:
        Enemy(string, int, int);
        ~Enemy();

        void printStatus();
        void decreaseHP(int);

    private:
        std::string name;
        int healthPoints;
        int defensePoints;
};

#endif
