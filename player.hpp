#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <string>
#include "character.hpp"

using namespace std;

class Player : public Character
{
  private:

  public:
    Player(string chosen)
    {
      if (chosen == "Defender")
      {
        health = 25;
        power = 5;
        defence = 7;
        speed = 3;
      }
      else if (chosen == "Cleaner")
      {
        health = 25;
        power = 8;
        defence = 3;
        speed = 7;
      }
      else
      {
        health = 35;
        power = 5;
        defence = 5;
        speed = 5;
      }
    }

    ~Player();

    void attack(Character* opponent)
    {
      int damageDealt = this->get_power() - opponent->get_defence();
      if (damageDealt < 0)
      {
        damageDealt = 0;
      }
      //opponent->set_health(damageDealt);
    }
};


#endif
