#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <string>
#include "player.hpp"
#include "character.hpp"
#include "dungeon.h"
#include <stdlib.h>
#include "enemy.h"
#include "skillset.hpp"
#include "town.hpp"

using namespace std;

class Game
{
  private:
    Player* playerChar = nullptr;
    bool gameOver = false;
    Dungeon* level1 = new Dungeon1();
    Dungeon* level2 = new Dungeon2();
    Dungeon* level3 = new Dungeon3();
    Dungeon* level4 = new Dungeon4();
    Dungeon* level5 = new Dungeon5();
    Town* town = nullptr;   
  public:
    Game(){};
    ~Game()
    {
      delete level1;
      delete level2;
      delete level3;
      delete level4;
      delete level5;
      delete town;
      delete playerChar;
    }
    void runGame()
    {
      create_character();
      town  = new Town(playerChar);
      clearScreen();
      cin.ignore();
      cout << "Health: " << playerChar->get_health() <<endl;
      cout << "Power: " << playerChar->get_power() <<endl;
      cout << "Defense: " << playerChar->get_defense() <<endl;
      cout << "Speed: " << playerChar->get_speed() <<endl;
      cout << "Test Worked" << endl;
      cin.ignore();
      

      clearScreen();
      intermission();
      battle(level1);
      intermission();
      battle(level2);
      intermission();
      battle(level3);
      intermission();
      battle(level4);
      intermission();
      battle(level5);
    }

    void create_character()
    {
      bool chosen = false;
      string characterInput = "";
      bool invalid = true;
      string character = "";
      while (chosen == false)
      {
        chosen = false;
        invalid = true;
        while (invalid == true)
        {
          invalid = true;
          cout << "Choose your character (insert a number to learn more)" << endl;
          cout << "1. Defender" << endl;
          cout << "2. Cleaner" << endl;
          cout << "3. Firewall" << endl;

          cin >> characterInput;
          clearScreen();
          if (characterInput == "1")
          {
            cout << "Defender: a character with high defense, but low speed" << endl;
            invalid = false;
            character = "Defender";
          }
          else if (characterInput == "2")
          {
            cout << "Cleaner: a character with high attack, but low defense" << endl;
            invalid = false;
            character = "Cleaner";
          }
          else if (characterInput == "3")
          {
            cout << "Firewall: a character with high health and average stats" << endl;
            invalid = false;
            character = "Firewall";
          }
          else
          {
            cout << "Please choose a valid number" << endl;
            invalid = true;
          }
        }
        cout << "Is this the character you want to choose? (y/n)" << endl;
        cin >> characterInput;
        if (characterInput == "y")
        {
          chosen = true;
          set_class(character);
        }
        else
        {
          chosen = false;
        }
      }
    }

    //NEW
    void set_class(string chosen)
    {
      if (chosen == "Defender")
      {
        playerChar = new Defender();
      }
      else if (chosen == "Cleaner")
      {
        playerChar = new Cleaner();
      }
      else
      {
        playerChar =  new Firewall();
      }
    }

    
    void battle(Dungeon* level)
    {
      if (gameOver == true) return;
      string choice;
      string action;
      bool select = false;
      int battle_health = playerChar->get_health();
      vector<Enemy*>* encounters = level->get_enemies();
      SkillSet* skill1 = playerChar->get_skill1();
      SkillSet* skill2 = playerChar->get_skill2();
      Enemy* opponent = nullptr;
      
      for(unsigned int i = 0; i < encounters->size(); i++)
      {
        while(encounters->at(i)->get_health() > 0)
        {
          opponent = encounters->at(i);
          menu_phase(action, battle_health, opponent);
          action_phase(action, battle_health, opponent);
          if(gameOver == true)
	  {
	    return;
          }
          select = false;
        }
        cout << encounters->at(i)->get_name() << " was defeated!" << endl;
        battle_health += 3;
        if(battle_health > playerChar->get_health())
        {
          battle_health = playerChar->get_health();
        }

      }
      
      cout << "Battle won!" << endl;
      cout << "You recieved " << level->get_reward() << " money" <<endl;
      playerChar->set_money(level->get_reward());
    }


