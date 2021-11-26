#ifndef SKILLSET_HPP
#define SKILLSET_HPP

#include <iostream>
#include <string>

using namespace std;

class SkillSet
{
  protected:
    string name;
    string description;
    int health_cost;
  public:
    SkillSet(){};
    virtual ~SkillSet(){};
    virtual int unique_skill(int& battle_hp) = 0;
    string get_name()
    {
      return name;
    }
    string get_description()
    {
      return description;
    }
    int get_health_cost()
    {
      return health_cost;
    }
};

class ShieldBash : public SkillSet
{
  public:
    ShieldBash()
    {
      name = "ShieldBash";
      description = "Attack goes first, 3 hp lost though";
      health_cost = 3;
    }
    int unique_skill(int& battle_hp)
    {
      battle_hp-=3;
      return 0;
    }
};

class CleanSweep : public SkillSet
{
  public:
    CleanSweep()
    {
      name = "CleanSweep";
      description = "attack is increased by 3 the next turn, but you lose 4 hp";
      health_cost  = 4;
    }
    int unique_skill(int& battle_hp)
    {
      battle_hp-=4;
      return 3;
    }

};

class Rebuild : public SkillSet
{
  public:
    Rebuild()
    {
      name = "Rebuild";
      description = "Restore 8 hp";
      health_cost = 0;
    }
    int unique_skill(int& battle_hp)
    {
      battle_hp+=8;
      return 0;
    }
};

class ComboSkill : public SkillSet
{
  private:
    SkillSet* Skill1;
    SkillSet* Skill2;

  public:
    ComboSkill(SkillSet* first, SkillSet* second)
    {
      Skill1 = first;
      Skill2 = second;
      name = Skill1->get_name() + " + " + Skill2->get_name();
      description = Skill1->get_description() + " + " + Skill2->get_description();
      health_cost = Skill1->get_health_cost() + Skill2->get_health_cost();

    }
    int unique_skill(int& battle_hp)
    {
      int damage_dealt = Skill1->unique_skill(battle_hp) + Skill2->unique_skill(battle_hp);
      return damage_dealt;
    }
    ~ComboSkill()
    {
      delete Skill1;
      delete Skill2;
    }

};
#endif
