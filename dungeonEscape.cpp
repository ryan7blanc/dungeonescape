// CSCI1300 Fall 2022
// Author: Louis Blanc
// Recitation: 106 - Chanheum Park
// Project 3
#include "Inventory.h"
#include "Map.h"
#include "Merchant.h"
#include "Party.h"
#include "Player.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;

int split(string input_string, char separator, string arr[], int arr_size)
{
    int arr_count = 0;
    int separator_count = 0;
    int separate_times = 1;
    string string_length;

    for (int i = 0; i < input_string.length(); i++)
    {
        if (input_string[i] == separator)
        {
            arr[arr_count] = input_string.substr(separator_count, i - separator_count);
            separator_count = i + 1;
            arr_count++;
            separate_times++;
        }
        else if (i == input_string.length() - 1)
        {
            arr[arr_count] = input_string.substr(separator_count, input_string.length());
        }
    }


    if (arr_count == 0)
    {
        arr[0] = input_string;
        separate_times = 1;
    }
    if (input_string.length() == 0)
    {
        separate_times = 0;
    }
    else if (arr_count > arr_size || separate_times > arr_size)
    {
        separate_times = -1;
    }

    return separate_times;
}
/**
 * @brief takes in party, inventory, and monster level
 * based on each party member's weapon, a value is added to strength
 * two random numbers between 1 and 5 are generated 
 * taking all values and putting it into the function, we get a return value
 * if the value is over 0, return true(win)
 * 
 * @param partyvec 
 * @param inv 
 * @param chanllenge_num 
 * @return true 
 * @return false 
 */
bool battle_win(vector<Party> partyvec, Inventory inv, int challenge_num)
{
    int strength = 0;
    int rand1, rand2;
    int calc = 0;

    for (int i = 0; i < partyvec.size(); i++)
    {
        if (partyvec.at(i).getWeapon() == "Club" || partyvec.at(i).getWeapon() == "Spear")
        {
            strength++;
        }
        else if (partyvec.at(i).getWeapon() == "Rapier")
        {
            strength += 2;
        }
        else if (partyvec.at(i).getWeapon() == "Axe")
        {
            strength += 3;
        }
        else if (partyvec.at(i).getWeapon() == "Longsword")
        {
            strength += 4;
        }
    }

    srand(time(0));
    rand1 = random() % 5 + 1;
    rand2 = random() % 5 + 1;

    if (inv.getArmour() > 0)
    {
        calc = (rand1 * strength + 3) - (rand2 * challenge_num)/inv.getArmour();
    }

    if (calc > 0)
    {
        return true;
    }
    else 
        return false;
}
/**
 * @brief takes in string which must be "Boulder", "Shears", or "Parchment"
 * generates random number between 1 and 3, which will decide the NPC's choice
 * if the players wins, return true 
 * if the player loses, return false
 * if the player ties, add 1 to counter, generate new number for NPC choice
 * if counter reaches 3, player loses anyways
 * 
 * @param choice 
 * @return true 
 * @return false 
 */
bool door_puzzle(string choice)
{
    bool return_bool;
    int boolint = 0;

    if (choice != "Boulder" && choice != "Shears" && choice != "Parchment")
    {
        cout << "Invalid Input. You lose!" << endl;
        return_bool = false;
    }
    else
    {
        int counter = 0;
        while (boolint == 0)
        {
            int rand = random() % 3 + 1;
            if (counter == 3)
            {
                cout << "You went over 3 tries. You lose!" << endl;
                return_bool = false;
                boolint++;
            }
            else if (rand == 1)//Boulder
            {
                if (choice == "Shears")
                {
                    return_bool = false;
                    boolint++;
                }
                else if (choice == "Parchment")
                {
                    return_bool = true;
                    boolint++;
                }
            }
            else if (rand == 2)//Shears
            {
                if (choice == "Boulder")
                {
                    return_bool = true;
                    boolint++;
                }
                else if (choice == "Parchment")
                {
                    return_bool = false;
                    boolint++;
                }
            }
            else if (rand == 3)//Parchment
            {
                if (choice == "Boulder")
                {
                    return_bool = false;
                    boolint++;
                }
                else if (choice == "Shears")
                {
                    return_bool = true;
                    boolint++;
                }
            }
            else
            {
                cout << "It's a tie! Generating new choice." << endl;
                counter++;
            }
        }
    }

    return return_bool;
}
/**
 * @brief takes in user Inventory, party, as well as key_use boolean
 * generates randmon number which decides if a misfortune will occur
 * if it does occur, another random number will decide which misfortune occurs
 * if team is robbed, lose 10 ingredients or ingredients is set to 0 if you have less than 10
 * if cookware is robbed, 1 is taken off based off of rarity. if there is none in inventory, one if given by courtesy
 * if armour is robbed, random member loses armour. if they don't have armour nothing will happen
 * if weapon is robbed, a random party member is selected and their weapon is lost,\. if they don't have one nothing will happen.
 * if party member's fullness is selected, 10 fullness is dropped off of health.
 * if dungeon trap is selected, one party member is lost. if key boolean is false, nothing will happen
 * 
 * @param Inv 
 * @param partyvec 
 * @param key_use 
 * @return Inventory 
 */
