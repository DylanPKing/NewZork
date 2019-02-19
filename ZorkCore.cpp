#include <QTextStream>

#include <time.h>

#include "ZorkCore.h"

/**
 * @brief ZorkCore::ZorkCore
 */
ZorkCore::ZorkCore()
    : playerCharacter("Player")
{
    createLocations();
    srand(time(nullptr));
}

/**
 * @brief ZorkCore::teleport
 */
void ZorkCore::teleport()
{

    bool valid = false;
    while (!valid)
    {
        Location* newLoc = locations.at(rand() % locations.size());
        if (currentLoc->getName().compare(newLoc->getName()) != 0)
        {
            QTextStream out(stdout);
            valid = true;
            currentLoc = newLoc;
            out << currentLoc->getDescription() << endl;
        }
    }
}

/**
 * @brief ZorkCore::processCommand
 * @param in
 * @return
 */
bool ZorkCore::processCommand(Command in)
{
    QTextStream out(stdout);
    if (!in.isValidCommand())
        out << "The fuck are you trying to do?" << endl;
    else if (in.commandWordRef.compare("info") == 0 && !in.hasSecondWord())
        out << "Valid commands are:\n" << in.listValidCommands() << endl;
    else if (in.commandWordRef.compare("go") == 0 && in.hasSecondWord())
    {
        Location *here = currentLoc;
        currentLoc = currentLoc->getExit(in.secondWordRef);
        if (here->getName().compare(currentLoc->getName()) == 0)
            out << "You cant go that direction.." << endl;
        else
            out << currentLoc->getDescription() << endl;
    }
    else if (in.commandWordRef.compare("teleport") == 0 && !in.hasSecondWord())
    {
        out << "You are teleporting to a new room..." << endl;
        teleport();
    }
    else if (in.commandWordRef.compare("quit") == 0 && !in.hasSecondWord())
        return true;
    return false;
}

/**
 * @brief ZorkCore::createLocations
 */
void ZorkCore::createLocations()
{
    Location *aPtr, *bPtr, *cPtr, *dPtr, *ePtr, *fPtr, *gPtr, *hPtr, *iPtr, *jPtr;

    aPtr = new Location("a");
    bPtr = new Location("b");
    cPtr = new Location("c");
    dPtr = new Location("d");
    ePtr = new Location("e");
    fPtr = new Location("f");
    gPtr = new Location("g");
    hPtr = new Location("h");
    iPtr = new Location("i");
    jPtr = new Location("j");

    aPtr->setExits(nullptr, nullptr, bPtr, nullptr);
    bPtr->setExits(nullptr, ePtr, cPtr, aPtr);
    cPtr->setExits(nullptr, nullptr, nullptr, bPtr);
    dPtr->setExits(nullptr, nullptr, ePtr, nullptr);
    ePtr->setExits(bPtr, hPtr, fPtr, dPtr);
    fPtr->setExits(nullptr, nullptr, nullptr, ePtr);
    gPtr->setExits(nullptr, jPtr, hPtr, nullptr);
    hPtr->setExits(ePtr, nullptr, iPtr, gPtr);
    iPtr->setExits(nullptr, nullptr, nullptr, hPtr);
    jPtr->setExits(gPtr, nullptr, nullptr, nullptr);

    locations.push_back(aPtr);
    locations.push_back(bPtr);
    locations.push_back(cPtr);
    locations.push_back(dPtr);
    locations.push_back(ePtr);
    locations.push_back(fPtr);
    locations.push_back(gPtr);
    locations.push_back(hPtr);
    locations.push_back(iPtr);
    locations.push_back(jPtr);

    ePtr->addItem(new Weapon("Sword", "A simple sword.", 15, 20, 1));

    currentLoc = ePtr;
}

/**
 * @brief ZorkCore::printWelcome
 */
void ZorkCore::printWelcome()
{
    QTextStream out(stdout);
    out << "Welcome to the saga of... something." << endl
        << "Current location:\t" << currentLoc->getDescription() << endl;
}

/**
 * @brief ZorkCore::play
 */
void ZorkCore::play()
{
    bool finished = false;
    printWelcome();
    while (!finished)
    {
        QTextStream out(stdout);
        out << "Enter command:" << endl;
        QTextStream in(stdin);
        QStringList inStr = in.readLine().split(" ", QString::SkipEmptyParts);
        QString firstWord = inStr.at(0);
        QString secondWord;
        (inStr.size() > 1) ? secondWord = inStr[1] : secondWord = "";
        Command userIn(firstWord, secondWord);
        finished = processCommand(userIn);
    }
}
