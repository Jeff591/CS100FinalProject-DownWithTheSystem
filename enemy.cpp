#include "enemy.h"

Enemy::Enemy(int h, int p, int s) {
    this->health = h;
    this->power = p;
    this->defense = 0;
    this->speed = s;
}

int Enemy::attack(Character* opponent) {
    int damageDealt = this->get_power() - opponent->get_defense();

    if(damageDealt < 0) {
        damageDealt = 0;
    }

    return damageDealt;
}

std::string Enemy::get_name() {
    return this->name;
}

void Enemy::set_health(int damage) {
    this->health -= damage;
}