#ifndef FIREWALL_HPP
#define FIREWALL_HPP

#include <iostream>
#include <string>
#include "player.hpp"

using namespace std;

class Firewall : public Player
{
  public:
    Firewall()
    {
      health = 35;
      power = 5;
      defence = 5;
      speed = 5;
    }

    ~Firewall();
};
#endif
