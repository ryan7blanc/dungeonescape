#include "Party.h"
#include <iostream>
#include <vector>

using namespace std;

Party::Party()
{
    name_ = "";
    fullness_ = 0;
    armour_ = false;
    weapon_ = "";
}

Party::Party(string name)
{
    name_ = name;
    fullness_ = 50;
    armour_ = false;
    weapon_ = "";
}

string Party::getName()
{
    return name_;
}
int Party::getFullness()
{
    return fullness_;
}
bool Party::getArmour()
{
    return armour_;
}
string Party::getWeapon()
{
    return weapon_;
}

void Party::setName(string name)
{
    name_ = name;
}
void Party::setFullness(int fullness)
{
    fullness_ = fullness;
}
void Party::setArmour()//switches armour using bool, can use one function for multiple situations
{
    if (armour_ == false)
    {
        armour_ = true;
    }
    else if (armour_ == true)
    {
        armour_ = false;
    }
}
void Party::setWeapon(string weapon)
{
    weapon_ = weapon;
}

void Party::displayParty(vector<Party> partyvec)
{
    cout << "+-------------+" << endl;
    cout << "| PARTY       |" << endl;
    cout << "+-------------+" << endl;

    for (int i = 0; i < partyvec.size(); i++)
    {
        cout << "| " << partyvec.at(i).getName() << " | Fullness: " << partyvec.at(i).getFullness() << endl;
    }
    
    cout << "+-------------+" << endl;
}