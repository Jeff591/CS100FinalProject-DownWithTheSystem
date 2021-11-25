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
    string itemType;
  public:
    Potion(){}
    int get_sell_price(){return sell_price;} 
    string get_potion_name(){return name;} 
    string get_potion_description(){return description;} 
    int get_alter(){return alter;} 
    string get_type(){return type;} 
    virtual void check_stats() { cout << "Potion: " << name << " Type: " << type << " Amount: " << alter << " Sell price: " << sell_price << endl << description << endl;  return; };
    
};

class HealthPotion : public Potion
{
  public:
    HealthPotion()
    {
      sell_price = 5;
      name = "HealthPotion";
      description = "A nice drink filled to the brim with dihydrogen monoxide or as you people call it, water. It'll replenish you well.";
      type = "Health";
      alter = 15;
      itemType = "Potion";
    }
    
};

#endif
