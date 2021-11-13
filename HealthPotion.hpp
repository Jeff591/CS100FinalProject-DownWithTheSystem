#ifndef __HEALTHPOTION_HPP__
#define __HEALTHPOTION_HPP__

#include <iostream>
#include "Potion.hpp"
using namespace std;

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
    }
    
};

#endif
