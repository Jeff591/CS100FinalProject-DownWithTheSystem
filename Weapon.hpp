#ifndef __WEAPON_HPP__
#define __WEAPON_HPP__

#include <iostream>
#include "Item.hpp"
using namespace std;

class Weapon : public Item
{
  protected:
    int attack;
  public:
    Weapon(){}
    int get_sell_price(){return sell_price;} 
    string get_weapon_name(){return name;} 
    string get_weapon_description(){return description;} 
    int get_attack(){return attack;} 
    
    virtual void check_stats() { cout << "Weapon: " << name << " Attack: " << attack << " Sell price: " << sell_price << endl << description << endl; return; };
    
};

class ByteWeapon : public Weapon
{
  public:
    ByteWeapon()
    {
      sell_price = 15;
      name = "ByteWeapon";
      description = "Weapon made of a byte of code. It may be a simple weapon, but it does byte!";
      attack = 5;
      itemType = "Weapon";
    }
    
};

class KiloWeapon : public Weapon
{
  public:
    KiloWeapon()
    {
      sell_price = 30;
      name = "KiloWeapon";
      description = "Weapon made of a kilobyte of code. This'll definitely make enemies shed a kilo!";
      attack = 10;
      itemType = "Weapon";
    }
    
};

class MegaWeapon : public Weapon
{
  public:
    MegaWeapon()
    {
      sell_price = 60;
      name = "MegaWeapon";
      description = "Weapon made of a megabyte of code. It has a mega personality to go along with its mega size";
      attack = 15;
      itemType = "Weapon";
    }
    
};

class GigaWeapon : public Weapon
{
  public:
    GigaWeapon()
    {
      sell_price = 120;
      name = "GigaWeapon";
      description = "Weapon made of a gigabyte of code. This giga-hurts, well for the victim on the sharp side anyways.";
      attack = 20;
      itemType = "Weapon";
    }
    
};

class TeraWeapon : public Weapon
{
  public:
    TeraWeapon()
    {
      sell_price = 240;
      name = "TeraWeapon";
      description = "Legendary weapon infused with a terabyte of code. The pinnacle of weapons that code can make. Trust me we tried to make a better weapon, but we don't have the storage for it...";
      attack = 25;
      itemType = "Weapon";
    }
    
};

#endif
