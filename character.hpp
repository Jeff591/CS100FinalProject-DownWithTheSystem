#ifndef CHARACTER_HPP
#define CHARACTER_HPP

class Character
{
  protected:
    int health;
    int power;
    int defence;
    int speed;
  public:
    
    virtual void attack(Character* opponent) = 0;
    int get_health()
    {
      return health;
    }
    int get_power()
    {
      return power;
    }
    int get_defence()
    {
      return defence;
    }
    int get_speed()
    {
      return speed;
    }

};
#endif
