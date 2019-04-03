#ifndef CHARACTER_H
#define CHARACTER_H

#include <QVector>
#include <QMap>
#include <QString>

#include "Item.h"

class Character
{
private:
    QString name;
    float hp;
    int weightLimit;
    int currentWeight;
    QVector <Item*> inventory;
    QMap <QString, Item*> activeItems;
    void replaceActiveItem(QString, Item*);
    static QVector <QString> validEquipAreas;
    static void isThereEquipAreas();
    static void loadEquipAreas();

public:
    Character(QString);
    Character(QString, float);
    Character(QString, float, int);
    const QString &nameRef = name;
    const float &hpRef = hp;
    const int &weightLimitRef = weightLimit;
    const int &currentWeightRef = currentWeight;
    const QVector <Item*> &inventoryRef = inventory;
    int updateCurrentWeight(int);
    void setHP(float hp);
    void updateWeightLimit(int);
    void takeItem(Item*);
    void giveItem(Item*);
    void deleteItem(Item*);
    void equipItem(QString, Item*);
    bool exceedWeightLimit(int);
    QString showInventory();
    QString showStatus();
};

#endif // CHARACTER_H
