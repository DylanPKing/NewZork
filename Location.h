#ifndef LOCATION_H
#define LOCATION_H

#include <QChar>
#include <QString>
#include <QMap>
#include <QVector>

#include "Character.h"
#include "Item.h"

class Location
{
private:
    QString name;
    QMap <QChar, Location*> exits;
    QVector <Character> characters;
    QVector <Item*> items;

public:
    Location(QString);
    inline QString getName() { return name; }
    QString getItemList();
    QString getDescription();
    Location* getExit(QString);
    void setExits(Location*, Location*, Location*, Location*);
    void addItem(Item*);
    void removeItem(Item*);
    void addCharacter(Character);
};

#endif // LOCATION_H
