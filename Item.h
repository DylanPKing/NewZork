#ifndef ITEM_H
#define ITEM_H

#include <QString>

class Item
{
private:
    QString name;
    QString description;
    int weight;

public:
    Item(QString, QString, int);
    inline QString getName() { return name; }
    inline QString getDescription() { return description; }
    inline int getWeight() { return weight; }
};

#endif // ITEM_H
