#ifndef DEFENDER_HPP
#define DEFENDER_HPP

#include <iostream>
#include <string>
#include "player.hpp"

using namespace std;

class Defender : public Player
{
  public:
    Defender()
    {
      health = 25;
      power = 5;
      defence = 7;
      speed = 3;
    }

    ~Defender();
};


#endif