Inventory misfortunes(Inventory Inv, vector<Party> partyvec, bool key_use)
{
    int randmis = random() % 10;
    if (randmis < 4)
    {
        int randwhat = random() % 10;

        if (randwhat < 3)
        {
            cout << "Oh no! Your team was robbed by dugeon bandits!" << endl;
            
            int randagain = random() % 3;

            if (randagain == 0)
            {
                if (Inv.getIngredients() - 10 < 0)
                {
                    cout << "You now have 0 ingredients" << endl;
                    Inv.setIngredients(0);
                }
                else
                {
                    cout << "You lost 10 kg of ingredients" << endl;
                    Inv.setIngredients(Inv.getIngredients() - 10);
                }
            }
            else if (randagain == 1)
            {
                if (Inv.getPot() >= 1)
                {
                    cout << "You lost a Ceramic Pot" << endl;
                    Inv.setPot(Inv.getPot() - 1);
                }
                else if (Inv.getPan() >= 1)
                {
                    cout << "You lost a Frying Pan" << endl;
                    Inv.setPan(Inv.getPan() - 1);
                }
                else if (Inv.getCauldron() >= 1)
                {
                    cout << "You lost a Cauldron" << endl;
                    Inv.setCauldron(Inv.getCauldron() - 1);
                }
                else
                {
                    cout << "The bandits were going to rob you, but you didn't have any cookware!" << endl;
                    cout << "Out of courtesy, they gave you a Ceramic Pot!" << endl;
                    Inv.setPot(Inv.getPot() + 1);
                    //if no cookware is in inventory, one is gifted by the bandits
                }
            }
            else if (randagain == 2)
            {
                int randarm = random() % partyvec.size();

                if (partyvec.at(randarm).getArmour() == true)
                {
                    cout << "Party member " << partyvec.at(randarm).getName() << " lost their armour!" << endl;
                    partyvec.at(randarm).setArmour();
                    Inv.setArmour(Inv.getArmour() - 1);
                }
                else
                {
                    //when randomly selected party member doesn't have armour, nothing happens
                    cout << "Party member " << partyvec.at(randarm).getName() << " got beaten up!" << endl;
                }
            }
        }
        else if (randwhat == 4)
        {
            int randwep = random() % partyvec.size();

            string wep = partyvec.at(randwep).getWeapon();
            //weapons are registered by string, so by using the getter we are able to compare weapons

            if (wep == "Club")
            {
                cout << "Party member " << partyvec.at(randwep).getName() << "'s Stone Club broke!" << endl;
                partyvec.at(randwep).setWeapon("");
                Inv.setClub(Inv.getClub() - 1);
            }
            else if (wep == "Spear")
            {
                cout << "Party member " << partyvec.at(randwep).getName() << "'s Iron Spear broke!" << endl;
                partyvec.at(randwep).setWeapon("");
                Inv.setSpear(Inv.getSpear() - 1);
            }
            else if (wep == "Rapier")
            {
                cout << "Party member " << partyvec.at(randwep).getName() << "'s +1 Mythril Rapier broke!" << endl;
                partyvec.at(randwep).setWeapon("");
                Inv.setRapier(Inv.getRapier() - 1);
            }
            else if (wep == "Axe")
            {
                cout << "Party member " << partyvec.at(randwep).getName() << "'s +2 Flaming Battle-Axe broke!" << endl;
                partyvec.at(randwep).setWeapon("");
                Inv.setAxe(Inv.getAxe() - 1); 
            }
            else if (wep == "Longsword")
            {
                cout << "Party member " << partyvec.at(randwep).getName() << "'s +3 Vorpal Longsword broke!" << endl;
                partyvec.at(randwep).setWeapon("");
                Inv.setLongsword(Inv.getLongsword() - 1); 
            }
            else
            {
                cout << "Party member " << partyvec.at(randwep).getName() << " has no weapon!" << endl;
            }
        }
        else if (randwhat > 4 && randwhat < 8)
        {
            int randpoi = random() % partyvec.size();
            cout << "Party member " << partyvec.at(randpoi).getName() << " lost 10 Fullness" << endl;
            partyvec.at(randpoi).setFullness(partyvec.at(randpoi).getFullness() - 10);
        }
        else if (randwhat > 7)
        {
            //if key is not used, nothing happens
            if (key_use == true)
            {
                int randp = random() % partyvec.size();

                cout << "Party member " << partyvec.at(randp).getName() << " got locked in the previous room. You must go on without them" << endl;
                partyvec.erase(partyvec.begin() + randp);
                cout << "Party size is now " << partyvec.size() << " members" << endl;

                key_use = false;
            }
        }
    }

    return Inv;
}
/**
 * @brief while loop which takes in user input and outputs menu based on input
 * if one category is selcted, it will show a variety of items that the user can purchase
 * when item is selected, the program asks the user to enter the amount of that item they would like to buy
 * if the user has enough of that amount, the transaction goes through
 * if the user doesn't have enough of that amount, a message will show up saying that they can't purchase it, taking them back to the main menu
 * 
 * @param Inv 
 * @param user_looper 
 * @param user_num 
 * @param user_char 
 * @param Merch 
 * @param partyvec 
 * @param store_weapon 
 * @return Inventory 
 */
