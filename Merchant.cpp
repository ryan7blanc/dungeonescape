#include "Merchant.h"
#include <iostream>

using namespace std;

Merchant::Merchant()
{
    ingredients_price_ = 1;
    pot_price_ = 2, pan_price_ = 10, cauldron_price_ = 20;
    stone_price_ = 2, iron_price_ = 2, mythril_price_ = 5, flaming_price_ = 15, vorpal_price_ = 50;
    armour_price_ = 5;
    ring_price_ = 10, necklace_price_ = 20, bracelet_price_ = 30, circlet_price_ = 40, goblet_price_ = 50;
}

int Merchant::getIngredientsPrice()
{
    return ingredients_price_;
}
int Merchant::getPotPrice()
{
    return pot_price_;
}
int Merchant::getPanPrice()
{
    return pan_price_;
}
int Merchant::getCauldronPrice()
{
    return cauldron_price_;
}
int Merchant::getStonePrice()
{
    return stone_price_;
}
int Merchant::getIronPrice()
{
    return iron_price_;
}
int Merchant::getMythrilPrice()
{
    return mythril_price_;
}
int Merchant::getFlamingPrice()
{
    return flaming_price_;
}
int Merchant::getVorpalPrice()
{
    return vorpal_price_;
}
int Merchant::getArmourPrice()
{
    return armour_price_;
}
int Merchant::getRingPrice()
{
    return ring_price_;
}
int Merchant::getNecklacePrice()
{
    return necklace_price_;
}
int Merchant::getBraceletPrice()
{
    return bracelet_price_;
}
int Merchant::getCircletPrice()
{
    return circlet_price_;
}
int Merchant::getGobletPrice()
{
    return goblet_price_;
}

void Merchant::setIngredientsPrice(int price)
{
    ingredients_price_ = price;
}
void Merchant::setPotPrice(int price)
{
    pot_price_ = price;
}
void Merchant::setPanPrice(int price)
{
    pan_price_ = price;
}
void Merchant::setCauldronPrice(int price)
{
    cauldron_price_ = price;
}
void Merchant::setStonePrice(int price)
{
    stone_price_ = price;
}
void Merchant::setIronPrice(int price)
{
    iron_price_ = price;
}
void Merchant::setMythrilPrice(int price)
{
    mythril_price_ = price;
}
void Merchant::setFlamingPrice(int price)
{
    flaming_price_ = price;
}
void Merchant::setVorpalPrice(int price)
{
    vorpal_price_ = price;
}
void Merchant::setArmourPrice(int price)
{
    armour_price_ = price;
}
void Merchant::setRingPrice(int price)
{
    ring_price_ = price;
}
void Merchant::setNecklacePrice(int price)
{
    necklace_price_ = price;
}
void Merchant::setBraceletPrice(int price)
{
    bracelet_price_ = price;
}
void Merchant::setCircletPrice(int price)
{
    circlet_price_ = price;
}
void Merchant::setGobletPrice(int price)
{
    goblet_price_ = price;
}


