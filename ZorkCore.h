#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QDialog>
#include <QTextEdit>

#include "Character.h"
#include "Command.h"
#include "Item.h"
#include "weapon.h"
#include "armour.h"
#include "Location.h"
#include "inventorywindow.h"

namespace Ui {
class ZorkCore;
}

class ZorkCore : public QDialog
{
    Q_OBJECT

public:
    explicit ZorkCore(QWidget *parent = nullptr);
    ~ZorkCore();
    void printWelcome();

signals:
    void winCondition();
    void loseCondition();

private slots:
    void on_westButton_clicked();
    void on_northButton_clicked();
    void on_southButton_clicked();
    void on_eastButton_clicked();
    void on_tpButton_clicked();
    void on_winCondition();
    void on_loseCondition();
    void quit();
    void on_inventoryBtn_clicked();
    void on_takeItemBtn_clicked();
    void on_dropItemBtn_clicked();

private:
    Ui::ZorkCore *ui;
    InventoryWindow *inventoryWindow;
    Location *currentLoc;
    Character *playerCharacter;
    QVector <Location*> locations;
    void createLocations();
    void go(QString&);
    void teleport();
    void showMap();
    void rebindBtns();
    bool isItemLineEmpty();
    void takeIfExists(QString&);
    void giveIfExists(QString&);
    void checkWinCondition();
};

#endif // GAMEWINDOW_H
