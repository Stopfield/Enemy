#include <iostream>
#include "enemy.h"

// Trying to use Member List Initialization
// Is it really necessary?
Enemy::Enemy(std::string name, int healthPoints, int defensePoints) 
: name(name), healthPoints(healthPoints), defensePoints(defensePoints) {
    
}

Enemy::~Enemy() {
    std::cout << "Destroying something right here..." << std::endl;
}

// Print all enemy status
void Enemy::printStatus() {
    std::cout << "===============================" << std::endl;
    std::cout << "Enemy: " << this->name << std::endl;
    std::cout << "Health Points: " << this->healthPoints << std::endl;
    std::cout << "Defense Points: " << this->defensePoints << std::endl; 
}

// When enemy takes damage
void Enemy::decreaseHP(int damage) {
    this->healthPoints -= damage;
}

void Enemy::setName(string name) {
    if (name.length() > 30) {
        std::cout << "The name is too big\n";
        return;
    }
    this->name = name;
}

void Enemy::getName() {
    return this->name;
}