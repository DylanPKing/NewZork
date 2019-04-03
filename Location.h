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
    const QVector <Item*> &itemsRef = items;
    QString getDescription();
    Location* getExit(QString);
    QString getExits();
    void setExits(Location*, Location*, Location*, Location*);
    void addItem(Item*);
    void removeItem(Item*);
    void addCharacter(Character);
    void operator+(Item*);
    void operator-(Item*);
};

#endif // LOCATION_H
