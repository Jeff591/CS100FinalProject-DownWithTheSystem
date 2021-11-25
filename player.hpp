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
#include <typeinfo>

using namespace std;

class Player : public Character
{
  protected:
    //0: Weapon, 1: Armor, 2: Potion
    //Equipped item will be in index 0 for each vector
    vector<vector<Item*>> inventory = vector<vector<Item*>>(3, vector<Item*>()); 
    int money = 0;
    Weapon* currentWeapon = nullptr;
    Armor* currentArmor = nullptr;
    SkillSet* mainSkill = nullptr;
    SkillSet* comboSkill = nullptr;

  public:

    Player(){};
    ~Player(){};

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

    void add_item(Item* item, int price) {
        if(this->money < price) {
            cout << "You don't have enough money to purchase this item." << endl << endl;
            return;
        }

        this->money -= price;

        string itemType = typeid(item).name();

        if(itemType == "Weapon") {
            this->inventory.at(0).push_back(item);
        }else if(itemType == "Armor") {
            this->inventory.at(1).push_back(item);
        }else{
            this->inventory.at(2).push_back(item);
        }

        cout << item->get_name() << " purchased successfully" << endl;
        cout << "Your new balance is " << this->money << endl << endl;

    }

    int get_money() {
        return this->money;
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
      mainSkill = new ShieldBash();
      comboSkill = new ComboSkill(new ShieldBash(), new Rebuild());
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
      mainSkill = new CleanSweep();
      comboSkill = new ComboSkill(new CleanSweep(), new ShieldBash());
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
      mainSkill = new Rebuild();
      comboSkill = new ComboSkill(new Rebuild(), new CleanSweep());
    }

    ~Firewall();
};
#endif
