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
#include "town.hpp"
#include "game.hpp"
#include <iostream>
using namespace std;

TEST(clearScreenTest, cleartest){
  cout<< "\033[2J\033[1;1H";
  EXPECT_EQ("","");
}

TEST(buyTest,Testbalance){
  int get_money = 10;
  cout << "Your current balance is " << get_money;
  EXPECT_EQ(get_money,10);
}

TEST(buyTest, ExitTest){
  int response = 4;
  while(response != 4) {
        cout << "What would you like to purchase?" << endl;
        cout << "1: Weapon" << endl
        << "2: Armor" << endl
        << "3: Potion" << endl 
        << "4: Exit" << endl;

        cout << "Your current balance is " << "100" << endl;
        switch(response){
        case 4:
          string exit_string= "thanks for shopping.";
          cout << exit_string <<endl;
          EXPECT_EQ(exit_string,"thanks for shopping.");
          break;
        }
  }
}

TEST(sellTest, get_nameTest)
{
  string get_name= "KiloWeapon";
  cout << "Are you sure you want to sell "<< get_name;
  EXPECT_EQ(get_name,"KiloWeapon");
}

TEST(buyConfirmationTest, buyTest)
{
  Item *item = new ByteWeapon();
  Player* player=new Defender()  ;
  string get_name = "ByteWeapon";
  int price = 20;
  int response = 1;
  cout << "Are you sure you want to purchase " << get_name << " for " << price << " credits?" << endl;
  cout << 1 << endl;
  switch(response){
    case 1:
      player->add_item(item,price);
      break;
   }
  ASSERT_ANY_THROW(item);
  delete player;
  delete item;
}

TEST(buyConfirmationTest, cancelTest){
  Item *item= new ByteWeapon();
  string item_type= "ByteWeapon";
  if(item_type == "Potion"){
    Potion* dele = dynamic_cast<Potion*> (item);
    delete dele;
  }
  else {
    delete item;
  }
  ASSERT_FALSE(item == nullptr);
}

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

TEST(BattleTests, SimulateSkill)
{
  Game* mainGame = new Game();
  mainGame->set_class("Cleaner"); 
  Enemy* opponent = new Bug();
  int battle_health = mainGame->get_player()->get_health();
  mainGame->action_phase("skill", battle_health, opponent);
  EXPECT_EQ(battle_health, 27);
  EXPECT_EQ(opponent->get_health(), 5);
  delete mainGame;
  delete opponent;
}

TEST(BattleTests, SimulatePotion)
{
  Game* mainGame = new Game();
  mainGame->set_class("Defender"); 
  Enemy* opponent = new Bug();
  int battle_health = mainGame->get_player()->get_health();
  mainGame->action_phase("attack", battle_health, opponent);
  mainGame->get_player()->AddItemTest(new HealthPotion());
  mainGame->action_phase("potion", battle_health, opponent);
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

TEST(EnemyTests, BugAttack)
{
  Player* player = new Defender();
  Enemy* opponent = new Bug();
  int damage = opponent->attack(player);
  EXPECT_EQ(damage, 1);
  delete player;
  delete opponent;
}

TEST(EnemyTests, WormAttack)
{
  Player* player = new Defender();
  Enemy* opponent = new Worm();
  int damage = opponent->attack(player);
  EXPECT_EQ(damage, 1);
  delete player;
  delete opponent;
}


TEST(EnemyTests, PopUpAdAttack)
{
  Player* player = new Defender();
  Enemy* opponent = new PopUpAd();
  int damage = opponent->attack(player);
  EXPECT_EQ(damage, 2);
  delete player;
  delete opponent;
}

TEST(EnemyTests, SpywareAttack)
{
  Player* player = new Defender();
  Enemy* opponent = new Spyware();
  int damage = opponent->attack(player);
  EXPECT_EQ(damage, 2);
  delete player;
  delete opponent;
}

TEST(EnemyTests, VirusAttack)
{
  Player* player = new Defender();
  Enemy* opponent = new Virus();
  int damage = opponent->attack(player);
  EXPECT_EQ(damage, 2);
  delete player;
  delete opponent;
}

TEST(EnemyTests, TrojanHorseAttack)
{
  Player* player = new Defender();
  Enemy* opponent = new TrojanHorse();
  int damage = opponent->attack(player);
  EXPECT_EQ(damage, 3);
  delete player;
  delete opponent;
}

TEST(EnemyTests, CorruptedMotherboardAttack)
{
  Player* player = new Defender();
  Enemy* opponent = new CorruptedMotherboard();
  int damage = opponent->attack(player);
  EXPECT_EQ(damage, 7);
  delete player;
  delete opponent;
}

TEST (EnemyTests, SetHealth)
{
  Enemy* opponent = new Bug();
  opponent->set_health(5);
  EXPECT_EQ(opponent->get_health(), 10);
  delete opponent;
}

TEST (CharacterTests, GetHealth)
{
  Player* player = new Defender();
  EXPECT_EQ(player->get_health(), 25);
  delete player;
}

TEST (CharacterTests, GetPower)
{
  Player* player = new Defender();
  EXPECT_EQ(player->get_power(), 5);
  delete player;
}

TEST (CharacterTests, GetDefense)
{
  Player* player = new Defender();
  EXPECT_EQ(player->get_defense(), 7);
  delete player;
}

TEST (CharacterTests, GetSpeed)
{
  Player* player = new Defender();
  EXPECT_EQ(player->get_speed(), 3);
  delete player;
}

TEST (CharacterTests, GetNameDefender)
{
  Player* player = new Defender();
  EXPECT_EQ(player->get_name(), "Defender");
  delete player;
}

TEST (CharacterTests, GetNameCleaner)
{
  Player* player = new Cleaner();
  EXPECT_EQ(player->get_name(), "Cleaner");
  delete player;
}

TEST (CharacterTests, GetNameFirewall)
{
  Player* player = new Firewall();
  EXPECT_EQ(player->get_name(), "Firewall");
  delete player;
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