Inventory merch_shop(Inventory Inv, string user_looper, int user_num, char user_char, Merchant Merch, vector<Party> partyvec, int store_weapon)
{
    do
    {
        Inv.displayInventory();

        cout << "Choose one of the following: " << endl;
        cout << "1. Ingredients: To make food, you have to cook raw ingredients." << endl;
        cout << "2. Cookware: You will need something to cook those ingredients." << endl;
        cout << "3. Weapons: It's dangerous to go alone, take this!" << endl;
        cout << "4. Armour: If you want to survive monster attacks, you will need some armor." << endl;
        cout << "5. Sell treasures: If you find anything shiny, I would be happy to take it off your hands." << endl;
        cout << "6. Leave: Make sure you get everything you need, I'm leaving after this sale!" << endl;

        cin >> user_looper;
        if (user_looper == "1")
        {
            cout << "How many kg of ingredients do you need [1 Gold/kg] (Enter 0 to cancel)" << endl;
            cin >> user_num;

            if (user_num > 0)
            {
                cout << "You want to buy " << user_num << " kg of ingredients for " << user_num << " Gold? (y/n)" << endl;
                cin >> user_char;

                if (user_char == 'y' && Inv.getGold() >= user_num)
                {
                    for (int i = 0; i < user_num; i++)
                    {
                        Inv = Merch.addIngredients(Inv);
                    }

                    cout << "Thanks! You want anything else?" << endl;
                }
                else if (user_char == 'n')
                {
                    cout << "Okay...(Why would you go through that hassel?)" << endl;
                }
                else if (user_char == 'y' && Inv.getGold() < user_num)
                {
                    cout << "You don't have enough gold for that!" << endl;
                }
                else 
                cout << "Please enter a valid input" << endl;
            }
            else
            cout << "Please enter a valid input" << endl;
        }
        else if (user_looper == "2")
        {
            cout << "I have a several types of cookware, which one would you like?" << endl;
            cout << "Each type has a different probability of breaking when used, marked with (XX%)." << endl;
            cout << endl;
            cout << "Choose one of the following:" << endl;
            cout << "1. (25%) Ceramic Pot [" << Merch.getPotPrice() << " Gold]" << endl;
            cout << "2. (10%) Frying Pan [" << Merch.getPanPrice() << " Gold]" << endl;
            cout << "3. ( 2%) Cauldron [" << Merch.getCauldronPrice() << " Gold]" << endl;
            cout << "4. Cancel" << endl;
            cin >> user_num;

            if (user_num == 1)
            {
                cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                cin >> user_num;

                cout << "You want to buy " << user_num << " Ceramic Pot(s) for " << Merch.getPotPrice() * user_num << " Gold? (y/n)" << endl;
                cin >> user_char;

                if (user_char == 'y' && Inv.getGold() >= Merch.getPotPrice() * user_num)
                {
                    for (int i = 0; i < user_num; i++)
                    {
                        Inv = Merch.addPot(Inv);
                    }

                    cout << "Thanks! You want anything else?" << endl;
                }
                else if (user_char == 'n')
                {
                    cout << "Okay...(Why would you go through that hassel?)" << endl;
                }
                else if (user_char == 'y' && Inv.getGold() < Merch.getPotPrice() * user_num)
                {
                    cout << "You don't have enough gold for that!" << endl;
                }
                else 
                cout << "Please enter a valid input" << endl;
            }
            else if (user_num == 2)
            {
                cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                cin >> user_num;

                cout << "You want to buy " << user_num << " Frying Pan(s) for " << Merch.getPanPrice() * user_num << " Gold? (y/n)" << endl;
                cin >> user_char;

                if (user_char == 'y' && Inv.getGold() >= Merch.getPanPrice() * user_num)
                {
                    for (int i = 0; i < user_num; i++)
                    {
                        Inv = Merch.addPan(Inv);
                    }

                    cout << "Thanks! You want anything else?" << endl;
                }
                else if (user_char == 'n')
                {
                    cout << "Okay...(Why would you go through that hassel?)" << endl;
                }
                else if (user_char == 'y' && Inv.getGold() < Merch.getPanPrice() * user_num)
                {
                    cout << "You don't have enough gold for that!" << endl;
                }
                else 
                cout << "Please enter a valid input" << endl;
            }
            else if (user_num == 3)
            {
                cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                cin >> user_num;

                cout << "You want to buy " << user_num << " Cauldron(s) for " << Merch.getCauldronPrice() * user_num << " Gold? (y/n)" << endl;
                cin >> user_char;

                if (user_char == 'y' && Inv.getGold() >= Merch.getCauldronPrice() * user_num)
                {
                    for (int i = 0; i < user_num; i++)
                    {
                        Inv = Merch.addCauldron(Inv);
                    }

                    cout << "Thanks! You want anything else?" << endl;
                }
                else if (user_char == 'n')
                {
                    cout << "Okay...(Why would you go through that hassel?)" << endl;
                }
                else if (user_char == 'y' && Inv.getGold() < Merch.getCauldronPrice() * user_num)
                {
                    cout << "You don't have enough gold for that!" << endl;
                }
                else 
                cout << "Please enter a valid input" << endl;
            }
            else if (user_num != 4)
            {
                cout << "Please enter a valid input" << endl;
            }
        }
        else if (user_looper == "3")
        {
            cout << "I have a plentiful collection of weapons to choose from. What would you like?" << endl;
            cout << "Note that some of them provide you a special bonus in combat, marker by (+X)." << endl;
            cout << endl;
            cout << "Choose one of the following:" << endl;
            cout << "1. Stone Club [" << Merch.getStonePrice() << " Gold]" << endl;
            cout << "2. Iron Spear [" << Merch.getIronPrice() << " Gold]" << endl;
            cout << "3. (+1) Mythril Rapier [" << Merch.getMythrilPrice() << " Gold]" << endl;
            cout << "4. (+2) Flaming Battle-Axe [" << Merch.getFlamingPrice() << " Gold]" << endl;
            cout << "5. (+3) Vorpal Longsword [" << Merch.getVorpalPrice() << " Gold]" << endl;
            cout << "6. Cancel" << endl;
            cin >> user_num;

            if (user_num == 1)
            {
                cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                cin >> user_num;

                cout << "You want to buy " << user_num << " Stone Club(s) for " << Merch.getStonePrice() * user_num << " Gold? (y/n)" << endl;
                cin >> user_char;

                if (user_char == 'y' && Inv.getGold() >= Merch.getStonePrice() * user_num)
                {
                    for (int i = 0; i < user_num; i++)
                    {
                        if (store_weapon < partyvec.size())//Assigns first 4 weapons purchased to party members
                        {
                            partyvec.at(store_weapon).setWeapon("Club");
                            store_weapon++;
                            Inv = Merch.addClub(Inv);
                        }
                        else
                        Inv = Merch.addClub(Inv);
                    }

                    cout << "Thanks! You want anything else?" << endl;
                }
                else if (user_char == 'y' && Inv.getGold() < Merch.getStonePrice() * user_num)
                {
                    cout << "You don't have enough gold for that!" << endl;
                }
                else if (user_char == 'n')
                {
                    cout << "Okay...(Why would you go through that hassel?)" << endl;
                }
                else 
                cout << "Please enter a valid input" << endl;
            }
            else if (user_num == 2)
            {
                cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                cin >> user_num;

                cout << "You want to buy " << user_num << " Iron Spear(s) for " << Merch.getIronPrice() * user_num << " Gold? (y/n)" << endl;
                cin >> user_char;

                if (user_char == 'y' && Inv.getGold() >= Merch.getIronPrice() * user_num)
                {
                    for (int i = 0; i < user_num; i++)
                    {
                        if (store_weapon < partyvec.size())
                        {
                            partyvec.at(store_weapon).setWeapon("Spear");
                            store_weapon++;
                            Inv = Merch.addSpear(Inv);
                        }
                        else
                        Inv = Merch.addSpear(Inv);
                    }

                    cout << "Thanks! You want anything else?" << endl;
                }
                else if (user_char == 'y' && Inv.getGold() < Merch.getIronPrice() * user_num)
                {
                    cout << "You don't have enough gold for that!" << endl;
                }
                else if (user_char == 'n')
                {
                    cout << "Okay...(Why would you go through that hassel?)" << endl;
                }
                else 
                cout << "Please enter a valid input" << endl;
            }
            else if (user_num == 3)
            {
                cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                cin >> user_num;

                cout << "You want to buy " << user_num << " (+1) Mythril Rapier(s) for " << Merch.getMythrilPrice() * user_num << " Gold? (y/n)" << endl;
                cin >> user_char;

                if (user_char == 'y' && Inv.getGold() >= Merch.getMythrilPrice() * user_num)
                {
                    for (int i = 0; i < user_num; i++)
                    {
                        if (store_weapon < partyvec.size())
                        {
                            partyvec.at(store_weapon).setWeapon("Rapier");
                            store_weapon++;
                            Inv = Merch.addRapier(Inv);
                        }
                        else
                        Inv = Merch.addRapier(Inv);
                    }

                    cout << "Thanks! You want anything else?" << endl;
                }
                else if (user_char == 'y' && Inv.getGold() < Merch.getMythrilPrice() * user_num)
                {
                    cout << "You don't have enough gold for that!" << endl;
                }
                else if (user_char == 'n')
                {
                    cout << "Okay...(Why would you go through that hassel?)" << endl;
                }
                else 
                cout << "Please enter a valid input" << endl;
            }
            else if (user_num == 4)
            {
                cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                cin >> user_num;

                cout << "You want to buy " << user_num << " (+2) Flaming Battle-Axe(s) for " << Merch.getFlamingPrice() * user_num << " Gold? (y/n)" << endl;
                cin >> user_char;

                if (user_char == 'y' && Inv.getGold() >= Merch.getFlamingPrice() * user_num)
                {
                    for (int i = 0; i < user_num; i++)
                    {
                        if (store_weapon < partyvec.size())
                        {
                            partyvec.at(store_weapon).setWeapon("Axe");
                            store_weapon++;
                            Inv = Merch.addAxe(Inv);
                        }
                        else
                        Inv = Merch.addAxe(Inv);
                    }

                    cout << "Thanks! You want anything else?" << endl;
                }
                else if (user_char == 'y' && Inv.getGold() < Merch.getFlamingPrice() * user_num)
                {
                    cout << "You don't have enough gold for that!" << endl;
                }
                else if (user_char == 'n')
                {
                    cout << "Okay...(Why would you go through that hassel?)" << endl;
                }
                else 
                cout << "Please enter a valid input" << endl;
            }
            else if (user_num == 5)
            {
                cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                cin >> user_num;

                cout << "You want to buy " << user_num << " (+3) Vorpal Longsword(s) for " << Merch.getVorpalPrice() * user_num << " Gold? (y/n)" << endl;
                cin >> user_char;

                if (user_char == 'y' && Inv.getGold() >= Merch.getVorpalPrice() * user_num)
                {
                    for (int i = 0; i < user_num; i++)
                    {
                        if (store_weapon < partyvec.size())
                        {
                            partyvec.at(store_weapon).setWeapon("Longsword");
                            store_weapon++;
                            Inv = Merch.addLongsword(Inv);
                        }
                        else
                        Inv = Merch.addLongsword(Inv);
                    }

                    cout << "Thanks! You want anything else?" << endl;
                }
                else if (user_char == 'y' && Inv.getGold() < Merch.getVorpalPrice() * user_num)
                {
                    cout << "You don't have enough gold for that!" << endl;
                }
                else if (user_char == 'n')
                {
                    cout << "Okay...(Why would you go through that hassel?)" << endl;
                }
                else 
                cout << "Please enter a valid input" << endl;
            }
            else if (user_num != 6)
            {
                cout << "Please enter a valid input" << endl;
            }
        }
        else if (user_looper == "4")
        {
            cout << "How many suits of armour can I get you? (Enter a positive integer, or 0 to cancel" << endl;
            cin >> user_num;

            cout << "You want to buy " << user_num << " suit(s) of armour for " << Merch.getArmourPrice() * user_num << "? (y/n)" << endl;
            cin >> user_char;

            if (user_char == 'y' && Inv.getGold() >= Merch.getArmourPrice() * user_num)
            {
                //first few armour purchase automatically attach onto the party members
                for (int i = 0; i < user_num; i++)
                {
                    if (i < partyvec.size())
                    {
                        if (partyvec.at(i).getArmour() == false)
                        {
                            partyvec.at(i).setArmour();
                        }
                    }
                    Inv = Merch.addArmour(Inv);
                }
                cout << "Thanks! You want anything else?" << endl;
            }
            else if (user_char == 'y' && Inv.getGold() < Merch.getArmourPrice() * user_num)
            {
                cout << "You don't have enough gold for that!" << endl;
            }
            else if (user_char == 'n')
            {
                cout << "Okay...(Why would you go through that hassel?)" << endl;
            }
            else 
            cout << "Please enter a valid input" << endl;
        }
        else if (user_looper == "5")
        {
            cout << "Which treasure would you like to sell?" << endl;
            cout << "1. Silver Ring [" << Merch.getRingPrice() << " Gold]" << endl;
            cout << "2. Ruby Necklace [" << Merch.getNecklacePrice() << " Gold]" << endl;
            cout << "3. Emerald Bracelet [" << Merch.getBraceletPrice() << " Gold]" << endl;
            cout << "4. Diamond Circlet [" << Merch.getCircletPrice() << " Gold]" << endl;
            cout << "5. Gem-encrusted Golbet [" << Merch.getGobletPrice() << " Gold]" << endl;
            cout << "6. Cancel" << endl;
            cin >> user_num;

            if (user_num == 1)
            {
                cout << "You have " << Inv.getRing() << " Silver Ring(s). How many would you like to sell?" << endl;
                cin >> user_num;

                if (user_num > Inv.getRing())
                {
                    cout << "You don't have enough Silver Rings for that" << endl;
                }
                else if (user_num <= Inv.getRing())
                {
                    cout << "You want to sell " << user_num << " Silver Rings for " << user_num * Merch.getRingPrice() << " Gold? (y/n)" << endl;
                    cin >> user_char;

                    if (user_char == 'y')
                    {
                        for (int i = 0; i < user_num; i++)
                        {
                            Inv = Merch.sellRing(Inv);
                        }
                    }
                    else if (user_char == 'n')
                    {

                        cout << "Okay...(Why would you go through that hassel?)" << endl;
                    }
                    else 
                        cout << "Please enter a valid input" << endl;
                }
            }
            else if (user_num == 2)
            {
                cout << "You have " << Inv.getNecklace() << " Ruby Necklace(s). How many would you like to sell?" << endl;
                cin >> user_num;

                if (user_num > Inv.getNecklace())
                {
                    cout << "You don't have enough Ruby Necklaces for that" << endl;
                }
                else if (user_num <= Inv.getNecklace())
                {
                    cout << "You want to sell " << user_num << " Ruby Necklaces for " << user_num * Merch.getNecklacePrice() << " Gold? (y/n)" << endl;
                    cin >> user_char;

                    if (user_char == 'y')
                    {
                        for (int i = 0; i < user_num; i++)
                        {
                            Inv = Merch.sellNecklace(Inv);
                        }
                    }
                    else if (user_char == 'n')
                    {

                        cout << "Okay...(Why would you go through that hassel?)" << endl;
                    }
                    else 
                        cout << "Please enter a valid input" << endl;
                }
            }
            else if (user_num == 3)
            {
                cout << "You have " << Inv.getBracelet() << " Emerald Bracelet(s). How many would you like to sell?" << endl;
                cin >> user_num;

                if (user_num > Inv.getBracelet())
                {
                    cout << "You don't have enough Emerald Bracelets for that" << endl;
                }
                else if (user_num <= Inv.getBracelet())
                {
                    cout << "You want to sell " << user_num << "Emerald Bracelets for " << user_num * Merch.getBraceletPrice() << " Gold? (y/n)" << endl;
                    cin >> user_char;

                    if (user_char == 'y')
                    {
                        for (int i = 0; i < user_num; i++)
                        {
                            Inv = Merch.sellBracelet(Inv);
                        }
                    }
                    else if (user_char == 'n')
                    {

                        cout << "Okay...(Why would you go through that hassel?)" << endl;
                    }
                    else 
                        cout << "Please enter a valid input" << endl;
                }
            }
            else if (user_num == 4)
            {
                cout << "You have " << Inv.getCirclet() << " Diamond Circlet(s). How many would you like to sell?" << endl;
                cin >> user_num;

                if (user_num > Inv.getCirclet())
                {
                    cout << "You don't have enough Diamond Circlets for that" << endl;
                }
                else if (user_num <= Inv.getCirclet())
                {
                    cout << "You want to sell " << user_num << " Diamond Circlets for " << user_num * Merch.getCircletPrice() << " Gold? (y/n)" << endl;
                    cin >> user_char;

                    if (user_char == 'y')
                    {
                        for (int i = 0; i < user_num; i++)
                        {
                            Inv = Merch.sellCirclet(Inv);
                        }
                    }
                    else if (user_char == 'n')
                    {

                        cout << "Okay...(Why would you go through that hassel?)" << endl;
                    }
                    else 
                        cout << "Please enter a valid input" << endl;
                }
            }
            else if (user_num == 5)
            {
                cout << "You have " << Inv.getGoblet() << " Gem-encrusted Goblet(s). How many would you like to sell?" << endl;
                cin >> user_num;

                if (user_num > Inv.getGoblet())
                {
                    cout << "You don't have enough Gem-encrusted Goblets for that" << endl;
                }
                else if (user_num <= Inv.getGoblet())
                {
                    cout << "You want to sell " << user_num << " Gem-encrusted Goblets for " << user_num * Merch.getGobletPrice() << " Gold? (y/n)" << endl;
                    cin >> user_char;

                    if (user_char == 'y')
                    {
                        for (int i = 0; i < user_num; i++)
                        {
                            Inv = Merch.sellGoblet(Inv);
                        }
                    }
                    else if (user_char == 'n')
                    {

                        cout << "Okay...(Why would you go through that hassel?)" << endl;
                    }
                    else 
                        cout << "Please enter a valid input" << endl;
                }
            }
            else if (user_num != 6)
            {
                cout << "Please enter a valid input" << endl;
            }
        }
        else
        {
            cout << "Please enter a valid input" << endl;
        }
    } while (user_looper != "6");

    return Inv;
}