    void menu_phase(string &action,int battle_health, Enemy* opponent)
    {
      bool select = false;
      string choice = "";
      SkillSet* skill1 = playerChar->get_skill1();
      SkillSet* skill2 = playerChar->get_skill2();

      while(select == false)
      {
        cout << "Enemy: " << opponent->get_name() << " HP: " << opponent->get_health() << endl;
        cout << "Your HP: " << battle_health << endl;
        cout << "Choose your action" << endl;
        cout << "1: Attack" << endl;
        cout << "2: Skills" << endl;
        cout << "3: Potions" << endl;
        cin >> choice;
        clearScreen();
        if(choice == "1")
        {
          action = "attack";
          select = true;
        }
        else if(choice == "2")
        {
          cout << "Choose your skill" << endl;
          cout << "1: " << skill1->get_name() << endl << skill1->get_description() << endl;
          cout << "2: " << skill2->get_name() << endl << skill2->get_description() << endl; 
          cout << "3: back to main menu" << endl;
          cin >> choice;
          clearScreen();
          if(choice == "1")
          {
            if(battle_health - skill1->get_health_cost() > 0)
            {
              action = "skill";
              select = true;
            }
            else
            {
              cout << "Your HP was too low to perform this skill" << endl;
              select = false;
            }
          }
          else if(choice == "2")
          {
            if(battle_health - skill2->get_health_cost() > 0)
            {
              action = "combo_skill";
              select = true;
            }
            else
            {
              cout << "Your HP was too low to perform this skill" << endl;
              select = false;
            }
            
          }
          else if(choice == "3")
          {
            cout << "Back to main menu" << endl;
            select = false;
          }
          else
          {
            cout << "Invalid input, back to main menu" << endl;
            select = false;
          }
        }
        else if(choice == "3")
        {
          cout << "Choose your potion" << endl;
          cout << "1: Health potion" << endl;
          cin >> choice;
          clearScreen();
          if(choice == "1")
          {
            action = "health_potion";
            select = true;
          }
          else
          {
            cout << "Invalid input, back to main menu" << endl;
            select  = false;
          }
        }
        else
        {
          cout << "Invalid input" << endl;
          select = false;
        }
      }
    }

    void action_phase(string action, int &battle_health, Enemy* opponent)
    {
      int attack_damage;
      SkillSet* skill1 = playerChar->get_skill1();
      SkillSet* skill2 = playerChar->get_skill2();
      if((action == "skill" && skill1->get_name() == "ShieldBash") || (action == "combo_skill" && skill2->get_name() == "ShieldBash + Rebuild") || (action == "combo_skill" && skill2->get_name() == "CleanSweep + ShieldBash"))
      {
        if(battle_health <= 0) 
        {
          game_over();
          gameOver = true;
          return;
        }
        else
        {
          if(action == "skill")
          {
            attack_damage = skill1->unique_skill(battle_health) + playerChar->attack(opponent);
            cout << playerChar->get_name() << " does " << attack_damage << " to " << opponent->get_name() << endl;
            opponent->set_health(attack_damage);
          }
          else if (action == "combo_skill")
          {
            attack_damage = skill2->unique_skill(battle_health) + playerChar->attack(opponent);
            cout << playerChar->get_name() << " does " << attack_damage << " to " << opponent->get_name() << endl;
            opponent->set_health(attack_damage);
          }
          
        }
        battle_health -= opponent->attack(playerChar);
      }
      else if(action == "attack" && opponent->get_speed() > playerChar->get_speed())
      {
        battle_health -= opponent->attack(playerChar);
        if(battle_health <= 0)
        {
          game_over();
          gameOver = true;
          return;
        }
        cout << playerChar->get_name() << " does " << playerChar->attack(opponent) << " to " << opponent->get_name() << endl;
        opponent->set_health(playerChar->attack(opponent));
      }
      else if(action == "attack" && opponent->get_speed() <= playerChar->get_speed())
      {
        cout << playerChar->get_name() << " does " << playerChar->attack(opponent) << " to " << opponent->get_name() << endl;
        opponent->set_health(playerChar->attack(opponent));

        battle_health -= opponent->attack(playerChar);
        if(battle_health <= 0)
        {
          game_over();
          gameOver = true;
          return;
        }
      }
      else if(action == "skill" && opponent->get_speed() > playerChar->get_speed())
      {
        battle_health -= opponent->attack(playerChar);
        if(battle_health <= 0)
        {
          game_over();
          gameOver = true;
          return;
        }
	if(skill1->get_name() == "Rebuild")//TEST
        {
          attack_damage = skill1->unique_skill(battle_health);
        }
        else
        {
          attack_damage = skill1->unique_skill(battle_health) + playerChar->attack(opponent);
        }
        cout << playerChar->get_name() << " does " << attack_damage << " to " << opponent->get_name() << endl;
        opponent->set_health(attack_damage);
        if(battle_health <=0)
        {
          game_over();
          gameOver = true;
          return;
        }
      }
      else if(action == "skill" && opponent->get_speed() <= playerChar->get_speed())
      {
        if(skill1->get_name() == "Rebuild")
        {
          attack_damage = skill1->unique_skill(battle_health);
        }
        else
        {
          attack_damage = skill1->unique_skill(battle_health) + playerChar->attack(opponent);
        }
        cout << playerChar->get_name() << " does " << attack_damage << " to " << opponent->get_name() << endl;
        opponent->set_health(attack_damage);
        if(battle_health <=0)
        {
          game_over();
          gameOver = true;
          return;
        }
        battle_health -= opponent->attack(playerChar);
        if(battle_health <= 0)
        {
          game_over();
          gameOver = true;
          return;
        }
      }
      else if(action == "combo_skill" && opponent->get_speed() > playerChar->get_speed())
      {
        attack_damage = skill2->unique_skill(battle_health) + playerChar->attack(opponent);
        battle_health -= opponent->attack(playerChar);
        if(battle_health <= 0)
        {
          game_over();
          gameOver = true;
          return;
        }
        cout << playerChar->get_name() << " does " << attack_damage << " to " << opponent->get_name() << endl;
        opponent->set_health(attack_damage);
        if(battle_health <=0)
        {
          game_over();
          gameOver = true;
          return;
        }
      }
      else if(action == "combo_skill" && opponent->get_speed() <= playerChar->get_speed())
      {
        attack_damage = skill2->unique_skill(battle_health) + playerChar->attack(opponent);
        cout << playerChar->get_name() << " does " << attack_damage << " to " << opponent->get_name() << endl;
        opponent->set_health(attack_damage);
        if(battle_health <=0)
        {
          game_over();
          gameOver = true;
          return;
        }
        battle_health -= opponent->attack(playerChar);
        if(battle_health <= 0)
        {
          game_over();
          gameOver = true;
          return;
        }
      }
      else if(action == "health_potion")
      {
        {
          if(playerChar->get_inventory()->at(2).size() <= 0)
          {
            cout << "You have no more health potions" << endl;
          }
          else
          {
            battle_health += 15;
            
            playerChar->get_inventory()->at(2).pop_back();
          }
        }
      }
      if(battle_health > playerChar->get_health())
      {
        battle_health = playerChar->get_health();
      }
      return;
    }
    
