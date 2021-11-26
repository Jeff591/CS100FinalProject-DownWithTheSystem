#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "character.hpp"
#include "player.hpp"
#include <iostream>

using namespace std;

class Enemy : public Character {
    public:
        Enemy() {};
        virtual ~Enemy() {};

        int attack(Character* opponent);

        void set_health(int damage);
};

class Bug : public Enemy {
    public:
        Bug(){
            this->name = "Bug";
            this->power = 8;
            this->defense = 2;
            this->health = 15;
            this->speed = 2;
        };

        int attack(Character* opponent) {
            std::cout << "Bug attacks you and deals " << Enemy::attack(opponent) << std::endl;
            return Enemy::attack(opponent);
        }
};

class Worm : public Enemy {
    public:
        Worm()  {
            this->name = "Worm";
            this->power = 8;
            this->defense = 3;
            this->health = 15;
            this->speed = 4;
        };

        int attack(Character* opponent) {
            std::cout << "Worm attacks you and deals " << Enemy::attack(opponent) << std::endl;
            return Enemy::attack(opponent);
        }
};

class PopUpAd : public Enemy {
    public:
        PopUpAd()  {
            this->name = "Pop-up Ad";
            this->power = 9;
            this->defense = 4;
            this->health = 20;
            this->speed = 3;
        };

        int attack(Character* opponent) {
            std::cout << "Pop-up Ad attacks you and deals " << Enemy::attack(opponent) << std::endl;
            return Enemy::attack(opponent);
        }
};

class Spyware : public Enemy {
    public:
        Spyware()  {
            this->name = "Spyware";
            this->power = 9;
            this->defense = 4;
            this->health = 15;
            this->speed = 6;
        };

        int attack(Character* opponent) {
            std::cout << "Spyware attacks you and deals " << Enemy::attack(opponent) << std::endl;
            return Enemy::attack(opponent);
        }
};

class Virus : public Enemy {
    public:
        Virus()  {
            this->name = "Virus";
            this->power = 9;
            this->defense = 6;
            this->health = 15;
            this->speed = 4;
        };

        int attack(Character* opponent) {
            std::cout << "Virus attacks you and deals " << Enemy::attack(opponent) << std::endl;
            return Enemy::attack(opponent);
        }
};

class TrojanHorse : public Enemy {
    public:
        TrojanHorse()  {
            this->name = "Trojan Horse";
            this->power = 10;
            this->defense = 6;
            this->health = 20;
            this->speed = 6;
        };

        int attack(Character* opponent) {
            std::cout << "Trojan Horse attacks you and deals " << Enemy::attack(opponent) << std::endl;
            return Enemy::attack(opponent);
        }
};

class CorruptedMotherboard : public Enemy {
    public:
        CorruptedMotherboard()  {
            this->name = "Corrupted Motherboard";
            this->power = 14;
            this->defense = 9;
            this->health = 30;
            this->speed = 6;
        };
        
        int attack(Character* opponent) {
            std::cout << "Corrupted Motherboard attacks you and deals " << Enemy::attack(opponent) << std::endl;
            return Enemy::attack(opponent);
        }
};

#endif
