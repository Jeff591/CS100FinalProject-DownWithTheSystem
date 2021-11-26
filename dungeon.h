#ifndef __DUNGEON_H__
#define __DUNGEON_H__

#include <vector>
#include "enemy.h"

class Dungeon : public Enemy {
    protected:
        std::vector<Enemy*> encounters;
        int reward;
    public:
        Dungeon(){};
        ~Dungeon();
        std::vector<Enemy*>* get_enemies();
        int get_reward()
        {
          return reward;
        }
};

class Dungeon1 : public Dungeon 
{
  public: 
    Dungeon1()
    {
      encounters.push_back(new Bug());
      encounters.push_back(new Worm());
      encounters.push_back(new Bug());
      reward = 20;
    }

};

class Dungeon2 : public Dungeon 
{
  public: 
    Dungeon2()
    {
      encounters.push_back(new PopUpAd());
      encounters.push_back(new Worm());
      encounters.push_back(new Spyware());
      reward = 50;
    }

};

class Dungeon3 : public Dungeon 
{
  public: 
    Dungeon3()
    {
      encounters.push_back(new Spyware());
      encounters.push_back(new Virus());
      encounters.push_back(new PopUpAd());
      reward = 80;
    }

};

class Dungeon4 : public Dungeon 
{
  public: 
    Dungeon4()
    {
      encounters.push_back(new Virus());
      encounters.push_back(new Spyware());
      encounters.push_back(new TrojanHorse());
      reward = 150;
    }
};

class Dungeon5 : public Dungeon 
{
  public: 
    Dungeon5()
    {
      encounters.push_back(new TrojanHorse());
      encounters.push_back(new TrojanHorse());
      encounters.push_back(new CorruptedMotherboard());
      reward = 9999999;
    }

};

#endif
