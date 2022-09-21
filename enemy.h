#ifndef ENEMY_H
#define ENEMY_H

#include <string>

using std::string;

class Enemy {
    public:
        Enemy();
        Enemy(string, int = 10, int = 10);
        Enemy(const Enemy &);
        ~Enemy();

        void printStatus() const;
        bool tauntPlayer() const;
        bool isHurt() const;
        void decreaseHP(int);

        string getName() const { return this->name; }
        int getHP() const { return this->healthPoints; }
        int getDefensePoints() const { return this->defensePoints; }
        int getMaxHP() const { return MAX_HEALTH_POINTS; }
        int getMaxDefensePoints() const { return MAX_DEFENSE_POINTS; }

        void setName(string);
        void setHP(int);
        void setDefensePoints(int);

    private:
        const int MAX_HEALTH_POINTS = 150;
        const int MAX_DEFENSE_POINTS = 200;
        std::string name;
        int healthPoints;
        int defensePoints;
};

#endif
