#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <string>
#include "character.hpp"
#include "Item.hpp"
#include "Weapon.hpp"
#include "Armor.hpp"
#include "Potion.hpp"
#include "skillset.hpp"
#include <vector>

using namespace std;

class Player : public Character
{
  protected:
    vector<vector<Item*>> inventory;
    Weapon* currentWeapon = nullptr;
    Armor* currentArmor = nullptr;
    SkillSet* mainSkill = nullptr;
    SkillSet* comboSkill = nullptr;
    int money = 0;

  public:

    Player(){};
    ~Player()
    {
      delete mainSkill;
      delete comboSkill;
      delete currentArmor;
      delete currentWeapon;
      for (unsigned int i = 0; i < inventory.size(); i++)
      {
        for(unsigned int j = 0; j < inventory.at(i).size(); j++)
        {
          delete inventory.at(i).at(j);
        }
      }
    }

    int attack(Character* opponent)
    {
      int damageDealt;
      if(currentWeapon != nullptr)
      {
        damageDealt = this->get_power() + this->currentWeapon->get_attack() - opponent->get_defense();
      }
      else
      {
        damageDealt = this->get_power() - opponent->get_defense();
      }
      if (damageDealt < 0)
      {
        damageDealt = 0;
      }
      return damageDealt;
    }
    
    SkillSet* get_skill1()
    {
      return mainSkill;
    }    

    SkillSet* get_skill2()
    {
      return comboSkill;
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
    
    int set_money(int amount)
    {
      money += amount;
    }

    int get_money()
    {
      return money;
    }

    vector<vector<Item*>> get_inventory() 
    {
      return inventory;
    }

    Armor* get_current_armor()
    {
      return currentArmor;
    }

    Weapon* get_current_weapon()
    {
      return currentWeapon;
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
      name = "Defender";
      mainSkill = new ShieldBash();
      comboSkill = new ComboSkill(new ShieldBash(), new Rebuild());
    }
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
      name = "Cleaner";
      mainSkill = new CleanSweep();
      comboSkill = new ComboSkill(new CleanSweep(), new ShieldBash());
    }

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
      name = "Firewall";
      mainSkill = new Rebuild();
      comboSkill = new ComboSkill(new Rebuild(), new CleanSweep());
    }

};
#endif
