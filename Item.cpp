#include "Item.h"

/**
 * @brief Item::Item
 * @param name
 * @param description
 * @param isWeapon
 * @param atk
 * @param weight
 */
Item::Item(QString name, QString description, bool isWeapon, float atk, int weight)
    : name(name)
    , description(description)
    , isWeapon(isWeapon)
    , isEquipped(false)
    , atk(atk)
    , weight(weight)
{}

/**
 * @brief Item::getIsWeapon
 * @return
 */
bool Item::getIsWeapon()
{
    return isWeapon;
}

/**
 * @brief Item::getIsEquipped
 * @return
 */
bool Item::getIsEquipped()
{
    return isEquipped;
}

/**
 * @brief Item::setIsEquipped
 * @param isEquipped
 */
void Item::setIsEquipped(bool isEquipped)
{
    this->isEquipped = isEquipped;
}

/**
 * @brief Item::getAtk
 * @return
 */
float Item::getAtk()
{
    return atk;
}

/**
 * @brief Item::getWeight
 * @return
 */
int Item::getWeight()
{
    return weight;
}
