#include "town.hpp"
#include "player.hpp"

#include <iostream>
void buy(){
    int response = 0;
    std::cout << "1: Armor 2:Weapon 3:Potion" << endl;
    do
    {
    std:: cin >> response;
    switch (response)
    {

    case 1: //armor
    std::cout << "What Armor would you like?"<< endl << "1. ByteArmor [15 credits] | +5 defense" << " 2.  KiloArmor [30 credits] | +10 defense" ;
    cout << "3. MegaArmor [60 credits] | +15 defense"<< "4. GigaArmor [120 credits] +20 defense"<< " 5.  TeraArmor {240 credits] | +25 defense" << endl;
    do{
        std:: cin >> response;
        switch(response)
        {
            case 1:
            Player.additem(ByteArmor(), 15 ); //.additem(item,sell_price) assuming we are adding an add item function to player'
            break;
            case 2:
            Player.additem(KiloArmor(), 30);
            break;
              case 3:
            Player.additem(MegaArmor(), 60 );
            break;
              case 4:
            Player.additem(GigaArmor(), 120 );
            break;
              case 5:
            Player.additem(TeraArmor(), 240 );
            break;
        }
    } while(response > 5|| response < 1 );
    break;


    case 2: //Weapon
    std::cout << "What Weapon would you like?" << endl << "1. ByteWeapon [15 credits] | +5 attack" << " 2.  KiloWeapon [30 credits] | +10 attack" ;
    cout << "3. MegaWeapon [60 credits] | +15 attack"<< "4. GigaWeapon [120 credits] | +20 attack"<< " 5.  TeraWeapon [240 credits] | +25 attack" << endl;
        do
        {
            std:: cin>> response;
            switch (response)
            {
             case 1:
            Player.additem(ByteWeapon(), 15 ); //assuming we are adding an add item function to player'
            break;
            case 2:
            Player.additem(KiloWeapon(), 30);
            break;
              case 3:
            Player.additem(MegaWeapon(), 60 );
            break;
              case 4:
            Player.additem(GigaWeapon(), 120 );
            break;
              case 5:
            Player.additem(TeraWeapon(), 240 );
            break;
            }
        } while (response > 5 || response < 1);
    break;

        case 3: //Potion

        std::cout << "What Potion would you like?" << endl << "1. Health Potion";
        do
        {
            std::cin >> response;
            switch (response)
            {
            case 1:
                Player.additem(HealthPotion(), 5);
                break;
            
            }
        } while (response > 5 || response < 1);
        
    }

    default:
    std:: cout << "Enter Valid Number" << endl;
    std::cout << "1: Armor 2:Weapon 3:Potion" << endl; 
    } while (response >5 || response < 1);
 }
  void sell()
    { //still need to implement this, not sure what to do for that excactly
        int response = 0;
        Player.showinventory();//or .inventory im not sure what the variable be called to display inventory

    }

int main()
{
    int response;//used to navigate menu
    std::cout << "Hello, what would you like to do" <<endl;
    std::cout << "1: Purchase Items 2. Sell Items 3: Show Inventory 4. Display total money 5: Exit"<< endl;

    do
    {
        std::cin >> response;

        switch (response)
        {

        case 1:
        town.buy();
            break;
        case 2:
        town.sell();
            break;
        case 3:
        Player.showinventory();/// or .inventory not sure yet
            break;
        case 4:
        std::cout << "You Have $" << player.money << endl;
            break;
        case 5:
        std::cout << "Thank you for shopping" <<endl;
            break;
        
        
        default:
                    std::cout << "Enter Valid Number" << endl;
                    std::cout << "1. Purchase Items 2. Sell Items 3: Show Inventory 4. Display total money 5: Exit"<< endl;
    } while (response !=5);
    
    return

}
