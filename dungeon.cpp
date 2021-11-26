#include "dungeon.h"

Dungeon::~Dungeon() {
    for(unsigned i = 0; i < this->encounters.size(); i++) {
        delete this->encounters.at(i);
    }
}

std::vector<Enemy*>* Dungeon::get_enemies() {
    return &encounters;
}
