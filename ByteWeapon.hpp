#ifndef __BYTEWEAPON_HPP__
#define __BYTEWEAPON_HPP__

#include <iostream>
#include "Weapon.hpp" 
using namespace std;

class ByteWeapon : public Weapon
{
  public:
    ByteWeapon()
    {
      sell_price = 15;
      name = "ByteWeapon";
      description = "Weapon made of a byte of code. It may be a simple weapon, but it does byte!";
      attack = 5;
    }
    
};

#endif
