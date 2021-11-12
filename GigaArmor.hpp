#ifndef __GIGAARMOR_HPP__
#define __GIGAARMOR_HPP__

#include <iostream>
#include "Armor.hpp"
using namespace std;

class GigaArmor : public Armor
{
  public:
    GigaArmor()
    {
      sell_price = 120;
      name = "GigaArmor";
      description = "Armor made of a gigabyte of code. Might give giga defense physically, but it'll be a giga dent on your money";
      defense = 20;
    }
    
};

#endif
