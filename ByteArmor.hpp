#ifndef __BYTEARMOR_HPP__
#define __BYTEARMOR_HPP__

#include <iostream>
#include "Armor.hpp"
using namespace std;

class ByteArmor : public Armor
{
  public:
    ByteArmor()
    {
      sell_price = 15;
      name = "ByteArmor";
      description = "Armor made of a byte of code. Probably too thin to be proper armor but its better than nothing!";
      defense = 5;
    }
    
};

#endif
