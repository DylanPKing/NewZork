#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QDialog>

#include "Character.h"
#include "Command.h"
#include "Item.h"
#include "weapon.h"
#include "Location.h"

namespace Ui {
class ZorkCore;
}

class ZorkCore : public QDialog
{
    Q_OBJECT

public:
    explicit ZorkCore(QWidget *parent = nullptr);
    ~ZorkCore();
    void go(QString);
    void teleport();
    void printWelcome();

private slots:
    void on_westButton_clicked();

    void on_northButton_clicked();

    void on_southButton_clicked();

    void on_eastButton_clicked();

    void on_tpButton_clicked();

    void on_inventoryButton_clicked();

private:
    Ui::ZorkCore *ui;
    Location* currentLoc;
    Character playerCharacter;
    QVector <Location*> locations;
    bool processCommand(Command);
    void createLocations();
    void showMap();
};

#endif // GAMEWINDOW_H
