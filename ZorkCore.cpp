#include "ZorkCore.h"
#include "ui_ZorkCore.h"
#include "mainwindow.h"

ZorkCore::ZorkCore(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ZorkCore),
    playerCharacter("Player")
{
    ui->setupUi(this);
    srand(time(nullptr));
    createLocations();
    showMap();
    ui->charStats->setText(playerCharacter.showStatus());
}

ZorkCore::~ZorkCore()
{
    delete ui;
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
            valid = true;
            currentLoc = newLoc;
            ui->out->append(currentLoc->getDescription() + "\n");
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
    if (!in.isValidCommand())
        ui->out->append("The hell are you trying to do?\n");
    else if (in.commandWordRef.compare("info") == 0 && !in.hasSecondWord())
        ui->out->append("Valid commands are:\n" + in.listValidCommands() + "\n");
    else if (in.commandWordRef.compare("go") == 0 && in.hasSecondWord())
    {
        QString here = currentLoc->getName();
        currentLoc = currentLoc->getExit(in.secondWordRef);
        if (here.compare(currentLoc->getName()) == 0)
            ui->out->append("You cant go that direction..\n");
        else
            ui->out->append(currentLoc->getDescription() + "\n");
    }
    else if (in.commandWordRef.compare("teleport") == 0 && !in.hasSecondWord())
    {
        ui->out->append("You are teleporting to a new room...\n");
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
    ui->out->append("Welcome to the saga of... something.\nCurrent location:\n" + currentLoc->getDescription() + "\n");
}

void ZorkCore::showMap()
{
    ui->mapBox->setText("[a]--[b]--[c]\n"
                        "      |      \n"
                        "[d]--[e]--[f]\n"
                        "      |      \n"
                        "[g]--[h]--[i]\n"
                        " | \n"
                        "[j]");
}

void ZorkCore::on_westButton_clicked()
{
    Command in("go", "west");
    processCommand(in);
}

void ZorkCore::on_northButton_clicked()
{
    Command in("go", "north");
    processCommand(in);
}

void ZorkCore::on_southButton_clicked()
{
    Command in("go", "south");
    processCommand(in);
}

void ZorkCore::on_eastButton_clicked()
{
    Command in("go", "east");
    processCommand(in);
}

void ZorkCore::on_tpButton_clicked()
{
    Command in("teleport", "");
    processCommand(in);
}

void ZorkCore::on_inventoryButton_clicked()
{

}
