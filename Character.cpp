#include <QTextStream>

#include "Character.h"
#include "Location.h"
#include "Item.h"

/**
 * @brief Static Vector of all valid equip areas.
 *
 * All the valid equip areas for weapins, shields, armour
 */
QVector <QString> Character::validEquipAreas;

/**
 * @brief Constructs a basic character, usually NPC.
 *
 * @param name
 *
 */
Character::Character(QString name) :
    name(name),
    hp(100.0),
    weightLimit(100),
    currentWeight(0)
{
    isThereEquipAreas();
}

/**
 * @brief Constructs a character with set HP.
 *
 * Constructs a character with a given HP, useful for enemies
 * @param name
 * @param hp
 */
Character::Character(QString name, float hp) :
    name(name),
    hp(hp),
    weightLimit(100),
    currentWeight(0)
{
    isThereEquipAreas();
}

/**
 * @brief Constructs a character with all relevant variables.
 *
 * Constructs a character with full customisability. Used for Player character
 * and Bosses.
 * @param name
 * @param hp
 * @param weightLimit
 */
Character::Character(QString name, float hp, int weightLimit) :
    name(name),
    hp(hp),
    weightLimit(weightLimit),
    currentWeight(0)

{
    isThereEquipAreas();
}

/**
 * @brief Increases or decreases current weight of a character.
 *
 * CHecks if the updated weight exceeds the characters weight limit.
 * @param extraWeight
 * @return -1 if it fails, new weight if it succeeds.
 */
int Character::updateCurrentWeight(int extraWeight)
{
    if (exceedWeightLimit(extraWeight))
        return -1;
    currentWeight += extraWeight;
    return currentWeight;
}

/**
 * @brief Increases or decreases the weight limit of the character.
 *
 * @param extraWeight
 */
void Character::updateWeightLimit(int extraWeight)
{
    weightLimit += extraWeight;
}

/**
 * @brief Transfers an Item to the characters inventory.
 *
 * Checks if the weight of the item exceeds weight limit,
 * and adds the item if it does not
 * @param newItemPtr
 */
void Character::takeItem(Item *newItemPtr)
{
    if (updateCurrentWeight(newItemPtr->getWeight()) != -1)
        inventory.push_back(newItemPtr);
}

/**
 * @brief Character::giveItem
 * @param oldItemPtr
 */
void Character::giveItem(Item *oldItemPtr)
{
    inventory.remove(inventory.indexOf(oldItemPtr));
    updateCurrentWeight(oldItemPtr->getWeight() * -1);
}

/**
 * @brief Character::deleteItem
 * @param oldItemPtr
 */
void Character::deleteItem(Item *oldItemPtr)
{
    if (inventory.contains(oldItemPtr))
    {
        inventory.remove(inventory.indexOf(oldItemPtr));
        updateCurrentWeight(oldItemPtr->getWeight() * -1);
        delete oldItemPtr;
    }
}

/**
 * @brief Character::equipItem
 * @param equipArea
 * @param itemToEquip
 */
void Character::equipItem(QString equipArea, Item *itemToEquip)
{
    if (validEquipAreas.contains(equipArea) && inventory.contains(itemToEquip))
    {
        if (activeItems[equipArea] != nullptr)
        {
            replaceActiveItem(equipArea, itemToEquip);
            return;
        }
        activeItems[equipArea] = itemToEquip;
        inventory.remove(inventory.indexOf(itemToEquip));
    }
}

/**
 * @brief Character::replaceActiveItem
 * @param equipArea
 * @param itemToEquipPtr
 */
void Character::replaceActiveItem(QString equipArea, Item *itemToEquipPtr)
{
    QTextStream out(stdout);
    out << activeItems[equipArea]->getName() << "is already equipped here." << endl
        << "Do you want to replace it?\t[Y/n]" << endl;
    bool validInput = false;
    QTextStream in(stdin);
    while (!validInput)
    {
        QString userResponse = in.readLine();
        if (userResponse.compare("Y") == 0 || userResponse.compare("y") == 0)
        {
            Item *temp = itemToEquipPtr;
            inventory.replace(inventory.indexOf(itemToEquipPtr), activeItems[equipArea]);
            activeItems[equipArea] = temp;
            validInput = true;
        }
        else if (userResponse.compare("N") == 0 || userResponse.compare("n") == 0)
            validInput = true;
    }
}

/**
 * @brief Character::exceedWeightLimit
 * @param extraWeight
 * @return
 */
bool Character::exceedWeightLimit(int extraWeight)
{
    return (currentWeight + extraWeight) > weightLimit;
}

/**
 * @brief Character::isThereEquipAreas
 */
void Character::isThereEquipAreas()
{
    if (validEquipAreas.empty())
        loadEquipAreas();
}

/**
 * @brief Character::loadEquipAreas
 */
void Character::loadEquipAreas()
{
    validEquipAreas.push_back("Head");
    validEquipAreas.push_back("Shoulders");
    validEquipAreas.push_back("LeftHand");
    validEquipAreas.push_back("RightHand");
    validEquipAreas.push_back("Top");
    validEquipAreas.push_back("Legs");
    validEquipAreas.push_back("Feet");
}

/**
 * @brief Character::showInventory
 * @return
 */
QString Character::showInventory()
{
    QString out = "";
    for (int i = 0; i < inventory.size(); ++i)
        out += inventory[i]->getName() + ((i % 6 == 0) ? "\n" : "");
    return out;
}

QString Character::showStatus()
{
    QString out = "Name:\t" + nameRef + "\n" + "Health:\t" + QString::number(hpRef) + "\n"
                + "Current carrying weight:\t" + QString::number(currentWeightRef) + "\n"
                + "Carrying weight limit:\t" + QString::number(weightLimitRef);
    return out;
}
