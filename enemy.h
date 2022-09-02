#ifndef ENEMY_H
#define ENEMY_H

#include <string>


class Enemy {
    private:
        std::string name;
        int healthPoints;
        int defensePoints;
    
    public:
        Enemy(std::string name, int healthPoints, int defensePoints);
        ~Enemy();

        void printStatus();
        void decreaseHP(int);
};

#endif