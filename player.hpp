#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <string>
#include "character.hpp"
#include "Item.hpp"
#include "Weapon.hpp"
#include "Armor.hpp"
#include "Potion.hpp"
#include <vector>

using namespace std;

class Player : public Character
{
  protected:
    vector<vector<Item*>> inventory;
    Weapon* currentWeapon = nullptr;
    Armor* currentArmor = nullptr;

  public:

    ~Player();

    void attack(Character* opponent)
    {
      int damageDealt = this->get_power() - opponent->get_defense();
      if (damageDealt < 0)
      {
        damageDealt = 0;
      }
      //opponent->set_health(damageDealt);
    }

    void check_stats() {
      cout << "-------------------------------------------------------" << endl;
      cout << "Player stats: " << endl;
      cout << "Health: " << this->get_health() << endl;
      cout << "Power: " << this->get_power() << endl;
      cout << "Defense: " << this->get_defense() << endl;
      cout << "Speed: " << this->get_defense() << endl;
      cout << "-------------------------------------------------------" << endl;
      cout << "Item stats: " << endl;
      if(this->currentWeapon != nullptr) this->currentWeapon->check_stats();
      if(this->currentArmor != nullptr) this->currentArmor->check_stats();
      for(unsigned i = 0; i < this->inventory.at(2).size(); i++) {
        this->inventory.at(2).at(i)->check_stats();
      }
      cout << "-------------------------------------------------------" << endl;
    }
};

class Defender : public Player
{
  public:
    Defender()
    {
      health = 25;
      power = 5;
      defense = 7;
      speed = 3;
    }

    ~Defender();
};

class Cleaner : public Player
{
  public:
    Cleaner()
    {
      health = 25;
      power = 8;
      defense = 3;
      speed = 7;
    }

    ~Cleaner();
};

class Firewall : public Player
{
  public:
    Firewall()
    {
      health = 35;
      power = 5;
      defense = 5;
      speed = 5;
    }

    ~Firewall();
};
#endif
