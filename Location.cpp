#include "Location.h"

/**
 * @brief Location::Location
 * @param name
 */
Location::Location(QString name)
    : name(name)
{}

/**
 * @brief Location::getItemList
 * @return
 */
QString Location::getItemList()
{
    if (items.size() > 0)
    {
        QString out = "The items here are:\n";
        for (int i = 0; i < items.size(); ++i)
            out += items.at(i)->getName() + "\n";
        return out;
    }
    return "There's nothing in here...";
}

/**
 * @brief Location::getDescription
 * @return
 */
QString Location::getDescription()
{
    QString out = "Name:\t";
    out += name + "\nExits:\t" + getExits() + "\nItems:\n" + getItemList();
    return out;
}

/**
 * @brief Location::getExit
 * @param direction
 * @return
 */
Location* Location::getExit(QString direction)
{
    Location *loc = this;
    QChar dir = direction.front().toLower();
    if (exits[dir] != nullptr)
        loc = exits[dir];
    return loc;
}

QString Location::getExits()
{
    QString out = "";
    for (QMap<QChar, Location*>::iterator i = exits.begin(); i != exits.end(); ++i)
        out += (*i)->getName() + (i != exits.end() - 1 ? ", " : "");
    return out;
}
/**
 * @brief Location::setExits
 * @param nPtr
 * @param sPtr
 * @param ePtr
 * @param wPtr
 */
void Location::setExits(Location *nPtr, Location *sPtr, Location *ePtr, Location *wPtr)
{
    if (nPtr != nullptr)
        exits['n'] = nPtr;
    if (sPtr != nullptr)
        exits['s'] = sPtr;
    if (ePtr != nullptr)
        exits['e'] = ePtr;
    if (wPtr != nullptr)
        exits['w'] = wPtr;
}

/**
 * @brief Location::addItem
 * @param newItemPtr
 */
void Location::addItem(Item *newItemPtr)
{
    items.push_back(newItemPtr);
}

/**
 * @brief Location::removeItem
 * @param oldItemPtr
 */
void Location::removeItem(Item *oldItemPtr)
{
    items.remove(items.indexOf(oldItemPtr));
}

