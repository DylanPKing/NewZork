#ifndef ITEM_H
#define ITEM_H

#include <QString>

class Item
{
private:
    QString name;
    QString description;
    bool isWeapon;
    bool isEquipped;
    float atk;
    int weight;

public:
    Item(QString, QString, bool, float, int);
    const QString &nameRef = name;
    const QString &descriptionRef = description;
    bool getIsWeapon();
    bool getIsEquipped();
    void setIsEquipped(bool isEquipped);
    float getAtk();
    int getWeight();
};

#endif // ITEM_H
