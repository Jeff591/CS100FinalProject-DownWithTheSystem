#ifndef __KILOWEAPON_HPP__
#define __KILOWEAPON_HPP__

#include <iostream>
#include "Weapon.hpp" 
using namespace std;

class KiloWeapon : public Weapon
{
  public:
    KiloWeapon()
    {
      sell_price = 30;
      name = "KiloWeapon";
      description = "Weapon made of a kilobyte of code. This'll definitely make enemies shed a kilo!";
      attack = 10;
    }
    
};

#endif
