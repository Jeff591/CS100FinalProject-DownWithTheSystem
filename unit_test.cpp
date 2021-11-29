#include "gtest/gtest.h"
#include "dungeon.h"
#include "enemy.h"
#include "Potion.hpp"
#include "player.hpp"
#include "Weapon.hpp"
#include "character.hpp"
#include "Armor.hpp"
#include "Item.hpp"
#include "skillset.hpp"
#include "game.hpp"
#include <iostream>

using namespace std;

TEST(standard_attack, Defender_Bug_attack_eachother)
{
  Player* player = new Defender();
  Enemy* bug = new Bug();
  EXPECT_EQ(player->attack(bug), 3);
  EXPECT_EQ(bug->attack(player), 1);
  delete player;
  delete bug;
}

TEST(regularskill, Defender_regularskill_test)
{
  Player* player = new Defender();
  Enemy* bug = new Bug();
  int damage = 0;
  int battle_Hp = 25;
  damage = player->attack(bug) + player->get_skill1()->unique_skill(battle_Hp);
  EXPECT_EQ(damage, 3);
  EXPECT_EQ(battle_Hp, 22);
  delete player;
  delete bug;
}

TEST(comboskill, Defender_comboskill_test)
{
  Player* player = new Defender();
  Enemy* bug = new Bug();
  int damage = 0;
  int battle_Hp = 20;
  damage = player->attack(bug) + player->get_skill2()->unique_skill(battle_Hp);
  EXPECT_EQ(damage, 3);
  EXPECT_EQ(battle_Hp, 25);
  delete player;
  delete bug;
}

TEST(standard_attack, Cleaner_Bug_attack_eachother)
{
  Player* player = new Cleaner();
  Enemy* bug = new Bug();
  EXPECT_EQ(player->attack(bug), 7);
  EXPECT_EQ(bug->attack(player), 4);
  delete player;
  delete bug;
}

TEST(regularskill, Cleaner_regularskill_test)
{
  Player* player = new Cleaner();
  Enemy* bug = new Bug();
  int damage = 0;
  int battle_Hp = 30;
  damage = player->attack(bug) + player->get_skill1()->unique_skill(battle_Hp);
  EXPECT_EQ(damage, 10);
  EXPECT_EQ(battle_Hp, 26);
  delete player;
  delete bug;
}

TEST(comboskill, Cleaner_comboskill_test)
{
  Player* player = new Cleaner();
  Enemy* bug  = new Bug();
  int damage = 0;
  int battle_Hp = 30;
  damage = player->attack(bug) + player->get_skill2()->unique_skill(battle_Hp);
  EXPECT_EQ(damage, 10);
  EXPECT_EQ(battle_Hp, 23);
  delete player;
  delete bug;
}

TEST(standard_attack, Firewall_Bug_attack_eachother)
{
  Player* player = new Firewall();
  Enemy* bug = new Bug();
  EXPECT_EQ(player->attack(bug), 3);
  EXPECT_EQ(bug->attack(player), 3);
  delete player;
  delete bug;
}

TEST(regularskill, Firewall_regularskill_test)
{
  Player* player = new Firewall();
  Enemy* bug = new Bug();
  int damage = 0;
  int battle_Hp = 35;
  damage = player->get_skill1()->unique_skill(battle_Hp);
  EXPECT_EQ(damage, 0);
  EXPECT_EQ(battle_Hp, 43);
  delete player;
  delete bug;
}

TEST(comboskill, Firewall_comboskill_test)
{
  Player* player = new Firewall();
  Enemy* bug = new Bug();
  int damage = 0;
  int battle_Hp = player->get_health();
  damage = player->attack(bug) + player->get_skill2()->unique_skill(battle_Hp);
  EXPECT_EQ(damage, 6);
  EXPECT_EQ(battle_Hp, 49);
  delete player;
  delete bug;
}


TEST(BattleTests, SimulateAttack)
{
  Game* mainGame = new Game();
  mainGame->set_class("Defender"); 
  Enemy* opponent = new Bug();
  int battle_health = mainGame->get_player()->get_health();
  mainGame->action_phase("attack", battle_health, opponent);
  EXPECT_EQ(battle_health, 24);
  EXPECT_EQ(opponent->get_health(), 12);
  delete mainGame;
  delete opponent;
}

TEST(PlayerGetters, Skill1)
{
  Player* defender = new Defender();
  Player* cleaner = new Cleaner();
  Player* firewall = new Firewall();

  EXPECT_EQ(defender->get_skill1()->get_name(), "ShieldBash");
  EXPECT_EQ(cleaner->get_skill1()->get_name(), "CleanSweep");
  EXPECT_EQ(firewall->get_skill1()->get_name(), "Rebuild");

  delete defender;
  delete cleaner;
  delete firewall;

}

TEST(PlayerGetters, Skill2)
{
  Player* defender = new Defender();
  Player* cleaner = new Cleaner();
  Player* firewall = new Firewall();

  EXPECT_EQ(defender->get_skill2()->get_name(), "ShieldBash + Rebuild");
  EXPECT_EQ(cleaner->get_skill2()->get_name(), "CleanSweep + ShieldBash");
  EXPECT_EQ(firewall->get_skill2()->get_name(), "Rebuild + CleanSweep");

  delete defender;
  delete cleaner;
  delete firewall;
}

TEST(PlayerGetters, Money)
{
  Player* player = new Defender();
  EXPECT_EQ(player->get_money(), 0);

  player->set_money(1000);

  EXPECT_EQ(player->get_money(), 1000);
  
  delete player;

}

TEST(PlayerGetters, CurrentArmor)
{
  Player* player = new Defender();
  EXPECT_EQ(player->get_current_armor(), nullptr);

  player->add_item(new KiloArmor(), 0);

  player->set_current_armor("KiloArmor");

  EXPECT_EQ(player->get_current_armor()->get_name(), "KiloArmor");

  delete player;

}

TEST(PlayerGetters, CurrentWeapon)
{
  Player* player = new Defender();
  EXPECT_EQ(player->get_current_weapon(), nullptr);

  player->add_item(new MegaWeapon(), 0);

  player->set_current_weapon("MegaWeapon");

  EXPECT_EQ(player->get_current_weapon()->get_name(), "MegaWeapon");

  delete player;
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
