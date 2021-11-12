#ifndef __TERAWEAPON_HPP__
#define __TERAWEAPON_HPP__

#include <iostream>
#include "Weapon.hpp" 
using namespace std;

class TeraWeapon : public Weapon
{
  public:
    TeraWeapon()
    {
      sell_price = 240;
      name = "TeraWeapon";
      description = "Legendary weapon infused with a terabyte of code. The pinnacle of weapons that code can make. Trust me we tried to make a better weapon, but we don't have the storage for it...";
      attack = 25;
    }
    
};

#endif
