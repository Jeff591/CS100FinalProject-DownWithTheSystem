#ifndef __POTION_HPP__
#define __POTION_HPP__

#include <iostream>
#include "Item.hpp"
using namespace std;

class Potion : public Item
{
  protected:
    int alter;
    string type;
  public:
    Potion(){}
    int get_sell_price(){return sell_price;} 
    string get_potion_name(){return name;} 
    string get_potion_description(){return description;} 
    int get_alter(){return alter;} 
    string get_type(){return type;} 
    virtual void check_stats() { cout << "Potion: " << name << " Type: " << type << " Amount: " << alter << " Sell price: " << sell_price << endl << description << endl;  return; };
    
};

#endif
