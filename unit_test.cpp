#include "gtest/gtest.h"
#include "dungeon.h"
#include "enemy.h"
#include "Potion.hpp"
#include "player.hpp"
#include "Weapon.hpp"
#include "character.hpp"
#include "Armor.hpp"
#include "Item.hpp"
#include "town.hpp"
#include "game.hpp"
#include <iostream>
using namespace std;

TEST(clearScreenTest, cleartest){
cout<< "\033[2J\033[1;1H";
EXPECT_EQ("","");
}

TEST(buyTest,Testbalance){
int get_money=10;
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
cout<< exit_string <<endl;
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



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
