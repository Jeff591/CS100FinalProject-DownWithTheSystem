#include "enemy.h"

int Enemy::attack(Character* opponent) {
    Player* player = dynamic_cast<Player*>(opponent);
    int damageDealt;
    if(player->get_current_armor() == nullptr)
    {
      damageDealt = this->get_power() - player->get_defense();
    }
    else
    {
      damageDealt = this->get_power() - player->get_defense() - player->get_current_armor()->get_defense();
    }

    if(damageDealt < 0) {
        damageDealt = 0;
    }

    return damageDealt;
}

void Enemy::set_health(int damage) {
    this->health -= damage;
}
