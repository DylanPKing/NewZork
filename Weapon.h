#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"

class Weapon : public Item
{
private:
    int atk;
    int def;
    bool equipped;

public:
    Weapon(QString, QString, int, int, int);
    inline int getAtk() { return atk; }
    inline void setAtk(int atk) { this->atk = atk; }
    inline int getDef() { return def; }
    inline void setDef(int def) { this->def = def;}
    inline bool getEquipped() { return equipped; }
    inline void setEquipped(bool equipped) { this->equipped = equipped; }
};

#endif // WEAPON_H
