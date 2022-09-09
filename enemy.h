#ifndef ENEMY_H
#define ENEMY_H

#include <string>


class Enemy {
    public:
        Enemy(std::string name, int healthPoints, int defensePoints);
        ~Enemy();

        void printStatus();
        void decreaseHP(int);

    private:
        std::string name;
        int healthPoints;
        int defensePoints;
};

#endif
