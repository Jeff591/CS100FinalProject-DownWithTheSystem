#include "dungeon.h"

Dungeon::Dungeon(std::vector<Enemy*> enemies) {
    this->encounters = enemies;
}

Dungeon::~Dungeon() {
    for(unsigned i = 0; i < this->encounters.size(); i++) {
        delete this->encounters.at(i);
    }
    delete this;
}

std::vector<Enemy*> Dungeon::get_enemies() {
    return this->encounters;
}