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
    const int &weightLimitRef = weightLimit;
    const int &currentWeightRef = currentWeight;
    int updateCurrentWeight(int);
    void updateWeightLimit(int);
    void takeItem(Item*);
    void giveItem(Item*);
    void deleteItem(Item*);
    void equipItem(QString, Item*);
    bool exceedWeightLimit(int);
    QString showInventory();
};

#endif // CHARACTER_H
