#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <string>
#include "player.hpp"
#include "character.hpp"
//#include "dungeon.hpp"

using namespace std;

class Game
{
  private:
    Player* playerChar = nullptr;

  public:
    void runGame()
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
          playerChar = set_class(character);
        }
        else
        {
          chosen = false;
        }
      }
      cout << "Health: " << playerChar->get_health() <<endl;
      cout << "Power: " << playerChar->get_power() <<endl;
      cout << "Defense: " << playerChar->get_defense() <<endl;
      cout << "Speed: " << playerChar->get_speed() <<endl;
      cout << "Test Worked" << endl;
     
    }

    //void battle(Dungeon* level);

    void game_over();
    
    Player* set_class(string chosen)
    {
      if (chosen == "Defender")
      {
        return new Defender();
      }
      else if (chosen == "Cleaner")
      {
        return new Cleaner();
      }
      else
      {
        return new Firewall();
      }
    }

};
#endif
