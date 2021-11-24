#include "town.hpp"

Town::Town(Player* player) {
    this->player = player;
}

void Town::buy(){
    cout << "Welcome to the town" << endl;
    cout << "What would you like to purchase?" << endl << endl;
    int response = 0;
    while(response != 4) {

        cout << "1: Armor" << endl
        << "2: Weapon" << endl
        << "3: Potion" << endl 
        << "4: Exit" << endl;

        cout << "Your current balance is " << this->player->get_money() << endl;

        cin >> response;

        int response2 = 0;
        switch (response)
        {
            case 1: //armor
                while(response2 != 6) {
                    cout << "What Armor would you like?"<< endl 
                    << "1. ByteArmor [15 credits] | +5 defense" << endl
                    << "2. KiloArmor [30 credits] | +10 defense" << endl
                    << "3. MegaArmor [60 credits] | +15 defense" << endl
                    << "4. GigaArmor [120 credits] +20 defense" << endl
                    << "5. TeraArmor {240 credits] | +25 defense" << endl
                    << "6. Back" << endl;

                    cin >> response2;
                    
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
                            cout << "Invalid option." << endl << endl;
                            break;
                    }
                }

                response2 = 0;
                break;

            case 2: //weapon
                while(response2 != 6) {
                    cout << "What Weapon would you like?" << endl 
                    << "1. ByteWeapon [15 credits] | +5 attack" << endl
                    << "2. KiloWeapon [30 credits] | +10 attack" << endl
                    << "3. MegaWeapon [60 credits] | +15 attack" << endl
                    << "4. GigaWeapon [120 credits] | +20 attack" << endl
                    << "5. TeraWeapon [240 credits] | +25 attack" << endl
                    << "6. Back" << endl;

                    cin >> response2;

                    switch(response2) {
                        case 1:
                            this->buyConfirmation(new ByteWeapon(), ByteArmor().get_sell_price());
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
                            cout << "Invalid option." << endl << endl;
                            break;
                    }
                }

                response2 = 0;
                break;

            case 3: //potion
                
                while(response2 != 2) {
                    cout << "What Potion would you like?" << endl 
                    << "1. Health Potion" << endl
                    << "2. Back" << endl;

                    cin >> response2;

                    switch(response2) {
                        case 1:
                            this->buyConfirmation(new HealthPotion(), HealthPotion().get_sell_price());
                            break;
                        case 2:
                            break;
                        default:
                            cout << "Invalid option." << endl << endl;
                            break;
                    }
                }

                response2 = 0;
                break;

            case 4: //exit
                cout << "Thanks for shopping." << endl;
                break;

            default:
                cout << "Invalid option." << endl << endl;
                break;
        }
    }
 }

void Town::sell() //TODO
{ 
    int response = 0;
}

void Town::buyConfirmation(Item *item, int price) {

    int response = 0;

    while(response != 1 && response != 2) {
        cout << "Are you sure you want to purchase " << item->get_name() << " for " << price << " credits?" << endl;
        cout << "1: Yes" << endl;
        cout << "2: No" << endl;
        cin >> response;
        switch(response) {
            case 1:
                this->player->add_item(item, price);
                break;
            case 2:
                cout << "Item purchase cancelled." << endl;
                break;
            default:
                cout << "Invalid option." << endl << endl;
                break;
        }
    }
}

Town::~Town() {}