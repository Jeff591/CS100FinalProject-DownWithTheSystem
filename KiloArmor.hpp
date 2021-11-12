#ifndef __KILOARMOR_HPP__
#define __KILOARMOR_HPP__

#include <iostream>
#include "Armor.hpp"
using namespace std;

class KiloArmor : public Armor
{
  public:
    KiloArmor()
    {
      sell_price = 30;
      name = "KiloArmor";
      description = "Armor made of a kilobyte of code. This weighs a kilo! You'll definitely gain strength carrying this!";
      defense = 10;
    }
    
};

#endif
