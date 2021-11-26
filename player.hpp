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
#include <algorithm>

using namespace std;

class Player : public Character
{
protected:
    // 0: Weapon, 1: Armor, 2: Potion
    // Equipped item will be in index 0 for each vector
    vector<vector<Item *>> inventory = vector<vector<Item *>>(3, vector<Item *>());
    int money = 0;
    Weapon *currentWeapon = nullptr;
    Armor *currentArmor = nullptr;
    SkillSet *mainSkill = nullptr;
    SkillSet *comboSkill = nullptr;

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
    
    void check_stats()
    {
        cout << "-------------------------------------------------------" << endl;
        cout << "Player stats: " << endl;
        cout << "Health: " << this->get_health() << endl;
        cout << "Power: " << this->get_power() << endl;
        cout << "Defense: " << this->get_defense() << endl;
        cout << "Speed: " << this->get_defense() << endl;
        cout << "-------------------------------------------------------" << endl;
        cout << "Item stats: " << endl;
        if (this->currentWeapon != nullptr)
        {
            this->currentWeapon->check_stats();
            cout << endl;
        }
        if (this->currentArmor != nullptr)
        {
            this->currentArmor->check_stats();
            cout << endl;
        }
        for (unsigned i = 0; i < this->inventory.at(2).size(); i++)
        {
            this->inventory.at(2).at(i)->check_stats();
            cout << endl;
        }
        cout << "-------------------------------------------------------" << endl;
    }

    void add_item(Item *item, int price)
    {
        if (this->money < price)
        {
            cout << "You don't have enough money to purchase this item." << endl
                 << endl;
            return;
        }

        this->money -= price;

        string itemType = item->get_item_type();

        if (itemType == "Weapon")
        {
            this->inventory.at(0).push_back(item);
        }
        else if (itemType == "Armor")
        {
            this->inventory.at(1).push_back(item);
        }
        else
        {
            this->inventory.at(2).push_back(item);
        }

        cout << item->get_name() << " purchased successfully" << endl;
    }
    
    void remove_item(Item *item, int price)
    {
        string itemType = item->get_item_type();

        if (itemType == "Weapon")
        {
            vector<Item*>::iterator it = find(this->inventory.at(0).begin(), this->inventory.at(0).end(), item);
            if(it != this->inventory.at(0).end()) {
                this->inventory.at(0).erase(it);
                this->money += price;
            }
        }
        else if (itemType == "Armor")
        {
            vector<Item*>::iterator it = find(this->inventory.at(1).begin(), this->inventory.at(1).end(), item);
            if(it != this->inventory.at(1).end()) {
                this->inventory.at(1).erase(it);
                this->money += price;
            }
        }
        else
        {
            vector<Item*>::iterator it = find(this->inventory.at(2).begin(), this->inventory.at(2).end(), item);
            if(it != this->inventory.at(2).end()) {
                this->inventory.at(2).erase(it);
                this->money += price;
            }
        }

        cout << item->get_name() << " sold successfully" << endl;
        delete item;
        cout << "Your new balance is " << this->money << endl
             << endl;
    }
    

    void display_inventory() {
        cout << "-------------------------------------------------------" << endl;
        cout << "Inventory: " << endl;
        for(unsigned i = 0; i < this->inventory.size(); i++) {
            for(unsigned j = 0; j < this->inventory.at(i).size(); j++) {
                cout << this->inventory.at(i).at(j)->get_name() << endl;
            }
        }
        cout << "-------------------------------------------------------" << endl;
    }

    vector<vector<Item*>>* get_inventory() {
        return &this->inventory;
    }

    
    int set_money(int amount)
    {
      money += amount;
    }

    int get_money()
    {
      return money;
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
