#ifndef ZORKCORE_H
#define ZORKCORE_H

#include "Character.h"
#include "Command.h"
#include "Item.h"
#include "Weapon.h"
#include "Location.h"

class ZorkCore
{
private:
    Location* currentLoc;
    Character playerCharacter;
    QVector <Location*> locations;
    bool processCommand(Command);
    void createLocations();
    void go(QString);
    void printWelcome();
    void teleport();
public:
    ZorkCore();
    void play();
};

#endif // ZORKCORE_H
