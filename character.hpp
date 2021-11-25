#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
using namespace std;

class Character
{
  protected:
    int health;
    int power;
    int defense;
    int speed;
    string name;   
  public:
    Character(){};
    virtual ~Character(){};
    virtual int attack(Character* opponent) = 0;
    int get_health()
    {
      return health;
    }
    int get_power()
    {
      return power;
    }
    int get_defense()
    {
      return defense;
    }
    int get_speed()
    {
      return speed;
    }
    string get_name()
    {
      return this->name;
    }
};
#endif
