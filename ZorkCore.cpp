#include "ZorkCore.h"
#include "ui_ZorkCore.h"
#include "mainwindow.h"

#define updateCharStats ui->charStats->setText(playerCharacter->showStatus())

ZorkCore::ZorkCore(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ZorkCore),
    playerCharacter(new Character("Player"))
{
    ui->setupUi(this);
    srand(time(nullptr));
    createLocations();
    showMap();
    updateCharStats;
    inventoryWindow = new InventoryWindow();
    connect(this, SIGNAL(winCondition()), this, SLOT(on_winCondition()));
    connect(this, SIGNAL(loseCondition()), this, SLOT(on_loseCondition()));
}

ZorkCore::~ZorkCore()
{
    delete ui;
    delete inventoryWindow;
}

/**
 * @brief ZorkCore::teleport
 */
void ZorkCore::teleport()
{
    ui->out->append("You are teleporting to a new room...\n");
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

void ZorkCore::go(QString &dir)
{
    QString here = currentLoc->getName();
    currentLoc = currentLoc->getExit(dir);
    if (here.compare(currentLoc->getName()) == 0)
        ui->out->append("You cant go that direction..\n");
    else
        ui->out->append(currentLoc->getDescription() + "\n");
    if (currentLoc->getName().compare("f") == 0)
        emit loseCondition();
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

    *ePtr + new Weapon("Sword", "A simple sword.", 15, 20, 1);
    *bPtr + new Armour("Breastplate", "A sturdy breatplate", 30, 25);
    *cPtr + new Armour("Helmet", "A metal helmet, fit for a knight", 20, 20);


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
    QString dir = "West";
    go(dir);
}

void ZorkCore::on_northButton_clicked()
{
    QString dir = "North";
    go(dir);
}

void ZorkCore::on_southButton_clicked()
{
    QString dir = "South";
    go(dir);
}

void ZorkCore::on_eastButton_clicked()
{
    QString dir = "East";
    go(dir);
}

void ZorkCore::on_tpButton_clicked()
{
    teleport();
}

void ZorkCore::rebindBtns()
{
    connect(ui->westButton, SIGNAL(clicked()), this, SLOT(quit()));
    connect(ui->northButton, SIGNAL(clicked()), this, SLOT(quit()));
    connect(ui->southButton, SIGNAL(clicked()), this, SLOT(quit()));
    connect(ui->eastButton, SIGNAL(clicked()), this, SLOT(quit()));
    connect(ui->tpButton, SIGNAL(clicked()), this, SLOT(quit()));
    connect(ui->dropItemBtn, SIGNAL(clicked()), this, SLOT(quit()));
    connect(ui->takeItemBtn, SIGNAL(clicked()), this, SLOT(quit()));
    connect(ui->inventoryBtn, SIGNAL(clicked()), this, SLOT(quit()));
}

void ZorkCore::on_winCondition()
{
    ui->out->append("Congratulations! You won! You did almost nothing! Press any button to quit.");
    rebindBtns();
}

void ZorkCore::on_loseCondition()
{
    ui->out->append("Sorry! You lost! You did almost nothing! Press any button to quit.");
    rebindBtns();
}

void ZorkCore::quit()
{
    close();
}

void ZorkCore::on_inventoryBtn_clicked()
{
    inventoryWindow->setText(*playerCharacter);
    inventoryWindow->show();
}

bool ZorkCore::isItemLineEmpty()
{
    return ui->itemEntry->text().compare("") == 0;
}

void ZorkCore::takeIfExists(QString &itemToTake)
{
    auto i = currentLoc->itemsRef.begin();
    auto j = currentLoc->itemsRef.end();
    for (; i != j; ++i)
    {
        if ((*i)->getName().compare(itemToTake) == 0)
        {
            Item* itemPtr = *i;
            playerCharacter->takeItem(itemPtr);
            currentLoc->removeItem(itemPtr);
            ui->out->append("You have taken the " + itemPtr->getName() + ".");
            return;
        }
    }
    ui->out->append("That item isn't here..");
}

void ZorkCore::giveIfExists(QString &itemToDrop)
{
    auto i = playerCharacter->inventoryRef.begin();
    auto j = playerCharacter->inventoryRef.end();
    for (; i != j; ++i)
    {
        if ((*i)->getName().compare(itemToDrop) == 0)
        {
            Item* itemPtr = *i;
            playerCharacter->giveItem(itemPtr);
            currentLoc->addItem(itemPtr);
            ui->out->append("You have dropped the " + itemPtr->getName() + ".");
            return;
        }
    }
    ui->out->append("You don't have that item..");
}

void ZorkCore::on_takeItemBtn_clicked()
{
    if (!isItemLineEmpty())
    {
        QString itemToTake = ui->itemEntry->text();
        takeIfExists(itemToTake);
    }
    updateCharStats;
}

void ZorkCore::on_dropItemBtn_clicked()
{
    if (!isItemLineEmpty())
    {
        QString itemToDrop = ui->itemEntry->text();
        giveIfExists(itemToDrop);
    }
    updateCharStats;
    checkWinCondition();
}

void ZorkCore::checkWinCondition()
{
    if (currentLoc->getName().compare("j") == 0 &&
        currentLoc->itemsRef.size() == 3)
        emit winCondition();
}
