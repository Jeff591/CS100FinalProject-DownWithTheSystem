#ifndef __ITEM_HPP__
#define __ITEM_HPP__

#include <iostream>
using namespace std;

class Item 
{
  protected:
    int sell_price;
    string itemType;
    string name;
    string description;
  public:

    string get_name() {
      return this->name;
    }

    string get_item_type() {
      return this->itemType;
    }
    
    virtual void check_stats() = 0;
    virtual int get_sell_price() = 0;
    
};

#endif
