#include "town.hpp"

void clearScreen()
{
    cout << "\033[2J\033[1;1H";
    return;
}

Town::Town(Player* player) {
    this->player = player;
}

void Town::buy(){
    int response = 0;
    while(response != 4) {
        cout << "What would you like to purchase?" << endl;
        cout << "1: Weapon" << endl
        << "2: Armor" << endl
        << "3: Potion" << endl 
        << "4: Exit" << endl;

        cout << "Your current balance is " << this->player->get_money() << endl;

        cin >> response;
        clearScreen();

        int response2 = 0;
        switch (response)
        {
            case 1: //Weapon
                while(response2 < 1 || response2 > 6) {
                    cout << "What Weapon would you like?" << endl 
                    << "1. ByteWeapon [15 credits] | +5 attack" << endl
                    << "2. KiloWeapon [30 credits] | +10 attack" << endl
                    << "3. MegaWeapon [60 credits] | +15 attack" << endl
                    << "4. GigaWeapon [120 credits] | +20 attack" << endl
                    << "5. TeraWeapon [240 credits] | +25 attack" << endl
                    << "6. Back" << endl;

                    cin >> response2;
                    clearScreen();

                    switch(response2) {
                        case 1:
                            this->buyConfirmation(new ByteWeapon(), ByteWeapon().get_sell_price());
                            break;
                        case 2:
                            this->buyConfirmation(new KiloWeapon(), KiloWeapon().get_sell_price());
                            break;
                        case 3:
                            this->buyConfirmation(new MegaWeapon(), MegaWeapon().get_sell_price());
                            break;
                        case 4:
                            this->buyConfirmation(new GigaWeapon(), GigaWeapon().get_sell_price());
                            break;
                        case 5:
                            this->buyConfirmation(new TeraWeapon(), TeraWeapon().get_sell_price());
                            break;
                        case 6:
                            break;
                        default:
                            cout << "Invalid option." << endl;
                            break;
                    }
                }

                response2 = 0;
                break;

            case 2: //Armor
                while(response2 < 1 || response2 > 6) {
                    cout << "What Armor would you like?"<< endl 
                    << "1. ByteArmor [15 credits] | +5 defense" << endl
                    << "2. KiloArmor [30 credits] | +10 defense" << endl
                    << "3. MegaArmor [60 credits] | +15 defense" << endl
                    << "4. GigaArmor [120 credits] | +20 defense" << endl
                    << "5. TeraArmor {240 credits] | +25 defense" << endl
                    << "6. Back" << endl;

                    cin >> response2;
                    clearScreen();
                    
                    switch(response2) {
                        case 1:
                            this->buyConfirmation(new ByteArmor(), ByteArmor().get_sell_price());
                            break;
                        case 2:
                            this->buyConfirmation(new KiloArmor(), KiloArmor().get_sell_price());
                            break;
                        case 3:
                            this->buyConfirmation(new MegaArmor(), MegaArmor().get_sell_price());
                            break;
                        case 4:
                            this->buyConfirmation(new GigaArmor(), GigaArmor().get_sell_price());
                            break;
                        case 5:
                            this->buyConfirmation(new TeraArmor(), TeraArmor().get_sell_price());
                            break;
                        case 6:
                            break;
                        default:
                            cout << "Invalid option." << endl;
                            break;
                    }
                }

                response2 = 0;
                break;
            case 3: //Armor
                
                while(response2 < 1 || response2 > 2) {
                    cout << "What Potion would you like?" << endl 
                    << "1. Health Potion" << endl
                    << "2. Back" << endl;

                    cin >> response2;
                    clearScreen();

                    switch(response2) {
                        case 1:
                            this->buyConfirmation(new HealthPotion(), HealthPotion().get_sell_price());
                            break;
                        case 2:
                            break;
                        default:
                            cout << "Invalid option." << endl;
                            break;
                    }
                }

                response2 = 0;
                break;

            case 4: //exit
                cout << "Thanks for shopping." << endl;
                break;

            default:
                cout << "Invalid option." << endl;
                break;
        }
    }
 }

