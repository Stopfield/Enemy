#ifndef ENEMY_H
#define ENEMY_H

#include <string>

using std::string;

// TODO: Ponteiro com alocação dinâmica -> Arma equipada 
//       Outro ponteiro -> O seu líder
// TODO: Similar ao alocarHist -> Inventário das armas (vai aumentando o tamanho)
// TODO: Vector de ponteiros -> Outros inimigos subordinados
// TODO: Map -> Ataques e danos

// DÚVIDA: Como funciona o const no C++?

class Enemy {
    public:
        Enemy();
        Enemy(const string &, int = 10, int = 10, int = 3, bool = false);
        Enemy(const Enemy &);
        ~Enemy();

        void printStatus() const;
        bool tauntPlayer() const;
        bool isHurt() const;
        bool isALeader() const { return this->isLeader; }
        void say(const string &) const;
        void decreaseHP(int);
        static void defineLeader(Enemy &);
        void catchWeapon(const string &);
        void attack(Enemy &);
        void fightWith(Enemy &);
        void equipWeapon(int);

        string getName() const { return this->name; }
        int getHP() const { return this->healthPoints; }
        int getDefensePoints() const { return this->defensePoints; }
        int getMaxHP() const { return MAX_HEALTH_POINTS; }
        int getMaxDefensePoints() const { return MAX_DEFENSE_POINTS; }
        string getEnemyType() const { return this->ENEMY_TYPE; }
        static int getNumEnemiesInArea() {return Enemy::numEnemies; }
        //static string* getEnemyBodyParts() { return Enemy::BODY_PARTS; }
        static const string *getBodyParts() { return Enemy::BODY_PARTS; }
        const string *getWeapons() const { return this->weapons; }
        // string *getWeapons() { return this->weapons; }
        int getAttackPoints() const { return this->attackPoints; }
        const string * getEquippedWeapon() const { return this->equippedWeaponPtr; }

        void setName(const string &);
        void setHP(int);
        void setDefensePoints(int);
        void setAttackPoints(int);

    private:
        const int MAX_HEALTH_POINTS = 150;
        const int MAX_DEFENSE_POINTS = 200;
        static const int INITIAL_NUM_WEAPONS = 3;
        static const string BODY_PARTS[3];
        static const string ENEMY_TYPE;
        static int numEnemies;
        std::string name;
        std::string weapons[Enemy::INITIAL_NUM_WEAPONS];
        std::string *equippedWeaponPtr;
        int healthPoints;
        int defensePoints;
        int attackPoints;
        int weaponInventorySize = Enemy::INITIAL_NUM_WEAPONS;
        bool isLeader;
};

#endif
