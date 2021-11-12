#ifndef __GIGAWEAPON_HPP__
#define __GIGAWEAPON_HPP__

#include <iostream>
#include "Weapon.hpp" 
using namespace std;

class GigaWeapon : public Weapon
{
  public:
    GigaWeapon()
    {
      sell_price = 120;
      name = "GigaWeapon";
      description = "Weapon made of a gigabyte of code. This giga-hurts, well for the victim on the sharp side anyways.";
      attack = 20;
    }
    
};

#endif
