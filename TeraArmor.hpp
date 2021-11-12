#ifndef __TERAARMOR_HPP__
#define __TERAARMOR_HPP__

#include <iostream>
#include "Armor.hpp"
using namespace std;

class TeraArmor : public Armor
{
  public:
    TeraArmor()
    {
      sell_price = 240;
      name = "TeraArmor";
      description = "Legendary armor made of a terabyte of code. The best of the best armor around the interface, but as it is the best, only a few exist due to the immense work for its creation.";
      defense = 25;
    }
    
};

#endif
