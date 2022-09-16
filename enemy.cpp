#include <iostream>
#include "enemy.h"

// Trying to use Member List Initialization
// Is it really necessary? It's not recommended, use the version below
// Enemy::Enemy(std::string name, int healthPoints, int defensePoints) 
// : name(name), healthPoints(healthPoints), defensePoints(defensePoints) {
// }

Enemy::Enemy() {
    this->setName("Void enemy");
    this->setHP(10);
    this->setDefensePoints(10);
}

Enemy::Enemy(std::string name, int healthPoints = 10, int defensePoints = 10) {
    this->setName(name);
    this->setHP(healthPoints);
    this->setDefensePoints(defensePoints);
}

Enemy::Enemy(const Enemy &otherEnemy) {
    this->setName( otherEnemy.name );
    this->setHP ( otherEnemy.healthPoints );
    this->setDefensePoints( otherEnemy.defensePoints);
}

Enemy::~Enemy() {
    std::cout << "Destroying something right here...\n";
}

// Print all enemy status
void Enemy::printStatus() const {
    std::cout << "===============================\n";
    std::cout << "Enemy: " << this->name << "\n";
    std::cout << "Health Points: " << this->healthPoints << "\n";
    std::cout << "Defense Points: " << this->defensePoints << "\n"; 
}

// When enemy takes damage
void Enemy::decreaseHP(int damage) {
    this->healthPoints -= damage;
}

void Enemy::setName(string name) {
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

