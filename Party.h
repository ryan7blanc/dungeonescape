#ifndef Party_H
#define Party_H

#include <iostream>
#include <vector>

using namespace std;

class Party
{
    private:
    string name_;
    int fullness_;
    bool armour_;
    string weapon_;

    public:
    Party();
    Party(string name);

    //getters
    string getName();
    int getFullness();
    bool getArmour();
    string getWeapon();

    //setters
    void setName(string name);
    void setFullness(int fullness);
    void setArmour();
    void setWeapon(string weapon);

    void displayParty(vector<Party> partyvec);
    //if I make party into a vector, we can display using a for loop
};

#endif