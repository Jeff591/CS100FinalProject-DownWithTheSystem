#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "character.hpp"

class Enemy : public Character {
    protected:
        std::string name;
    public:
        Enemy() {};
        ~Enemy() {};
        Enemy(int h, int p, int s);

        int attack(Character* opponent);

        std::string get_name();

        void set_health(int damage);
};

class Bug : public Enemy {
    public:
        Bug(int h, int p, int s) : Enemy(h, p, s) {
            this->name = "Bug";
        };

        int attack(Character* opponent) {
            std::cout << "Bug attacks you" << std::endl;
            return Enemy::attack(opponent);
        }
};

class Worm : public Enemy {
    public:
        Worm(int h, int p, int s) : Enemy(h, p, s) {
            this->name = "Worm";
        };

        int attack(Character* opponent) {
            std::cout << "Worm attacks you" << std::endl;
            return Enemy::attack(opponent);
        }
};

class PopUpAd : public Enemy {
    public:
        PopUpAd(int h, int p, int s) : Enemy(h, p, s) {
            this->name = "Pop-up Ad";
        };

        int attack(Character* opponent) {
            std::cout << "Pop-up Ad attacks you" << std::endl;
            return Enemy::attack(opponent);
        }
};

class Spyware : public Enemy {
    public:
        Spyware(int h, int p, int s) : Enemy(h, p, s) {
            this->name = "Spyware";
        };

        int attack(Character* opponent) {
            std::cout << "Spyware attacks you" << std::endl;
            return Enemy::attack(opponent);
        }
};

class Virus : public Enemy {
    public:
        Virus(int h, int p, int s) : Enemy(h, p, s) {
            this->name = "Virus";
        };

        int attack(Character* opponent) {
            std::cout << "Virus attacks you" << std::endl;
            return Enemy::attack(opponent);
        }
};

class TrojanHorse : public Enemy {
    public:
        TrojanHorse(int h, int p, int s) : Enemy(h, p, s) {
            this->name = "Trojan Horse";
        };

        int attack(Character* opponent) {
            std::cout << "Trojan Horse attacks you" << std::endl;
            return Enemy::attack(opponent);
        }
};

class CorruptedMotherboard : public Enemy {
    public:
        CorruptedMotherboard(int h, int p, int s) : Enemy(h, p, s) {
            this->name = "Corrupted Motherboard";
        };
        
        int attack(Character* opponent) {
            std::cout << "Corrupted Motherboard attacks you" << std::endl;
            return Enemy::attack(opponent);
        }
};

#endif
