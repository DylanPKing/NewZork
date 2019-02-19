#include "Item.h"

/**
 * @brief Item::Item
 * @param name
 * @param description
 * @param isWeapon
 * @param atk
 * @param weight
 */
Item::Item(QString name, QString description, int weight)
    : name(name)
    , description(description)
    , weight(weight)
{}
