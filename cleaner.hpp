#ifndef CLEANER_HPP
#define CLEANER_HPP

#include <iostream>
#include <string>
#include "player.hpp"

using namespace std;

class Cleaner : public Player
{
  public:
    Cleaner()
    {
      health = 25;
      power = 8;
      defence = 3;
      speed = 7;
    }

    ~Cleaner();
};
#endif