void Town::sell()
{ 
    vector<vector<Item*>>* itemList = player->get_inventory();

    int response = 0;
    while(response != 4) {
        cout << "What would you like to sell?" << endl;
        cout << "1: Weapon" << endl
        << "2: Armor" << endl
        << "3: Potion" << endl 
        << "4: Exit" << endl;

        cout << "Your current balance is " << this->player->get_money() << endl;


        cin >> response;
        clearScreen();

        int response2 = 0;
        switch(response) {
            case 1: //Weapon
                if(itemList->at(0).size() == 0) {
                    cout << "You have no items in this category." << endl;
                    break;
                }

                while(response2 < 1 || response2 > itemList->at(0).size() + 1) {
                    for(unsigned i = 0; i < itemList->at(0).size(); i++) {
                        cout << i + 1 << ": " << itemList->at(0).at(i)->get_name() << " [" << itemList->at(0).at(i)->get_sell_price() << " credits]" << endl;
                    }
                    cout << itemList->at(0).size() + 1 << ": Back" << endl;

                    cin >> response2;
                    clearScreen();
                    if(response2 < 0 || response2 > itemList->at(0).size() + 1) {
                        cout << "Invalid option." << endl;

                    }else if(response2 == itemList->at(0).size() + 1) {
                        break;
                    
                    }else{    
                        Item* itemToSell = itemList->at(0).at(response2 - 1);

                        this->sellConfirmation(itemToSell, itemToSell->get_sell_price());
                    }

                }

                response2 = 0;
                break;

            case 2: //Armor
                if(itemList->at(1).size() == 0) {
                    cout << "You have no items in this category." << endl;
                    break;
                }

                while(response2 < 1 || response2 > itemList->at(1).size() + 1) {
                    for(unsigned i = 0; i < itemList->at(1).size(); i++) {
                        cout << i + 1 << ": " << itemList->at(1).at(i)->get_name() << " [" << itemList->at(1).at(i)->get_sell_price() << " credits]" << endl;
                    }
                    cout << itemList->at(1).size() + 1 << ": Back" << endl;

                    cin >> response2;
                    clearScreen();
                    if(response2 < 0 || response2 > itemList->at(1).size() + 1) {
                        cout << "Invalid option." << endl;

                    }else if(response2 == itemList->at(1).size() + 1) {
                        break;
                    
                    }else{    
                        Item* itemToSell = itemList->at(1).at(response2 - 1);

                        this->sellConfirmation(itemToSell, itemToSell->get_sell_price());
                    }
                }
                
                response2 = 0;
                break;
            case 3: //Potion
                if(itemList->at(2).size() == 0) {
                    cout << "You have no items in this category." << endl;
                    break;
                }

                while(response2 < 1 || response2 > itemList->at(2).size() + 1) {
                    for(unsigned i = 0; i < itemList->at(2).size(); i++) {
                        cout << i + 1 << ": " << itemList->at(2).at(i)->get_name() << " [" << itemList->at(2).at(i)->get_sell_price() << " credits]" << endl;
                    }
                    cout << itemList->at(2).size() + 1 << ": Back" << endl;

                    cin >> response2;
                    clearScreen();
                    if(response2 < 0 || response2 > itemList->at(2).size() + 1) {
                        cout << "Invalid option." << endl;

                    }else if(response2 == itemList->at(2).size() + 1) {
                        break;
                    
                    }else{
                        Item* itemToSell = itemList->at(2).at(response2 - 1);

                        this->sellConfirmation(itemToSell, itemToSell->get_sell_price());
                    }
                }
                
                response2 = 0;
                break;
            case 4: //Exit
                break;
            default:
                cout << "Invalid option." << endl << endl;
                break;
        }
    }
}

void Town::buyConfirmation(Item *item, int price) {

    int response = 0;

    while(response != 1 && response != 2) {
        cout << "Are you sure you want to purchase " << item->get_name() << " for " << price << " credits?" << endl;
        cout << "1: Yes" << endl;
        cout << "2: No" << endl;
        cin >> response;
        clearScreen();
        switch(response) {
            case 1:
                this->player->add_item(item, price);
                break;
            case 2:
                cout << "Item purchase cancelled." << endl;
                if (item->get_item_type() == "Potion")
		{
		  Potion* dele =  dynamic_cast<Potion*> (item);
                  delete dele;
		}
		else
		{
                  delete item;
                }
                break;
            default:
                cout << "Invalid option." << endl << endl;
                break;
        }
    }
}

void Town::sellConfirmation(Item *item, int price) {
     int response = 0;

    while(response != 1 && response != 2) {
        cout << "Are you sure you want to sell " << item->get_name() << " for " << price << " credits?" << endl;
        cout << "1: Yes" << endl;
        cout << "2: No" << endl;
        cin >> response;
        clearScreen();
        switch(response) {
            case 1:
                this->player->remove_item(item, price);
                break;
            case 2:
                cout << "Item sell cancelled." << endl;
                break;
            default:
                cout << "Invalid option." << endl << endl;
                break;
        }
    }
}

Town::~Town() {}
