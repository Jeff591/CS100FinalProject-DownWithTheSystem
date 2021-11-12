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

#endif
