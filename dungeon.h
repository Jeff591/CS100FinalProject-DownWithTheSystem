#ifndef __DUNGEON_H__
#define __DUNGEON_H__

#include <vector>
#include "enemy.hpp"

class Dungeon : public Enemy {
    private:
        std::vector<Enemy*> encounters;
    public:
        Dungeon(std::vector<Enemy*> enemies);
        ~Dungeon();
        std::vector<Enemy*> get_enemies();
};

#endif