int main()
{
    Player Ryan;
    Merchant Merch;
    Inventory Inv;
    Map myMap;
    vector<Party> partyvec;
    string user_input;
    string hold_monsters[2];
    string monsters[6][4];
    string hold_riddles[2];
    string riddles[2][20];
    string line;
    bool user_choice;
    int user_num;
    int user_loop;
    int explore_count = 0;
    int num_mon = 0;
    char user_char;
    int store_weapon = 0;
    bool key_use = false;
    bool win = false;
    bool lose = false;
    string user_looper;
    string user_numer;

    ifstream fin;
    ifstream bin;
    
    cout << "Welcome to Dungeon Escape - By Louis Ryan Blanc" << endl;
    cout << "Please enter your name: ";
    cin >> user_input;

    Ryan.setName(user_input);

    cout << "Hello " << Ryan.getName() << "!" << endl;
    
    for (int i = 0; i < 4; i++)
    {
        cout << "Please enter the name for Party Member #" << i + 1 << ":";
        cin >> user_input;

        Party member(user_input);
        partyvec.push_back(member);

        cout << "Hello " << partyvec.at(i).getName() << "!" << endl;
    }

    cout << "Now that we have a party, let's head over to the merchant!" << endl;
    cout << "I gave you 50 gold coins so you guys can get a start! Let's check out whats for sale!" << endl; 
    Inv = merch_shop(Inv, user_looper, user_num, user_char, Merch, partyvec, store_weapon);

    cout << "I guess I'll be heading off. Good luck on your adventure " << Ryan.getName() << "!" << endl;
    cout << endl;
    cout << "Now your journey begins! Use wasd to move yourself(X) around the map!" << endl;

    srand(time(0));
    int k = 0;
    //assigns space for room if true
    while (k < 5)
    {
        int rand_row = rand() % 12;
        int rand_column = rand() % 12;
        if (myMap.addRoom(rand_row, rand_column) == true)
        {
            k++;
        }
    }
    k = 0;
    //assigns space for NPC if true
    while (k < 5)
    {
        int rand_row = rand() % 12;
        int rand_column = rand() % 12;
        if (myMap.addNPC(rand_row, rand_column) == true)
        {
            k++;
        }
    }

    //read monsters
    fin.open("Monster.txt");
    int monster_level = 0;
    int i = 0, j = 0;
    while (getline(fin, line))
    {
        split(line, ',', hold_monsters, 2);
        monsters[i][j] = hold_monsters[0];
        j++;

        if (j == 4)
        {
            i++;
            j = 0;
        }
    }

    //read riddles
    bin.open("riddles.txt");
    int c = 0;
    while (getline(fin, line))
    {
        split(line, '~', hold_riddles, 2);
        riddles[0][c] = hold_riddles[0];
        riddles[1][c] = hold_riddles[1];
        c++;
    }


    while (Ryan.getAnger() != 100 && partyvec.size() != 0 && win == false && lose == false)
    {
        //since there will be so many cout statements with misfortunes and fights, before every map output we will be asking for a user input
        cout << "Enter any character to continue" << endl;
        cin >> user_input;
        Ryan.displayStatus();
        Inv.displayInventory();
        Ryan.displayParty(partyvec);
        myMap.displayMap();
        cout << "1. Move" << endl;
        cout << "2. Investigate" << endl;
        cout << "3. Pick a Fight" << endl;
        cout << "4. Cook and Eat" << endl;
        cout << "5. Give up" << endl;
        cin >> user_numer;
        
        if (user_numer == "1")
        {
            cout << "Enter W,A,S, or D" << endl;
            cin >> user_char;
            myMap.move(user_char);

            if(myMap.isDungeonExit(myMap.getPlayerRow(),myMap.getPlayerCol()) == true)
            {
                if (Ryan.getRooms() < 5)
                {
                    cout << "You need to complete the other rooms to exit" << endl;
                }
                else
                {
                    cout << "You have completed all of the rooms and can challenge the Sorcerer" << endl;
                    cout << "You enter the room, but it is empty" << endl;
                    cout << "You look at your party members, and they are all giving you an unpleasant smile" << endl;
                    cout << "Sorcerer: Welcome to my lair, traveler " << Ryan.getName() << endl;
                    cout << "Your party members begin to melt, slowly grouping together!" << endl;
                    cout << "They turn into the Sorcerer!" << endl;
                    cout << "Sorcerer: Young traveler, you've come a far way, so before I destroy you let me give you a chance" << endl;
                    cout << "Sorcerer: Solve me this question, and I shall let you and your party go" << endl;
                    cout << "What is the first name of the author of Dungeon Escape?" << endl;
                    cin >> user_input;

                    if (user_input == "Louis")
                    {
                        cout << "Sorcerer: Good job traveler, I shall let you go" << endl;
                        cout << "A bright light shines within the room, bringing your party members back to life!" << endl;
                        cout << "Another door opens to the outside world! You win!" << endl;
                        win = true;
                    }
                    else
                    {
                        cout << "Sorcerer: Stupdi traveler! It says it right at the start of the game!" << endl;
                        cout << "The Sorcerer used dark magic, causing everything in the room to turn into darkness..." << endl;
                        cout << "You lose" << endl;
                        lose = true;
                    }

                }
            }

            if (myMap.isRoomLocation(myMap.getPlayerRow(), myMap.getPlayerCol()) == true)
            {
                cout << "You found a room! Let's enter it!" << endl;
                if (Ryan.getKeys() > 0)
                {
                    cout << "Would you like a key to unlock this room? (y/n)" << endl;
                    cin >> user_char;

                    if (user_char == 'y')
                    {
                        Ryan.minusKeys();
                        key_use = true;
                    }
                    else if (user_char == 'n')
                    {
                        cout << "Okay then, you will need to complete a puzzle instead" << endl;
                        cout << "Type in 'Boulder', 'Shears', or 'Parchment'. (If anything else is typed you automatically lose)" << endl;
                        cin >> user_input;
                        user_choice = door_puzzle(user_input);

                        if (user_choice == false)
                        {
                            int rand = random() % partyvec.size();
                            cout << "Party member " << partyvec.at(rand).getName() << " was slain by magic." << endl;
                            partyvec.erase(partyvec.begin() + rand);
                        }
                        else
                        {
                            cout << "You win!" << endl;
                            cout << "Now you are able to fight the monster!" << endl;
                        }
                    }
                    else
                    cout << "Please enter a valid input" << endl;
                }
                else
                {
                    cout << "You don't have any keys to unlock this room, so you must complete a puzzle to enter" << endl;
                    cout << "Type in 'Boulder', 'Shears', or 'Parchment'. (If anything else is typed you automatically lose)" << endl;
                    cin >> user_input;
                    user_choice = door_puzzle(user_input);

                    if (user_choice == false)
                    {
                        cout << "You lost" << endl;
                        int rand = random() % partyvec.size();
                        cout << "Party member " << partyvec.at(rand).getName() << " was slain by magic." << endl;
                        partyvec.erase(partyvec.begin() + rand);
                    }
                    else if (user_choice == true)
                    {
                        cout << "You win!" << endl;
                        cout << "Now you are able to fight the monster!" << endl;
                    }
                }

                int randmon = random() % 4;
                cout << "A " << monsters[monster_level][randmon] << " appeared!" << endl;
                cout << "Would you like to fight the monster? (y/n)" << endl;
                cin >> user_char;

                if (user_char == 'y')
                {
                    cout << "Computing battle score..." << endl;
                    bool win = battle_win(partyvec, Inv, monster_level);

                    if (win == true)
                    {
                        num_mon++;
                        cout << "You beat the " << monsters[monster_level][randmon] << "!" << endl;
                        Ryan.plusRooms();
                        monster_level++;
                        int key_drop = random() % 10;
                        Inv.setGold(Inv.getGold() + 10);
                        cout << "You got 10 Gold!" << endl;
                        Inv.setIngredients(Inv.getIngredients() + 5);
                        cout << "You got 5 Ingredients!" << endl;

                        if (key_drop == 1)
                        {
                            cout << "The monster dropped a key!" << endl;
                            Ryan.plusKeys();
                        }

                        myMap.removeRoom(myMap.getPlayerRow(), myMap.getPlayerCol());
                    }
                    else if (win == false)
                    {
                        cout << "You lost against " << monsters[monster_level][randmon] << endl;
                        int ing_lost = random() % 30;
                        Inv.setGold(Inv.getGold() * 3/4);
                        cout << "You lost some Gold" << endl;

                        if ((Inv.getIngredients() - ing_lost) >= 0)
                        {
                            Inv.setIngredients(Inv.getIngredients() - ing_lost);
                            cout << "You lost " << ing_lost << " Ingredients" << endl;
                        }
                        else
                        {
                            cout << "You have 0 Ingredients" << endl;
                            Inv.setIngredients(0);
                        }

                        for (int i = 0; i < partyvec.size(); i++)
                        {
                            int randnum;
                            if (partyvec.at(i).getArmour() == true)
                            {
                                randnum = random() % 20;
                                if (randnum == 1)
                                {
                                    cout << "Party Member " << partyvec.at(i).getName() << " has been slain!" << endl; 
                                    partyvec.erase(partyvec.begin() + i);
                                }
                            }
                            else
                            {
                                randnum = random() % 10;
                                if (randnum == 1)
                                {
                                    cout << "Party Member " << partyvec.at(i).getName() << " has been slain!" << endl; 
                                    partyvec.erase(partyvec.begin() + i);
                                }
                            }
                        }
                    }
                    Inv = misfortunes(Inv, partyvec, key_use);
                }
                else if (user_char == 'n')
                {
                    int randsur = random() % partyvec.size();
                    cout << "You were able to escape, but party member " << partyvec.at(randsur).getName() << " got held captive" << endl;
                    partyvec.erase(partyvec.begin() + randsur);
                }
                else
                {
                    cout << "Invalid Input" << endl;
                }

                Ryan.plusAnger();
            }
            else if (myMap.isNPCLocation(myMap.getPlayerRow(), myMap.getPlayerCol()) == true)
            {
                cout << "Would you like to speak to the NPC? (y/n)" << endl;
                cin >> user_char;

                if (user_char == 'n')
                {
                    for (int i = 0; i < partyvec.size(); i++)
                    {
                        int rand = random() % 5;

                        if (rand == 1)
                        {
                            cout << "Party member " << partyvec.at(i).getName() << " lost 1 health point."<< endl;
                            partyvec.at(i).setFullness(partyvec.at(i).getFullness() - 1);
                        }
                    }
                }
                else if (user_char == 'y')
                {
                    int rand = random() % 20;
                    cout << "NPC: Hey there traveller! Solve this riddle to buy some items!" << endl;
                    cout << riddles[0][rand] << endl;
                    cin >> user_input;

                    if (user_input == riddles[1][rand])
                    {
                        cout << "NPC: Correct! Go ahead and check out my shop." << endl;
                        Inv = merch_shop(Inv, user_looper, user_num, user_char, Merch, partyvec, store_weapon);

                        cout << "The price of each item has increased by 25%" << endl;
                        //function increases price for every availible item by using x = x + x * 0.25
                        Merch.upPrice();

                        misfortunes(Inv, partyvec, key_use);
                    }
                    else
                    {
                        rand = random() % 4;
                        cout << "NPC: Incorrect... Sorry" << endl;
                        cout << "The NPC turned into a " << monsters[monster_level][rand] << endl;
                        user_choice = battle_win(partyvec, Inv, monster_level);

                        if (user_choice == false)
                        {
                            cout << "You lost the battle against " << monsters[monster_level][rand] << endl;

                            int ing_lost = random() % 30;
                            Inv.setGold(Inv.getGold() * 3/4);
                            if ((Inv.getIngredients() - ing_lost) >= 0)
                            {
                                Inv.setIngredients(Inv.getIngredients() - ing_lost);
                            }
                            else
                            {
                                cout << "You have 0 Ingredients" << endl;
                                Inv.setIngredients(0);
                            }

                            for (int i = 0; i < partyvec.size(); i++)
                            {
                                int randnum;
                                if (partyvec.at(i).getArmour() == true)
                                {
                                    randnum = random() % 20;
                                    if (randnum == 1)
                                    {
                                        cout << "Party Member " << partyvec.at(i).getName() << " has been slain!" << endl; 
                                        partyvec.erase(partyvec.begin() + i);
                                    }
                                }
                                else
                                {
                                    randnum = random() % 10;
                                    if (randnum == 1)
                                    {
                                        cout << "Party Member " << partyvec.at(i).getName() << " has been slain!" << endl; 
                                        partyvec.erase(partyvec.begin() + i);
                                    }
                                }
                            }
                        }
                        else
                        {
                            num_mon++;
                            cout << "You won the battle against " << monsters[monster_level][rand] << "!" << endl;
                            int randkey = random() % 10; 

                            if (randkey == 1)
                            {
                                cout << "The monster dropped a key!" << endl;
                                Ryan.plusKeys();
                            }
                        }
                    }
                    myMap.removeNPC(myMap.getPlayerRow(), myMap.getPlayerCol());
                }
                Ryan.plusAnger();
            } 
            //20% chance of dropping fullness by 1
            for (int i = 0; i < partyvec.size(); i++)
            {
                int randomon = random() % 5;
                if (randomon == 1)
                {
                    cout << partyvec.at(i).getName() << "'s fullness dropped by one point." << endl;
                    partyvec.at(i).setFullness(partyvec.at(i).getFullness() - 1);
                }
            }
        }
        else if (user_numer == "2")
        {
            if (myMap.isExplored(myMap.getPlayerRow(), myMap.getPlayerCol()) == true)
            {
                cout << "This space has already been explored." << endl;
            }
            else
            {
                int randchance = random() % 10;

                if (randchance == 0)
                {
                    cout << "You found a key!" << endl;
                    Ryan.plusKeys();

                    for (int i = 0; i < partyvec.size(); i++)
                    {
                        int rand = random() % 2;

                        if (rand == 0)
                        {
                            cout << partyvec.at(i).getName() << " lost 1 Fullness" << endl;
                            partyvec.at(i).setFullness(partyvec.at(i).getFullness() - 1);
                        }
                    }
                }
                else if (randchance > 0 && randchance < 3)
                {
                    if (Ryan.getRooms() == 0)
                    {
                        cout << "There was no treasure to be found" << endl;
                    }
                    else if (Ryan.getRooms() == 1)
                    {
                        cout << "You found a Silver Ring!" << endl;
                        Inv.setRing(Inv.getRing() + 1);
                    }
                    else if (Ryan.getRooms() == 2)
                    {
                        cout << "You found a Ruby Necklace!" << endl;
                        Inv.setNecklace(Inv.getNecklace() + 1);
                    }
                    else if (Ryan.getRooms() == 3)
                    {
                        cout << "You found an Emerald Bracelet!" << endl;
                        Inv.setBracelet(Inv.getBracelet() + 1);
                    }
                    else if (Ryan.getRooms() == 4)
                    {
                        cout << "You found a Diamond Circlet!" << endl;
                        Inv.setCirclet(Inv.getCirclet() + 1);
                    }
                    else if (Ryan.getRooms() == 5)
                    {
                        cout << "You found a Gem-encrusted Goblet!" << endl;
                        Inv.setGoblet(Inv.getGoblet() + 1);
                    }

                    for (int i = 0; i < partyvec.size(); i++)
                    {
                        int rand = random() % 2;

                        if (rand == 0)
                        {
                            cout << partyvec.at(i).getName() << " lost 1 Fullness" << endl;
                            partyvec.at(i).setFullness(partyvec.at(i).getFullness() - 1);
                        }
                    }
                }
                else if (randchance >= 3 && randchance < 5)
                {
                    int randmon = random() % 4;
                    cout << "A " << monsters[monster_level][randmon] << " appeared!" << endl;
                    cout << "Computing battle score..." << endl;

                    bool win = battle_win(partyvec, Inv, monster_level);

                    if (win == true)
                    {
                        num_mon++;
                        cout << "You beat the " << monsters[monster_level][randmon] << "!" << endl;
                        int key_drop = random() % 10;
                        Inv.setGold(Inv.getGold() + 10);
                        cout << "You got 10 Gold!" << endl;
                        Inv.setIngredients(Inv.getIngredients() + 5);
                        cout << "You got 5 Ingredients!" << endl;

                        if (key_drop == 1)
                        {
                            cout << "The monster dropped a key!" << endl;
                            Ryan.plusKeys();
                        }
                    }
                    else
                    {
                        cout << "You lost against " << monsters[monster_level][randmon] << endl;
                        int ing_lost = random() % 30;
                        Inv.setGold(Inv.getGold() * 3/4);
                        cout << "You lost some Gold" << endl;
                        if ((Inv.getIngredients() - ing_lost) >= 0)
                        {
                            Inv.setIngredients(Inv.getIngredients() - ing_lost);
                            cout << "You lost " << ing_lost << " Ingredients" << endl;
                        }
                        else
                        {
                            cout << "You have 0 Ingredients" << endl;
                            Inv.setIngredients(0);
                        }

                        for (int i = 0; i < partyvec.size(); i++)
                        {
                            int randnum;
                            if (partyvec.at(i).getArmour() == true)
                            {
                                randnum = random() % 20;
                                if (randnum == 1)
                                {
                                    cout << "Party Member " << partyvec.at(i).getName() << " has been slain!" << endl; 
                                    partyvec.erase(partyvec.begin() + i);
                                }
                            }
                            else
                            {
                                randnum = random() % 10;
                                if (randnum == 1)
                                {
                                    cout << "Party Member " << partyvec.at(i).getName() << " has been slain!" << endl; 
                                    partyvec.erase(partyvec.begin() + i);
                                }
                            }
                        }
                    }
                }
                else
                {
                    cout << "There was nothing to be found..." << endl;
                }
                //at the end of the exploration, sets explored to true
                explore_count++;
                myMap.exploreSpace(myMap.getPlayerRow(), myMap.getPlayerCol());

                Inv = misfortunes(Inv, partyvec, key_use);
            }

            Ryan.plusAnger();
        }
        else if (user_numer == "3")
        {
            int randmon = random() % 4;
            cout << "A " << monsters[monster_level][randmon] << " appeared!" << endl;
            cout << "Computing battle score..." << endl;

            bool win = battle_win(partyvec, Inv, monster_level);

            if (win == true)
            {
                num_mon++;
                cout << "You beat the " << monsters[monster_level][randmon] << "!" << endl;
                int key_drop = random() % 10;
                Inv.setGold(Inv.getGold() + 10);
                cout << "You got 10 Gold!" << endl;
                Inv.setIngredients(Inv.getIngredients() + 5);
                cout << "You got 5 Ingredients!" << endl;

                if (key_drop == 1)
                {
                    cout << "The monster dropped a key!" << endl;
                    Ryan.plusKeys();
                }
            }
            else
            {
                cout << "You lost against " << monsters[monster_level][randmon] << endl;
                int ing_lost = random() % 30;
                Inv.setGold(Inv.getGold() * 3/4);
                cout << "You lost some Gold" << endl;
                if ((Inv.getIngredients() - ing_lost) >= 0)
                {
                    Inv.setIngredients(Inv.getIngredients() - ing_lost);
                    cout << "You lost " << ing_lost << " Ingredients" << endl;
                }
                else
                {
                    cout << "You have 0 Ingredients" << endl;
                    Inv.setIngredients(0);
                }

                for (int i = 0; i < partyvec.size(); i++)
                {
                    int randnum;
                    if (partyvec.at(i).getArmour() == true)
                    {
                        randnum = random() % 20;
                        if (randnum == 1)
                        {
                            cout << "Party Member " << partyvec.at(i).getName() << " has been slain!" << endl; 
                            partyvec.erase(partyvec.begin() + i);
                        }
                    }
                    else
                    {
                        randnum = random() % 10;
                        if (randnum == 1)
                        {
                            cout << "Party Member " << partyvec.at(i).getName() << " has been slain!" << endl; 
                            partyvec.erase(partyvec.begin() + i);
                        }
                    }
                }
            }

            Inv = misfortunes(Inv, partyvec, key_use);
        }
        else if (user_numer == "4")
        {
            if (Inv.getIngredients() < 5)
            {
                cout << "You don't have enough Ingredients for that" << endl;
            }
            else
            {
                cout << "What type of cookware would you like to use?" << endl;
                cout << "1. Ceramic Pot" << endl;
                cout << "2. Frying Pan" << endl;
                cout << "3. Cauldron" << endl;
                cin >> user_num;

                if (user_num == 1)
                {
                    if (Inv.getPot() < 1)
                    {
                        cout << "You don't have any Ceramic Pots" << endl;
                    }
                    else
                    {
                        cout << "How many meals would you like to make? (1 meal = 5 Ingredients)" << endl;
                        cin >> user_num;

                        if (user_num * 5 > Inv.getIngredients())
                        {
                            cout << "You don't have enough ingredients to make that" << endl;
                        }
                        else if (user_num * 5 <= Inv.getIngredients())
                        {
                            cout << user_num << " meals coming right up!" << endl;
                            Inv.setPot(Inv.getPot() - 1);
                            Inv.setIngredients(Inv.getIngredients() - user_num * 5);

                            int randcook = random() % 4;

                            if (randcook == 1)
                            {
                                cout << "Your Ceramic Pot broke while cooking and all of your Ingredients went to waste" << endl;
                            }
                            else
                            {
                                cout << "Your meals have been cooked successfully!" << endl;
                                for (int i = 0; i < partyvec.size(); i++)
                                {
                                    partyvec.at(i).setFullness(partyvec.at(i).getFullness() + user_num);
                                    cout << partyvec.at(i).getName() << " gained " << user_num << " fullness!" << endl;
                                }
                            }
                        }
                        else
                        {
                            cout << "Invalid Input" << endl;
                        }
                    }
                }
                else if (user_num == 2)
                {
                    if (Inv.getPan() < 1)
                    {
                        cout << "You don't have any Frying Pans" << endl;
                    }
                    else
                    {
                        cout << "How many meals would you like to make? (1 meal = 5 Ingredients)" << endl;
                        cin >> user_num;

                        if (user_num * 5 > Inv.getIngredients())
                        {
                            cout << "You don't have enough ingredients to make that" << endl;
                        }
                        else if (user_num * 5 <= Inv.getIngredients())
                        {
                            cout << user_num << " meals coming right up!" << endl;
                            Inv.setPan(Inv.getPan() - 1);
                            Inv.setIngredients(Inv.getIngredients() - user_num * 5);

                            int randcook = random() % 10;

                            if (randcook == 1)
                            {
                                cout << "Your Frying Pan broke while cooking and all of your Ingredients went to waste" << endl;
                            }
                            else
                            {
                                cout << "Your meals have been cooked successfully!" << endl;
                                for (int i = 0; i < partyvec.size(); i++)
                                {
                                    partyvec.at(i).setFullness(partyvec.at(i).getFullness() + user_num);
                                    cout << partyvec.at(i).getName() << " gained " << user_num << " fullness!" << endl;
                                }
                            }
                        }
                        else
                        {
                            cout << "Invalid Input" << endl;
                        }
                    }
                }
                else if (user_num == 3)
                {
                    if (Inv.getCauldron() < 1)
                    {
                        cout << "You don't have any Cauldrons" << endl;
                    }
                    else
                    {
                        cout << "How many meals would you like to make? (1 meal = 5 Ingredients)" << endl;
                        cin >> user_num;

                        if (user_num * 5 > Inv.getIngredients())
                        {
                            cout << "You don't have enough ingredients to make that" << endl;
                        }
                        else if (user_num * 5 <= Inv.getIngredients())
                        {
                            cout << user_num << " meals coming right up!" << endl;
                            Inv.setCauldron(Inv.getCauldron() - 1);
                            Inv.setIngredients(Inv.getIngredients() - user_num * 5);

                            int randcook = random() % 50;

                            if (randcook == 1)
                            {
                                cout << "Your Cauldron broke while cooking and all of your Ingredients went to waste" << endl;
                            }
                            else
                            {
                                cout << "Your meals have been cooked successfully!" << endl;
                                for (int i = 0; i < partyvec.size(); i++)
                                {
                                    partyvec.at(i).setFullness(partyvec.at(i).getFullness() + user_num);
                                    cout << partyvec.at(i).getName() << " gained " << user_num << " fullness!" << endl;
                                }
                            }
                        }
                        else
                        {
                            cout << "Invalid Input" << endl;
                        }
                    }
                }
                else
                {
                    cout << "Invalid Input" << endl;
                }
                
                Inv = misfortunes(Inv, partyvec, key_use);
            }

            Ryan.plusAnger();
        }
        else if (user_numer != "5")
        {
            cout << "Invalid Input" << endl;
        }
        else
        {
            cout << "You lose! Thanks for trying" << endl;
            return 0;
        }

        //checks if any member is dead first, then checks for any member with fullness lower than 10
        for (int i = 0; i < partyvec.size(); i++)
        {
            if (partyvec.at(i).getFullness() < 1)
            {
                cout << "Party member " << partyvec.at(i).getName() << " starved to death. They are no longer in your party" << endl;
                partyvec.erase(partyvec.begin() + i);
                cout << "Party size is now " << partyvec.size() << " members" << endl;
            }
            else if (partyvec.at(i).getFullness() < 10)
            {
                cout << "Party member " << partyvec.at(i).getName() << "'s Fullness is low. Eat something before they die!" << endl;
            }
        }
    }

    if (Ryan.getAnger() >= 100)
    {
        cout << "The Sorcerer's Anger reached a 100. You lose!" << endl;
        cout << "You had " << partyvec.size() << " party members left" << endl;
    }
    else if (partyvec.size() < 1)
    {
        cout << "All of your party member's died. You lose!" << endl;
    }
    else if (win == true)
    {
        cout << "Winner: " << Ryan.getName() << endl;
        cout << "Remaining Party Members: ";
        for (int i = 0; i < partyvec.size(); i++)
        {
            cout << partyvec.at(i).getName() << " ";
        }
        cout << endl;
        cout << "Number of rooms cleared: " << Ryan.getRooms() << endl;
        Inv.displayInventory();
        cout << "Number of spaces explored: " << explore_count << endl;
        cout << "Number of turns elapsed: " << Ryan.getAnger() << endl;
    }
    
    return 0;
}