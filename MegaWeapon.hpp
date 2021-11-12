#ifndef __MEGAWEAPON_HPP__
#define __MEGAWEAPON_HPP__

#include <iostream>
#include "Weapon.hpp" 
using namespace std;

class MegaWeapon : public Weapon
{
  public:
    MegaWeapon()
    {
      sell_price = 60;
      name = "MegaWeapon";
      description = "Weapon made of a megabyte of code. It has a mega personality to go along with its mega size";
      attack = 15;
    }
    
};

#endif
