#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <string>
#include "character.hpp"

using namespace std;

class Player : public Character
{
  protected:

  public:

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
