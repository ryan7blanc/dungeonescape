#include "Inventory.h"
#include <iostream>

using namespace std;

Inventory::Inventory()
{
    gold_ = 50;
    ingredients_ = 0;
    pot_ = 0, frying_pan_ = 0, cauldron_ = 0;
    stone_club_ = 0, iron_spear_ = 0, mythril_rapier_ = 0, flaming_battle_axe_ = 0, vorpal_longsword_ = 0;
    armour_ = 0;
    ring_ = 0, necklace_ = 0, bracelet_ = 0, circlet_ = 0, goblet_ = 0;
}

int Inventory::getGold()
{
    return gold_;
}
int Inventory::getIngredients()
{
    return ingredients_;
}
int Inventory::getPot()
{
    return pot_;
}
int Inventory::getPan()
{
    return frying_pan_;
}
int Inventory::getCauldron()
{
    return cauldron_;
}
int Inventory::getClub()
{
    return stone_club_;
}
int Inventory::getSpear()
{
    return iron_spear_;
}
int Inventory::getRapier()
{
    return mythril_rapier_;
}
int Inventory::getAxe()
{
    return flaming_battle_axe_;
}
int Inventory::getLongsword()
{
    return vorpal_longsword_;
}
int Inventory::getArmour()
{
    return armour_;
}
int Inventory::getRing()
{
    return ring_;
}
int Inventory::getNecklace()
{
    return necklace_;
}
int Inventory::getBracelet()
{
    return bracelet_;
}
int Inventory::getCirclet()
{
    return circlet_;
}
int Inventory::getGoblet()
{
    return goblet_;
}

void Inventory::setGold(int gold)
{
    gold_ = gold;
}
void Inventory::setIngredients(int ingredients)
{
    ingredients_ = ingredients;
}
void Inventory::setPot(int pot)
{
    pot_ = pot;
}
void Inventory::setPan(int frying_pan)
{
    frying_pan_ = frying_pan;
}
void Inventory::setCauldron(int cauldron)
{
    cauldron_ = cauldron;
}
void Inventory::setClub(int club)
{
    stone_club_ = club;
}
void Inventory::setSpear(int spear)
{
    iron_spear_ = spear;
}
void Inventory::setRapier(int rapier)
{
    mythril_rapier_ = rapier;
}
void Inventory::setAxe(int axe)
{
    flaming_battle_axe_ = axe;
}
void Inventory::setLongsword(int longsword)
{
    vorpal_longsword_ = longsword;
}
void Inventory::setArmour(int armour)
{
    armour_ = armour;
}
void Inventory::setRing(int ring)
{
    ring_ = ring;
}
void Inventory::setNecklace(int necklace)
{
    necklace_ = necklace;
}
void Inventory::setBracelet(int bracelet)
{
    bracelet_ = bracelet;
}
void Inventory::setCirclet(int circlet)
{
    circlet_ = circlet;
}
void Inventory::setGoblet(int goblet)
{
    goblet_ = goblet;
}

void Inventory::displayInventory()
{
    cout << "+-------------+" << endl;
    cout << "| INVENTORY   |" << endl;
    cout << "+-------------+" << endl;
    cout << "| Gold        | " << getGold() << endl;
    cout << "| Ingredients | " << getIngredients() << " kg" << endl;
    cout << "| Cookware    | P: " << getPot() << " | F: " << getPan() << " | C: " << getCauldron() << endl;
    cout << "| Weapons     | C: " << getClub() << " | S: " << getSpear() << " | R: " << getRapier() << " | B: " << getAxe() << " | L: " << getLongsword() << endl;
    cout << "| Armor       | " << getArmour() << endl;
    cout << "| Treasures   | R: " << getRing() << " | N: " << getNecklace() << " | B: " << getBracelet() << " | C: " << getCirclet() << " | G: " << getGoblet() << endl;
}