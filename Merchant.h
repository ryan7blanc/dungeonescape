#ifndef Merchant_H
#define Merchant_H

#include "Inventory.h"

class Merchant: private Inventory
{
    private:
    int ingredients_price_;
    int pot_price_, pan_price_, cauldron_price_;
    int stone_price_, iron_price_, mythril_price_, flaming_price_, vorpal_price_;
    int armour_price_;
    int ring_price_, necklace_price_, bracelet_price_, circlet_price_, goblet_price_;

    public:
    Merchant();

    //getters
    int getIngredientsPrice();
    int getPotPrice();
    int getPanPrice();
    int getCauldronPrice();
    int getStonePrice();
    int getIronPrice();
    int getMythrilPrice();
    int getFlamingPrice();
    int getVorpalPrice();
    int getArmourPrice();
    int getRingPrice();
    int getNecklacePrice();
    int getBraceletPrice();
    int getCircletPrice();
    int getGobletPrice();

    //setters
    void setIngredientsPrice(int price);
    void setPotPrice(int price);
    void setPanPrice(int price);
    void setCauldronPrice(int price);
    void setStonePrice(int price);
    void setIronPrice(int price);
    void setMythrilPrice(int price);
    void setFlamingPrice(int price);
    void setVorpalPrice(int price);
    void setArmourPrice(int price);
    void setRingPrice(int price);
    void setNecklacePrice(int price);
    void setBraceletPrice(int price);
    void setCircletPrice(int price);
    void setGobletPrice(int price);

    //when purchased, also subtracts Gold in inventory when called
    Inventory addIngredients(Inventory inv);
    Inventory addPot(Inventory inv);
    Inventory addPan(Inventory inv);
    Inventory addCauldron(Inventory inv);
    Inventory addClub(Inventory inv);
    Inventory addSpear(Inventory inv);
    Inventory addRapier(Inventory inv);
    Inventory addAxe(Inventory inv);
    Inventory addLongsword(Inventory inv);
    Inventory addArmour(Inventory inv);

    Inventory sellRing(Inventory inv);
    Inventory sellNecklace(Inventory inv);
    Inventory sellBracelet(Inventory inv);
    Inventory sellCirclet(Inventory inv);
    Inventory sellGoblet(Inventory inv);

    void upPrice();

};

#endif