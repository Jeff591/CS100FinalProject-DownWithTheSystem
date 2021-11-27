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

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
