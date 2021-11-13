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
      int damageDealt = this->get_power() - opponent->get_defense();
      if (damageDealt < 0)
      {
        damageDealt = 0;
      }
      //opponent->set_health(damageDealt);
    }
};

class Defender : public Player
{
  public:
    Defender()
    {
      health = 25;
      power = 5;
      defense = 7;
      speed = 3;
    }

    ~Defender();
};

class Cleaner : public Player
{
  public:
    Cleaner()
    {
      health = 25;
      power = 8;
      defense = 3;
      speed = 7;
    }

    ~Cleaner();
};

class Firewall : public Player
{
  public:
    Firewall()
    {
      health = 35;
      power = 5;
      defense = 5;
      speed = 5;
    }

    ~Firewall();
};
#endif
