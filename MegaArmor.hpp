#ifndef __MEGAARMOR_HPP__
#define __MEGAARMOR_HPP__

#include <iostream>
#include "Armor.hpp"
using namespace std;

class MegaArmor : public Armor
{
  public:
    MegaArmor()
    {
      sell_price = 60;
      name = "MegaArmor";
      description = "Armor made of a megabyte of code. Being able to shoot and change weapons like MegaMan not included";
      defense = 15;
    }
    
};

#endif
