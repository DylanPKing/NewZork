#include "weapon.h"

Weapon::Weapon(QString name, QString description, int weight, int atk, int def) :
    Item(name, description, weight),
    atk(atk),
    def(def),
    equipped(false)
{}