Inventory Merchant::addIngredients(Inventory inv)
{
    int gold = inv.getGold();
    gold = gold - ingredients_price_;
    inv.setGold(gold);

    int ingredients = inv.getIngredients();
    ingredients++;
    inv.setIngredients(ingredients);
    return inv;
}
Inventory Merchant::addPot(Inventory inv)
{
    int gold = inv.getGold();
    gold = gold - pot_price_;
    inv.setGold(gold);

    int pot = inv.getPot();
    pot++;
    inv.setPot(pot);
    return inv;
}
Inventory Merchant::addPan(Inventory inv)
{
    int gold = inv.getGold();
    gold = gold - pan_price_;
    inv.setGold(gold);

    int pan = inv.getPan();
    pan++;
    inv.setPan(pan);
    return inv;
}
Inventory Merchant::addCauldron(Inventory inv)
{
    int gold = inv.getGold();
    gold = gold - cauldron_price_;
    inv.setGold(gold);

    int cauldron = inv.getCauldron();
    cauldron++;
    inv.setCauldron(cauldron);
    return inv;
}
Inventory Merchant::addClub(Inventory inv)
{
    int gold = inv.getGold();
    gold = gold - stone_price_;
    inv.setGold(gold);

    int club = inv.getClub();
    club++;
    inv.setClub(club);
    return inv;
}
Inventory Merchant::addSpear(Inventory inv)
{
    int gold = inv.getGold();
    gold = gold - iron_price_;
    inv.setGold(gold);

    int spear = inv.getSpear();
    spear++;
    inv.setSpear(spear);
    return inv;
}
Inventory Merchant::addRapier(Inventory inv)
{
    int gold = inv.getGold();
    gold = gold - mythril_price_;
    inv.setGold(gold);

    int rapier = inv.getRapier();
    rapier++;
    inv.setRapier(rapier);
    return inv;
}
Inventory Merchant::addAxe(Inventory inv)
{
    int gold = inv.getGold();
    gold = gold - flaming_price_;
    inv.setGold(gold);

    int axe = inv.getAxe();
    axe++;
    inv.setAxe(axe);
    return inv;
}
Inventory Merchant::addLongsword(Inventory inv)
{
    int gold = inv.getGold();
    gold = gold - vorpal_price_;
    inv.setGold(gold);

    int longsword = inv.getLongsword();
    longsword++;
    inv.setLongsword(longsword);
    return inv;
}
Inventory Merchant::addArmour(Inventory inv)
{
    //since armour is bool what should i do.
    //subtract one from armour when booling to party member
    //can make function where you can have extra armour in inventory for open space
    if (inv.getArmour() < 5)
    {
        int gold = inv.getGold();
        gold = gold - armour_price_;
        inv.setGold(gold);

        int armour = inv.getArmour();
        armour++;
        inv.setArmour(armour);
    }
    else 
    {
        cout << "You have too much armour, try equipping it to your party members!" << endl;
    }

    return inv;
}

Inventory Merchant::sellRing(Inventory inv)
{
    int gold = inv.getGold();
    gold = gold + ring_price_;
    inv.setGold(gold);

    int ring = inv.getRing();
    ring--;
    inv.setRing(ring);
    return inv;
}
Inventory Merchant::sellNecklace(Inventory inv)
{
    int gold = inv.getGold();
    gold = gold + necklace_price_;
    inv.setGold(gold);

    int necklace = inv.getNecklace();
    necklace--;
    inv.setNecklace(necklace);
    return inv;
}
Inventory Merchant::sellBracelet(Inventory inv)
{
    int gold = inv.getGold();
    gold = gold + bracelet_price_;
    inv.setGold(gold);

    int bracelet = inv.getBracelet();
    bracelet--;
    inv.setBracelet(bracelet);
    return inv;
}
Inventory Merchant::sellCirclet(Inventory inv)
{
    int gold = inv.getGold();
    gold = gold + circlet_price_;
    inv.setGold(gold);

    int circlet = inv.getCirclet();
    circlet--;
    inv.setCirclet(circlet);
    return inv;
}
Inventory Merchant::sellGoblet(Inventory inv)
{
    int gold = inv.getGold();
    gold = gold + goblet_price_;
    inv.setGold(gold);

    int goblet = inv.getGoblet();
    goblet--;
    inv.setGoblet(goblet);
    return inv;
}

void Merchant::upPrice()
{
    ingredients_price_ = ingredients_price_ + ingredients_price_ * 0.25;
    pot_price_ = pot_price_ + pot_price_ * 0.25, pan_price_ = pan_price_ + pan_price_ * 0.25, cauldron_price_ = cauldron_price_ + cauldron_price_ * 0.25;
    stone_price_ = stone_price_ + stone_price_ * 0.25, iron_price_ = iron_price_ + iron_price_ * 0.25, mythril_price_ = mythril_price_ + mythril_price_ * 0.25, flaming_price_ = flaming_price_ + flaming_price_ * 0.25, vorpal_price_ = vorpal_price_ + vorpal_price_ * 0.25;
    armour_price_ = armour_price_ + armour_price_ * 0.25;
    ring_price_ = ring_price_ + ring_price_ * 0.25, necklace_price_ = necklace_price_ + necklace_price_ * 0.25, bracelet_price_ = bracelet_price_ + bracelet_price_ * 0.25, circlet_price_ = circlet_price_ + circlet_price_ * 0.25, goblet_price_ = goblet_price_ + goblet_price_ * 0.25;
}