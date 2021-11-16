#ifndef SKILLSET_HPP
#define SKILLSET_HPP

#include <iostream>
#include <string>

using namespace std;

class SkillSet
{
  protected:
    string name;
  public:
    SkillSet(){};
    virtual int unique_skill(int& battle_hp) = 0;
    string get_name()
    {
      return name;
    }
    ~SkillSet(){};
};

class ShieldBash : public SkillSet
{
  public:
    ShieldBash(){name = "ShieldBash";}
    int unique_skill(int& battle_hp)
    {
      battle_hp-=3;
      return 0;
    }
};

class CleanSweep : public SkillSet
{
  public:
    CleanSweep(){name = "CleanSweep";}
    int unique_skill(int& battle_hp)
    {
      battle_hp-=4;
      return 3;
    }
};

class Rebuild : public SkillSet
{
  public:
    Rebuild(){name = "Rebuild";}
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

    }
    int unique_skill(int& battle_hp)
    {
      int damage_dealt = Skill1->unique_skill(battle_hp) + Skill2->unique_skill(battle_hp);
      return damage_dealt;
    }
};
#endif
