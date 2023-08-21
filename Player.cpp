#include "Player.h"
#include <iostream>

using namespace std;

Player::Player()
{
    rooms_cleared_ = 0;
    keys_ = 0;
    anger_level_ = 0;
    party_count_ = 1;
}

void Player::displayStatus()
{
    cout << "+-------------+" << endl;
    cout << "| STATUS      |" << endl;
    cout << "+-------------+" << endl;
    cout << "| Rooms Cleared: " << getRooms() << "| Keys: " << getKeys() << " | Anger Level: " << getAnger() << endl;
}

int Player::getRooms()
{
    return rooms_cleared_;
}
int Player::getKeys()
{
    return keys_;
}
int Player::getAnger()
{
    return anger_level_;
}
int Player::getParty()
{
    return party_count_;
}

void Player::setRooms(int rooms)
{
    rooms_cleared_ = rooms;
}
void Player::setKeys(int keys)
{
    keys_ = keys;
}
void Player::setAnger(int anger)
{
    anger_level_ = anger;
}
void Player::setParty(int count)
{
    party_count_ = count;
}

void Player::plusRooms()
{
    rooms_cleared_++;
}
void Player::plusKeys()
{
    keys_++;
}
void Player::plusAnger()
{
    anger_level_++;
}
void Player::plusParty()
{
    party_count_++;
}

void Player::minusKeys()
{
    keys_--;
}
void Player::minusParty()
{
    party_count_--;
}