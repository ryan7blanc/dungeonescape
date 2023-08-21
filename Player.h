#ifndef Player_H
#define Player_H

#include <iostream>
#include <vector>
#include "Party.h"

using namespace std;

class Player: public Party
{
    private:
    int rooms_cleared_;
    int keys_;
    int anger_level_;
    int party_count_;

    public:
    Player();

    //getters
    int getRooms();
    int getKeys();
    int getAnger();
    int getParty();

    //setters //won't really be used since these factors will only increase by 1 after turns
    void setRooms(int rooms);
    void setKeys(int keys);
    void setAnger(int anger);
    void setParty(int count);

    //increasers
    void plusRooms();
    void plusKeys();
    void plusAnger();
    void plusParty();

    //decreasers
    void minusKeys();//when key is used
    void minusParty();//when party member dies

    void displayStatus();
};

#endif