    void intermission()
    {
      if(gameOver == true)
      {
        return;
      }
      bool select = false;
      while(select == false)
      {
        string choice;
        cout << "What would you like to do before continuing to the next battle?" << endl;
        cout << "1. Check Inventory" << endl;
        cout << "2. Check Stats" << endl;
        cout << "3. Visit the Town to buy items" << endl;
        cout << "4. Visit the Town to sell items" << endl;
        cout << "5. Change current weapon" << endl;
        cout << "6. Change current armor" << endl;
        cout << "7. Continue to the next battle" << endl;
        cin >> choice;
        if (choice == "1")
        {
          playerChar->display_inventory();
        }
        else if (choice == "2")
        {
          playerChar->check_stats();
        }
        else if (choice == "3")
        {
          town->buy();
        }
        else if (choice == "4")
        {
          town->sell();
        }
        else if (choice == "5") 
        {
          choose_weapon();
        }
        else if (choice == "6")
        {
          choose_armor();
        }
        else if (choice == "7")
        {
          return;
        }
        else
        {
          cout << "Invalid input" << endl;
        }
      }
    }

    void choose_weapon()
    {
      string choice;
      if (playerChar->get_inventory()->at(0).size() == 0)
      {
        cout << "No weapons to equip" << endl;
        return;
      }
      cout << "Weapons List: " << endl;
      cout << "---------------------------------------------------------" << endl;
      for (unsigned int i = 0; i < playerChar->get_inventory()->at(0).size(); i++)
      {
        cout << i+1 << ". " << playerChar->get_inventory()->at(0).at(i)->get_name() << endl;
      }
      cout << "---------------------------------------------------------" << endl;
      cout << "Which weapon would you like to equip? (Please put the name of the weapon)" << endl;
      cin >> choice;
      playerChar->set_current_weapon(choice);
      return;
    }

    void choose_armor()
    {
      string choice;
      if(playerChar->get_inventory()->at(1).size() == 0)
      {
        cout << "No armor to equip" << endl;
        return;
      }
      cout << "---------------------------------------------------------" << endl;
      cout << "Armor List: " << endl;
      for (unsigned int i = 0; i < playerChar->get_inventory()->at(1).size(); i++)
      {
        cout << i+1 << ". " << playerChar->get_inventory()->at(1).at(i)->get_name() << endl;
      }
      cout << "---------------------------------------------------------" << endl;
      cout << "Which armor would you like to put on? (Please put the name of the armor)" << endl;
      cin >> choice;
      playerChar->set_current_armor(choice);
      return;
      
    }

    void clearScreen()
    {
      cout << "\033[2J\033[1;1H";
      return;
    }

    Player* get_player()
    {
      return playerChar;
    }

    void game_over()
    {
      clearScreen();
      cout << "You died" << endl;
      cout << "Game over" << endl;
      cin.ignore();
    }
};
#endif
