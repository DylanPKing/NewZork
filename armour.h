#ifndef ARMOUR_H
#define ARMOUR_H

#include "Item.h"

class Armour : public Item
{
private:
    int def;
    bool equipped;

public:
    Armour(QString, QString, int, int);
    inline int getDef() { return def; }
    inline void setDef(int def) { this->def = def; }
    inline bool getEquipped() { return equipped; }
    inline void setEquipped(bool equipped) { this->equipped = equipped; }
};

#endif // ARMOUR_H
