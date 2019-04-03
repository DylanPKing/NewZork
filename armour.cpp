#include "armour.h"

Armour::Armour(QString name, QString description, int weight, int def) :
    Item(name, description, weight),
    def(def),
    equipped(false)
{}
