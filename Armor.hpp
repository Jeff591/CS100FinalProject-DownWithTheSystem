#ifndef __ARMOR_HPP__
#define __ARMOR_HPP__

#include <iostream>
#include "Item.hpp"
using namespace std;

class Armor : public Item
{
  protected:
    int defense;
  public:
    Armor(){}
    int get_sell_price(){return sell_price;} 
    string get_armor_name(){return name;} 
    string get_armor_description(){return description;} 
    int get_defense(){return defense;} 
    
    virtual void check_stats() { cout << "Armor: " << name << " Defense: " << defense << " Sell price: " << sell_price << endl << description << endl; return; };
    
};

#endif
