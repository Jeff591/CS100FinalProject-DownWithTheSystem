#ifndef __TOWN__HPP__
#define __TOWN_HPP__

#include <iostream>
#include "Armor.hpp"
#include "HealthPotion.hpp"
#include "Potion.hpp"
#include "Weapon.hpp"
#include "player.hpp"
using namespace std;
/*
 * Town class: This like the dungeon class
 * are two destinations the player class can travel to
 * and includes connections to the player class as it will modify the vector of vector items
 * that the player has to add or take away items from the player,
 * as well as modify the integer money the player has 
 * through increasing money if selling an item or subtracting money if 
 * buying an item.
 * */
class Town
{
    private:

    public:

    void buy();
    void sell();

    Town();
   virtual  ~Town();

};
#endif
