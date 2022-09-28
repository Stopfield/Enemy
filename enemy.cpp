#include <iostream>
#include <time.h>
#include <cstdlib>
#include "enemy.h"

// Trying to use Member List Initialization
// Is it really necessary? It's not recommended, use the version below
// Enemy::Enemy(std::string name, int healthPoints, int defensePoints) 
// : name(name), healthPoints(healthPoints), defensePoints(defensePoints) {
// }

int Enemy::numEnemies = 0;
const string Enemy::ENEMY_TYPE = "Generic Enemy";
const string Enemy::BODY_PARTS[3] = {"Head", "Body", "Feet"};

Enemy::Enemy() {
    this->setName("Void enemy");
    this->setHP(10);
    this->setDefensePoints(10);
    this->setAttackPoints(3);
    this->isLeader = false;
    srand(time(0));
    Enemy::numEnemies++;
}

Enemy::Enemy(const std::string &name, int healthPoints, int defensePoints, int attackPoints, bool leader) {
    this->setName(name);
    this->setHP(healthPoints);
    this->setDefensePoints(defensePoints);
    this->setAttackPoints(attackPoints);
    this->isLeader = leader;
    srand(time(0));
    Enemy::numEnemies++;
}

Enemy::Enemy(const Enemy &otherEnemy) {
    this->setName( otherEnemy.name );
    this->setHP ( otherEnemy.healthPoints );
    this->setDefensePoints( otherEnemy.defensePoints );
    this->setAttackPoints( otherEnemy.attackPoints );
    this->isLeader = otherEnemy.isLeader;
    srand(time(0));
    Enemy::numEnemies++;
}

Enemy::~Enemy() {
    std::cout << "Destroying " << this->name <<" from memory\n";
    Enemy::numEnemies--;
}

// Aqui, o melhor uso seria vector
void Enemy::catchWeapon(string weapon) {
    // Verify which position is empty and store it there
    for (int i = 0; i < 5; i++) {
        if (this->weapons[i] == "") {
            this->weapons[i] = weapon;
            std::cout << this->name << " catches " << weapon << "!\n";
            return;
        }
    }
    std::cout << this->name << "'s pockets are full! He leaves " << weapon << "!\n";
}

void Enemy::attack(Enemy &otherEnemy) {
    int randomNumber = rand() % 3;
    if (otherEnemy.healthPoints <= 0) {
        std::cout << otherEnemy.name << " is already dead.\n";
        return;
    }
    std::cout << this->name << " attacks " << otherEnemy.name << " in the " << otherEnemy.BODY_PARTS[randomNumber] << " by " << this->attackPoints << " HP!\n";
    otherEnemy.decreaseHP(this->attackPoints);
}

void Enemy::fightWith(Enemy &otherEnemy) {
    while ((this->healthPoints > 0) && (otherEnemy.healthPoints > 0)) {
        this->attack(otherEnemy);   // This enemy attacks another
        otherEnemy.attack(*this);   // The other enemy attacks this one
    }
    string winner = this->healthPoints > otherEnemy.healthPoints ? this->name : otherEnemy.name ;
    std::cout << "The winner is " << winner << "!\n";
}

// Print all enemy status
void Enemy::printStatus() const {
    std::cout << "===============================\n";
    std::cout << "Enemy: " << this->name << "\n";
    std::cout << "Health Points: " << this->healthPoints << "\n";
    std::cout << "Defense Points: " << this->defensePoints << "\n"; 
    std::cout << "Attack Points: " << this->attackPoints << "\n"; 
    std::cout << "===============================\n";
}

void Enemy::say(const string &phrase) const {
    std::cout << this->name << " says: " << phrase << "\n";
}

void Enemy::defineLeader(Enemy &enemy) {
    enemy.isLeader = true;
}

// When enemy takes damage
void Enemy::decreaseHP(int damage) {
    this->healthPoints -= damage;
}

// Is the enemy hurt?
bool Enemy::isHurt() const {
    return this->healthPoints < 5 ? true : false;
}

// The enemy uses his strength to scare the player!
// If the enemy's defense points are the 10th part of its maximum, he succeeds!
bool Enemy::tauntPlayer() const {
    std::cout << this->name << " taunts the player using his strength!\n";
    if (this->defensePoints > (this->MAX_DEFENSE_POINTS / 10) && this->isLeader ) {
        std::cout << "It's a sucess! The player feels scared!\n";
        return true;
    }
    std::cout << "It fails! The player feels awkward!\n";
    return false;
}

void Enemy::setName(const string &name) {
    if (name.length() > 30) {
        std::cout << "The name is too big!\n";
        this->name = name.substr(0, 30);
        return;
    }
    this->name = name;
}

void Enemy::setHP(int healthPoints) {
    if ((healthPoints < 0) && (healthPoints > MAX_HEALTH_POINTS) ){
        std::cout << "HP invalid!\n";
        return;
    }
    this->healthPoints = healthPoints;
}

void Enemy::setDefensePoints(int defensePoints) {
    if ((defensePoints < 0) && (defensePoints > this->MAX_DEFENSE_POINTS)) {
        std::cout << "Defense points invalid!\n";
        return;
    }
    this->defensePoints = defensePoints;
}

void Enemy::setAttackPoints(int attackPoints) {
    if (attackPoints < 0) {
        this->attackPoints = 1;
        return;
    }
    this->attackPoints = attackPoints;
}

