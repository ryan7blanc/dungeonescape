#ifndef Inventory_H
#define Inventory_H

class Inventory
{
    private:
    int gold_;
    int ingredients_;
    int pot_, frying_pan_, cauldron_;
    int stone_club_, iron_spear_, mythril_rapier_, flaming_battle_axe_, vorpal_longsword_;
    int armour_;
    int ring_, necklace_, bracelet_, circlet_, goblet_;

    public:
    Inventory();

    //getters
    int getGold();
    int getIngredients();
    int getPot();
    int getPan();
    int getCauldron();
    int getClub();
    int getSpear();
    int getRapier();
    int getAxe();
    int getLongsword();
    int getArmour();
    int getRing();
    int getNecklace();
    int getBracelet();
    int getCirclet();
    int getGoblet();

    //setters
    void setGold(int gold);
    void setIngredients(int ingredients);
    void setPot(int pot);
    void setPan(int pan);
    void setCauldron(int cauldron);
    void setClub(int club);
    void setSpear(int spear);
    void setRapier(int rapier);
    void setAxe(int axe);
    void setLongsword(int longsword);
    void setArmour(int armour);
    void setRing(int ring);
    void setNecklace(int necklace);
    void setBracelet(int bracelet);
    void setCirclet(int circlet);
    void setGoblet(int goblet);

    //other
    void displayInventory();
};

#endif
