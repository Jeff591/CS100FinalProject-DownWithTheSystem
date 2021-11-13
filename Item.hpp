#ifndef __ITEM_HPP__
#define __ITEM_HPP__

#include <iostream>
using namespace std;

class Item 
{
  protected:
    int sell_price;
    string name;
    string description;
  private:
    
    virtual void check_stats() = 0;
};

#endif
