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
    ~Armor()
    {
      delete this;
    }
    int get_sell_price(){return sell_price;} 
    string get_armor_name(){return name;} 
    string get_armor_description(){return description;} 
    int get_defense(){return defense;} 
    
    virtual void check_stats() { cout << "Armor: " << name << " Defense: " << defense << " Sell price: " << sell_price << endl << description << endl; return; };
    
};

class ByteArmor : public Armor
{
  public:
    ByteArmor()
    {
      sell_price = 15;
      name = "ByteArmor";
      description = "Armor made of a byte of code. Probably too thin to be proper armor but its better than nothing!";
      defense = 5;
    }
    
};

class KiloArmor : public Armor
{
  public:
    KiloArmor()
    {
      sell_price = 30;
      name = "KiloArmor";
      description = "Armor made of a kilobyte of code. This weighs a kilo! You'll definitely gain strength carrying this!";
      defense = 10;
    }

};

class MegaArmor : public Armor
{
  public:
    MegaArmor()
    {
      sell_price = 60;
      name = "MegaArmor";
      description = "Armor made of a megabyte of code. Being able to shoot and change weapons like MegaMan not included";
      defense = 15;
    }

};

class GigaArmor : public Armor
{
  public:
    GigaArmor()
    {
      sell_price = 120;
      name = "GigaArmor";
      description = "Armor made of a gigabyte of code. Might give giga defense physically, but it'll be a giga dent on your money";
      defense = 20;
    }
      
};

class TeraArmor : public Armor
{
  public:
    TeraArmor()
    {
      sell_price = 240;
      name = "TeraArmor";
      description = "Legendary armor made of a terabyte of code. The best of the best armor around the interface, but as it is the best, only a few exist due to the immense work for its creation.";
      defense = 25;
    }
   
};

#endif
